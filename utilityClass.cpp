#include "utilityClass.hpp"

using namespace std;

void Randomize(){
    srand(static_cast<unsigned>(time(0))); 
}


std::string srandom(){
    static const char* const pnames[] = {
        "Berathan",
        "Gorkem",
        "Berda",
        "Ramazan",
        "Ahmetcan",
        "Melih",
        "Burak",
        "Emir",
        "Eymen",
        "Miray",
        "Zeynep",
        "Goktug"};
    
    size_t size = sizeof(pnames) / sizeof(*pnames);

    return pnames[rand() % size];
}