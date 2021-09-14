
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

#include "utilityClass.hpp"

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

    / EX1
*/

/*
    / EX2

    / EX2
*/

#include "utilityClass.hpp"

using namespace std;

int main(){

    
    // pointer is not alocated. iVec just stored itself
    vector<int> iVec; 
    vector<double> dVec; 
    vector<string> sVec; 
    
    Randomize();

    cfill(iVec, 10, 0.0, 100.0);
    cdisplay(iVec);
    cfill(dVec, 10, 0.0, 100.0);
    cdisplay(dVec);
    cfillString(sVec, 10);
    cdisplay(sVec);

    return 0;
}
