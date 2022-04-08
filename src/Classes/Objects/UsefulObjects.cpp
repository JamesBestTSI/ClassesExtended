#include "../../../include/UsefulObjects.h"

UsefulObject::UsefulObject(){};
UsefulObject::UsefulObject(std::string name, int amount, int durability){
    Name = name;
    Amount = amount;
    Durability = durability;
};
std::string UsefulObject::UsefulObjectName() { return Name; };
int UsefulObject::Amounts() { return Amount; };
void UsefulObject::UpdateAmount(int amount) { Amount += amount; };
int UsefulObject::Durabilities() { return Durability; };
void UsefulObject::UpdateDurability(int amount) { Durability += amount; };