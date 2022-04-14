#include <iostream>
#include <string>
#include "include/Constants.h"
#include "include/Manager.h"

void SetUpResources(Manager &mainManager);
void Introduction();

int main()
{
    Manager mainManager = Manager();
    Introduction();
    SetUpResources(mainManager);
    bool playGame = true;

    while (playGame){
        bool advanceDay = false;
        system("cls");
        while (!advanceDay){
            mainManager.DisplayData();
            mainManager.DisplayInfo();
            advanceDay = mainManager.DisplayChoices();
            std::cout << "Press Enter to continue.. " << std::endl;
            char option = std::toupper(getchar());
            system("cls");
        }
        if (mainManager.personManager.PeopleCount() == 0 && mainManager.GetResource("Wood")->Amounts() < 10 && mainManager.HouseCount() ==0){
            playGame = false;
            std::cout << "You have no people, no wood to make houses, and no working houses...\nGAME OVER!" << std::endl;
            std::cout << "Press Enter to Exit.. " << std::endl;
            char option = std::toupper(getchar());
        }
    }
    return 0;
};

/**
 * @brief Set the Up Resources that will be tracked as well as firsat house and people
 * 
 * @param mainManager the main manager that manages the resources.
 */
void SetUpResources(Manager &mainManager)
{
    Resource wood = Resource("Wood", costOfHouse, ResourceTypes::Wood);
    Resource crops = Resource("Crops", costOfMeal*2, ResourceTypes::Crops);
    Resource stone = Resource("Stone", costOfTool*2, ResourceTypes::Stone);
    mainManager.AddResource(wood);
    mainManager.AddResource(crops);
    mainManager.AddResource(stone);
    mainManager.CreateHouse();
    mainManager.CreatePerson();
    mainManager.CreatePerson();
    mainManager.CreatePerson();
};

/**
 * @brief Introduction of the project.
 * 
 */
void Introduction()
{
    std::cout << "#########################" << std::endl;
    std::cout << "# Settlement Management #" << std::endl;
    std::cout << "#########################\n" << std::endl;

    std::cout << "This system represents a basic working settlement." << std::endl;
    std::cout << "You start with one house that can house 3 people and are tasked with growing the settlement larger.\n" << std::endl;

    std::cout << "Each house holds " << peoplePerHouse << " people.\n" << std::endl;

    std::cout << "People get hungry and will need feeding." << std::endl;
    std::cout << "When their hunger hits 100% they will try and eat a meal." << std::endl;

    std::cout << "Each person can be assigned a job." << std::endl;
    std::cout << "Each job will collect 1 resource so long as a person is housed and not starving." << std::endl;
    std::cout << "However, if a worker has a tool, they will gather 2 resources instead.\n" << std::endl;

    std::cout << "Tools cost " << costOfTool << " stone to create, and will break over time." << std::endl;
    std::cout << "Houses cost " << costOfHouse << " wood and will break over time" << std::endl;
    std::cout << "Meals cost " << costOfMeal << " crops and degrade over time." << std::endl;

    std::cout << "\n\nLets start by naming your first 3 people..." << std::endl;
};