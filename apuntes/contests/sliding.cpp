#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int sliding(int n, int m, int r, int c){
    int matrix[n][m];
    memset(matrix, 1, sizeof(matrix));
    matrix[r][c] = 0;
    if(r>n||c>m){
        return 0;
    }
    int acc1 = 0, acc2 = 0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            
        }
    }
}


int main(){
    int n_cases;
    int n,m,r,c;
    cin>>n_cases;
    while(n_cases--){
        cin>>n>>m;
        cin>>r>>c;
        cout<<sliding(n,m,r,c)<<endl;
    }
}