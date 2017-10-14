/*
				explicit				
	1 是个构造器 ，2 是个默认且隐含的类型转换操作符。
	explicit构造函数是用来防止隐式转换
	普通构造函数能够被隐式调用。而explicit构造函数只能被显式调用。

*/

#include<iostream>
#include<cstdlib>
using namespace std;

class Test1
{
public:
    Test1(int n)
    {
        num=n;
    }//普通构造函数
private:
    int num;
};
class Test2
{
public:
    explicit Test2(int n)
    {
        num=n;
    }//explicit(显式)构造函数
private:
    int num;
};
int main()
{
    Test1 t1=12;//隐式调用其构造函数,成功
    Test2 t2=12;//编译错误,不能隐式调用其构造函数
    Test2 t2(12);//显式调用成功
    return 0;
}
