// #pragma once

#include <iostream>

// #include "member.h"
#include "length.h"

using namespace std; 

//Default constructor
//NO default value of member ID, but that's fine!
Member::Member(): weight(0) {
}

//Initialization constructor #1
Member::Member(int memberID): memberID(memberID) {
}


void Member::setHeight(int feet, int inches) {

    // height is object of class length anyway
    this->height.setFeet(feet);
    this->height.setInches(inches);

}

void Member::setHeight(Length obj1) {

    // WRONG!
    // setFeet(obj1.feet);
    // setInches(obj1.inches);

    // cout << obj1.getFeet(); 
    // cout << obj1.getInches(); 

    this->height.setFeet(obj1.getFeet());
    this->height.setInches(obj1.getInches());
    // can't access private members directly for ANOTHER OBJECT 
    // ^^ use getters! (only for this instance --> this -> feet, this -> inches)
}

void Member::setWeight(int weight) {

    this->weight = weight; 
}

// No need to include 'friend' keyword when defining function (only when declaring)
// Same with 'virtual' keyword --> keywords are only for declaration/in-line definition 
// NOT out-of-line definition!!!
// ostream operator << -> pass-by-value return type --> only a copy of the
// 'ostream-object' is returned, NOT THE ORIGINAL OSTREAM OBJECT ITSELF (not referenced)!
ostream& operator<<(ostream& out, Member m1) {

    out << "Height: " << m1.height; 
    // Length height; --> already overloaded for output of feet,inches! (inheritance)...

    out << "Weight: " << m1.weight << '\n';

    out << "Member ID: " << m1.memberID <<'\n';

    return out; 
    // return a reference to the original ostream-variable for in-line outputs 
    // ex) cout << "hey" << "boy" --> cout << "boy"!!!
}
