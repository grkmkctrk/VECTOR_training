
/*

.vector -> dynamin array block (run time, compile time)

- swap must be handled in physical.
- dynamic storage -> capacity()
- dynamic data ----> size()
- push_back() function has O(n) const.

In order to use vector efficiently, these following statement are noticed as
    - use reserve() funtion
    - pay attention to the pointers : reallocation can be uncurrent
    - capacity can be smaller or higher than normal


/ Advantages of the usage of vectors:
    . constant time access, addition or removing data
    . assignment of value has linear cost!

*/


/*
    / EX1

    / EX1
*/
#include "utility/utilityClass.hpp"

using namespace std;

vector<int>& fillVec(vector<int>& vec, int count){
    for (size_t i = 0; i < count; i++)
        vec.push_back(((i/2)+1)*i*i);

    return vec;
}

void displayVec(const vector<int>& vec){
    for (
        auto i = vec.begin(); 
        i != vec.end(); 
        cout << *i << " ",
        i++); cout << endl;
}

int main(){

    vector<int> iVec;

    fillVec(iVec, 21);
    displayVec(iVec);

    return 0;
}