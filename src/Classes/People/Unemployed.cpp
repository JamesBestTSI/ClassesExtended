#include "../../../include/Unemployed.h"
#include <string>

Unemployed::Unemployed(){};

Unemployed::Unemployed(People person){
    PUID(person.PUID());
    PName(person.PName());
    PAge(person.PAge());
    PRole(person.PRole());
    PHunger(person.PHunger());
    PHoused(person.PHoused());
};


bool Unemployed::PEat() {
    PHunger(50);
    return true;
};
