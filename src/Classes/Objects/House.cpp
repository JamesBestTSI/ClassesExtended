#include "../../../include/House.h"

House::House(){
    
};

int House::NumberOfPeopleInHouse(){
    return PeopleInHouseUIDs.size();
};

void House::AddPersonToHouse(int personUID){
    PeopleInHouseUIDs.push_back(personUID);
};