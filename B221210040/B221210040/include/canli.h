#ifndef CANLI_H
#define CANLI_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"


struct CANLI
{
  int sayiDeger;
  void (*yoket)(struct CANLI*);
  void (*canlilariYazdir)(struct CANLI**);
  void (*ekran_sil)();
  int id;
  char* (*gorunum)();

};

typedef struct CANLI* Canli;

Canli Canli_Olustur();
void ekran_sil();
void yoket(const Canli);
void canlilariYazdir(Canli*,int,int);




#endif