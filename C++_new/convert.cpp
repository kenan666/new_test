# include <iostream>
using namespace std;

int sumStone(int sts)
{
    return 14 * sts ;
}

int main()
{
    int stone;
    cout << "enter the weight in stone : ";
    cin >> stone ;
    int pounds = sumStone(stone);
    cout << stone << "stone = ";
    cout << pounds << "pounds = "<< endl;
    return 0;
}

