#include "../../../include/Miners.h"
#include <string>

Miners::Miners(){};

Miners::Miners(People person)
{
    PUID(person.PUID());
    PName(person.PName());
    PAge(person.PAge());
    PRole(person.PRole());
    PHunger(person.PHunger());
    PHoused(person.PHoused());
};
