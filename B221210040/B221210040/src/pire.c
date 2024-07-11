#include "pire.h"

Pire PireOlustur()
{
    Pire this;
    this = (Pire)malloc(sizeof(struct PIRE));
    this->super= BocekOlustur();
    this->yoket_pire = &yoket_pire;
    this->super->super->gorunum = &gorunumPire;
    return this;
}



void yoket_pire(const Pire this)
{
  if (this == NULL)
  {
    return;
  }

  this->super->yoket_bocek(this->super);
  free(this);
}

char* gorunumPire()
{
    return "P";
}