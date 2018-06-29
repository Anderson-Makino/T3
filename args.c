#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "args.h"

char *arqEntrada (char *entrada,int i,char *argv[])
{
	int j;
	entrada=(char *) malloc(strlen((argv[i])+1)*sizeof(char));
	for (j=0;j<strlen(argv[i]);j++)
	{
		entrada[j]=argv[i] [j];
	}
	entrada[j]='\0';
	return(entrada);
}

char *arqSaida (char *diretorio,int i,char *argv[])
{
	int j;
	diretorio=(char *) malloc(strlen(argv[i]+2)*sizeof(char));
	for (j=0;j<strlen(argv[i]);j++)
	{
		diretorio[j]=argv[i] [j];
	}
	diretorio[j]='\0';
	return(diretorio);
}

char *verificF(char *entrada,int argc,char *argv[])
{
	int i;
	for (i=1;i<argc;i++)
	{
	if (argv[i] [0]=='-')
	{
		if (argv[i][1]=='f')
		{
			entrada=arqEntrada(entrada,i+1,argv);
		}
	}
	}
	return (entrada);
}

char *verificO(char *diretorio,int argc,char *argv[])
{
	int i;
	for (i=1;i<argc;i++)
	{
	if (argv[i] [0]=='-')
	{
		if(argv[i] [1]=='o')
		{
			diretorio=arqSaida(diretorio,i+1,argv);
		}
	}
	}
	return (diretorio);
}