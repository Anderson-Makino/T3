#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "comandos.h"
#include "retangulo.h"
#include "circulo.h"
#include "quadra.h"
#include "semaforo.h"
#include "hidrante.h"
#include "torre.h"
#include "arquivo.h"
#include "list.h"
#include "formaGeo.h"
#include "funcoes.h"

int comandos(FILE *e,char *diretorio,char *nomebase,char *token,char *qry)
{
    FILE *sig;
    FILE *sig2;
    char espaco[2]=" ";
    char *linha,*ch;
    char *info;
    char *dio;
    char *svg;
    char c;
    char *comandA;
    char *element1,*element2,*element3,*element4,*element5,*element6,*element7;
    char *cor1q,*cor2q,*cor1h,*cor2h,*cor1t,*cor2t,*cor1s,*cor2s;
    unsigned long int element0;
    int ndefault=1000;
    unsigned long int cont=0,contnx=0;
    int sizefile=0;
    int tamdio=0;
    int idA;
    int ntor=0;
    Posic *p;
    fg *fgeo;
    Circulo *circ;
    Retangulo *ret;
    Quadra *quad;
    Hidrante *hid;
    Semaforo *sem;
    Torre *tor;
    sig=fopen(nomebase,"w");
    dio=malloc(sizeof(0));
    svg=malloc(sizeof(0));
    linha=malloc(sizeof(char));
    fgeo=createFG ();
	while (1)
	{
        if (contnx>ndefault)
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
    else if (ch[0]=='c' && ch[1]=='q')  //pega cores de quadra
    {
        ch=strtok(NULL,"\n");
        info=strtok(ch," ");
        cor1q=pegaCor(ch,info);
        info=strtok(NULL," ");
        cor2q=pegaCor(ch,info);
    }
    else if (ch[0]=='c' && ch[1]=='h')  //pega cores de hidrante
    {
        ch=strtok(NULL,"\n");
        info=strtok(ch," ");
        cor1h=pegaCor(ch,info);
        info=strtok(NULL," ");
        cor2h=pegaCor(ch,info);
    }
    else if (ch[0]=='c' && ch[1]=='t')  //pega cores de torre
    {
        ch=strtok(NULL,"\n");
        info=strtok(ch," ");
        cor1t=pegaCor(ch,info);
        info=strtok(NULL," ");
        cor2t=pegaCor(ch,info);
    }
    else if (ch[0]=='c' && ch[1]=='s')  //pega cores de semaforo
    {
        ch=strtok(NULL,"\n");
        info=strtok(ch," ");
        cor1s=pegaCor(ch,info);
        info=strtok(NULL," ");
        cor2s=pegaCor(ch,info);
    }
    else if (ch[0]=='c')     //insere um circulo
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
        circ=createCirculo (element0,atoi(element1),element2,element3,atof(element4),atof(element5),atof(element6));
        addCircle (fgeo,circ);
        cont++;
        contnx++;
    }
    
    else if (ch[0]=='r')     //insere um retangulo
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
        contnx++;
    }
    else if(ch[0]=='q')     //insere quadra
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
        quad=createQuadra(element0,element1,atof(element2),atof(element3),atof(element4),atof(element5),cor1q,cor2q);
        addBlock(fgeo,quad);
        cont++;
    }

    else if(ch[0]=='h')     //insere hidrante
    {
        ch=strtok(NULL,"\n");
        element0=cont;
        info=strtok(ch," ");
        element1=info;
        info=strtok(NULL," ");
        element2=info;
        info=strtok(NULL," ");
        element3=info;
        hid=createHidrante(element0,element1,atof(element2),atof(element3),cor1h,cor2h);
        addHydrant(fgeo,hid);
        cont++;
    }

    else if(ch[0]=='s')     //insere semaforo
    {
        ch=strtok(NULL,"\n");
        element0=cont;
        info=strtok(ch," ");
        element1=info;
        info=strtok(NULL," ");
        element2=info;
        info=strtok(NULL," ");
        element3=info;
        sem=createSemaforo(element0,element1,atof(element2),atof(element3),cor1s,cor2s);
        addSemaphore(fgeo,sem);
        cont++;
    }

    else if(ch[0]=='t')     //insere torre de celular
    {
        ch=strtok(NULL,"\n");
        element0=cont;
        info=strtok(ch," ");
        element1=info;
        info=strtok(NULL," ");
        element2=info;
        info=strtok(NULL," ");
        element3=info;
        tor=createTorre(element0,element1,atof(element2),atof(element3),cor1t,cor2t);
        addTower(fgeo,tor);
        cont++;
        ntor++;
    }

    else if(ch[0]=='q' && ch[1]=='?')
    {
        ch=strtok(NULL,"\n");
        
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
        info=strtok(ch," ");
        idA=atoi(info);
        info=strtok(NULL," ");
        comandA=malloc(sizeof(char)*(strlen(info)+1));
        strcpy(comandA,info);
        sig2=criaSuf (diretorio,nomebase,sig2,comandA);
        insereSVG(sig2,cont,fgeo);
        sig2=tracaLinha(sig2,idA,cont,fgeo);
        terminaSVG(sig2);
        fclose(sig2);
    }
    
    else if (ch[0]=='#')
    {
        iniciaSVG(sig);
        insereSVG(sig,cont,fgeo);
        criaDio(dio,nomebase,tamdio);
        terminaSVG(sig);
        free (linha);
        free (dio);
        free (svg);
        fclose(e);
        if (qry!=NULL)
        {
	    executarQry(token,qry,nomebase,cont,fgeo,ntor);
        }
        else 
        {
           return 0;
        }
    }
    }
}