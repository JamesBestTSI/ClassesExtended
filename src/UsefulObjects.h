#ifndef USEFULOBJECTS_H
#define USEFULOBJECTS_H
#include <string>

class UsefulObject{
    private:
        std::string Name;
        int Amount;
        int Durability;

    public:
        UsefulObject();
        UsefulObject(std::string name, int amount, int durability);
        std::string UsefulObjectName();
        int Amounts();
        void UpdateAmount(int amount);
        int Durabilities();
        void UpdateDurability(int amount);
};
#endif