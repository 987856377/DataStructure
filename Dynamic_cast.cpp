/*
	 				dynamic_cast
	static_cast可以实现子类到基类的安全转换，但是不能实现基类到子类的安全转换，
		如果想实现基类到子类的安全转换应用dynamic_cast类型转换;
注意：
	上行转换(子类到基类)是安全的，并且static_cast dynamic_cast是等效的
	下行转换(基类到子类)static_cast转换是不安全的但是dynamic_cast转换是安全的
	
dynamic_cast被用来执行从基类到子类的安全转换，转换的类类型(基类)必须有虚函数，否则不能使用dynamic_cast

dynamic_cast<type-id>(expression):
	如果type-id是void*类型，那么是expression类型。
	如果type-id是非void*类型，那么运行时检查指向 expression 的对象能否转换为指向 type-id 类型的对象。

*/
#include<iostream>
using namespace std;

class Employee{
	public:
   		virtual int salary(){
   			cout<<"Employee is calling . . . "<<endl; 
		}
		void work(){
			cout<<"Employee is working . . . "<<endl;
		}
    	virtual ~Employee(){
	} 
};
class Manager:public Employee{
	public:
    	int salary(){
    		cout<<"Manager is calling . . . "<<endl;
		}
		void work(){
			cout<<"Manager is working . . . "<<endl;
		}
};
class Programmer:public Employee{
	public:
    	int salary(){
			cout<<"Programmer is calling . . . "<<endl;
		}
    	int bonus(){
    		cout<<"Congratulations! ! !"<<endl;	
    	}
};

int main(){
	Employee *emp1 = new Employee;
	Manager *man = dynamic_cast<Manager*>(emp1);    //动态类型转换：基类到派生类，安全 
	emp1->work();
	man->work(); 
	
	Programmer *pro = new Programmer;
	Employee *emp2 = dynamic_cast<Employee*>(emp2);//动态类型转换：派生类到基类，不安全 
	pro->bonus();
	emp2->work();
	return 0;
} 
