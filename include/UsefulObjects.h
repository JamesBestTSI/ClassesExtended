#ifndef USEFULOBJECTS_H
#define USEFULOBJECTS_H
#include <string>

enum UsefulObjectType
{
    HouseObject,
    MealObject,
    ToolObject
};

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