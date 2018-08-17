#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "closestPair.h"
#include "list.h"

typedef struct menordistancia{
    char *id1;
    float x1;
    float y1;
    char *id2;
    float x2;
    float y2;
    float dist;
}menordistancia;


point** transformList(fg *fgeo,unsigned long int cont,int ntor)
{
    point **vector;
    unsigned long int i;
    int j=0;
    Torre *tor;
    vector=(point**) malloc(sizeof(point*)*ntor);
    for (i=0;i<cont;i++)
    {
        tor=GetTorOrd(fgeo,i);
        if (tor!=NULL)
        {
            vector[j]->x=devolveXTorre(tor);
            vector[j]->y=devolveYTorre(tor);
            strcpy(vector[j]->id,devolveIdTorre(tor));
            j++;
        }
    }
    return (vector);
}

void mergeX(point **vetor,int comeco,int meio,int fim)
{
    int com1=comeco, com2=meio+1, comAux=0, tam=fim-comeco+1;
    point **vetAux;
    vetAux=malloc(tam*sizeof(point));

    while(com1<=meio && com2<=fim)
    {
        if(vetor[com1]->x < vetor[com2]->x) 
        {
            vetAux[comAux]=vetor[com1];
            com1++;
        } 
        else 
        {
            vetAux[comAux]=vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1<=meio) //insere elementos restantes da primeira metade
    {
        vetAux[comAux]=vetor[com1];
        comAux++;
        com1++;
    }

    while(com2<=fim)  //insere elementos restantes da segunda metade
    {
        vetAux[comAux]=vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux=comeco;comAux<=fim;comAux++) //Move os elementos de volta para o vetor original
    {
        vetor[comAux]=vetAux[comAux-comeco];
    }
    
    free(vetAux);

}

void mergeY(point **vetor,int comeco,int meio,int fim)
{
    int com1=comeco, com2=meio+1, comAux=0, tam=fim-comeco+1;
    point **vetAux;
    vetAux=malloc(tam*sizeof(point));

    while(com1<=meio && com2<=fim)
    {
        if(vetor[com1]->y < vetor[com2]->y) 
        {
            vetAux[comAux]=vetor[com1];
            com1++;
        } 
        else 
        {
            vetAux[comAux]=vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1<=meio) //insere elementos restantes da primeira metade
    {
        vetAux[comAux]=vetor[com1];
        comAux++;
        com1++;
    }

    while(com2<=fim)  //insere elementos restantes da segunda metade
    {
        vetAux[comAux]=vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux=comeco;comAux<=fim;comAux++) //Move os elementos de volta para o vetor original
    {
        vetor[comAux]=vetAux[comAux-comeco];
    }
    
    free(vetAux);

}

void mergeSortY(point **vetor,int comeco,int fim)
{
    if (comeco<fim)
    {
        int meio = (fim+comeco)/2;
        mergeSortY(vetor,comeco,meio);
        mergeSortY(vetor,meio+1,fim);
        mergeY(vetor,comeco,meio,fim);
    }
}

void mergeSortX(point **vetor,int comeco,int fim)
{
    if (comeco<fim)
    {
        int meio = (fim+comeco)/2;
        mergeSortX(vetor,comeco,meio);
        mergeSortX(vetor,meio+1,fim);
        mergeX(vetor,comeco,meio,fim);
    }
}

float dist(point *p1,point *p2)
{
    return sqrt((p1->x-p2->x)*(p1->x-p2->x)+(p1->y-p2->y)*(p1->y-p2->y));
}

void *bruteForce(point **p,int ntor,void *menor)
{
    float min=999999;
    int i,j;
    j=0;
    for(i=0;i<ntor;i++)
    {
        if(dist(p[i],p[j])<min)
        {
            min=dist(p[i],p[j]);
            ((menordistancia*)menor)->dist=999999;
            ((menordistancia*)menor)->x1=p[i]->x;
            ((menordistancia*)menor)->y1=p[i]->y;
            ((menordistancia*)menor)->x2=p[j]->x;
            ((menordistancia*)menor)->x2=p[j]->x;
            strcpy(((menordistancia*)menor)->id1,p[i]->id);
            strcpy(((menordistancia*)menor)->id2,p[j]->id);
        }
        return menor;
    }
}

void *CriarMenorDist()
{
    menordistancia *menor = malloc(sizeof(menordistancia));
    menor->id1 = malloc(50 * sizeof(char));
    menor->id2 = malloc(50 * sizeof(char));
 return (void*)menor;
}

void *stripClosest(point **strip, int size, float min)
{
    void *menor=CriarMenorDist();
    int i;
    int j;
    for (i=0;i<size;++i)
        for (j=i+1;j<size && (strip[j]->y-strip[i]->y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
            {
                min=dist(strip[i],strip[j]);
                ((menordistancia*)menor)->dist=999999;
                ((menordistancia*)menor)->x1=strip[i]->x;
                ((menordistancia*)menor)->y1=strip[i]->y;
                ((menordistancia*)menor)->x2=strip[j]->x;
                ((menordistancia*)menor)->x2=strip[j]->x;
                strcpy(((menordistancia*)menor)->id1,strip[i]->id);
                strcpy(((menordistancia*)menor)->id2,strip[j]->id);
            }
    return menor;
}


void *closestUtil (point **towerX,point **towerY,int ntor)
{
    int meio=ntor/2;
    point **pol=malloc(sizeof(point*)* (meio+1)); //points on left
    point **por=malloc(sizeof(point*)* (ntor-meio-1)); //points on right
    point *midpoint=towerX[meio];
    point **strip=malloc(ntor*sizeof(point*));
    int li=0,ri=0;
    int i;
    int j=0,qtdL=0,qtdR=0;
    void *dl;
    void *dr;
    void *d;
    void *p;
    void *stripClsDist;
    int val;
    void *menor=CriarMenorDist();
    if (ntor<=3)
    {
        return bruteForce(towerX,ntor,menor);
    }
    for(i=0;i<ntor;i++)
    {
        if(towerY==NULL)
        {
            break;
        }
        if(towerY[i]->x <= midpoint->x)
        {
            pol[li++]=towerY[i];
        }
        else
        {
            por[ri++]=towerY[i];
        }
    }
    dl=closestUtil(towerX,pol,meio); 
    dr=closestUtil(towerX,por,meio);

    if(((menordistancia*)dl)->dist <= ((menordistancia*)dr)->dist)
    {
        d=dl;
    }
    else
    {
        d=dr;
    }

    for (i=0;i<ntor;i++)
        if (abs(towerY[i]->x-midpoint->x) < ((menordistancia*)d)->dist){
            strip[j]=towerY[i];
            j++;
        }

    stripClsDist=stripClosest(strip,j,((menordistancia*)d)->dist);
    if( ((menordistancia*)d)->dist<=((menordistancia*)stripClsDist)->dist)
    {
        return d;
    }
    else
    {
        return stripClsDist;
    }
}

void distanceTowers(void *mdis,FILE *report)
{
    fprintf(report,"Torres com menor distancia: ID1:%s  X1:%f  Y1:%f\n ID2:%s  X2:%f  Y2:%f\nDistancia:%f\n",((menordistancia*)mdis)->id1,((menordistancia*)mdis)->x1,((menordistancia*)mdis)->x2,((menordistancia*)mdis)->id2,((menordistancia*)mdis)->x2,((menordistancia*)mdis)->y2,((menordistancia*)mdis)->dist);
}

void closestpair (fg *fgeo,unsigned long int cont,int ntor,FILE *report)
{
    point **vectorTower=transformList(fgeo,cont,ntor);
    point **towerX=vectorTower;
    point **towerY=vectorTower;
    void *menordis;
    mergeSortX(towerX,0,ntor-1);
    mergeSortY(towerY,0,ntor-1);
    menordis=closestUtil(towerX,towerY,ntor);
    distanceTowers(menordis,report);
}