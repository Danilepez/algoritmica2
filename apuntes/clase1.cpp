//Algorítmica II
//Inicio 18/09/24
//Contenido de la materia: 

//Evaluación: 
//1er Parcial: 20 Examen, 10 Prácticas//30, hasta Kriskal MST
//2do Parcial: 20 Examen, 10 Prácticas//30
//3er Parcial: 20 Proyecto, 20 Examen//40

//TRIE
//Trie es una estructura de datos que permite almacenar un conjunto de cadenas de caracteres de manera eficiente.
//Complejidad de for para recorrer un trie: O(n) donde n es el número de nodos del trie.
//Trie (Hola,Juan,Pedro,Hilo,Juevesm,Papel,Pelota,Paul) 
//Se trata de buscar las palabras en el Trie que empiezan con x,y....z, su complejidad es O(n*m) donde n es el número de nodos y m es el número de palabras que empiezan con x,y...z.

//Árbol de Prefijos(*) [nodo fantasma]
//(H)                      (J)           (P)
//(i)   (o)               (u)           (a)  (e)   
//(l)   (l)             (a)  (e)       (u) (p)  (d)   (l)
//(a)   (a)             (n)  (v)       (l*)  (e)  (r)  (o)
//(*)   (*)             (*)  (e)            (l*)  (o*)  (t)
//(*)   (*)             (*)  (s*)                      (a*)
//la complejidad es O(abecedario*m)
//* es una etiqueta para indicar el fin de una palabra.

//Fin de Palabra
//Caso
//   Juan
//   Juancito
//   Juana

//Se realiza un vector de tamaño del abecedario(27)
//cont = 0 (se crea un contador por cada nodo)
//la complejidad total es el maximo de los nodos
//caracter = ""
//end word == false
//[a][b][c][d]...[z]
//caracter = a                 caracter = c             caracter = z
//[null][null][c][null]...[z]           [a][b][c][d]...[z]       [a][b][c][d]...[z] end word == true
//caracter = c                 caracter = i             caracter = a
//[a][b][c][d]...[z]           [a][b][c][d]...[z]       [a][b][c][d]...[z]
//end word == true            end word == true          
//se pregunta si el caracter existe en el nodo (array) si no existe se crea un nuevo nodo y se sigue con el siguiente caracter.
//como es fin de palabra tiene contador = 1
//para eliminar palabras se reduce el contador en 1 y se pregunta si el contador es 0 se elimina el nodo.

//hay que pensar que una estructura es un objeto porque tiene atributos
#include <bits/stdc++.h>
#define input freopen ("inTrie.txt","r",stdin)
#define output freopen ("outTrie.txt","w",stdout)
using namespace std;

/*struct node {
    char currentCharacter;
    bool isWord;
    //int priority = 0;
    struct node *children[27]; //[null,null,null,......,null]
    node (){
        isWord = false;
    }

}*trie*/ //es lo mismo que declarar un: node trie;      usando * crea la estructura trie
//* es un puntero a una estructura de tipo nodo


//19/09/24

struct node{
    char currentCharacter;
    bool endOfWord;
    node *children[26];
    node(){
        endOfWord = false;
        for(int i = 0; i<26;i++){
            children[i] = NULL;
        }
    }
};

void insert(node *trie, string word) { //solo con node trie recibiriamos el nodo pero no la posicion
    node *currentNode = trie;
    for(int i = 0; i<word.size();i++){
        int index = word[i] - 'a';
        if(currentNode->children[index] == NULL){
            currentNode->children[index] = new node();
            currentNode->children[index]->currentCharacter = word[i];
        }
        currentNode = currentNode->children[index];
        currentNode->currentCharacter = word[i];
    }
    currentNode->endOfWord = true;
}
//el puntero acaba en el nodo de la ultima letra de la palabra

bool search(node *trie, string word){
    node *currentNode = trie;
    for(int i = 0; i<word.size(); i++){
        int index = word[i] -'a';
        if(currentNode->children[index] == NULL){ // -> funciona como contains
            return false;
        }
        currentNode = currentNode->children[index];
    }
    return currentNode->endOfWord;
}

int numWords = 0;
int prefixWords(node *trie, string prefix){
    node *currentNode = trie;
    for(int i = 0; i<prefix.size();i++){
        int index = prefix[i] - 'a';
        if(currentNode->children[index] == NULL){
            return 0;
        }
        if(currentNode->endOfWord){
            numWords++;
        }
        currentNode = currentNode->children[index];
    }
}

int main(){
    int wordsNumber;
    cin>>wordsNumber;

    node *trie = new node();

    while(wordsNumber--){
        string word;
        cin >> word;
        insert(trie,word);
    }

    if(search(trie,"apt")){
        cout<<"Si existe la palabra apt"<<endl;
    } else {
        cout<<"No existe la palabra apt"<<endl;
    }
}