#ifndef TOOLS_H
#define TOOLS_H
#include "UsefulObjects.h"
#include "People.h"

class Tools : public UsefulObject{
    private:
        bool available = true;
        int ownerID;

    public:
        Tools();
        bool Available();
        void Available(bool isavailable);
        void SetOwner(People *owner);
        int GetOwner();
        void Break();
};

#endif
