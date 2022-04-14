#include "../../../include/resource.h"

Resource::Resource()
{
    Name = "NULL";
    Amount = 0;
    ResourceType = ResourceTypes::Wood;
};
Resource::Resource(std::string name, int amount, ResourceTypes resourceType)
{
    Name = name;
    Amount = amount;
    ResourceType = resourceType;
};
std::string Resource::ResourceName() { return Name; };
int Resource::Amounts() { return Amount; };
void Resource::UpdateAmount(int amount) { Amount += amount; };

