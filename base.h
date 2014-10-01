#ifndef BASE_INCLUDED
#define BASE_INCLUDED

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "lista.h"

//Codigos de escape
#define KRST "\033[0m"
#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"


extern bool AtivarTextoColorido;
class TST;

enum TipoDeSegmento
{
    SEG_TITULO,
    SEG_PARAGRAFO,
};

struct Segmento
{
    char* texto;
    int linha;
    TipoDeSegmento tipo;
};

struct Ocorrencia
{
    struct Local
    {
        int linha;
        int index;
    };
    char* palavra;
    Lista<Local>* locais;
};

struct Texto
{
    TST* titulo;
    TST* paragrafo;
    Lista<Segmento*>* segmento;
    char* enderecofonte;
};

bool VerificarSubString(const char* texto, int index, const char* substring);
char* ObterSubString(const char* texto, int index, char limite);

#endif // BASE_INCLUDED
