#ifndef MANAGER_H
#define MANAGER_H
#include <list>
#include "resource.h"
#include "UsefulObjects.h"

class Manager{
    private:
        std::list<Resource> resources{};
        std::list<UsefulObject> usefulObjects{};

    public:
        Manager();
        void AddResource(Resource resource);
        Resource *GetResource(std::string resourceType);

        void AddUsefulObject(UsefulObject usefulObject);
        UsefulObject *GetUsefulObject(std::string usefulObjectType);
};
#endif