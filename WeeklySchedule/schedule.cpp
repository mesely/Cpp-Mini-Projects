//Mehmet Selman Yilmaz

#include "schedule.h"

// Default constructor creates a schedule with 7 rows and 0 columns, with all elements set to NULL.
Schedule::Schedule()
{
    time_slots = 0;
    data = new string * [7];
    for (int i = 0; i < 7; i++)
    {
        data[i] = nullptr;
    }
}

// Parametric constructor creates a schedule with 7 rows and c columns, with all elements initially set to "free".
Schedule::Schedule(int c)
{
    time_slots = c;
    data = new string*[7];
    for (int i = 0; i < 7; i++)
    {
        data[i] = new string[c];
        for (int j = 0; j < c; j++)
        {
            data[i][j] = "free";
        }
    }
}

// Deep copy constructor
Schedule::Schedule(const Schedule &rhs)
{
    time_slots = rhs.time_slots;
    data = new string*[7];
    for (int i = 0; i < 7; i++)
    {
        if (rhs.data[i] == nullptr)
        {
            data[i] = nullptr;
        }
        else
        {
            data[i] = new string[time_slots];
            for (int j = 0; j < time_slots; j++)
            {
                data[i][j] = rhs.data[i][j];
            }
        }
    }
}

// Destructor
Schedule::~Schedule()
{
    for (int i = 0; i < 7; i++)
    {
        delete[] data[i];
    }
    delete[] data;
}

// Returns the number of time slots in the schedule.
int Schedule::getTimeSlots() const
{
    return time_slots;
}

// Returns the pointer to the data array in the schedule.
string** Schedule::getData() const
{
    return data;
}

// Sets the number of time slots in the schedule.
void Schedule::setTimeSlots(int time)
{
    time_slots = time;
}

// Sets the value of the element at the specified row and column in the schedule.
void Schedule::setDataValue(int i, int j, string element)
{
    data[i][j] = element;
}

// Sets the data array in the schedule to the specified array of pointers.
void Schedule::setDataPointer(string *element[])
{
    data = element;
}

// Sets the data array in the schedule at the specified row to the specified array of elements.
void Schedule::setData(int i, string element[])
{
    data[i] = element;
}
// This is the assignment operator overload for the Schedule class
const Schedule& Schedule::operator=(const Schedule &rhs) {
    if (this != &rhs) {
// Delete the data of the left-hand side
        for (int i = 0; i < 7; i++) {
            delete[] data[i];
        }
        delete[] data;
// Create new array for the left-hand side
        time_slots = rhs.time_slots;
        data = new string *[7];
        for (int i = 0; i < 7; i++) {
            if (rhs.data[i] == nullptr) {
                data[i] = nullptr;
            } else {
                data[i] = new string[time_slots];
                for (int j = 0; j < time_slots; j++) {
                    data[i][j] = rhs.data[i][j];
                }
            }
        }
    }
    return *this;
}

// This is the overload of the "+" operator for adding a day
Schedule Schedule::operator+(const Days &input_days)
{
    int DayNumber = input_days;
    Schedule result;
    result.data = new string *[7];
    result.time_slots = time_slots;
// Loop through each day of the week
    for(int j =0; j<7; j++)
    {
        result.data[j] = new string[result.time_slots];
// Loop through each time slot
        for(int k=0;k<time_slots;k++)
        {
// If it's not the input day, copy the current value
            if(j!=DayNumber)
            {
                result.data[j][k] = data[j][k];
            }
// If it is the input day, mark it as busy
            else if (j==DayNumber)
            {
                result.data[DayNumber][k] = "busy";
            }
        }
    }
    return result;

}

// This is the overload of the "+" operator for adding a time slot
Schedule Schedule::operator+(const int & time)
{
    Schedule result;
    result.data = new string *[7];
    result.time_slots = time_slots;
// Loop through each day of the week
    for(int j =0; j<7; j++)
    {
        result.data[j] = new string[result.time_slots];
// Loop through each time slot
        for(int k=0;k<time_slots;k++)
        {
// If it's not the input time slot, copy the current value
            if(k!=time)
            {
                result.data[j][k] = data[j][k];
            }
// If it is the input time slot, mark it as busy
            else if (k==time)
            {
                result.data[j][k] = "busy";
            }
        }
    }
    return result;
}

// Overload operator+ to merge two schedules, marking times as "busy" if either schedule has a "busy" entry
Schedule operator +(const Schedule &lhs, const Schedule &rhs)
{
    Schedule result;
    result.setDataPointer(new string*[7]);
    result.setTimeSlots(lhs.getTimeSlots());
    for(int i=0; i<7;i++){
        result.setData(i,new string[result.getTimeSlots()]);
        for(int j=0;j<result.getTimeSlots();j++)
        {
            if(lhs.getData()[i][j] == rhs.getData()[i][j] && lhs.getData()[i][j] == "free")
            {
                result.setDataValue(i,j,"free");
            }
            else{
                result.setDataValue(i,j,"busy");
            }
        }

    }
    return result;
}

// Overload operator* to merge two schedules, marking times as "free" if both schedules have a "free" entry
Schedule operator *(const Schedule &lhs, const Schedule &rhs)
{
    Schedule result;
    result.setDataPointer(new string * [7]);
    result.setTimeSlots(lhs.getTimeSlots());
    for(int i=0; i<7;i++){
        result.setData(i,new string[result.getTimeSlots()]);
        for(int j=0;j<result.getTimeSlots();j++)
        {
            if(lhs.getData()[i][j] == rhs.getData() [i][j] && lhs.getData()[i][j] == "busy")
            {
                result.setDataValue(i,j,"busy");
            }
            else{
                result.setDataValue(i,j,"free");
            }
        }

    }
    return result;
}

// Overload operator< to compare two schedules by counting the number of "busy" entries in each one
bool operator <(const Schedule &lhs, const Schedule &rhs)
{
    int lhs_ctr=0,rhs_ctr=0;
    for(int i=0; i<7;i++){
        for(int j=0;j<lhs.getTimeSlots();j++)
        {
            if(lhs.getData()[i][j] == "busy")
            {
                lhs_ctr++;
            }
            if(rhs.getData() [i][j] == "busy")
            {
                rhs_ctr++;
            }
        }
    }
    if(lhs_ctr < rhs_ctr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Overload operator[] to allow indexing by day of the week
string* &Schedule::operator[](Days day) const
{
    int DayInt = (int)day;
    return data[DayInt];
}

// Overload operator<< to allow printing a day of the week
ostream& operator<<(ostream& lhs, Days & d)
{
    string array[7] = {"Monday","Tuesday","Wednesday","Thursday", "Friday","Saturday","Sunday"};
    lhs << array[d];
    return lhs;
}

// Overload operator<< to allow printing a schedule
ostream& operator<<(ostream &lhs, const Schedule &rhs)
{
    string array[7] = {"Mo","Tu","We","Th", "Fr","Sa","Su"};
    for (int i = 0; i < 7; i++) {
        lhs << array[(Days(i))] << ": ";
        for (int j = 0; j < rhs.getTimeSlots(); j++) {
            lhs << rhs.getData()[i][j] << " ";
        }
        lhs << endl;
    }
    return lhs;
}
