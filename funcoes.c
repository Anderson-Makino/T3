#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcoes.h"

char *concatena(char *stringmain,char *stringconcatena,int *stringlen)
{
    int i;
    int j=strlen(stringconcatena);
    for(i=0;i<j;i++)
    {
        stringmain[*stringlen+i]=stringconcatena[i];
    }
    *stringlen=*stringlen+j;
    return (stringmain);
}

char *concatena2(char *stringmain,char *stringconcatena,int *stringlen)
{
    int i;
    int j=strlen(stringconcatena);
    for(i=0;i<j;i++)
    {
        stringmain[*stringlen+i]=stringconcatena[i];
    }
    stringmain[*stringlen+i]='\n';
    *stringlen=*stringlen+j+1;
    return (stringmain);
}

char *pegaCor(char *ch,char *info)
{
    char *cor;
    cor=(char *) malloc(sizeof(char)*strlen(info));
    strcpy(cor,info);
    return cor;
}