#include <stdio.h>
#include <stdlib.h>

#include "list.h"

typedef struct  posicao{
  void *element;
  struct posicao *next; /*proximo elemento, em direcao ao fim*/
  struct posicao *prev; /*elemento anterior, em direcao ao inicio*/
} posicao;

typedef struct list{
  int lenght;
  posicao *inicio; /*primeiro elemento da lista*/
  posicao *final; /*ultimo elemento da lista*/
}lista;

Lista createLista ()
{
    lista *lis;
    lis=malloc(sizeof(lista));
    lis->lenght=0;
    lis->inicio=NULL;
    lis->final=NULL;
    return lis;
}

int lenght (Lista pList)
{   
    lista *l;
    l = (lista *)pList;
    return l->lenght;
}

Posic insert (Lista pLista, Objeto pItem)
{
    lista *l;
  posicao *n, *aux;

  l=(lista *)pLista;
  n=malloc(sizeof(posicao));


  (l->lenght)++;

  if(l->final==NULL)
  {
    l->inicio=n;
    l->final=n;

    n->element=pItem;
    n->next=NULL;
    n->prev=NULL;
  }
  else
  {
    aux=l->final;
    aux->next=n;

    n->element=pItem;
    n->next=NULL;
    n->prev=aux;
    l->final=n;
  }
  return n;
}

void remover (Lista pLista,Posic pPosic)
{
    lista *l;
    posicao *aux,*aux2,*p;

    l=(lista *)pLista;
    p=(posicao *)pPosic;

    if(l->lenght==1)
    {
      free(p);
      l->inicio=NULL;
      l->final=NULL;
      (l->lenght)--;
    }
    else if(l->inicio==p)
    {
      aux=p->next;
      free(p);
      l->inicio=aux;
      aux->prev=NULL;
      (l->lenght)--;
    }
    else if(l->final==p)
    {
      aux = p->prev;
      free(p);
      l->final=aux;
      aux->next=NULL;
      (l->lenght)--;
    }
    else
    {
      aux=p->prev;
      aux2=p->next;
      free(p);
      aux->next=aux2;
      aux2->prev=aux;
      (l->lenght)--;
    }
}

void *get(Lista pLista,Posic pPosic)
{
  posicao *n;
  n = (posicao *)pPosic;
  return n->element;
}

Posic insertBefore(Lista pLista,Posic pPosic,Objeto pItem)
{
    lista *l;
    posicao *p,*aux,*aux2;

    l=(lista *)pLista;
    p=(posicao *)pPosic;

    aux=malloc(sizeof(posicao));
    aux->element=pItem;
    (l->lenght)++;

    if(l->inicio==p)
    {
        l->inicio=aux;
        aux->prev=NULL;
        aux->next=p;
        p->prev=aux;
        return aux;
    }
    else
    {
        aux2=p->prev;
        aux2->next=aux;
        p->prev=aux;
        aux->prev=aux2;
        aux->next=p;
        return aux;
    }
}

Posic insertAfter(Lista pLista,Posic pPosic,Objeto pItem)
{
    lista *l;
    posicao *p,*aux,*aux2;

    l = (lista *)pLista;
    p = (posicao *)pPosic;

    aux = malloc(sizeof(posicao));
    aux->element=pItem;
    (l->lenght)++;

    if(l->final==p)
    {
        l->final=aux;
        aux->prev=p;
        aux->next=NULL;
        p->next=aux;
        return aux;
    }
    else
    {
        aux2=p->next;
        aux2->prev=aux;
        p->next=aux;
        aux->prev=p;
        aux->next=aux2;
        return aux;
    }
}

Posic getFirst(Lista pLista)
{
    lista *l;
    l=(lista *)pLista;
    return l->inicio;
}

Posic getNext(Lista pLista,Posic pPosic)
{
    posicao *n;
    n=(posicao *)pPosic;
    return n->next;
}

Posic getLast(Lista pLista)
{
    lista *l;
    l=(lista *)pLista;
    return l->final;
}

Posic getPrevious(Lista pLista,Posic pPosic)
{
    posicao *n;
    n=(posicao *)pPosic;
    return n->prev;
}

void freeLista(Lista pLista)
{
    lista *l;
    posicao *n;
    l=(lista *)pLista;
    while(lenght(pLista)!=0)
    {
    remover(pLista,getFirst(pLista));
    }
    free(l);
}