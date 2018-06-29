#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arquivo.h"
#include "circulo.h"
#include "retangulo.h"
#include "formaGeo.h"

FILE *criaSuf (char *diretorio,char *nomebase,char *sufixo,FILE *sig2,char *ch)
{
    int i,j=0;
    char *token;
    token=strtok(ch," ");
    token=strtok(NULL," ");
    sufixo=malloc((strlen(diretorio)+(strlen(nomebase)+1)+(strlen(token))+6)*sizeof(char));
    for(i=0;i<strlen(diretorio);i++)
    {
        sufixo[j]=diretorio[i];
        j++;
    }
    for(i=0;i<strlen(nomebase);i++)
    {
        sufixo[j]=nomebase[i];
        j++;
    }
    sufixo[j]='-';
    j++;
    for(i=0;i<strlen(token);i++)
    {
        sufixo[j]=token[i];
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

FILE *copiaFile(FILE *sig,FILE *sig2,int cont)
{
    int i;
    Circulo *c;
    Retangulo *r;
    fg *f;
    iniciaSVG(sig2);
    for(i=0;i<cont;i++)
    {
    c=GetCircOrd (f,i);
    escreveSVGCirc (sig2,c);
    if(c==NULL)
    {
    r=GetRectOrd (f,i);
    escreveSVGQuad (sig2,r);
    }
    }
    return (sig2);
}

FILE *tracaLinha(FILE *sig,char *ch,int cont)
{
    char *token;
    char *cor;
    int tamcor;
    int id,nforma;
    float x1,y1,x2,y2;
    int i;
    fg *f;
    Circulo *c1,*c2;
    Retangulo *r1,*r2;
    token=strtok(ch," ");
    id=atoi(token);
    for(i=0;i<cont;i++)
    {
    c1=GetCircOrd (f,id);
    if(c1==NULL)
    {
    r1=GetRectOrd (f,id);
    }
    }
    if (c1==NULL && r1==NULL)
    {
        printf("forma geometrica nao encontrada\n");
        return 0;
    }
    if (c1!=NULL)
    {
        x1=devolveXCirculo(c1);
        y1=devolveYCirculo(c1);
        tamcor=devolveStrlencor1Circulo(c1);
        cor=malloc(sizeof(char)*(tamcor+1));
        cor=devolveCor1Circulo(c1);
    }
    else
    {
        x1=devolveXRetangulo(r1);
        y1=devolveYRetangulo(r1);
        tamcor=devolveStrlencor1Retangulo(r1);
        cor=malloc(sizeof(char)*(tamcor+1));
        cor=devolveCor1Retangulo(r1);
    }
    for(i=0;i<cont;i++)
    {
    c2=GetCircOrd (f,i);
    if(c2==NULL)
    {
        r2=GetRectOrd (f,i);
        x2=devolveXRetangulo(r2);
        y2=devolveYRetangulo(r2);
    }
    else
    {
        x2=devolveXCirculo(c2);
        y2=devolveYCirculo(c2);
    }
    escreveLinha(sig,x1,y1,x2,y2,cor);
    }
    free(cor);
    return(sig);
}

void iniciaSVG(FILE *sig)
{
    fprintf(sig,"<svg>");
}

void insereSVG (FILE *sig,int cont,fg *fgeo)
{
    int i;
    Circulo *c;
    Retangulo *r;
    for (i=0;i<cont;i++)
    {
        c=GetCircId(fgeo,i);
        if(c==NULL)
        {
        r=GetRectId(fgeo,i);
        escreveSVGQuad(sig,r);
        }
        else
        {
            escreveSVGCirc(sig,c);
        }
    }
}

void terminaSVG(FILE *sig)
{
    fprintf(sig,"</svg>");
}

void escreveLinha(FILE *sig,float x1,float y1,float x2,float y2,char *cor)
{
    fprintf(sig,"<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" stroke:\"%s\" fill=\"%s\"/></line>\n",x1,y1,x2,y2,cor,cor);
}

void escreveSVGCirc (FILE *sig,Circulo *circ)
{
    char *cor1,*cor2;
    float raio,x,y;
    int tam1,tam2;
    Circulo *c=(Circulo *) *circ;
    tam1=devolveStrlencor1Circulo(c);
    tam2=devolveStrlencor2Circulo(c);
    cor1=malloc(sizeof(char)*(tam1+1));
    cor2=malloc(sizeof(char)*(tam2+1));
    strcpy(cor1,devolveCor1Circulo(c));
    strcpy(cor2,devolveCor2Circulo(c));
    raio=devolveRaio(c);
    x=devolveXCirculo(c);
    y=devolveYCirculo(c);
    fprintf(sig,"<circle cx=\"%f\" cy=\"%f\" r=\"%f\"  stroke-width=\"3\" stroke=\"%s\" fill=\"%s\"/>\n",x,y,raio,cor1,cor2);
}

void escreveSVGQuad (FILE *sig,Retangulo *ret)
{
    char *cor1,*cor2;
    float altura,largura,x,y;
    int tam1,tam2;
    Retangulo *r=(Retangulo *)ret;
    tam1=devolveStrlencor1Retangulo(r);
    tam2=devolveStrlencor2Retangulo(r);
    cor1=malloc(sizeof(char)*(tam1+1));
    cor2=malloc(sizeof(char)*(tam2+1));
    strcpy(cor1,devolveCor1Retangulo(r));
    strcpy(cor2,devolveCor2Retangulo(r));
    altura=devolveAltura(r);
    largura=devolveLargura(r);
    x=devolveXRetangulo(r);
    y=devolveYRetangulo(r);
    fprintf(sig,"<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" stroke=\"%s\" fill=\"%s\"/></rect>\n",x,y,largura,altura,cor1,cor2);
}

void criaDio (char *dio,char *nomebase,int tamdio)
{
    FILE *p;
    char *token,*arqdio;
    int i;
    dio[tamdio+1]='\0';
    token=strtok(nomebase,".");
    arqdio=malloc(sizeof(char)*(strlen(token)+5));
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
    free(arqdio);
    free(dio);
}

void finalArq ()
{
    exit (0);
}