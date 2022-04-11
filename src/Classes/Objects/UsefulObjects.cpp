#include "../../../include/UsefulObjects.h"

UsefulObject::UsefulObject(){};
UsefulObject::UsefulObject(std::string name, int amount, int durability){
    Name = name;
    Amount = amount;
    Durability = durability;
};
void UsefulObject::SetID(int uid) { UID = uid; };
int UsefulObject::GetID() { return UID; };
std::string UsefulObject::UsefulObjectName() { return Name; };
void UsefulObject::UsefulObjectName(std::string name) { Name = name; };
int UsefulObject::Amounts() { return Amount; };
void UsefulObject::UpdateAmount(int amount) { Amount += amount; };
int UsefulObject::Durabilities() { return Durability; };
void UsefulObject::UpdateDurability(int amount) { Durability += amount; };