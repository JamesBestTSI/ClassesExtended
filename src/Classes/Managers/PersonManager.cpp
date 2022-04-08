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

People PersonManager::FindPerson(int uid){
    People personsDetails = People();

    std::list<Unemployed>::iterator person = unemployedPeople.begin();
    for (int index = 0; index < unemployedPeople.size(); index++)
    {
        if (person->PUID() == uid)
        {
            personsDetails = People(*person);
            return personsDetails;
        }
        ++person;
    }

    std::list<Farmers>::iterator farmer = farmerPeople.begin();
    for (int index = 0; index < farmerPeople.size(); index++)
    {
        if (farmer->PUID() == uid)
        {
            personsDetails = People(*farmer);
            return personsDetails;
        }
        ++farmer;
    }

    std::list<Miners>::iterator miner = minerPeople.begin();
    for (int index = 0; index < minerPeople.size(); index++)
    {
        if (miner->PUID() == uid)
        {
            personsDetails = People(*miner);
            return personsDetails;
        }
        ++miner;
    }

    std::list<Loggers>::iterator logger = loggerPeople.begin();
    for (int index = 0; index < loggerPeople.size(); index++)
    {
        if (logger->PUID() == uid)
        {
            personsDetails = People(*logger);
            return personsDetails;
        }
        ++logger;
    }
    return personsDetails;
};

void PersonManager::GivePersonJob(int uid, jobRole role){
    // Find Person
    People personsDetails = FindPerson(uid);
    // Remove old person
    RemovePerson(personsDetails.PRole(), personsDetails.PUID());
    // Add person with new role
    personsDetails.PRole(role);
    AddPerson(personsDetails);
};

void PersonManager::ListPersonInfo(int uid){
    // Find Person
    People personsDetails = FindPerson(uid);

    std::cout << personsDetails.PUID() << std::endl;
    std::cout << personsDetails.PName() << std::endl;
    std::cout << personsDetails.PAge() << std::endl;
    std::cout << personsDetails.PHunger() << std::endl;
    // Housed       std::cout << personsDetails.PName() << std::endl;
    // Job Role     std::cout << personsDetails.PName() << std::endl;
};

void PersonManager::ListPeopleInRole(jobRole role){

};