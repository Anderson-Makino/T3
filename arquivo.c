#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arquivo.h"
#include "circulo.h"
#include "retangulo.h"
#include "formaGeo.h"

FILE *criaSuf (char *diretorio,char *nomebase,FILE *sig2,char *ch)
{
    int i,j=0;
    char *sufixo;
    if (diretorio!=NULL)
    {
    i=(strlen(diretorio)+(strlen(nomebase)+1)+(strlen(ch))+6);
    }
    else
    {
        i=((strlen(nomebase)+1)+(strlen(ch))+6);
    }
    sufixo=(char *) malloc(i*sizeof(char));
    if (diretorio!=NULL)
    {
    for(i=0;i<strlen(diretorio);i++)
    {
        sufixo[j]=diretorio[i];
        j++;
    }
    }
    for(i=0;i<strlen(nomebase);i++)
    {
        sufixo[j]=nomebase[i];
        j++;
    }
    sufixo[j]='-';
    j++;
    for(i=0;i<strlen(ch);i++)
    {
        sufixo[j]=ch[i];
        j++;
    }
    sufixo[j]='.';
    j++;
    sufixo[j]='s';
    j++;
    sufixo[j]='v';
    j++;
    sufixo[j]='g';
    j++;
    sufixo[j]='\0';
    sig2=fopen(sufixo,"w");
    return (sig2);
}

void iniciaSVG(FILE *sig)
{
    fprintf(sig,"<svg>\n");
}

void terminaSVG(FILE *sig)
{
    fprintf(sig,"</svg>");
}

void escreveLinha(FILE *sig,float *x1,float *y1,float *x2,float *y2,char *cor)
{
    fprintf(sig,"<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" stroke:\"%s\" fill=\"%s\"/></line>\n",*x1,*y1,*x2,*y2,cor,cor);
}

void criaDio (char *dio,char *nomebase,int tamdio)
{
    FILE *p;
    char *token,*arqdio;
    int i;
    dio[tamdio+1]='\0';
    token=strtok(nomebase,".");
    arqdio=(char *) malloc((strlen(token)+5)*sizeof(char));
    for (i=0;i<strlen(token);i++)
    {
        arqdio[i]=token[i];
    }
    arqdio[i]='.';
    i++;
    arqdio[i]='t';
    i++;
    arqdio[i]='x';
    i++;
    arqdio[i]='t';
    i++;
    arqdio[i]='\0';
    p=fopen(arqdio,"w");
    fprintf(p,"%s",dio);
    fclose (p);
}