#ifndef PEOPLE_H
#define PEOPLE_H
#include <string>
#include "House.h"

enum jobRole
{
    None,
    Farmer,
    Miner,
    Logger
};

class People{
    private:
        int UID = -1;
        std::string Name;
        int Age;
        int Hunger = 0;
        int Health = 5;
        bool Housed = false;
        jobRole Role = jobRole::None;

    public:
        // Construstors
        People();
        People(std::string name, int age, jobRole role);
        People(People *person);

        // Get/Set
        int PUID();
        void PUID(int uid);
        std::string PName();
        void PName(std::string name);
        int PAge();
        void PAge(int age);
        int PHunger();
        void PHunger(int hunger);
        bool PHoused();
        void PHoused(bool housed);
        jobRole PRole();
        void PRole(jobRole role);

        // Methods
        bool Starve();
        virtual bool PEat();
        virtual void PDie();

        House *home;
};

#endif