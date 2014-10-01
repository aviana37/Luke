#ifndef EXTRACAO_H_INCLUDED
#define EXTRACAO_H_INCLUDED

#include "base.h"
#include "lista.h"

enum HTML_TAG
{
    HTML_PARAGRAPH,
    HTML_SPAN,
    HTML_HEADER,
    HTML_OTHER,
};

HTML_TAG TagAtual(const char* texto, int index);
void ExtrairTexto(const char* fonte, Texto* saida);

#endif // EXTRACAO_H_INCLUDED
