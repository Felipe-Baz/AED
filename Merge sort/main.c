merge(int lista[], int first, int mid, int last)
{
    /*!
    Parametros:
        Lista:
        First:
        Mid:
        Last:
    Funcionamento:

    Retorno:

    */
    
    int i, j, k, *w;
    //alocamento do vetor de forma dinamica
    w = malloc ((last-first) * sizeof (int));

    //loop para adicionar a 1 metade de elementos no vetor
    for (i = first; i < mid; ++i)
        w[i-first] = lista[i];
    //loop para adicionar a 2 metade de elementos no vetor
    for (j = mid; j < last; ++j)
        w[last-first+mid-j-1] = lista[j];
    //configura os valores de i e j
    i = 0;
    j = last-first-1;
    for (k = first; k < last; ++k)
        if (w[i] <= w[j]) lista[k] = w[i++];
            else lista[k] = w[j--];
    free (w);
}


//criação da função Merge Sort
void mergeSort(int *lista, int first, int last)
{
    /*!
    Parametros:
        lista: Contem o vetor de elementos que será ordenado.
        First: Contem o indice do primeiro elemento que será analizado
        Last: Contem o indice do ultimo elemento que será analizado
    Funcionamento:
        A função ira utilizar do metodo de divisão e conquista,
        para ordenar o vetor informado no parametro "lista". Essa
        ordenação funciona após a chegada em um caso trivial, que
        seria a lista tratada ter somente 1 elemento. Após essa
        chegada o algoritmo ira usar da função merge para combinar
        de forma ordenada e inteligente esses elementos, resultando
        em pequenos vetores ordenados que iram sendo combinados até
        retornarmos toda a arvore criada pela recursão da função mergeSort.
    retorno:
        A função não possui retorno por se tratar de uma função void, porem
        altera a variavel informada no parametro "lista".
    */

    if (first < last)
    {
        int mid = (first + last)/2;
        mergeSort(lista, first, mid);
        mergeSort(lista, mid+1, last);
        merge(lista, first, mid, last);
    }
}


int main(int argc, char const *argv[])
{
    int i, tamanho;
    scanf("%d", &tamanho);
    int lista[tamanho];
    for (i = 0; i < tamanho; i++)
        scanf("%d", &lista[i]);
    mergeSort(&lista, 0, 9);
    for (i = 0; i < tamanho; i++)
        printf("%d \n", lista[i]);
    return 0;
}
