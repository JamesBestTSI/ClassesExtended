#include "../../../include/Farmers.h"
#include <string>

Farmers::Farmers(){};

Farmers::Farmers(People person)
{
    PUID(person.PUID());
    PName(person.PName());
    PAge(person.PAge());
    PRole(person.PRole());
    PHunger(person.PHunger());
    PHoused(person.PHoused());
};
