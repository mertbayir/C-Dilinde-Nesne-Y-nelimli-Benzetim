#ifndef SINEK_H
#define SINEK_H

#include "canli.h"
#include "stdlib.h"
#include "bocek.h"
#include "stdio.h"


struct SINEK
{
  Bocek super;
  void (*yoket_sinek)(struct SINEK*);
};

typedef struct SINEK* Sinek;

Sinek SinekOlustur();
void yoket_sinek(const Sinek);

char* gorunumSinek();



#endif