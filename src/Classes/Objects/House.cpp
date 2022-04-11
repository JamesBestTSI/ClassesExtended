#include "../../../include/House.h"

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
}

void House::UnhousePeople(){
    
};