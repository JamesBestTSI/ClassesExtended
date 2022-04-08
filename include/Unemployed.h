#ifndef UNEMPLOYED_H
#define UNEMPLOYED_H
#include "People.h"

class Unemployed: public People{
    private:
    public:
        Unemployed();
        Unemployed(People person);
        bool PEat();
};

#endif
