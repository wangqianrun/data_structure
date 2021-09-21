#include <iostream>
using namespace std;
#include <string>


enum signType{aplus,aminus};
//创建类currency
class currency
{
public:
	//构造函数
	currency
	(
		 signType theSign = aplus,
	unsigned long theDollars = 0,
	unsigned int theCents = 0
	);

	
	//析构函数
	~currency(){}
	void setValue(signType, unsigned long, unsigned int);
	void setValue(double);
	signType getSign()const { return sign; }
	unsigned long getDollars()const { return dollars; }
	unsigned int getCents() const { return cents; }
	currency add(const currency&)const;
	currency& increment(const currency&);
	void output()const;
	void input();
	currency subtract(double);
	currency percent(double);
	currency multiply(double);
	currency divide(double);

private:
	signType sign;  //对象的符号
	unsigned long dollars;//对象的数量
	unsigned int cents;//美分的数量
};

currency::currency(signType theSign, unsigned long theDollars, unsigned int theCents)
{
	setValue(theSign, theDollars, theCents);
}
void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents)
{
	if (theCents > 99)
		// 抛出异常 throw illegalParameterValue("Cents should be <100");
		cout << "输入错误" << endl;
	sign = theSign;
	dollars = theDollars;
	cents = theCents;
}
void currency::setValue(double theAmount)
{
	if (theAmount < 0) { sign = aminus;theAmount = -theAmount; }
	else sign = aplus;
	dollars = (unsigned long)theAmount;
	cents = (unsigned int)((theAmount + 0.001 - dollars) * 100);
}

void currency::input()
{
	signType theSign;
	unsigned long theDollars;
	unsigned int theCents;
	cout << "请输入值" << endl;
	cin >> theSign >> theDollars >> theCents;
	setValue(theSign, theDollars, theCents);
}

currency currency::subtract(double x)
{
	long a1, a3;
	currency result;
	a1 = dollars * 100 + cents;
	if (sign == aminus)a1 = -a1;
	a3 = a1 - x;
	if (a3 < 0) { result.sign = aminus; a3 = -a3; }
	else result.sign = aplus;
	result.dollars = a3 / 100;
	result.cents = a3 - result.dollars * 100;
	return result;
}
currency currency::percent(double x)
{
	long a1, a3;
	currency result;
	a1 = dollars * 100 + cents;
	a3 = a1 * (x / 100);
	if (a3 < 0) { result.sign = aminus, a3 = -a3; }
	else result.sign = aplus;
	result.dollars = a3 / 100;
	result.cents = a3 - result.dollars * 100;
	return result;

}
currency currency::multiply(double x)
{
	long a1, a3;
	currency result;
	a1 = dollars * 100 + cents;
	a3 = a1 * x;
	if (a3 < 0) { result.sign = aminus, a3 = -a3; }
	else result.sign = aplus;
	result.dollars = a3 / 100;
	result.cents = a3 - result.dollars * 100;
	return result;

}
currency currency::divide(double x)
{
	long a1, a3;
	currency result;
	a1 = dollars * 100 + cents;
	a3 = a1 / x;
	if (a3 < 0) { result.sign = aminus, a3 = -a3; }
	else result.sign = aplus;
	result.dollars = a3 / 100;
	result.cents = a3 - result.dollars * 100;
	return result;
}



//欧几里得算法
int gcd(int a, int b)
{
	if (b == 0) return a;
	else return(gcd(b, a % b));
}
int main()
{
	
}


//编写递归函数，判断x是否在数组a[0:n-1]上
//#include <bits/stdc++.h> // 万能头文件（注意：POJ上无法使用）
//using namespace std;
//
//template<class T>
//bool in_the_array(const vector<T>& a, int x, int pos) //递归判断元素x是否在数组a中，其中pos代表数组的元素位置，pos < n时合法
//{
//	int n = a.size();
//
//	if (pos >= n) return false;
//
//	if (x == a[pos] && pos < n)
//		return true;
//	else
//		return in_the_array(a, x, pos + 1); // 递归判断元素x是否在数组a中
//}
//
//int main()
//{
//	vector<int> a{ 1, 3, 2, 4, 3, 6, 5 }; // 自定义数组（向量）
//	int x; // 待判断元素
//	while (cin >> x)
//	{
//		if (in_the_array<int>(a, x, 0)) // 调用递归函数
//			cout << "Yes\n";
//		else
//			cout << "No\n";
//	}
//	return 0;
//}