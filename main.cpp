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
    mainManager.personManager.GivePersonJob(1, jobRole::Miner);
    mainManager.personManager.GivePersonJob(2, jobRole::Farmer);

    mainManager.DisplayData();

    mainManager.personManager.ListPersonInfo(1);
    mainManager.personManager.ListPeopleInRole(jobRole::None);

    

    mainManager.GetResource("Wood")->UpdateAmount(1);



    return 0;
};

void SetUpResources(Manager &mainManager)
{
    Resource wood = Resource("Wood", 10, ResourceTypes::Wood, UsefulObjectType::HouseObject);
    Resource crops = Resource("Crops", 0, ResourceTypes::Crops, UsefulObjectType::MealObject);
    Resource stone = Resource("Stone", 0, ResourceTypes::Stone, UsefulObjectType::ToolObject);
    mainManager.AddResource(wood);
    mainManager.AddResource(crops);
    mainManager.AddResource(stone);
};
