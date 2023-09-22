#ifndef _MEMBER_

#define _MEMBER_

#include <iostream> 

#include "length.h"

using namespace std; 

class Member : public Length {

    private: 
        Length height; 
        int weight; 

        int memberID; 
        // no default value -> JUNK!

    public: 

        //Default constructor
        // NO default value of member ID, but that's fine!
        Member(); 

        //Initialization constructor #1
        Member(int memberID);
    
        //setters
        void setHeight(int feet, int inches);

        void setHeight(Length obj1);

        void setWeight(int weight);

        //overloading 'cout' operator 
        // friend (2 obj args) or member (1 obj arg)
        // Should return a ostream-object, for in-line outputs
        // ex) cout << "dog" << "cat" -> cout << "cat"
        // • 2nd cout is returned by first cout!
        // return a REFERENCE to the SAME 'ostream'-object, 
        // so it can sequentially link to the next output, as well!
        // Must be 'friend' --> left object has implicit 'dot-operator' for 
        // member functions. Since '<<' doesn't have a object of 'Length' Class 
        // on the left, it can implicity 'dot-invocate' the function, so we must use 
        // the 'friend'-function operator to allow this output-ostream-function to 
        // access (output) the private members of the Length-class (feet, inches)...
        friend ostream& operator<<(ostream& out, Member m1);

};

#endif

