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
        int houseUID = 0;
        int peoplePerHouse = 3;

    public:
        PersonManager personManager;
        // Constructor
        Manager();
        int GetInt();


        /***********************/
        /* Resource Management */
        /***********************/

        void AddResource(Resource resource);
        Resource *GetResource(std::string resourceType);


        /*****************/
        /* Display things */
        /*****************/

        void DisplayData();
        bool DisplayChoices();
        void DisplayOptions();
        void CreateOptions();
        void ListPersonOptions();
        void ListPersonByID();
        void ListPeopleByRole();
        void ListHouses();
        void ListMeals();
        void ListTools();

        /*****************/
        /* Create things */
        /*****************/

        bool CreatePerson();
        bool CreateHouse();
        bool CreateMeal();
        bool CreateTool();


        /*****************/
        /* Update things */
        /*****************/

        void UpdatePeople();
        void UpdateHouses();
        void UpdateMeals();
        void UpdateTools();

        House *FindHouseWithSpace();

        void ConsumeMeal();

        void GivePersonJob();
        void GivePersonTool();
        void FixHouse();
};
#endif