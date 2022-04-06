#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>

enum UsefulObjectTypes
{
    House,
    Meal,
    Tool
};

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
        UsefulObjectTypes ObjectCreated;

    public:
        Resource();
        Resource(std::string name, int amount, ResourceTypes resourceType, UsefulObjectTypes objectCreated);
        std::string ResourceName();
        int Amounts();
        void UpdateAmount(int amount);
        bool CreateLinkedObject();
};
#endif