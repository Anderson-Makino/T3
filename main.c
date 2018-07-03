#include <stdio.h>
#include <stdlib.h>

#include "learq.h"
#include "args.h"

int main (int argc,char *argv[])
{
    char *entrada,*diretorio;
    entrada=verificF(argc,argv);
    diretorio=verificO(argc,argv);
    leArq(entrada,diretorio);
    return 0;
}