#ifndef FORMAGEO_H
#define FORMAGEO_H

#include "circulo.h"
#include "retangulo.h"
#include "quadra.h"
#include "hidrante.h"
#include "semaforo.h"
#include "torre.h"

typedef void* fg;

void nCirculo (int *ndefault,char *ch);
fg createFG ();
void addCircle (fg *fgeo,Circulo *circ);
void addRet (fg *fgeo,Retangulo *ret);
void addBlock(fg *fgeo,Quadra *quad);
void addHydrant(fg *fgeo,Hidrante *hid);
void addSemaphore(fg *fgeo,Semaforo *sem);
void addTower(fg *fgeo,Torre *tor);
Circulo GetCircId(fg *fgeo,int id);
Retangulo GetRectId(fg *fgeo,int id);
Quadra *GetBlockId(fg *fgeo,char *id);
Hidrante *GetHydId(fg *fgeo,char *id);
Semaforo *GetSemId(fg *fgeo,char *id);
Torre *GetTorId(fg *fgeo,char *id);
Circulo GetCircOrd(fg *fgeo,unsigned long int ord);
Retangulo GetRectOrd(fg *fgeo,unsigned long int ord);
Quadra GetBlockOrd(fg *fgeo,unsigned long int ord);
Hidrante GetHidOrd(fg *fgeo,unsigned long int ord);
Semaforo GetSemOrd(fg *fgeo,unsigned long int ord);
Torre GetTorOrd(fg *fgeo,unsigned long int ord);
char *sobreposicao (fg *fge,char *ch,char *dio,int *tamdio);
char *pontointerno (fg *fge,char *ch,char *dio,int *tamdio);
char *distancia (fg *fge,char *ch,char *dio,int *tamdio);
FILE *tracaLinha(FILE *sig,int id,unsigned long int cont,fg *fgeo);  /*traça linha*/
void insereSVG (FILE *sig,unsigned long int cont,fg *fgeo);  /*insere os elementos de svg*/
void escreveSVGCirc (FILE *sig,Circulo *circ); /*escreve dados do circulo no arquivo*/
void escreveSVGQuad (FILE *sig,Retangulo *ret); /*escreve dados do quadrado no arquivo*/

#endif

