#include <iostream>
#include <string>
using namespace std;
// Mehmet Selman Yilmaz
string lowerString(const string& str) {
    char c;
    string newString = "";
    for(int i = 0; i < str.length(); i++) {
        c = str[i];
        if (int(c) >= int('A') && int(c) <= int('Z')) {
            c += 32;
        }
        newString += c;
    }
    return newString;
}

string inputCheck(string & q,int & point, int & soru, bool & check, string j)
{
    int eq,op;
    int counter = 0, counter2= 0;
    string part1,part2,n1,n2;
    if (soru == 0 && j != "yes") {cout << "Please enter question #"<< soru+1 <<" and its answer: ";
        cin >> q;
    }
    else if(soru!= 0 && j!="yes") {cout << endl << "Please enter question #"<< soru+1 <<" and its answer: ";
        cin >> q;
    }
    check = 1;
    eq = q.find("=");
    part2 = q.substr(eq+1,q.length()-eq);
    part1 = q.substr(0,eq);
    if (part1.length() == 0 || part2.length()== 0) {check = 0;}
    if (eq== -1)
    {
        check =0;
    }
    else
    {
        if(part2.length() != 0&& check==1)
        {
            if ((part2.at(0) == 43) || (part2.at(0) == 45))
            {
                counter ++;
                while (counter <= part2.length()-1)
                {
                    char val = part2.at(counter);
                    if (isdigit(val) == 0)
                    {
                        check = 0;
                        break;
                    }
                    counter ++;
                }
            }
            else
            {
                while (counter <= part2.length()-1)
                {
                    char val = part2.at(counter);
                    if (isdigit(val) == 0)
                    {
                        check = 0;
                        break;
                    }
    
                    counter ++;
                }
            }
        }
        if (part1.length() != 0 && check ==1)
        {
            if ( (part1.at(0) == 43) || (part1.at(0) == 45)){part1 = part1.substr(1,part1.length());}
            else if ((part1.at(0)) != 43 && (part1.at(0)) != 45){part1 = part1.substr(0,part1.length());}
            while(counter2 <=part1.length()-1)
            {
                char candidate = part1.at(counter2);
                if (candidate == 43 || candidate == 45)
                {
                    op = counter2;
                    n1 = part1.substr(0,op);
                    break;
                }
                counter2 ++;
            }
            if(n1.length() == 0)
            {
                check = 0;
            }
            else
            {
                
                int counter3 = 0;
                if (n1.length()!= 0 && check == 1)
                {
                    while(counter3 <= n1.length()-1)
                    {
                        
                        if (isdigit(n1.at(counter3)) == 0)
                        {
                            
                            check = 0;
                            break;
                        }
                    
                        counter3++;
                    }
                }
                part1 = part1.substr(op+1,eq-op);
                if ((part1.at(0) == 43) || (part1.at(0)) == 45){n2 = part1.substr(1,eq-op);}
                else if((part1.at(0)) != 43 && (part1.at(0)) != 45){n2 =part1.substr(0,eq-op);}
                int counter4 = 0;
                while (counter4 <= n2.length()-1)
                {
                    if(isdigit(n2.at(counter4)) == 0)
                    {
                        check = 0;
                        break;
                    }
                    counter4 ++;
                }
            }
        }
    }
    if (check == 0 && j!= "yes")
    {
        cout << "Wrong input format! You got -10 penalty points for this math expression." << endl;;
        point -= 10;}
    else if (check == 0 && j == "yes")
    {
        cout << "Wrong input format! You got -10 penalty points for this joker option." << endl;;
        point -= 10;}
    
    return q;
    
}

void questionParce(string q,int &n1, int &n2 , int &r, string &o)
{
int eq,op,opr;
int counter2= 0;
string part1,part2;
eq = q.find("=");
part2 = q.substr(eq+1,q.length()-eq);
    string part1v2= q.substr(0,eq);
    part1 = q.substr(0,eq);

    r=atoi(part2.c_str());
    if ( (part1.at(0) == 43) || (part1.at(0) == 45)){part1 = part1.substr(1,part1.length());}
    else if ((part1.at(0)) != 43 && (part1.at(0)) != 45){part1 = part1.substr(0,part1.length());}
    while(counter2 <=part1.length()-1)
    {
        char candidate = part1.at(counter2);
        if (candidate == 43 || candidate == 45)
        {
            op = counter2;
            o = candidate;
            n1 = atoi(part1.substr(0,op).c_str());
            break;
        }
        counter2 ++;
    }
    part1 = part1.substr(op+1,eq-op);
    if (part1v2.at(0) ==45) {n1=n1*-1;}
    n2 = atoi(part1.c_str());
}
void checkResult(string q,int n1, int n2, int r, string o,string j,int & point, bool & jc, int &soru, int & joker)
{
    if(o=="+")
    {
        if(n1+n2==r && joker != soru)
        {cout << "Correct answer! You got 25 points for this math expression." << endl;
            point +=25;
        }
        else if(n1+n2==r && joker==soru)
        {cout << "Correct answer! You got 25 points for this joker option." << endl;
            point +=25;
        }
        else
        {
            
            if (jc == 1)
            {
                cout << "Wrong!"<<endl<<"Would you like to use your joker option to correct the answer? ";
                cin >> j;
                j = lowerString(j);
                int joker, pn1=n1,pn2=n2;
                bool check = 1;
                string po=o;
                if(j=="yes")
                {
                    jc = 0;
                    joker = soru;
                    cout << "Please enter the expression again: ";
                    cin >> q;
                    inputCheck(q,point, soru, check,j);
                    if (check ==1)
                    {
                        questionParce(q, n1, n2, r, o);
                        if (n1 == pn1 && n2==pn2 && o==po)
                        {
                            checkResult(q,n1, n2, r, o, j, point,jc,soru, joker);
                        }
                        else
                        {
                            cout << "Different question! You got -10 penalty points for this joker option."<< endl;
                            point -=10;
                            
                        }
                    }
                }
                else
                {
                    cout << "Sorry! The answer should have been: " << n1+n2 << ". You got "<< 0 <<" points for this math expression."<< endl;
                }
            }
            else if(jc ==0 && j!= "yes")
            {
                cout << "Sorry! The answer should have been: " << n1+n2 << ". You got "<< 0 <<" points for this math expression."<< endl;
            }
            else if(jc == 0 && j=="yes")
            {
                cout << "Sorry! The answer should have been: " << n1+n2 << ". You got "<< -10 <<" penalty points for this joker option."<< endl;
                point -=10;
            }
        }
    }
    else if(o=="-")
    {

        if(n1-n2==r && j!="yes")
        {cout << "Correct answer! You got 25 points for this math expression." << endl;
            point +=25;
        }
        else if(n1-n2==r && j=="yes")
        {cout << "Correct answer! You got 25 points for this joker option." << endl;
            point +=25;
        }
        else
        {
            
            if (jc == 1)
            {
                cout << "Wrong!"<<endl<< "Would you like to use your joker option to correct the answer? ";
                cin >> j;
                j = lowerString(j);
                int joker,pn1=n1,pn2=n2;
                string po =o;
                bool check = 1;
                if(j=="yes")
                {
                    jc = 0;
                    joker = soru;
                    cout << "Please enter the expression again: ";
                    cin >> q;
                    inputCheck(q,point, soru, check,j);
                    if (check ==1)
                    {
                        questionParce(q, n1, n2, r, o);
                        if (n1 == pn1 && n2==pn2 && o==po)
                        {
                            checkResult(q,n1, n2, r, o, j, point,jc,soru, joker);
                        }
                        else
                        {
                            cout << "Different question! You got -10 penalty points for this joker option."<< endl;
                            point -=10;
                            
                        }
                    }
                }
                else
                {
                    cout << "Sorry! The answer should have been: " << n1-n2 << ". You got "<< 0 <<" points for this math expression." << endl;
                }
            }
            else if(jc ==0 && j!= "yes")
            {
                cout << "Sorry! The answer should have been: " << n1-n2 << ". You got "<< 0 <<" points for this math expression."<< endl;
            }
            else if(jc == 0 && j=="yes")
            {
                cout << "Sorry! The answer should have been: " << n1-n2 << ". You got "<< -10 <<" penalty points for this joker option."<< endl;
                point -= 10;
            }
            
        }
    }
}

int main()
{
    int n1,n2,r,soru=0,p=0, joker;
    string o,j,q;
    bool check,jc;
    jc = 1;
    while(soru < 4)
    {
        q = inputCheck(q,p, soru, check,j);
        if (check == 1)
        {
           questionParce(q, n1, n2, r, o);
           checkResult(q,n1, n2, r, o, j, p,jc,soru,joker);
        }
        soru++;
    }
    if (p< 0) {cout << endl << "End of the program. You got " << 0 << " points in total." << endl;}
    else{cout << endl<< "End of the program. You got " << p << " points in total."<< endl;}
    
    return 0;
}
