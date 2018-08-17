#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "torre.h"

typedef struct torre{
    unsigned long int *ord;
    char *id;
    float *x,*y;      /*coordenadas*/
    char *cor1,*cor2; /*cor da borda e do preenchimento*/
}torre;

Torre createTorre (unsigned long int ordem,char *pid,float px,float py,char *pcor1,char *pcor2)
{
    torre *tor;
    tor=malloc (sizeof(torre));
    tor->ord=malloc(sizeof(unsigned long int));
    tor->id=malloc(sizeof(char)*(strlen(pid)+1));
    tor->x=malloc(sizeof(float));
    tor->y=malloc(sizeof(float));
    tor->cor1=malloc(sizeof(char)*(strlen(pcor1)+1));
    tor->cor2=malloc(sizeof(char)*(strlen(pcor2)+1));
    *(tor->ord)=ordem;
    *(tor->x)=px;
    *(tor->y)=py;
    strcpy(tor->id,pid);
    strcpy(tor->cor1,pcor1);
    strcpy(tor->cor2,pcor2);
    return (tor);
    
}

unsigned long int devolveNOrdemTorre(Torre *ptor)
{
    torre *tor=(torre *)ptor;
    return *(tor->ord);

}
char *devolveIdTorre(Torre *ptor)
{
    torre *tor=(torre *)ptor;
    return (tor->id);
}

float devolveXTorre(Torre *ptor)
{
    torre *tor=(torre *)ptor;
    return *(tor->x);
}

float devolveYTorre(Torre *ptor)
{
    torre *tor=(torre *)ptor;
    return *(tor->y);
}

int devolveStrlencor1Torre(Torre *ptor)
{
    torre *tor = (torre *)ptor;
    int tam;
    tam=strlen (tor->cor1);
    return (tam);
}

int devolveStrlencor2Torre(Torre *ptor)
{
    torre *tor = (torre *)ptor;
    int tam;
    tam=strlen (tor->cor2);
    return (tam);
}

char *devolveCor1Torre(Torre *ptor)
{
    torre *tor = (torre *)ptor;
    return (tor->cor1);
}

char *devolveCor2Torre(Torre *ptor)
{
    torre *tor = (torre *)ptor;
    return (tor->cor2);
}

void mudaCorTorre(Torre *ptor,char *pcor1,char *pcor2)
{
    torre *tor = (torre *)ptor;
    tor->cor1=malloc(sizeof(char)*strlen(pcor1)+1);
    tor->cor2=malloc(sizeof(char)*strlen(pcor2)+1);
    strcpy(tor->cor1,pcor1);
    strcpy(tor->cor2,pcor2);
}