#include <iostream>
#include <stdlib.h> //para malloc();

using std::cin;
using std::cout;
using std::endl;

typedef struct tree{
    int id;
    struct tree *left;
    struct tree *right;
}tree;

tree * _add(tree *, int);
tree *createNo(int);
void search(tree *, int);

int menu();
int mallocVerify(tree *, tree *); //Verifica se malloc conseguiu encontrar um espaço de memória livre para no* novo

int main(){
    setlocale(LC_ALL, "Portuguese");

	 tree *no = NULL;
    tree *root = NULL;
    int flag = 0;
    int id;

    do{
        switch(menu()){
        case 1:
        //inserir - _add();
        cout << "Insira a nova chave: ";
        cin >> id;
        if(root == NULL){
			  root = _add(root, id);
		  }else{
			  _add(root, id);
		  }

        break;
        case 2:
			   cout << "Insira a chave que deseja buscar: ";
			   cin >> id;
            search(root, id);
            cout << endl;
            //pause();
            //clear();
        break;
        case 3:
        	  //Sair
		     flag = 1;
        break;
        default:
            cout << "Opção Inválida!" << endl;
            //pause();
        }
        //clear();
    }while(flag != 1);

    return 0;
}

int menu(){
    int op;

    cout << "*****ÁRVORES*****" << endl;
    cout << "[1] - Inserir" << endl;
    cout << "[2] - Buscar" << endl;
    cout << "[3] - Sair" << endl;
    cin >> op;

    return op;
};

tree *_add(tree *newid, int id){
	tree *aux = NULL;
	aux = newid;
	
	if(aux != NULL){
		while(true){
			while(id < aux->id && aux->left != NULL){
				aux = aux->left;
			}
			if(id < aux->id && aux->left == NULL){
				aux->left = createNo(id);
				return aux->left;
			}
			
			while(id > aux->id && aux->right != NULL){
				aux = aux->right;
			}
			if(id > aux->id && aux->right == NULL){
				aux->right = createNo(id);
				return aux->right;
			}
		}
	}
	
	return createNo(id);
}

tree *createNo(int id){
    tree *newid = (tree *)malloc(sizeof(tree)); //O ponteiro 'novo' recebe o local indicado por malloc(); do tamanho definido por sizeof();
    newid->right = NULL;
    newid->left = NULL;
    newid->id = id;

    return newid;
};

void search(tree *root, int id){
	tree *aux = NULL;
	aux = root;
	
	while(aux->id != id && (aux->left != NULL || aux->right != NULL)){
		while(aux->id > id && aux->id != id && aux->left != NULL){
			aux = aux->left;
		}
		while(aux->id < id && aux->id != id && aux->right != NULL){
			aux = aux->right;
		}
	}
	if(aux->id == id){
		cout << "Chave encontrada!" << endl;
	}else{
		cout << "Chave não encontrada!" << endl;
	}
}

int mallocVerify(tree *novo, tree *lista){

	int flag = 0;

	 if (novo == NULL){ //Impede que o programa execute caso o malloc não consiga encontrar memória livre
        cout << "Memória insuficiente!\n Tente fechar alguns programas ou reiniciar a máquina." << endl;
        flag = 1;
        //pause();
        if(lista == NULL){ // se novo e lista == NULL então nada foi adicionado na lista e o programa pode ser fechado
            exit(1);
        } // se a lista possuir elementos o programa não fecha, mesmo com o malloc não conseguindo encontrar espaços de memória livres
    }

	return flag;
}
