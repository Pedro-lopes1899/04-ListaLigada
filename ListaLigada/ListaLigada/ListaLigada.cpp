
#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;

		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista já possuir elementos
	// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
    int valor;
    cout << "Digite o valor do novo elemento: ";
    cin >> valor;
    if (posicaoElemento(valor) != NULL) {
        cout << "Esse elemento já está na lista." << endl;
        return;
    }
    NO* novo = new NO();
    novo->valor = valor;
    novo->prox = NULL;
    if (primeiro == NULL) {
        primeiro = novo;
        cout << "Elemento " << valor << " inserido como o primeiro da lista." << endl;
        return;
    }
    NO* aux = primeiro;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novo;
    cout << "Elemento " << valor << " inserido no final da lista." << endl;
}

void excluirElemento()
{
    if (primeiro == NULL) {
        cout << "A lista está vazia." << endl;
        return;
    }

    int busca;
    cout << "Digite um elemento para excluí-lo: ";
    cin >> busca;

    NO* anterior = NULL;
    for (NO* atual = primeiro; atual != NULL; anterior = atual, atual = atual->prox) 
        if (atual->valor == busca) {
            if (anterior == NULL) {
                primeiro = atual->prox; 
            } else {
                anterior->prox = atual->prox; 
            }

            delete atual; 
            cout << "Elemento excluído com sucesso!" << endl;
            return;
        }
    }

    
    cout << "Elemento não encontrado na lista." << endl;
}

void buscarElemento()
{
    if (primeiro == NULL) {
        cout << "A lista está vazia." << endl;
        return;
    }
    int busca;
    cout << "Digite um elemento para buscar: ";
    cin >> busca;

    int posicao = 1; 
    NO* atual;
    for (atual = primeiro; atual != NULL; atual = atual->prox, posicao++) {
        if (atual->valor == busca) {
            cout << "Elemento " << busca << " encontrado na posição " << posicao << "." << endl;
            return;
        }
    }
    cout << "Elemento " << busca << " não encontrado na lista." << endl;
}


// retorna um ponteiro para o elemento buscado
// ou NULL se o elemento não estiver na lista
NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}
