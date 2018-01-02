























/*

//=======141==========
#include "routine.h"
void Family::set_family(string new_family_name, string new_home_address, int new_num_people)
{
	_family_name = new_family_name;
	_home_address = new_home_address;
	_num_people = new_num_people;	
}

void Family::get_family()
{
	cout << "The family name is " << _family_name << endl
		 << "The home adddress is " << _home_address << endl
		 << "The number of people in the family is " << _num_people << endl;	
}

void Son::set_son(string new_given_name)
{
	_given_name = new_given_name;	
}

void Son::get_son()
{
	cout << "The information of the son is " << endl;
	get_family();
	cout << "The given name is " << _given_name << endl;	
}




//=======140=========
#include "routine.h"

void Polygon::set_value(double new_length, double new_height)
{
	_length = new_length;
	_height = new_height;
}

void Rectangle::get_area()
{
	cout << "The area is " << _length * _height / 2. << endl;
}






//=========139========
#include "routine.h"
void test_visibility::test_cout()
{
	cout << "In the member function test_cout()" << endl;
	
}




//=======138========
#include "routine.h"

void Rectangle::get_info()
{
	cout << "LENGTH: " << _length << ", HEIGHT: " << _height << endl;
}

void Rectangle::set_info(Square & temp_square) //pass by reference, not a copy but itself.
{
	_length = temp_square._side;
	_height = temp_square._side + 1;
	
	temp_square._side = temp_square._side + 1;
	
}


void Square::get_side()
{
	cout << "SIDE: " << _side << endl;
}

void Square::set_side(Rectangle & temp_rectangle)
{
	_side = temp_rectangle._height;
}




//======137=========
#include "Routine.h"
Square::Square(): _side(0) {}
Square::Square(double ini_side): _side(ini_side) {}
Square::~Square()
{
	cout << "Destroying Square" << endl;
}
void Square::get_side()
{
	cout << "The side of the square is " << _side << endl;
}

void Square::set_side(double new_side)
{
	_side = new_side;
}

void change_side(Square &temp_square)
{
	//So the following two lines of code demonstrate that
	//temp_square._side = -1;	//we can actually change the value directly in the class
	temp_square.set_side(-1);
	cout << "The side of the square is changed to " << temp_square._side << endl;
}





//=========135=========
#include "routine.h"

void lover::set_lover(int ini_age)
//: _age {ini_age} {} //This is wrong because only constructor can take the initializer
{
	_age = ini_age;
}

int lover::get_age()
{
	return _age;
}




//=======134========
#include "routine.h"
//Info::Info(char ini_char, int ini_num)
//{
	//_char = ini_char;
	//_num = ini_num;	
//}

void Info::set_info(char ini_char, int ini_num)
{
	_char = ini_char;
	_num = ini_num;	
}

void get_info(void * struc, const Info & tem_info)
{
	((my_struct *) struc) -> my_char = tem_info._char;
	((my_struct *) struc) -> my_num = tem_info._num;
	cout << "Char is " << ((my_struct *) struc) -> my_char << ", num is "
	     << ((my_struct *) struc) -> my_num << endl;
}




//=======133=======
#include "routine.h"

//Person::Person(): _name {"Nodefaultname"}, _age {0} {cout << "Initializing" << endl;}
Person::Person(string ini_name, int ini_age): _name {ini_name}, _age {ini_age}
{cout << "In the initializer, not the default one" << endl;}
Person::~Person()
{
	cout << "Destroying the object" << endl;
}

void Person::get_info()
{
	cout << "Name is " << _name << ", age is " << _age << "." << endl;	
}
void steal_info(const Person & params_ptr)
{
	cout << "In the steal_info function, the name is " << params_ptr._name << endl;
}






//========132==========
#include "routine.h"

Rectangle::Rectangle(): _length {0.2}, _height {0.2}{}
Rectangle::~Rectangle(){cout << "Destroying the object" << endl;}
Rectangle::Rectangle(double ini_length, double ini_height)
:	//This : is the initializer
	_length {ini_length},	//Never use assignment operator, other error, cause it's 
							//initializing the object.
	_height (ini_height)
{}
void Rectangle::get_area()
{
	cout << _length << "	" << _height << "	" << _length * _height << endl;
}




//==========57===========
#include "routine.h"

person::person(string ini_name, int ini_age)
{
	_name = ini_name;
	_age = ini_age;		
}

void person::get_info()
{
	cout << "Name: " << _name << ", age: " << _age << endl;
}




//=============25===============
#include "routine.h"

void family_name::set_family_name (string new_family_name)
{
	_family_name = new_family_name;
}

string family_name::get_family_name()
{
	return _family_name;
}

void given_name::set_given_name(string new_given_name)
{
	_given_name = new_given_name;
}

string given_name::get_given_name()
{
	return _given_name;
}

full_name::full_name(string new_my_family_name, string new_my_given_name)
{
	_my_family_name.set_family_name(new_my_family_name);
	_my_given_name.set_given_name(new_my_given_name);	
}

string full_name::get_full_name()
{
	return _my_family_name.get_family_name() + _my_given_name.get_given_name();	
}



//============18============
#include "routine.h"
#include <iostream>

using namespace std;

//rectangle::rectangle()
//{
//	cout << "The default constructor is called." << endl;
//	//_length = 1.;
//	//_width = 1.;
//}

rectangle::rectangle(double ini_length, double ini_width)
{
	cout << "Initializing the rectangle " << endl;
	_length = ini_length;
	_width = ini_width;	
}

double rectangle::get_area()
{
	return _length * _width;
}

//member initializer list
cuboid::cuboid(double ini_length, double ini_width, double ini_height)
{
	base = {ini_length, ini_width};
	_height = ini_height;	
}



//:base {ini_length, ini_width}, _height {ini_height}
//{}

double cuboid::get_volumn()
{
	return base.get_area() * _height;	
}



//===========17=============
#include "routine.h"
#include <iostream>
//#include <string>

//using namespace std;
person::person()
{
	_name = "NAME";
	_age = {0};
	_height = 0;
	
}
person::person(string ini_name, int ini_age, double ini_height)
{
	_name = ini_name;
	_age = ini_age;
	_height = ini_height;
}

void person::get_person()
{
	cout << _name << endl 
		 << _age << endl
		 << _height << endl;
}


 
//===========16==========

#include "routine.h"
#include <iostream>

using namespace std;

apartment::apartment()
{
	cout << "The constructed is called." << endl;
	
	_num_residents = 0;
	cout << "The number of residents in the apartment is initialized to " << _num_residents
		 << endl;
}



//==========15===========
#include "routine.h"
//#include <iostream>	//This is necessary because of cout in the get_info() function.

using namespace std;

info::info(string ini_name, int ini_age)
{
	_name = ini_name;
	_age = ini_age;
	_height = 0;
}

info::info(string ini_name, double ini_height)
{
	_name = ini_name;
	_age = 0;
	_height = ini_height;
}

void info::set_info(string new_name, int new_age, double new_height)
{
	_name = new_name;
	_age = new_age;
	_height = new_height;	
}

void info::get_info()
{
	cout << "Name: " << _name << endl << "Age: " << _age << endl << "Height: " << _height 
		 << endl;
}




//===========14===========
#include <iostream>
//#include <string>
#include "routine.h"

using namespace std;

//the definition of the constructor
info::info()
{
	_family_name = "Zhao";
	_given_name = "Lianshui";
}

info::info(string ini_family_name, string ini_given_name)
{
	_family_name = ini_family_name;
	_given_name = ini_given_name;
}

void info::set_name(string new_family_name, string new_given_name)
{
	_family_name = new_family_name;
	_given_name = new_given_name;
}

void info::get_name()
{
	cout << "Your family name is " << _family_name << ", your given name is " << _given_name
		 << "." << endl;	
}



//==========13===========
#include <iostream>
#include "routine.h"
#include <string>

using namespace std;

void info::set_name(string new_family_name, string new_given_name)
{
	_family_name = new_family_name;
	_given_name = new_given_name;	
}

void info:: get_name()
{
	cout << "Your family name is " << _family_name	<< ", your given name is " << _given_name
	     << "." << endl;	
}



//===========11==========
#include "routine.h"
#include <iostream>

using namespace std;
void personal_information::get_name()
{
	cout << "My family name is " << family_name << ", my given name is " << given_name
		 << "." << endl;	
}

string personal_information::get_race()
{
	return race;	
}

double personal_information:: get_height()
{
	return height;	
}

int personal_information::get_age()
{
	return age;
}


//=============9=========

#include "routine.h"

void rectangle::set_size(double new_length, double new_height)
{
	_length = new_length;
	_height = new_height;
}
		
double rectangle::area ()
{
	return _length * _height;
}


//========================1============================
#include "routine.h"
#include <iostream>
using namespace std;

//=========Simpson's rule=============
//The weight in each subinterval is (h/3, 4*h/3, h/3)
double simpson(double low_end, double up_end, long int num_sub, void * params_ptr,
				double (* my_integrand) (double x, void * params_ptr))
{
	double h = (up_end - low_end)/(2. * num_sub); 	//the interval length
	double sum = 0; 	//initialize the sum
	for (long int i = 1; i <= num_sub; i++)
	{	
		//define the two points in the subinterval
		double x1 = low_end + h * (2*i -1); 		//the lower point
		double x2 = low_end + h * 2*i;		//the higher point
		
		sum += my_integrand(x1, params_ptr) * 4 + my_integrand(x2, params_ptr) * 2;
	}	
	
	sum += my_integrand(low_end, params_ptr) - my_integrand(up_end, params_ptr);
	
	sum *= h/3.;
	return sum;	
}

//=====Milne's rule=============
//The weight in each subinterval is (14h/45, 64h/45, 24h/45, 64h/45, 14h/45)
double milne(double low_end, double up_end, long int num_sub, void * params_ptr,
			double (* my_integrand) (double x, void * params_ptr))
{
	double h = (up_end - low_end)/(4. * num_sub); 	//the interval length
	double sum = 0; 	//initialize the sum
	
	for (long int i = 1; i <= num_sub; i++)
	{
		//define the 4 points in the subinterval
		double x1 = low_end + h * (4*i - 3);
		double x2 = low_end + h * (4*i - 2);
		double x3 = low_end + h * (4*i - 1);
		double x4 = low_end + h * (4*i);
		
		sum += my_integrand(x1, params_ptr) * 64 + my_integrand(x2, params_ptr) * 24
				+ my_integrand(x3, params_ptr) * 64 + my_integrand(x4, params_ptr) * 28;
	}
	
	sum += my_integrand(low_end, params_ptr) * 14 - my_integrand(up_end, params_ptr) * 14;
	sum *= h/45.;
	
	return sum;
}			
*/
