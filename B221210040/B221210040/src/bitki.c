#include "bitki.h"


Bitki BitkiOlustur()
{
    Bitki this;
    this = (Bitki)malloc(sizeof(struct BITKI));
    this->super= Canli_Olustur();
    this->super->gorunum = &gorunumBitki;
    this->yoket_bitki = &yoket_bitki;
    return this;
}

void yoket_bitki(const Bitki this)
{
  if (this == NULL)
  {
    return;
  }
  
  this->super->yoket(this->super);
  free(this);
}

char* gorunumBitki()
{
    return "B";
}