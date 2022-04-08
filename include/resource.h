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
        UsefulObjectType ObjectCreated;

    public:
        Resource();
        Resource(std::string name, int amount, ResourceTypes resourceType, UsefulObjectType objectCreated);
        std::string ResourceName();
        int Amounts();
        void UpdateAmount(int amount);
        bool CreateLinkedObject();
};
#endif