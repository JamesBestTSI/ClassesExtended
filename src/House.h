#ifndef HOUSE_H
#define HOUSE_H
#include <list>

class House{
    private:
        bool InUse;
        //std::list<People *> HousedPeople{};

    public:
        House();
        bool Fix();
        void UnhousePeople();
};

#endif