#ifndef TOOLS_H
#define TOOLS_H
#include "UsefulObjects.h"
#include "People.h"

class Tools : public UsefulObject{
    private:
        bool available = true;
        People *owner;

    public:
        Tools();
        bool Available();
        void Available(bool isavailable);
        void SetOwner(People *owner);
};

#endif
