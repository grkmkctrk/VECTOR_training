#ifndef _UTILITYCLASS_HPP__
#define _UTILITYCLASS_HPP__

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iterator>
#include <algorithm>

#include <ctime>
#include <cstdlib>

///////////////////////////
// / begin decleration / //

void Randomize();
std::string srandom();

// / begin decleration / //
///////////////////////////

/////////////////////////////
// / template definition / //

template<class Con>
void cdisplay(const Con& con){
    // auto iter = con.begin();
    typename Con::const_iterator iter = con.begin();
    for (
        ; 
    iter != con.end(); 
    std::cout << *iter << " ",
    iter++);std::cout << std::endl;
}

template<class T>
T naturalRandom(T beg, T end){
    double value = static_cast<double>(rand()) / RAND_MAX; // it will generate random numbers between 0 and 1
    T returnValue = static_cast<T>((value * (end - beg)) + beg);
    return returnValue;
}

template<class Con, class Y>
void cfill(Con& con, int size, Y beg, Y end){
    for (size_t i = 0; i < size; i++)
        con.push_back(naturalRandom(beg, end));
}

template<class Con>
void cfillString(Con& con, int size){
    for (size_t i = 0; i < size; i++)
        con.push_back(srandom());
}

// / template definition / //
/////////////////////////////

#endif