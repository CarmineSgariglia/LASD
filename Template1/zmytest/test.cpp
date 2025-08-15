
/* ************************************************************************** */

#include <iostream>

#include "../list/list.hpp"
#include "../vector/vector.hpp"
#include "../zlasdtest/container/container.hpp"
#include "../zlasdtest/container/traversable.hpp"
#include "../zlasdtest/container/testable.hpp"
#include "../zlasdtest/container/dictionary.hpp"
#include "../zlasdtest/container/linear.hpp"
#include "../zlasdtest/container/mappable.hpp"
#include "../zlasdtest/vector/vector.hpp"
#include "../zlasdtest/list/list.hpp"
#include "../zlasdtest/set/set.hpp"
#include "../set/lst/setlst.hpp"
#include "../set/vec/setvec.hpp"

using namespace std;

template <typename Data>
void InsertAtFrontM(uint & testnum, uint & testerr, lasd::List<Data> & list1, bool chk, const Data & val) {
    bool tst;
    testnum++;
    try {
        std::cout << " " << testnum << " (" << testerr << ") Insert at the front of the list the value \"" << val << "\": ";
        list1.InsertAtFront(move(val));
        std::cout << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
    } catch(std::exception & exc) {
        std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
    }
    testerr += (1 - (uint) tst);
}

template <typename Data>
void InsertAtBackM(uint & testnum, uint & testerr, lasd::List<Data> & list1, bool chk, const Data & val) {
    bool tst;
    testnum++;
    try {
        std::cout << " " << testnum << " (" << testerr << ") Insert at the back of the list the value \"" << val << "\": ";
        list1.InsertAtBack(move(val));
        std::cout << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
    } catch(std::exception & exc) {
        std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
    }
    testerr += (1 - (uint) tst);
}

void Clear(uint & testnum, uint & testerr,  lasd::ClearableContainer & con) {
    bool tst;
    testnum++;
    std::cout << " " << testnum << " (" << testerr << ") Clearing the container: ";
    con.Clear();
    std::cout << ((tst = (con.Empty())) ? "Correct" : "Error") << "!" << std::endl;
    testerr += (1 - (uint) tst);
}
template <typename Data>
void Sort(uint & testnum, uint & testerr, lasd::SortableLinearContainer<Data> & con, lasd::SortableLinearContainer<Data> &  c2, bool chk) {
    bool tst;
    testnum++;
    try {
        std::cout << " " << testnum << " (" << testerr << ") Sorting Array ";
        con.Sort();

        std::cout << ((tst = ((con == c2) == chk)) ? "Correct" : "Error") << "!" << std::endl;
    } catch(std::out_of_range & exc) {

        std::cout << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
    }  catch(std::exception & exc) {
        tst = false;
        std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
    }
    testerr += (1 - (uint) tst);
}

void testVectorInt(uint & testnum, uint & testerr) {
    uint loctestnum = 0, loctesterr = 0;
    cout << endl << "Start of Vector<int> Test:" << endl;
    try {
        {
            cout << endl << "Start of empty Vector<int> Test:" << endl;

            
            lasd::SortableVector<int> vec1;
            lasd::SortableVector<int> vec2;
            vec2 = vec1;
            Empty(loctestnum, loctesterr, vec1, true);
            Size(loctestnum, loctesterr, vec1, true, 0);
            EqualVector(loctestnum, loctesterr, vec1, vec2, true);
            

            SetAt(loctestnum, loctesterr, vec1, false, 1, 0);
            SetFront(loctestnum, loctesterr, vec1, false, 1);
            SetBack(loctestnum, loctesterr, vec1, false, 1);
            
            GetAt(loctestnum, loctesterr, vec1, false, 2, 0);
            GetFront(loctestnum, loctesterr, vec1, false, 0);
            GetBack(loctestnum, loctesterr, vec1, false, 0);
            

            Exists(loctestnum, loctesterr, vec1, false, 0);

            Traverse(loctestnum, loctesterr, vec1, true, &TraversePrint<int>);
            TraversePreOrder(loctestnum, loctesterr, vec1, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, vec1, true, &TraversePrint<int>);

            Fold(loctestnum, loctesterr, vec1, true, &FoldAdd<int>, 0, 0);
            FoldPreOrder(loctestnum, loctesterr, vec1, true, &FoldAdd<int>, 0, 0);
            FoldPostOrder(loctestnum, loctesterr, vec1, true, &FoldAdd<int>, 0, 0);

            Map(loctestnum, loctesterr, vec1, true, &MapIncrement<int>);
            MapPreOrder(loctestnum, loctesterr, vec1, true, &MapIncrement<int>);
            MapPostOrder(loctestnum, loctesterr, vec1, true, &MapIncrement<int>);

            lasd::SortableVector<int> check;
            Sort(loctestnum, loctesterr, vec1, check, true);
            Clear(loctestnum, loctesterr, vec1);

            cout  << "Stop of empty Vector<int> Test:" << endl;

        }
        {
            cout << endl << "Start of Vector<int> Test:" << endl;

            lasd::SortableVector<int> vec1(3);
            Empty(loctestnum, loctesterr, vec1, false);
            Size(loctestnum, loctesterr, vec1, true, 3);

            SetAt(loctestnum, loctesterr, vec1, true, 0, 2);
            SetAt(loctestnum, loctesterr, vec1, true, 1, 5);
            SetAt(loctestnum, loctesterr, vec1, true, 2, 7);

            GetFront(loctestnum, loctesterr, vec1, true, 2);
            GetBack(loctestnum, loctesterr, vec1, true, 7);
            GetAt(loctestnum, loctesterr, vec1, true, 2, 7);

            SetFront(loctestnum, loctesterr, vec1, true, 5);
            SetBack(loctestnum, loctesterr, vec1, true, 4);

            Exists(loctestnum, loctesterr, vec1, true, 5);
            Exists(loctestnum, loctesterr, vec1, false, 9);

            Traverse(loctestnum, loctesterr, vec1, true, &TraversePrint<int>);
            TraversePreOrder(loctestnum, loctesterr, vec1, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, vec1, true, &TraversePrint<int>);

            Fold(loctestnum, loctesterr, vec1, true, &FoldAdd<int>, 0, 14); 
            FoldPreOrder(loctestnum, loctesterr, vec1, true, &FoldAdd<int>, 0, 14); 
            FoldPostOrder(loctestnum, loctesterr, vec1, true, &FoldMultiply<int>, 1, 100); 

            Map(loctestnum, loctesterr, vec1, true, &MapIncrement<int>);
            MapPreOrder(loctestnum, loctesterr, vec1, true, &MapIncrement<int>);
            MapPostOrder(loctestnum, loctesterr, vec1, true, &MapIncrement<int>);

            lasd::SortableVector<int> check(vec1);
            Sort(loctestnum, loctesterr, vec1, check, false);
            check.Sort();
            Sort(loctestnum, loctesterr, vec1, check, true);

            TraversePreOrder(loctestnum, loctesterr, vec1, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, vec1, true, &TraversePrint<int>);

            vec1.Resize(1);
            FoldPostOrder(loctestnum, loctesterr, vec1, true, &FoldMultiply<int>, 1, 7); 

            lasd::SortableVector<int> mvec1(move(vec1));
            TraversePostOrder(loctestnum, loctesterr, mvec1, true, &TraversePrint<int>);

            Clear(loctestnum, loctesterr, mvec1);
        }
    } catch(...) {
        loctestnum++;
        loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }
    cout << "End of Vector<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}

void testVectorDouble(uint & testnum, uint & testerr) {
    uint loctestnum = 0, loctesterr = 0;
    cout << endl << "Begin of Vector<double> Test:" << endl;
    try {
        lasd::SortableVector<double> vec(3);
        Empty(loctestnum, loctesterr, vec, false);
        Size(loctestnum, loctesterr, vec, true, 3);

        SetAt(loctestnum, loctesterr, vec, true, 0, 2.5);
        SetAt(loctestnum, loctesterr, vec, true, 1, 3.3);
        SetAt(loctestnum, loctesterr, vec, true, 2, 6.1);

        SetFront(loctestnum, loctesterr, vec, true, 5.5);
        SetBack(loctestnum, loctesterr, vec, true, 1.1);

        GetFront(loctestnum, loctesterr, vec, true, 5.5);
        GetBack(loctestnum, loctesterr, vec, true, 1.1);
        GetAt(loctestnum, loctesterr, vec, true, 2, 1.1);

        Exists(loctestnum, loctesterr, vec, true, 3.3);


        Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
        TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
        TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);

        Fold(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 0.0, 9.9);
        FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 0.0, 9.9);
        FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldMultiply<double>, 1.0, 19.965);

        Map(loctestnum, loctesterr, vec, true, &MapIncrement<double>);
        MapPreOrder(loctestnum, loctesterr, vec, true, &MapIncrement<double>);
        MapPostOrder(loctestnum, loctesterr, vec, true, &MapIncrement<double>);

        lasd::SortableVector<double> chk(vec);
        chk.Sort();
        Sort(loctestnum, loctesterr, vec, chk, true);
        TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
        TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);

        vec.Resize(2);
        FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 1, 11);


        Clear(loctestnum, loctesterr, vec);


    } catch(...) {
        loctestnum++;
        loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }
    cout << "End of Vector<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}

void testVectorString(uint & testnum, uint & testerr) {
    uint loctestnum = 0, loctesterr = 0;
    cout << endl << "Start of Vector<string> Test:" << endl;
    try {
        lasd::SortableVector<string> vec1(3);

        Empty(loctestnum, loctesterr, vec1, false);
        Size(loctestnum, loctesterr, vec1, true, 3);

        SetAt(loctestnum, loctesterr, vec1, true, 0, string("X"));
        SetAt(loctestnum, loctesterr, vec1, true, 1, string("Y"));
        SetAt(loctestnum, loctesterr, vec1, true, 2, string("Z"));

        GetFront(loctestnum, loctesterr, vec1, true, string("X"));
        GetBack(loctestnum, loctesterr, vec1, true, string("Z"));
        GetAt(loctestnum, loctesterr, vec1, true, 2, string("Z"));

        Exists(loctestnum, loctesterr, vec1, true, string("X"));
        Exists(loctestnum, loctesterr, vec1, false, string("A"));

        SetFront(loctestnum, loctesterr, vec1, true, string("S"));
        SetBack(loctestnum, loctesterr, vec1, true, string("A"));

        MapPreOrder(loctestnum, loctesterr, vec1, true, [](string & str) {
            MapStringAppend(str, string(" "));
        });

        Traverse(loctestnum, loctesterr, vec1, true, &TraversePrint<string>);
        TraversePostOrder(loctestnum, loctesterr, vec1, true, &TraversePrint<string>);
        TraversePreOrder(loctestnum, loctesterr, vec1, true, &TraversePrint<string>);

        Fold(loctestnum, loctesterr, vec1, true, &FoldStringConcatenate, string("!"), string("!S Y A "));
        FoldPreOrder(loctestnum, loctesterr, vec1, true, &FoldStringConcatenate, string("!"), string("!S Y A "));
        FoldPostOrder(loctestnum, loctesterr, vec1, true, &FoldStringConcatenate, string("!"), string("!A Y S "));

        Exists(loctestnum, loctesterr, vec1, false, string("A"));

        lasd::SortableVector<string> copvec1(vec1);
        EqualVector(loctestnum, loctesterr, vec1, copvec1, true);
        NonEqualVector(loctestnum, loctesterr, vec1, copvec1, false);

        MapPreOrder(loctestnum, loctesterr, vec1, true, [](string & str) {
            MapStringAppend(str, string("C"));
        });
        MapPostOrder(loctestnum, loctesterr, vec1, true, [](string & str) {
            MapStringAppend(str, string("C"));
        });
        
        NonEqualVector(loctestnum, loctesterr, vec1, copvec1, true);

        copvec1 = move(vec1);
        FoldPreOrder(loctestnum, loctesterr, copvec1, true, &FoldStringConcatenate, string("A"), string("AS CCY CCA CC")); //

        lasd::SortableVector<string> movvec1(move(vec1));
        FoldPreOrder(loctestnum, loctesterr, movvec1, true, &FoldStringConcatenate, string("A"), string("AS Y A ")); //

        lasd::SortableVector<string> check(movvec1);
        movvec1.Sort();
        Sort(loctestnum, loctesterr, check, movvec1, true);
        FoldPreOrder(loctestnum, loctesterr, movvec1, true, &FoldStringConcatenate, string("A"), string("AA S Y ")); //
        SetAt(loctestnum, loctesterr, vec1, false, 1, string(""));
        vec1.Resize(1);
        SetAt(loctestnum, loctesterr, vec1, true, 0, string("X"));

        movvec1.Clear();
        Clear(loctestnum, loctesterr, vec1);
        Empty(loctestnum, loctesterr, movvec1, true);
    } catch(...) {
        loctestnum++;
        loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }
    cout << "End of Vector<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}

void testVector(uint & testnum, uint & testerr) {
    uint loctestnum = 0, loctesterr = 0;
    testVectorDouble(loctestnum, loctesterr);
    testVectorInt(loctestnum, loctesterr);
    testVectorString(loctestnum, loctesterr);
    testnum += loctestnum;
    testerr += loctesterr;
    cout << endl << "Exercise - Vector (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}

/* ************************************************************************** */

void testListInt(uint & testnum, uint & testerr) {
    uint loctestnum = 0, loctesterr = 0;
    cout << endl << "Start of List<int> Test:" << endl;
    try {
        lasd::List<int> list1;
        lasd::List<int> list2;
        list2 = list1;
        Empty(loctestnum, loctesterr, list1, true);
        Size(loctestnum, loctesterr, list1, true, 0);
        EqualList(loctestnum, loctesterr, list1, list2, true);
        Exists(loctestnum, loctesterr, list1, false, 0);

        GetFront(loctestnum, loctesterr, list1, false, 0);
        GetBack(loctestnum, loctesterr, list1, false, 0);

        TraversePreOrder(loctestnum, loctesterr, list1, true, &TraversePrint<int>);
        TraversePostOrder(loctestnum, loctesterr, list1, true, &TraversePrint<int>);
        FoldPreOrder(loctestnum, loctesterr, list1, true, &FoldAdd<int>, 0, 0);
        FoldPostOrder(loctestnum, loctesterr, list1, true, &FoldAdd<int>, 0, 0);

        FrontNRemove(loctestnum, loctesterr, list1, false, 0);
        RemoveFromFront(loctestnum, loctesterr, list1, false);
        

        InsertAtBack(loctestnum, loctesterr, list1, true, 1);
        InsertAtFront(loctestnum, loctesterr, list1, true, 2);
        InsertAtFront(loctestnum, loctesterr, list1, true, 3);
        InsertAtBack(loctestnum, loctesterr, list1, true, 4);
        InsertAtFront(loctestnum, loctesterr, list1, true, 5);
        Traverse(loctestnum, loctesterr, list1, true, &TraversePrint<int>);

        InsertAtFrontM(loctestnum, loctesterr, list1, true, 5);
        RemoveFromFront(loctestnum, loctesterr, list1, true);
        Traverse(loctestnum, loctesterr, list1, true, &TraversePrint<int>);

        InsertAtBackM(loctestnum, loctesterr, list1, true, 5);
        RemoveFromBack(loctestnum, loctesterr, list1, true);
        Traverse(loctestnum, loctesterr, list1, true, &TraversePrint<int>);

        GetFront(loctestnum, loctesterr, list1, true, 5);
        GetFront(loctestnum, loctesterr, list1, false, 7);
        GetBack(loctestnum, loctesterr, list1, true, 4);
        GetBack(loctestnum, loctesterr, list1, false, 8);
        SetFront(loctestnum, loctesterr, list1, true, 2);
        SetBack(loctestnum, loctesterr, list1, true, 6);

        GetAt(loctestnum, loctesterr, list1, true, 3, 1);
        SetAt(loctestnum, loctesterr, list1, true, 3, 8);

        Exists(loctestnum, loctesterr, list1, true, 8);
        Exists(loctestnum, loctesterr, list1, false, 4);

        Traverse(loctestnum, loctesterr, list1, true, &TraversePrint<int>);
        TraversePreOrder(loctestnum, loctesterr, list1, true, &TraversePrint<int>);
        TraversePostOrder(loctestnum, loctesterr, list1, true, &TraversePrint<int>);

        Fold(loctestnum, loctesterr, list1, false, &FoldParity, 0, 0);
        FoldPreOrder(loctestnum, loctesterr, list1, true, &FoldAdd<int>, 0, 21);
        FoldPreOrder(loctestnum, loctesterr, list1, false, &FoldAdd<int>, 0, 37);
        FoldPostOrder(loctestnum, loctesterr, list1, true, &FoldMultiply<int>, 1, 576); //

        RemoveFromFront(loctestnum, loctesterr, list1, true);
        FrontNRemove(loctestnum, loctesterr, list1, false, 9);
        FoldPostOrder(loctestnum, loctesterr, list1, true, &FoldMultiply<int>, 1, 96); 

        lasd::List<int> coplist1(list1);
        EqualList(loctestnum, loctesterr, list1, coplist1, true);
        Map(loctestnum, loctesterr, list1, true, &MapDouble<int>);

        MapPreOrder(loctestnum, loctesterr, list1, true, &MapIncrement<int>);
        NonEqualList(loctestnum, loctesterr, list1, coplist1, true);
        EqualList(loctestnum, loctesterr, list1, coplist1, false);
        Traverse(loctestnum, loctesterr, list1, true, &TraversePrint<int>);

        InsertAtFront(loctestnum, loctesterr, list1, true, 0);
        InsertAtBack(loctestnum, loctesterr, list1, true, 0);
        NonEqualList(loctestnum, loctesterr, list1, coplist1, true);
        coplist1 = list1;
        EqualList(loctestnum, loctesterr, list1, coplist1, true);
        Traverse(loctestnum, loctesterr, coplist1, true, &TraversePrint<int>);
        Traverse(loctestnum, loctesterr, list1, true, &TraversePrint<int>);

        RemoveFromFront(loctestnum, loctesterr, coplist1, true);
        FrontNRemove(loctestnum, loctesterr, coplist1, true, 5);
        coplist1 = move(list1);
        Traverse(loctestnum, loctesterr, coplist1, true, &TraversePrint<int>);
        Traverse(loctestnum, loctesterr, list1, true, &TraversePrint<int>);

        FoldPreOrder(loctestnum, loctesterr, list1, true, &FoldAdd<int>, 0, 30); 
        FoldPreOrder(loctestnum, loctesterr, coplist1, true, &FoldAdd<int>, 0, 35); 

        lasd::List<int> movlist1(move(list1));
        MapPostOrder(loctestnum, loctesterr, movlist1, true, &MapIncrement<int>); 
        Traverse(loctestnum, loctesterr, movlist1, true, &TraversePrint<int>);
        FoldPreOrder(loctestnum, loctesterr, movlist1, false, &FoldAdd<int>, 0, 14); 

        InsertAtFront(loctestnum, loctesterr, movlist1, true, 5);
        InsertAtBack(loctestnum, loctesterr, movlist1, true, 11);
        RemoveFromFront(loctestnum, loctesterr, movlist1, true);
        InsertAtBack(loctestnum, loctesterr, movlist1, true, 9);
        Traverse(loctestnum, loctesterr, movlist1, true, &TraversePrint<int>);

        FoldPreOrder(loctestnum, loctesterr, movlist1, true, &FoldAdd<int>, 1, 54); 
        BackNRemove(loctestnum, loctesterr, movlist1, false, 18); 

        Clear(loctestnum, loctesterr, movlist1);
        Empty(loctestnum, loctesterr, movlist1, true);
        Size(loctestnum, loctesterr, movlist1, true, 0);
    } catch(...) {
        loctestnum++;
        loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }
    cout << "End of List<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}

void testListDouble(uint & testnum, uint & testerr) {
    uint loctestnum = 0, loctesterr = 0;
    cout << endl << "Start of List<double> Test:" << endl;
    try {
        lasd::List<double> list1;
        lasd::List<double> list2;
        list2 = list1;

        EqualList(loctestnum, loctesterr, list1, list2, true);
        Clear(loctestnum, loctesterr, list2);
        Empty(loctestnum, loctesterr, list1, true);
        Size(loctestnum, loctesterr, list1, true, 0);

        GetFront(loctestnum, loctesterr, list1, false, 0.0);
        GetBack(loctestnum, loctesterr, list1, false, 0.0);
        Exists(loctestnum, loctesterr, list1, false, 0.0);

        RemoveFromFront(loctestnum, loctesterr, list1, false);
        FrontNRemove(loctestnum, loctesterr, list1, false, 0.0);

        InsertAtBack(loctestnum, loctesterr, list1, true, -3.5);
        InsertAtBack(loctestnum, loctesterr, list1, true, 3.5);
        SetFront(loctestnum, loctesterr, list1, true, -2.5);
        SetBack(loctestnum, loctesterr, list1, true, 2.5);
        Traverse(loctestnum, loctesterr, list1, true, &TraversePrint<double>);

        list1.Clear();
        InsertAtFrontM(loctestnum, loctesterr, list1, true, 5.1);
        RemoveFromFront(loctestnum, loctesterr, list1, true);
        InsertAtBackM(loctestnum, loctesterr, list1, true, 5.0);
        RemoveFromBack(loctestnum, loctesterr, list1, true);
        InsertAtBack(loctestnum, loctesterr, list1, true, 1.5);
        InsertAtFront(loctestnum, loctesterr, list1, true, 3.3);
        InsertAtFront(loctestnum, loctesterr, list1, true, 5.5);
        InsertAtBack(loctestnum, loctesterr, list1, true, 1.1);
        Traverse(loctestnum, loctesterr, list1, true, &TraversePrint<double>);

        GetAt(loctestnum, loctesterr, list1, true, 3, 1.1);
        SetAt(loctestnum, loctesterr, list1, true, 3, 0.5);



        GetFront(loctestnum, loctesterr, list1, true, 5.5);
        GetBack(loctestnum, loctesterr, list1, false, 1.1);

        Exists(loctestnum, loctesterr, list1, false, 0.0);

        TraversePreOrder(loctestnum, loctesterr, list1, true, &TraversePrint<double>);
        TraversePostOrder(loctestnum, loctesterr, list1, true, &TraversePrint<double>);
        Traverse(loctestnum, loctesterr, list1, true, &TraversePrint<double>);

        Fold(loctestnum, loctesterr, list1, false, &FoldAdd<double>, 0, 0);
        FoldPreOrder(loctestnum, loctesterr, list1, true, &FoldAdd<double>, 0.0, 10.8);
        FoldPostOrder(loctestnum, loctesterr, list1, false, &FoldMultiply<double>, 1.0, 9.9825);

        lasd::List<double> coplist1(list1);
        EqualList(loctestnum, loctesterr, list1, coplist1, true);
        Traverse(loctestnum, loctesterr, list1, true, &TraversePrint<double>);

        Map(loctestnum, loctesterr, list1, true, &MapHalf<double>);
        Traverse(loctestnum, loctesterr, list1, true, &TraversePrint<double>);
        NonEqualList(loctestnum, loctesterr, list1, coplist1, true);
        BackNRemove(loctestnum, loctesterr, coplist1, true, 0.5);
        Traverse(loctestnum, loctesterr, list1, true, &TraversePrint<double>);
        Traverse(loctestnum, loctesterr, coplist1, true, &TraversePrint<double>);
        MapPostOrder(loctestnum, loctesterr, coplist1, true, &MapIncrement<double>);
        lasd::List<double> movlist1(move(coplist1));
        MapPreOrder(loctestnum, loctesterr, movlist1, true, &MapInvert<double>);

        Traverse(loctestnum, loctesterr, movlist1, true, &TraversePrint<double>);
        Clear(loctestnum, loctesterr, movlist1);
    } catch(...) {
        loctestnum++;
        loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }
    cout << "End of List<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}

void testListString(uint & testnum, uint & testerr) {
    uint loctestnum = 0, loctesterr = 0;
    cout << endl << "Start of List<string> Test:" << endl;
    try {
        lasd::List<string> list1;
        lasd::List<string> list2;
        list2 = list1;

        EqualList(loctestnum, loctesterr, list1, list2, true);
        Clear(loctestnum, loctesterr, list2);
        Empty(loctestnum, loctesterr, list1, true);
        Size(loctestnum, loctesterr, list1, true, 0);

        GetFront(loctestnum, loctesterr, list1, false, string("F"));
        GetBack(loctestnum, loctesterr, list1, false, string("F"));
        Exists(loctestnum, loctesterr, list1, false, string("F"));

        RemoveFromFront(loctestnum, loctesterr, list1, false);
        FrontNRemove(loctestnum, loctesterr, list1, false, string("F"));

        InsertAtFront(loctestnum, loctesterr, list1, true, string("S"));
        InsertAtBack(loctestnum, loctesterr, list1, true, string("A"));
        SetFront(loctestnum, loctesterr, list1, true, string("S"));
        SetBack(loctestnum, loctesterr, list1, true, string("A"));
        Traverse(loctestnum, loctesterr, list1, true, &TraversePrint<string>);
        GetFront(loctestnum, loctesterr, list1, true, string("S"));
        GetBack(loctestnum, loctesterr, list1, true, string("A"));

        Exists(loctestnum, loctesterr, list1, true, string("A"));

        InsertAtFrontM(loctestnum, loctesterr, list1, true, string("front"));
        RemoveFromFront(loctestnum, loctesterr, list1, true);
        InsertAtBackM(loctestnum, loctesterr, list1, true,  string("back"));
        GetAt(loctestnum, loctesterr, list1, true, 2, string("back"));
        SetAt(loctestnum, loctesterr, list1, true, 2, string("B"));
        RemoveFromBack(loctestnum, loctesterr, list1, true);

        MapPreOrder(loctestnum, loctesterr, list1, true, [](string & str) {
            MapStringAppend(str, string(" "));
        });
        TraversePreOrder(loctestnum, loctesterr, list1, true, &TraversePrint<string>);
        FoldPreOrder(loctestnum, loctesterr, list1, true, &FoldStringConcatenate, string("F"), string("FS A "));
        FoldPostOrder(loctestnum, loctesterr, list1, true, &FoldStringConcatenate, string("F"), string("FA S "));

        Exists(loctestnum, loctesterr, list1, false, string("S"));

        lasd::List<string> coplist1(list1);
        EqualList(loctestnum, loctesterr, list1, coplist1, true);
        RemoveFromFront(loctestnum, loctesterr, coplist1, true);
        NonEqualList(loctestnum, loctesterr, list1, coplist1, true);

        list1 = coplist1;
        EqualList(loctestnum, loctesterr, list1, coplist1, true);
        InsertAtBack(loctestnum, loctesterr, list1, true, string("A"));
        InsertAtFront(loctestnum, loctesterr, list1, true, string("C"));
        NonEqualList(loctestnum, loctesterr, list1, coplist1, true);

        coplist1 = move(list1);
        FoldPreOrder(loctestnum, loctesterr, coplist1, true, &FoldStringConcatenate, string("?"), string("?CA A"));
        MapPostOrder(loctestnum, loctesterr, coplist1, true, [](string & str) {
            MapStringNonEmptyAppend(str, string("A"));
        });
        Map(loctestnum, loctesterr, coplist1, true, [](string & str) {
            MapStringNonEmptyAppend(str, string("A"));
        });
        Traverse(loctestnum, loctesterr, coplist1, true, &TraversePrint<string>);
        Clear(loctestnum, loctesterr, coplist1);

    } catch(...) {
        loctestnum++;
        loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }
    cout << "End of List<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}

void testList(uint & testnum, uint & testerr) {
    uint loctestnum = 0, loctesterr = 0;
    testListString(loctestnum, loctesterr);
    testListDouble(loctestnum, loctesterr);
    testListInt(loctestnum, loctesterr);
    testnum += loctestnum;
    testerr += loctesterr;
    cout << endl << "Exercise - List (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}
/* ************************************************************************** */
void testSetInt(lasd::Set<int> & set1, uint & testnum, uint & testerr) {
    uint loctestnum = 0, loctesterr = 0;
    try {
        Traverse(loctestnum, loctesterr, set1, true, &TraversePrint<int>);

        Empty(loctestnum, loctesterr, set1, false);
        Size(loctestnum, loctesterr, set1, true, 7);

        GetAt(loctestnum, loctesterr, set1, true, 0, 0);
        GetBack(loctestnum, loctesterr, set1, false, 0);
        GetFront(loctestnum, loctesterr, set1, false, 6);
        GetBack(loctestnum, loctesterr, set1, false, 9);

        Traverse(loctestnum, loctesterr, set1, true, &TraversePrint<int>);
        TraversePreOrder(loctestnum, loctesterr, set1, true, &TraversePrint<int>);
        TraversePostOrder(loctestnum, loctesterr, set1, true, &TraversePrint<int>);

        Min(loctestnum, loctesterr, set1, true, 0);
        Max(loctestnum, loctesterr, set1, true, 6);

        RemoveMin(loctestnum, loctesterr, set1, true);
        MinNRemove(loctestnum, loctesterr, set1, true, 1);

        InsertC(loctestnum, loctesterr, set1, true, -1);
        InsertC(loctestnum, loctesterr, set1, true, 1);

        Min(loctestnum, loctesterr, set1, true, -1);
        MaxNRemove(loctestnum, loctesterr, set1, true, 6);
        Size(loctestnum, loctesterr, set1, true, 6);

        InsertC(loctestnum, loctesterr, set1, true, 7);

        Size(loctestnum, loctesterr, set1, true, 7);

        Max(loctestnum, loctesterr, set1, true, 7);

        InsertC(loctestnum, loctesterr, set1, true, 8);

        Size(loctestnum, loctesterr, set1, true, 8);

        Exists(loctestnum, loctesterr, set1, true, 8);
        Exists(loctestnum, loctesterr, set1, false, 9);
        Exists(loctestnum, loctesterr, set1, false, 0);
        Exists(loctestnum, loctesterr, set1, true, -1);
        Exists(loctestnum, loctesterr, set1, true, 3);
        Exists(loctestnum, loctesterr, set1, true, 4);
        InsertC(loctestnum, loctesterr, set1, true, 9);

        Exists(loctestnum, loctesterr, set1, true, 4);
        Remove(loctestnum, loctesterr, set1, true, 9);
        InsertC(loctestnum, loctesterr, set1, true, 6);
        Remove(loctestnum, loctesterr, set1, true, 6);

        TraversePreOrder(loctestnum, loctesterr, set1, true, &TraversePrint<int>);
        TraversePostOrder(loctestnum, loctesterr, set1, true, &TraversePrint<int>);

        Remove(loctestnum, loctesterr, set1, false, 6);
        Remove(loctestnum, loctesterr, set1, true, 2);

        TraversePreOrder(loctestnum, loctesterr, set1, true, &TraversePrint<int>);
        TraversePostOrder(loctestnum, loctesterr, set1, true, &TraversePrint<int>);

        Exists(loctestnum, loctesterr, set1, false, 6);
        Exists(loctestnum, loctesterr, set1, false, 2);

        RemoveMax(loctestnum, loctesterr, set1, true);
        Max(loctestnum, loctesterr, set1, true, 7);

        TraversePreOrder(loctestnum, loctesterr, set1, true, &TraversePrint<int>);

        Predecessor(loctestnum, loctesterr, set1, true, 4, 3);
        Predecessor(loctestnum, loctesterr, set1, true, 5, 4);

        Successor(loctestnum, loctesterr, set1, true, 2, 3);
        Successor(loctestnum, loctesterr, set1, true, 4, 5);

        SuccessorNRemove(loctestnum, loctesterr, set1, true, 0, 1);
        Min(loctestnum, loctesterr, set1, true, -1);

        TraversePreOrder(loctestnum, loctesterr, set1, true, &TraversePrint<int>);

        PredecessorNRemove(loctestnum, loctesterr, set1, true, 7, 5);
        TraversePreOrder(loctestnum, loctesterr, set1, true, &TraversePrint<int>);

        Max(loctestnum, loctesterr, set1, true, 7);

        TraversePostOrder(loctestnum, loctesterr, set1, true, &TraversePrint<int>);

        Fold(loctestnum, loctesterr, set1, true, &FoldAdd<int>, 0, 13);
        FoldPreOrder(loctestnum, loctesterr, set1, true, &FoldAdd<int>, 0, 13);
        FoldPostOrder(loctestnum, loctesterr, set1, true, &FoldAdd<int>, 0, 13);

        TraversePreOrder(loctestnum, loctesterr, set1, true, &TraversePrint<int>);
        TraversePostOrder(loctestnum, loctesterr, set1, true, &TraversePrint<int>);
        RemovePredecessor(loctestnum, loctesterr, set1, false, -18);
        RemovePredecessor(loctestnum, loctesterr, set1, true, 4);
        RemovePredecessor(loctestnum, loctesterr, set1, true, 0);
        Traverse(loctestnum, loctesterr, set1, true, &TraversePrint<int>);

        RemoveSuccessor(loctestnum, loctesterr, set1, false, 28);
        RemoveSuccessor(loctestnum, loctesterr, set1, true, 4);


        Clear(loctestnum, loctesterr, set1);
        Clear(loctestnum, loctesterr, set1);
        InsertM(loctestnum, loctesterr, set1, true, move(1));
        InsertC(loctestnum, loctesterr, set1, true, 3);
        InsertC(loctestnum, loctesterr, set1, true, -1);
        InsertC(loctestnum, loctesterr, set1, false, -1);

        Traverse(loctestnum, loctesterr, set1, true, &TraversePrint<int>);
        lasd::List<int> list1;
        InsertAllC(loctestnum, loctesterr, set1, true, list1);

        list1.InsertAtBack(4);
        list1.InsertAtFront(5);
        list1.InsertAtFront(9);
        list1.InsertAtFront(1);
        list1.InsertAtBack(2);

        InsertAllC(loctestnum, loctesterr, set1, false, list1);
        lasd::List<int> list2;
        list2.InsertAtFront(12);
        list2.InsertAtFront(13);
        list2.InsertAtFront(14);

        InsertAllM(loctestnum, loctesterr, set1, true, move(list2));

        Remove(loctestnum, loctesterr, set1, true, -1);
        Remove(loctestnum, loctesterr, set1, true, 1);
        Remove(loctestnum, loctesterr, set1, false, 120);

        RemoveAll(loctestnum, loctesterr, set1, false, list1);
        Traverse(loctestnum, loctesterr, set1, true, &TraversePrint<int>);


        list2.Clear();
        list2.InsertAtFront(3);
        list2.InsertAtFront(120);

        InsertSomeC(loctestnum, loctesterr, set1, true, list2);
        list2.InsertAtFront(130);


        InsertSomeC(loctestnum, loctesterr, set1, true, move(list2));
        Traverse(loctestnum, loctesterr, set1, true, &TraversePrint<int>);
        list1.Front() = 12;
        list1.Back() = 130;

        RemoveSome(loctestnum, loctesterr, set1, true, list1);
        Traverse(loctestnum, loctesterr, set1, true, &TraversePrint<int>);
        Clear(loctestnum, loctesterr, set1);

        Empty(loctestnum, loctesterr, set1, true);
        Size(loctestnum, loctesterr, set1, true, 0);

    } catch(...) {
        loctestnum++;
        loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }
    cout << "End of Set<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}

void testSetInt(uint & testnum, uint & testerr) {
    uint loctestnum = 0, loctesterr = 0;
    cout << endl << "Start of Set<int> Test" << endl;
    try {
        lasd::Vector<int> vec1(7);
        SetAt(loctestnum, loctesterr, vec1, true, 0, 4);
        SetAt(loctestnum, loctesterr, vec1, true, 1, 2);
        SetAt(loctestnum, loctesterr, vec1, true, 2, 0);
        SetAt(loctestnum, loctesterr, vec1, true, 3, 5);
        SetAt(loctestnum, loctesterr, vec1, true, 4, 6);
        SetAt(loctestnum, loctesterr, vec1, true, 5, 1);
        SetAt(loctestnum, loctesterr, vec1, true, 6, 3);

        /* ********************************************************************** */

        cout << endl << "Start of SetVec<int> Test:" << endl;
        lasd::SetVec<int> setvec1(vec1);


        testSetInt(setvec1, loctestnum, loctesterr);
        cout << endl << "Start of SetLst<int> Test:" << endl;
        lasd::SetLst<int> setlist1(vec1);
        testSetInt(setlist1, loctestnum, loctesterr);
        cout << "\n";

        /* ***********************************************************************/

        setvec1.InsertAll(vec1);
        lasd::SetVec<int> setvec2(setvec1);
        Traverse(loctestnum, loctesterr, setvec1, true, &TraversePrint<int>);
        Traverse(loctestnum, loctesterr, setvec2, true, &TraversePrint<int>);
        EqualSetVec(loctestnum, loctesterr, setvec1, setvec2, true);

        Remove(loctestnum, loctesterr, setvec2, true, 4);

        NonEqualSetVec(loctestnum, loctesterr, setvec1, setvec2, true);
        Traverse(loctestnum, loctesterr, setvec1, true, &TraversePrint<int>);
        Traverse(loctestnum, loctesterr, setvec2, true, &TraversePrint<int>);

        InsertC(loctestnum, loctesterr, setvec2, true, 4);

        EqualSetVec(loctestnum, loctesterr, setvec1, setvec2, true);
        NonEqualSetVec(loctestnum, loctesterr, setvec1, setvec2, false);

        lasd::SetVec<int> setvec3 = setvec2;

        EqualSetVec(loctestnum, loctesterr, setvec2, setvec3, true);

        RemovePredecessor(loctestnum, loctesterr, setvec2, true, 9);

        EqualSetVec(loctestnum, loctesterr, setvec2, setvec3, false);

        lasd::SetVec<int> setvec4(move(setvec3));

        Empty(loctestnum, loctesterr, setvec3, true);
        Size(loctestnum, loctesterr, setvec3, true, 0);

        Empty(loctestnum, loctesterr, setvec4, false);
        Size(loctestnum, loctesterr, setvec4, true, 7);

        setvec3 = move(setvec2);

        Empty(loctestnum, loctesterr, setvec2, true);
        Size(loctestnum, loctesterr, setvec2, true, 0);

        Empty(loctestnum, loctesterr, setvec3, false);
        Size(loctestnum, loctesterr, setvec3, true, 6);

        NonEqualSetVec(loctestnum, loctesterr, setvec4, setvec3, true);

        Traverse(loctestnum, loctesterr, setvec3, true, &TraversePrint<int>);
        Traverse(loctestnum, loctesterr, setvec4, true, &TraversePrint<int>);

        InsertC(loctestnum, loctesterr, setvec3, true, 6);

        EqualSetVec(loctestnum, loctesterr, setvec4, setvec3, true);

        /* ********************************************************************** */

        setlist1.InsertAll(vec1);
        lasd::SetLst<int> setlist2(setlist1);

        EqualSetLst(loctestnum, loctesterr, setlist1, setlist2, true);

        Remove(loctestnum, loctesterr, setlist2, true, 4);

        NonEqualSetLst(loctestnum, loctesterr, setlist1, setlist2, true);

        InsertC(loctestnum, loctesterr, setlist2, true, 4);

        EqualSetLst(loctestnum, loctesterr, setlist1, setlist2, true);

        lasd::SetLst<int> setlist3 = setlist2;

        EqualSetLst(loctestnum, loctesterr, setlist2, setlist3, true);

        RemovePredecessor(loctestnum, loctesterr, setlist2, true, 9);

        EqualSetLst(loctestnum, loctesterr, setlist2, setlist3, false);

        lasd::SetLst<int> setlist4(move(setlist3));

        Empty(loctestnum, loctesterr, setlist4, false);
        Size(loctestnum, loctesterr, setlist4, false, 0);

        Empty(loctestnum, loctesterr, setlist3, true);
        Size(loctestnum, loctesterr, setlist3, false, 7);

        setlist4 = move(setlist3);

        Empty(loctestnum, loctesterr, setlist3, false);
        Size(loctestnum, loctesterr, setlist3, false, 0);

        Empty(loctestnum, loctesterr, setlist4, true);
        Size(loctestnum, loctesterr, setlist4, false, 6);

        NonEqualSetLst(loctestnum, loctesterr, setlist3, setlist4, true);

        Traverse(loctestnum, loctesterr, setlist3, true, &TraversePrint<int>);
        Traverse(loctestnum, loctesterr, setlist4, true, &TraversePrint<int>);

        InsertC(loctestnum, loctesterr, setlist4, true, 6);

        EqualSetLst(loctestnum, loctesterr, setlist4, setlist3, false);

        /* ********************************************************************** */

        EqualLinear(loctestnum, loctesterr, setvec3, setlist3, true);
        NonEqualLinear(loctestnum, loctesterr, setvec3, setlist3, false);
        NonEqualLinear(loctestnum, loctesterr, setlist3, setvec3, false);

    } catch(...) {
        loctestnum++;
        loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }
    cout << "End of Set<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}

void testSetFloat(lasd::Set<double> & set1, uint & testnum, uint & testerr) {
    uint loctestnum = 0, loctesterr = 0;
    try {
        cout << endl << "Start of Set<Float> Test" << endl << endl;

        Traverse(loctestnum, loctesterr, set1, true, &TraversePrint<double>);

        Empty(loctestnum, loctesterr, set1, false);
        Size(loctestnum, loctesterr, set1, true, 6);

        GetAt(loctestnum, loctesterr, set1, true, 3, 3.5);
        GetFront(loctestnum, loctesterr, set1, true, 0.4);
        GetBack(loctestnum, loctesterr, set1, false, 5.4);

        Traverse(loctestnum, loctesterr, set1, true, &TraversePrint<double>);
        TraversePreOrder(loctestnum, loctesterr, set1, true, &TraversePrint<double>);
        TraversePostOrder(loctestnum, loctesterr, set1, true, &TraversePrint<double>);

        Max(loctestnum, loctesterr, set1, false, 6.1);
        Min(loctestnum, loctesterr, set1, true, 0.4);

        RemoveMin(loctestnum, loctesterr, set1, true);
        MinNRemove(loctestnum, loctesterr, set1, true, 1.2);

        InsertC(loctestnum, loctesterr, set1, true, -1.1);
        InsertC(loctestnum, loctesterr, set1, true, 1.0);

        Min(loctestnum, loctesterr, set1, true, -1.1);
        MaxNRemove(loctestnum, loctesterr, set1, false, 6.0);
        Size(loctestnum, loctesterr, set1, true, 5);

        InsertC(loctestnum, loctesterr, set1, true, 7.0);

        Size(loctestnum, loctesterr, set1, false, 7);

        Max(loctestnum, loctesterr, set1, true, 7.0);

        InsertC(loctestnum, loctesterr, set1, true, 8.4);

        Size(loctestnum, loctesterr, set1, true, 7);

        Exists(loctestnum, loctesterr, set1, true, 8.4);
        Exists(loctestnum, loctesterr, set1, false, 9.0);
        Exists(loctestnum, loctesterr, set1, false, 0.0);

        TraversePostOrder(loctestnum, loctesterr, set1, true, &TraversePrint<double>);
        TraversePreOrder(loctestnum, loctesterr, set1, true, &TraversePrint<double>);

        Remove(loctestnum, loctesterr, set1, true, -1.1);
        Remove(loctestnum, loctesterr, set1, false, 6.0);

        TraversePreOrder(loctestnum, loctesterr, set1, true, &TraversePrint<double>);
        TraversePostOrder(loctestnum, loctesterr, set1, true, &TraversePrint<double>);

        Exists(loctestnum, loctesterr, set1, false, 6.0);
        Exists(loctestnum, loctesterr, set1, false, 2.0);

        RemoveMax(loctestnum, loctesterr, set1, true);
        Max(loctestnum, loctesterr, set1, true, 7.0);

        TraversePreOrder(loctestnum, loctesterr, set1, true, &TraversePrint<double>);

        Predecessor(loctestnum, loctesterr, set1, true, 4.0, 3.5);
        Predecessor(loctestnum, loctesterr, set1, true, 4.9, 4.0);

        Successor(loctestnum, loctesterr, set1, true, 1.6, 2.1);
        Successor(loctestnum, loctesterr, set1, true, 4.0, 7.0);

        SuccessorNRemove(loctestnum, loctesterr, set1, true, 0.0, 1.0);
        Min(loctestnum, loctesterr, set1, true, 2.1);

        TraversePreOrder(loctestnum, loctesterr, set1, true, &TraversePrint<double>);

        PredecessorNRemove(loctestnum, loctesterr, set1, true, 7.0, 4.0);
        Max(loctestnum, loctesterr, set1, true, 7.0);

        TraversePostOrder(loctestnum, loctesterr, set1, true, &TraversePrint<double>);

        Fold(loctestnum, loctesterr, set1, true, &FoldAdd<double>, 0.0, 12.6);
        FoldPreOrder(loctestnum, loctesterr, set1, true, &FoldAdd<double>, 0.0, 12.6);
        FoldPostOrder(loctestnum, loctesterr, set1, false, &FoldAdd<double>, 0.0, 11.5);

        TraversePreOrder(loctestnum, loctesterr, set1, true, &TraversePrint<double>);
        TraversePostOrder(loctestnum, loctesterr, set1, true, &TraversePrint<double>);
        RemovePredecessor(loctestnum, loctesterr, set1, false, -3.0);
        RemovePredecessor(loctestnum, loctesterr, set1, true, 4.0);
        RemovePredecessor(loctestnum, loctesterr, set1, false, 0.0);
        Traverse(loctestnum, loctesterr, set1, true, &TraversePrint<double>);

        RemoveSuccessor(loctestnum, loctesterr, set1, false, 7.0);
        RemoveSuccessor(loctestnum, loctesterr, set1, true, 4.0);
        RemoveSuccessor(loctestnum, loctesterr, set1, false, 19.0);


        Clear(loctestnum, loctesterr, set1);
        Clear(loctestnum, loctesterr, set1);
        InsertM(loctestnum, loctesterr, set1, true, move(1.0));
        InsertC(loctestnum, loctesterr, set1, true, 3.0);
        InsertC(loctestnum, loctesterr, set1, true, -1.0);
        InsertC(loctestnum, loctesterr, set1, false, -1.0);

        Traverse(loctestnum, loctesterr, set1, true, &TraversePrint<double>);
        lasd::List<double> list1;
        InsertAllC(loctestnum, loctesterr, set1, true, list1);

        list1.InsertAtBack(4.0);
        list1.InsertAtFront(5.0);
        list1.InsertAtFront(9.0);
        list1.InsertAtFront(1.0);
        list1.InsertAtBack(2.0);

        InsertAllC(loctestnum, loctesterr, set1, false, list1);
        lasd::List<double> list2;
        list2.InsertAtFront(12.0);
        list2.InsertAtFront(13.0);
        list2.InsertAtFront(14.0);

        InsertAllM(loctestnum, loctesterr, set1, true, move(list2));

        Remove(loctestnum, loctesterr, set1, true, -1.0);
        Remove(loctestnum, loctesterr, set1, true, 1.0);
        Remove(loctestnum, loctesterr, set1, false, 120.0);

        RemoveAll(loctestnum, loctesterr, set1, false, list1);
        Traverse(loctestnum, loctesterr, set1, true, &TraversePrint<double>);


        list2.Clear();
        list2.InsertAtFront(3.0);
        list2.InsertAtFront(120.0);

        InsertSomeC(loctestnum, loctesterr, set1, true, list2);
        list2.InsertAtFront(121.0);


        InsertSomeC(loctestnum, loctesterr, set1, true, move(list2));
        Traverse(loctestnum, loctesterr, set1, true, &TraversePrint<double>);
        list2.Front() = 12.0;
        list2.Back() = 121.0;

        RemoveSome(loctestnum, loctesterr, set1, true, list2);
        Traverse(loctestnum, loctesterr, set1, true, &TraversePrint<double>);
        Clear(loctestnum, loctesterr, set1);

        Empty(loctestnum, loctesterr, set1, true);
        Size(loctestnum, loctesterr, set1, true, 0);

    } catch(...) {
        loctestnum++;
        loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }
    cout << "End of Set<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}

void testSetFloat(uint & testnum, uint & testerr) {
    uint loctestnum = 0, loctesterr = 0;
    cout << endl << "Begin of Set<double> Test" << endl;
    try {
        lasd::List<double> lst;
        InsertAtFront(loctestnum, loctesterr, lst, true, 4.0);
        InsertAtBack(loctestnum, loctesterr, lst, true, 0.4);
        InsertAtFront(loctestnum, loctesterr, lst, true, 1.2);
        InsertAtBack(loctestnum, loctesterr, lst, true, 2.1);
        InsertAtFront(loctestnum, loctesterr, lst, true, 3.5);
        InsertAtBack(loctestnum, loctesterr, lst, true, 5.3);

        TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);

        /* ***********************************************************************/

        lasd::SetVec<double> setvec1(lst);
        cout << endl << "Begin of SetVec<double> Test:" << endl;

        testSetFloat(setvec1, loctestnum, loctesterr);
        InsertAllC(loctestnum, loctesterr, setvec1, true, lst);
        Empty(loctestnum, loctesterr, setvec1, false);
        Size(loctestnum, loctesterr, setvec1, true, 6);

        TraversePreOrder(loctestnum, loctesterr, setvec1, true, &TraversePrint<double>);
        TraversePostOrder(loctestnum, loctesterr, setvec1, true, &TraversePrint<double>);

        lasd::SetVec<double> setvec2;

        InsertC(loctestnum, loctesterr, setvec2, true, 2.1);
        InsertC(loctestnum, loctesterr, setvec2, true, 0.4);
        InsertC(loctestnum, loctesterr, setvec2, true, 1.2);
        InsertC(loctestnum, loctesterr, setvec2, true, 3.5);
        InsertC(loctestnum, loctesterr, setvec2, true, 5.3);
        InsertC(loctestnum, loctesterr, setvec2, true, 4.0);

        EqualSetVec(loctestnum, loctesterr, setvec1, setvec2, true);
        NonEqualSetVec(loctestnum, loctesterr, setvec1, setvec2, false);

        setvec1.Clear();
        setvec2.Clear();

        InsertC(loctestnum, loctesterr, setvec1, true, 0.2);
        InsertC(loctestnum, loctesterr, setvec1, true, 1.1);
        InsertC(loctestnum, loctesterr, setvec1, true, 2.1);

        InsertC(loctestnum, loctesterr, setvec2, true, 2.1);
        InsertC(loctestnum, loctesterr, setvec2, true, 1.1);
        InsertC(loctestnum, loctesterr, setvec2, true, 0.2);

        EqualSetVec(loctestnum, loctesterr, setvec1, setvec2, true);
        NonEqualSetVec(loctestnum, loctesterr, setvec1, setvec2, false);

        /* ********************************************************************** */

        lasd::SetLst<double> setlst1(lst);
        cout << endl << "Start of SetList<double> Test:" << endl;

        testSetFloat(setlst1, loctestnum, loctesterr);
        InsertAllC(loctestnum, loctesterr, setlst1, true, lst);
        Empty(loctestnum, loctesterr, setlst1, false);
        Size(loctestnum, loctesterr, setlst1, true, 6);

        TraversePreOrder(loctestnum, loctesterr, setlst1, true, &TraversePrint<double>);
        TraversePostOrder(loctestnum, loctesterr, setlst1, true, &TraversePrint<double>);

        lasd::SetLst<double> setlst2;

        InsertC(loctestnum, loctesterr, setlst2, true, 2.1);
        InsertC(loctestnum, loctesterr, setlst2, true, 0.4);
        InsertC(loctestnum, loctesterr, setlst2, true, 1.2);
        InsertC(loctestnum, loctesterr, setlst2, true, 3.5);
        InsertC(loctestnum, loctesterr, setlst2, true, 5.3);
        InsertC(loctestnum, loctesterr, setlst2, true, 4.0);


        EqualSetLst(loctestnum, loctesterr, setlst1, setlst2, true);
        NonEqualSetLst(loctestnum, loctesterr, setlst1, setlst2, false);

        setlst1.Clear();
        setlst2.Clear();

        InsertC(loctestnum, loctesterr, setlst1, true, 0.2);
        InsertC(loctestnum, loctesterr, setlst1, true, 1.1);
        InsertC(loctestnum, loctesterr, setlst1, true, 2.1);

        InsertC(loctestnum, loctesterr, setlst2, true, 2.1);
        InsertC(loctestnum, loctesterr, setlst2, true, 1.1);
        InsertC(loctestnum, loctesterr, setlst2, true, 0.2);

        EqualSetLst(loctestnum, loctesterr, setlst1, setlst2, true);
        NonEqualSetLst(loctestnum, loctesterr, setlst1, setlst2, false);


        /* ********************************************************************** */

        EqualLinear(loctestnum, loctesterr, setvec1, setlst2, true);
        NonEqualLinear(loctestnum, loctesterr, setlst2, setvec2, false);
    } catch(...) {
        loctestnum++;
        loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }
    cout << "End of Set<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}

void testSetString(lasd::Set<string> & set1, uint & testnum, uint & testerr) {
    uint loctestnum = 0, loctesterr = 0;
    try {


        Traverse(loctestnum, loctesterr, set1, true, &TraversePrint<string>);


        Empty(loctestnum, loctesterr, set1, false);
        Size(loctestnum, loctesterr, set1, true, 5);

        GetAt(loctestnum, loctesterr, set1, true,  0, string("A"));
        GetBack(loctestnum, loctesterr, set1, false, string("B"));
        GetFront(loctestnum, loctesterr, set1, false, string("N"));

        Traverse(loctestnum, loctesterr, set1, true, &TraversePrint<string>);
        TraversePreOrder(loctestnum, loctesterr, set1, true, &TraversePrint<string>);
        TraversePostOrder(loctestnum, loctesterr, set1, true, &TraversePrint<string>);

        Min(loctestnum, loctesterr, set1, true,  string("A"));
        Max(loctestnum, loctesterr, set1, true,  string("E"));

        RemoveMin(loctestnum, loctesterr, set1, true);
        MinNRemove(loctestnum, loctesterr, set1, true,  string("B"));

        InsertC(loctestnum, loctesterr, set1, true,  string("A"));
        InsertC(loctestnum, loctesterr, set1, true,  string("B"));

        Min(loctestnum, loctesterr, set1, true,  string("A"));
        MaxNRemove(loctestnum, loctesterr, set1, true, string("E"));
        Size(loctestnum, loctesterr, set1, true,  4);

        InsertC(loctestnum, loctesterr, set1, true,  string("Z"));
        Size(loctestnum, loctesterr, set1, true,  5);
        Max(loctestnum, loctesterr, set1, true,  string("Z"));

        InsertC(loctestnum, loctesterr, set1, true,  string("Q"));
        Size(loctestnum, loctesterr, set1, true,  6);


        Exists(loctestnum, loctesterr, set1, true,  string("A"));
        Exists(loctestnum, loctesterr, set1, false, string("N"));
        Exists(loctestnum, loctesterr, set1, false, string("S"));
        Exists(loctestnum, loctesterr, set1, true,  string("Z"));
        Exists(loctestnum, loctesterr, set1, true,  string("Q"));

        TraversePreOrder(loctestnum, loctesterr, set1, true, &TraversePrint<string>);
        TraversePostOrder(loctestnum, loctesterr, set1, true, &TraversePrint<string>);

        Remove(loctestnum, loctesterr, set1, false, string("c"));
        Remove(loctestnum, loctesterr, set1, true,  string("D"));

        TraversePreOrder(loctestnum, loctesterr, set1, true, &TraversePrint<string>);
        TraversePostOrder(loctestnum, loctesterr, set1, true, &TraversePrint<string>);

        Exists(loctestnum, loctesterr, set1, false, string("c"));
        Exists(loctestnum, loctesterr, set1, false, string("D"));

        RemoveMax(loctestnum, loctesterr, set1, true);
        Max(loctestnum, loctesterr, set1, true, string("Q"));

        TraversePreOrder(loctestnum, loctesterr, set1, true, &TraversePrint<string>);

        Predecessor(loctestnum, loctesterr, set1, true, string("C"), string("B"));
        Predecessor(loctestnum, loctesterr, set1, false, string("A"), string("B"));

        Successor(loctestnum, loctesterr, set1, true, string("C"), string("Q"));
        Successor(loctestnum, loctesterr, set1, false,  string("Q"), string("B"));

        SuccessorNRemove(loctestnum, loctesterr, set1, true, string("C"), string("Q"));
        Min(loctestnum, loctesterr, set1, true, string("A"));

        TraversePreOrder(loctestnum, loctesterr, set1, true, &TraversePrint<string>);

        PredecessorNRemove(loctestnum, loctesterr, set1, true, string("Z"), string("C"));
        Max(loctestnum, loctesterr, set1, true, string("B"));

        TraversePostOrder(loctestnum, loctesterr, set1, true, &TraversePrint<string>);

        FoldPreOrder(loctestnum, loctesterr, set1, true, &FoldStringConcatenate, string("?"), string("?AB"));
        FoldPostOrder(loctestnum, loctesterr, set1, true, &FoldStringConcatenate, string("?"), string("?BA"));

        TraversePreOrder(loctestnum, loctesterr, set1, true, &TraversePrint<string>);
        TraversePostOrder(loctestnum, loctesterr, set1, true, &TraversePrint<string>);

        InsertM(loctestnum, loctesterr, set1, true, move(string("Z")));
        InsertC(loctestnum, loctesterr, set1, true, string("M"));
        InsertC(loctestnum, loctesterr, set1, true, string("N"));
        InsertC(loctestnum, loctesterr, set1, false, string("M"));

        RemovePredecessor(loctestnum, loctesterr, set1, false, string("A"));
        RemovePredecessor(loctestnum, loctesterr, set1, true, string("Z"));
        RemovePredecessor(loctestnum, loctesterr, set1, true, string("M"));
        Traverse(loctestnum, loctesterr, set1, true, &TraversePrint<string>);

        RemoveSuccessor(loctestnum, loctesterr, set1, false, string("Z"));
        RemoveSuccessor(loctestnum, loctesterr, set1, true, string("C"));


        Clear(loctestnum, loctesterr, set1);
        Clear(loctestnum, loctesterr, set1);

        InsertM(loctestnum, loctesterr, set1, true, move(string("A")));
        InsertC(loctestnum, loctesterr, set1, true, string("B"));
        InsertC(loctestnum, loctesterr, set1, true, string("C"));
        InsertC(loctestnum, loctesterr, set1, false, string("C"));

        Traverse(loctestnum, loctesterr, set1, true, &TraversePrint<string>);
        lasd::List<string> list1;
        InsertAllC(loctestnum, loctesterr, set1, true, list1);

        list1.InsertAtBack(string("C"));
        list1.InsertAtFront(string("X"));
        list1.InsertAtFront(string("V"));
        list1.InsertAtFront(string("N"));
        list1.InsertAtBack(string("L"));

        InsertAllC(loctestnum, loctesterr, set1, false, list1);
        lasd::List<string> list2;
        list2.InsertAtFront(string("J"));
        list2.InsertAtFront(string("K"));
        list2.InsertAtFront(string("O"));

        InsertAllM(loctestnum, loctesterr, set1, true, move(list2));
        Traverse(loctestnum, loctesterr, set1, true, &TraversePrint<string>);

        Remove(loctestnum, loctesterr, set1, true, string("K"));
        Remove(loctestnum, loctesterr, set1, true, string("L"));
        Remove(loctestnum, loctesterr, set1, false, string("M"));

        RemoveAll(loctestnum, loctesterr, set1, false, list1);
        Traverse(loctestnum, loctesterr, set1, true, &TraversePrint<string>);


        list2.Clear();
        list2.InsertAtFront(string("M"));
        list2.InsertAtFront(string("P"));

        InsertSomeC(loctestnum, loctesterr, set1, true, list2);
        list2.InsertAtFront(string("D"));


        InsertSomeC(loctestnum, loctesterr, set1, true, move(list2));
        Traverse(loctestnum, loctesterr, set1, true, &TraversePrint<string>);
        list1.Front() = string("D");
        list1.Back() = string("T");

        RemoveSome(loctestnum, loctesterr, set1, true, list1);
        Traverse(loctestnum, loctesterr, set1, true, &TraversePrint<string>);
        Clear(loctestnum, loctesterr, set1);

        Empty(loctestnum, loctesterr, set1, true);
        Size(loctestnum, loctesterr, set1, true, 0);

    } catch(...) {
        loctestnum++;
        loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }
    cout << "End of Set<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}

void testSetString(uint & testnum, uint & testerr) {
    uint loctestnum = 0, loctesterr = 0;
    cout << endl << "Start of Set<string> Test" << endl;
    try {
        lasd::Vector<string> vec1(5);
        SetAt(loctestnum, loctesterr, vec1, true, 0, string("A"));
        SetAt(loctestnum, loctesterr, vec1, true, 1, string("C"));
        SetAt(loctestnum, loctesterr, vec1, true, 2, string("D"));
        SetAt(loctestnum, loctesterr, vec1, true, 3, string("E"));
        SetAt(loctestnum, loctesterr, vec1, true, 4, string("B"));

        /* ********************************************************************** */

        cout << endl << "Begin of SetVec<string> Test:" << endl;
        lasd::SetVec<string> setvec1(vec1);
        testSetString(setvec1, loctestnum, loctesterr);
        cout << endl << "Begin of SetLst<string> Test:" << endl;
        lasd::SetLst<string> setlist1(vec1);
        testSetString(setlist1, loctestnum, loctesterr);
        cout << "\n";

        /* ********************************************************************** */

        EqualLinear(loctestnum, loctesterr, setvec1, setlist1, true);

    } catch(...) {
        loctestnum++;
        loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }
    cout << "End of Set<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}

/* ************************************************************************** */
void mytest() {
    cout << endl << "Start MyTest" <<endl;
    lasd::Vector<int> vec(7);
    vec[0] = 10;
    vec[1] = 11;
    uint testnum = 0;
    uint testerr = 0;
    testList(testnum, testerr);
    testVector(testnum, testerr);
    testSetString(testnum, testerr);
    testSetFloat(testnum, testerr);
    testSetInt(testnum, testerr);
    cout << endl << "Test (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;

}

