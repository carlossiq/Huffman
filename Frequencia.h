//dev Portes
#ifndef FREQUENCIA
#define FREQUENCIA

#include <iostream>

struct NO
{
    char dados;
    int freq;
    struct NO *direita, *esquerda;
};

struct  NO *frequencia(char nome[], int *cont)
{
    FILE *arquivo;

    struct NO * frequencia_crescente;

    int ASCII[256], i, k=0, contador=0;
    for (i = 0; i < 256; i++)
    {
        ASCII[i] = 0;           //inicializando todos com frequencia zero
    }
    

    arquivo = fopen(nome, "r");

    if (arquivo==NULL)
    {
        printf("erro ao abrir o arquivo");
    }
    else
    {
        char c;
        int n;
        while (!feof(arquivo))
        {
            c = getc(arquivo);
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
        frequencia_crescente = (struct NO *) malloc(contador*sizeof(struct NO));

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
    }
    *cont = contador;
    return frequencia_crescente; //o retorno será um vetor de estrutura nó, com o caracetere e a frequencia que aparecem, nó esquerdo e nó direito NULL, o
                                 //o vetor estará em ordem crescente de frequencia, sendo que as frequencias zero foram retiradas.
}

#endif