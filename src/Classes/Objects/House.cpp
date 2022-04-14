#include "../../../include/House.h"
#include "../../../include/Constants.h"

House::House(){
};

int House::NumberOfPeopleInHouse(){
    return PeopleInHouseUIDs.size();
};

void House::AddPersonToHouse(int personUID){
    PeopleInHouseUIDs.push_back(personUID);
};

bool House::Fix(int amount){
    UpdateDurability(amount);
    return true;
};

void House::UnhousePeople(int peopleToUnhouse[peoplePerHouse]){
    std::list<int>::iterator personID = PeopleInHouseUIDs.begin();

    for (int index = 0; index < PeopleInHouseUIDs.size(); index++)
    {
        peopleToUnhouse[index] = *personID;
        ++personID;
    }
};

void House::Break(){
    PeopleInHouseUIDs.clear();    
};