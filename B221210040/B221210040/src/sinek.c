#include "sinek.h"


Sinek SinekOlustur()
{
    Sinek this;
    this = (Sinek)malloc(sizeof(struct SINEK));
    this->super= BocekOlustur();
    this->yoket_sinek = &yoket_sinek;
    this->super->super->gorunum = &gorunumSinek;
    return this;
}


void yoket_sinek(const Sinek this)
{
  if (this == NULL)
  {
    return;
  }

  this->super->yoket_bocek(this->super);
  free(this);
}


char* gorunumSinek()
{
    return "S";
}