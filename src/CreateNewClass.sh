#!/bin/bash

echo "# Enter Class Name:"
read className


###########################################
# Make .h
###########################################
echo "#ifndef ${className^^}_H
#define ${className^^}_H

class $className{
    private:

    public:
        $className();
};

#endif" > $className.h

###########################################
# Make .cpp
###########################################
echo "#include \"$className.h\"
#include <string>

$className::$className(){};
    
" > $className.cpp
