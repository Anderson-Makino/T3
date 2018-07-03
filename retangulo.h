#ifndef RETANGULO_H
#define RETANGULO_H

typedef void* Retangulo;

Retangulo createRetangulo (unsigned long int ordem,int pi,char *pcor1,char *pcor2,float pw,float ph,float px,float py);

int devolveStrlencor1Retangulo(Retangulo *pret);

int devolveStrlencor2Retangulo(Retangulo *pret);

unsigned long int devolveNOrdemRetangulo(Retangulo *pret);

int devolveIdRetangulo(Retangulo *pret);

char *devolveCor1Retangulo(Retangulo *pret);

char *devolveCor2Retangulo(Retangulo *pret);

float devolveAltura(Retangulo *pret);

float devolveLargura(Retangulo *pret);

float devolveXRetangulo(Retangulo *pret);

float devolveYRetangulo(Retangulo *pret);

#endif
