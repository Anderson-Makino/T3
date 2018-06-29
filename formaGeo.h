#ifndef FORMAGEO_H
#define FORMAGEO_H

#include "circulo.h"
#include "retangulo.h"

typedef void* fg;

void nCirculo (int *ndefault,char *ch);
fg createFG ();
void addCircle (fg *fgeo,Circulo *circ);
void addRet (fg *fgeo,Retangulo *ret);
Circulo GetCircId(fg *f, int id);
Retangulo GetRectId(fg *f, int id);
Circulo GetCircOrd(fg *f, int ord);
Retangulo GetRectOrd(fg *f, int ord);
char *sobreposicao (fg *fge,char *ch,char *dio,int *tamdio);
char *pontointerno (fg *fge,char *ch,char *dio,int *tamdio);
char *distancia (fg *fge,char *ch,char *dio,int *tamdio);
void pegaElementsCirc(char *ch,int *element0,char *element1,char *element2,char *element3,char *element4,char *element5,char *element6,int cont);
void pegaElementsRet(char *ch,int *element0,char *element1,char *element2,char *element3,char *element4,char *element5,char *element6,char *element7,int cont);

#endif

