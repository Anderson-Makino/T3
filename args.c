#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "args.h"

char *verificF(int argc,char *argv[])
{
	char *entrada;
	int i;
	for (i=1;i<argc;i++)
	{
	if (argv[i] [0]=='-')
	{
		if (argv[i][1]=='f')
		{
			entrada=(char *) malloc((strlen(argv[i+1])+1)*sizeof(char));
			strcpy(entrada,argv[i+1]);
			return (entrada);
		}
	}
	}
}

char *verificO(int argc,char *argv[])
{
	char *diretorio;
	int i;
	for (i=1;i<argc;i++)
	{
	if (argv[i] [0]=='-')
	{
		if(argv[i] [1]=='o')
		{
			diretorio=(char *) malloc((strlen(argv[i+1])+2)*sizeof(char));
			strcpy(diretorio,argv[i+1]);
			return (diretorio);
		}
	}
	}
}