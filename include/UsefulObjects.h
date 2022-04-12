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
        int UID;
        std::string Name;
        int Amount;
        int Durability;

    public:
        UsefulObject();
        UsefulObject(std::string name, int amount, int durability);
        void SetID(int uid);
        int GetID();
        std::string UsefulObjectName();
        void UsefulObjectName(std::string name);
        int Amounts();
        void UpdateAmount(int amount);
        int Durabilities();
        void UpdateDurability(int amount);

        virtual void Break();
};
#endif