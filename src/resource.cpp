#include "resource.h"

Resource::Resource()
{
    Name = "NULL";
    Amount = 0;
    ResourceType = ResourceTypes::Wood;
    ObjectCreated = UsefulObjectTypes::House;
};
Resource::Resource(std::string name, int amount, ResourceTypes resourceType, UsefulObjectTypes objectCreated){
    Name = name;
    Amount = amount;
    ResourceType = resourceType;
    ObjectCreated = objectCreated;
};
std::string Resource::ResourceName() { return Name; };
int Resource::Amounts() { return Amount; };
void Resource::UpdateAmount(int amount) { Amount += amount; };
bool Resource::CreateLinkedObject(){
    // Create object
    // if created
    return true;
    // Else
    // return false;
};
