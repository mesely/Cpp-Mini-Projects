#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "strutils.h"
#include <fstream>
#include "movie.h"

using namespace std;

int main()
{
    string filename;
    vector<Movie> movielist;
    ifstream ifile;
    string line;
    int choice;
    cout << "Welcome to the movie recommender program!" << endl << endl;
    cout << "Please enter the movie list filename: ";
    cin >> filename;
    ifile.open(filename.c_str());
    while(ifile.fail())
    {
        cout << "Please check filename! Enter a correct movie list filename: ";
        cin >> filename;
        ifile.open(filename.c_str());
    }
    while (getline(ifile, line))
    {

        string word,name="", genre= "",syear="";
        int year, yearstart,genrestart;
        istringstream strStream(line);

        for (int i=0; i< line.length();i++)
        {
            if((isdigit(line.at(i)) == 1) && (isalpha(line.at(i-1)) == 0))
            {
                yearstart =i;
                break;
            }
        }
        for (int i=0; i< line.length();i++)
        {
            if(isdigit(line.at(i)) == 0 && i>yearstart)
            {
                genrestart =i+1;
                break;
            }
        }
        name = line.substr(0,yearstart-1);
        year = atoi(line.substr(yearstart,line.length()-yearstart));
        genre = line.substr(genrestart,line.length()-genrestart-1);
        Movie movie(name,year,genre);
        movielist.push_back(movie);

    }
    int maxIndex;
    Movie temp;
    for (int i =0; i<movielist.size()-1; i++)
    {
        maxIndex = i;
        for(int j= i+1; j<movielist.size(); j++)
        {
            if(movielist[j].getYear() > movielist[maxIndex].getYear() || ((movielist[j].getYear() == movielist[maxIndex].getYear() && movielist[j].getName() < movielist[maxIndex].getName())))
            {
                maxIndex = j;
            }
        }
        temp = movielist[i];
        movielist[i] = movielist[maxIndex];
        movielist[maxIndex] = temp;
    }





    cout << "Please select your action:" << endl << "1. Select the genre of the movie that you want to watch" << endl <<"2. Select the year of the movie that you want to watch" << endl <<"3. Exit program" << endl << endl << "Enter your choice: ";
    cin >> choice;
    bool check = false;
    string genrechoice,yearchoice, g;
    int firstyear,lastyear;
    while(0>= choice || 3< choice)
    {
        cout << "Invalid action!" << endl << endl << "Enter your choice: ";
        cin>> choice;
    }
    while(choice != 3)
    {
        if (choice == 1)
        {
            cout << "Please enter the genre of the movie you want to watch: ";
            cin >> genrechoice;
            for (int i =0; i<movielist.size(); i++)
            {
                g = movielist[i].getGenre();

                if(LowerString(g) == LowerString(genrechoice))
                {
                    if(check == 0){cout << endl << genrechoice << " movies from newest to oldest:" << endl;}
                    check = true;
                    cout << "Movie name: " << movielist[i].getName() << " Release Year: " << movielist[i].getYear() << endl;

                }
            }
            if (check == 0){cout << endl << "There are no " << genrechoice << " movies!" << endl;}
            check = false;

        }
        else if (choice == 2)
        {
            cout << "Please enter the year of the movie you want to watch: ";
            cin >> yearchoice;
            int idx;
            if(yearchoice.find("-") == -1)
            {
                firstyear = stoi(yearchoice);
                for (int i =0; i<movielist.size(); i++)
                {
                    if(movielist[i].getYear() == firstyear)
                    {
                        if(check == 0){cout << "Movies released in " << yearchoice << " from A to Z:" << endl;}
                        check = true;
                        cout << "Movie name: " << movielist[i].getName() << " Genre: " << movielist[i].getGenre() << endl;

                    }
                }
                if (check == 0){cout << "There are no movies released in " << yearchoice << "!" << endl;}
                check = false;
            }
            else
            {
                idx = yearchoice.find("-");
                firstyear = stoi(yearchoice.substr(0,idx));
                lastyear = stoi(yearchoice.substr(idx+1,yearchoice.length()-idx));
                for (int i =0; i<movielist.size(); i++)
                {
                    if(movielist[i].getYear() >= firstyear && movielist[i].getYear() <= lastyear)
                    {
                        if(check == 0){cout << "Movies released between the years " << firstyear << "-" << lastyear << " from A to Z with decreasing year ordering:" << endl;}
                        check = true;
                        cout << "Movie name: " << movielist[i].getName() << " Release Year: "<< movielist[i].getYear()<< " Genre: " << movielist[i].getGenre() << endl;
                    }
                }
                if (check == 0){cout << "There are no movies released between " << firstyear << "-" << lastyear << "!" << endl;}
                check = false;
            }

        }
        cout << endl << "Enter your choice: ";
        cin >> choice;
        while(0>= choice || 3< choice)
        {
            cout << "Invalid action!" << endl << endl << "Enter your choice: ";
            cin>> choice;
        }


    }
    cout << "Thank you..." << endl;


    return 0;
}

