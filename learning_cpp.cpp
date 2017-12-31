//======155======
//This program is to practice copying one string to another.
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string a = "Hi I love you!",
           b;

    b = a;  //In C, this does not what we want.
    cout << b << endl;
}







/*


//=======154==========
//This program is to practice clearing the previous string stream.
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	ostringstream my_stream;
	my_stream << "hi";

	cout << my_stream.str() << endl;

	//my_stream.clear();
	my_stream.str("");
	my_stream << "Man Guniang";
	cout << my_stream.str() << endl;

    struct person
    {
        string name = "zhao";
        int age = 27;
    };

    struct person me;   //in c, struct should be present in front of the statement.
    cout << "name: " << me.name << ", age: " << me.age << "." << endl;

}





//========153======
//This program is to test 0/0
#include <iostream>

using namespace std;

int main()
{
	//No it does not work
	//cout << 0/0 << endl;

}



//=======152========
//This program is to practice fixed and setprecision
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
	int i;
	cout << "Enter the precision number ";
	cin >> i;

	string my_str;
	ostringstream mysstream;
	mysstream << "HI" << setprecision(i) << .3249;

	my_str = mysstream.str();

	cout << my_str << endl;
}




//=======151========
//This program is to calculate pow(2,20)
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	cout << pow(2, 20) << endl;
}




//========150=========
//This program is to test arrays
#include <iostream>

using namespace std;

int main()
{
	int a [4];	//only 0, 1, 2, 3 elements are declared, not beyond this limit.

	//a[7] = 3;	//segmentation fault.

	cout << a[6];
}




//========149========
//This program is to practice initializing the array
#include <iostream>

using namespace std;

int main()
{
	//when initializing an array of many elements, you have to use a loop to do that.
	int a [3] ={0};	//a[2]=0; is wrong
	cout << a[1] << endl;

}





//========148========
//This program is to practice setting the default value in the constructor
#include "routine.h"

int main()
{
	test_class my_test;
	my_test.get();
}




//=======147========
//This program is to practice initialization of a structure
#include <iostream>
#include <string>

using namespace std;
int main()
{
	struct mystruct
	{
		int my_int;
		double my_double;
		string my_string;
	};

	//Initialize at once.
	mystruct ms ={2, 2.3, "hi"};

	cout << ms.my_int << ms.my_double << ms.my_string << endl;
}




//=======146========
//This program is to practice the pointers to base class. Even though the derived class is
//built on more than one base class, & derived_object will assign the correct address to
//the type defined by the declaration. See base2 and base typed pointers.
#include "routine.h"

int main()
{
	derive my_derive; 	//In the class the default constructor has to be present, otherwise
						//error.

	my_derive.get_dou_2();

	cout << "======" << endl;
	base2 * ptr = & my_derive;
	ptr -> get_dou_3();
	//(* ptr).get_dou_3(); 	//the pointer can not access get_dou_2(), because that's not in
						//the base class but in the derived class.

	cout << "=======" << endl;
	base * ptr_base = & my_derive;
	ptr_base -> get_dou();
}





//=======145========
//This program is to practice if strct has a derived type
//Yeah, just like the class type the struct type can also have a derived struct with
//the similiar syntax. Without the access visibility, the default is public, however for
//class the default is private.
#include <iostream>
#include <string>

using namespace std;

int main()
{
	struct person
	{
		string name;
		int age;
	};

	struct person2 : person
	{
		string home_address;
	};

	person2 me, * ptr = & me;
	me.name = "zhao";
	me.age = 27;
	me.home_address = "USA";

	cout << me.name << me.age << me.home_address << endl;
	cout << (* ptr).age << endl;
}




//=======144========
//This program is to practice using more than one base class
#include "routine.h"

int main()
{
	Info my_info("Seth", "Zhao");

	my_info.get_info();

}



//=========143=========
//This program is to practice calling a member function in a class from outside

#include "routine.h"

int main()
{
	//test my_test;
	test::print();

}



//========142========
//This program is to test if the derived class could change the values in the base class
#include "routine.h"

int main()
{
	derive my_derive;
	get_int_derive(my_derive);
	my_derive.change_int();
	get_int_derive(my_derive);
}



//=======141=========
//This program is to practice derived class again. When initializing the derived class,
//the base class is initialized first, so put base initializer at the very beginning,
//otherwise error.
#include "routine.h"

int main()
{
	Son me("Seth", "h", "i", 4);
	me.get_son();

}





//=======140===========
//This program is to practice derived class
#include "routine.h"

int main()
{
	Rectangle my_rec(2, 4);
	//my_rec.set_value(2, 3);
	my_rec.get_area();
}





//========139=========
//This program is to practice the visibilit of public members in a class
#include "routine.h"

int main()
{
	test_cout();
}




//=======138========
//This program is to practice friend class, which can access directly the private and
//protected members of another class
#include "routine.h"

int main()
{
	Square my_square (2);
	my_square.get_side();
	Rectangle my_rectangle;

	for (int i = 1; i < 5; i++)
	{
		my_rectangle.set_info(my_square);

		my_rectangle.get_info();
		my_square.set_side(my_rectangle);
		my_square.get_side();
	}
}





//========137=========
//This program is to test if the friend function can change the value of an object
#include "routine.h"

void Not_friend(Square &temp_square)		//pass the value by reference instead of by value
										//so it saves time, but if don't want the values
										//changed, you should add const in the declaration
										//like const Square $temp_square, just like we did
										// before for fundamental data types.
{
	//tem_square._side = 0; //Error: since this function is NOT a friend function of the
							//class, so it can NOT access the private member directly, but
							//can access the public members.
	temp_square.set_side (0);
	cout << "Not_friend changed _side to "  << endl;
	temp_square.get_side();
}

int main()
{
	Square my_square(2);
	my_square.get_side();

	change_side(my_square);
	my_square.get_side();

	Not_friend(my_square);
	my_square.get_side();
}




//=======136========
//This program is to practice assignmet of value to each element of an array
#include <iostream>

using namespace std;

int main()
{
	int a[3] = {4, 8, 9};
	for (int i = 1; i < 4; i ++)
	{
		//int a[i] = i; //No you can not assignment value to array elements like this,
						//it's different from that to a variable.
		a[i] = i;

		cout << a[i] << endl;

	}

}





//======135======
//This program is to practice an array of type of a class
#include "routine.h"

int main()
{
	lover my_lover[87];
	for (int i = 27; i < 32; i++)
	{
		my_lover[i].set_lover(i);
		cout << my_lover[i].get_age() << " " << endl;
	}
}




//=======134==========
//This program is to practice friend function inside a class
#include "routine.h"

int main()
{
	//Info my_info[3];

	for (int i = 0; i < 3; i++)
	{

		Info my_info[i];
		my_info[i].set_info (char(65+i),65+i);
		my_struct my_st[i];
		get_info(& my_st[i], my_info[i]);
	}


}




//======133=========
//This program is to use practice the friend function which is DECLARED inside a class,
//but it's NOT a member function, but again it can used to access the private and protected
//members inside the class.
#include "routine.h"

int main()
{
	Person me;
	me.get_info();
	steal_info(me);
}




//=======132======
//This program is to practice assigning an object to another
#include "routine.h"

int main()
{
	//Just like the fundamental data types, a class object can be used to assign values
	//to another.
	Rectangle my_rectangle(10, 11), you_rectangle = my_rectangle;

	you_rectangle.get_area();
}




//========131==========
//This program is to practice assigning a variable to another without assigning a value to
//the first one.
#include <iostream>

using namespace std;

int main()
{
	int a;
	//It will give a warning that a is uninitialized.
	int b = a;

	cout << b << endl;
}



//==========130=============
//This program is to practice passing a variable to a const in a function
#include <iostream>

using namespace std;

void prin(const int a, int arr[])
{
	cout << "a is " << a << "\n";
	//a++;	//error: read-only parameter

	//cout << arr[1] << endl;

	for (auto c : arr)
	{
		cout << c << endl;
	}
}

int main()
{
	int a = 3, b [] {1, 2, 3};

	prin(a, b);


	return 0;
}





//========129=======
//This program is to practice ifstream and ofstream
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string mystr;
	ostringstream mystream;

	cout << "Enter the name of the file: ";
	getline(cin, mystr);
	mystream << mystr << "129";

	ofstream myout (mystream.str(), ios::trunc);

	if (! myout.is_open())
		cout << "Failed to open file " << mystream.str() << endl;
	else
	{
		for (int i = 1; i < 5; i++)
		{
			myout << "This is line " << i << endl;
		}
		myout.close();
	}
	system("cat out129");

	ifstream myinput (mystream.str());

	for (int i = 1; i <= 16; i++)
	{
		myinput >> mystr;
		if (i % 4 == 0)
			cout << mystr << endl;
	}

	myinput.seekg(6);
	cout << "The position of the control is now at " << myinput.tellg() << endl;
	//getline() terminates at the end of the line where \n is read.
	while (getline(myinput, mystr))
	{
		cout << mystr << endl;
	}
	myinput.close();

	//istringstream integer to a character
	mystr = "65";
	istringstream myin(mystr);

	int in;
	myin >> in;

	cout << char(in) << endl;
}





//========128=======
//This program is to practice file stream
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream myfile("a128", ios::trunc | ios::out);
	string mystr;
	if (! myfile.is_open())
		cout << "Failed to open file a128." << endl;
	else
	{
		myfile << "Hi Seth, you are going to be great!" << endl;
		cout << "The position of the contron now is at " << myfile.tellp() << endl;
		myfile.seekg(1);
		cout << "The position is now at " << myfile.tellg() << endl;
		myfile >> mystr;
		cout << mystr << endl;
	}
	myfile.close();
	system("cat a128");
}





//========127=======
//This program is to practice call more than one time stringstream, and clear the previous
//contents in the stream.
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	string mystr;
	stringstream mystream;

	for (int i = 0; i < 5; i++)
	{
		mystream << i << " ";
		cout << mystream.str() << endl;
		//This is to clear the stream.
		mystream.str("");
		//This more efficient.
		mystream.str(string());
	}

	mystream << 23;
	cout << mystream.str() << endl;

}




//==========126============
//This program is to practice more aspects of stringstream
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	string mystr;
	double mydouble;

	cout << "Enter a num: ";
	getline(cin, mystr);
	//istringstream (mystr) >> mydouble;
	//stringstream (mystr) >> mydouble;

	//Initialize the object with a string.
	stringstream mystream("2");
	cout << "The initialized value is: " << mystream.str() << endl;
	mystream << mystr;
	mystream >> mydouble;
	//cout << mystream.str() << endl;
	cout << "Mydouble is " << mydouble << endl;

	//You can NOT do this because this object has been declared so it can not initialized
	//again, but can assign value by mystream << soemthing.
	//mystream("hi");
	mystream << "11111";
	cout << "final " << mystream.str() << endl;
}




//========125=========
//This program is to parctice string array
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string mystr[] {"h i", "my", "love"};

	for (auto str : mystr)
	{
		cout << str << endl;
	}


}




//=========124==========
//This program is to practice stringstream, which can both have istringstream and
//ostringstream members, both of which can be initialized.
#include <sstream>
#include <iostream>

using namespace std;

int main()
{
	string my_str;
	int my_int;

	ostringstream myout("xxoo");
	myout << "hI";

	my_str = myout.str();
	cout << my_str << endl << "=========" << endl;

	stringstream mystream("dodg");
	//mystream << "Hi" << endl;
	mystream >> my_str;
	//my_str = mystream.str();
	cout << my_str << endl << "==========" << endl;

	istringstream myinput("12 3");
	myinput >> my_int;
	cout << my_int << endl;
	myinput >> my_str;
	cout << my_str << endl;
	myinput >> my_int;
	cout << my_int << endl;
}





//==========123======
//This program is to practice defining a function inside the main or another function
#include <iostream>

using namespace std;
void add (int i)
{
	//The same error, can not define a function inside a function.
	void add_in(int i)
	{
		cout << i << endl;
	}
}
int main()
{
	//Failed.
	//void add (int i)
	//{
	//	cout << i;
	//}

	add (3);
}



//==========122=======
//This program is to practice passing a function to another
#include <iostream>

using namespace std;

int add_1(int i);
void add_2(int (* f) (int i), int i);

int main()
{
	add_2(add_1, 2);
}

int add_1(int i)
{
	return i;
}

void add_2(int (* f)(int i), int i)
{
	cout << "In add_2, the value passed from add_1 is " << f(i) << endl;

}





//============121==========
//This program is to practice insert new data in an old file
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	string my_str;

	fstream myout ("out121", ios::out);

	if (! myout.is_open())
		cout << "Failed to open the file!" << endl;
	else
	{
		for (int i = 1; i < 8; i=i+1)
		{
			myout << "This is line " << i << endl;
		}

		myout.seekp(2);
		myout << "I";
		myout.close();
		system("cat out121");
	}

	fstream myinput("out121", ios::in);
	if (! myinput.is_open())
		cout << "Failed to open the file!" << endl;
	else
	{
		myinput.seekg(13);
		myinput >> my_str;
		cout << my_str << endl;

		myinput.seekg(0, ios::beg);
		cout << myinput.tellg() << endl;

		myinput.close();
	}

	//How to insert something at some specific position without overwriting the original
	//data.
	ofstream myout1("out121", ios::app);
	myout1.seekp(2);	//This does work, since mode app always make the control write the
						//data at the end of the file.
	myout1 << "HH";

	myout1.close();
}





//========120=======
//This program is to practice streampos
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	string filename_main;
	ostringstream filename_total;

	cout << "Enter the main part of the filename: ";
	cin >> filename_main;

	filename_total << filename_main << "120";

	ofstream myout(filename_total.str(), ios::trunc);
	if (! myout.is_open())
		cout << "Failed to open the file " << filename_total.str() << endl;
	else
	{
		for (int i = 1; i < 6; i++)
		{
			myout << "This is line " << i << "\n";
		}
		myout.close();
	}
	system("cat out120");


	ifstream myinput(filename_total.str());
	if (! myinput.is_open())
		cout << "Failed to open the file " << filename_total.str() << endl;
	else
	{
		//Here streampos can also be replaced by int (int begine, end;)
		streampos begine, end;
		myinput.seekg(0, ios::beg);
		begine = myinput.tellg();
		myinput.seekg(0, ios::end);
		end = myinput.tellg();
		cout << end << endl;
		cout << "end - begine is " << end - begine << endl;


	}
}





//==========119==========
//This program is to practice the streampos
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	ostringstream filename_total;
	string filename_main, my_str;
	cout << "Please enter the main part of the file name: ";
	cin >> filename_main;

	filename_total << filename_main << "119";

	ofstream myout(filename_total.str());

	if (! myout.is_open())
		cout << "Open failed!" << endl;
	else
	{
		cout << "Open successfully!" << endl;

		for (double i = 10; i < 15; i++)
		{
			//ofstream has NO tellg() member function, so you can NOT use it.
			cout << "The stream position of the current control is: " << myout.tellp()
				 << "	" << endl;
			//With and without << endl following i give different stream position, so I
			//think endl is counted as another position.
			myout << i << endl;

		}
		myout.close();
	}

	ifstream myinput(filename_total.str());
	for (int i = 0; i <= 12; i=i+3)
	{
		myinput.seekg(i);
		cout << "position " << myinput.tellg();
		myinput >> my_str;
		cout << ": " << my_str << " the position now is " << myinput.tellg() << endl;
	}

	//endl is different from a space, when the position is at the endl the control can still
	//read the next string, while a space only makes the control read the space instead of
	//the next "non-space" string.
	myinput.seekg(2, ios::beg);
	cout << "The current position is " << myinput.tellg();
	myinput >> my_str;
	cout << my_str << endl;
	cout << "Now the position is at " << myinput.tellg() << endl;
	myinput.seekg(-3, ios::cur);
	cout << "Now the position is at " << myinput.tellg() << endl;
	myinput >> my_str;
	cout << my_str << endl;

	cout << "======" << endl;
	myinput.seekg(0, ios::end);
	cout << "The position is now at " << myinput.tellg() << endl;
	myinput.seekg(-3, ios::cur);
	cout << "The position is now at " << myinput.tellg() << endl;
	myinput >> my_str;
	cout << my_str << endl;
}





//=========118======
//This program is to test how to split strings with spaces in it into different strings.
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string my_str = "hello world !";

	cout << my_str [0] << endl;

	ostringstream cat;
	for (int i = 1; i <= 10; i++)
	{
		//concatenate the numbers into a sequence
		cat << i << " ";
	}
	my_str = cat.str();
	cout << my_str << endl;
}



//=========117=======
//This program is to practice
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	string my_line;
	int data;

	ofstream myout ("out117", ios::trunc);
	for (int i = 1; i < 5; i++)
	{
		myout << "This is line " << i << endl;
	}
	myout.close();

	ifstream myinput ("out117"), myinput_word("out117");
	if (! myinput.is_open())
		cout << "Failed to open the file" << endl;
	else
	{
		int j = 1;
		while (getline(myinput, my_line))
		{
			cout << "Line " << j++ << endl;
			//There are two controls here, one is to loop through the lines, and the other
			//is to read the data which are seperated by spaces. Alos stringstream is used
			//to convert string-typed integer to numerical integer.
			for (int i = 1; i <=4; i++)
			{
				myinput_word >> my_line;
				if (i == 4)
				{
					stringstream(my_line) >> data;
					cout << "This is data: " << 2*data;
				}
				else if (i == 2)
				{
					cout << (char) (my_line[1] - 32) << char(115) << " ";
				}
			}
			cout << endl;
		}
	}
}




//===========116==========
//This program is to practice reading from a file
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int data;

	ofstream myout("out116", ios:: binary);
	for (int i=3; i < 5; i++)
	{
		myout << i << "\n";
	}
	myout.close();

	ifstream myinput ("out116");

	//for an ofstream object, there are a few important member functions which are open(),
	//close(), is_open(), and of course constructors and destructors.
	if (myinput.is_open())
		cout << "Open successfully!";
	else
		cout << "Open failed!";
	myinput.close();

	system("cat out116");
}



//========115=========
//Since string a kind of data type, it should have array and pointer format, so here I'm
//going to test it.
#include <iostream>
#include <string>

using namespace std;

int main()
{
	//() is the constructor initialization, {} is the universal initialization
	string my_str ("Hello	"), my_str_arr [] {"world	", "!"}, * my_str_ptr = my_str_arr;

	cout << my_str << my_str_arr[0] << my_str_arr[1] << endl;
	int i = 0;

	//range-based for loop is super useful and convenient to output the elements of arrays.
	for (auto temp : my_str_arr)
	{
		cout << i ++ << "	" << temp << endl;
	}

	cout << "pointer: " << * (my_str_ptr++) << endl;
	cout << "pointer: " << * my_str_ptr ++ << endl;

	//Even though the name of the array is like a pointer which contains the address,
	//it can NOT be changed (++, --) while a pointer pointing to an array can.
	cout << "my_str_arr: " << * (my_str_arr+1) << endl;
}





//========114==========
//This program is to practice writing to and reading from a file.
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string my_line[2];

	ofstream myout("out114");

	myout << "hi" << endl << 4 << endl;
	myout.close();

	cout << "From calling system cat: " << endl; 	//weird without << endl, the content
													//is above this line. why?
	system("cat out114");

	cout << "From calling ifstream: " << endl;
	ifstream myin("out114");
	myin >> my_line[0];
	myin >> my_line[1];

	for (auto tem : my_line)
	{
		cout << tem << endl;
	}

}




//=========113=======
//This program is to practice stringstream
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	string mystr, mystrcopy;
	double a;

	cout << "Enter a number: ";
	getline(cin, mystr);
	stringstream (mystr) >> a;
	cout << a << endl;
}



//=======112=======
//This program is to practice getting a sentence
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string my_str;
	cout << "Enter a string: ";

	cin >> my_str;	//space terminates the input value.
	getline(cin, my_str);	//getline terminates when ENTER is pressed.

	cout << my_str << endl;
}




//=========111========
//This program is to practice inputing two values.
#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cout << "Enter two integers: ";
	cin >> a >> b;
	//cin >> a;
	//cin >> b;
	cout << a << b << "\n";

}





//==========110==========
//This program is to practice the type casting (type_to_be_casted)
#include <iostream>

using namespace std;

int main()
{
	int i;
	double j = 2.343;

	i = (int) j;
	cout << i << endl;
}




//=========109==========
//This program is to practice the logical operator
#include <iostream>

using namespace std;

int main()
{
	int a = 2, b = 3;
	//short circuit: the program tries to get true, so once it's true, then the rest will
	//not execute, anyway it always tries to retain true.
	if (a == 2 && b ++ == 93 )
		cout << b << endl;
	cout << "out: " << b << endl;

	cout << "=======" << endl;
	if (! (2+3))	//better include the parentheses
		cout << "true" << endl;

	if (++a > 2)
		cout << a << "second true" << endl;

}




//==========108==========
//This program is to practice the increment operator
#include <iostream>

using namespace std;

int main()
{
	int a = 3;
	cout << a++ << endl;	//the value of expression a++ is just a, but then a is added
							//by 1
	cout << a << endl;
}



//========107=========
//This program is to practice the compound operator
#include <iostream>

using namespace std;

int main()
{
	int a = 3;
	int b = 2;
	a *= b+3;
	cout << a << endl;
}



//========106=======
//This program is to practice modulo operator, which is the remainder
#include <iostream>

using namespace std;

int main()
{
	cout << 22%3 << endl;
}





//=========105=======
//This program is to practice the assignment operation
#include <iostream>

using namespace std;

int main()
{
	int a = 5;
	int b = 2 + (a = 23);

	cout << a << "	" << b << '\n';
}




//========104========
//This program is to practice the preprocessor definitons #define
#include <iostream>
#include <iomanip>

using namespace std;
#define PI 3.14159265323	//sd
#define nl '\n'
int main()
{
	cout << setprecision(14) << PI << nl << "hi" ;
}




//=========103========
//This program is to practice \t tab \a alarm \n newline \v verticaltab
#include <iostream>

using namespace std;

int main()
{
	cout << "hi\a\tmy\vhisd\nhi\vdsd?f\b";
}



//=======102==========
//This program is to practice newline, '\n' and "\n" both make a new line.
#include <iostream>
#include <string>

using namespace std;

int main()
{
	char newline = '\n';
	string nl = "\n";
	cout << "hi" << newline << "hi"<< nl << "hi";
}





//=============101========
//This program is to practice boolean
#include <iostream>

using namespace std;

int main()
{
	bool tf = false && true;	//logical operator AND OR
	//bool tf = false || true;

	if (tf)
		cout << "True" << endl;
	else
		cout << "False" << endl;
}




//===========100=========
//This program is to practice \, which is a continuation mark
#include <iostream>

using namespace std;

int main()
{
	cout << "HITSDFS \
            HISDF." << endl;	//the spaces inside are introduced unintentionally

}




//==========99========
//This program is to practice e
#include <iostream>

using namespace std;

int main()
{
	double a = 2.3E3, b = 2e-3;	//e has to be the next character following the digits,
								//no space.

	cout << a << b << endl;
}




//=======98========
//This program is to practice auto and decltype
#include <iostream>

using namespace std;

namespace my_ns
{
	int x = 3;
}

int main()
{
	int a [] {1, 3, 4};
	auto * b = a;

	for (auto c : a)
	{
		cout << c << endl;
	}

	cout << b[1] << endl;

	cout << "======" << endl;


	decltype(my_ns::x) y = my_ns::x;
	auto z = my_ns::x;

	cout << y << z << endl;
}




//============97===========
//This program is to practice declaring the namespace
#include <iostream>

using namespace std;

//namespace my;	//this is wrong, it seems namespace can not be declared like this, but
				//can be like this: namespace my = std, which means you can not leave it
				//uninitialized.
namespace my
{
	int x = 5;
}

int main()
{
	using namespace my;
	cout << x << endl;
}




//=========96=========
//This is to test the initialization of global and local variables
#include <iostream>

using namespace std;
int x;
double y;
char z;

int main()
{
	cout << x << "	" << y << "	" << x << endl;	//all are initizalied to zeros only.

	int a;
	//double b;
	//char c;

	cout << a <<  endl;	//can not tell, but 0. Anyways it can be other values too.

}




//===========95=========
//This program is to practice std
#include <iostream>

using namespace std;

int main()
{
	int a =3;


}




//========94=========
//This program is to practice the namespace again
#include <iostream>

using namespace std;
namespace my_ns_1
{
	int x = 3;
	void pri(){cout << "hi";}	//if using namespace std is not delcared before, then
								//error (scope)
}

namespace my_ns_2
{
	int x = 4;
}

namespace newsp
{
	int y = 5;
}
//using namespace std;
int main()
{
	//combine old an old namespace to the new one
	//namespace newsp = std;	//here newsp is not the same as the one outside.
	cout << newsp::y << endl;

	//namespace newsp = my_ns_1;
	using namespace newsp;
	using namespace my_ns_1;
	cout << x << endl;
	cout << my_ns_1::x << my_ns_2::x << endl;

	//namespace my 	//The compiler complains that this definition is not allowed here.
	//{
	//	int x =3;
	//}

}




//===========93=========
//This program is to practice the namescope
#include <iostream>

using namespace std;

//namespace_1 prototype
namespace my_ns_1
{
	int add(int x);
}

//namespace_2 prototype
namespace my_ns_2
{
	int add(int x);
}

int main()
{
	cout << "my_ns_1: " << my_ns_1::add(2) << endl;
	cout << "my_ns_2: " << my_ns_2::add(3) << endl;
}

int my_ns_1::add(int x)
{
	return x+3;
}
int my_ns_2::add(int x)
{
	return x+30;
}





//===========92=========
//This program is to practice the local variable scope
#include <iostream>

using namespace std;

int main()
{
	int x = 10, * x_ptr = & x;	//store the address of x
	int y = 3, * y_ptr = & y;	//store the address of y

	//A new scope starts here
	{
		int x = 5; 	//A different x than the one outside the block
		y = 5;
		cout << "Inside the inner block: " << & x << "	" << x << endl;
		cout << "Inside the inner block: " << &y << "	" << y << endl;

		if (x_ptr == & x)
			cout << "The two x's are the same." << endl;
		else
			cout << "The two x's are not the same." << endl;

		if (y_ptr == & y)
			cout << "The two y's are the same." << endl;
		else
			cout << "The two y's are not the same." << endl;
	}

	cout << "Outside the inner block: " << & x << "	" << x << endl;
	cout << "Outside the inner block: " << & y << "	" << y << endl;
}





//=========91==========
//This program is to practice non-type template argument
#include <iostream>

using namespace std;

template < typename T, int N>
T add (T x);

int main()
{
	const int c=3;
	cout << add<int, c>(3);	//here c has to be a const, otherwise wrong, case it's needed
							//in compiler-time.
}
template < typename T, int N>
T add (T x)
{
	return x+N;
}




//==========90==========
//This program is to practice function template with a default value (overloads)
//function template is essentially all about the typenames
#include <iostream>

using namespace std;

template <typename T, typename U>	//the number of typenames have to be matched when the
									//the function is called.
double add (T a, double b=3.4)	//the function template can be set some default values
{
	return a+b;
}

int main()
{
	cout << add <int, double> (2, 23) << "    " << add <int, double> (3) << endl;
}




//=========89=========
//This program is to practice the overloads of function
#include <iostream>

using namespace std;
//This will cause a problem because when add is called with one argument, then the compiler
//will not know which one to execute.
int add(int x);
int add(int x, int y=3);
int main()
{
	cout << add (4, 4) << endl;
}

int add (int x)
{
	return x;
}

int add (int x, int y)
{
	return x+y;
}



//==============88==========
//This program is to practice function templates, here keyword "typename" is the same as
//"class"
#include <iostream>

using namespace std;

//function template prototype
template <typename T, typename U, typename V>
V add(T a, U b);


int main()
{
	cout << add <int, double, int> (2, 3.8) << endl;
}

//The definition of function template prototype
template <typename T, typename U, typename V>
V add(T a, U b)
{
	return a+b;
}




//=========87========
//This program is to practice the function overloads, which I think may be very important.
#include <iostream>

using namespace std;

void add(int x, int y);
void add(double x, double y);

int main()
{
	add (2, 3);
	add (2.2, 3.);

}

void add(int x, int y)
{
	cout << "int x + int y = " << x+y << endl;
}

void add (double x, double y)
{
	cout << "double x + double y = " << x+y << endl;
}




//===========86=============
//This program is to practice the recursivity of a function
#include <iostream>

using namespace std;

long facto(long a);

int main()
{
	//cout << sizeof(long) << sizeof(int) << endl;	//long=8, int=4
	cout << facto(5)；
}

long facto(long a)
{
	if (a != 1)
		return (a * facto(a-1));
	else if (a == 1)

		return 1;

}




//=========85========
//sometimes prototype is required as two functions are mutually called.
#include <iostream>

using namespace std;

void even(int);
void odd(int);

int main()
{
	int a;

	do
	{
		cout << "Enter an integer: ";
		cin >> a;

		even(a);
	}while(a != 0);
}

void even(int a)
{
	if (a % 2 == 0)
		cout << "Even" << endl;
	else
		odd(a);
}

void odd(int a)
{
	if (a % 2 == 1)
		cout << "Odd" << endl;
	else
		even(a);
}




//===========84===========
//This program is to practice default values in a function
#include <iostream>

using namespace std;

//Here when declaring a funciton with a default value, you must include the default value.
void chae(int a, int b=3);

int main()
{
	chae(0);
	chae(4, 9);
}

//Here when defining the function, you must NOT include that value, otherwise error.
void chae(int a, int b)
{
	cout << a << b << endl;
}




//========83=======
//This program is to practice adding two char values.
#include <iostream>

using namespace std;

int main()
{
	char a='a', b='b';

	//the sum of two chars are ascii values, int can also be convert to char type.
	cout << a+b << char(97) << endl;
}





//==============82============
//This program is to practice using the const reference in a function
#include <iostream>

using namespace std;

void chae(const int & x, int & y);

int main()
{
	int a = 2, b = 3;

	chae(a, b);
	cout << a << b << endl;

}

void chae(const int & x, int & y)
{
	y *= 2;
	//x *= 1;	//even the actual value is not changed but through the assignment statement.
	//x *= 3;	//the compiler complains that assignment of read-only reference, just
				//ready-only pointer
}




//==========81========
//This program is to practice calling functions by reference and pointers to a variable
#include <iostream>

using namespace std;

void chage(int & x);
void chage_ptr(int * ptr);

int main()
{
	int a = 2, b = 3;

	chage(a);
	chage_ptr(& b);

	cout << a << endl;
	cout << b <<endl;
}

void chage(int & x)
{
	x *= 2;
}

void chage_ptr(int * ptr)
{
	(* ptr) *= (*ptr);
}




//========80========
//This program is to practice length of an array
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int a [] {1, 2, 3, 4};
	//.length()is a member of string class
	//cout << a.length() << endl;
	cout << a << endl;	//a contains the address of the array.

	string my_str = "hi";
	cout << my_str.length() << endl;

	//again this char array does not have length() method.
	//array is not a class type
	char b [] {'z', 'd'};
	//cout << b.length() << endl;
	cout << b << endl;
	//array is not a class type
	char c [] = "hi";
	//cout << c.length() << endl;
	cout << c << endl;
}




//==========79=============
//This program is to practice break and continue statements in a loop, just like in a
//switch statement.
#include <iostream>

using namespace std;

int main()
{
	for (int i = 1; i < 10; i++)
	{
		cout << i << endl;
		if (i == 8)
		{
			cout << "breaking" << endl;
			break;	//jump out of the for loop, neglecting all the rest of iterations.
		}
		if (i == 4)
		{
			cout << "Wont' print another 4 here because of the continue statement" << endl;
			continue;
		}
		cout << i << endl;
	}
}





//==========78===========
//This program is to practice pointer and array.
#include <iostream>

using namespace std;

int main()
{
	char a [] = "hile", * a_ptr = a;	//char pointer can point to a char array, not string
									//type.
	//just like string literal.
	cout << a_ptr << a << endl;
	for (auto c : a)	//here auto is char in this case.
	{
		cout << c;
	}
	//cout << c << endl;	//c is active only in the for loop.
}




//==========77==========
//This program is to practice range-based for loop for string liberals or arrays.
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string my_str = "helloworld";
	int i=0;
	//char * my_ptr = my_str;	//wrong.

	for (char c : my_str)
	{
		//convert the lower case to upper case.
		cout << char(c-32);
		//string is essentially a char array.
		my_str[i++]=char(c-32);
		// * (my_ptr++) = char (c-32);	//wrong, you can not point to a string

	}
	cout << endl << my_str << endl;
}





//==========76========
//This program is to practice the range-based for loop
#include <iostream>

using namespace std;

int main()
{
	int a [] {1, 2, 3, 10};
	//a_ele can only be declared in the condition, NOT before.
	for (int a_ele : a)
	{
		cout << a_ele << endl;
	}

}





//==========75==========
//This program is to practice the loop with two counters
#include <iostream>

using namespace std;

int main()
{
	for (int i = 1, j = 10; i < 3 || j > 5; i++, j--)
	{
		cout << "i= " << i << ", j= " << j << endl;
	}
}




//============74========
//This program is to test the checking of the initial condition.
#include <iostream>

using namespace std;

int main()
{
	//before executing each loop i has to be checked with the condition even the first one.

	for (int i = 1; i < 1; i++)
	{
		cout << i << endl;
	}
}




//==========73===========
//This program is to practice do-while loop which executes at least once.
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string my_str;
	int a;

	do
	{
		cout << "Enter a word: ";
		getline(cin, my_str);
		stringstream(my_str) >> a;

	} while (a != 2 && my_str != "2");
}





//=============72==============
//This program is to practice while loop
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
	int i = 10;

	while (i > 0)
	{
		cout << i << ", ";
		this_thread::sleep_for(chrono::seconds(1));
		i --;
	}

	cout << " LIFTOFF!" << endl;
	cout << i << endl;

}





//==========71==========
//This program is to test the switch statement without break in some cases.
#include <iostream>

using namespace std;

int main()
{
	int a = 2;
	//by testing it, I found that if break is not specified, then the statements following
	//the case will be executing till a break or the end of the switch statement is reached.
	switch (a*35/2)
	{
		default:
			cout << "No" << endl;
		case 2:
			cout << "2" << endl;
		case 3:
			cout << "3" << endl;
			break;
		case 4:
			cout << "4"	<< endl;
	}
}





//===========70============
//This program is to test the switch statement
#include <iostream>

using namespace std;

int main()
{
	int a = 2;
	const int b = 2;	//this constant is used as a case in the switch statement.

	switch (a)
	{
		case 1:
			cout << "a=1" << endl;
			break;
		case 22:	//if it was 2, then the compiler would complain that duplicate case.
			cout << "a=2" << endl;
			break;
		case b:
			cout << "a=b" << endl;
			break;
		default:
			cout << "No match found!" << endl;
			break;
	}
}




//===========69===========
//This program is to test the logcal operator
#include <iostream>

using namespace std;

int main()
{
	//use parenthesis when necessary
	//logical NOT
	if (! (2 == 2))	//2 and 02 are the same.
		cout << "true." << endl;

	//logical AND and OR
	if ((2==1 || 2==2) && 1==1)
		cout << "At least one is right." << endl;

}



//==========68=============
//This program is to practice if else statements without curly braces.
#include <iostream>

using namespace std;

int main()
{
	int a = 2;
	double b = 2.39;
	char c = 'x';

	if (a == 2)
		cout << "a = 2" << endl;
	cout << "hi" << endl;	//this statement is not in the if block.
	if (a ==2 && b == 2.3)
		cout << "a =2, b = 2.3" << endl;
	if ( ! (a==82 || c=='m'))
		cout <<"final." << endl;

}




//===========67===========
//This program is to practice enum
#include <iostream>

using namespace std;

int main()
{
	enum score
	{
		//be careful, comma is used instead of semi_colon, just like array whose elements
		//are of the same type. In enum the elements are also of the same type.
		first_exam=8,
		second_exam,
		final_exam,
	}my_score;

	my_score = final_exam;
	//Essentially the elements of enum type are int, so it can assigned to a variable
	//of int type. But you can NOT assign an integer to my_score.
	int a = my_score;
	cout << a << endl;
	cout << my_score << endl;
}




//=========66========
//This program is to practice union type
#include <iostream>
#include <string>

using namespace std;

int main()
{
	union units
	{
		double dollar=5;
		double dollar1;
		float yuan;	//if yuan is declared to be a float, then it will be the same as dollar.
		float yuan1;
		double yuan2;
		char ch;
		char ch1;
		//string hi;
	};

	units my_unit;
	my_unit.dollar = 2.3;
	my_unit.yuan = 283.3;
	my_unit.ch = 'x';

	cout << "Dollar: " << my_unit.dollar1 << ", Yuan: " << my_unit.yuan2 << ", Char: "
		 << my_unit.ch1 << endl;
	//cout << "String: " << my_unit.hi;
}





//===========65=============
//This program is to practice nesting structure
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	struct car
	{
		string name;
		int year;
	};

	struct person
	{
		string name;
		int dob;
		car favoriate_car;
	}me;

	string my_str;

	cout << "Enter your name: ";
	getline(cin, me.name);
	cout << "Enter your DOB (only numbers): ";
	getline(cin, my_str);
	stringstream(my_str) >> me.dob;
	cout << "Enter the name of your favoriate car: ";
	getline(cin, me.favoriate_car.name);
	cout << "Ente the year made of your car: ";
	getline(cin, my_str);
	stringstream(my_str) >> me.favoriate_car.year;

	cout << "Your basic information is " << endl;
	cout << "Name: " << me.name << endl;
	cout << "DOB: "	<< me.dob << endl;
	cout << "Your favoriate car: " << me.favoriate_car.name << endl;
	cout << "The year made of your car: " << me.favoriate_car.year << endl;

}




//========64========
//This program is to practice pointers in a structure
#include <iostream>

using namespace std;

int main()
{
	struct person
	{
		int a;
		int * a_ptr;
	} me, * me_ptr;

	me.a = 26;
	me.a_ptr = & me.a;
	cout << *me.a_ptr << endl;

	me_ptr = & me;
	cout << "========" << endl;
	cout << me_ptr -> a << "	" << *(me_ptr -> a_ptr) << "	"
		 << (*me_ptr).a << "	" << *((* me_ptr).a_ptr) << endl;

}




//=======63===========
//This program is to practice the sizeof(struc)
#include <iostream>
#include <string>

using namespace std;

int main()
{
	struct person
	{
		string name;
		long int age;
	}per;

	cout << sizeof(per.name) << sizeof(string) << endl;
}




//===========62===========
//This program is to test moving a void pointer forward
#include <iostream>

using namespace std;

int main()
{
	int a[] { 2, 3, 4}, * a_ptr = a;

	cout << a_ptr[2];
	cout << *(a_ptr+2);

	void * b_ptr = a;

	cout << ((int *) b_ptr)[2] << *((int *)b_ptr+1);
}




//===========61=============
//This program is to practice passing an array of structures to a function
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct person
	{
		string name;
		int age;
	};

//void print_per(person [], int num);	//[] SHOULD be there, othewise wrong.
void print_per(void *, int num);
int main()
{
	string my_str;

	person	per[3];

	cout << "Please enter the properties o the 3 persons: " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "	" << i << endl;
		cout <<	"	 name:";
		getline(cin, per[i].name);
		cout << "	 age: ";
		getline(cin, my_str);
		stringstream (my_str) >> per[i].age;
	}

	print_per(per, 3);

}

//void print_per(person perf [], int num)
void print_per(void * perf_ptr, int num)
{
	for (int i = 0; i < num; i++)
	{
		//cout << ((person *)perf_ptr)[i].name << "	" << ((person *)perf_ptr)[i].age << endl;
		cout << ((person *) perf_ptr)->name << "	" << ((person *)perf_ptr)->age << endl;
		perf_ptr = (person *)perf_ptr + 1;
		//(person *) perf_ptr ++;	//This does not work, use the above statement
	}
}



//========60==========
//This program is practice passing array of structures to a function.
#include <iostream>
#include <string>

using namespace std;

int main()
{
	struct person
	{
		string name;
		int age;
	};

	person per[3], *per_ptr = per;

	for (int i = 0; i < 3; i++)
	{
		cout << "Enter the name of " << i << "th person: ";
		//cin does not take spaces, if spaces wanted, use getline(string)
		cin >> per_ptr -> name;
		cout << "Enter the age of " << i << "th person: ";
		cin >> per_ptr -> age;

		per_ptr ++;	//since the array elements are in contiguous positions, so pointer
					//goes to the next position means to the next array element.
	}

	cout << "The array of the person structure is: " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << per[i].name << "		" << per[i].age << endl;
	}
}





//==========59============
//This program is practice passing array to functions
#include <iostream>

using namespace std;
void print_func(int, int num);
void print_func(int a[], int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << a[i] << ", " << endl;
	}

}
int main()
{
	int a_ [] {1, 2, 4};

	print_func(a_, sizeof(a_)/sizeof(a_[0]));


}




//============58===========
//From this program we can see that structures also
//This program is to practice an array of structures.
#include <iostream>
#include <sstream>	//convert string of numbers to int/double/float.
					//stringstream(my_string) >> my_number.
#include <string>

using namespace std;

int main()
{
	struct fruit
	{
		string name;
		double weight;
	}apple[3], * app_ptr = & apple[2];
	string my_str;

	cout << "Please enter the properties of the 3 apples: " << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "Apple " << i << " name and weitht: " << endl;
		cout << "	name: ";
		getline(cin, apple[i].name);
		cout << "	weight: ";
		getline(cin, my_str);
		stringstream(my_str) >> apple[i].weight;
	}

	cout << "The properties of the 3 apples are: \n";
	for (int i = 0; i < 3; i++)
	{
		cout << apple[i].name << " is " << apple[i].weight << "lbs." << endl;
	}

	cout << "Pointer: " << endl;
	cout << app_ptr -> name << app_ptr -> weight << endl;
}




//==========57==========
//This program is to practice an array of classes.
//Class is a kind of data structure, so just like other data types which have variables,
//arrays and pointers, class can also have objects, arrays of objects and pointers to
//objects.
#include "routine.h"

int main()
{
	person per [3], *per_ptr = & per[2];
	per [1] = {"LianshuiZhao", 27};
	per [2] = {"Yiyi", 28};


	for (int i = 0; i < 3; i++)
	{
		per[i].get_info();

	}
	per_ptr -> get_info();
}






//=============56================
//This program is to practice plain data structure outside of the main method
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct person
{
	string name;
	int age;
};

void print_person(person per);

int main()
{
	person me, you;
	string mystr;

	me.name = "LianshuiZhao";
	me.age = 26;

	cout << "Enter your name: ";
	getline(cin, you.name);
	cout << "Ente your age: ";
	getline(cin, mystr);
	stringstream(mystr) >> you.age;

	print_person(me);
	print_person(you);

	return 0;
}

void print_person(person per)
{
	cout <<per.name << " is " << per.age << " years old."<< endl;
}




//============55=============
//This program is to practice to_string
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
	double i=3;
	string mystr = "hisd" + to_string (i), constr="4.4";
	ostringstream mysstream;
	mysstream << "hisd" << setprecision(1) << i;
	cout << mysstream.str() << endl;
	cout << mystr << endl;

	stringstream(constr) >> i;
	cout << i << endl;

	cout << mystr[2] << endl;	//string literals, array.
	//cout << *(mystr+2) << endl;	//this is not okay
}




//===========54===========
//This program is to practice the plain data structure
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	struct person
	{
		string name;
		int age;

	}me, you;

	string mystr;	//hold temporary data

	me.name = "LianshuiZhao";
	me.age = 27;

	cout << "My name is: " << me.name << ", and my age is " << me.age << endl;

	cout << "Please enter your name: ";
	//be carefull, getline can only store string, not other types of data, like int here.
	//also you can not put two variables here because it can not distinguish two different
	//strings, only one.
	getline(cin, you.name);
	cout << "Please enter your age: ";
	//cin >> you.age;
	getline (cin, mystr);
	stringstream (mystr) >> you.age;

	cout << "Your name is: " << you.name << ", and your age is: " << you.age << endl;


}




//===========53============
//This is to prctice the getline method which transforms stream to string.
//It looks like ostringstream.
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string name;
	cout << "Enter your name: ";
	getline(cin, name);

	cout << "The name you entered is: " << name << endl;

	ostringstream ssline;

	ssline << "hi, " << name;
	cout << ssline.str() << endl;


}




//=============52=============
//This program is to test the intrinsic length method in string.
#include <iostream>
#include <string>

using namespace std;

int main()

{
	string a {"hi"}, b="seth";

	cout << a.length() << endl;
	cout << b.length() << endl;

}




//=============51=============
//This program is to test second way of handling failure of memory allocation
//Without specifying nothrow when dynamically allocating memory, the program will terminate
//if the allocation fails.
#include <iostream>
#include <new>

using namespace std;

int main()
{
	int i;
	cout << "enter the number of elements: ";
	cin >> i;

	int * ptr = new (nothrow) int [i];

	if (ptr == nullptr)	//0, NULL, nullptr all mean the pointer points to nowhere
	{
		cout << "Failing allocating memory ..." << endl;
	}
	else
	{
		for (int j = 0; j < i; j++)
		{
			ptr[j] = j;
		}
		cout << "The elements you entered are: ";
		for (int j = 0; j < i; j++)
		{
			cout << ptr[j];
			if (j != i-1)
			{
				cout << ", ";
			}
		}
	}

	delete [] ptr;
}



//===========50===========
//This program is to practice array and pointers
#include <iostream>

using namespace std;

int main()
{
	int a [ ] {1, 2, 3, 4};
	int * a_ptr = a;
	//when a pinter is pointing to an array, ptr[2] works.
	cout << a_ptr [1] << *a_ptr << *(a+2) << endl;
}




//=============49=============
//This program is to practice dynamic memory allocation
#include <iostream>

using namespace std;

int main()
{
	int i;

	cout << "Ente the number of elements you want to create: " << endl;
	cin >> i;
	int * ptr = new int [i];
	for (int j = 0; j < i; j++)
	{
		cout << "Enter the " << j << "th elenent: ";
		cin >> ptr[j];
		cout << endl;
	}

	for (int j = 0; j < i; j++)
	{
		cout << "The " << j << "th element you entered is " << ptr[j] << endl;
	}

	delete [] ptr;
}





//==========48============
//This program is to practice new
#include <iostream>

using namespace std;

int main()
{
	double * p = new double;
	//p = new int;
	cout << *p << endl;
	cout << "enter an integer: " << endl;
	cin >> *p;

	cout << *p << endl;

	delete p;
}



//=============47============
//This program is to practice the pointers to functions.
#include <iostream>

using namespace std;

inline void like_me(int i)
{
	if (i == 0)
	{
		cout << "我不喜欢你！" << endl;
	}
	else if (i == 1)
	{
		cout << "我非常喜欢你!" << endl;
	}
}

void tot_func(int i, void (* f)(int));
int main()
{
	for (int i = 0; i<=1; i++)
	{
		cout << i << endl;
		tot_func(i, like_me);
		cout << endl;
	}
}

void tot_func(int i, void (* f) (int i))
{
	cout << "In the total function ..." << endl;
	f(i);
}





//==============46===============
//This program is to parctice the pointers to functions
#include <iostream>

using namespace std;

inline void first_call() {cout << "In the first call ..." << endl;}
//In the pointer to a function, the input type has to be explicitly specified.
inline void second_call(void (* f) (), int a, int b, int (* add)(int, int)) {f(); cout << "In the second call ..." << endl; cout << a << b << endl; cout << "ADDITION: " << add(a, b) << endl; }
int addition(int a, int b);
int main()
{
	int a = 2, b = 3;
	second_call(first_call, a, b, addition);
}

int addition(int a, int b)
{
	return a+b;
}





//===========45===========
//This program is to practice the pointers to functions
#include <iostream>

using namespace std;

void addition(void * a, void * b, int a_size, int b_size);

int main()
{
	char a = 'x';
	char b = -2;
	//void * a_ptr;
	//for void pointer, no matter what the type is casted to, its size is always 8 bytes.
	//cout << sizeof((double *) a_ptr) << endl;

	addition(& a, & b, sizeof(a), sizeof(b));

	double c = -3.2;
	cout << char (a+c) << endl;	//it turns out char+int/double also works.
}

void addition(void * a, void * b, int a_size, int b_size)
{
	//cout << sizeof(((int * )a)) << endl;
	if (a_size==8 && b_size==8)
	{
		cout << "int+int: " << *((double *) a) + *((double *)b) << endl;
	}
	else if (a_size==8 && b_size==4)
	{
		cout << "double+int: " << *((double *) a) + *((int *) b) << endl;
	}
	else if (a_size==4 && b_size==8)
	{
		cout << "int+double: " << *((int *) a) + *((double *) b) << endl;
	}
	else if (a_size==4 && b_size==4)
	{
		cout << "int+int: " << *((int *) a) + *((int *) b) << endl;
	}
	else if (a_size==1 && b_size==1)
	{
		cout << "char+char: " << char(*((char *) a) + *((char *) b)) << endl;
	}
}





//==========44===========
//This program is to practice the null pointer
#include <iostream>

using namespace std;

int main()
{
	int * a = 0;
	char * b = nullptr;

	cout << & a << " " << & b << endl;
}




//===========43============
//This program is to test the void pointer
#include <iostream>

using namespace std;

void incre(void * data, int size);

int main()
{
	char a='x';
	int b=2;

	incre(&a, sizeof(a));
	incre(&b, sizeof(b));

}

void incre(void * data, int size)
{
	if (size == sizeof(char))
	{
		++*((char *) data);
		cout << *((char *) data) << endl;
	}
	else if (size == sizeof(int))
	{
		++*((int *) data);
		cout << *((int *) data) << endl;
	}
}





//==========42========
//This program is to test char operation
#include <iostream>

using namespace std;

int main()
{
	char a = 'x';
	cout << char(a+1) << endl;
}




//==========41============
//This program is to practice the pointers to pointers
#include <iostream>

using namespace std;

int main()
{
	int a = 2;
	int * a_ptr = &a;
	int * * b_ptr = &a_ptr;
	int * * * c_ptr = & b_ptr;
	cout << &a <<" " << a_ptr <<" "<<* b_ptr << " " << * * c_ptr << endl;
}




//==========40=========
//This program is to practice pointers and strings
#include <iostream>

using namespace std;

int main()
{
	char a[] {"h,illow"};
	char * a_ptr=a;
	cout << *++a_ptr << endl;

	a_ptr = a;
	cout << * (a_ptr++) << * a_ptr << endl;
	cout << * a_ptr << endl;
	cout << a[1] << endl;

	a_ptr = a;
	cout << *(a + 2) << *(a_ptr+2)<<endl;
}




//============39==================
//This program is to test const pointers
#include <iostream>

using namespace std;

void change_ele(int * star, int * end);
void print_ele(const int * star, const int * end);

int main()
{
	int a [] {1, 2, 3, 4};

	change_ele (a, a+sizeof(a)/sizeof(a[0]));
	print_ele (a, a+sizeof(a)/sizeof(a[0]));
}

void change_ele(int *star, int * end)
{
	int * current = star;

	while(current != end)
	{
		(*current) *= 2;
		current ++;
	}
}

void print_ele(const int *star, const int * end)
{
	const int * current = star;

	while (current != end)
	{
		cout << * current << endl;
		current ++;
	}
}




//===============38===============
//This program is to practice const pointers. const * means that the content can not be
//modified by the pointer, * const means that the initialized pointer address can not be
//modified, but its content can.
#include <iostream>

using namespace std;

int main()
{
	int a = 3;

	const int * a_ptr;	//the pointer can only read the content, NOT modify it.

	a_ptr = &a;

	cout << * a_ptr << endl;

	//(* a_ptr)++;	//error increment of read-only location

	// ++ * a_ptr;
	a_ptr ++;
	int * const b_ptr = & a;	//b_ptr is a const, so has to be initialized, can not ++ or --

	cout << ++ * b_ptr << endl;	//but the content pointed to can be modified.

}





//===========37=============
//This program is to test the pointers.
#include <iostream>

using namespace std;

int main()
{
	double a[] {1, 2, 3 ,4, 5, 6, 7, 8, 9, 10}, * a_ptr;

	a_ptr = a;	//initiate the pointer to the address of the array
				//i.e. the address of the first element.

	for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
	{
		cout << a_ptr << "  " << a[i] << endl;
		a_ptr ++;	//move the pointer to the next position
	}
}



//=============36===============
//This program is to practice the arithmetic operation on pointers.
#include <iostream>

using namespace std;

int main()
{
	int * a_ptr, b=2;
	a_ptr = &b;
	cout << b << endl;
	cout << a_ptr << endl;
	cout << (a_ptr+1)<< endl;


}





//=============35===============
//This program is to practice the pointers

#include <iostream>

using namespace std;

int main()
{
	int a = 2, * a_ptr;
	a_ptr = & a;

	cout << &a << endl;
	cout << a_ptr << "\n";

	//cout << & a_ptr << endl;

	cout << *(& a_ptr) << endl;

	cout << * a_ptr << endl;




}



//============34==============
//This program is to test the concatenation of two strings or string leterals?
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a = "Hello", b = "World", c = "!";

	cout << a+b+c << endl;

	char aa [] = "hi", bb [] = "my";
	a = aa;	//transform string literals to string
	b = bb;	//transform string literals to string
	cout << aa  << bb <<"  " << a+b << endl;
}



//===========33============
//This program is to practice string literals and library strings.
#include <iostream>
#include <string>

using namespace std;

int main()
{
	char question_1 [] = "What is your name dude?";
	string answer_1;
	char question_2 [] = "What is your age?";
	string answer_2;
	string str = question_2;	//transform string literals to string.

	cout << question_1 << "  " << question_2 << endl;
	cin >> answer_1 >> answer_2;

	cout << "Your name is " << answer_1 << ", and you are " << answer_2	<< " years old."
		 << endl;
	cout << answer_1.c_str() << answer_1.data();	//transform string to string literals.
	cout << str << endl;
	cout << "END !\n";

}



//=============32================
#include <iostream>

using namespace std;

int main()
{
	int a [] {1, 2, 4, 5};
	cout << a[1] << endl;
	a[1] = 23;
	cout << a[8] << endl;

	char b []={};
	b[0]=' ';
	b[1]='s';
	b[2]=' ';
	b[3]='d';
	b[4]='\0';
	cout << b << endl;

	char c[]=" s d";
	cout << c << endl;
}




//============31===========
//This program is to practice passing characters to functions.

#include <iostream>

using namespace std;

void print_array (char arr[]);

int main()
{
	char a[] = "ZhaoLianshui123";
	cout << a << endl;
	cout << "In the main program, the length is " << sizeof(a)/sizeof(a[0]) << endl;
	print_array(a);

}

void print_array(char arr[])
{
	int length = sizeof(arr)/sizeof(arr[0]);	//this is similar to the issue found with
											//other-typed array.
	cout << "Lenght of the string is " << length << endl;
	cout << "In the function: " << arr << endl;	//outputs the whole array.
}



//=============30===============
//This program is to test the char.
#include <iostream>

using namespace std;

int main()

{
	//char a = 'hi';	//overflow

	char a []  {"hi"};	//universal initialization
	cout << a << endl;	//output the whole character sequence

	char b[] = {'2', 's', 'h', '\0'};
	cout << b << " " << b[3]<< endl; 	//b[3] does not output the null-terminal.

	int c [] {2, 3};
	cout << c << " " << c[0] << endl;	//however for numbers, does not ouput the whole
										//array.

	char d[] = "hello_world";
	cout << d << " " << d[1] << endl;
}



//=============29==============
//This program is to test the default value of an array of some type.

#include <iostream>

using namespace std;

int main()
{
	char b;
	char a[4] {'2', '3', '4'};

	cout << a[3] << endl;
	cout << b << endl;

}




//========28==========

#include <iostream>

using namespace std;

int main()
{
	//universal initializer
	//int a[] {1, 2, 3};
	//cout << a[2] << endl;

	//two-dimension array, which has to set bounds to dimensions except the first one
	int m = 2;

	int b[][m]= {{1, 82}, {3, 4}};

	cout << b[0][1] << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j= 0; j < 2; j++)
		{
			cout << b[i][j] << " ";
		}
		cout << endl;
	}

	for (int elem : b[0])
		cout << elem << ' ';


}




//===============27==============
//This program is to test passing an array to a function, which really means passing the
//address of the array to the function.

#include <iostream>

using namespace std;

void print_array(int arr[], int length);
//void print_array(int arr[]);

int main()
{
	int arr1[5] = {12, 2, 4, 5, 8};
	cout << sizeof(arr1) << " " << sizeof(arr1[0]) << endl;
	int length = sizeof(arr1)/sizeof(arr1[0]);
	print_array(arr1, length);
	return 0;
}

void print_array(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << "  ";
	}
}


//void print_array(int arr[])	//what's passed to the function is the address of the array
							////not the complete information of the array, so the following
							////implementation is not right.
//{
	//cout << sizeof (arr) << "  " << sizeof(arr[0]) << endl;
	//int j = sizeof(arr)/sizeof(arr[0]);
	//cout << j<< endl;
	//for (int i=0; i < 9; i++)
	//{
		//cout << arr[i] << "  ";
	//}

//}




//==========26============
#include <iostream>

using namespace std;

int main()
{
	char a;
	int b[4];

	//sizeof() returns the size of the bytes the variable occupies.
	cout << sizeof (a) << endl;
	cout << sizeof (b) << endl;
	//how to find the number of elements in an array? Here it is.
	cout << sizeof (b) / sizeof (b[0]) << endl;
}



//============25============
#include "routine.h"
#include <iostream>

//using namespace std;

int main()
{
	full_name my_name("ZHAO", "LIANSHUI");
	cout << my_name.get_full_name() << endl;


}


//=========24==============
#include <iostream>

using namespace std;

class square
{
	private:
		double _side;
	public:
		square () {}
		//if any constructors taking any number of parameters exist, the implicit default
		//constructor will not be valid. So you have to include an explicit default
		//constructor if you want to initialize the object without passing parameters.
		square(double ini_side): _side {ini_side} {}
		void set_side(double new_side)
		{
			_side = new_side;
		}
		void get_side()
		{
			cout << "The side is " << _side << endl;
		}
};

int main()
{
	square my_square;
	my_square.get_side();

}


//===========23=============
#include <iostream>

using namespace std;
class circle
{
	private:
		double _radius_1, _radius_2;
	public:
		circle(double ini_radius_1, double ini_radius_2)
			{_radius_1 = ini_radius_1; _radius_2 = ini_radius_2;}
		void get_radius() {cout << _radius_1 << "  " << _radius_2 << endl;}
};

int main()
{
	//array of objects.
	circle my_circle[] = {{1, 2}, {2, 3}, {1, 1}};

	my_circle[0].get_radius();
	my_circle[2].get_radius();

}




//==============22===============
#include <math.h>
#include <iostream>

using namespace std;
class square
{
	private:
		double _side;
	public:
		square() : _side{1.0} {}
		square (double ini_side) : _side {ini_side} {}

		void set_side(double new_side) {_side = new_side;}
		double get_area() {return _side * _side;}
};

class circle
{
	private:
		double _radius;
	public:
		circle (): _radius{1.0} {}
		circle (double ini_radius): _radius{ini_radius} {}

		double get_area() {return atan(1.)*4*_radius*_radius;}
};

int main()
{
	square my_square {};
	my_square.set_side(2);
	cout << my_square.get_area() << endl;

	square * my_square_ptr;
	my_square_ptr = & my_square;
	my_square_ptr -> set_side(3);
	cout << my_square_ptr -> get_area() << endl;
	//for void pointer, first pass the address to it and then specify the type by typecasting.
	void * my_ptr;
	my_ptr = & my_square;
	((square *) my_ptr) -> set_side (4);
	cout << ((square *) my_ptr) -> get_area() << endl;

	circle my_circle {1.};
	my_ptr = & my_circle;
	cout << ((circle *) my_ptr) -> get_area() << endl; //never use - >, but ->
}

//=========21===============
//class members can not access the variables declared outside of the class.
#include <iostream>

using namespace std;

class circle
{
	private:
		double _radius;
	public:
		circle () {}	//needless if my_circle is initialized behind :.
		circle ( double r) {_radius = r;}
		double get_area()
		{
			return 3.141592653 * _radius * _radius;
		}
};

class cylinder
{
	private:
		circle my_circle;
		double _height;
	public:
		cylinder (double r, double h)
		{
			my_circle = {r};
			_height = h;
		}
		//	: my_circle {r}, _height {h} {}
		double get_volumn ()
		{
			return my_circle.get_area() * _height;
		}
};

int main()
{
	cylinder my_cylinder {1.0, 1.0};

	cout << my_cylinder.get_volumn() << endl;

}


//==========20==========
//This program is to test <string>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string my_string = "Hello World";

	cout << my_string << endl;

}



//==============19===============
//This program is to test pointers
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
	int * a_ptr;
	double * b_ptr;
	string * c_ptr;


	int a = 3;
	double b = 4. * atan(1.);
	string c = "'hello world'";

	a_ptr = & a;
	b_ptr = & b;
	c_ptr = & c;

	cout << fixed << setprecision (12);
	cout << "* a_ptr is " << * a_ptr << endl;
	cout << "* b_ptr is " << * b_ptr << endl;
	cout << "* c_ptr is " << * c_ptr << endl;
	return 0;
}



//=========18==========
//This program is to test the member initializer list when an object is a member inside
//of another class. If the object has a default constructor, then it can be initialized
//in the body of a function, otherwise it has to be initialized between : and {} in that
//function.
#include "routine.h"
#include <iostream>

using namespace std;

int main()
{
	cuboid my_cuboid {5, 4, 3};

	cout << "The volumn of my cuboid is " << my_cuboid.get_volumn() << endl;
}


//===========17============
//This program is to test the uniform initialization of class.
//Here we don't explicitly include <iostream>, but it's included in the header file, so
//when compiling, it's copied here directly.
#include "routine.h"

int main()
{
	//uniform initialization
	person me = {"LianshuiZhao", 27, 180.1};
	person she {"MuziLi", 26, 170.2};
	//functional form initialization
	person roommate("WeiZhong", 25, 175.2);
	//here we can just do "person def;", or include {} behind, but never use (), which will
	//make person not a class. Here {} is a uniform initialization form.
	person def {};

	cout << "=========" << endl;
	me.get_person();

	cout << "=========" << endl;

	she.get_person();

	cout << "=========" << endl;

	roommate.get_person();

	cout << "=========" << endl;

	def.get_person();
}




//===========16=========
//This program is to test when the constructor is called.
//no <iostream> or using namespace std
#include "routine.h"

int main()
{
	apartment my_apartment;

	return 0;
}


//==========15==========
//This program is to practice overloading of class constructors.
#include <iostream>	//This is necessary because of cout in the main function.
//#include <string>
#include "routine.h"
using namespace std;

int main()
{
	info first_info("LianshuiZhao", 27);
	first_info.get_info();
	cout << endl << endl;
	info second_info("MuziLi", 172.);
	second_info.get_info();
}



//==========14=========
//This program is to practice the constructor.
#include <iostream>
//#include <string>	//when should I include string lib?
#include "routine.h"

using namespace std;

int main()
{
	info my_info("ZHAO", "LIANSHUI");

	my_info.get_name();

	my_info.set_name("LI", "MUZI");
	my_info.get_name();

	info MY_INFO;
	MY_INFO.get_name();
}



//=========13==========
#include <iostream>
#include <string>
#include "routine.h"
using namespace std;

int main()
{
	//You can not put set_name function behind the variable when initializing, you have to
	//use the constructor, otherwise error reads 'expected initializer before .'
	//info my_info.set_name("Zhao", "Lianshui");
	info my_info;
	my_info.set_name("Zhao", "Lianshui");
	my_info.get_name();

	cout << "MY_INFO: " <<endl;
	MY_INFO.get_name();

}


//=========11===========
#include <iostream>
#include "routine.h"
#include <string>
using namespace std;

int main()
{
	personal_information my_info;

	//since in get_name there is no return type but a cout function, so we can not do
	//cout << my_info.get_name().
	my_info.get_name();
	cout << "I'm an(a) " << my_info.get_race() << ", I'm " <<
			my_info.get_age() << ", and I'm " << my_info.get_height() << "cm high." << endl;


}



//============10===============
#include <iostream>
#include <string>

using namespace std;

int main()
{
	//for string, double quotes "" instead of '', which is character type.
	string family_name="zhao", given_name="lianshui";

	cout << "my family name is " << family_name << ", my given name is " << given_name
	<< "." << endl;
}


//=========9===========
//use the make file to compile and link.
//This program is to test spliting the class into different files.
#include <iostream>
#include "routine.h"

using namespace std;

int main()
{
	//rectangle my_rectangle;
	my_rectangle.set_size(2, 3);
	cout << my_rectangle.area() << endl;

	return 0;
}



//==========8===========
//This program is to practice class type
#include <iostream>
#include <iomanip>

using namespace std;
//One of the advantages of declaration is that we don't need to worry about the order of
//the definition of functions, i.e. the scope.
//when declaring, the order is not important.
void print_size_my_rectangle ();
class rectangle
{
	public:
		double _length = 4.;
		double _height = 3.;

		void get_size ();

}my_rectangle, my_other_rectangle;

//void print_size_my_rectangle ();

int main()
{
	//even though there are no external input values, we have to put () behind the function.
	rectangle my_third_rectangle;
	print_size_my_rectangle();
}

void print_size_my_rectangle()
{
	//fixed makes
	cout << fixed << setprecision (2);
	cout << "length " << my_other_rectangle._length << endl
		 << "height " << my_rectangle._height << endl;

	//here the order of the definition is not important.
	my_rectangle.get_size();
}


void rectangle::get_size ()
{
	cout << _length << _height << endl;
}



//===========7===============
//This program is to test the class type
#include <iostream>
#include <iomanip>

using namespace std;

//The class is not split into different files.
class Rectangle
{
	private:
		double _length, _height;

	public:
		void set_size (double new_length, double new_height)
		{
			_length = new_length;
			_height = new_height;
		}

		void get_size ()
		{
			cout << "The length of your rectangle is " <<fixed << setprecision(2) << _length
			     << endl << "The height of your rectangle is " << setprecision(2) << _height
			     << endl;
		}

		double get_area ()
		{
			return _length * _height;
		}
}my_rectangle;

//You can not define this function before the class, which has not been defined yet.
//Scope is very important.
void area_my_rectangle()
{
	cout << my_rectangle.get_area() << endl;
}

int main()
{
	//Rectangle my_rectangle;
	my_rectangle.set_size(4., 3.);

	my_rectangle.get_size();
	//cout << my_rectangle.get_area() << endl;
	area_my_rectangle();
}



//=============6================
//This program is to test the power function pow(base, exponent), which requires cmath or
//math.h hearder file.
#include <iostream>
//#include <cmath>	//also works
#include <math.h>

using namespace std;

int main()
{
	cout << pow(4, 1./2.) << endl;
}


//===============5===============
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double a=2.3;

	cout << fixed << setprecision(4) << a << endl;
	cout  << scientific << setprecision(5) << a << endl;
}


//===========4===============
//This program is to test the manipulation of the filenames
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
	ostringstream filename;	//can not be initialized.
	filename << "file_" << 4 << ".dat";

	string my_filename=filename.str();
	ofstream outfile(my_filename);

	//outfile.open(my_filename); //which also works
	//outfile.open (my_filename.c_str());

	outfile << "This is file 4" <<endl;
	outfile.close();

	system ("cat file_4.dat");
	system ("rm file_4.dat");
	system ("if [ ! -f file_4.dat ]; then echo 'not exists'; fi");
}



//============3==============
//This program is to test the ostringstream, which just acts like cout
#include <iostream>
#include <string>
#include <sstream> 	//stringstream
#include <iomanip>
using namespace std;

int main()
{
	//stringstream, stringstream.str(), stringstream.str().length()
	//we can also use + to concatenate different strings.
	ostringstream my_stringstream;

	int i=3;
	my_stringstream << "first_" <<i <<".out" <<endl;

	string my_string=my_stringstream.str();

	string cat_string = my_string +"_" + to_string(i) +".dat";

	cout << my_string<< endl << cat_string << " " << cat_string.length() << endl;;

	my_stringstream << "hi_" << i <<"_" << scientific << setprecision(2) << 3.23934 << "out";

	cout << my_stringstream.str() << endl;

}



//=========2============
//This program is to test the string.
#include <iostream>
//#include <string>

using namespace std;

int main()
{
	for (int i=0; i<=3; i++)
	{
	string test_string_1="hi", test_string_2="world";	//using double quotes, not single one.

	//to_string(i) is used to convert number to string.
	string total_string=test_string_1 + to_string(i) + test_string_2;
	//total_string.length() is to output the length of the string.
	int length=total_string.length();
	cout << total_string<< " "<< length<< endl;
	}
}



//==============================1========================
//Analysis of the plot:
//		The integral is done by summing h*f(x_i) with some weights in every
//		unit interval, however the f(x) is not all the same in the interval
//		so there comes the error delta_f(x), and the resulting error in the
//		integral is h*delta_f(x), the total error will be h*total_delta_f(x),
//		thus the relative error is proportional to h. So that's why we have
//		a slop of 1 in the log-log plot. When h reaches the machine precision,
//		x+h=x, so f(x+h)=f(x). Suppose we just reach the machine precision, and
//		the integral is approximated as h*f(x), then we still want to divide the
//		interval into to, so h is h/2, and the two new intervals will give us
//		the result of h/2*f(x)+h/2*f(x+h/2), since x=x+h/2 in the computer, so
//		f(x+h/2)=f(x), thus the two new intervals will give us h*f(x), which
//		is the same as the previous one. That's the reason why we have a plato on the
//		left side.
//
//

//=====================================================================
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <omp.h>
#include <time.h>
#include "routine.h"
#include <gsl/gsl_integration.h>

using namespace std;

//function prototype
double my_integrand(double x, void * params_ptr);

//structure prototype to hold the parameters related to the integral.
typedef struct
{
	double alpha, low_end, up_end;
}
params_integ;

int main()
{

	params_integ my_params_integ;
	my_params_integ.alpha = 1.0; 	//set the parameter in the integrand

	//set lower point not to be 0(singularity), because 0 will make both
	//Simpson's and Milne's method to get inf.
	my_params_integ.low_end=1e-1;		//lower end of the integration interval
	my_params_integ.up_end=1;		//upper end of the integration interval

	void * params_ptr = &my_params_integ.alpha;		//set pointer to pass the parameter
													//to the integrand

	//use long int to be able to have more points or we can decrease the integral range
	//so that we can still have enough points using int
	long int num_sub;		//the number of subintervals, so for simpson's rule, the total
							//number of intervals will be 2 * num_sub + 1.

	gsl_integration_workspace *work_ptr
    = gsl_integration_workspace_alloc (1000);
    double abs_error = 1.0e-8;
    double rel_error = 1.0e-9;
    double gsl_result;
    double gsl_error;


    gsl_function My_function;
    My_function.function = &my_integrand;
    My_function.params = params_ptr;

    gsl_integration_qags (&My_function, my_params_integ.low_end, my_params_integ.up_end,
			abs_error, rel_error, 1000, work_ptr, &gsl_result,
			&gsl_error);
	cout << setprecision(16);
	cout << "gsl_result = "  << gsl_result << endl;
	cout << "1/gsl_result = " << 1./gsl_result << endl;

	ofstream outsimpson("simpson.dat");
	ofstream outmilne("milne.dat");

	//Print the head line.
	outsimpson << setw(15) << "# 2*num_sub+1" << setw(15) << "h     " << setw(20) << "error" << endl;

	outmilne << setw(15) << "# 4*num_sub+1" << setw(15) << "h     " << setw(20) << "error" << endl;
	int i;	//used in the omp loop
	double result; //to hold the integral value

	omp_set_num_threads(2);

	double start = omp_get_wtime();	//to record the starting time.
	cout << start << endl;

	#pragma omp parallel for private(i, num_sub, result)
	for (i = 2; i >=1; i--)
	{
		cout << "This is thread " << omp_get_thread_num() << endl;

		if ( i == 1 )
		{
			for (num_sub = 1; num_sub <= 600000000; num_sub *= 2)
			{

				//the integral for each num_sub
				result = simpson(my_params_integ.low_end, my_params_integ.up_end,
										num_sub, params_ptr, &my_integrand);

				outsimpson << setw(15) << 2*num_sub+1 << scientific << setw(15) << (	my_params_integ.up_end - my_params_integ.low_end)/(2.*num_sub) << setw(20) <<fabs((result-gsl_result)/gsl_result) << endl;
			}
			outsimpson.close();		//close the output file
		}

		if ( i == 2)
		{
			for (num_sub = 1; num_sub <= 600000000; num_sub *= 2)
			{
				result = milne(my_params_integ.low_end, my_params_integ.up_end, num_sub,
									params_ptr, &my_integrand);	//the integral for each num_sub

				outmilne << setw(15) << 4*num_sub+1 << scientific << setw(15) << (my_params_integ.up_end - my_params_integ.low_end)/(4.*num_sub) << setw(20) << fabs((result-gsl_result)/gsl_result) << endl;
			}
			outmilne.close();		//close the output file
		}
	}
	double end = omp_get_wtime(); 		// the time when the omp finishes the loop
	cout << end<< endl;
	cout << "The wall time using omp is " << end - start << "s" <<endl;
}


//implementation of my_integrand
double my_integrand(double x, void * params_ptr)
{
	double alpha = * (double *) params_ptr;

	return ( log (alpha * x) / sqrt (x) );

}

*/
