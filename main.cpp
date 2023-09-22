#include <iostream> 

// include both cpp, h files (instead of just '.h')
#include "length.h"
#include "member.h"
#include "length.cpp"
#include "member.cpp"
// ONLY #include 'implementation-cpp' files in MAIN.CPP (along with '.h' files).
// DO NOT INCLUDE PARENT (BASE-CLASS) '.cpp' (Implementation) FILE IN 
// THE 'derived-child.cpp' (implementation-file), as the following error belwo 
// will result: 

// 'Redefinition error' is exclusive to VSCODE. 
// WHY: Since we need to include both the cpp-file (implementation file),
// and h-file (header file), we need to have our INCLUDE GUARDS IN BOTH OF THEM. 
// Include guards prevent redefinition of the same-class multiple times, 
// typically when working with base, derived classes, where #including 
// the derived class includes the base class again as well (inheritance).
// SO, since we are explicitly importing our '.cpp' (implementation)-file 
// in our main.cpp, we need to add an include-guard 
// to prevent it from being redefined as well (length.cpp is 
// implicitly redefined via member.cpp, both of which are #included 
// in main.cpp)!!!

// OR, don't include length.cpp in my member.cpp file (implicitly pulled 
// in via "member.h", which includes "length.h")...That was it....

using namespace std; 

// 2-finger click in this window, and click run! (via extension).
// So I don't need to 'debug'
// cmd + s to not lose changes
int main() {

    Length h1; //h1 initialized to 0 feet 0 inches
    Length h2(3); //h2 initialized to 3 feet 0 inches
    Length h3(5,10); //h3 initialized to 5 feet 10 inches
    int inches = 10;
    cout << h1;
    cout << h2 << h3;
    cout << h2 + h3;
    h1 = h3 + inches;
    cout << h1;

    cout << "\n--------------------------\n";

    int memberID = 1000;
    Member m1(memberID); 
    //Note that there should be no default value of memberID
    m1.setHeight(5, 7); 
    //Sets the height field to 5 feet and 7 inches
    m1.setWeight(150);
     //Sets the weight field to 150lbs;
    cout << m1; 
    //Outputs member information in a suitable format

    Length h(6, 2);

    m1.setHeight(h);
    // ! FIX THIS!!!
    // SOLUTION: Use getters! Can't access private members FROM ANOTHER PARENT-CLASS 
    // OBJECT (Length) PASSED AS AN ARGUMENT, as they are PRIVATE MEMBERS! 
    // (can only access 'private members' OF CURRENT INSTANCE, AS THOSE 'private-member valuies' 
    // BELONG OT THE CURRENT OBJECT [THEY ARE NOT from another instance of class (object), 
    // that was not created from the inheriting child-class 'Member])

    // //Sets the height field to values from h

    cout << '\n';

    cout << m1;


}
