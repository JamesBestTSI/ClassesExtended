#ifndef PERSONMANAGER_H
#define PERSONMANAGER_H
#include <list>
#include <iostream>
#include "Workers.h"
#include "Miners.h"
#include "Loggers.h"
#include "Farmers.h"
#include "Unemployed.h"

class PersonManager{
private:
    int peopleUID = 0;
    std::list<Unemployed> unemployedPeople{};
    std::list<Miners> minerPeople{};
    std::list<Farmers> farmerPeople{};
    std::list<Loggers> loggerPeople{};

public:
    PersonManager();
    void AddPerson(People &person);
    void RemovePerson(jobRole role, int uid);
    int unemployedCount();
    int minerCount();
    int farmerCount();
    int loggerCount();
    People FindPerson(int uid);
    void GivePersonJob(int uid, jobRole role);
    void ListPersonInfo(int uid);
    void ListPeopleInRole(jobRole role);
};

#endif
