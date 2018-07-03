#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "semaforo.h"

typedef struct semaforo{
    unsigned long int *ord;
    char *id;
    float *x,*y;      /*coordenadas*/
    char *cor1,*cor2; /*cor da borda e do preenchimento*/
}semaforo;

Semaforo createSemaforo (unsigned long int ordem,char *pid,float px,float py,char *pcor1,char *pcor2)
{
    semaforo *sem;
    sem=malloc (sizeof(semaforo));
    sem->ord=malloc(sizeof(unsigned long int));
    sem->id=malloc(sizeof(char)*(strlen(pid)+1));
    sem->x=malloc(sizeof(float));
    sem->y=malloc(sizeof(float));
    sem->cor1=malloc(sizeof(char)*(strlen(pcor1)+1));
    sem->cor2=malloc(sizeof(char)*(strlen(pcor2)+1));
    *(sem->ord)=ordem;
    *(sem->x)=px;
    *(sem->y)=py;
    strcpy(sem->id,pid);
    strcpy(sem->cor1,pcor1);
    strcpy(sem->cor2,pcor2);
    return (sem);
    
}

unsigned long int devolveNOrdemSemaforo(Semaforo *psem)
{
    semaforo *sem=(semaforo *)psem;
    return *(sem->ord);

}
int devolveIdSemaforo(Semaforo *psem)
{
    semaforo *sem=(semaforo *)psem;
    return *(sem->id);
}

float devolveXSemaforo(Semaforo *psem)
{
    semaforo *sem=(semaforo *)psem;
    return *(sem->x);
}

float devolveYSemaforo(Semaforo *psem)
{
    semaforo *sem=(semaforo *)psem;
    return *(sem->y);
}

int devolveStrlencor1Semaforo(Semaforo *psem)
{
    semaforo *sem = (semaforo *)psem;
    int tam;
    tam=strlen (sem->cor1);
    return (tam);
}

int devolveStrlencor2Semaforo(Semaforo *psem)
{
    semaforo *sem = (semaforo *)psem;
    int tam;
    tam=strlen (sem->cor2);
    return (tam);
}

char *devolveCor1Semaforo(Semaforo *psem)
{
    semaforo *sem = (semaforo *)psem;
    return (sem->cor1);
}

char *devolveCor2Semaforo(Semaforo *psem)
{
    semaforo *sem = (semaforo *)psem;
    return (sem->cor2);
}