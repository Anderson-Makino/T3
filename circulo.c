#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "circulo.h"

typedef struct circulo{
    unsigned long int *ord;
    int *i;       /*indentificador*/
    float *x,*y;   /*coordenadas*/
    float *r;      /*raio do Circulo*/
    char *cor1,*cor2;    /*cor da borda e do preenchimento*/
}circulo;

Circulo createCirculo (unsigned long int ordem,int pi,char *pcor1,char *pcor2,float pr,float px,float py)
{
    circulo *circ;
    circ=(circulo *)malloc (sizeof(circulo));
    circ->ord=malloc (sizeof(unsigned long int));
    circ->i=malloc (sizeof(int));
    circ->x=malloc (sizeof(float));
    circ->y=malloc (sizeof(float));
    circ->r=malloc (sizeof(float));
    circ->cor1=malloc ((strlen(pcor1)+1)*sizeof(char));
    circ->cor2=malloc ((strlen(pcor2)+1)*sizeof(char));
    *(circ->ord)=ordem;
    *(circ->i)=pi;
    *(circ->x)=px;
    *(circ->y)=py;
    *(circ->r)=pr;
    strcpy(circ->cor1,pcor1);
    strcpy(circ->cor2,pcor2);
    return (circ);
}

int devolveStrlencor1Circulo(Circulo *pcirc)
{
    circulo *circ = (circulo *)pcirc;
    int tam;
    tam=strlen(circ->cor1);
    return (tam);
}

int devolveStrlencor2Circulo(Circulo *pcirc)
{
    circulo *circ = (circulo *)pcirc;
    int tam;
    tam=strlen(circ->cor2);
    return (tam);
}

char *devolveCor1Circulo(Circulo *pcirc)
{
    circulo *circ = (circulo *)pcirc;
    return (circ->cor1);
}

char *devolveCor2Circulo(Circulo *pcirc)
{
    circulo *circ = (circulo *)pcirc;
    return (circ->cor2);
}

float devolveRaio(Circulo *pcirc)
{
    circulo *circ = (circulo *)pcirc;
    return *(circ->r);
}

unsigned long int devolveNOrdemCirculo(Circulo *pcirc)
{
    circulo *circ = (circulo *)pcirc;
    return *(circ->ord);
}

int devolveIdCirculo(Circulo *pcirc)
{
    circulo *circ = (circulo *)pcirc;
    return *(circ->i);
}

float devolveXCirculo(Circulo *pcirc)
{
    circulo *circ = (circulo *)pcirc;
    return *(circ->x);
}

float devolveYCirculo(Circulo *pcirc)
{
    circulo *circ = (circulo *)pcirc;
    return *(circ->y);
}
