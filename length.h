#ifndef _LENGTH_

#define _LENGTH_

#include <iostream> 
using namespace std; 
// INCLUDE IN BOTH LENGTH, MEMBER FILE!

class Length {

    // for inheritance -> so derived classes can access private members!
    protected: 
        int feet; 
        int inches; 

    public: 

        //Default constructor
        Length(); 

        //Initialization constructor #1
        Length(int feet);

        //Initializaton constructor #2
        Length(int feet, int inches);

        //getters
        int getFeet();
        int getInches();
    
        //setters
        void setFeet(int feet);
        void setInches(int inches);

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
        friend ostream& operator<<(ostream& out, Length length1);

        // left-argument is object of class for this operator, so we can use the 
        // member-function for it (implicit dot invocator).
        Length operator+(Length l2);

        //2nd overloaded + operator
        Length operator+(int inches);

        // member function --> Length l1 is the implicit object on the right
        void operator=(Length l2);

};

#endif

