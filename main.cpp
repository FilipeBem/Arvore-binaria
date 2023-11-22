#include <cstdlib>
#include <iostream>
#include "arvore.h"
using namespace std;

typedef struct Tnode Tnode;

void menu();

Tnode* inicia_arvore() {
	Tnode* tmp = new (Tnode);
	tmp->tam = 0;
	tmp->arvore = NULL;

	return tmp;
}

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

Tnode* encerra_arvore(Tnode * ptarvore) {
	Tnode * ant = ptarvore->arvore;
	Tnode * pont = ptarvore->arvore;
	
	while(ant != NULL){
		pont = ant->esq;
		delete(ant);
		ant = pont;
	}
	delete(ptarvore);
        cout << "-A arvore foi removida."<<endl;
	
        return NULL;
}


noh * busca (Tnode *a, int valor) {
    if (a == NULL || a->chave == valor)
       return a;
    if (a->chave > valor)
       return busca (a->esq, valor);
    else
       return busca (a->dir, valor);
}

// A função recebe uma árvore de busca a
// e uma folha avulsa novo e insere a folha
// na árvore de modo que a árvore continue
// sendo de busca. A função devolve a raiz 
// da árvore resultante.


Tnode* insere (Tnode *a, noh *novo) {  
    if (a == NULL)  return novo;
    if (a->chave > novo->chave) 
       a->esq = insere (a->esq, novo);
    else 
       a->dir = insere (a->dir, novo);
    return a;
}

// Recebe uma árvore de busca não vazia a.
// Remove a raiz da árvore e rearranja a
// árvore de modo que ela continue sendo
// de busca. Devolve o endereço da nova
// raiz.


Tnode* removeraiz (Tnode *a) {  
    noh *p, *f;
    if (a->esq == NULL) {
       f = a->dir;
       free (a);
       return f;
    }
    p = a; f = a->esq;
    while (f->dir != NULL) {
       p = f; f = f->dir;
    }
    // f é nó anterior a "a" na ordem e-a-d
    // p é o pai de f
    if (p != a) {
       p->dir = f->esq;
       f->esq = a->esq;
    }
    f->dir = a->dir;
    free (a);
    return f;
}

void displayPreOrder(Tnode* a);
void displayInOrder(Tnode* a);
void displayPostOrder(Tnode* a);

void display(Tnode* a, int ordem) {
    if (ordem == 1) {
        cout << "Pre-Order: ";
        displayPreOrder(a);
    } else if (ordem == 2) {
        cout << "In-Order: ";
        displayInOrder(a);
    } else if (ordem == 3) {
        cout << "Post-Order: ";
        displayPostOrder(a);
    } else {
        cout << "Invalid order selected." << endl;
    }
}

void displayPreOrder(Tnode* a) {
    if (a != NULL) {
        cout << a->chave << " ";
        displayPreOrder(a->esq);
        displayPreOrder(a->dir);
    }
    
}

void displayInOrder(Tnode* a) {
    if (a != NULL) {
        displayInOrder(a->esq);
        cout << a->chave << " ";
        displayInOrder(a->dir);
    }
}

void displayPostOrder(Tnode* a) {
    if (a != NULL) {
        displayPostOrder(a->esq);
        displayPostOrder(a->dir);
        cout << a->chave << " ";
    }
}
int contarNos(Tnode* a) {
    if (a == NULL) {
        return 0;
    } else {
        return contarNos(a->esq) + contarNos(a->dir);
    }
}

void total(Tnode* a) {
    int count = contarNos(a);
    cout << "Total nodes: " << count  << endl;
}

void clear(){
    system("cls");
     menu();
}

int main() {
    Tnode* a = inicia_arvore();
    menu();
    
    int chave;
    int valor;
    int ordem; 
    do {
        cout << "Select option: ";
        cin >> chave;
        
        switch (chave) {
            case 1: {
                cout << "Enter the value you want to search for: ";
                cin >> valor;
                busca(a, valor);
                break;
            }
            case 2: {
                cout << "Enter the value you want to insert: ";
                cin >> valor;
                noh* novo = new noh;
                novo->chave = valor;
                novo->esq = NULL;
                novo->dir = NULL;
                insere(a, novo);
                break;
            }
            case 3: {
                cout << "Enter the value you want to remove: ";
                cin >> valor;
                removeraiz(a);
                break;
            }
            case 4: {
                cout << "Enter the order of traversal (1 for pre-order, 2 for in-order, 3 for post-order): ";
                cin >> ordem;
                display(a, ordem);
                break;
            }
            case 5: 
                total(a);
                break;   
            case 6: {
                clear();
                break;
            }
            case 7: {
                cout << "Exit" << endl;
                break;
            }
            default: {
                cout << "Invalid chave" << endl;
                break;
            }
        }
    } while (chave != 7);
    return 0;
}

void menu() {
    cout << "Menu:" << endl;
    cout << "1. Search" << endl;
    cout << "2. Insert" << endl;
    cout << "3. Remove" << endl;
    cout << "4. Display" << endl;
    cout << "5. Total" << endl;
    cout << "6. Clear" << endl;
    cout << "7. Exit" << endl;
}
