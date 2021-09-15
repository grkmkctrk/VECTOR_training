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

// .---------------------------------------------. //
///////////////////////////
// / begin decleration / //

void Randomize();
std::string srandom();

// / end decleration / //
///////////////////////////
// .---------------------------------------------. //
///////////////////////
// / begin typedef / //

typedef std::vector<int> vectorInt;
typedef std::vector<double> vectorDouble;
typedef std::vector<std::string> vectorString;

// /  end typedef  / //
///////////////////////
// .---------------------------------------------. //
///////////////////////////////////
// / begin template definition / //

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

template<class iterCon>
auto cSum(iterCon beg, iterCon end){
    auto returnValue = *beg - *beg;
    
    for (
        auto iter = beg; 
        iter != end; 
        returnValue+=(*iter++)
        );

    return returnValue;
}

template<class Con>
auto cSum2(Con& con){
    typename Con::const_iterator iter = con.begin();
    auto returnValue = *iter - *iter;

    for (
        ;
        iter != con.end(); 
        returnValue+=(*iter++)
        );

    return returnValue;
}

template<class iterCon>
auto cMeanIt(iterCon beg, iterCon end){
    auto returnValue = *beg - *beg;
    size_t size = 0;
    for (
        ;
        beg != end;
        size++,
        returnValue+=(*beg++)
        );

    return static_cast<double>(returnValue) / size;
}

template<class iterCon>
auto cMeanIt2(iterCon beg, iterCon end){
    auto returnValue = *beg - *beg;
    auto iter = beg;
    size_t size = 0;

    while (
        (iter != end) && 
        (size++ != -1) && 
        (returnValue+=(*iter++))
        );
    
    return static_cast<double>(returnValue) / size;
}

template<class Con>
auto cMeanCon(Con& con){
    typename Con::const_iterator iter = con.begin();
    auto returnValue = *iter - *iter;
    size_t size = 0;
    for (
        ; 
        iter != con.end();
        size++, 
        returnValue+=*iter++
        );
    return static_cast<double>(returnValue) / size;
}

template<class Con>
auto cMeanCon2(Con& con){
    typename Con::const_iterator iter = con.begin();
    auto returnValue = *iter - *iter;
    size_t size = 0;

    while (
        (iter != con.end()) && 
        (size++ != -1) && 
        (returnValue+=(*iter++))
        );
    
    return static_cast<double>(returnValue) / size;
}

template<class Con>
auto cMeanCon3(Con& con){
    return static_cast<double>(cSum2(con)) / con.size();
}

// / end template definition / //
///////////////////////////////////
// .---------------------------------------------. //

#endif