/* Programa: Heap sort
Autor: Felipe Baz Mitsuishi
Versao: 1.0 - 18/8/2020
*/
// ##################### Bibliotecas Externas ##############################
 
#include <stdio.h>
 
// ########################## TAD X.h ######################################
 
void maxHeapify(int n, int A[], int i)
{
    int left = 2 * i;
    int right = (2 * i) + 1;
    int max;
    int aux;
    if (left <= n && A[left] > A[i])
    {
        max = left;
    }
    else
    {
        max = i;
    }
 
    if (right <= n && A[right] > A[max])
    {
        max = right;
    }
 
    if (max != i)
    {
        //swap(A[i] e A[max])
        aux = A[i];
        A[i] = A[max];
        A[max] = aux;
        maxHeapify(n, A, max);
    }
}
 
void buildMaxHeap(int n, int A[])
{
    int i;
    for (i = n / 2; i >= 1; i--)
    {
        maxHeapify(n, A, i);
    }
}
 
int HeapExtractMax(int *n, int A[])
{
    int max = A[1];
    int last = *n;
    int aux;
    int i;
    for (i = 1; i < *n; i++)
    {
        A[i] = A[i + 1];
    }
 
    *n = *n - 1;
    buildMaxHeap(*n, A);
 
    return max;
}
 
void HeapSort(int n, int A[])
{
    buildMaxHeap(n, A);
    int i;
    for (i = 1; i <= n; i++)
        printf("%d ", A[i]);
    printf("\n");
    int V[n];
    int last = n;
    int ultimo = n;
    while (n > 0)
    {
        V[n - 1] = HeapExtractMax(&last, A);
        n--;
    }
 
    for (i = 0; i < ultimo; i++)
    {
        printf("%d ", V[i]);
    }
}
 
// ###################### Funcoes e Procedimentos do programa ##############
 
/*fun�?es feitas para o programa*/
 
// ############################ Principal ###################################
 
int main()
{
    //come�a na pos 1;
    int n, i;
    scanf("%d", &n);
    int A[n + 1];
    A[0] = 0;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &A[i]);
    }
    HeapSort(n, A);
 
    return 0;
}