#ifndef LISTA_INCLUDED
#define LISTA_INCLUDED

/*  Andre Viana Sena de Souza - 26/08/2014
**  PAA Projeto #1 - R2D2
*/

#include <stddef.h>

/**
*   \file lista.h
*   \brief Definições da classe template de lista encadeada simples.
**/
/** \class Lista
*   \brief Template de lista encadeada simples.
*/
template <typename T>
class Lista
{
private:
    /**
    * \struct no
    * \brief  Nó do template de lista.
    *
    * Contém um item T e um ponteiro apontando para o próximo nó.
    */
    struct no
    {
        T item; /**< Armazena o item.*/
        no* prox;   /**< Aponta para o próximo no.\n NULL caso seja o último item da lista.*/
    };
    no* lista;  /**<\brief Ponteiro interno da lista.\n NULL caso a lista esteja vazia.*/
    no* ultimo; /**<\brief Aponta ao último item da lista, para acelerar o processo de inserção.*/
    no* iterador;   /**<\brief Iterador.*/
    long int contador;  /**<\brief Contador.*/

public:
    Lista();    /**<\brief Construtor.\n Inicializa os membros internos da lista.*/
    ~Lista();   /**<\brief Destrutor.\n Chama a função void Descarregar().*/

    void Inserir(T item); /**<\brief Insere o item T na lista.*/
    void Descarregar(); /**<\brief Esvazia a lista e reseta os membros internos.*/
    void It_Inicio();   /**<\brief Faz o iterador apontar para o ponteiro inicial da lista*/
    void It_Proximo();  /**<\brief Incrementa o iterador.*/
    T* Iterador();  /**<\brief Retorna o item armazenado pelo ponteiro apontado por iterador.*/
    long Contador();/**<\brief Retorna a quantidade de itens contidos na lista.*/
    T* Vetor(); /**<\brief Retorna um vetor com todos os itens da lista.*/
};

#include "lista.tpp"

#endif // LISTA_INCLUDED
