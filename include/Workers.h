#ifndef WORKERS_H
#define WORKERS_H
#include "People.h"
#include "Tools.h"

class Workers : public People{
    private:
        bool hasTool = false;
        Tools *tool;

    public:
        Workers();
        void GiveTool(Tools *toolGiven);
        bool HasTool();
};

#endif
