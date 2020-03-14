# include <iostream>

using namespace std;

int main()
{
    int carrots;

    cout << "how many carrots do you have?";
    cin >> carrots;
    cout << "here are 2 more.";
    
    carrots = carrots + 2;
    cout << "now you have :" << carrots << "carrots" << endl;

    return 0;
}