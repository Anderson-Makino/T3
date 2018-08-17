#ifndef CLOSESTPAIR_H
#define CLOSESTPAIR_H

#include "formaGeo.h"

typedef struct point
{
    float x,y;
    char *id;
}point;

point** transformList(fg *fgeo,unsigned long int cont,int ntor);
void mergeX(point **vetor,int comeco,int meio,int fim);
void mergeY(point **vetor,int comeco,int meio,int fim);
void mergeSortY(point **vetor,int comeco,int fim);
void mergeSortX(point **vetor,int comeco,int fim);
float dist(point *p1,point *p2);
void *bruteForce(point **p,int ntor,void *menor);
void *CriarMenorDist();
void *stripClosest(point **strip, int size, float min);
void *closestUtil (point **towerX,point **towerY,int ntor);
void distanceTowers(void *menordis,FILE *report);
void closestpair (fg *fgeo,unsigned long int cont,int ntor,FILE *report);

#endif
