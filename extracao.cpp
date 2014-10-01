#include "extracao.h"


HTML_TAG TagAtual(const char* texto, int index)
{
    printf(KRST);
    if(texto[index] == 'h')
        switch(texto[index+1])
        {
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
            return HTML_HEADER;
        }
    else if(VerificarSubString(texto, index, "span"))
        return HTML_SPAN;
    else if(texto[index] == 'p')
        if(isspace(texto[index+1]) || texto[index+1]=='>' || texto[index+1]=='&')
            return HTML_PARAGRAPH;
    return HTML_OTHER;
}

void ExtrairTexto(const char* fonte, Texto* saida)
{
    int buffercont;
    int it=0, linha=0;
    HTML_TAG tag;
    Segmento* buffer=NULL;
    saida->segmento = NULL;

    while(true)
    {
        if(fonte[it]=='\0')
            break;

        else if(fonte[it]=='<')
        {
            it++;
            if(fonte[it]!='/')
            {
                tag=TagAtual(fonte, it);
                if(tag!=HTML_OTHER)
                {
                    while(fonte[it]!='>')
                        it++;
                    it++;
                    while(true)
                    {
                        buffercont=0;
                        while(fonte[it+buffercont]!='<')
                            buffercont++;
                        if(fonte[((it+buffercont)+1)]=='/')
                            break;
                        else
                        {
                            it++;
                            tag=TagAtual(fonte, it);
                            while(fonte[it]!='>')
                                it++;
                            it++;
                        }
                    }

                    if(tag!=HTML_OTHER)
                    {
                        if(fonte[it]=='&')
                        {
                            if(VerificarSubString(fonte, it, "&lt;"))
                            {
                                it=it+4;
                                tag=TagAtual(fonte, it);
                                while(fonte[it]!=';')
                                    it++;
                                it++;

                                buffercont=0;
                                int e=0;
                                while(true)
                                {
                                    if(VerificarSubString(fonte, it+e, "&lt;/"))
                                        break;
                                    else if(VerificarSubString(fonte, it+e, "&amp;hellip;"))
                                    {
                                        buffercont=buffercont+3;
                                        buffercont=buffercont-11;
                                    }
                                    else
                                        buffercont++;
                                    e++;
                                }
                            }
                        }

                        buffer = new Segmento;
                        buffer->texto = new char[buffercont];
                        linha++;
                        int c=0, e=0;
                        while(true)
                        {
                            if(c>=buffercont)
                                break;
                            if(VerificarSubString(fonte, it+e, "&amp;hellip;"))
                            {
                                e=e+12;
                                buffer->texto[c++]='.';
                                buffer->texto[c++]='.';
                                buffer->texto[c++]='.';
                            }
                            else
                            {
                                buffer->texto[c++] = fonte[it+e];
                                e++;
                            }
                        }

                        buffer->texto[c] = '\0';
                        buffer->linha = linha;
                        if(tag==HTML_HEADER)
                            buffer->tipo = SEG_TITULO;

                        else if(tag==HTML_PARAGRAPH)
                            buffer->tipo = SEG_PARAGRAFO;

                        if(!saida->segmento)
                            saida->segmento = new Lista<Segmento*>;
                        saida->segmento->Inserir(buffer);

                        it = it+buffercont;
                    }
                }
            }
            else
            {
                while(fonte[it]!='>')
                    it++;
            }
        }
        it++;
    }
}
