#include "../../../include/People.h"

// Constructors
People::People(){};

People::People(std::string name, int age, jobRole role){
    Name    = name;
    Age     = age;
    Role    = role;
};

People::People(People *person){
    UID     = person->UID;
    Name    = person->Name;
    Age     = person->Age;
    Role    = person->Role;
    Hunger  = person->Hunger;
    Housed  = person->Housed;
};

// Get
int People::PUID()              { return UID; };
std::string People::PName()     { return Name; };
int People::PAge()              { return Age; };
int People::PHunger()           { return Hunger; };
bool People::PHoused()          { return Housed; };
jobRole People::PRole()         { return Role; };
// Set
void People::PUID(int uid)              { UID = uid; }
void People::PName(std::string name)    { Name = name; };
void People::PAge(int age)              { Age = age; };
void People::PHunger(int hunger)        { Hunger = hunger; };
void People::PHoused(bool housed)       { Housed = housed; };
void People::PRole(jobRole role)        { Role = role; };

// Methods
bool People::PEat() {
    Hunger = 0;
    return true;
};
void People::PDie(){};