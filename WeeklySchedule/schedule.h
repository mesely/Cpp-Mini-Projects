//
// Created by Mehmet Selman Yilmaz on 23.04.2023.
//

#ifndef THE4_SCHEDULE_H
#define THE4_SCHEDULE_H

#endif //THE4_SCHEDULE_H

#include <iostream>
using namespace std;

enum Days {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

class Schedule{
private:
    int time_slots;
    string** data;

public:
    Schedule(); //Default constructor, 7 rows 0 column, all elements are NULL.
    Schedule(int c); //Parametric constructor, 7 rows c columns, all elements are "free".
    Schedule(const Schedule &); //Deep copy constructor.
    ~Schedule(); //Destructor.

    int getTimeSlots() const; //Getter for time_slots attribute.
    string** getData() const; //Getter for data attribute.
    void setTimeSlots(int time); //Setter for time_slots attribute.
    void setDataValue(int i, int j, string element); //Sets the element at position [i][j] to the given string.
    void setDataPointer(string * element[]); //Setter for data attribute.
    void setData(int i, string  element[]); //Sets the entire row i to the given string array.

    //MEMBER FUNCTIONS
    const Schedule& operator=(const Schedule & ); //Overloaded assignment operator.
    Schedule operator +(const Days &); //Overloaded addition operator, adds a single day to the Schedule.
    Schedule operator +(const int &); //Overloaded addition operator, adds a number of days to the Schedule.
    string* &operator[](Days rhs) const; //Overloaded subscript operator for accessing a single day's data.

schedule = schedule + 5
    q

};

//FREE FUNCTIONS
Schedule operator +(const Schedule &, const Schedule &); //Overloaded addition operator, returns the union of two Schedules.
Schedule operator *(const Schedule &, const Schedule &); //Overloaded multiplication operator, returns the intersection of two Schedules.
bool operator <(const Schedule &lhs, const Schedule&rhs); //Overloaded less than operator, compares two Schedules based on the number of busy time slots they contain.
ostream& operator<<(ostream &, const Schedule &); //Overloaded stream insertion operator, prints the Schedule in a readable format.
ostream& operator<<(ostream& lhs , Days& d ); //Overloaded stream insertion operator, prints the name of a given day.
