#ifndef SEMAFORO_H
#define SEMAFORO_H

typedef void* Semaforo;

Semaforo createSemaforo (unsigned long int ordem,char *id,float px,float py,char *cor1,char *cor2);

unsigned long int devolveNOrdemSemaforo(Semaforo *psem);

int devolveIdSemaforo(Semaforo *psem);

float devolveXSemaforo(Semaforo *psem);

float devolveYSemaforo(Semaforo *psem);

int devolveStrlencor1Semaforo(Semaforo *psem);

int devolveStrlencor2Semaforo(Semaforo *psem);

char *devolveCor1Semaforo(Semaforo *psem);

char *devolveCor2Semaforo(Semaforo *psem);

#endif