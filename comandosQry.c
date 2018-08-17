#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "comandosQry.h"
#include "consultaQry.h"
#include "funcoes.h"
#include "list.h"
#include "closestPair.h"
#include "formaGeo.h"


void executarQry(char *token,char *qry,char *nomebase,unsigned long int cont,fg *fgeo,int ntor)
{
    FILE *e,*sig,*report;
    char *tok;
	char *linha;
	char *arquivoreport;
	char c;
	char *ch,*info;
	char *element0,*element1,*element2,*element3,*element4;
	int tam;
	int sizefile=0;
	int i=0;
	unsigned long int *nequips,*contequips;
	nequips=malloc(sizeof(unsigned long int));
	contequips=malloc(sizeof(unsigned long int));
	*contequips=0;
	arquivoreport=malloc(sizeof(char)*strlen(nomebase)+7);
	strcpy(arquivoreport,nomebase);
	arquivoreport[strlen(nomebase)+i]='r';
	i++;
	arquivoreport[strlen(nomebase)+i]='e';
	i++;
	arquivoreport[strlen(nomebase)+i]='.';
	i++;
	arquivoreport[strlen(nomebase)+i]='t';
	i++;
	arquivoreport[strlen(nomebase)+i]='x';
	i++;
	arquivoreport[strlen(nomebase)+i]='t';
	i++;
	arquivoreport[strlen(nomebase)+i]='\0';
	report=fopen(arquivoreport,"w");
	fprintf(report,"equipamentos urbanos dentro:\n");
	linha=malloc(sizeof(char));
	sig=fopen(nomebase,"r");
	if (sig==NULL)
	{
		exit(0);
	}
    e=fopen(qry,"r");
    if (e==NULL)
	{
	exit (0);
	}
    tok=strtok(qry,".");
	tam=strlen(tok);
    concatena(token,tok,&tam);
	int j=strlen(token)+tam;
	i=0;
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
		sizefile=0;
        c=fgetc(e);
        while (c!= EOF && c!='\n' && c!='\r')
	    {
            linha=realloc(linha,sizeof(char)*(sizefile+2));
		    linha[sizefile]=c;
            sizefile++;
            c=fgetc(e);
	    }
        linha[sizefile]='\0';
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
		fprintf(sig,"<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" stroke=\"black\" fill=\"transparent\"  stroke-dasharray=\"10\"/></rect>\n",atof(element1),atof(element2),atof(element3),atof(element4));
		reportaRetQry(atof(element1),atof(element2),atof(element3),atof(element4),cont,report,nequips,contequips,fgeo);
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
		fprintf(sig,"<circle cx=\"%f\" cy=\"%f\" r=\"%f\"  stroke-width=\"3\" stroke=\"black\" fill=\"transparent\" stroke-dasharray=\"10\"/>\n",atof(element1),atof(element2),atof(element3));
		reportaCircQry(atof(element1),atof(element2),atof(element3),cont,report,nequips,&contequips,fgeo);
	}
	else if(ch[0]=='d' && ch[1]=='q')   //remove quadra no retangulo
	{
		printf("!!!\n");
		ch=strtok(NULL,"\n");
		info=strtok(ch," ");
        element1=info;
        info=strtok(NULL," ");
        element2=info;
        info=strtok(NULL," ");
        element3=info;
        info=strtok(NULL," ");
        element4=info;
		removeBlockInQuad(atof(element1),atof(element2),atof(element3),atof(element4),cont,nequips,&contequips,fgeo);
	}
	
	else if(ch[0]=='d' && ch[1]=='l'  && ch[2]=='e')  //remove equips no retangulo
	{
		ch=strtok(NULL,"\n");
		info=strtok(ch," ");
        element0=info;
        info=strtok(NULL," ");
        element1=info;
        info=strtok(NULL," ");
        element2=info;
        info=strtok(NULL," ");
        element3=info;
		info=strtok(NULL," ");
        element4=info;
		removeEquipsInQuad(element0,atof(element1),atof(element2),atof(element3),atof(element4),cont,nequips,&contequips,fgeo);
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
		removeBlockInCirc(atof(element1),atof(element2),atof(element3),cont,nequips,&contequips,fgeo);
	}
	else if(ch[0]=='D' && ch[1]=='l' && ch[2]=='e')   //remove equips no circulo
	{
		ch=strtok(NULL,"\n");
		info=strtok(ch," ");
        element0=info;
		info=strtok(ch," ");
        element1=info;
        info=strtok(NULL," ");
        element2=info;
        info=strtok(NULL," ");
        element3=info;
		removeEquipsInCirc(element0,atof(element1),atof(element2),atof(element3),cont,nequips,&contequips,fgeo);
	}
	else if(ch[0]=='c' && ch[1]=='c')  //muda cor da quadra
	{
		ch=strtok(NULL,"\n");
		info=strtok(ch," ");
        element0=info;
		info=strtok(ch," ");
        element1=info;
        info=strtok(NULL," ");
        element2=info;
		mudaCor(element0,element1,element2,cont,nequips,&contequips,fgeo);
	}
	else if(ch[0]=='c' && ch[1]=='r' && ch[2]=='d' && ch[3]=='?')  //informa equipamento e ID
	{
		ch=strtok(NULL,"\n");
		info=strtok(ch," ");
		element0=info;
		informa(element0,report,fgeo);
	}
	else if(ch[0]=='c' && ch[1]=='r' && ch[2]=='b' && ch[3]=='?')
	{
		ch=strtok(NULL,"\n");
		closestpair (fgeo,cont,ntor,report);
	}
	else if(ch==NULL)
	{
		exit(0);
	}
	}
}