#include <iostream>
using namespace std;
#include <string>


enum signType{aplus,aminus};
//������currency
class currency
{
public:
	//���캯��
	currency
	(
		 signType theSign = aplus,
	unsigned long theDollars = 0,
	unsigned int theCents = 0
	);

	
	//��������
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
	signType sign;  //����ķ���
	unsigned long dollars;//���������
	unsigned int cents;//���ֵ�����
};

currency::currency(signType theSign, unsigned long theDollars, unsigned int theCents)
{
	setValue(theSign, theDollars, theCents);
}
void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents)
{
	if (theCents > 99)
		// �׳��쳣 throw illegalParameterValue("Cents should be <100");
		cout << "�������" << endl;
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
	cout << "������ֵ" << endl;
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



//ŷ������㷨
int gcd(int a, int b)
{
	if (b == 0) return a;
	else return(gcd(b, a % b));
}
int main()
{
	
}


//��д�ݹ麯�����ж�x�Ƿ�������a[0:n-1]��
//#include <bits/stdc++.h> // ����ͷ�ļ���ע�⣺POJ���޷�ʹ�ã�
//using namespace std;
//
//template<class T>
//bool in_the_array(const vector<T>& a, int x, int pos) //�ݹ��ж�Ԫ��x�Ƿ�������a�У�����pos���������Ԫ��λ�ã�pos < nʱ�Ϸ�
//{
//	int n = a.size();
//
//	if (pos >= n) return false;
//
//	if (x == a[pos] && pos < n)
//		return true;
//	else
//		return in_the_array(a, x, pos + 1); // �ݹ��ж�Ԫ��x�Ƿ�������a��
//}
//
//int main()
//{
//	vector<int> a{ 1, 3, 2, 4, 3, 6, 5 }; // �Զ������飨������
//	int x; // ���ж�Ԫ��
//	while (cin >> x)
//	{
//		if (in_the_array<int>(a, x, 0)) // ���õݹ麯��
//			cout << "Yes\n";
//		else
//			cout << "No\n";
//	}
//	return 0;
//}