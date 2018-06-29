#ifndef CIRCULO_H
#define CIRCULO_H

typedef void* Circulo;

Circulo createCirculo (int *ordem,int pi,char *pcor1,char *pcor2,float pr,float px,float py);

int devolveStrlencor1Circulo(Circulo *pcirc);

int devolveStrlencor2Circulo(Circulo *pcirc);

char *devolveCor1Circulo(Circulo *pcirc);

char *devolveCor2Circulo(Circulo *pcirc);

float devolveRaio(Circulo *pcirc);

int devolveNOrdemCirculo(Circulo *pcirc);

int devolveIdCirculo(Circulo *pcirc);

float devolveXCirculo(Circulo *pcirc);

float devolveYCirculo(Circulo *pcirc);

#endif
