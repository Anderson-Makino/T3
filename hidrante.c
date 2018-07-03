#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hidrante.h"

typedef struct hidrante{
    unsigned long int *ord;
    char *id;
    float *x,*y;      /*coordenadas*/
    char *cor1,*cor2; /*cor da borda e do preenchimento*/
}hidrante;

Hidrante createHidrante (unsigned long int ordem,char *pid,float px,float py,char *pcor1,char *pcor2)
{
    hidrante *hid;
    hid=malloc (sizeof(hidrante));
    hid->ord=malloc(sizeof(unsigned long int));
    hid->id=malloc(sizeof(char)*(strlen(pid)+1));
    hid->x=malloc(sizeof(float));
    hid->y=malloc(sizeof(float));
    hid->cor1=malloc(sizeof(char)*(strlen(pcor1)+1));
    hid->cor2=malloc(sizeof(char)*(strlen(pcor2)+1));
    *(hid->ord)=ordem;
    *(hid->x)=px;
    *(hid->y)=py;
    strcpy(hid->id,pid);
    strcpy(hid->cor1,pcor1);
    strcpy(hid->cor2,pcor2);
    return (hid);
    
}

unsigned long int devolveNOrdemHidrante(Hidrante *phid)
{
    hidrante *hid=(hidrante *)phid;
    return *(hid->ord);

}
int devolveIdHidrante(Hidrante *phid)
{
    hidrante *hid=(hidrante *)phid;
    return *(hid->id);
}

float devolveXHidrante(Hidrante *phid)
{
    hidrante *hid=(hidrante *)phid;
    return *(hid->x);
}

float devolveYHidrante(Hidrante *phid)
{
    hidrante *hid=(hidrante *)phid;
    return *(hid->y);
}

int devolveStrlencor1Hidrante(Hidrante *phid)
{
    hidrante *hid = (hidrante *)phid;
    int tam;
    tam=strlen (hid->cor1);
    return (tam);
}

int devolveStrlencor2Hidrante(Hidrante *phid)
{
    hidrante *hid = (hidrante *)phid;
    int tam;
    tam=strlen (hid->cor2);
    return (tam);
}

char *devolveCor1Hidrante(Hidrante *phid)
{
    hidrante *hid = (hidrante *)phid;
    return (hid->cor1);
}

char *devolveCor2Hidrante(Hidrante *phid)
{
    hidrante *hid = (hidrante *)phid;
    return (hid->cor2);
}