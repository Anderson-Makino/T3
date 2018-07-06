#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "circulo.h"
#include "retangulo.h"
#include "formaGeo.h"

FILE *criaSuf (char *diretorio,char *nomebase,FILE *sig2,char *ch);     /*cria arq svg*/
void iniciaSVG (FILE *sig);  /*inicia arquivo svg*/
void terminaSVG(FILE *sig);   /*finaliza e fecha arquivo svg*/
void escreveLinha(FILE *sig,float *x1,float *y1,float *x2,float *y2,char *cor);
void criaDio(char *dio,char *nomebase,int tamdio);  /*cria arquivo das informações DIO*/

#endif
