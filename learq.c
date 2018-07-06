#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "learq.h"
#include "comandos.h"
#include "comandosQry.h"

void leArq(char *entrada,char *diretorio,char *qry)
{
	FILE *e;
	char *nomebase;
	char *token;
	int i,j=0;
	e=fopen (entrada,"r");
	if (e==NULL)
	{
	printf("erro ao abrir o arquivo");
	exit (0);
	}
	token=strtok(entrada,".");
	nomebase=malloc((strlen(token)+5)*sizeof(char));
	for(i=0;i<strlen(token);i++)
	{
	nomebase[j]=token[i];
	j++;
	}
	nomebase[j]='.';
	j++;
	nomebase[j]='s';
	j++;
	nomebase[j]='v';
	j++;
	nomebase[j]='g';
	j++;
	nomebase[j]='\0';
	comandos(e,diretorio,nomebase);
	fclose(e);
	executarQry(token,qry);
	free (nomebase);
}
