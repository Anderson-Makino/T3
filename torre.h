#ifndef TORRE_H
#define TORRE_H

typedef void* Torre;

Torre createTorre (unsigned long int ordem,char *pid,float px,float py,char *cor1,char *cor2);

unsigned long int devolveNOrdemTorre(Torre *ptor);

char *devolveIdTorre(Torre *ptor);

float devolveXTorre(Torre *ptor);

float devolveYTorre(Torre *ptor);

int devolveStrlencor1Torre(Torre *ptor);

int devolveStrlencor2Torre(Torre *ptor);

char *devolveCor1Torre(Torre *ptor);

char *devolveCor2Torre(Torre *ptor);

void mudaCorTorre(Torre *ptor,char *pcor1,char *pcor2);

#endif