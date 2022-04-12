#include <iostream>
#include <string>
#include "include/Manager.h"

void SetUpResources(Manager &mainManager);
void Introduction();

int main()
{
    Introduction();
    Manager mainManager = Manager();
    SetUpResources(mainManager);



    bool playGame = true;

    while (playGame){
        bool advanceDay = false;
        system("cls");
        while (!advanceDay)
        {
            mainManager.DisplayData();
            mainManager.DisplayInfo();
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
    Resource wood = Resource("Wood", 100, ResourceTypes::Wood, UsefulObjectType::HouseObject);
    Resource crops = Resource("Crops", 20, ResourceTypes::Crops, UsefulObjectType::MealObject);
    Resource stone = Resource("Stone", 20, ResourceTypes::Stone, UsefulObjectType::ToolObject);
    mainManager.AddResource(wood);
    mainManager.AddResource(crops);
    mainManager.AddResource(stone);
    mainManager.CreateHouse();
    mainManager.CreatePerson();
    mainManager.CreatePerson();
    mainManager.CreatePerson();
};

void Introduction()
{
    std::cout << "#########################" << std::endl;
    std::cout << "# Settlement Management #" << std::endl;
    std::cout << "#########################" << std::endl;
    std::cout << "\nThis system represents a basic working settlement.\nYou start with one house that can house 3 people and are tasked with growing the settlement larger." << std::endl;
    std::cout << "\nEach house holds 3 people.\n\nPeople get hungry and will need feeding.\nWhen their hunger hits 100% they will try and eat a meal.\nEach Meal costs 10 crops to make." << std::endl;
    std::cout << "\nEach person can be assigned a job.\nEach job will collect 1 resource so long as a person is housed and not starving.\nIf a worker has a tool, they will gather 2 resources instead." << std::endl;
    std::cout << "\nTools cost 15 stone to create, and will break over time.\nHouses cost 100 wood and will break over time\nMeals cost 25 crops and degrade over time." << std::endl;
    std::cout << "\n\nLets start by naming your first 3 people..." << std::endl;
};