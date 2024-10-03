#include <bits/stdc++.h>
#define input freopen ("inTelf.txt","r",stdin)
#define output freopen ("outTelf.txt","w",stdout)
using namespace std;

struct node{
    char currentCharacter;
    bool endOfNumber;
    node *children[10];
    node(){
        endOfNumber = false;
        for(int i = 0; i<10;i++){
            children[i] = NULL;
        }
    }
};

bool isNumber, isCreated;

void insert(node *trie, string number) { //solo con node trie recibiriamos el nodo pero no la posicion
    node *currentNode = trie;
    for(int i = 0; i<number.size();i++){
        int index = number[i] - '0';
        if(currentNode->children[index] == NULL){
            isCreated = true;
            currentNode->children[index] = new node();
            currentNode->children[index]->currentCharacter = number[i];
        }
        currentNode = currentNode->children[index];
        if(currentNode->endOfNumber){
            isNumber = true;
        }
        currentNode->currentCharacter = number[i];
        if(isCreated && !isNumber){
            
        }
    }
    if(isCreated){
        currentNode->endOfNumber = true;
    }
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
    return currentNode->endOfNumber;
}

int main(){
    int wordsNumber;
    cin>>wordsNumber;

    node *trie = new node();

    while(wordsNumber--){
        string word;
        cin >> word;
        isNumber = false;
        isCreated = false;
        insert(trie,word);
        cout<<isNumber<<" "<<isCreated<<endl;
    }

    if(search(trie,"76517816")){
        cout<<"Si existe el 76517816"<<endl;
    } else {
        cout<<"No existe el 76517816"<<endl;
    }

    if(search(trie,"76517")){
        cout<<"Si existe el 76517"<<endl;
    } else {
        cout<<"No existe el 76517"<<endl;
    }
}