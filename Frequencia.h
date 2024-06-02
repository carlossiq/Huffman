//dev Portes
#ifndef FREQUENCIA
#define FREQUENCIA

#include <iostream>
#include <vector>
#include <fstream>

using std::string;
using std::vector;
using std::ifstream;//leitura de arquivo


struct NO
{
    char dados;
    int freq;
    struct NO *direita, *esquerda;
};

vector<NO> frequencia(string nome, int *cont) //*cont serve como ontador para saber quantos caracteres diferentes tem
{
    ifstream arquivo(nome);

    int ASCII[256]={0}, i, k=0, contador=0;
    

    if (!arquivo.is_open())
    {
        printf("erro ao abrir o arquivo");
        vector<NO> erro(1);
        erro[0].dados= '\0';
        erro[0].direita= nullptr;
        erro[0].esquerda= nullptr;
        erro[0].freq= 0;

        return erro;
    }
    else
    {
        char c;
        int n;
        while (arquivo.get(c))
        {
            n = c;
            ASCII[n-1]++;
        }

        for (int i = 0; i < 256; i++)
        {
            if (ASCII[i]!=0)
            {
                contador++;
            }
        }

        vector<NO> frequencia_crescente(contador);//contador está dizendo quantos elementos terão no vector

        for (int i = 0; i < 256; i++)
        {
            if (ASCII[i]!=0)
            {
                frequencia_crescente[k].dados = i+1;
                frequencia_crescente[k].freq = ASCII[i];
                frequencia_crescente[k].direita = NULL;
                frequencia_crescente[k].esquerda = NULL;
                k++;
            }
        }

        int check=1;
        struct NO aux;
        
        while (check)
        {
            check=0;
            for (i = 0; i < contador-1; i++) 
            {
                for (int j = 0; j < contador-i-1; j++) 
                {
                    if (frequencia_crescente[j].freq > frequencia_crescente[j+1].freq) 
                    {
                        
                        aux = frequencia_crescente[j];
                        frequencia_crescente[j] = frequencia_crescente[j+1];
                        frequencia_crescente[j+1] = aux;
                        check++;
                    }      
                }
            }
        }

        *cont = contador;
        return frequencia_crescente; //o retorno será um vector de estrutura nó, com o caracetere e a frequencia que aparecem, nó esquerdo e nó direito NULL, o
                                 //o vetor estará em ordem crescente de frequencia, sendo que as frequencias zero foram retiradas.
    }
    
}

#endif