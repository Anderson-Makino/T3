#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "formaGeo.h"
#include "circulo.h"
#include "retangulo.h"
#include "quadra.h"
#include "hidrante.h"
#include "semaforo.h"
#include "torre.h"
#include "list.h"
#include "funcoes.h"


typedef struct formasGeometricas{
    Lista *circle;
    Lista *Rectangle;
    Lista *Block;
    Lista *Hydrant;
    Lista *Semaphore;
    Lista *Tower;

}formasGeometricas;

void nCirculo (int *ndefault,char *ch)
{
    *ndefault=atoi(ch);
}

fg createFG ()
{
    formasGeometricas *fgeo;
    fgeo=malloc(sizeof (formasGeometricas));
    fgeo->circle=createLista ();
    fgeo->Rectangle=createLista ();
    fgeo->Block=createLista ();
    fgeo->Hydrant=createLista ();
    fgeo->Semaphore=createLista ();
    fgeo->Tower=createLista ();
    return fgeo;
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

void addBlock(fg *fgeo,Quadra *quad)
{
  formasGeometricas *f = (formasGeometricas *)fgeo;
  Posic *p;
  p=insert(f->Block,quad);
}

void addHydrant(fg *fgeo,Hidrante *hid)
{
  formasGeometricas *f = (formasGeometricas *)fgeo;
  Posic *p;
  p=insert(f->Hydrant,hid);
}

void addSemaphore(fg *fgeo,Semaforo *sem)
{
  formasGeometricas *f = (formasGeometricas *)fgeo;
  Posic *p;
  p=insert(f->Semaphore,sem);
}

void addTower(fg *fgeo,Torre *tor)
{
  formasGeometricas *f = (formasGeometricas *)fgeo;
  Posic *p;
  p=insert(f->Tower,tor);
}

Circulo GetCircId(fg *fgeo,int id)
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

Retangulo GetRectId(fg *fgeo,int id)
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

Quadra *GetBlockId(fg *fgeo,char *id)
{
  formasGeometricas *f=(formasGeometricas *)fgeo;
  Posic *p;
  Quadra *quad;
  p=getFirst(f->Block);
  while(p!=NULL)
  {
    quad=get(f->Block, p);
    if(strcmp(devolveCepQuadra(quad),id)==0)
    {
      return quad;
    }
    p=getNext(f->Block,p);
  }
  return NULL;
}

Hidrante *GetHydId(fg *fgeo,char *id)
{
  formasGeometricas *f=(formasGeometricas *)fgeo;
  Posic *p;
  Hidrante *hid;
  p=getFirst(f->Hydrant);
  while(p!=NULL)
  {
    hid=get(f->Hydrant, p);
    if(strcmp(devolveIdHidrante(hid),id)==0)
    {
      return hid;
    }
    p=getNext(f->Hydrant,p);
  }
  return NULL;
}

Semaforo *GetSemId(fg *fgeo,char *id)
{
  formasGeometricas *f=(formasGeometricas *)fgeo;
  Posic *p;
  Semaforo *sem;

  p=getFirst(f->Semaphore);
  while(p!=NULL)
  {
    sem=get(f->Semaphore, p);
    if(strcmp(devolveIdSemaforo(sem),id)==0)
    {
      return sem;
    }
    p=getNext(f->Semaphore,p);
  }
  return NULL;
}

Torre *GetTorId(fg *fgeo,char *id)
{
  formasGeometricas *f=(formasGeometricas *)fgeo;
  Posic *p;
  Torre *tor;

  p=getFirst(f->Tower);
  while(p!=NULL)
  {
    tor=get(f->Tower, p);
    if(strcmp(devolveIdTorre(tor),id)==0)
    {
      return tor;
    }
    p=getNext(f->Tower,p);
  }
  return NULL;
}

Circulo GetCircOrd(fg *fgeo, unsigned long int ord)
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

Retangulo GetRectOrd(fg *fgeo, unsigned long int ord)
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

Quadra GetBlockOrd(fg *fgeo, unsigned long int ord)
{
  formasGeometricas *f=(formasGeometricas *)fgeo;
  Posic *p;
  Quadra *quad;

  p=getFirst(f->Block);
  while(p!=NULL)
  {
    quad=get(f->Block, p);
    if(devolveNOrdemQuadra(quad)==ord)
    {
      return quad;
    }
    p=getNext(f->Block,p);
  }
  return NULL;
}

Hidrante GetHidOrd(fg *fgeo,unsigned long int ord)
{
  formasGeometricas *f=(formasGeometricas *)fgeo;
  Posic *p;
  Hidrante *hid;

  p=getFirst(f->Hydrant);
  while(p!=NULL)
  {
    hid=get(f->Hydrant, p);
    if(devolveNOrdemHidrante(hid)==ord)
    {
      return hid;
    }
    p=getNext(f->Hydrant,p);
  }
  return NULL;
}

Semaforo GetSemOrd(fg *fgeo, unsigned long int ord)
{
  formasGeometricas *f=(formasGeometricas *)fgeo;
  Posic *p;
  Semaforo *sem;

  p=getFirst(f->Semaphore);
  while(p!=NULL)
  {
    sem=get(f->Semaphore, p);
    if(devolveNOrdemSemaforo(sem)==ord)
    {
      return sem;
    }
    p=getNext(f->Semaphore,p);
  }
  return NULL;
}

Torre GetTorOrd(fg *fgeo, unsigned long int ord)
{
  formasGeometricas *f=(formasGeometricas *)fgeo;
  Posic *p;
  Torre *tor;
  p=getFirst(f->Tower);
  while(p!=NULL)
  {
    tor=get(f->Tower, p);
    if(devolveNOrdemTorre(tor)==ord)
    {
      return tor;
    }
    p=getNext(f->Tower,p);
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
        if((xj+raioj>=xk && yj+raioj>=yk) || (xj-raioj<=xk+largurak && yj-raioj<=yk+alturak))  /*circulo com retangulo*/
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
        if((xk+raiok>=xj && yk+raiok>=yj) || (xk-raiok<=xj+larguraj && yk-raiok<=yj+alturaj))
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
          if (ret1!=NULL)
          {
          x1=devolveXRetangulo(ret1);
          y1=devolveYRetangulo(ret1);
          }
        }
        else
        {
            x1=devolveXCirculo(c1);
            y1=devolveYCirculo(c1);
        }
    c2=GetCircId(fgeo,k);
        if(c2==NULL)
        {
          ret2=GetRectId(fgeo,k);
          if (ret2!=NULL)
          {
          x2=devolveXRetangulo(ret2);
          y2=devolveYRetangulo(ret2);
          }
        }
        else
        {
            x2=devolveXCirculo(c2);
            y2=devolveYCirculo(c2);
        }
    if ((c1==NULL && ret1==NULL) || (c2==NULL && ret2==NULL))
    {
        dio=concatena2 (dio," figura nao encontrada",tamdio);
    }
    else
    {
    a=x1-x2;
    b=y1-y2;
    a=fabs(a);
    b=fabs(b);
    result=pow(a,2)+pow(b,2);
    distance=sqrt(result);
    sprintf(distanciachar,"%.4f",distance);
    }
    dio=concatena2 (dio,distanciachar,tamdio);
    return (dio);
}

FILE *tracaLinha(FILE *sig,int id,unsigned long int cont,fg *fgeo)
{
    char *cor;
    int tamcor;
    int nforma;
    float x1,y1,x2,y2;
    int i;
    Circulo *c1,*c2;
    Retangulo *r1,*r2;
    fg *f=(fg *)fgeo;
    for(i=0;i<cont;i++)
    {
    c1=GetCircId (f,id);
    if(c1==NULL)
    {
    r1=GetRectId (f,id);
    }
    if (c1!=NULL || r1!=NULL)
    {
        break;
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
    escreveLinha(sig,&x1,&y1,&x2,&y2,cor);
    }
    free(cor);
    return(sig);
}

void insereSVG (FILE *sig,unsigned long int cont,fg *fgeo)
{
    unsigned long int i;
    formasGeometricas *f=(formasGeometricas *)fgeo;
    Circulo *c;
    Retangulo *r;
    Quadra *quad;
    Hidrante *hid;
    Semaforo *sem;
    Torre *tor;
    for (i=0;i<cont;i++)
    {
      c=GetCircOrd(f,i);
        if(c==NULL)
        {
          r=GetRectOrd(f,i);
          if (r==NULL)
          {
            quad=GetBlockOrd(f,i);
            if (quad==NULL)
            {
              hid=GetHidOrd(f,i);
              if (hid==NULL)
              {
                sem=GetSemOrd(f,i);
                if (sem==NULL)
                {
                  tor=GetTorOrd(f,i);
                  if(tor!=NULL)
                  {
                  escreveSVGTower (sig,tor);
                  }
                }
                else 
                {
                  escreveSVGSemaphore (sig,sem);
                }
              }
              else
              {
                escreveSVGHydrant(sig,hid);
              }
            }
            else
            {
              escreveSVGBlock(sig,quad);
            }
          }
            else 
            {
            escreveSVGQuad(sig,r);
            }
        }
      else
      {
          escreveSVGCirc(sig,c);
      }
    }
}

void escreveSVGCirc (FILE *sig,Circulo *circ)
{
    char *cor1,*cor2;
    float raio,x,y;
    int tam1,tam2;
    Circulo *c=(Circulo *) circ;
    tam1=devolveStrlencor1Circulo(c);
    tam2=devolveStrlencor2Circulo(c);
    cor1=malloc(sizeof(char)*(tam1+1));
    cor2=malloc(sizeof(char)*(tam2+1));
    cor1=devolveCor1Circulo(c);
    cor2=devolveCor2Circulo(c);
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
    cor1=devolveCor1Retangulo(r);
    cor2=devolveCor2Retangulo(r);
    altura=devolveAltura(r);
    largura=devolveLargura(r);
    x=devolveXRetangulo(r);
    y=devolveYRetangulo(r);
    fprintf(sig,"<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" stroke=\"%s\" fill=\"%s\"/></rect>\n",x,y,largura,altura,cor1,cor2);
}

void escreveSVGBlock (FILE *sig,Quadra *pquad)
{
    char *cor1,*cor2,*cep;
    float altura,largura,x,y;
    int tam1,tam2,tam3;
    Quadra *quad=(Quadra *)pquad;
    tam1=devolveStrlencepQuadra(quad);
    tam2=devolveStrlencor1Quadra(quad);
    tam3=devolveStrlencor2Quadra(quad);
    cep=malloc(sizeof(char)*(tam1+1));
    cor1=malloc(sizeof(char)*(tam2+1));
    cor2=malloc(sizeof(char)*(tam3+1));
    cep=devolveCepQuadra(quad);
    cor1=devolveCor1Quadra(quad);
    cor2=devolveCor2Quadra(quad);
    altura=devolveAlturaQuadra(quad);
    largura=devolveLarguraQuadra(quad);
    x=devolveXQuadra(quad);
    y=devolveYQuadra(quad);
    fprintf(sig,"<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" stroke=\"%s\" fill=\"%s\"/></rect>\n",x,y,largura,altura,cor1,cor2);
    fprintf(sig,"<text x=\"%f\" y=\"%f\" fill=\"%s\">%s</text>\n",x+1,y+10,cor1,cep);
    free(cep);
    free(cor1);
    free(cor2);
}

void escreveSVGSemaphore (FILE *sig,Semaforo *psem)
{
    char *cor1,*cor2;
    float x,y;
    int tam1,tam2;
    Semaforo *sem=(Semaforo *)psem;
    tam1=devolveStrlencor1Semaforo(sem);
    tam2=devolveStrlencor2Semaforo(sem);
    cor1=malloc(sizeof(char)*(tam1+1));
    cor2=malloc(sizeof(char)*(tam2+1));
    cor1=devolveCor1Semaforo(sem);
    cor2=devolveCor2Semaforo(sem);
    x=devolveXSemaforo(sem);
    y=devolveYSemaforo(sem);
    fprintf(sig,"<circle cx=\"%f\" cy=\"%f\" r=\"10\"  stroke-width=\"3\" stroke=\"%s\" fill=\"%s\"/>\n",x,y,cor1,cor2);
    fprintf(sig,"<text x=\"%f\" y=\"%f\" fill=\"black\">S</text>\n",x-3,y+5);
}

void escreveSVGHydrant (FILE *sig,Hidrante *phid)
{
    char *cor1,*cor2;
    float x,y;
    int tam1,tam2;
    Hidrante *hid=(Hidrante *)phid;
    tam1=devolveStrlencor1Hidrante(hid);
    tam2=devolveStrlencor2Hidrante(hid);
    cor1=malloc(sizeof(char)*(tam1+1));
    cor2=malloc(sizeof(char)*(tam2+1));
    cor1=devolveCor1Hidrante(hid);
    cor2=devolveCor2Hidrante(hid);
    x=devolveXHidrante(hid);
    y=devolveYHidrante(hid);
    fprintf(sig,"<circle cx=\"%f\" cy=\"%f\" r=\"10\"  stroke-width=\"3\" stroke=\"%s\" fill=\"%s\"/>\n",x,y,cor1,cor2);
    fprintf(sig,"<text x=\"%f\" y=\"%f\" fill=\"black\">H</text>\n",x-3,y+5);
}

void escreveSVGTower (FILE *sig,Torre *ptor)
{
    char *cor1,*cor2;
    float x,y;
    int tam1,tam2;
    Torre *tor=(Torre *)ptor;
    tam1=devolveStrlencor1Torre(tor);
    tam2=devolveStrlencor2Torre(tor);
    cor1=malloc(sizeof(char)*(tam1+1));
    cor2=malloc(sizeof(char)*(tam2+1));
    cor1=devolveCor1Torre(tor);
    cor2=devolveCor2Torre(tor);
    x=devolveXTorre(tor);
    y=devolveYTorre(tor);
    fprintf(sig,"<circle cx=\"%f\" cy=\"%f\" r=\"10\"  stroke-width=\"3\" stroke=\"%s\" fill=\"%s\"/>\n",x,y,cor1,cor2);
    fprintf(sig,"<text x=\"%f\" y=\"%f\" fill=\"black\">T</text>\n",x-3,y+5);
}