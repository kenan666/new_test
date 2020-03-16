# include <iostream>

using namespace std;

void simon(int) ; // prototype for simon

int main()
{
    simon(3);
    cout << "pick an integer";
    int count;
    cin >> count ;
    simon(count);
    cout << "done" << endl ;
    return 0;

}

void simon(int n) // define the simon function
{
    cout << "simon says touch your toes " << n << "times"<< endl;
}