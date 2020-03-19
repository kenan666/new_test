// limits.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


/*
相对来说，C++ 中字符串的长度
short 至少16位
int 至少与short 一样长
long 至少32位，且至少与int 一样长
long long 至少64 位，且至少与 long 一样长

*/
#include <iostream>
#include <climits>
using namespace std;

int main()
{
	int n_int = INT_MAX;   //initialize n_int to max value
	short n_short = SHRT_MAX;  // symbols define in climits file
	long n_long = LONG_MAX;
	long  long n_llong = LLONG_MAX;

	//sizeof operator yields size of  type or of variable

	// 对于计算类型名（int）使用sizeof运算符时，应该将名称放在括号中，但是对于变量名（n_int ）使用sizeof时，括号则是可选的 
	cout << "int is " << sizeof n_int << "type" << endl;
	cout << "int is " << sizeof(int) << "type" << endl; 

	cout << "short is " << sizeof(n_short) << "type " << endl;
	cout << "short is " << sizeof n_short << "type" << endl;

	cout << "long is " << sizeof n_long << "type" << endl;
	cout << "long long is " << sizeof n_llong << "type" << endl;
	cout << endl;

	cout << "maximum valus :" << endl;
	cout << " int :" << n_int << endl;
	cout << " short :" << n_short << endl;
	cout << " long :" << n_long << endl;
	cout << " long long :" << n_llong << endl << endl;

	cout << "minimum int value :" << INT_MIN << endl;
	cout << "Bits per byte = " << CHAR_BIT << endl;

	return 0;

}
