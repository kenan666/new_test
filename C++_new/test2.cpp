# include <iostream>
using namespace std;

float degreeF (float degreec)
{
    float degreef = degreec * 9 / 5 + 32 ;
    return degreef;
}

int main()
{
    float degreec;
    cout << "enter the now degreec :";
    cin >> degreec;
    float degreef = degreeF(degreec);
    cout << degreec << "degreec = ";
    cout << degreef << "degreef = " << endl ;
    return 0;
}