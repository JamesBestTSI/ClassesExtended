#include "../../../include/Workers.h"
#include <string>

Workers::Workers(){};
    
void Workers::GiveTool(Tools *toolGiven){
    hasTool = true;
    tool = toolGiven;
};

bool Workers::HasTool() { return hasTool; };

void Workers::RemoveTool(){
    tool = NULL;
    hasTool = false;
};