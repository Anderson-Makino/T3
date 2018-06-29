#include <stdio.h>
#include <stdlib.h>

#include "learq.h"
#include "args.h"

int main (int argc,char *argv[])
{
    char *entrada,*diretorio;
    entrada=malloc(sizeof(0));
    diretorio=malloc(sizeof(0));
    entrada=verificF(entrada,argc,argv);
    diretorio=verificO(diretorio,argc,argv);
    leArq(entrada,diretorio);
    return 0;
}