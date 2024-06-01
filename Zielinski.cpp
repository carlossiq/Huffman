// aqui eu vou fazer o algorítimo ja supondo um vetor de nós ordenado em ordem crescente.

#include <bits/stdc++.h>

using namespace std;


// isso aqui resume bem o que seria um nó, para um no de junção, utilizaremos algum algorítimo que não pode ser encontrado no texto.

class no{
    public:
    int vis = 0;
    int frequencia;
    int aasc;
    no* direito;
    no* esquerdo;
};

// parte que o portes disse já ter feito de adicionar elementos na lista.

vector <no*> lista;

// função de busca no vetor lista dado um valor de frequencia:

int busca(int frequencia){
    // vou usar busca normal, mas é melhor colocar a binaria aqui dps
    for (int i = 0; i < lista.size(); i++)
    {
        if(lista[i]->frequencia >= frequencia){
            return i;
        }
    }
    return -1;
}
//retorna o primeiro elemento que possui o valor da frequencia buscada, se retonar -1 é o maior elemento da lista.

// montada a arvore, temos que fazer o dfs para codificar os caracteres.

string palavra = "";

vector <pair<string, int>> tabela;

void dfs(no* base ,int k){
    if(k == 0) palavra += '0';
    if(k == 1) palavra += '1';
    base -> vis = 1;
    if(base -> esquerdo == NULL && base -> direito == NULL){
        tabela.push_back({palavra, base->aasc});
        palavra = "";
    }
    if(base -> esquerdo != NULL) dfs(lista[0] -> esquerdo, 0);
    if(base -> direito != NULL)dfs(lista[0] -> direito, 1);
}

int main(){
    vector <no*> lista_nos[1000000];  
    int i = 0;
    while(lista.size() > 1){
        no* suporte = lista[i];
        suporte->esquerdo = lista[0];
        suporte->direito = lista[1];
        suporte->frequencia = lista[0]->frequencia + lista[1]->frequencia;
        suporte->aasc = -1;
        lista.pop_back(); lista.pop_back();
        int k = busca(suporte->frequencia) == -1 ? lista.size() : busca(suporte->frequencia);
        lista.emplace(lista.begin() + k, suporte);
        i++;
    }
    dfs(lista[0], -1);
    for (int i = 0; i < tabela.size(); i++)
    {
        cout << "A codificacao da letra de aasc = " << tabela[i].second <<" vale " <<tabela[i].first << endl;
    }
}