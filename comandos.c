#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "comandos.h"
#include "retangulo.h"
#include "circulo.h"
#include "arquivo.h"
#include "list.h"
#include "formaGeo.h"

void comandos(FILE *e,char *diretorio,char *nomebase)
{
    FILE *sig;
    FILE *sig2;
    char espaco[2]=" ";
    char *linha,*ch;
    char *info;
    char *nomearq;
    char *dio;
    char *svg;
    char c;
    char *element1,*element2,*element3,*element4,*element5,*element6,*element7;
    int element0;
    int ndefault=1000;
    int cont=0;
    int sizefile=0;
    int tamdio=0;
    Posic *p;
    fg *fgeo;
    Circulo *circ;
    Retangulo *ret;
    circ=malloc(sizeof(0));
    ret=malloc(sizeof(0));
    sig=fopen(nomebase,"w");
    dio=malloc(sizeof(0));
    svg=malloc(sizeof(0));
    linha=malloc(sizeof(char));
    nomearq=(char *) malloc(sizeof(char));
    fgeo=createFG ();
	while (1)
	{
        if (cont>ndefault)
        {
            printf("numero de formas geometricas excedido\n");
            exit (0);
        }
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
	ch=strtok(linha,espaco);
    if (ch[0]=='n' && ch[1]=='x')
    {
        ch=strtok(NULL,"\n");
        nCirculo(&ndefault,ch);
    }
    else if (ch[0]=='c')
    {
        ch=strtok(NULL,"\n");
        element0=cont;
        info=strtok(ch," ");
        element1=info;
        info=strtok(NULL," ");
        element2=info;
        info=strtok(NULL," ");
        element3=info;
        info=strtok(NULL," ");
        element4=info;
        info=strtok(NULL," ");
        element5=info;
        info=strtok(NULL," ");
        element6=info;
        circ=createCirculo (&element0,atoi(element1),element2,element3,atof(element4),atof(element5),atof(element6));
        addCircle (fgeo,circ);
        cont++;
    }
    
    else if (ch[0]=='r')
    {
        ch=strtok(NULL,"\n");
        element0=cont;
        info=strtok(ch," ");
        element1=info;
        info=strtok(NULL," ");
        element2=info;
        info=strtok(NULL," ");
        element3=info;
        info=strtok(NULL," ");
        element4=info;
        info=strtok(NULL," ");
        element5=info;
        info=strtok(NULL," ");
        element6=info;
        info=strtok(NULL," ");
        element7=info;
        ret=createRetangulo(element0,atoi(element1),element2,element3,atof(element4),atof(element5),atof(element6),atof(element7));
        addRet(fgeo,ret);
        cont++;
    }
    
    else if (ch[0]=='o')
    {
        ch=strtok(NULL,"\n");
        dio=sobreposicao (fgeo,ch,dio,&tamdio);
    }
    
    else if (ch[0]=='i')
    {
        ch=strtok(NULL,"\n");
        dio=pontointerno (fgeo,ch,dio,&tamdio);
    }
    
    else if (ch[0]=='d')
    {
        ch=strtok(NULL,"\n");
        dio=distancia (fgeo,ch,dio,&tamdio);
    }
    
    else if (ch[0]=='a')
    {
        ch=strtok(NULL,"\n");
        sig2=criaSuf (diretorio,nomebase,nomearq,sig2,ch);
        insereSVG(sig2,cont,fgeo);
        sig2=tracaLinha(sig2,ch,cont);
        terminaSVG(sig2);
        fclose(sig2);
    }
    
    else if (ch[0]=='#')
    {
        iniciaSVG(sig);
        insereSVG(sig,cont,fgeo);
        criaDio(dio,nomebase,tamdio);
        terminaSVG(sig);
        free(linha);
        finalArq ();
        break;
    }
    }
}