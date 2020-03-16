# include <iostream>
using namespace std;

int sumMonth (int age)
{
    int summonth = 12 * age;
    return summonth;
}

int main ()
{
    int age ;    
    cout << "enter your age : " ;
    cin >> age ;
    int summonth = sumMonth(age );
    cout << age << " age = ";
    cout << summonth << "summonth = " << endl;
    return 0;
}