#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "comandosQry.h"
#include "consultaQry.h"
#include "funcoes.h"

void executarQry(char *token,char *qry)
{
    FILE *e;
    char *tok;
	char *linha;
	char c;
	char *ch,*info;
	char *element1,*element2,*element3,*element4;
	int tam;
	int sizefile=0;
	linha=malloc(sizeof(char));
    e=fopen(qry,"r");
    if (e==NULL)
	{
	exit (0);
	}
    tok=strtok(qry,".");
	tam=strlen(tok);
    concatena(token,tok,&tam);
	int j=strlen(token)+tam;
	int i=1;
    qry[j+i]='.';
	i++;
	qry[j+i]='s';
	i++;
	qry[j+i]='v';
	i++;
	qry[j+i]='g';
	i++;
	qry[j+i]='\0';
	while (1)
	{
        c=fgetc(e);
        while (c!= EOF && c!='\n' && c!='\r')
	    {
            linha=realloc(linha,sizeof(char)*(sizefile+2));
		    linha[sizefile]=c;
            sizefile++;
            c=fgetc(e);
	    }
        linha[sizefile]='\0';
	}
	ch=strtok(linha," ");
	if(ch[0]=='q' && ch[1]=='?')    //reporta no retangulo
	{
		ch=strtok(NULL,"\n");
		info=strtok(ch," ");
        element1=info;
        info=strtok(NULL," ");
        element2=info;
        info=strtok(NULL," ");
        element3=info;
        info=strtok(NULL," ");
        element4=info;
		reportaQuadQry(atof(element1),atof(element2),atof(element3),atof(element4));
	}
	else if(ch[0]=='Q' && ch[1]=='?')   //reporta no circulo
	{
		ch=strtok(NULL,"\n");
		info=strtok(ch," ");
        element1=info;
        info=strtok(NULL," ");
        element2=info;
        info=strtok(NULL," ");
        element3=info;
		reportaCircQry(atof(element1),atof(element2),atof(element3));
	}
	else if(ch[0]=='d' && ch[1]=='q')   //remove quadra no retangulo
	{
		ch=strtok(NULL,"\n");
		info=strtok(ch," ");
        element1=info;
        info=strtok(NULL," ");
        element2=info;
        info=strtok(NULL," ");
        element3=info;
        info=strtok(NULL," ");
        element4=info;
		removeBlockInQuad(atof(element1),atof(element2),atof(element3),atof(element4));
	}
	
	else if(ch[0]=='d' && ch[1]=='l'  && ch[2]=='e')  //remove equips no retangulo
	{
		ch=strtok(NULL,"\n");
		info=strtok(ch," ");
        element1=info;
        info=strtok(NULL," ");
        element2=info;
        info=strtok(NULL," ");
        element3=info;
        info=strtok(NULL," ");
        element4=info;
		removeEquipsInQuad(/*something,*/atof(element1),atof(element2),atof(element3),atof(element4));
		
	}
	else if(ch[0]=='D' && ch[1]=='q')   //remove quadra no circulo
	{
		ch=strtok(NULL,"\n");
		info=strtok(ch," ");
        element1=info;
        info=strtok(NULL," ");
        element2=info;
        info=strtok(NULL," ");
        element3=info;
		removeBlockInCirc(atof(element1),atof(element2),atof(element3));
	}
	else if(ch[0]=='D' && ch[1]=='l' && ch[2]=='e')   //remove equips no circulo
	{
		ch=strtok(NULL,"\n");
		info=strtok(ch," ");
        element1=info;
        info=strtok(NULL," ");
        element2=info;
        info=strtok(NULL," ");
        element3=info;
		removeEquipsInCirc(atof(element1),atof(element2),atof(element3));
	}
	else if(ch[0]=='c' && ch[1]=='c')  //muda cor da quadra
	{
		ch=strtok(NULL,"\n");
	}
	else if(ch[0]=='c' && ch[1]=='r' && ch[2]=='d' && ch[3]=='?')
	{
		ch=strtok(NULL,"\n");
	}
	else if(ch[0]=='c' && ch[1]=='r' && ch[2]=='b' && ch[3]=='?')
	{
		ch=strtok(NULL,"\n");
	}
}