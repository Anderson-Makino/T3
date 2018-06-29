#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "retangulo.h"

typedef struct retangulo{
    int *ord;
    int *i;
    float *x,*y;    /*coordenadas*/
    float *w,*h;      /*largura e altura do Retangulo*/
    char *cor1,*cor2;    /*cor da borda e do preenchimento*/
}retangulo;

Retangulo createRetangulo (int ordem,int pi,char *pcor1,char *pcor2,float pw,float ph,float px,float py)
{
    retangulo *ret;
    ret=malloc (sizeof(Retangulo));
    ret->ord=malloc(sizeof(int));
    ret->i=malloc(sizeof(int));
    ret->x=malloc(sizeof(float));
    ret->y=malloc(sizeof(float));
    ret->w=malloc(sizeof(float));
    ret->h=malloc(sizeof(float));
    ret->cor1=malloc ((strlen(pcor1)+1)*sizeof(char));
    ret->cor2=malloc ((strlen(pcor2)+1)*sizeof(char));
    *(ret->ord)=ordem;
    *(ret->i)=pi;
    *(ret->x)=px;
    *(ret->y)=py;
    *(ret->w)=pw;
    *(ret->h)=ph;
    strcpy(ret->cor1,pcor1);
    strcpy(ret->cor2,pcor2);
    return (ret);
}

int devolveStrlencor1Retangulo(Retangulo *pret)
{
    retangulo *ret=(retangulo *)pret;
    int tam;
    tam=strlen(ret->cor1);
    return (tam);
}

int devolveStrlencor2Retangulo(Retangulo *pret)
{
    retangulo *ret=(retangulo *)pret;
    int tam;
    tam=strlen(ret->cor1);
    return (tam);
}

int devolveNOrdemRetangulo(Retangulo *pret)
{
    retangulo *ret=(retangulo *)pret;
    return *(ret->ord);
}

int devolveIdRetangulo(Retangulo *pret)
{
    retangulo *ret=(retangulo *)pret;
    return *(ret->i);
}

char *devolveCor1Retangulo(Retangulo *pret)
{
    retangulo *ret=(retangulo *)pret;
    return ret->cor1;
}

char *devolveCor2Retangulo(Retangulo *pret)
{
    retangulo *ret=(retangulo *)pret;
    return ret->cor2;
}

float devolveAltura(Retangulo *pret)
{
    retangulo *ret=(retangulo *)pret;
    return *(ret->h);
}

float devolveLargura(Retangulo *pret)
{
    retangulo *ret=(retangulo *)pret;
    return *(ret->w);
}

float devolveXRetangulo(Retangulo *pret)
{
    retangulo *ret=(retangulo *)pret;
    return *(ret->x);
}

float devolveYRetangulo(Retangulo *pret)
{
    retangulo *ret=(retangulo *)pret;
    return *(ret->y);
}
