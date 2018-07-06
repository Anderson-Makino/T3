#include <stdio.h>
#include <stdlib.h>

#include "learq.h"
#include "args.h"

int main (int argc,char *argv[])
{
    char *entrada,*diretorio,*qry;
    entrada=malloc(sizeof(0));
    diretorio==malloc(sizeof(0));
    qry==malloc(sizeof(0));
    entrada=verificF(argc,argv);
    diretorio=verificO(argc,argv);
    qry=verificQ(argc,argv);
    leArq(entrada,diretorio,qry);
    return 0;
}