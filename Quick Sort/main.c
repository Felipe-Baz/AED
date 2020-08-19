/* Programa: Metodo de ordenação quicksort
Autor: Felipe Baz Mitsuishi
Versao: 1.0 - 11/08/2020
*/
// ##################### Bibliotecas Externas ##############################

#include <stdio.h>
#include <string.h>

// ########################## TAD X.h ######################################

typedef struct
{
    char nome[15];
    int idade;
} reg;


int separa(reg v[], int p, int r)
{
    reg aux;
    int meio = (p+r)/2;
    int a = v[p].idade;
    int b = v[meio].idade;
    int c = v[r].idade;
    int medIndice = 0;

    if (a < b && b < c)
    {
        medIndice = meio;
    }
    if (a < c && c <= b)
    {
        medIndice = r;
    }
    if (c <= a && a < b)
    {
        medIndice = p;
    }
    if (c < b && b <= a)
    {
        medIndice = meio;
    }
    if (b <= c && c < a)
    {
        medIndice = r;
    }
    if (b <= a && a <= c)
    {
        medIndice = p;
    }
    aux = v[r], v[r] = v[medIndice], v[medIndice] = aux;
    c = v[r].idade; // pivo´
    int j = p;

    reg t;
    int k;
    for (k = p; /*A*/ k < r; ++k)
    {
        int atual = v[k].idade;
        if (atual <= c)
        {
            t = v[j], v[j] = v[k], v[k] = t;
            ++j;
        }
    }
    t = v[j], v[j] = v[r], v[r] = t;
    return j;
}

void quicksort(reg v[], int p, int r)
{
    if (p < r)
    {                            // 1
        int j = separa(v, p, r); // 2
        quicksort(v, p, j - 1);  // 3
        quicksort(v, j + 1, r);  // 4
    }
}

// ###################### Funcoes e Procedimentos do programa ##############

void estabilidade(int tamanho, reg reg1[], reg verifica[])
{
    int i, j, cond = 0;
    for (i = 0; i < tamanho - 2; i++)
    {
        if (cond == 0 && reg1[i].idade == reg1[i + 1].idade)
        {
            for (j = 0; j < 15; j++)
            {
                if (reg1[i].nome != verifica[i].nome)
                {
                    cond = 1;
                    break;
                }
            }
        }
    }
    if (cond == 1)
    {
        printf("no\n");
    }
    else
    {
        printf("yes\n");
    }
}

// ############################ Principal ###################################

int main()
{
    int i, j, N, p, m, nla;
    scanf(" %d", &N);
    reg registro[N], registro2[N];
    for (i = 0; i < N; i++)
    {
        //nome
        scanf("%s", registro[i].nome);
        //idade
        scanf("%d", &nla);
        registro[i].idade = nla;

        registro2[i].idade = registro[i].idade;
        strcpy(registro2[i].nome, registro[i].nome);
    }
    scanf("%d %d", &p, &m);
    quicksort(registro, 0, N-1);
    estabilidade(N, registro, registro2);
    
    for (i = 0; i < m; i++)
    {
        printf("%s %d\n", registro[i+p-1].nome, registro[i+p-1].idade);
    }
    
    return 0;
}
