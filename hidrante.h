#ifndef HIDRANTE_H
#define HIDRANTE_H

typedef void* Hidrante;

Hidrante createHidrante (unsigned long int ordem,char *pid,float px,float py,char *pcor1,char *pcor2);

unsigned long int devolveNOrdemHidrante(Hidrante *phid);

int devolveIdHidrante(Hidrante *phid);

float devolveXHidrante(Hidrante *phid);

float devolveYHidrante(Hidrante *phid);

int devolveStrlencor1Hidrante(Hidrante *phid);

int devolveStrlencor2Hidrante(Hidrante *phid);

char *devolveCor1Hidrante(Hidrante *phid);

char *devolveCor2Hidrante(Hidrante *phid);

#endif