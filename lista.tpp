/*  Andre Viana Sena de Souza - 26/08/2014
**  PAA Projeto #1 - R2D2
*/

template <typename T>
Lista<T>::Lista()
{
    lista = NULL;
    ultimo = NULL;
    iterador = NULL;
    contador = 0;
}

template <typename T>
Lista<T>::~Lista()
{
    Descarregar();
}

template <typename T>
void Lista<T>::Inserir(T item)
{
    if(lista == NULL)
    {
        lista = new no;
        lista->item = item;
        lista->prox = NULL;
        ultimo = lista;
    }
    else
    {
        ultimo->prox = new no;
        ultimo = ultimo->prox;
        ultimo->item = item;
        ultimo->prox = NULL;
    }
    contador++;
}

template <typename T>
void Lista<T>::Descarregar()
{
    no* d = NULL;
    while(lista!=NULL)
    {
        d = lista;
        lista = lista->prox;
        delete d;
    }
    ultimo = NULL;
    iterador = NULL;
    contador = 0;
}

template <typename T>
void Lista<T>::It_Inicio()
{
    iterador = lista;
}

template <typename T>
void Lista<T>::It_Proximo()
{
    if(iterador)
        iterador = iterador->prox;
}

template <typename T>
T* Lista<T>::Iterador()
{
    if(iterador == NULL)
        return NULL;
    else
        return &iterador->item;
}
template <typename T>
long int Lista<T>::Contador()
{
    return contador;
}
template <typename T>
T* Lista<T>::Vetor()
{
    if(lista == NULL)
        return NULL;

    no* it = lista;
    T* vetor = new T[contador];
    for(int c=0; c<contador; c++)
    {
        vetor[c] = it->item;
        it = it->prox;
    }
    return vetor;
}
