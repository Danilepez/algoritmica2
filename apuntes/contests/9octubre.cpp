//A)Zhan's Blender
//B) Battle for survive
#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;



//Recursividad 

/*int battle(vector<int> ratings) {
    if (ratings.size() == 1) {
        return ratings[0];
    } 
    
    if (ratings.size() % 2 == 0) {
        vector<int> aux2;
        int aux = ratings[ratings.size() / 2] - ratings[ratings.size() / 2 - 1];
        cout << "Step: " << aux << endl;  // Para ver el progreso
        
        for (int i = 0; i < ratings.size() / 2 - 1; i++) {
            aux2.push_back(ratings[i]);
        }
        
        aux2.push_back(aux);
        
        for (int j = ratings.size() / 2 + 1; j < ratings.size(); j++) {
            aux2.push_back(ratings[j]);
        }
        
        return battle(aux2);
    }
    
    if (ratings.size() % 2 != 0) {
        vector<int> aux2;
        int aux = ratings[ratings.size() - 2] - ratings[0];
        cout << "Step: " << aux << endl;  // Para ver el progreso
        
        for (int i = 1; i < ratings.size() - 2; i++) {
            aux2.push_back(ratings[i]);
        }
        
        aux2.push_back(aux);
        aux2.push_back(ratings[ratings.size() - 1]);
        
        return battle(aux2);
    }
    
    return 0;  
}*/


int main(){
    int n_cases;
    int fighters;
    cin>>n_cases;

    while(n_cases--){
        cin>>fighters;
        vector<int>ratings(fighters);
        for(int i = 0; i < fighters; i++){
            cin>>ratings[i];
        }
        if(ratings.size() == 2){
            //cout << "solo 2" <<endl;
            cout << ratings[1]-ratings[0]<<endl;
        } else {
          long long suma = 0; // Se cambió a long long para evitar errores
            for(int i = 0; i < fighters-2; i++){
                suma += ratings[i];
                //cout << "Step: " << suma<< endl;  // Para ver el progreso
                //cout << "en: " << i<< endl;
                //cout << "en array: " << ratings.size()<< endl;
            }
            suma = ratings[fighters-2]-suma;
            suma = ratings[fighters-1]-suma;
            cout << suma<< endl;
        }
    }
    return 0;
}