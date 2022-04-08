#include <iostream>
#include "../../../include/Manager.h"


Manager::Manager(){};

/**
 * @brief Adds a new Resource to the list.
 * 
 * @param resource The new Resource we want to add.
 */
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








// void Manager::UpdatePeople(){

//     std::list<Unemployed>::iterator person = unemployedPeople.begin();
//     for (int i = 0; i < unemployedPeople.size(); i++)
//     {
//         if (person->PHunger() == 100 && meals.size() > 0){
//             // Man be hungry and we have a meal available
//             ConsumeMeal();
//             person->PEat();
//         }
//         else if (person->PHunger() == 100){
//             // Man be hungry but no meals free
//             // EAT FINGERS!
//         }
//         ++person;
//     }
// };

/**
 * @brief Looks through the list of Meals we have and 
 * then consumes the one with the least durability
 */
void Manager::ConsumeMeal(){
    // Find the meal with the least durability
    int index = 0;
    int durability = 100;
    std::list<Meals>::iterator meal = meals.begin();
    for (int mealIndex = 0; mealIndex < meals.size(); mealIndex++)
    {
        if (meal->Durabilities() < durability)
        {
            index = mealIndex;
            durability = meal->Durabilities();
        }
        ++meal;
    }

    // Set iterator to the meal with the least durability
    meal = meals.begin();
    for (int mealIndex = 0; mealIndex < index; mealIndex++){++meal;}

    // Remove that meal
    meals.erase(meal);
};

void Manager::DisplayData()
{
    Resource *wood = GetResource("Wood");
    Resource *crops = GetResource("Crops");
    Resource *stone = GetResource("Stone");

    std::string housesSize = std::to_string(houses.size());
    while (housesSize.length() < 3)     {housesSize = "0" + housesSize;}

    std::string mealsSize = std::to_string(meals.size());
    while (mealsSize.length() < 3)      {mealsSize = "0" + mealsSize;}

    std::string toolsSize = std::to_string(tools.size());
    while (toolsSize.length() < 3)      {toolsSize = "0" + toolsSize;}

    std::string unemployedSize = std::to_string(personManager.unemployedCount());
    while (unemployedSize.length() < 3) {unemployedSize = "0" + unemployedSize;}

    std::string minerSize = std::to_string(personManager.minerCount());
    while (minerSize.length() < 3)      {minerSize = "0" + minerSize;}

    std::string loggerSize = std::to_string(personManager.loggerCount());
    while (loggerSize.length() < 3)     {loggerSize = "0" + loggerSize;}

    std::string farmerSize = std::to_string(personManager.farmerCount());
    while (farmerSize.length() < 3)     {farmerSize = "0" + farmerSize;}

    std::cout << "People: [" << personManager.unemployedCount() + personManager.minerCount() + personManager.farmerCount() + personManager.loggerCount() << "/" << peoplePerHouse << "]   "
              << loggerSize << " Logger - " << minerSize << " Miner - " << farmerSize << " Farmer - " << unemployedSize << " Unemployed" << std::endl;
    std::cout << "Usable:         " << housesSize << " Houses - " << mealsSize << " Meals - " << toolsSize << " Tools" << std::endl;
    std::cout << "Resources:      " << wood->Amounts() << " Wood - " << stone->Amounts() << " Stone - " << crops->Amounts() << " Crops" << std::endl;

};

bool Manager::CreatePerson()
{
    House *homeWithSpace = FindHouseWithSpace();
    if (homeWithSpace == 0){
        // No house found
        return false;
    }
    People James1 = People("James", 32, jobRole::None);
    personManager.AddPerson(James1);
    homeWithSpace->AddPersonToHouse(James1.PUID());
    return true;
};

bool Manager::CreateHouse()
{
    if (GetResource("Wood")->Amounts() >= 10)
    {
        // Can create house
        GetResource("Wood")->UpdateAmount(-10);
        House newHouse = House();
        houses.push_back(newHouse);
    }
    else
    {
        // Not enough wood
    }
};

bool Manager::CreateMeal()
{
    if (GetResource("Crops")->Amounts() >= 10)
    {
        // Can create meal
        GetResource("Crops")->UpdateAmount(-10);
        //Meals newMeal = Meals();
        //meals.push_back(newMeal);
    }
    else
    {
        // Not enough wood
    }
};

bool Manager::CreateTool()
{
    if (GetResource("Stone")->Amounts() >= 10)
    {
        // Can create house
        GetResource("Stone")->UpdateAmount(-10);
        //Tools newTool = Tools();
        //tools.push_back(newTool);
    }
    else
    {
        // Not enough wood
    }
};

House *Manager::FindHouseWithSpace(){
    std::list<House>::iterator house = houses.begin();
    for (int index = 0; index < houses.size(); index++)
    {
        if (house->NumberOfPeopleInHouse() < 3 )
        {
            return &*house;
        }
        ++house;
    }
    return 0;
};