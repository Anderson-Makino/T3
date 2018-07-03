#ifndef QUADRA_H
#define QUADRA_H

typedef void* Quadra;

Quadra createQuadra (unsigned long int ordem,char *pcep,float px,float py,float pw,float ph,char *cor1,char *cor2);

int devolveStrlencepQuadra(Quadra *pquad);

char devolveCepQuadra(Quadra *pquad);

unsigned long int devolveNOrdemQuadra(Quadra *pquad);

float devolveAlturaQuadra(Quadra *pquad);

float devolveLarguraQuadra(Quadra *pquad);

float devolveXQuadra(Quadra *pquad);

float devolveYQuadra(Quadra *pquad);

int devolveStrlencor1Quadra(Quadra *pquad);

int devolveStrlencor2Quadra(Quadra *pquad);

char *devolveCor1Quadra(Quadra *pquad);

char *devolveCor2Quadra(Quadra *pquad);

#endif
