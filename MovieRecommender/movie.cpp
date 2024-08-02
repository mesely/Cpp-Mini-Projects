#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "movie.h"

using namespace std;

Movie::Movie()
{
    name = "";
    genre = "";
    year = 0;
}

Movie::Movie(string n, int y, string g)
{
    name = n;
    genre = g;
    year = y;
}

void Movie::setName(string n)
{
    name = n;
}
string Movie::getName() const
{
    return name;
}
void Movie::setGenre(string g)
{
    genre = g;
}
string Movie::getGenre() const
{
    return genre;
}
void Movie::setYear(int y)
{
    year = y;
}
int Movie::getYear() const
{
    return year;
}
void Movie::print() const
{
    cout << name << " " << year << " " << genre;
}


