#ifndef MANAGER_H
#define MANAGER_H
#include <list>
#include "PersonManager.h"
#include "People.h"
#include "Unemployed.h"
#include "resource.h"
#include "UsefulObjects.h"
#include "House.h"
#include "Meals.h"
#include "Tools.h"

class Manager{
    private:
        std::list<Resource> resources{};
        std::list<House> houses{};
        std::list<Meals> meals{};
        std::list<Tools> tools{};
        int peopleUID = 0;
        int peoplePerHouse = 3;

    public:
        PersonManager personManager;
        // Constructor
        Manager();

        // Resource Management
        void AddResource(Resource resource);
        Resource *GetResource(std::string resourceType);

        void ConsumeMeal();

        void DisplayData();

        bool CreateHouse();
        bool CreateMeal();
        bool CreateTool();
        bool CreatePerson();

        House *FindHouseWithSpace();
};
#endif