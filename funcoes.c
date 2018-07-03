#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcoes.h"

char *concatena(char *stringmain,char *stringconcatena,int *stringlen)
{
    int i;
    for(i=0;i<strlen(stringconcatena);i++)
    {
        stringmain[*stringlen+i]=stringconcatena[i];
    }
    *stringlen=*stringlen+strlen(stringconcatena);
    return (stringmain);
}

char *concatena2(char *stringmain,char *stringconcatena,int *stringlen)
{
    int i;
    for(i=0;i<strlen(stringconcatena);i++)
    {
        stringmain[*stringlen+i]=stringconcatena[i];
    }
    stringmain[*stringlen+i]='\n';
    *stringlen=*stringlen+strlen(stringconcatena)+1;
    return (stringmain);
}

char *pegaCor1(char *ch)
{
    char *cor1;
    char *info;
    info=strtok(ch," ");
    cor1=malloc(sizeof(char)*strlen(info));
    strcpy(cor1,info);
    return cor1;
}

char *pegaCor2(char *ch)
{
    char *cor2;
    char *info;
    info=strtok(ch," ");
    info=strtok(ch," ");
    cor2=malloc(sizeof(char)*strlen(info));
    strcpy(cor2,info);
    return cor2;
}