#include "../../../include/Tools.h"
#include <string>

Tools::Tools(){};

bool Tools::Available() { return available; };

void Tools::Available(bool isavailable) { available = isavailable; };

void Tools::SetOwner(People *person)
{
    ownerID = person->PUID();
}

int Tools::GetOwner() { return ownerID; };

void Tools::Break(){
    //owner->RemoveTool();
};