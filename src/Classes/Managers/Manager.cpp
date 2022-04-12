#include <iostream>
#include "../../../include/Manager.h"
#include <random>

const int HouseWoodCost = 100;
const int MealCropsCost = 25;
const int ToolStoneCost = 15;

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
    std::cout << "#######################################################################" << std::endl;
    std::cout << "#                       Settlement Information                        #" << std::endl;
    std::cout << "#######################################################################" << std::endl;
    std::cout << "#" << std::endl;
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

    std::cout << "# People: [" << personManager.unemployedCount() + personManager.minerCount() + personManager.farmerCount() + personManager.loggerCount() << "/" << peoplePerHouse << "]   "
              << loggerSize << " Logger - " << minerSize << " Miner - " << farmerSize << " Farmer - " << unemployedSize << " Unemployed" << std::endl;
    std::cout << "# Usable:         " << housesSize << " Houses - " << mealsSize << " Meals - " << toolsSize << " Tools" << std::endl;
    std::cout << "# Resources:      " << wood->Amounts() << " Wood - " << stone->Amounts() << " Stone - " << crops->Amounts() << " Crops" << std::endl;
    std::cout << "#" << std::endl;
    std::cout << "#######################################################################" << std::endl;
    std::cout << "\n\n";
    if (personManager.unemployedCount()>0){
        std::cout << "               You have " << personManager.unemployedCount() << " unemployed people!" << std::endl;
        std::cout << "- You should try and [G]ive all your people jobs so they can gather resources.\n" << std::endl;
        personManager.ListPeopleInRole(jobRole::None);
        std::cout << "\n\n";
    }
};

bool Manager::DisplayChoices(){
    char option = '#';
    std::cout << "#######################################################################" << std::endl;
    std::cout << "What would you like to do?\n";
    std::cout << "[ V ] - View Things\n";
    std::cout << "[ C ] - Create Things\n";
    std::cout << "[ G ] - Give Things\n";
    std::cout << "[ F ] - Fix Houses\n";
    std::cout << "[ Enter ] - Advance A Day" << std::endl;

    std::cout << "Option: ";
    option = std::toupper(getchar());
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
    case 'G':
    {
        GiveOptions();
        return false;
        break;
    }
    case 'F':
    {
        FixHouse();
        return false;
        break;
    }
    case '\n':
    {
        AdvanceDay();
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
    std::cout << "#######################################################################" << std::endl;
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "[ P ] - View People" << std::endl;
    std::cout << "[ H ] - View Houses" << std::endl;
    std::cout << "[ M ] - View Meals" << std::endl;
    std::cout << "[ T ] - View Tools" << std::endl;

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
void Manager::CreateOptions()
{
    std::cout << "#######################################################################" << std::endl;
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "[ P ] - Add People" << std::endl;
    std::cout << "[ H ] - Add Houses" << std::endl;
    std::cout << "[ M ] - Add Meals" << std::endl;
    std::cout << "[ T ] - Add Tools" << std::endl;

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
 * @brief Allows the user to choose to give a persona job or tools
 * 
 */
void Manager::GiveOptions()
{
    std::cout << "#######################################################################" << std::endl;
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "[ T ] - Give People Tools" << std::endl;
    std::cout << "[ J ] - Give People Jobs" << std::endl;
    std::cout << "[ H ] - Give People Houses" << std::endl;

    std::cout << "Option: ";
    char option = std::toupper(getchar());
    std::cin.ignore();

    switch (option)
    {
    case 'T':
    {
        GivePersonTool();
        break;
    }
    case 'J':
    {
        GivePersonJob();
        break;
    }
    case 'H':
    {
        GivePersonHouse();
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
void Manager::ListPersonOptions()
{
    std::cout << "#######################################################################" << std::endl;
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "[ P ] - View Person Using ID" << std::endl;
    std::cout << "[ J ] - View People With Specific Role" << std::endl;

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
    std::cout << "Please enter a Job Role number [Miner] [Farmer] [Logger] [None] [All]: ";
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
        case 'N':
        {
            personManager.ListPeopleInRole(jobRole::None);
            break;
        }
        case 'A':
        {
            personManager.ListPeopleInRole(jobRole::Miner);
            personManager.ListPeopleInRole(jobRole::Farmer);
            personManager.ListPeopleInRole(jobRole::Logger);
            personManager.ListPeopleInRole(jobRole::None);
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
    std::mt19937 gen(time(0));
    std::uniform_int_distribution<> distr(20, 60);
    int age = distr(gen);
    House *homeWithSpace = FindHouseWithSpace();
    if (homeWithSpace == 0){
        std::cout << "There doesn't seem to be space for new people,\nTry building new houses." << std::endl;
        return false;
    }
    std::string newname;
    std::cout << "Please Enter a Name for a new person: ";
    std::cin >> newname;

    People newPerson = People(newname, age, jobRole::None);
    //newPerson.home = homeWithSpace;
    //newPerson.PHoused(true);
    personManager.AddPerson(newPerson);
    //homeWithSpace->AddPersonToHouse(newPerson.PUID());
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
    People* person = personManager.FindPerson(uid);
    if (person->PUID() == -1)
    {
        std::cout << "Person not found!" << std::endl;
        return;
    }
    std::cout << "\nYou selected ";
    personManager.ListPersonInfo(uid);
    std::cout << "What role do you want to give to them? [Miner] [Farmer] [Logger]\nRole: ";
    char option = std::toupper(getchar());
    std::cin.ignore();
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

/**
 * @brief Allows the user to give a person a tool
 * 
 */
void Manager::GivePersonTool(){
    // Find free tool
    bool toolAvailable = false;
    std::list<Tools>::iterator tool = tools.begin();
    for (int toolIndex = 0; toolIndex < tools.size(); toolIndex++)
    {
        if (!tool->Available())
        {
            ++tool;
        }
        else
        {
            toolAvailable = true;
            toolIndex = tools.size();
        }
    }

    if (!toolAvailable){
        std::cout << "No free tools available!" << std::endl;
    }
    else{
        std::cout << "To give a person a tool, please enter a person ID" << std::endl;
        std::cout << "ID: ";
        int uid = GetInt();
        People* person = personManager.FindPerson(uid);
        if (person->PUID() == -1)
        {
            std::cout << "Person not found!" << std::endl;
            return;
        }
        std::cout << "\nYou selected ";
        personManager.ListPersonInfo(uid);
        if (person->PRole() != jobRole::None)
        {
            personManager.GivePersonTool(person->PUID(), person->PRole(), &*tool);
            std::cout << "Person ID: " << person->PUID() << " " << person->PName() << " now has tool!" << std::endl;
        }
    }
};

void Manager::GivePersonHouse(){
    std::cout << "To give a person a job, please enter a person ID" << std::endl;
    std::cout << "ID: ";
    int uid = GetInt();
    People* person = personManager.FindPerson(uid);
    if (person->PUID() == -1)
    {
        std::cout << "Person not found!" << std::endl;
        return;
    }
    std::cout << "\nYou selected ";
    personManager.ListPersonInfo(uid);
    if (person->PHoused()){
        std::cout << "This person has a home!" << std::endl;
        return;
    }

    House *homeWithSpace = FindHouseWithSpace();
    if (homeWithSpace == 0)
    {
        std::cout << "There doesn't seem to be space for new people,\nTry building new houses." << std::endl;
        return;
    }
    person->home = homeWithSpace;
    person->PHoused(true);
    homeWithSpace->AddPersonToHouse(person->PUID());
};

/**
 * @brief Allows the user to fix up a house using wood
 * 
 */
void Manager::FixHouse(){
    std::cout << "To fix up a house please enter a house ID" << std::endl;
    std::cout << "ID: ";
    int uid = GetInt();

    bool foundHouse = false;
    std::list<House>::iterator house = houses.begin();
    for (int index = 0; index < houses.size(); index++)
    {
        if (house->GetID() != uid)
        {
            ++house;
        }
        else{
            foundHouse = true;
            index = houses.size();
        }
    }

    if (foundHouse){
        std::cout << "This house has " << house->Durabilities() << "% durability." << std::endl;
        std::cout << "To fix the house please enter an amount of wood to use.\n1 Wood = 10%\nWood To Use:";
        int woodToUse = GetInt();
        if (GetResource("Wood")->Amounts()>woodToUse){
            int maxFix = 100 - house->Durabilities();
            int woodCanBeUsed = (maxFix / 10) + 1;
            if (woodToUse>0 && woodToUse<=woodCanBeUsed){
                house->Fix(woodToUse * 10);    
            }
            GetResource("Wood")->UpdateAmount(-woodToUse);
        }
        else{
            std::cout << "Not enough wood" << std::endl;
        }
    }
    else{
        std::cout << "No house with that ID found!" << std::endl;
    }
};

void Manager::AdvanceDay(){
    std::cout << "A day has passed" << std::endl;
    UpdatePeople();
    UpdateTools();
    UpdateMeals();
    UpdateHouses();
};

void Manager::UpdatePeople()
{
    personManager.FeedPeople(&meals);
    std::cout << "People Fed!" << std::endl;
    int resourcesWSC[3];
   
    personManager.MakeResources(resourcesWSC);
    GetResource("Wood")->UpdateAmount(resourcesWSC[0]);
    GetResource("Stone")->UpdateAmount(resourcesWSC[1]);
    GetResource("Crops")->UpdateAmount(resourcesWSC[2]);
    std::cout << "Resources Gained!" << std::endl;
}

void Manager::UpdateHouses()
{
    std::list<House>::iterator house = houses.begin();
    for (int index = 0; index < houses.size(); index++)
    {
        if (house->Durabilities()>0){
            house->UpdateDurability(-4);
        }
        if (house->Durabilities() <=0){
            // Unhouse people
            int peopleToUnhouse[3];
            house->UnhousePeople(peopleToUnhouse);
            personManager.UnhousePerson(peopleToUnhouse[0]);
            personManager.UnhousePerson(peopleToUnhouse[1]);
            personManager.UnhousePerson(peopleToUnhouse[2]);
            house->Break();
        }
        ++house;
    }
}

void Manager::UpdateMeals()
{
    std::list<Meals>::iterator meal = meals.begin();
    for (int index = 0; index < meals.size(); index++)
    {
        meal->UpdateDurability(-3);
        if(meal->Durabilities()<=0){
            meal = meals.erase(meal);
            --meal;
        }
        ++meal; // Might not need this if something hist 0 durability
    }
}

void Manager::UpdateTools()
{
    std::list<Tools>::iterator tool = tools.begin();
    for (int index = 0; index < tools.size(); index++)
    {
        if(!tool->Available()){
            tool->UpdateDurability(-5);
        }
        if(tool->Durabilities() <=0){
            Workers* person = personManager.FindWorker(tool->GetOwner());
            person->RemoveTool();
            tool->Break();
            tool = tools.erase(tool);
            --tool;
        }
        ++tool;
    }
};

int Manager::HouseCount(){
    int housesFixed = 0;

    std::list<House>::iterator house = houses.begin();
    for (int index = 0; index < houses.size(); index++)
    {
        if (house->Durabilities() > 0)
        {
            housesFixed++;
        }
        ++house;
    }
    return housesFixed;
}


void Manager::DisplayInfo(){
    Resource *wood = GetResource("Wood");
    Resource *crops = GetResource("Crops");
    Resource *stone = GetResource("Stone");

    if (wood->Amounts() >= 10 || crops->Amounts() >= 10 || stone->Amounts() >= 10){
        std::cout << "You are able to [C]reate: ";
        if (wood->Amounts() >= 10)
        {
            std::cout << wood->Amounts() / 10 << " houses   ";
        }
        if (crops->Amounts() >= 10)
        {
            std::cout << crops->Amounts() / 10 << " meals   ";
        }
        if (stone->Amounts() >= 10)
        {
            std::cout << stone->Amounts() / 10 << " tools" << std::endl;
        }
        std::cout << "\n";
    }

        
};