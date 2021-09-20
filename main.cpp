
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

    / EX2
*/


/*
    / EX3



#include "utilityClass.hpp"

using namespace std;

int main(){

    vector<int> iVec;
    vector<double> dVec;

    Randomize();

    cout << "SUM PROCESS USING ITERATOR" << endl;
    
    cfill(iVec, 2,  0.0,  100.0);
    cdisplay(iVec);
    cout << "The result of sumation of iVec : " << cSum(iVec.begin(), iVec.end()) << endl;
    
    cout << endl; ///
    
    cfill(dVec, 2,  0.0,  100.0);
    cdisplay(dVec);
    cout << "The result of sumation of dVec : " << cSum(dVec.begin(), dVec.end()) << endl;
    
    cout << endl << endl; iVec.clear(); dVec.clear();

    cout << "SUM PROCESS USING CONTEINER ITSELF" << endl;
 
    cfill(iVec, 2, 0.0, 100.0);
    cdisplay(iVec);
    cout << "The result of sumation of dVec : " << cSum2(iVec) << endl;
 
    cout << endl;
 
    cfill(dVec, 2,  0.0,  100.0);
    cdisplay(dVec);
    cout << "The result of sumation of dVec : " << cSum2(dVec) << endl;
 
    return 0;
}
    / EX3
*/

/*
    / EX4


#include "utilityClass.hpp"

using namespace std;

int main(){

    vectorInt iVec;
    vectorDouble dVec;
    
    Randomize();

    cfill(iVec, 2, 0.0, 100.0);
    cdisplay(iVec);
    
    cfill(dVec, 2, 0.0, 100.0);
    cdisplay(dVec);

    cout << cSum2(iVec) << " " << cSum2(dVec) << endl;

    // cout << "Mean of iVec is (" << cMeanIt(iVec.begin(), iVec.end()) << ")" << endl; 

    // cout << "Mean of iVec is (" << cMeanIt(dVec.begin(), dVec.end()) << ")" << endl; 
    // cout << endl << endl;
    // cout << "Mean of iVec is (" << cMeanIt2(iVec.begin(), iVec.end()) << ")" << endl; 

    // cout << "Mean of iVec is (" << cMeanIt2(dVec.begin(), dVec.end()) << ")" << endl; 

    return 0;
}

    / EX4
*/

/*
    / EX5


#include "utilityClass.hpp"

using namespace std;

int main(){

    vectorInt iVec;

    Randomize();

    cfill(iVec, 3, 0.0, 100.0);
    cdisplay(iVec);

    cout << "Mean of iVec is (" << cMeanCon(iVec) << ")" << endl;
    cout << "Mean of iVec is (" << cMeanCon2(iVec) << ")" << endl;
    cout << "Mean of iVec is (" << cMeanCon3(iVec) << ")" << endl;

    return 0;
}
    / EX5
*/

/*
    / EX6

#include "utilityClass.hpp"

using namespace std;

int main(){

    vectorInt iVec1, iVec2, iVec3(10);

    Randomize();

    cfill(iVec1, 10, 0.0, 100.0);
    cfill(iVec2, 10, 0.0, 100.0);

    cdisplay(iVec1);
    cdisplay(iVec2);

    // cSumTwoVectorIt(
    //     iVec1.begin(), iVec1.end(), 
    //     iVec2.begin(), iVec2.end(),
    //     iVec3
    //     );

    // cSumTwoVectorIt2(
    //     iVec1.begin(), iVec1.end(), 
    //     iVec2.begin(), iVec2.end(),
    //     iVec3
    //     );

    cSumTwoVectorIt3(
        iVec1.begin(), iVec1.end(), 
        iVec2.begin(), iVec2.end(),
        iVec3.begin(), iVec3.end()
        );

    cdisplay(iVec3);

    return 0;
}

    / EX6
*/


/*
    / EX7
   
#include "utilityClass.hpp"

using namespace std;

int main(){

    vectorInt iVec1, iVec2;
    vectorDouble iVec3;

    Randomize();

    cfill(iVec1, 10, 0.0, 100.0);
    cfill(iVec2, 10, 0.0, 100.0);

    cout << "iVec1 : "; cdisplay(iVec1);
    cout << "iVec2 : "; cdisplay(iVec2);

    cout << "CALCULATIONS" << endl;

    cMinusTwoVector(
        iVec1.begin(), iVec1.end(), 
        iVec2.begin(), iVec2.end(),
        iVec3
        );

    cout << "MINUS   -> ";
    cdisplay(iVec3); cout << endl; iVec3.clear();
    cProductTwoVector(
        iVec1.begin(), iVec1.end(), 
        iVec2.begin(), iVec2.end(),
        iVec3
        );

    cout << "PRODUCT -> ";
    cdisplay(iVec3); cout << endl; iVec3.clear();
    cDivideTwoVector(
        iVec1.begin(), iVec1.end(), 
        iVec2.begin(), iVec2.end(),
        iVec3
        );
        
    cout << "DIVIDE  -> ";
    cdisplay(iVec3);


    return 0;
}
 / EX7
*/

/*
    / EX8


#include "utilityClass.hpp"

using namespace std;

int main(){

    // vectorInt iVec1, iVec2;
    vectorDouble iVec1, iVec2;
    vectorDouble iVec3(10);

    Randomize();

    cfill(iVec1, 10, 0.0, 100.0);
    cfill(iVec2, 10, 0.0, 100.0);

    cout << "iVec1 : "; cdisplay(iVec1);
    cout << "iVec2 : "; cdisplay(iVec2);

    cout << "CALCULATIONS" << endl;

    cMinusTwoVectorIt(
        iVec1.begin(), iVec1.end(), 
        iVec2.begin(), iVec2.end(),
        iVec3.begin(), iVec3.end()
        );
    cout << "MINUS   -> ";
    cdisplay(iVec3); cout << endl;

    cProductTwoVectorIt(
        iVec1.begin(), iVec1.end(), 
        iVec2.begin(), iVec2.end(),
        iVec3.begin(), iVec3.end()
        );
    cout << "PRODUCT -> ";
    cdisplay(iVec3); cout << endl; 


    cDivideTwoVectorIt(
        iVec1.begin(), iVec1.end(), 
        iVec2.begin(), iVec2.end(),
        iVec3.begin(), iVec3.end()
        );
    cout << "DIVIDE  -> ";
    cdisplay(iVec3);
   
    return 0;
}
    / EX8
*/


/*
    / EX9



#include "utilityClass.hpp"

using namespace std;

int main(){

    list<double>  iVec1, iVec2;

    Randomize();

    cfill(iVec1, 10, 0.0, 100.0);
    cfill(iVec2, 10, 0.0, 100.0);

    cout << "iVec1 : "; cdisplay(iVec1);
    cout << "iVec2 : "; cdisplay(iVec2);

    cSumOneVecIt(
        iVec1.begin(), iVec1.end(), 
        iVec2.begin(), iVec2.end()
        );

    cout << "iVec1 : "; cdisplay(iVec1);

    cout << "/==================================================/\n";

    cout << "iVec1 : "; cdisplay(iVec1);
    cout << "iVec2 : "; cdisplay(iVec2);

    cMinusOneVecIt(
        iVec1.begin(), iVec1.end(), 
        iVec2.begin(), iVec2.end()
        );

    cout << "iVec1 : "; cdisplay(iVec1);

    cout << "/==================================================/\n";

    cout << "iVec1 : "; cdisplay(iVec1);
    cout << "iVec2 : "; cdisplay(iVec2);

    cProductOneVecIt(
        iVec1.begin(), iVec1.end(), 
        iVec2.begin(), iVec2.end()
        );

    cout << "iVec1 : "; cdisplay(iVec1);
    
    cout << "/==================================================/\n";

    cout << "iVec1 : "; cdisplay(iVec1);
    cout << "iVec2 : "; cdisplay(iVec2);

    cDivideOneVecIt(
        iVec1.begin(), iVec1.end(), 
        iVec2.begin(), iVec2.end()
        );

    cout << "iVec1 : "; cdisplay(iVec1);



    return 0;
}
    / EX9
*/


/*
    / EX10


#include "utilityClass.hpp"

using namespace std;

int main(){

    Randomize();

    vectorInt iVec1, iVec2;
    // list<int> iVec2;

    cfill(iVec1, 10, 0.0, 100.0);
    cfill(iVec2, 10, 0.0, 100.0);

    cout << "iVec1 = "; cdisplay(iVec1);
    cout << "iVec2 = "; cdisplay(iVec2);

    swapVecElementIt(
        iVec1.begin(), iVec1.end(), 
        iVec2.begin(), iVec2.end()
        );

    cout << "iVec1 = "; cdisplay(iVec1);
    cout << "iVec2 = "; cdisplay(iVec2);

    return 0;
}

    / EX10
*/

/*
    / EX11



#include "utilityClass.hpp"

using namespace std;

int main(){

    vectorDouble iVec1;
    vectorDouble iVec2;

    Randomize();

    cfill(iVec1, 10, 0.0, 100.0);
    cfill(iVec2, 10, 0.0, 100.0);

    cout << "iVec1 = "; cdisplay(iVec1);
    cout << "iVec2 = "; cdisplay(iVec2);

    swapVectorElementsItFunc(
        iVec1.begin(), iVec1.end(), 
        iVec2.begin(), iVec2.end()
        );
 
    cout << "iVec1 = "; cdisplay(iVec1);
    cout << "iVec2 = "; cdisplay(iVec2);

    return 0;
}

    / EX11
*/


/*
    / EX12


#include "utilityClass.hpp"

using namespace std;

int main(){

    vectorDouble iVec1;
    vectorDouble iVec2;

    Randomize();

    cfill(iVec1, 10, 0.0, 100.0);
    cfill(iVec2, 10, 0.0, 100.0);

    cout << "iVec1 = "; cdisplay(iVec1);
    cout << "iVec2 = "; cdisplay(iVec2);

    swapVectorElementsCon(iVec1, iVec2);

    cout << "iVec1 = "; cdisplay(iVec1);
    cout << "iVec2 = "; cdisplay(iVec2);

    return 0; 
}
    / EX12
*/

/*
    / EX13


#include "utilityClass.hpp"

using namespace std;

int main(){

    Randomize();

    vectorInt iVec1, iVec2;

    cfill(iVec1, 10, 0.0, 100.0);
    cfill(iVec2, 10, 0.0, 100.0);

    cout << "iVec1 : "; cdisplay(iVec1);
    cout << "iVec2 : "; cdisplay(iVec2);

    // reverseSwapVectorsElemenstIt(
    //     iVec1.begin(), iVec1.end(),
    //     iVec2.begin(), iVec2.end()
    //     );

    reverseSwapVectorsElementsCon(iVec1, iVec2);

    cout << "iVec1 : "; cdisplay(iVec1);
    cout << "iVec2 : "; cdisplay(iVec2);

    return 0;
}
    / EX13
*/

/*
    / EX14
    

#include "utilityClass.hpp"

using namespace std;

int main(){

    Randomize();

    vectorInt iVec1, iVec2;

    cfill(iVec1, 10, 0.0, 100.0);
    cfill(iVec2, 10, 0.0, 100.0);

    cout << "iVec1 : "; cdisplay(iVec1);
    cout << "iVec2 : "; cdisplay(iVec2);    

    // cout << "Max value of iVec1 is " << findMaxValueIt(iVec1.begin(), iVec1.end()) << endl;
    // cout << "Max value of iVec2 is " << findMaxValueIt(iVec2.begin(), iVec2.end()) << endl;
    // cout << "Max value of iVec1 is " << findMaxValueCon(iVec1) << endl;
    // cout << "Max value of iVec2 is " << findMaxValueCon(iVec2) << endl;

    // cout << "Max value of iVec1 is " << findMinValueIt(iVec1.begin(), iVec1.end()) << endl;
    // cout << "Max value of iVec2 is " << findMinValueIt(iVec2.begin(), iVec2.end()) << endl;
    cout << "Max value of iVec1 is " << findMinValueCon(iVec1) << endl;
    cout << "Max value of iVec2 is " << findMinValueCon(iVec2) << endl;

    return 0;
}

    / EX14
*/


/*
    / EX15
    

#include "utilityClass.hpp"

using namespace std;


int main(){

    Randomize();

    vectorInt iVec1, iVec2;

    cfill(iVec1, 10, 0.0, 100.0);
    cfill(iVec2, 10, 0.0, 100.0);

    cout << "iVec1 : "; cdisplay(iVec1);
    cout << "iVec2 : "; cdisplay(iVec2);     

    sortVectorIt(iVec1.begin(), iVec1.end());
    sortVectorIt(iVec2.begin(), iVec2.end());

    cout << "iVec1 : "; cdisplay(iVec1);
    cout << "iVec2 : "; cdisplay(iVec2);

    return 0;
}
    / EX15
*/

/*
    / EX16
    
#include "utilityClass.hpp"

using namespace std;


int main(){

  Randomize();

    vectorInt iVec1, iVec2;

    cfill(iVec1, 10, 0.0, 100.0);
    cfill(iVec2, 10, 0.0, 100.0);

    cout << "iVec1 : "; cdisplay(iVec1);
    cout << "iVec2 : "; cdisplay(iVec2);     

    sortVectorCon(iVec1);
    sortVectorCon(iVec2);

    cout << "iVec1 : "; cdisplay(iVec1);
    cout << "iVec2 : "; cdisplay(iVec2);     

    return 0;
}

    / EX16
*/

/*
    / EX17
    

#include "utilityClass.hpp"

using namespace std;


int main(){

    Randomize();

    vectorInt iVec1, iVec2;

    cfill(iVec1, 10, 0.0, 100.0);
    cfill(iVec2, 10, 0.0, 100.0);

    cout << "iVec1 : "; cdisplay(iVec1);
    cout << "iVec2 : "; cdisplay(iVec2);     

    reverseSortVectorCon(iVec1);
    reverseSortVectorCon(iVec2);
    // reverseSortVectorIt(iVec1.begin(), iVec1.end());
    // reverseSortVectorIt(iVec2.begin(), iVec2.end());

    cout << "iVec1 : "; cdisplay(iVec1);
    cout << "iVec2 : "; cdisplay(iVec2);     

    return 0;
}

    / EX17
*/

/*
    / EX18
    

#include "utilityClass.hpp"

using namespace std;

int main(){

    Randomize();

    vectorInt iVec1;

    cfill(iVec1, 10, 0.0, 100.0);

    cout << "iVec1 : "; cdisplay(iVec1);

    // vectorInt iVec2(10);
    vectorInt iVec2;
    // one to two
    // myCopyIt(
    //     iVec1.begin(), iVec1.end(), 
    //     iVec2.begin(), iVec2.end()
    //     );
    myCopyCon(iVec1, iVec2);

    cout << "After copying" << "\n";
    cout << "iVec1 : "; cdisplay(iVec1);
    cout << "iVec2 : "; cdisplay(iVec2);

    sortVectorCon(iVec1);
    sortVectorCon(iVec2);

    cout << "After sorting" << "\n";
    cout << "iVec1 : "; cdisplay(iVec1);
    cout << "iVec2 : "; cdisplay(iVec2);
    
    return 0;
}
    / EX18
*/

/*
    / EX19
    
    / EX19
*/

#include "utilityClass.hpp"

using namespace std;

int main(){

    Randomize();

    vectorInt iVec1;

    cfill(iVec1, 10, 0.0, 100.0);

    cout << "iVec1 : "; cdisplay(iVec1);

    // list<int> iList1(10);
    // myCopyDiff(
    //     iVec1.begin(), iVec1.end(),
    //     iList1.begin(), iList1.end()
    //     );

    // myCopyDiffReverse(
    //     iVec1.begin(), iVec1.end(),
    //     iList1.begin(), iList1.end()
    //     );

    list<int> iList1;
    myCopyReverse(iVec1, iList1);

    cout << "iVec1 : "; cdisplay(iVec1);
    cout << "iList1 : "; cdisplay(iList1);

    return 0;
}