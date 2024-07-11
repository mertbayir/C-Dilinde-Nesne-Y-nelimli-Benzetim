#ifndef BITKI_H
#define BITKI_H

#include "canli.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

struct BITKI
{
  Canli super;
  void (*yoket_bitki)(struct BITKI*);
};

typedef struct BITKI* Bitki;

Bitki BitkiOlustur();
void yoket_bitki(const Bitki);
char* gorunumBitki();


#endif