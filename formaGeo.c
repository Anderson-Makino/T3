#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "formaGeo.h"
#include "circulo.h"
#include "retangulo.h"
#include "list.h"
#include "concatena.h"


typedef struct formasGeometricas{
    Lista *circle;
    Lista *Rectangle;

}formasGeometricas;

void nCirculo (int *ndefault,char *ch)
{
    *ndefault=atoi(ch);
}

fg createFG ()
{
    formasGeometricas *fg;
    fg->circle=createLista ();
    fg->Rectangle=createLista ();
    return fg;
}

void addCircle (fg *fgeo,Circulo *circ)
{
  formasGeometricas *f = (formasGeometricas *)fgeo;
  Posic *p;
  p=insert(f->circle,circ);
}

void addRet (fg *fgeo,Retangulo *ret)
{
  formasGeometricas *f = (formasGeometricas *)fgeo;
  Posic *p;
  p=insert(f->Rectangle,ret);
}

Circulo GetCircId(fg *fgeo, int id)
{
  formasGeometricas *f=(formasGeometricas *)fgeo;
  Posic *p;
  Circulo *c;
  p=getFirst(f->circle);
  while(p!=NULL)
  {
    c=get(f->circle, p);
    if(devolveIdCirculo(c)==id)
    {
      return c;
    }
    p=getNext(f->circle,p);
  }
  return NULL;
}

Retangulo GetRectId(fg *fgeo, int id)
{
  formasGeometricas *f=(formasGeometricas *)fgeo;
  Posic *p;
  Retangulo *r;

  p=getFirst(f->Rectangle);
  while(p!=NULL)
  {
    r=get(f->Rectangle, p);
    if(devolveIdRetangulo(r)==id)
    {
      return r;
    }
    p=getNext(f->Rectangle,p);
  }
  return NULL;
}

Circulo GetCircOrd(fg *fgeo, int ord)
{
  formasGeometricas *f=(formasGeometricas *)fgeo;
  Posic *p;
  Circulo *c;
  p=getFirst(f->circle);
  while(p!=NULL)
  {
    c=get(f->circle, p);
    if(devolveNOrdemCirculo(c)==ord)
    {
      return c;
    }
    p=getNext(f->circle,p);
  }
  return NULL;
}

Retangulo GetRectOrd(fg *fgeo, int ord)
{
  formasGeometricas *f=(formasGeometricas *)fgeo;
  Posic *p;
  Retangulo *r;

  p=getFirst(f->Rectangle);
  while(p!=NULL)
  {
    r=get(f->Rectangle, p);
    if(devolveNOrdemRetangulo(r)==ord)
    {
      return r;
    }
    p=getNext(f->Rectangle,p);
  }
  return NULL;
}

char *sobreposicao (fg *fge,char *ch,char *dio,int *tamdio)
{
    char *info;
    char *resultado;
    char funcao[2]="o ";
    int nforma;
    int i;
    int j,k;
    float raioj=0,alturaj=0,larguraj=0;
    float raiok=0,alturak=0,largurak=0;
    int xj,yj;
    int xk,yk;
    Circulo *c1 = NULL, *c2 = NULL;
    Retangulo *r1 = NULL, *r2 = NULL;
    fg *fgeo = (fg *)fge;
    resultado=malloc(sizeof(char));
    dio=realloc(dio,((*tamdio+strlen(ch)+25)*sizeof(char)));
    resultado=malloc(4*sizeof(char));
    dio=concatena (dio,funcao,tamdio);
    dio=concatena2 (dio,ch,tamdio);
    info=strtok(ch," ");
    j=atoi(info);
    info=strtok(NULL," ");
    k=atoi(info);
    c1=GetCircId(fgeo,j);
    if(c1==NULL)
    {
      r1=GetRectId(fgeo,j);
      if(r1==NULL)
      { 
        printf("figura nao encontrada\n");
        return 0;
      }
    }
    c2=GetCircId(fgeo,k);
    if(c2==NULL)
    {
      r2=GetRectId(fgeo,k);
      if(r2==NULL)
      { 
        printf("figura nao encontrada\n");
        return 0;
      }
    }
    if (c1!=NULL && c2!=NULL) /*circulo com circulo*/
    {
      raioj=devolveRaio(c1);
      xj=devolveXCirculo(c1);
      yj=devolveYCirculo(c1);
      raiok=devolveRaio(c2);
      xk=devolveXCirculo(c2);
      yk=devolveYCirculo(c2);
        if(raioj+raiok>=abs(xj-xk) && raioj+raiok>=abs(yj-yk))
        {
            resultado="sim";
        }
        else
        {
            resultado="nao";
        }
    }
    else if(r1!=NULL && r2!=NULL) /*retangulo com retangulo*/
    {
      alturaj=devolveAltura(r1);
      larguraj=devolveLargura(r1);
      xj=devolveXRetangulo(r1);
      yj=devolveYRetangulo(r1);
      alturak=devolveAltura(r2);
      largurak=devolveLargura(r2);
      xk=devolveXRetangulo(r2);
      yk=devolveYRetangulo(r2);
        if(xj+larguraj>=xk && yj+alturaj>=yk)
        {
            resultado="sim";
        }
        else
        {
            resultado="nao";
        }
    }
    else if(c1!=NULL && r2!=NULL)  /*circulo com retangulo*/
    {
      raioj=devolveRaio(c1);
      xj=devolveXCirculo(c1);
      yj=devolveYCirculo(c1);
      alturak=devolveAltura(r2);
      largurak=devolveLargura(r2);
      xk=devolveXRetangulo(r2);
      yk=devolveYRetangulo(r2);
        if(xj+raioj>=xk && yj+raioj>=yk)
        {
            resultado="sim";
        }
        else
        {
            resultado="nao";
        }
    }
    else if(r1!=NULL && c2!=NULL)  /*retangulo com circulo*/
    {
      alturaj=devolveAltura(r1);
      larguraj=devolveLargura(r1);
      xj=devolveXRetangulo(r1);
      yj=devolveYRetangulo(r1);
      raiok=devolveRaio(c2);
      xk=devolveXCirculo(c2);
      yk=devolveYCirculo(c2);
        if(xk+raiok>=xj && yk+raiok>=yj)
        {
            resultado="sim";
        }
        else
        {
            resultado="nao";
        }
    }
     dio=concatena2 (dio,resultado,tamdio);
     return (dio);
}

char *pontointerno (fg *fge,char *ch,char *dio,int *tamdio)
{
    char *info;
    char funcao[2]="i ";
    char *resultado; /*resultado da funcao (se é ou nao ponto interno)*/
    int id,i;
    int nforma;
    float raio,altura,largura;
    float x,y;
    float xforma,yforma; /*coordenadas do centro da figura geometrica*/
    Circulo *c;
    Retangulo *ret;
    fg *fgeo = (fg *)fge;
    resultado=malloc (4*sizeof(char));
    dio=realloc(dio,((*tamdio+strlen(ch)+25)*sizeof(char)));
    dio=concatena (dio,funcao,tamdio);
    dio=concatena (dio,ch,tamdio);
    dio[*tamdio-1]=' ';
    info=strtok(ch," ");
    id=atoi(info);
    info=strtok(NULL," ");
    x=atof(info);
    info=strtok(NULL," ");
    y=atof(info);
        c=GetCircId(fgeo,id);
        if(c==NULL)
        {
          ret=GetRectId(fgeo,id);
        }
        if (c!=NULL)
          {
            raio=devolveRaio(c);
            xforma=devolveXCirculo(c);
            yforma=devolveYCirculo(c);
            if(x>=(xforma-raio) && x<=(xforma+raio) && y>=(yforma-raio) && y<=(yforma+raio))
            {
                resultado="sim";
            }
            else
            {
                resultado="nao";
            }
          }
    else if(ret!=NULL)
         {   
            ret=GetRectId(fgeo,id);
            altura=devolveAltura(ret);
            largura=devolveLargura(ret);
            xforma=devolveXRetangulo(ret);
            yforma=devolveYRetangulo(ret);
            if(x>=xforma && x<=(xforma+largura) && y>=xforma && y<=(yforma+altura))
            {
                resultado="sim";
            }
            else
            {
                resultado="nao";
            }
          }
    else 
    {
      resultado=malloc(23*sizeof(char));
      resultado=" figura nao encontrada";
    }
        dio=concatena2 (dio,resultado,tamdio);
        return (dio);
}

char *distancia (fg *fge,char *ch,char *dio,int *tamdio)
{
    char *info;
    int i;
    int j,k;   /*indentificadores*/
    float a,b;   /*distancia entre coordenadas x e y*/
    float x1,y1;  /*coordenada x e y da figura 1*/
    float x2,y2;  /*coordenada x e y da figura 2*/
    int nforma;           /*numero da forma geometrica n*/
    float result;           /*seno^2 + cos^2*/
    float distance;       /*distancia*/
    char *distanciachar;
    char *resultado;
    char funcao[2]="d ";
    int forma1=0,forma2=0;  /*forma da figura*/
    Circulo *c1,*c2;
    Retangulo *ret1,*ret2;
    fg *fgeo = (fg *)fge;
    distanciachar=malloc(10*sizeof(char));
    dio=realloc(dio,((*tamdio+strlen(ch)+25)*sizeof(char)));
    dio=concatena (dio,funcao,tamdio);
    dio=concatena2 (dio,ch,tamdio);
    info=strtok(ch," ");
    j=atoi(info);
    info=strtok(NULL," ");
    k=atoi(info);
    c1=GetCircId(fgeo,j);
        if(c1==NULL)
        {
          ret1=GetRectId(fgeo,j);
        }
        if (c1!=NULL)
        {
            x1=devolveXCirculo(c1);
            y1=devolveYCirculo(c1);
        }
        else if(ret1!=NULL)
        {
          x1=devolveXRetangulo(ret1);
          y1=devolveYRetangulo(ret1);
        }
    c2=GetCircId(fgeo,j);
        if(c2==NULL)
        {
          ret2=GetRectId(fgeo,j);
        }
        if (c2!=NULL)
        {
            x2=devolveXCirculo(c2);
            y2=devolveYCirculo(c2);
        }
        else if(ret2!=NULL)
        {
          x2=devolveXRetangulo(ret2);
          y2=devolveYRetangulo(ret2);
        }
    if ((c1==NULL || ret1==NULL) || (c2==NULL || ret2==NULL))
    {
        resultado=malloc(23*sizeof(char));
        resultado=" figura nao encontrada";
        dio=concatena2 (dio,resultado,tamdio);
    }
    else
    {
    a=x1-x2;
    b=y1-y2;
    a=abs(a);
    b=abs(b);
    result=pow(a,2)+pow(b,2);
    distance=sqrt(result);
    sprintf(distanciachar,"%.4f",distance);
    }
    dio=concatena2 (dio,distanciachar,tamdio);
    return (dio);
}

void pegaElementsCirc(char *ch,int *element0,char *element1,char *element2,char *element3,char *element4,char *element5,char *element6,int cont)
{
    char *info;
    *element0=cont;
    info=strtok(ch," ");
    element1=info;
    info=strtok(NULL," ");
    element2=info;
    info=strtok(NULL," ");
    element3=info;
    info=strtok(NULL," ");
    element4=info;
    info=strtok(NULL," ");
    element5=info;
    info=strtok(NULL," ");
    element6=info;
}

void pegaElementsRet(char *ch,int *element0,char *element1,char *element2,char *element3,char *element4,char *element5,char *element6,char *element7,int cont)
{
    char *info;
    *(element0)=cont;
    info=strtok(ch," ");
    element1=info;
    info=strtok(NULL," ");
    element2=info;
    info=strtok(NULL," ");
    element3=info;
    info=strtok(NULL," ");
    element4=info;
    info=strtok(NULL," ");
    element5=info;
    info=strtok(NULL," ");
    element6=info;
    info=strtok(NULL," ");
    element7=info;
    printf("element7:%s\n",element7);
}
