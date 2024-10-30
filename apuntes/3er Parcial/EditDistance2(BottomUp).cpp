#include <iostream>
#include <cstring>
using namespace std;

string cadena1="paullandaeta", cadena2="juanperezdiegogomez";
int n = cadena1.size(),m = cadena2.size() ;
int dp[10000+10][10000+10];

int f(int i, int j) {
  // casos base
  if(i >= n && m-i >= 0){
    return m-i;
  }
  if(j>=m) {
     return n-j>=0? n-j: 0;
  }
  // i = 100 j = 87
  if(dp[i][j] == -1) {
    dp[i][j] = 0; // no se cuantas operaciones me faltan 
       // cout<<resultado<<endl;
    if(cadena1[i] == cadena2[j]){
      //cout<<"i= "<< i<< "j="<<j<<endl;
      dp[i][j] += 0 + f(i+1,j+1); // ya que son iguales aumento los punteros  
    } else {
      // cout<<"i= "<< i<< "j=*"<<j<<endl;
      // remplazar
      int resultadoR = 1 + f(i+1, j+1);
      // cout<<"Remplazar "<<resultadoR<<endl;
      // eliminar 
      int resultadE = 1 + f(i + 1,j);
      // adicionar 
      int resultadoA = 1 + f(i, j+1);
      
      dp[i][j] += min(resultadoR, min(resultadE,resultadoA));
    }
    // cout<<resultado<<endl;
  }
  return dp[i][j];
}


int main() 
{
  
    memset(dp, -1, sizeof(dp)); // a todas las celdas como no visitado
    cout<<f(0,0)<<endl;
    
    int dp2[100][100];
    memset(dp2, 0 , sizeof dp2);
    
    for (int i = 0; i < n; i++) {
      dp2[i][0] = i;
    }
    
    for (int j = 0; j < m; j++) {
      dp2[0][j] = j;
    }
    
    // for(int i = 0; i <=n; i++) {
    //   for (int j = 0; j<= m ; j++) {
    //     cout<<"[" << dp2[i][j]<<"]";
    //   }
    //   cout<<"\n";
    // }
    
    
    for(int i = 1; i <=n;i++) {
      for (int j = 1; j <=m; j++) {
        if (cadena1[i] == cadena2[j]) {
          dp2[i][j] = dp2[i-1][j-1];
        } else {
          dp2[i][j] = min(1 + dp2[i-1][j-1], min( 1 + dp2[i-1][j], 1 + dp2[i][j-1])); 
        }
      }
    }
    // for(int i = 0; i <=n; i++) {
    //   for (int j = 0; j<= m ; j++) {
    //     cout<<"[" << dp2[i][j]<<"]";
    //   }
    //   cout<<"\n";
    // }
    
    cout<<dp2[n][m]<<endl;
    
    
    
    return 0;
}