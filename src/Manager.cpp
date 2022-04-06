#include "Manager.h"

Manager::Manager(){};

void Manager::AddResource(Resource resource){
    resources.push_back(resource);
};

Resource* Manager::GetResource(std::string resourceType)
{
    std::list<Resource>::iterator resource = resources.begin();

    for (int i = 0; i < resources.size(); i++)
    {
        if (resource->ResourceName() == resourceType)
        {
            return &*resource;
        }
        ++resource;
    }
    return 0;
};

void Manager::AddUsefulObject(UsefulObject usefulObject){
    usefulObjects.push_back(usefulObject);
};

UsefulObject *Manager::GetUsefulObject(std::string usefulObjectType)
{
    std::list<UsefulObject>::iterator usefulObject = usefulObjects.begin();

    for (int i = 0; i < usefulObjects.size(); i++)
    {
        if (usefulObject->UsefulObjectName() == usefulObjectType)
        {
            return &*usefulObject;
        }
        ++usefulObject;
    }
    return 0;
};