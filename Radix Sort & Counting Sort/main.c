/* Programa: couting sort e radix sort
 
Autor: Felipe Baz Mitsuishi
 
Versao: 1.0 - 25/08/2020
 
*/
 
// ##################### Bibliotecas Externas ##############################
 
 
 
#include <stdio.h>
 
#include <string.h>
 
#include <ctype.h>
 
 
 
// ########################## TAD X.h ######################################
 
typedef struct
 
{
 
    char nome[15];
 
    int tam;
 
} reg;
 
 
 
typedef struct
 
{
 
    int nome[15];
 
    int tam;
 
} reg2;
 
 
 
void countingSort(int n, int d, reg2 A[n], reg2 *B[n]) //input: A, n, d     output: B
 
{
 
}
 
 
 
void radixSort(int n, int d, reg2 A[n], reg2 C[]) //input: A, n, d   output: B
 
{
 
    int i, j, k, m, cond;
 
    reg2 B[n];
 
    for (m = d - 1; m >= 0; m--)
 
    {
 
        //faça um metodo estavel de ordenação
 
        //countingSort(n,i,A,&B);
 
 
 
        //k = 27
 
        int c[27]; //0,1,2,..., 27(k)
 
 
 
        //zera o vetor c
 
        for (i = 0; i < 27; i++)
 
        {
 
            c[i] = 0;
 
        }
 
 
 
        //conta a quantidade de elementos
 
        for (j = 0; j < n; j++)
 
        {
 
            if (m < A[j].tam)
 
            {
 
                int a = A[j].nome[m] - 96;
 
                c[a]++;
 
            }
 
            else
 
            {
 
                c[0]++;
 
            }
 
        }
 
 
 
        //faz a soma prefixa dos elementos
 
        for (i = 1; i < 27; i++)
 
        {
 
            c[i] = c[i] + c[i - 1];
 
        }
 
 
 
        for (i = 0; i < 27; i++)
 
        {
 
            printf("%d ", c[i]);
 
        }
 
        printf("\n");
 
        
 
        //adiciona os elementos nas posições corretas
 
        for (j = n - 1; j >= 0; j--)
 
        {
 
            if (m < A[j].tam)
 
            {
 
                int o = c[A[j].nome[m] - 96] - 1;
 
                int tamanho = A[j].tam;
 
                B[o].tam = tamanho;
 
                C[o].tam = tamanho;
 
                for (i = 0; i < tamanho; i++)
 
                {
 
                    B[o].nome[i] = A[j].nome[i];
 
                    C[o].nome[i] = B[o].nome[i];
 
                    char b = B[o].nome[i];
 
                }
 
                c[A[j].nome[m] - 96]--;
 
            }
 
            else
 
            {
 
                int o = c[0] - 1;
 
                int tamanho = A[j].tam;
 
                B[o].tam = tamanho;
 
                C[o].tam = tamanho;
 
                for (i = 0; i < tamanho; i++)
 
                {
 
                    B[o].nome[i] = A[j].nome[i];
 
                    C[o].nome[i] = B[o].nome[i];
 
                    char b = B[o].nome[i];
 
                }
 
 
 
                c[0]--;
 
            }
 
        }
 
 
 
        //imprime o vetor C
 
        
 
 
 
        for (j = 0; j < n; j++)
 
        {
 
            int tamb = B[j].tam;
 
            for (k = 0; k < tamb; k++)
 
            {
 
                A[j].nome[k] = B[j].nome[k];
 
                B[j].nome[k] = 0;
 
 
 
                C[j].nome[k] = A[j].nome[k];
 
            }
 
            A[j].tam = B[j].tam;
 
            C[j].tam = A[j].tam;
 
            B[j].tam = 0;
 
        }
 
    }
 
}
 
 
 
// ###################### Funcoes e Procedimentos do programa ##############
 
 
 
void transformData(int n, reg A[n], reg2 B[n]) // Input: A, n    Output: B
 
{
 
    int aux;
 
    int i, j, k;
 
 
 
    for (i = 0; i < n; i++)
 
    {
 
        //lower(A[i], n); //tranforma tudo em minusculo
 
        for (j = 0; j < A[i].tam; j++)
 
        {
 
            A[i].nome[j] = tolower(A[i].nome[j]);
 
            aux = A[i].nome[j];
 
            B[i].nome[j] = aux;
 
            B[i].tam = A[i].tam;
 
        }
 
    }
 
}
 
 
 
int MaiorString(int n, reg A[n])
 
{
 
    int i, maior = 0;
 
    for (i = 0; i < n; i++)
 
    {
 
 
 
        if (maior < A[i].tam)
 
        {
 
            maior = A[i].tam;
 
        }
 
    }
 
    return maior;
 
}
 
 
 
void reTranformData(int n, reg2 A[n], reg B[n]) // Input: A, n    Output: B
 
{
 
    int i, j;
 
    char aux;
 
    for (i = 0; i < n; i++)
 
    {
 
        //lower(A[i], n); //tranforma tudo em minusculo
 
        for (j = 0; j < A[i].tam; j++)
 
        {
 
            aux = A[i].nome[j];
 
            B[i].nome[j] = aux;
 
            B[i].tam = A[i].tam;
 
        }
 
        B[i].nome[A[i].tam] = '\0';
 
 
 
    }
 
}
 
// ############################ Principal ###################################
 
 
 
int main()
 
{
 
    int n, i, p, m;
 
    scanf("%d", &n);
 
    reg A[n], D[n];
 
    reg2 B[n], C[n];
 
    for (i = 0; i < n; i++)
 
    {
 
        scanf("%s", &A[i].nome);
 
        A[i].tam = strlen(A[i].nome);
 
    }
 
    scanf("%d %d", &p, &m);
 
    transformData(n, A, B);
 
    //B é o vetor codificado
 
    int tam = MaiorString(n, A);
 
    radixSort(n, tam, B, C);
 
    //c é o vetor codificado ordenado
 
 
 
    reTranformData(n, C, D);
 
 
 
    for (i = 0; i < m; i++)
 
    {
 
        printf("%s\n", D[i + p - 1].nome);
 
    }
 
 
 
    return 0;
 
}