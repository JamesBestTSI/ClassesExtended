#ifndef HOUSE_H
#define HOUSE_H
#include <list>
#include "UsefulObjects.h"

class House : public UsefulObject {
    private:
        bool InUse = false;
        std::list<int> PeopleInHouseUIDs{};

    public:
        House();
        int NumberOfPeopleInHouse();
        void AddPersonToHouse(int personUID);
        bool Fix(int amount);
        void UnhousePeople(int peopleToUnhouse[3]);
        void Break();
};

#endif