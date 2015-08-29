#include <iostream>
#include <string>
#define PI 3.14

using namespace std;

// hodgepodge of fundamental c++ concepts and examples

// function declarations
int power(int, int);
void user_options();
void select_shape(int);
void calc_shape_area(double, double, int);
bool is_valid(string);
// overloading functions
double power(double, int);
// inline function
double add(double a, double b) { return a + b; }

void change_value(int a)
{
  // makes a copy of a so not modifying a within main
  a = 10;
  // also local variable is destroyed after return of func
}

int fib(int n) {
	if (n < 3) {
		return 1;
	}
	else 
	{
		return(fib(n - 2) + fib(n - 1));
	}
}

int main() {
	short  t1;    // -32768 to 32767, 2bytes
	float  t2;    // 4bytes up to 38 zeros
	double t3;    // 8bytes up to 308zeros more precision
	int A = 4;
	char cont, t4;    // character
	string t5 = "blah blah";
	string t6 = " gah gah";
	string combine = t5 + t6;
	const string NAMEOFGAME = "the due";
	bool   t7 = true;
	int a,b,num, choice;
  a = 5;
  
  change_value(a);
  cout << " a is " << a << endl ;
	// bitwise practice
	cout << (10 & 2) << endl;
	/*
	1 0 1 0
	0 0 1 0
	- - - -
	0 0 1 0 
	*/
	cout << (10 | 2) << endl;
	/*
	1 0 1 0
	0 0 1 0
	- - - -
	1 0 1 0
	*/
	cout << (10 ^ 2) << endl;
	/*
	1 0 1 0
	0 0 1 0
	- - - -
	1 0 0 0
	*/
	cout << (~10) << endl;
	/*
	1 0 1 0
	0 0 1 0
	*/
	
  // reference address of var
  cout << A << endl;
	cout << &A << endl;
	cout << "this is test\n";
	cin >> b;
	cout << "b=" << b << endl;
  //

	// ternary conditional
	a = 5;
	b = 6;
	string message = (a > b) ? "a>b" : "a<=b";

	// can get cryptic but doable
	cout << ((a > b ? a : b) + 10) << endl;


  // function
	cout << "enter fib : ";
	cin >> num;
	cout << "fib is : " << fib(num) << endl;
  //

  // inline function
  cout << add(4, 5);
  //

  // multi arrays
	/*
	int y[3][4];
	y[1][1];
     1   2  3  4
	1[] [] [] []
	2[] [x][] []
	3[] [] [] []

	*/

	// loops
	string tmp;
	cout << "Enter number: " << endl;
	cin >> tmp;

	cout << "number is : ";
	for (int i = 0; i < tmp.length(); i++)
	{
		if (tmp[i] >= 48 && tmp[i] <= 57)
			cout << tmp[i];
		else
			continue;
	}

	cout << endl;
	cout << endl;

	for (int i = 1; i <= 10; i++) // amt of rows, len of columns
	{
		if (i == 5)
			continue;
	
		for (int j = 1; j <= 10; j++) { // amt of columns, len of rows
			if (j == 5)
				break;
			cout.width(4);
			cout << i * j << " ";
		}
		cout << endl;
	}

	while (a < 10)
	{
		cout << " blah " << endl;
		a++;
	}

	do
	{
		cout << "i execute at least once" << endl;
	} while (a < 10);
  //

  cout << power(2.8, 3) << endl;

  // calculate shape\

  do
  {
    system("cls");                                            // clear screen
    user_options();
    
    while (!(cin >> choice))
    {
      is_valid("incorrect choice");    // ignore all but 1
    }

    select_shape(choice);
    do
    {
      cout << "continue Y/N ?" << endl;
      cin >> cont;                                            // do not have to clear with char
      cin.ignore(numeric_limits<streamsize>::max(), '\n');    // ignore all but 1

    } while (cont != 'y' && cont != 'Y' && cont != 'n' && cont != 'N');

  } while (cont == 'y' || cont == 'Y');

	system("pause");
}

int power(int b, int e)
{
  int tmp = b;
  while (e-- > 1)
  {
    b *= tmp;
  }

  return b;
}

double power(double b, int e)
{
  int tmp = b;
  while (e-- > 1)
  {
    b *= tmp;
  }

  return b;
}

void user_options()
{
  cout << "Enter option:" << endl;
  cout << "1. Circle"     << endl;
  cout << "2. Square"     << endl;
  cout << "3. Rectangle"  << endl;
  cout << "4. Triangle"   << endl;

}

void select_shape(int choice)
{
  double radius,x,y;
  int shape;
  switch (choice)
  {
    case 1:
      cout << endl;
      cout << "Enter the radius: " << endl;
      do { cin >> radius; } while (!is_valid("radius incorrect plz try again"));
      shape = 1;
      y = 0;
      calc_shape_area(radius, y, shape);
      break;
    case 2:
      cout << "Enter the side of the square" << endl;
      do { cin >> x; } while (!is_valid("side is incorrect plz try again"));
      shape = 2;
      y = 0;
      calc_shape_area(x, y, shape);
      break;
    case 3:
      cout << "Enter the width & length" << endl;
      do { cin >> x >> y; } while (!is_valid("width or length is incorrect plz try again"));
      shape = 3;
      calc_shape_area(x, y, shape);
      break;
    case 4:
      cout << "Enter the base & height " << endl;
      do { cin >> x >> y; } while (!is_valid("base or height is incorrect plz try again"));
      shape = 4;
      calc_shape_area(x, y, shape);
      break;
    default:
      cout << "You didn't choose a correct option" << endl;
  }

}

// would be interested to see how much memory is reserved when creating all the var vs separate functions for each shape
void calc_shape_area(double x, double y, int shape)
{
  double width = x, side= x, radius =x, base = x, height = y;

  switch (shape)
  {
  case 1:
    cout << "The area of the circle is: " << PI * radius * radius << endl;
    break;
  case 2:
    cout << "The area of the square is: " << side * side << endl;
    break;
  case 3:
    cout << "The area of the rectangle is: " << width * height << endl;
    break;
  case 4:
    cout << "The area of the triangle is: " << (base * height) / 2 << endl;
    break;
  default:
    cout << "shouldn't hit this";
  }

}

bool is_valid(string error_msg)
{
  if (cin.rdstate())                                         // state is wrong when eq 0
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');    // ignore all but 1
    system("cls");
    user_options();
    cout << error_msg << endl;
    return false;
  }

  return true;

}