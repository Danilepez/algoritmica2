#include <bits/stdc++.h>
#define input freopen ("inTelf.txt","r",stdin)
#define output freopen ("outTelf.txt","w",stdout)
using namespace std;

struct node {
    char currentCharacter;
    bool endOfWord;
    node *children[26];  
    
    node() {
        endOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

void insert(node *trie, string word) {
    node *currentNode = trie;
    for (int i = 0; i < word.size(); i++) {
        int index = word[i] - 'a';
        if (currentNode->children[index] == NULL) {
            currentNode->children[index] = new node();
            currentNode->children[index]->currentCharacter = word[i];
        }
        currentNode = currentNode->children[index];
    }
    currentNode->endOfWord = true;
}

bool search(node *trie, string word) {
    node *currentNode = trie;
    for (int i = 0; i < word.size(); i++) {
        int index = word[i] - 'a';
        if (currentNode->children[index] == NULL) {
            return false;  
        }
        currentNode = currentNode->children[index];
    }
    return currentNode->endOfWord;  
}

/*bool deleteWord(node *trie, string word) {
    node *currentNode = trie;
    for (int i = 0; i < word.size(); i++) {
        int index = word[i] - 'a';

        if (currentNode->children[index] == NULL) {
            return false;
        }

        currentNode = currentNode->children[index];
    }

    if (currentNode->endOfWord) {
        currentNode->endOfWord = false;
        return true;  
    }
    return false;  
}*/
bool isEmpty(node* currentNode) {
    for (int i = 0; i < 26; i++) {
        if (currentNode->children[i] != NULL) {
            return false; // El nodo tiene al menos un hijo
        }
    }
    return true;
}

// Función para eliminar una palabra del trie
node* removeWord(node* trie, const std::string& word, int depth = 0) {
    // Si el trie está vacío
    if (!trie)
        return NULL;

    // Si se está procesando el último carácter de la palabra
    if (depth == word.size()) {
        // Ya no es fin de palabra después de la eliminación
        if (trie->endOfWord)
            trie->endOfWord = false;

        // Si el nodo no es prefijo de ninguna otra palabra
        if (isEmpty(trie)) {
            delete trie;
            trie = NULL;
        }

        return trie;
    }

    // Si no es el último carácter, proceder recursivamente
    int index = word[depth] - 'a';
    trie->children[index] = removeWord(trie->children[index], word, depth + 1);

    // Si el nodo actual no tiene hijos y no es el fin de otra palabra
    if (isEmpty(trie) && !trie->endOfWord) {
        delete trie;
        trie = NULL;
    }

    return trie;
}

int main() {
    node *trie = new node();
    
    // Insertar palabras
    insert(trie, "apple");
    insert(trie, "app");
    
    // Buscar palabras
    cout << (search(trie, "apple") ? "Si existe la palabra 'apple'" : "No existe la palabra 'apple'") << endl;
    cout << (search(trie, "app") ? "Si existe la palabra 'app'" : "No existe la palabra 'app'") << endl;
    cout << (search(trie, "apricot") ? "Si existe la palabra 'apricot'" : "No existe la palabra 'apricot'") << endl;

    // Eliminar palabras
    cout << (removeWord(trie, "apple") ? "Se eliminó la palabra 'apple'" : "No se pudo eliminar la palabra 'apple'") << endl;
    cout << (search(trie, "apple") ? "Si existe la palabra 'apple'" : "No existe la palabra 'apple'") << endl;
}
