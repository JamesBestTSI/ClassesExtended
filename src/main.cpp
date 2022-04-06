#include <iostream>
#include <string>
#include "Manager.h"

void SetUpResources(Manager &mainManager);

int main(){

    Manager mainManager = Manager();
    SetUpResources(mainManager);

    mainManager.GetResource("Wood")->UpdateAmount(1);

    return 0;
};

void SetUpResources(Manager &mainManager)
{
    Resource wood = Resource("Wood", 0, ResourceTypes::Wood, UsefulObjectTypes::House);
    Resource crops = Resource("Crops", 0, ResourceTypes::Crops, UsefulObjectTypes::Meal);
    Resource stone = Resource("Stone", 0, ResourceTypes::Stone, UsefulObjectTypes::Tool);
    mainManager.AddResource(wood);
    mainManager.AddResource(crops);
    mainManager.AddResource(stone);
};
