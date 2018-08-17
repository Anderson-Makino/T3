#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "consultaQry.h"
#include "circulo.h"
#include "retangulo.h"
#include "quadra.h"
#include "semaforo.h"
#include "hidrante.h"
#include "torre.h"
#include "list.h"
#include "formaGeo.h"
#include "funcoes.h"

void reportaRetQry(float x,float y,float larg,float alt,unsigned long int cont,FILE *report,unsigned long int *nequips,unsigned long int *contequips,fg *fgeo)
{
    Circulo *circ;
    Retangulo *ret;
    Quadra *quad;
    Hidrante *hid;
    Semaforo *sem;
    Torre *tor;
    unsigned long int i;
    float x2,y2;
    float raio,altura,largura;
    for (i=0;i<cont;i++)
    {
        circ=GetCircOrd(fgeo,i);
        if (circ==NULL)
        {
            ret=GetRectOrd(fgeo,i);
            if (ret==NULL)
            {
                quad=GetBlockOrd(fgeo,i);
                if (quad==NULL)
                {
                    hid=GetHidOrd(fgeo,i);
                    if(hid==NULL)
                    {
                        sem=GetSemOrd(fgeo,i);
                        if(sem==NULL)
                        {
                            tor=GetTorOrd(fgeo,i);
                            if(tor!=NULL)
                            {
                            x2=devolveXTorre(tor);
                            y2=devolveYTorre(tor);
                            //raio=10
                            if(x2+10>=x && y2+10>=y  && x2-10<=x+larg && y2-10<=y+alt)  //dentro
                            {
                                fprintf(report,"Torre x:%f  y:%f\n",x2,y2);
                                nequips[*contequips]=i;
                                *contequips++;
                                nequips=realloc(nequips,sizeof(unsigned long int)* *(contequips));

                            }
                            }
                        }
                        else
                        {
                            x2=devolveXSemaforo(sem);
                            y2=devolveYSemaforo(sem);
                            //raio=10
                            if(x2+10>=x && y2+10>=y  && x2-10<=x+larg && y2-10<=y+alt)  //dentro
                            {
                                fprintf(report,"Semaforo x:%f  y:%f\n",x2,y2);
                                nequips[*contequips]=i;
                                *contequips++;
                                nequips=realloc(nequips,sizeof(unsigned long int)* *(contequips));

                            }
                        }
                    }
                    else
                    {
                        x2=devolveXHidrante(hid);
                        y2=devolveYHidrante(hid);
                        //raio=10
                        if(x2+10>=x && y2+10>=y  && x2-10<=x+larg && y2-10<=y+alt)  //dentro
                        {
                            fprintf(report,"Hidrante x:%f  y:%f\n",x2,y2);
                            nequips[*contequips]=i;
                            *contequips++;
                            nequips=realloc(nequips,sizeof(unsigned long int)* *(contequips));

                        }
                    }
                }
                else
                {
                    x2=devolveXQuadra(quad);
                    y2=devolveYQuadra(quad);
                    altura=devolveAlturaQuadra(quad);
                    largura=devolveLarguraQuadra(quad);
                    if(x2+largura>=x && y2+altura>=y && x2<=x+larg && y2<=y+alt)
                    {
                        fprintf(report,"Quadra x:%f  y:%f\n",x2,y2);
                        nequips[*contequips]=i;
                        *contequips++;
                        nequips=realloc(nequips,sizeof(unsigned long int)* *(contequips));

                    }
                }
            }
            else
            {
            x2=devolveXRetangulo(ret);
            y2=devolveYRetangulo(ret);
            altura=devolveAltura(ret);
            largura=devolveLargura(ret);
            if(x2+largura>=x && y2+altura>=y && x2<=x+larg && y2<=y+alt)
                {
                    fprintf(report,"Retangulo x:%f  y:%f\n",x2,y2);
                    nequips[*contequips]=i;
                    *contequips++;
                    nequips=realloc(nequips,sizeof(unsigned long int)* *(contequips));

                }
            }
        }
        else if (circ!=NULL)
        {
            x2=devolveXCirculo(circ);
            y2=devolveYCirculo(circ);
            raio=devolveRaio(circ);
            if(x2+raio>=x && y2+raio>=y  && x2-raio<=x+larg && y2-raio<=y+alt)
            {
                fprintf(report,"Circulo x:%f  y:%f\n",x2,y2);
                nequips[*contequips]=i;
                *contequips++;
                nequips=realloc(nequips,sizeof(unsigned long int)* *(contequips));

            }
        }
    }
}

void reportaCircQry(float r,float x,float y,unsigned long int cont,FILE *report,unsigned long int *nequips,unsigned long int *contequips,fg *fgeo)
{
    Circulo *circ;
    Retangulo *ret;
    Quadra *quad;
    Hidrante *hid;
    Semaforo *sem;
    Torre *tor;
    unsigned long int i;
    float x2,y2;
    float raio,altura,largura;
    for (i=0;i<cont;i++)
    {
        circ=GetCircOrd(fgeo,i);
        if (circ==NULL)
        {
            ret=GetRectOrd(fgeo,i);
            if (ret==NULL)
            {
                quad=GetBlockOrd(fgeo,i);
                if (quad==NULL)
                {
                    hid=GetHidOrd(fgeo,i);
                    if(hid==NULL)
                    {
                        sem=GetSemOrd(fgeo,i);
                        if(sem==NULL)
                        {
                            tor=GetTorOrd;(fgeo,i);
                            x2=devolveXTorre(tor);
                            y2=devolveYTorre(tor);
                            //raio=10
                            if(x2+10>=x-r && y2+10>=y-r  && x2-10<=x+r && y2-10<=y+r)  //dentro
                            {
                                fprintf(report,"Torre x:%f  y:%f\n",x2,y2);
                                nequips[*contequips]=i;
                                *contequips++;
                                nequips=realloc(nequips,sizeof(unsigned long int)* *(contequips));

                            }
                        }
                        else
                        {
                            x2=devolveXSemaforo(sem);
                            y2=devolveYSemaforo(sem);
                            //raio=10
                            if(x2+10>=x-r && y2+10>=y-r  && x2-10<=x+r && y2-10<=y+r)  //dentro
                            {
                                fprintf(report,"Semaforo x:%f  y:%f\n",x2,y2);
                                nequips[*contequips]=i;
                                *contequips++;
                                nequips=realloc(nequips,sizeof(unsigned long int)* *(contequips));

                            }
                        }
                    }
                    else
                    {
                        x2=devolveXHidrante(hid);
                        y2=devolveYHidrante(hid);
                        //raio=10
                        if(x2+10>=x-r && y2+10>=y-r  && x2-10<=x+r && y2-10<=y+r)  //dentro
                        {
                            fprintf(report,"Hidrante x:%f  y:%f\n",x2,y2);
                            nequips[*contequips]=i;
                            *contequips++;
                            nequips=realloc(nequips,sizeof(unsigned long int)* *(contequips));

                        }
                    }
                }
                else
                {
                    x2=devolveXQuadra(quad);
                    y2=devolveYQuadra(quad);
                    altura=devolveAlturaQuadra(quad);
                    largura=devolveLarguraQuadra(quad);
                    if(x2+largura>=x-r && y2+altura>=y-r && x2<=x+r && y2<=y+r)
                    {
                        fprintf(report,"Quadra x:%f  y:%f\n",x2,y2);
                        nequips[*contequips]=i;
                        *contequips++;
                        nequips=realloc(nequips,sizeof(unsigned long int)* *(contequips));

                    }
                }
            }
            else
            {
            x2=devolveXRetangulo(ret);
            y2=devolveYRetangulo(ret);
            altura=devolveAltura(ret);
            largura=devolveLargura(ret);
            if(x2+largura>=x-r && y2+altura>=y-r && x2<=x+r && y2<=y+r)
                {
                    fprintf(report,"Retangulo x:%f  y:%f\n",x2,y2);
                    nequips[*contequips]=i;
                    *contequips++;
                    nequips=realloc(nequips,sizeof(unsigned long int)* *(contequips));

                }
            }
        }
        else
        {
            x2=devolveXCirculo(circ);
            y2=devolveYCirculo(circ);
            raio=devolveRaio(circ);
            if(x2+raio>=x-r && y2+raio>=y-r  && x2-raio<=x+r && y2-raio<=y+r)
            {
                fprintf(report,"Circulo x:%f  y:%f\n",x2,y2);
                nequips[*contequips]=i;
                *contequips++;
                nequips=realloc(nequips,sizeof(unsigned long int)* *(contequips));

            }
        }
    }
}

void removeBlockInQuad(float x,float y,float larg,float alt,unsigned long int cont,unsigned long int *nequips,unsigned long int *contequips,fg *fgeo)
{
    Quadra *quad;
    unsigned long int i,j;
    float x2,y2,altura,largura;
    for (i=0;i<cont;i++)
    {
        quad=GetBlockOrd(fgeo,i);
        if (quad!=NULL)
        {
            for (j=0;j<(*contequips);j++)
            {
                if(nequips[j]==i)
                {
                    x2=devolveXQuadra(quad);
                    y2=devolveYQuadra(quad);
                    altura=devolveAlturaQuadra(quad);
                    largura=devolveLarguraQuadra(quad);
                    if(x2+largura>=x && y2+altura>=y && x2<=x+larg && y2<=y+alt)
                    {
                        remover(fgeo,quad);
                    }
                }
            }
           
        }
    }
}

void removeEquipsInQuad(char *obj,float x,float y,float larg,float alt,unsigned long int cont,unsigned long int *nequips,unsigned long int *contequips,fg *fgeo)
{
    Hidrante *hid;
    Semaforo *sem;
    Torre *tor;
    int h=0,s=0,t=0;
    int j;
    float x2,y2;
    unsigned long int i;
    for(j=0;j<strlen(obj);j++)
    {
        if(obj[j]=='s')  //remove semaforos
        {
            s=1;
        }
        if(obj[j]=='h')  //remove hidrantes
        {
            h=1;
        }
        if(obj[j]=='r')  //remove torres
        {
            t=1;
        }
    }

    for (i=0;i<cont;i++)
    {
        hid=GetHidOrd(fgeo,i);
        if (hid!=NULL && h==1)
        {
            for (j=0;j<(*contequips);j++)
            {
                if(nequips[j]==i)
                {
                    x2=devolveXHidrante(hid);
                    y2=devolveYHidrante(hid);
                    if(x2+10>=x && y2+10>=y && x2<=x+larg && y2<=y+alt)
                    {
                        remover(fgeo,hid);
                    }
                }
            }
        }
        sem=GetSemOrd(fgeo,i);
        if (sem!=NULL && s==1)
        {
            for (j=0;j<(*contequips);j++)
            {
                if(nequips[j]==i)
                {
                    x2=devolveXSemaforo(sem);
                    y2=devolveYSemaforo(sem);
                    if(x2+10>=x && y2+10>=y && x2<=x+larg && y2<=y+alt)
                    {
                        remover(fgeo,sem);
                    }
                }
            }
        }
        tor=GetTorOrd(fgeo,i);
        if (tor!=NULL && t==1)
        {
            for (j=0;j<(*contequips);j++)
            {
                if(nequips[j]==i)
                {
                    x2=devolveXTorre(tor);
                    y2=devolveYTorre(tor);
                    if(x2+10>=x && y2+10>=y && x2<=x+larg && y2<=y+alt)
                    {
                        remover(fgeo,tor);
                    }
                }
            }
        }
    }
}

void removeBlockInCirc(float r,float x,float y,unsigned long int cont,unsigned long int *nequips,unsigned long int *contequips,fg *fgeo)
{
    Quadra *quad;
    unsigned long int i,j;
    float x2,y2,altura,largura;
    for (i=0;i<cont;i++)
    {
        quad=GetBlockOrd(fgeo,i);
        if (quad!=NULL)
        {
            for (j=0;j<(*contequips);j++)
            {
                if(nequips[j]==i)
                {
                    x2=devolveXQuadra(quad);
                    y2=devolveYQuadra(quad);
                    altura=devolveAlturaQuadra(quad);
                    largura=devolveLarguraQuadra(quad);
                    if(x2+largura>=x-r && y2+altura>=y-r && x2<=x+r && y2<=y+r)
                    {
                        remover(fgeo,quad);
                    }
                }
            }
           
        }
    }
}

void removeEquipsInCirc(char *obj,float x,float y,float r,unsigned long int cont,unsigned long int *nequips,unsigned long int *contequips,fg *fgeo)
{
    Hidrante *hid;
    Semaforo *sem;
    Torre *tor;
    int h=0,s=0,t=0;
    int j;
    float x2,y2;
    unsigned long int i;
    for(j=0;j<strlen(obj);j++)
    {
        if(obj[j]=='s')  //remove semaforos
        {
            s=1;
        }
        if(obj[j]=='h')  //remove hidrantes
        {
            h=1;
        }
        if(obj[j]=='r')  //remove torres
        {
            t=1;
        }
    }

    for (i=0;i<cont;i++)
    {
        hid=GetHidOrd(fgeo,i);
        if (hid!=NULL && h==1)
        {
            for (j=0;j<(*contequips);j++)
            {
                if(nequips[j]==i)
                {
                    x2=devolveXHidrante(hid);
                    y2=devolveYHidrante(hid);
                    if(x2+10>=x-r && y2+10>=y-r  && x2-10<=x+r && y2-10<=y+r)
                    {
                        remover(fgeo,hid);
                    }
                }
            }
        }
        sem=GetSemOrd(fgeo,i);
        if (sem!=NULL && s==1)
        {
            for (j=0;j<(*contequips);j++)
            {
                if(nequips[j]==i)
                {
                    x2=devolveXSemaforo(sem);
                    y2=devolveYSemaforo(sem);
                    if(x2+10>=x-r && y2+10>=y-r  && x2-10<=x+r && y2-10<=y+r)
                    {
                        remover(fgeo,sem);
                    }
                }
            }
        }
        tor=GetTorOrd(fgeo,i);
        if (tor!=NULL && t==1)
        {
            for (j=0;j<(*contequips);j++)
            {
                if(nequips[j]==i)
                {
                    x2=devolveXTorre(tor);
                    y2=devolveYTorre(tor);
                    if(x2+10>=x-r && y2+10>=y-r  && x2-10<=x+r && y2-10<=y+r)
                    {
                        remover(fgeo,tor);
                    }
                }
            }
        }
    }
}

void mudaCor(char *id,char *cor1,char *cor2,unsigned long int cont,unsigned long int *nequips,unsigned long int *contequips,fg *fgeo)
{
    Circulo *circ;
    Retangulo *ret;
    Quadra *quad;
    Hidrante *hid;
    Semaforo *sem;
    Torre *tor;
    unsigned long int i;
    float x2,y2;
    float raio,altura,largura;
        quad=GetBlockId(fgeo,id);
        if (quad==NULL)
        {
            hid=GetHydId(fgeo,id);
            if(hid==NULL)
            {
                sem=GetSemId(fgeo,id);
                if(sem==NULL)
                {
                    tor=GetTorId(fgeo,id);
                    if(tor!=NULL)
                    {
                        mudaCorTorre(tor,cor1,cor2);
                    }
                }
                else
                {
                    mudaCorSemaforo(sem,cor1,cor2);
                }
            }
            else
            {
                mudaCorHidrante(hid,cor1,cor2);
            }
        }
        else if (quad!=NULL)
        {
            mudaCorQuadra(quad,cor1,cor2);
        }
}

void informa(char *id,FILE *report,fg *fgeo)
{
    Quadra *quad;
    Hidrante *hid;
    Semaforo *sem;
    Torre *tor;
    quad=GetBlockId(fgeo,id);
    if(quad==NULL)
    {
    hid=GetHydId(fgeo,id);
        if(hid==NULL)
        {
            sem=GetSemId(fgeo,id);
            if(sem==NULL)
            {
                tor=GetTorId(fgeo,id);
                if(tor!=NULL)
                {
                    fprintf(report,"Torre  X:%f  Y:%f\n",devolveXTorre(tor),devolveYTorre(tor));
                }
            }
            else
            {
                fprintf(report,"Semaforo  X:%f  Y:%f\n",devolveXSemaforo(sem),devolveYSemaforo(sem));
            }
        }
        else
        {
            fprintf(report,"Hidrante  X:%f  Y:%f\n",devolveXHidrante(hid),devolveYHidrante(hid));
        }
    }
    else
    {
        fprintf(report,"Quadra  X:%f  Y:%f\n",devolveXQuadra(quad),devolveYQuadra(quad));
    }
}