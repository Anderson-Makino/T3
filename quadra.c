#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "quadra.h"

typedef struct quadra{
    unsigned long int *ord;
    char *cep;
    float *x,*y;      /*coordenadas*/
    float *w,*h; /*largura e altura da quadra*/
    char *cor1,*cor2; /*cor da borda e do preenchimento*/
}quadra;

Quadra createQuadra (unsigned long int ordem,char *pcep,float px,float py,float pw,float ph,char *pcor1,char *pcor2)
{
    quadra *quad;
    quad=malloc (sizeof(quadra));
    quad->ord=malloc(sizeof(unsigned long int));
    quad->x=malloc(sizeof(float));
    quad->y=malloc(sizeof(float));
    quad->w=malloc(sizeof(float));
    quad->h=malloc(sizeof(float));
    quad->cep=malloc ((strlen(pcep)+1)*(sizeof(char)+1));
    quad->cor1=malloc(sizeof(char)*(strlen(pcor1)+1));
    quad->cor2=malloc(sizeof(char)*(strlen(pcor2)+1));
    *(quad->ord)=ordem;
    *(quad->x)=px;
    *(quad->y)=py;
    *(quad->w)=pw;
    *(quad->h)=ph;
    strcpy(quad->cep,pcep);
    strcpy(quad->cor1,pcor1);
    strcpy(quad->cor2,pcor2);
    return (quad);
}

int devolveStrlencepQuadra(Quadra *pquad)
{
    quadra *quad=(quadra *)pquad;
    int tam;
    tam=strlen(quad->cep);
    return (tam);
}

char devolveCepQuadra(Quadra *pquad)
{
    quadra *quad=(quadra *)pquad;
    return *(quad->cep);
}

unsigned long int devolveNOrdemQuadra(Quadra *pquad)
{
    quadra *quad=(quadra *)pquad;
    return *(quad->ord);
}

float devolveAlturaQuadra(Quadra *pquad)
{
    quadra *quad=(quadra *)pquad;
    return *(quad->h);
}

float devolveLarguraQuadra(Quadra *pquad)
{
    quadra *quad=(quadra *)pquad;
    return *(quad->w);
}

float devolveXQuadra(Quadra *pquad)
{
    quadra *quad=(quadra *)pquad;
    return *(quad->x);
}

float devolveYQuadra(Quadra *pquad)
{
    quadra *quad=(quadra *)pquad;
    return *(quad->y);
}

int devolveStrlencor1Quadra(Quadra *pquad)
{
    quadra *quad = (quadra *)pquad;
    int tam;
    tam=strlen (quad->cor1);
    return (tam);
}

int devolveStrlencor2Quadra(Quadra *pquad)
{
    quadra *quad = (quadra *)pquad;
    int tam;
    tam=strlen (quad->cor2);
    return (tam);
}

char *devolveCor1Quadra(Quadra *pquad)
{
    quadra *quad = (quadra *)pquad;
    return (quad->cor1);
}

char *devolveCor2Quadra(Quadra *pquad)
{
    quadra *quad = (quadra *)pquad;
    return (quad->cor2);
}