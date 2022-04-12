#include "../../../include/PersonManager.h"

#include <string>

PersonManager::PersonManager(){};

int PersonManager::unemployedCount() { return unemployedPeople.size(); };
int PersonManager::farmerCount() { return farmerPeople.size(); };
int PersonManager::loggerCount() { return loggerPeople.size(); };
int PersonManager::minerCount() { return minerPeople.size(); };

/**
 * @brief Adds a new person to the corrent list based on their role
 * 
 * @param person The person we want o add
 */
void PersonManager::AddPerson(People &person){

    if (person.PUID() == -1)
    {
        person.PUID(peopleUID);
        peopleUID += 1;
    }

    switch (person.PRole())
    {
        case jobRole::None:
        {        unemployedPeople.push_back(Unemployed(person));    break;    }
        case jobRole::Farmer:
        {        farmerPeople.push_back(Farmers(person));           break;    }
        case jobRole::Miner:
        {        minerPeople.push_back(Miners(person));             break;    }
        case jobRole::Logger:
        {        loggerPeople.push_back(Loggers(person));           break;    }
        default:
        {break;}
    }
};

/**
 * @brief Removes a person from a list based on their role and id
 * 
 * @param role the role the person has
 * @param uid the ID of the person
 */
void PersonManager::RemovePerson(jobRole role, int uid){
    switch (role)
    {
        case jobRole::None:
        {
            for (std::list<Unemployed>::iterator person = unemployedPeople.begin(); person != unemployedPeople.end(); person++)
            {
                if (person->PUID() == uid)
                { unemployedPeople.erase(person); return; }
            }
            break;
        }
        case jobRole::Farmer:
        {
            for (std::list<Farmers>::iterator person = farmerPeople.begin(); person != farmerPeople.end(); person++)
            {
                if (person->PUID() == uid)
                {
                    farmerPeople.erase(person);
                    return;
                }
            }
            break;
        }
        case jobRole::Miner:
        {
            for (std::list<Miners>::iterator person = minerPeople.begin(); person != minerPeople.end(); person++)
            {
                if (person->PUID() == uid)
                {
                    minerPeople.erase(person);
                    return;
                }
            }
            break;
        }
        case jobRole::Logger:
        {
            for (std::list<Loggers>::iterator person = loggerPeople.begin(); person != loggerPeople.end(); person++)
            {
                if (person->PUID() == uid)
                {
                    loggerPeople.erase(person);
                    return;
                }
            }
            break;
        }
    }
};

/**
 * @brief Finds a person within all the lists, based on its uid
 * 
 * @param uid the UID of the person
 * @return People* The pointer to the person
 */
People* PersonManager::FindPerson(int uid){
    for (std::list<Unemployed>::iterator person = unemployedPeople.begin(); person != unemployedPeople.end(); person++)
    {
        if (person->PUID() == uid) { return &*person; }
    }
    for (std::list<Farmers>::iterator person = farmerPeople.begin(); person != farmerPeople.end(); person++)
    {
        if (person->PUID() == uid) { return &*person; }
    }
    for (std::list<Miners>::iterator person = minerPeople.begin(); person != minerPeople.end(); person++)
    {
        if (person->PUID() == uid) { return &*person; }
    }
    for (std::list<Loggers>::iterator person = loggerPeople.begin(); person != loggerPeople.end(); person++)
    {
        if (person->PUID() == uid) { return &*person; }
    }

    People tempPerson = People();
    People *personsDetails = &tempPerson;
    return personsDetails;
};

/**
 * @brief Finds a worker from the lists
 * 
 * @param uid The uid of the worker
 * @return Workers* the worker in the lists
 */
Workers* PersonManager::FindWorker(int uid)
{
    for (std::list<Farmers>::iterator person = farmerPeople.begin(); person != farmerPeople.end(); person++)
    {
        if (person->PUID() == uid) { return &*person; }
    }
    for (std::list<Miners>::iterator person = minerPeople.begin(); person != minerPeople.end(); person++)
    {
        if (person->PUID() == uid) { return &*person; }
    }
    for (std::list<Loggers>::iterator person = loggerPeople.begin(); person != loggerPeople.end(); person++)
    {
        if (person->PUID() == uid) { return &*person; }
    }

    Workers tempPerson = Workers();
    Workers *personsDetails = &tempPerson;
    return personsDetails;
};

/**
 * @brief Gives a person a specific job role and then adds them to the right list
 * 
 * @param uid 
 * @param role 
 */
void PersonManager::GivePersonJob(int uid, jobRole role){
    // Find Person
    People* personsDetails = FindPerson(uid);
    if (personsDetails->PUID() == -1){
        std::cout << "Unable to give person role, person with ID doesn't exist" << std::endl;
        return;
    }
    // Remove old person
    RemovePerson(personsDetails->PRole(), personsDetails->PUID());
    // Add person with new role
    personsDetails->PRole(role);
    AddPerson(*personsDetails);
};

void PersonManager::GivePersonTool(int uid, jobRole role, Tools *tool){
    Workers *worker = FindWorker(uid);
    if(!worker->HasTool() && worker->PUID() !=-1){
        worker->GiveTool(tool);
        tool->Available(false);
        tool->SetOwner(worker);
    }
    else{
        std::cout << "This person has a tool" << std::endl;
    }
};

/**
 * @brief Lists out all the info about a person
 *
 * @param uid the UID of the person we want to look up;
 */
void PersonManager::ListPersonInfo(int uid){
    // Find Person
    People* personsDetails = FindPerson(uid);
    ListPersonInfo(personsDetails);
};

/**
 * @brief Lists the info on a person based on the person pointer
 * 
 * @param personsDetails A pointer to the person we are working with
 */
void PersonManager::ListPersonInfo(People *personsDetails){

    std::cout << "[ID:" << personsDetails->PUID() << "] - ";
    if (personsDetails->PHoused())   {std::cout << "Housed ";}
    else                            {std::cout << "Homeless ";}
    switch (personsDetails->PRole())
    {
        case jobRole::None:     { std::cout << "Unemployed "; break;}
        case jobRole::Farmer:   { std::cout << "Farmer "; break; }
        case jobRole::Logger:   { std::cout << "Logger "; break; }
        case jobRole::Miner:    { std::cout << "Miner "; break; }
        default:
            break;
    }

    std::cout << personsDetails->PName();
    std::cout << "\nAge:    " << personsDetails->PAge() << "    -    " << "Hunger: " << personsDetails->PHunger()<< "%" << std::endl;
    if (personsDetails->PRole() != jobRole::None)
    {
        Workers *personWorker = FindWorker(personsDetails->PUID());
        if (personWorker->HasTool())
        {std::cout << "Has Tool" << std::endl;}
    }
};

/**
 * @brief Lists all the people in a set role
 * 
 * @param role The role of the people we are wanting to use
 */
void PersonManager::ListPeopleInRole(jobRole role){
    switch (role)
    {
    case jobRole::None:
    {
        for (std::list<Unemployed>::iterator person = unemployedPeople.begin(); person != unemployedPeople.end(); person++)
        {ListPersonInfo(person->PUID());}
        break;
    }
    case jobRole::Miner:
    {
        for (std::list<Miners>::iterator person = minerPeople.begin(); person != minerPeople.end(); person++)
        {ListPersonInfo(person->PUID());}
        break;
    }
    case jobRole::Farmer:
    {
        for (std::list<Farmers>::iterator person = farmerPeople.begin(); person != farmerPeople.end(); person++)
        {ListPersonInfo(person->PUID());}
        break;
    }
    case jobRole::Logger:
    {
        for (std::list<Loggers>::iterator person = loggerPeople.begin(); person != loggerPeople.end(); person++)
        {ListPersonInfo(person->PUID());}
        break;
    }
    default:
        break;
    }
};

void PersonManager::FeedPeople(std::list<Meals>* meals)
{
    std::list<Farmers>::iterator farmer = farmerPeople.begin();
    for (int index = 0; index < farmerPeople.size(); index++)
    {
        farmer->PHunger(farmer->PHunger() + hungerSpeed);
        if (farmer->PHunger() >= 100)
        {
            if (meals->size() > 0)
            {
                std::cout << "Feeding farmer " << farmer->PUID() << std::endl;
                meals->pop_front();
                farmer->PEat();
            }
            else
            {
                std::cout << "Can't feed farmer " << farmer->PUID() << std::endl;
                if (farmer->Starve())
                {
                    farmer = farmerPeople.erase(farmer);
                    --farmer;
                }
            }
        }
        ++farmer;
    }

    std::list<Miners>::iterator miner = minerPeople.begin();
    for (int index = 0; index < minerPeople.size(); index++)
    {
        miner->PHunger(miner->PHunger() + hungerSpeed);
        if (miner->PHunger() >=100)
        {
            if (meals->size() > 0)
            {
                std::cout << "Feeding miner " << miner->PUID() << std::endl;
                meals->pop_front();
                miner->PEat();
            }
            else
            {
                std::cout << "Can't feed miner " << miner->PUID() << std::endl;

                if (miner->Starve())
                {
                    miner = minerPeople.erase(miner);
                    --miner;
                }
            }
        }
        ++miner;
    }

    std::list<Loggers>::iterator logger = loggerPeople.begin();
    for (int index = 0; index < loggerPeople.size(); index++)
    {
        logger->PHunger(logger->PHunger() + hungerSpeed);
        if (logger->PHunger() >=100)
        {
            if (meals->size() > 0)
            {
                std::cout << "Feeding logger " << logger->PUID() << std::endl;
                meals->pop_front();
                logger->PEat();
            }
            else
            {
                std::cout << "Can't feed logger " << logger->PUID() << std::endl;

                if (logger->Starve())
                {
                    logger = loggerPeople.erase(logger);
                    --logger;
                }
            }
        }
        ++logger;
    }

    std::list<Unemployed>::iterator person = unemployedPeople.begin();
    for (int index = 0; index < unemployedPeople.size(); index++)
    {
        person->PHunger(person->PHunger() + hungerSpeed);
        if (person->PHunger() >=100)
        {
            if (meals->size() > 0)
            {
                std::cout << "Feeding person " << person->PUID() << std::endl;
                meals->pop_front();
                person->PEat();
            }
            else
            {
                std::cout << "Can't feed person " << person->PUID() << std::endl;
            }
        }
        ++person;
    }
};

int* PersonManager::MakeResources(int resources[3]){
    resources[0] = 0;
    resources[1] = 0;
    resources[2] = 0;

    std::list<Farmers>::iterator farmer = farmerPeople.begin();
    for (int index = 0; index < farmerPeople.size(); index++)
    {
        if (farmer->PHoused() && farmer->PHunger() <100)
        {
            resources[2]++;
            if(farmer->HasTool()){
                resources[2]++;
            }
        }
        ++farmer;
    }

    std::list<Miners>::iterator miner = minerPeople.begin();
    for (int index = 0; index < minerPeople.size(); index++)
    {
        if (miner->PHoused() && miner->PHunger() < 100)
        {
            resources[1]++;
            if (miner->HasTool())
            {
                resources[1]++;
            }
        }
        ++miner;
    }

    std::list<Loggers>::iterator logger = loggerPeople.begin();
    for (int index = 0; index < loggerPeople.size(); index++)
    {
        if (logger->PHoused() && logger->PHunger() < 100)
        {
            resources[0]++;
            if (logger->HasTool())
            {
                resources[0]++;
            }
        }
        ++logger;
    }
    return resources;
};

void PersonManager::UnhousePerson(int uid){
    People* person = FindPerson(uid);
    person->PHoused(false);
};

int PersonManager::PeopleCount()
{
    return (unemployedCount() + farmerCount() + loggerCount() + minerCount());
};