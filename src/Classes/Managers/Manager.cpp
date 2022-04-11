#include <iostream>
#include "../../../include/Manager.h"

const int HouseWoodCost = 10;
const int MealCropsCost = 10;
const int ToolStoneCost = 10;

Manager::Manager(){};

/**
 * @brief Adds a new Resource to the list.
 * 
 * @param resource The new Resource we want to add.
 */
void Manager::AddResource(Resource resource){
    resources.push_back(resource);
};

/**
 * @brief Used to get a int from the console
 * 
 * @return int Returns an int entered by the user
 */
int Manager::GetInt()
{
    while (true)
    {
        int input = -1;
        std::string consoleInput;

        try
        {
            while (input < 0)
            {
                std::cin >> consoleInput;
                std::cin.ignore();
                input = std::stoi(consoleInput);
            }
            return input;
        }
        catch (...)
        {
            std::cout << "\n Thats not a number!" << std::endl;
            std::cout << "Try again: ";
        }
    }
}

/**
 * @brief Used to get a pointer to a resource type.
 * 
 * @param resourceType The name of the resource we want to get
 * @return Resource* A pointer to the resource
 */
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

/**
 * @brief Displays the current data for houses, people and resources
 * 
 */
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

bool Manager::DisplayChoices(){

    std::cout << "What would you like to do?" << std::endl;
    std::cout << "[V] - View Things" << std::endl;
    std::cout << "[C] - Create Things" << std::endl;
    std::cout << "[A] - Advance A Day" << std::endl;

    std::cout << "Option: ";
    char option = std::toupper(getchar());
    std::cin.ignore();

    switch (option)
    {
    case 'V':
    {
        DisplayOptions();
        return false;
        break;
    }
    case 'C':
    {
        CreateOptions();
        return false;
        break;
    }
    case 'A':
    {
        // AdvanceDay();
        return true;
        break;
    }
    default:{
        return false;
        break;
        }
    }
};

/**
 * @brief Displays the options the user has and allows them to make choices.
 *
 */
void Manager::DisplayOptions()
{
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "[P] - View People" << std::endl;
    std::cout << "[H] - View Houses" << std::endl;
    std::cout << "[M] - View Meals" << std::endl;
    std::cout << "[T] - View Tools" << std::endl;

    std::cout << "Option: ";
    char option = std::toupper(getchar());
    std::cin.ignore();

    switch (option)
    {
    case 'P':
    {
        ListPersonOptions();
        break;
    }
    case 'H':
    {
        ListHouses();
        break;
    }
    case 'M':
    {
        ListMeals();
        break;
    }
    case 'T':
    {
        ListTools();
        break;
    }

    default:
        break;
    }
};

/**
 * @brief Allows the user to select an option to create something
 * 
 */
void Manager::CreateOptions(){
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "[P] - Add People" << std::endl;
    std::cout << "[H] - Add Houses" << std::endl;
    std::cout << "[M] - Add Meals" << std::endl;
    std::cout << "[T] - Add Tools" << std::endl;

    std::cout << "Option: ";
    char option = std::toupper(getchar());
    std::cin.ignore();

    switch (option)
    {
    case 'P':
    {
        CreatePerson();
        break;
    }
    case 'H':
    {
        CreateHouse();
        break;
    }
    case 'M':
    {
        CreateMeal();
        break;
    }
    case 'T':
    {
        CreateTool();
        break;
    }

    default:
        break;
    }
};

/**
 * @brief Options for displaying people.
 * 
 */
void Manager::ListPersonOptions(){
    system("cls");
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "[P] - View Person Using ID" << std::endl;
    std::cout << "[J] - View People With Specific Role" << std::endl;

    std::cout << "Option: ";
    char option = std::toupper(getchar());
    std::cin.ignore();

    switch (option)
    {
        case 'P':
        {
            ListPersonByID();
            break;
        }
        case 'J':
        {
            ListPeopleByRole();
            break;
        }
        default:
        {
            break;
        }
    }
};

/**
 * @brief Function used to display a person by their ID
 * 
 */
void Manager::ListPersonByID()
{
    system("cls");
    std::cout << "Please enter a ID number: ";
    int UID = GetInt();
    system("cls");
    personManager.ListPersonInfo(UID);
};

/**
 * @brief Option function for displaying a list of people based on roles
 * 
 */
void Manager::ListPeopleByRole()
{
    system("cls");
    std::cout << "Please enter a Job Role number [Miner] [Farmer] [Logger]: ";
    char option = std::toupper(getchar());
    std::cin.ignore();
    system("cls");
    switch (option)
    {
        case 'M':
        {
            personManager.ListPeopleInRole(jobRole::Miner);
            break;
        }
        case 'F':
        {
            personManager.ListPeopleInRole(jobRole::Farmer);
            break;
        }
        case 'L':
        {
            personManager.ListPeopleInRole(jobRole::Logger);
            break;
        }
        default:
            break;
    }
};

/**
 * @brief Lists out all the houses we have and their data
 * 
 */
void Manager::ListHouses(){
    std::list<House>::iterator house = houses.begin();
    for (int index = 0; index < houses.size(); index++)
    {
        std::cout << "ID: [" << house->GetID() << "] - " << house->UsefulObjectName() << " housing " << house->NumberOfPeopleInHouse() << " of " << peoplePerHouse << " people." << std::endl;
        std::cout << "Durability: " << house->Durabilities() << std::endl;
        ++house;
    }
};

/**
 * @brief Lists out all our meals with their freshness
 * 
 */
void Manager::ListMeals(){
    if (meals.size() == 0){
        std::cout << "You don't have any meals.\nTry making some more using crops!" << std::endl;
        return;
    }
    std::list<Meals>::iterator meal = meals.begin();
    for (int index = 0; index < meals.size(); index++)
    {
        std::cout << meal->UsefulObjectName() << " freshness: " << meal->Durabilities() << "%" << std::endl;
        ++meal;
    }
};

/**
 * @brief Lists all the tools and their data
 * 
 */
void Manager::ListTools(){
    if (tools.size() == 0)
    {
        std::cout << "You don't have any tools.\nTry making some more using stone!" << std::endl;
        return;
    }
    std::list<Tools>::iterator tool = tools.begin();
    for (int index = 0; index < tools.size(); index++)
    {
        std::cout << tool->UsefulObjectName() << " durability: " << tool->Durabilities() << "%" << std::endl;
        ++tool;
    }
};

/**
 * @brief Creates a person if there is space in a house
 *
 * @return true if person was created
 * @return false if person cant be created
 */
bool Manager::CreatePerson()
{
    House *homeWithSpace = FindHouseWithSpace();
    if (homeWithSpace == 0){
        std::cout << "There doesn't seem to be space for new people,\nTry building new houses." << std::endl;
        return false;
    }
    People James1 = People("James", 32, jobRole::None);
    personManager.AddPerson(James1);
    homeWithSpace->AddPersonToHouse(James1.PUID());
    return true;
};

/**
 * @brief Creates a new house if we have enough wood
 * 
 * @return true if we had enough wood and created a new house
 * @return false if there wasn't enough wood for a new house
 */
bool Manager::CreateHouse()
{
    if (GetResource("Wood")->Amounts() >= HouseWoodCost)
    {
        // Can create house
        GetResource("Wood")->UpdateAmount(-HouseWoodCost);
        House newHouse = House();
        newHouse.SetID(houseUID);
        newHouse.UsefulObjectName("Small house");
        newHouse.UpdateDurability(100);
        houseUID++;
        houses.push_back(newHouse);
        return true;
    }
    else
    {
        std::cout << "You don't have enough wood for a new house.\nMaybe make some more Loggers to collect wood?" << std::endl;
    }
    return false;
};

/**
 * @brief Creates a new meal if we have enough crops
 * 
 * @return true if we had enough crops for a new meal
 * @return false if we didn't have enough crops for a meal
 */
bool Manager::CreateMeal()
{
    if (GetResource("Crops")->Amounts() >= MealCropsCost)
    {
        // Can create meal
        GetResource("Crops")->UpdateAmount(-MealCropsCost);
        Meals newMeal = Meals();
        newMeal.UsefulObjectName("Small Meal");
        newMeal.UpdateDurability(100);
        meals.push_back(newMeal);
        return true;
    }
    else
    {
        std::cout << "You don't have enough crops for a new meal.\nMaybe make some more Farmers to collect crops?" << std::endl;
    }
    return false;
};

/**
 * @brief Creates a new tool if we have enough stone
 * 
 * @return true if we had enough stone to make a tool
 * @return false if we didn't have enough stone for a tool
 */
bool Manager::CreateTool()
{
    if (GetResource("Stone")->Amounts() >= ToolStoneCost)
    {
        // Can create tool
        GetResource("Stone")->UpdateAmount(-ToolStoneCost);
        Tools newTool = Tools();
        newTool.UsefulObjectName("Small Tool");
        newTool.UpdateDurability(100);
        tools.push_back(newTool);
        return true;
    }
    else
    {
        std::cout << "You don't have enough stone for a new tool.\nMaybe make some more Miners to collect stone?" << std::endl;
    }
    return false;
};

void Manager::UpdatePeople()
{
}

void Manager::UpdateHouses()
{
}

void Manager::UpdateMeals()
{
}

void Manager::UpdateTools()
{
}

/**
 * @brief Finds and returns a house that has space for a person to move into
 * 
 * @return House* pointer to a house that has space for a person
 */
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

/**
 * @brief Looks through the list of Meals we have and
 * then consumes the one with the least durability
 */
void Manager::ConsumeMeal()
{
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
    for (int mealIndex = 0; mealIndex < index; mealIndex++)
    {
        ++meal;
    }

    // Remove that meal
    meals.erase(meal);
};

/**
 * @brief Allows the user to select a person to give them a role
 * 
 */
void Manager::GivePersonJob(){
    std::cout << "To give a person a job, please enter a person ID" << std::endl;
    std::cout << "ID: ";
    int uid = GetInt();
    People person = personManager.FindPerson(uid);
    if (person.PUID() == -1){
        std::cout << "Person not found!" << std::endl;
        return;
    }
    std::cout << "\nYou selected ";
    personManager.ListPersonInfo(uid);
    std::cout << "What role do you want to give to them? [Miner] [Farmer] [Logger]\nRole: ";
    char option = std::toupper(getchar());
    std::cin.ignore();
    system("cls");
    switch (option)
    {
    case 'M':
    {
        personManager.GivePersonJob(uid, jobRole::Miner);
        break;
    }
    case 'F':
    {
        personManager.GivePersonJob(uid, jobRole::Farmer);
        break;
    }
    case 'L':
    {
        personManager.GivePersonJob(uid, jobRole::Logger);
        break;
    }
    default:
        break;
    }
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