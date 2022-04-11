#include <iostream>
#include <string>
#include "include/Manager.h"

void SetUpResources(Manager &mainManager);

int main()
{
    Manager mainManager = Manager();
    SetUpResources(mainManager);
    mainManager.CreateHouse();
    mainManager.CreatePerson();
    mainManager.CreatePerson();
    mainManager.CreatePerson();
    //mainManager.personManager.GivePersonJob(0, jobRole::Miner);
    //mainManager.personManager.GivePersonJob(1, jobRole::Logger);
    //mainManager.personManager.GivePersonJob(2, jobRole::Farmer);



    bool playGame = true;

    while (playGame){
        bool advanceDay = false;
        system("cls");
        while (!advanceDay)
        {
            mainManager.DisplayData();
            advanceDay = mainManager.DisplayChoices();
            std::cout << "Press Enter to continue.. " << std::endl;
            char option = std::toupper(getchar());
            system("cls");
        }
    }

        mainManager.GetResource("Wood")->UpdateAmount(1);



    return 0;
};

void SetUpResources(Manager &mainManager)
{
    Resource wood = Resource("Wood", 10, ResourceTypes::Wood, UsefulObjectType::HouseObject);
    Resource crops = Resource("Crops", 10, ResourceTypes::Crops, UsefulObjectType::MealObject);
    Resource stone = Resource("Stone", 10, ResourceTypes::Stone, UsefulObjectType::ToolObject);
    mainManager.AddResource(wood);
    mainManager.AddResource(crops);
    mainManager.AddResource(stone);
};
