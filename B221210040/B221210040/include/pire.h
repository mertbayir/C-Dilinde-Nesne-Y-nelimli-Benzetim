#ifndef PIRE_H
#define PIRE_H

#include "canli.h"
#include "stdlib.h"
#include "bocek.h"
#include "stdio.h"

struct PIRE
{
   Bocek super;
   void (*yoket_pire)(struct PIRE*);
};
typedef struct PIRE* Pire;

Pire PireOlustur();
void yoket_pire(const Pire);

char* gorunumPire();


#endif