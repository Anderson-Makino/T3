#ifndef CONSULTAQRY_H
#define CONSULTAQRY_H

typedef void* fg;

void reportaRetQry(float x,float y,float larg,float alt,unsigned long int cont,FILE *report,unsigned long int *nequips,unsigned long int *contequips,fg *fgeo);
void reportaCircQry(float r,float x,float y,unsigned long int cont,FILE *report,unsigned long int *nequips,unsigned long int *contequips,fg *fgeo);
void removeBlockInQuad(float x,float y,float larg,float alt,unsigned long int cont,unsigned long int *nequips,unsigned long int *contequips,fg *fgeo);
void removeEquipsInQuad(char *obj,float x,float y,float larg,float alt,unsigned long int cont,unsigned long int *nequips,unsigned long int *contequips,fg *fgeo);
void removeBlockInCirc(float r,float x,float y,unsigned long int cont,unsigned long int *nequips,unsigned long int *contequips,fg *fgeo);
void removeEquipsInCirc(char *obj,float x,float y,float r,unsigned long int cont,unsigned long int *nequips,unsigned long int *contequips,fg *fgeo);
void mudaCor(char *id,char *cor1,char *cor2,unsigned long int cont,unsigned long int *nequips,unsigned long int *contequips,fg *fgeo);
void informa(char *id,FILE *report,fg *fgeo);

#endif
