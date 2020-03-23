// using_array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <iomanip>

using namespace std;
using std::setw;  //  setw() 函数 格式化输出

int main()
{
	/* 数组的使用

	1、数组的声明
	数据类型 数组名[元素数量]

	2、数组初始化
	double balance[5] = {1000.0,2.0,3.4,7.0,50.0};
	## 大括号之间的数值的数目不能大于数组声明时 方括号中指定的数目
	## 其中省略了数组的大小，数组的大小可视为 初始化时元素的个数如：
	double balance[] = {1000.0,2.0,3.4,7.0,50.0};

	3、访问数组元素
	数组元素可以通过数组名称+索引进行访问。
	double salary = balance[3];

	*/
	int a[10];  // 声明 一个 包含 10个元素的整型数组
	// 初始化数组
	for (int i = 0; i < 10; i++)
		a[i] = i + 100;
	cout << "元素索引" << setw(13) << "元素值" << endl;

	// 输出数组中的每个元素
	for (int j = 0; j < 10; j++)
		cout << setw(7) << j << setw(13) << a[j] << endl;

	/*
	多维数组：
	数据类型名 数组名[size1][size2]...[sizeN]
	example : int tridim[5][10][4]

	二维数组： 二维数组本质上是一个 一维数组的列表。
	example : 数据类型 数组名[x][y]
	int a[3][4] = {{0, 1, 2, 3},   //  初始化索引号为 0 的行
					{4, 5, 6, 7},   //  初始化索引号为 1 的行 
					{ 8, 9, 10, 11 }, // 初始化索引号为 2 的行 
				}
	等同于（Equates to）
	int a[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	
	访问数组中的元素
	int val = a[2][3]

	example2 :
	// 1.二维数组
	int aa[5][2] = {{0, 0}, {1, 2}, {2, 4}, {5, 7}, {9, 10}};
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 2; j++){
			cout << "aa[" << i << "][" << j << "] = " << aa[i][j] << endl;
		}
	}
	
	# ------------------------------------
	数组指针：

	1、数组名是一个指向数组中第一元素的常量指针(int const *p;),因此,double a[40];
	a是一个指向&a[0]的指针，即数组a的第一个元素的地址。
	example :
	double *p;
	double a[10];
	p = a;

	2、使用数组名作为常量指针是合法的，因此*(a+4)是一种访问a[4]数据的合法方式。
	一旦把第一个元素的地址存储在p中，就可以使用*p,*(p+1),*(p+2)等来访问数组的元素。
	example:
	// 2.指向数组的指针：数组指针
	double b[5] = {12.4, 3.1, 5.6, 0.8, 5.4};
	double *p;  // 一个指向double型的指针,可以存储一个double类型变量的地址
	p = b;
	cout << "使用指针的数组值 " << endl;
	for (int i = 0; i < 5; i++)
		cout << "*(p + " << i << ") = " << *(p + i) << endl;
	cout << "使用b作为地址的数组值 " << endl;
	for (int i = 0; i < 5; i++)
		cout << "*(b + " << i << ") = " << *(b + i) << endl;

	3、C++中，将char*或char[]传给cout进行输出，结果会是整个字符串，如果想要获得字符串的地址(第一个字符的地址)，
	可以使用方法：强制转化为其他指针(非char),可以是void*, float*,int*,double*等。
	使用&s[0]不能输出s[0]的地址,因为&s[0]将返回char*,对于char*,cout会将其作为字符串来处理，向下查找字符并输出直到字符结束*。
	example:
	// C++中，将char*或char[]传递给cout进行输出，结果会是整个字符串。如果想要获得字符串的地址，强制转化为其他指针（非char*）
	char var[MAX] = {'a', 'b', 'c'};
	char *ptr;
	// 指针中的数组地址
	ptr = var;
	for (int i = 0; i < 3; i++){
		cout << "var[" << i << "]的地址是 = " << (int *)ptr << endl;
		cout << "var[" << i << "] = " << *ptr << endl;
		ptr++;  // 移动到下一个位置
	}

	4、数组传参给函数
		1、可以通过指定不带索引的数组名来传递一个指向数组的指针
		2、传数组给一个函数，数组类型自动转换为指针类型，因此传的实际是地址
		3、如果想在函数中传递一个一维数组作为参数，必须用下面三种方式来声明函数形式参数，
		   这三种声明方式的结果是一样的，因为每种方式都会告诉编译器将要接收一个整型指针。
		   同样的，也可以传递一个多维数组作为形式参数。
		   example1:
		   void func1(int *param){}
		   example2:
		   void func2(int params[10]){}
		   example3:
		   void func3(int params[]){}
	*/
	//实例
	// 3.C++中把数组传递给函数(方法1)
	int bb[5] = { 1000, 2, 3, 17, 50 };
	double avg, avg1;
	// 传递一个指向数组的指针作为参数
	avg = getAverage(bb, 5);
	cout << "平均值: " << avg << endl;
	/*-----------------------方法2-----------------------*/
	int bbb[5] = { 1000, 2, 3, 17, 50 };
	int *ptr1 = bbb;
	// 分别计算数组元素个数，以及整型指针的字节数
	size_t bbb_size = sizeof(bbb) / sizeof(int);
	size_t ptr1_size = sizeof(ptr1);
	cout << "bbb size = " << bbb_size << endl;
	cout << "ptr1 size = " << ptr1_size << endl;
	avg1 = getAverage1(bbb, 5);
	cout << "平均值: " << avg1 << endl;

	// 方法1(下面的例子中把数组作为参数，同时还传递了另一个参数)
	double getAverage(int arr[], int size) {
		int i, sum = 0;
		double avg;
		cout << "sizeof(arr) = " << sizeof(arr) << endl;
		for (i = 0; i < size; i++)
			sum += arr[i];
		avg = double(sum) / size;
		return avg;
	}

	// 方法2
	double getAverage1(int *arr, int size) {
		int i, sum = 0;
		double avg;
		cout << "sizeof(arr) = " << sizeof(arr) << endl;
		for (i = 0; i < size; i++)
			sum += arr[i];
		avg = double(sum) / size;
		return avg;
	}

	//C++不允许返回一个完整的数组作为函数的参数。但是，可以通过指定不带索引的数组名来返回一个指向数组的指针。C++不支持在函数外返回局部变量的地址，除非定义局部变量为static变量。
	//如果想要从函数返回一个一维数组，必须声明一个返回指针的函数(指针函数)
	/*
	example :
	int *func(){} 
	
	*/
	//实例
	// 要生成和返回随机数的函数
	int * getRandom() {
		static int r[10];  // C++不支持在函数外返回局部变量的地址，除非定义局部变量为static变量
		// 设置随机数种子
		srand((unsigned)time(NULL));
		for (int i = 0; i < 10; i++) {
			r[i] = rand();
			cout << "r[" << i << "] = " << r[i] << endl;
		}
		return r;
	}
	// 4.从函数返回数组----指针函数
	int *p1;
	p1 = getRandom();
	for (int i = 0; i < 10; i++)
		cout << "*( p1 + " << i << ") = " << *(p1 + i) << endl；

	/*
	1、细节知识点：
	char a1[] = {'p', 'y', 't', 'h', 'o', 'n'};  // 初始化，没有 null     
	char a2[] = {'p', 'y', 't', 'h', 'o', 'n', '\0'};   // 初始化，明确有 null     
	char a3[] = "python";  // null 终止符自动添加     
	const char a4[6] = "python";  // 报错，没有 null 的位置 

	2、数组大小是固定的，如果使用不固定大小的字符时，使用vector
	vector<int> vec;  // 创建向量用于存储整型数据
	int m;
	// 显示vec初始大小
	cout << "vector size = " << vec.size() << endl;
	// 向向量vec追加5个整数值
	for(int m = 0; m < 5; m++)
		vec.push_back(m);
	// 显示追加后vec的大小
	cout << "追加后的vector size = " << vec.size() << endl;

	3、静态数组与动态数组
	静态 int array[100];  定义了数组 array，并未对数组进行初始化
		int array[100] = {1, 2};  定义并初始化了数组 array

	动态 int * array = new int[100];  分配了长度为 100 的数组 array
		delete [] array;

	动态 int * array = new int[100]{1, 2};  为长度为100的数组array初始化前两个元素
		delete [] array;
	
	4、数组初始化时可以用聚合方法，但是赋值时候不可以用聚合方法
	example：
	int array[] = {5,10,20,40};   // 合法      
	int array[];     
	int main()     
	{     
		array[] = {5,10,20,40}; // 不合法     
		return 0;     
	}

	5、数组在使用时可以是一个含有变量的表达式，但是，在数组声明时必须用常量表达式
	example：
	// 合法     
	const int a=19;     
	long b[a];      
	// 合法     
	const int a=19;     
	long b[a+5];      
	// 不合法     
	int a=19;     
	long b[a+5];

	6、声明任意长度的数组，可以用显示的类型转换
	example：
	int a=19;
	int b[(const int)a ];
	或者：
	int a = 19;
	const int a1 = a;
	int b[a1];

	7、向量：
	Vector(向量): C++中的一种数据结构，确切的说是一个类。它相当于一个动态的数组，当程序员无法知道自己需要的数组的规模多大时，用其来解决问题可以达到最大节约空间的目的。
	用法： 1.文件包含: 首先在程序开头处加上 #include 以包含所需要的类文件vector;还有一定要加上 using namespace std; 
	       2.变量声明: 
			2.1例: 声明一个 int 向量以替代一维的数组: vector a; (等于声明了一个 int 数组 a[]，大小没有指定，可以动态的向里面添加删除)。
			2.2例: 用vector代替二维数组.其实只要声明一个一维数组向量即可，而一个数组的名字其实代表的是它的首地址,所以只要声明一个地址的向量即可，即: vector <int *> a。
			同理想用向量代替三维数组也是一样，vector <int**>a; 

	example：
	1、得到向量中的元素和数组一样
	example :
	vector <int *> a     
	int b = 5;     
	a.push_back(b);//该函数下面有详解     
	cout << a[0];       //输出结果为5

	2、使用数组给向量赋值：
	vector <int> v(a,a+sizeof(a)/sizeof(a[0]));
	或者 ：
	int a[]={1,2,3,4,5,6,7,8,9};     
	typedef vector<int> vec_int;     
	vec_int vecArray(a,a+9);

	*/

	return 0;
	
}

