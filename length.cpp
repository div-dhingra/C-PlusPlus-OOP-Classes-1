// #pragma once

#include <iostream> 

#include "length.h"

using namespace std; 


//Default constructor
Length::Length():feet(0), inches(0) {
}

//Initialization constructor #1
Length::Length(int feet):feet(feet), inches(0){
}

//Initializaton constructor #2
Length::Length(int feet, int inches):feet(feet), inches(inches) {

}

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
// don't need to add 'friend' keyword in implementation (.cpp)-file. 
// ONLY in header (.h)-definition file!
ostream& operator<<(ostream& out, Length length1) {
    
    // only put base-case text (what the private members are) in overloaded out-operator
    // Any other text will be manually added in main.cpp, as it may vary. 
    // "Here is the height of user1" << ...
    out << length1.feet << " feet and " << length1.inches << " inches.\n";
    return out; 
}

// left-argument is object of class for this operator, so we can use the 
// member-function for it (implicit dot invocator).
Length Length::operator+(Length l2) {

    int totInches; 

    totInches = ((this->feet * 12) + (l2.feet * 12))+ (this->inches + l2.inches);
    
    return Length(totInches / 12, totInches % 12);

}

// member function --> Length l1 is the implicit object on the right
void Length::operator=(Length l2) {

    this->feet = l2.feet; 
    this->inches = l2.inches; 
}

// USE LENGTH::MEMBERFUNC, to scope access member functions of class!

//getters
int Length::getFeet() {

    return this->feet; 
}
int Length::getInches() {

    return this->inches;
}

//setters
void Length::setFeet(int feet) {

    this->feet = feet; 
    // must include this keyword to differentiate from same-name arg

}
void Length::setInches(int inches) {

    this->inches = inches; 
     // must include this keyword to differentiate from same-name arg
}

Length Length::operator+(int inches) {

    int totInches = (this->feet * 12) + (this->inches) + inches;
    return Length(totInches / 12, totInches % 12);

}
