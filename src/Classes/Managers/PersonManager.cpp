#include "../../../include/PersonManager.h"

#include <string>

PersonManager::PersonManager(){};

void PersonManager::AddPerson(People &person){

    if (person.PUID() == -1)
    {
        person.PUID(peopleUID);
        peopleUID += 1;
    }

    switch (person.PRole())
    {
    case jobRole::None:
    {
        Unemployed Person = Unemployed(person);
        unemployedPeople.push_back(Person);
        break;
    }
    case jobRole::Farmer:
    {
        Farmers Person = Farmers(person);
        farmerPeople.push_back(Person);
        break;
    }
    case jobRole::Miner:
    {
        Miners Person = Miners(person);
        minerPeople.push_back(Person);
        break;
    }
    case jobRole::Logger:
    {
        Loggers Person = Loggers(person);
        loggerPeople.push_back(Person);
        break;
    }
    default:
        break;
    }
};

void PersonManager::RemovePerson(jobRole role, int uid){
    switch (role)
    {
        case jobRole::None:
        {
            std::list<Unemployed>::iterator person = unemployedPeople.begin();
            for (int index = 0; index < unemployedPeople.size();index++){
                if (person->PUID() == uid){
                    unemployedPeople.erase(person);
                    return;
                }
                ++person;
            }
            break;
        }
    case jobRole::Farmer:
    {
        std::list<Farmers>::iterator person = farmerPeople.begin();
        for (int index = 0; index < farmerPeople.size(); index++)
        {
            if (person->PUID() == uid)
            {
                farmerPeople.erase(person);
                return;
            }
            ++person;
        }
        break;
    }
    case jobRole::Miner:
    {
        std::list<Miners>::iterator person = minerPeople.begin();
        for (int index = 0; index < minerPeople.size(); index++)
        {
            if (person->PUID() == uid)
            {
                minerPeople.erase(person);
                return;
            }
            ++person;
        }
        break;
    }
    case jobRole::Logger:
    {
        std::list<Loggers>::iterator person = loggerPeople.begin();
        for (int index = 0; index < loggerPeople.size(); index++)
        {
            if (person->PUID() == uid)
            {
                loggerPeople.erase(person);
                return;
            }
            ++person;
        }
        break;
    }
    }
};

int PersonManager::unemployedCount()    { return unemployedPeople.size(); };
int PersonManager::farmerCount()        { return farmerPeople.size(); };
int PersonManager::loggerCount()        { return loggerPeople.size(); };
int PersonManager::minerCount()         { return minerPeople.size(); };

People* PersonManager::FindPerson(int uid){
    People tempPerson = People();
    People *personsDetails = &tempPerson;

    std::list<Unemployed>::iterator person = unemployedPeople.begin();
    for (int index = 0; index < unemployedPeople.size(); index++)
    {
        if (person->PUID() == uid)
        {
            personsDetails = &*person;
            return personsDetails;
        }
        ++person;
    }

    std::list<Farmers>::iterator farmer = farmerPeople.begin();
    for (int index = 0; index < farmerPeople.size(); index++)
    {
        if (farmer->PUID() == uid)
        {
            personsDetails = &*farmer;
            return personsDetails;
        }
        ++farmer;
    }

    std::list<Miners>::iterator miner = minerPeople.begin();
    for (int index = 0; index < minerPeople.size(); index++)
    {
        if (miner->PUID() == uid)
        {
            personsDetails = &*miner;
            return personsDetails;
        }
        ++miner;
    }

    std::list<Loggers>::iterator logger = loggerPeople.begin();
    for (int index = 0; index < loggerPeople.size(); index++)
    {
        if (logger->PUID() == uid)
        {
            personsDetails = &*logger;
            return personsDetails;
        }
        ++logger;
    }
    return personsDetails;
};

Workers* PersonManager::FindWorker(int uid)
{
    Workers tempPerson = Workers();
    Workers *personsDetails = &tempPerson;

    std::list<Farmers>::iterator farmer = farmerPeople.begin();
    for (int index = 0; index < farmerPeople.size(); index++)
    {
        if (farmer->PUID() == uid)
        {
            personsDetails = &*farmer;
            return personsDetails;
        }
        ++farmer;
    }

    std::list<Miners>::iterator miner = minerPeople.begin();
    for (int index = 0; index < minerPeople.size(); index++)
    {
        if (miner->PUID() == uid)
        {
            personsDetails = &*miner;
            return personsDetails;
        }
        ++miner;
    }

    std::list<Loggers>::iterator logger = loggerPeople.begin();
    for (int index = 0; index < loggerPeople.size(); index++)
    {
        if (logger->PUID() == uid)
        {
            personsDetails = &*logger;
            return personsDetails;
        }
        ++logger;
    }
    return personsDetails;
};

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

    tool->Available(false);
    switch (role)
    {
    case jobRole::Miner:
    {
        std::list<Miners>::iterator person = minerPeople.begin();
        for (int index = 0; index < minerPeople.size(); index++)
        {
            if (person->PUID() == uid){
                if(person->HasTool()){
                    std::cout << "This person has a tool" << std::endl;
                }
                else{
                    // Give tool thats available
                    person->GiveTool(&*tool);
                    tool->SetOwner(&*person);
                    return;
                }
            }
            ++person;
        }
        break;
    }
    case jobRole::Farmer:
    {
        std::list<Farmers>::iterator person = farmerPeople.begin();
        for (int index = 0; index < farmerPeople.size(); index++)
        {
            if (person->PUID() == uid)
            {
                if (person->HasTool())                {
                    std::cout << "This person has a tool" << std::endl;
                    return;
                }
                else
                {
                    // Give tool thats available
                    person->GiveTool(&*tool);
                    tool->SetOwner(&*person);
                    return;
                }
            }
            ++person;
        }
        break;
    }
    case jobRole::Logger:
    {
        std::list<Loggers>::iterator person = loggerPeople.begin();
        for (int index = 0; index < loggerPeople.size(); index++)
        {
            if (person->PUID() == uid)
            {
                if (person->HasTool())                {
                    std::cout << "This person has a tool" << std::endl;
                    return;
                }
                else
                {
                    // Give tool thats available
                    person->GiveTool(&*tool);
                    tool->SetOwner(&*person);
                    return;
                }
            }
            ++person;
        }
        break;
    }
    default:
        break;
    }
};

void PersonManager::ListPersonInfo(int uid){
    // Find Person
    People* personsDetails = FindPerson(uid);

    if (personsDetails->PUID() != -1)
    {
        std::cout << "[ID:" << personsDetails->PUID() << "] - ";
        if (personsDetails->PHoused())
        {
            std::cout << "Housed ";
        }
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

        std::cout << personsDetails->PName() << std::endl;
        std::cout << "Age:    " << personsDetails->PAge() << std::endl;
        std::cout << "Hunger: " << personsDetails->PHunger() << "%" << std::endl;
    }
    else{
        std::cout << "Person with that ID does not exist!" << std::endl;
    }
};

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

    std::cout << personsDetails->PName() << "  -  ";
    std::cout << "Age:    " << personsDetails->PAge() << "    -    " << "Hunger: " << personsDetails->PHunger()<< "%" << std::endl;
};

void PersonManager::ListPeopleInRole(jobRole role){
    switch (role)
    {
    case jobRole::None:
    {
        std::list<Unemployed>::iterator person = unemployedPeople.begin();
        for (int index = 0; index < unemployedPeople.size(); index++)
        {
            People *personptr = &*person;
            ListPersonInfo(personptr);
            ++person;
        }
        break;
    }
    case jobRole::Miner:
    {
        std::list<Miners>::iterator person = minerPeople.begin();
        for (int index = 0; index < minerPeople.size(); index++)
        {
            People *personptr = &*person;
            ListPersonInfo(personptr);
            ++person;
        }
        break;
    }
    case jobRole::Farmer:
    {
        std::list<Farmers>::iterator person = farmerPeople.begin();
        for (int index = 0; index < farmerPeople.size(); index++)
        {
            People *personptr = &*person;
            ListPersonInfo(personptr);
            ++person;
        }
        break;
    }
    case jobRole::Logger:
    {
        std::list<Loggers>::iterator person = loggerPeople.begin();
        for (int index = 0; index < loggerPeople.size(); index++)
        {
            People *personptr = &*person;
            ListPersonInfo(personptr);
            ++person;
        }
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
    int wood = 0;
    int stone = 0;
    int crops = 0;

    std::list<Farmers>::iterator farmer = farmerPeople.begin();
    for (int index = 0; index < farmerPeople.size(); index++)
    {
        if (farmer->PHoused() && farmer->PHunger() <100)
        {
            crops++;
            if(farmer->HasTool()){
                crops++;
            }
        }
        ++farmer;
    }

    std::list<Miners>::iterator miner = minerPeople.begin();
    for (int index = 0; index < minerPeople.size(); index++)
    {
        if (miner->PHoused() && miner->PHunger() < 100)
        {
            stone++;
            if (miner->HasTool())
            {
                stone++;
            }
        }
        ++miner;
    }

    std::list<Loggers>::iterator logger = loggerPeople.begin();
    for (int index = 0; index < loggerPeople.size(); index++)
    {
        if (logger->PHoused() && logger->PHunger() < 100)
        {
            wood++;
            if (logger->HasTool())
            {
                wood++;
            }
        }
        ++logger;
    }
    resources[0] = wood;
    resources[1] = stone;
    resources[2] = crops;
    return resources;
};

void PersonManager::UnhousePerson(int uid){
    People* person = FindPerson(uid);
    person->PHoused(false);
};