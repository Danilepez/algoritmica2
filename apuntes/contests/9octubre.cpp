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

int battle(vector<int>& ratings) {
    while (ratings.size() > 1) {
        if (ratings.size() % 2 == 0) {
            // Para tamaño par, restar los elementos del medio
            int aux = ratings[ratings.size() / 2] - ratings[ratings.size() / 2 - 1];
            ratings.erase(ratings.begin() + ratings.size() / 2 - 1, ratings.begin() + ratings.size() / 2 + 1); // Borra los dos elementos del medio
            ratings.insert(ratings.begin() + ratings.size() / 2, aux);  // Inserta el nuevo valor
        } else {
            // Para tamaño impar, restar el primer y el penúltimo
            int aux = ratings[ratings.size() - 2] - ratings[0];
            ratings.erase(ratings.begin());  // Borra el primer elemento
            ratings.erase(ratings.end() - 2);  // Borra el penúltimo elemento
            ratings.insert(ratings.begin() + ratings.size() - 1, aux);  // Inserta el nuevo valor
        }
    }
    
    return ratings[0];
}

int main() {
    int n_cases;
    cin >> n_cases;

    while (n_cases--) {
        int fighters;
        cin >> fighters;
        vector<int> ratings(fighters);

        for (int i = 0; i < fighters; i++) {
            cin >> ratings[i];
        }

        cout << battle(ratings) << endl;  // Mostrar el resultado de la batalla
    }

    return 0;
}



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
}


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
        cout<<battle(ratings)<<endl;
    }
    return 0;
}*/