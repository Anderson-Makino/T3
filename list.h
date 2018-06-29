#ifndef LIST_H
#define LIST_H

typedef void* Lista;
typedef void* Posic;
typedef void* Objeto;

Lista createLista ();

int lenght ();

Posic insert (Lista pLista,Objeto pItem);

void remover (Lista pLista,Posic pPosic);

Objeto get(Lista pLista,Posic pPosic);

Posic insertBefore(Lista pLista,Posic pPosic,Objeto pItem);

Posic insertAfter(Lista pLista,Posic pPosic,Objeto pItem);

Posic getFirst(Lista pLista);

Posic getNext(Lista pLista,Posic pPosic);

Posic getLast(Lista pLista);

Posic getPrevious(Lista pLista,Posic pPosic);

void freeLista(Lista pLista);

#endif