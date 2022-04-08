#include "../../../include/Loggers.h"
#include <string>

Loggers::Loggers(){};

Loggers::Loggers(People person)
{
    PUID(person.PUID());
    PName(person.PName());
    PAge(person.PAge());
    PRole(person.PRole());
    PHunger(person.PHunger());
    PHoused(person.PHoused());
};
