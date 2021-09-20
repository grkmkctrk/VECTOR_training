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

template<class Con, class iter1, class iter2>
Con cSumTwoVectorIt(iter1 beg1, iter1 end1, iter2 beg2, iter2 end2, Con& con){
    for (; 
        beg1 != end1 && beg2 != end2; 
        con.push_back(*beg1++ + *beg2++)
        );
    return con;
}

template<class Con, class iter1, class iter2>
Con cSumTwoVectorIt2(iter1 beg1, iter1 end1, iter2 beg2, iter2 end2, Con& con){
    while(beg1 != end1 && beg2 != end2){
        con.push_back(*beg1++ + *beg2++);
    }

    return con;
}

template<class iter1, class iter2, class iter3>
auto cSumTwoVectorIt3(
    iter1 beg1, iter1 end1, 
    iter2 beg2, iter2 end2, 
    iter3 beg3, iter3 end3){
    for (; 
        beg1 != end1 && beg2 != end2 && beg3 != end3; 
        *beg3++ = *beg1++ + *beg2++
        );

    return beg3;
}

template<class Con, class iter1, class iter2>
Con cMinusTwoVector(iter1 beg1, iter1 end1, iter2 beg2, iter2 end2, Con& con){
    for (; 
        beg1 != end1 && beg2 != end2; 
        con.push_back(*beg1++ - *beg2++)
        );
    return con;
}

template<class Con, class iter1, class iter2>
Con cProductTwoVector(iter1 beg1, iter1 end1, iter2 beg2, iter2 end2, Con& con){
    for (; 
        beg1 != end1 && beg2 != end2; 
        con.push_back(*beg1++ * *beg2++)
        );
    return con;
}

template<class Con, class iter1, class iter2>
Con cDivideTwoVector(iter1 beg1, iter1 end1, iter2 beg2, iter2 end2, Con& con){
    auto dividedZero = *beg2 - *beg2;
    
    do{
        if(*beg2 == dividedZero || *beg1 == dividedZero) 
            con.push_back(dividedZero);
        else 
            con.push_back(static_cast<double>(*beg1) / *beg2);
        // beg1++;beg2++; 
    }while(beg1++ != end1 && beg2++ != end2);
    
    return con;
}

template<class Type1, class Type2, class Type3>
void cMinusTwoVectorIt( Type1 beg1, Type1 end1, 
                        Type2 beg2, Type2 end2, 
                        Type3 beg3, Type3 end3){
    for (; 
        beg1 != end1 && beg2 != end2;
        *beg3++ = *beg1++ - *beg2++
    );
}

template<class Type1, class Type2, class Type3>
void cProductTwoVectorIt(Type1 beg1, Type1 end1, 
                         Type2 beg2, Type2 end2, 
                         Type3 beg3, Type3 end3){
    for (; 
        beg1 != end1 && beg2 != end2;
        *beg3++ = *beg1++ * *beg2++
    );

}

template<class Type1, class Type2, class Type3>
void cDivideTwoVectorIt(Type1 beg1, Type1 end1, 
                        Type2 beg2, Type2 end2, 
                        Type3 beg3, Type3 end3){
    for (; 
        beg1 != end1 && beg2 != end2;
        *beg3 = !(*beg2) ? (*beg2 - *beg2) : static_cast<double>(*beg1) / *beg2,
        beg1++, beg2++, beg3++
    );

}

template<class type1, class type2>
void cSumOneVecIt(
    type1 beg1, type1 end1, 
    type2 beg2, type2 end2){

    for (; 
    beg1 != end1 && beg2 != end2; 
    *beg1++ += *beg2++
    );
}

template<class type1, class type2>
void cMinusOneVecIt(
    type1 beg1, type1 end1, 
    type2 beg2, type2 end2){

    for (; 
    beg1 != end1 && beg2 != end2; 
    *beg1++ -= *beg2++
    );
}

template<class type1, class type2>
void cProductOneVecIt(
    type1 beg1, type1 end1, 
    type2 beg2, type2 end2){

    for (; 
    beg1 != end1 && beg2 != end2; 
    *beg1++ *= *beg2++
    );
}

template<class type1, class type2>
void cDivideOneVecIt(
    type1 beg1, type1 end1, 
    type2 beg2, type2 end2){

    for (; 
        beg1 != end1 && beg2 != end2; 
        *beg1 = (*beg2) ? static_cast<double>(*beg1) / *beg2 : 0 ,
        beg1++, beg2++
    );
}

template<class t1, class t2>
void swapVecElementIt(t1 beg1, t1 end1, t2 beg2, t2 end2){
    auto holder = beg1;
    do{
        holder = *beg1;
        *beg1 = *beg2;
        *beg2 = holder;
    }while (beg1++ != end1 && beg2++ != end2);

}

template<class t1, class t2>
void swapR(t1& beg1, t2& beg2){
    auto holder = beg1;
    beg1 = beg2;
    beg2 = holder;
}

template<class t1, class t2>
void swapP(t1 beg1, t2 beg2){
    auto holder = *beg1;
    *beg1 = *beg2;
    *beg2 = holder;
}

template<class t1, class t2>
void swapVectorElementsItFunc(t1 beg1, t1 end1, t2 beg2, t2 end2){
    do{
        // swapR(*beg1, *beg2);
        swapP(beg1, beg2);
    }while(beg1++ != end1 && beg2++ != end2);
}

template<class t1Con, class t2Con>
void swapVectorElementsCon(t1Con& con1, t2Con& con2){

    typename t1Con::iterator iter1 = con1.begin();
    typename t2Con::iterator iter2 = con2.begin();
    do{
        // auto holder = *iter1;
        // *iter1 = *iter2;
        // *iter2 = holder;

        // swapR(*iter1, *iter2);

        swapP(iter1, iter2);
    }while (iter1++ != con1.end() && iter2++ != con2.end());
    
}


template<class t1It, class t2It>
void reverseSwapVectorsElemenstIt(t1It beg1, t1It end1, t2It beg2, t2It end2){
    
    // do{
    //     end1--;
    //     auto holder = *end1;
    //     *end1 = *beg2;
    //     *beg2 = holder;
    // }while (end1 != beg1 && beg2++ != end2);

    for (
        auto holder = *end1; 
        end1 != beg1 && beg2 != end2; 
        end1--,
        holder = *end1,
        *end1 = *beg2,
        *beg2 = holder,
        beg2++
        );
    

}
// / end template definition / //
///////////////////////////////////
// .---------------------------------------------. //

template<class Con1, class Con2>\
void reverseSwapVectorsElementsCon(Con1& con1, Con2& con2){
    
    // auto end1 = con1.end();
    // auto beg2 = con2.begin();
    // do{
    //     end1--;
    //     auto holder = *end1;
    //     *end1 = *beg2;
    //     *beg2 = holder;
    // }while(end1 != con1.begin() && beg2++ != con2.end());

    // auto end1 = con1.end();
    // auto beg2 = con2.begin();
    // for(
    //     auto holder = *end1;
    //     end1 != con1.begin() && beg2 != con2.end();
    //     end1--,
    //     holder = *end1,
    //     *end1 = *beg2,
    //     *beg2 = holder,
    //     beg2++
    //     );

    typename Con1::reverse_iterator iter1 = con1.rbegin();
    typename Con2::iterator  iter2 = con2.begin();
    auto holder = *iter1 = *iter1;

    for (
        ; 
        iter1 != con1.rend() && iter2 != con2.end(); 
        holder = *iter1,
        *iter1 = *iter2,
        *iter2 = holder,
        iter1++, iter2++
        );
}

template<class T>
auto findMaxValueIt(T beg, T end){
    auto result = *beg - *beg;

    // while (
    //     end-- != beg && 
    //     (result = (*end > result) ? *end : result)
    //     );

    for(
        ; 
        end-- != beg; 
        result = (*end > result) ? *end : result
    );

    return result;
}

template<class Con>
auto findMaxValueCon(Con& con){
    auto beg = con.begin();
    auto end = con.end();
    auto result = *beg - *beg;
    for(
        ; 
        end-- != beg;
        result = (*end > result) ? *end : result
    );
    return result;
}

template<class T>
auto findMinValueIt(T beg, T end){
    auto result = *beg;

    // while (
    //     end-- != beg && 
    //     (result = (*end < result) ? *end : result)
    //     );

    for(
        ; 
        end-- != beg; 
        result = (*end < result) ? *end : result
    );

    return result;
}

template<class Con>
auto findMinValueCon(Con& con){
    auto beg = con.begin();
    auto end = con.end();
    auto result = *beg;
    for(
        ; 
        end-- != beg;
        result = (*end < result) ? *end : result
    );
    return result;
}

template<typename T>
void sortVectorIt(T beg, T end){
    size_t size = 0;

    auto sortBeg = beg;
    auto sortEnd = end;

    while(beg != end){
        size++;
        beg++;
    }

    for (size_t i = 0; i < size - 1; i++){
        auto sortBegNext = sortBeg;
        for (size_t k = 0; k < size - i - 1; k++){
            if(*sortBeg > *++sortBegNext)
                swapR(*sortBeg, *sortBegNext);
        }
        sortBeg++;
    }

}

template<class T>
void sortVectorCon(T& con){

    size_t size = con.size();

    for (size_t i = 0; i < size - 1; i++){
        for (size_t k = 0; k < size - i; k++){
            if(con[i] > con[i+k])
                swapR(con[i], con[i+k]);
        }
    }

}

template<typename T>
void reverseSortVectorIt(T beg, T end){
    size_t size = 0;

    auto sortBeg = beg;
    auto sortEnd = end;

    while(beg != end){
        size++;
        beg++;
    }

    for (size_t i = 0; i < size - 1; i++){
        auto sortBegNext = sortBeg;
        for (size_t k = 0; k < size - i - 1; k++){
            if(*sortBeg < *++sortBegNext)
                swapR(*sortBeg, *sortBegNext);
        }
        sortBeg++;
    }

}

template<class T>
void reverseSortVectorCon(T& con){

    size_t size = con.size();

    for (size_t i = 0; i < size - 1; i++){
        for (size_t k = 0; k < size - i; k++){
            if(con[i] < con[i+k])
                swapR(con[i], con[i+k]);
        }
    }

}


template<class T1, class T2>
void myCopyIt(T1 beg1, T1 end1, T2 beg2, T2 end2){
    
    for (
        ; 
        beg1 != end1; 
        *beg2 = *beg1,
        beg1++, beg2++
        );
}

template<class Con>
void myCopyCon(Con& con1, Con& con2){

    typename Con::iterator iter = con1.begin();

    for (
        ; iter != con1.end(); 
        con2.push_back(*iter), 
        iter++
        );
}

template<class T1, class T2>
void myCopyDiff(T1 beg1, T1 end1, T2 beg2 , T2 end2){
    for (
        ; 
        beg1 != end1; 
        *beg2 = *beg1,
        beg1++, beg2++
        );
}

template<class t1, class t2>
void myCopyDiffReverse(t1 beg1, t1 end1, t2 beg2, t2 end2){

    for (
        end1--; 
        end1 != beg1-1; 
        *beg2 = *end1,
        end1--,
        beg2++
        );
}

template<class Con1, class Con2>
void myCopyReverse(Con1& con1, Con2& con2){
    

    for (
        typename Con1::iterator iter = con1.end();
        iter != con1.begin(); 
        con2.push_back(*--iter)
        );
}

#endif