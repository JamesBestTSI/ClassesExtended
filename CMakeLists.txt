# Set minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Set the project_name and version
project(ClassesExtended VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#include_directories(include)

set(MANAGERS src/Classes/Managers/Manager.cpp src/Classes/Managers/PersonManager.cpp)
set(RESOURCES src/Classes/Resources/resource.cpp)
set(OBJECTS src/Classes/Objects/UsefulObjects.cpp src/Classes/Objects/House.cpp src/Classes/Objects/Meals.cpp src/Classes/Objects/Tools.cpp)
set(PEOPLE src/Classes/People/People.cpp src/Classes/People/Workers.cpp src/Classes/People/Unemployed.cpp src/Classes/People/Farmers.cpp src/Classes/People/Loggers.cpp src/Classes/People//Miners.cpp)

# Add the executable
add_executable(ClassesExtended main.cpp ${MANAGERS} ${RESOURCES} ${OBJECTS} ${PEOPLE})

# Add the targeted cpp features
target_compile_features(ClassesExtended PUBLIC cxx_std_20)
