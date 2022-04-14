#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>
#include "UsefulObjects.h"

enum ResourceTypes
{
    Wood,
    Crops,
    Stone
};

class Resource{

    private:
        std::string Name;
        int Amount;
        ResourceTypes ResourceType;

    public:
        Resource();
        Resource(std::string name, int amount, ResourceTypes resourceType);
        std::string ResourceName();
        int Amounts();
        void UpdateAmount(int amount);
};
#endif