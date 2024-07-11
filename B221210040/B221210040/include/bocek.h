
#ifndef BOCEK_H
#define BOCEK_H

#include "canli.h"
#include "stdlib.h"
#include "stdio.h"


struct BOCEK
{
  Canli super;
  void (*yoket_bocek)(struct BOCEK*);
};


typedef struct BOCEK* Bocek;
Bocek BocekOlustur();
void yoket_bocek(const Bocek);
char* gorunumBocek();


#endif