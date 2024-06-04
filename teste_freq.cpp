#include <iostream>

#include "frequencia.h"

using namespace std;

int main()
{
    int i, *n;
    vector<NO> teste;

    teste = frequencia("teste.txt", n);

    for (i = 0; i < *n; i++)
    {
        if (teste[i].dados == '\n')
        {
            printf("\\n - %d\n", teste[i].freq);
        }
        else
            printf("%c - %d\n", teste[i].dados, teste[i].freq);

    //para testar o .h
                
    }
    
    
    return 0;
}
