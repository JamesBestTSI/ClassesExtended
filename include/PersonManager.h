#ifndef PERSONMANAGER_H
#define PERSONMANAGER_H
#include <list>
#include <iostream>
#include "Workers.h"
#include "Miners.h"
#include "Loggers.h"
#include "Farmers.h"
#include "Unemployed.h"
#include "Tools.h"
#include "Meals.h"
#include "Constants.h"

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
    People* FindPerson(int uid);
    Workers* FindWorker(int uid);
    void GivePersonJob(int uid, jobRole role);
    void GivePersonTool(int uid, Tools *tool);
    void ListPersonInfo(int uid);
    void ListPersonInfo(People *personsDetails);
    void ListPeopleInRole(jobRole role);
    void FeedPeople(std::list<Meals>* meals);
    int* MakeResources(int resourcesWSC[3]);
    void UnhousePerson(int uid);
    int PeopleCount();
};

#endif