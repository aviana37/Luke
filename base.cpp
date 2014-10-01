#include "base.h"

bool AtivarTextoColorido=false;

bool VerificarSubString(const char* texto, int index, const char* substring)
{
    if((index + strlen(substring)) > strlen(texto))
        return false;

    for(unsigned c=0; c<strlen(substring); c++)
    {
        if(texto[c+index] != substring[c])
            return false;
    }
    return true;
}

char* ObterSubString(const char* texto, int index, char limite)
{
    if(index>=strlen(texto))
        return NULL;

    int c=0;
    while(true)
    {
        if(texto[c+index]=='\0')
            break;
        if(texto[c+index]==limite)
            break;
        c++;
    }
    char* ret=new char[c];
    ret[c]='\0';

    c=0;
    while(true)
    {
        if(texto[c+index]=='\0')
            break;
        if(texto[c+index]==limite)
            break;

        ret[c]=texto[c+index];
        c++;
    }
    return ret;
}
