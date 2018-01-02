
//========148=======
#ifndef ROUTINE_H
#define ROUTINE_H
#include <iostream>

using namespace std;

class test_class
{
	private:
		int i;
		double d;
	public:
		test_class(int ini_i=3, double ini_d=2.3): i{ini_i}, d{ini_d} {}
		void get() 
		{
			cout << i << d << endl;
		}
	
	
};
#endif




/*

//======146=======
#ifndef ROUTINE_H
#define ROUTINE_H
#include <iostream>

using namespace std;
class base 
{
	protected:
		double _dou;
	public:
		base (): _dou{0.1} {}
		base (double ini_dou) : _dou{ini_dou} {}
		~base() {}
		void get_dou() 
		{
			cout << "_out_1 is " << _dou << endl;
		}
};


class base2
{
	protected:
		double _dou_3;
	public:
		base2 (): _dou_3{0.2} {}
		base2 (double ini_dou) : _dou_3{ini_dou} {}
		~base2() {}
		void get_dou_3() 
		{
			cout << "_out_3 is " << _dou_3 << endl;
		}
};

class derive : public base, public base2
{
	public:
		derive() {}
		derive(double ini_dou) : base(ini_dou), base2(ini_dou) {}
		void get_dou_2()
		{
			cout << "Call get_out() in the base class " << endl;
			get_dou(); 
			get_dou_3();
		}
};





#endif



//========144========
#ifndef ROUTINE_H
#define ROUTINE_H
#include <iostream>
#include <string>

using namespace std;

class School
{
	protected:
		string _school_name, _country_name;
	public:
		School(): _school_name{"OSU"}, _country_name{"USA"} {}
		School(string ini_school_name, string ini_country_name)
			: _school_name{ini_school_name}, _country_name{ini_country_name}
			{}
		void get_school()
		{
			cout << "The school name is " << _school_name << ", " << _country_name
				 << endl;
		}
};

class Work
{
	protected:
		string _company_name, _country_name;
	public:
		Work(): _company_name{"Intel/MS"}, _country_name{"USA"} {}
		Work(string ini_company_name, string ini_country_name)
			: _company_name{ini_company_name}, _country_name{ini_country_name}
			{}
		void get_work()
		{
			cout << "The working information is " << _company_name << ", " << _country_name
				 << endl;
		}
};

//You can specify the base as any access specifier, private/protected/public, but it will 
//affect the accessibility of the function members outside of the class
class Info : private School, public Work
{
	private:
		string _family_name, _given_name;
	public:
		Info(): School(), Work(), _family_name{"Zhao"}, _given_name{"Lianshui"} {}
		//If not explicitly specified, the default base constructor is called.
		Info(string ini_family_name, string ini_given_name)
			: _family_name{ini_family_name}, _given_name{ini_given_name}
			{}
		void get_info()
		{	
			cout << "My family name is " << _family_name << ", my given name is "
				 << _given_name << endl;
			get_school();
			get_work();
		}
};
#endif




//=======143==========
#ifndef ROUTINE_H
#define ROUTINE_H

#include <iostream>

using namespace std;

class test
{
	public:
		//static type, not really understand, but I know that a static type of function can
		//be called without a instance of object.
		static void print()
		{
			cout << "Hello world!" << endl;
		}	
};
#endif






//========142========
#ifndef ROUTINE_H
#define ROUTINE_H
#include <iostream>

using namespace std;

class base
{
	protected:
		int _int;
	public:
		base(): _int {2}{}
		base(int ini_int): _int{ini_int} {}
		~base() {cout << "Base is destroyed." << endl;}
		friend void get_int_base(base &);
};

void get_int_base(base & params_ptr)
{
	cout << "_int in base is " << params_ptr._int << endl;	
}

class derive: public base 
{
	public:
		derive(){cout << "The initial value is 2" << endl;}
		derive(int ini_int): base(ini_int) {}
		void change_int()
		{
			_int += 1;
		}
		friend void get_int_derive(derive &);
		void test_func(int x)
		{
			cout << "x is " << x << endl;
		}
};

void get_int_derive(derive & params_ptr)
{
	cout << "_int in derive is " << params_ptr._int << endl;	
}
#endif





//=======141========
#ifndef ROUTINE_H
#define ROUTINE_H
#include <iostream>
#include <string>

using namespace std;

class Family
{
	protected:
		string _family_name, _home_address;
		int _num_people;
		
	public:
		Family(): _family_name{"Zhao"}, _home_address{"CHINA"}, _num_people{5}
				  {cout << "Default values of class Family are set" << endl;}
		Family(string ini_family_name, string ini_home_address, int ini_num_people)
			: _family_name{ini_family_name}, _home_address{ini_home_address},
			  _num_people{ini_num_people}
			{cout << "You have set the values of class Family" << endl;}
		~Family() {cout << "The class Family has been destroyed" << endl;}
		void set_family(string new_family_name, string new_home_address, int new_num_people);
		void get_family();
};

class Son : public Family
{
	protected:
		string _given_name;
	public:
		Son(): _given_name{"Lianshui"} {}
		Son(string ini_given_name, string ini_family_name, string ini_home_address, int ini_num_people): Family{ini_family_name, ini_home_address, ini_num_people}, _given_name{ini_given_name}{}
		~Son() {cout << "The class son is destroyed" << endl;}
		void set_son(string new_given_name);
		void get_son();
};
#endif




//=======140=======
#ifndef ROUTINE_H
#define ROUTINE_H
#include <iostream>

using namespace std;

class Polygon
{
	protected:
		double _length, _height;
	public:
		Polygon(): _length{0}, _height{0} {cout << "Length and height are set to 0" << endl;}
		Polygon(double ini_length, double ini_height)
			: _length{ini_length}, _height{ini_height}
			{cout << ini_length << ini_height << endl;}
		~Polygon() {cout << "Destroying the class" << endl;}
		void set_value(double new_length, double new_height);
};

class Rectangle: public Polygon{
	public:
		Rectangle(){cout << "Rectangel 0 0" << endl;}
		Rectangle(double ini_length, double ini_height)
			: Polygon(ini_length, ini_height)
			{cout << "Rectangle and Polygon" << endl;}
		void get_area();
};
#endif





//========139========
#ifndef ROUTINE_H
#define ROUTINE_H
#include <iostream>
using namespace std;

class test_visibility
{
	public:
		void test_cout ();

};
#endif




//=======138=======
#ifndef ROUTINE_H
#define ROUTINE_H
#include <iostream>

using namespace std;

class Square;	//without this, the compiler complains that Square has not been declared.

class Rectangle
{
	friend class Square;
	private:
		double _length, _height;
	public:
		Rectangle():_length{0}, _height{0} { cout << "Initialized the rectangle to be 0, 0"
												  << endl;}
		Rectangle(double ini_length, double ini_height): _length{ini_length}, _height
														{ini_height} {}
		~Rectangle() {cout << "Destroying the rectangle." << endl;}
			
		void get_info();
		void set_info(Square & temp_square);
	
};

class Square
{
	friend class Rectangle;	//Rectangle can access all the members of Square, even modify
							//them directly.
	private:
		double _side;
	public:
		Square(double ini_side): _side {ini_side} {}
		void get_side();
		void set_side(Rectangle &);
	
};

#endif







//=======137========
#ifndef ROUTINE_H
#define ROUTINE_H
#include <iostream>

using namespace std;

class Square
{
	private:
		double _side;
	public:
		Square();
		Square(double ini_side);
		~Square();
		void set_side(double new_side);
		void get_side();
		friend void change_side(Square &);	//without const Square &, we can change the 
											//value of the original object via the friend
											//function.
};
#endif



//========135==========
#ifndef ROUTINE_H
#define ROUTINE_H
#include <iostream>

using namespace std;

class lover
{
	private:
		int _age;
	public:
		void set_lover(int ini_age);
		int get_age();	
};


#endif





//=======134========
#ifndef ROUTINE_H
#define ROUTINE_H
#include <iostream>

using namespace std;

struct my_struct
{
	char my_char;
	int my_num;	
};

class Info
{
	private:
		char _char;
		int _num;
	public:
		//Info(char ini_char, int ini_num);
		void set_info(char ini_char, int ini_num);
		//~Info();
		friend void get_info(void *, const Info &);
};

#endif




//=======133==========
#ifndef ROUTINE_H
#define ROUTINE_H
#include <iostream>
#include <string>

using namespace std;

class Person
{
	private:
		string _name;
		int _age;
	public:
		//Person();
		Person(string ini_name="hi", int ini_age=26);//The two variables can not be
													//initialized at the same time, 
													//otherwise it will conflict with
													//the constructor.
		~Person();
		void get_info();	
		friend void steal_info(const Person &);	//use & without questioning.
};
#endif





//==========132==========
#ifndef ROUTINE_H
#define ROUTINE_H
#include <iostream>

using namespace std;
class Rectangle
{
	private:
		double _length, _height;
	public:
		Rectangle();
		Rectangle(double ini_length, double ini_height = 1.1);	//default value
		~Rectangle();
		void get_area();	
};
#endif




 
//===========57===========
#ifndef ROUTINE_H
#define ROUTINE_H

#include <string>
#include <iostream>

using namespace std;

class person 
{
	private:
		string _name;
		int	_age;
	public:
		person(): _name {"Dog"}, _age {0} {};
		~person(){};
		person(string ini_name, int ini_age);
		void get_info();	
	
};

#endif



//=============25=============
#ifndef ROUTINE_H
#define ROUTINE_H

#include <string>	//<iostream> includes <string>, but it's implementation dependent.
using namespace std;

class family_name
{
	private:
		string _family_name;
	public:
		void set_family_name (string new_family_name);
		string get_family_name();	
};


class given_name
{
	private:
		string _given_name;
	public:
		void set_given_name(string new_given_name);
		string get_given_name();	
};

class full_name
{
	private:
		family_name _my_family_name;
		given_name _my_given_name;
	public:
		full_name(string new_my_family_name, string new_my_given_name);
		string get_full_name();
	
};

#endif



//===========18===============
#ifndef ROUTINE_H
#define ROUTINE_H

class rectangle
{
	private:
		double _length, _width;
	public:
		rectangle(){};	//Here the default constructor is not needed to be defined, empty!
		rectangle(double ini_length, double ini_width);
		
		double get_area();	
};

class cuboid
{
	private:
		rectangle base;
		double _height;
	public:
		cuboid(double ini_length, double ini_width, double ini_height);
		
		double get_volumn();
	
	
};
#endif




//===========17============ 
#ifndef ROUTINE_H
#define ROUTINE_H

#include <string>
#include <iostream>
using namespace std;

class person
{
	private:
		string _name;
		int _age;
		double _height;
	
	public:
		person();
		person(string ini_name, int ini_age, double ini_height);
		
		void get_person();	
};

#endif


 
//===========16============
#ifndef ROUTINE_H
#define ROUTINE_H

class apartment
{
	private:
		int _num_residents;
	public:
		apartment();	
};

#endif


//===========15=========
#ifndef ROUTINE_H
#define ROUTINE_H
#include <string>
using namespace std;

class info
{
	private:
		string _name;
		int _age;
		double _height;
	
	public:
		info(string ini_name, int ini_age);
		info(string ini_name, double ini_height);
		
		void set_info(string new_name, int new_age, double new_height);
		void get_info();	
};
#endif



//=========14=========
#ifndef ROUTINE_H
#define ROUTINE_H

//#include <string>
using namespace std;

class info
{
	private:
		string _family_name, _given_name;
	
	public:
		//this is the constructor which can be defined outside of the header file. By 
		//matching the types of the arguments, we can do overloading 
		info();
		info(string ini_family_name, string ini_given_name);
		
		void set_name (string new_family_name, string new_given_name);
		void get_name ();	
};

#endif



//===============13===============
#ifndef ROUTINE_H
#define ROUTINE_H
#include <string>
using namespace std;
class info
{
	private:
		string _family_name, _given_name;
	public:
		void set_name(string new_family_name, string new_given_name);
		void get_name();	
} MY_INFO;
#endif



//=========11=======
//guards
#ifndef _ROUTINE_H_INCLUDED_
#define _ROUTINE_H_INCLUDED_

#include <string>
//#include <iostream>
using namespace std;
class personal_information
{
	private:
		string family_name="Zhao", given_name="family_name";
		double height = 180;
		int age = 27;
		string race = "Asian";
	
	public:
		void get_name();
		string get_race();
		double get_height();
		int get_age ();	
};
#endif



//=============9============
class rectangle
{
	private:
		double _length, _height;
	
	public:
		void set_size(double new_length, double new_height);

		double area ();
		
}my_rectangle;


//==============1==================
double simpson(double low_end, double up_end, long int num_sub, void * params_ptr,
				double (* my_integrand) (double x, void * params_ptr));
				
double milne(double low_end, double up_end, long int num_sub, void * params_ptr,
			double (* my_integrand) (double x, void * params_ptr));
*/
