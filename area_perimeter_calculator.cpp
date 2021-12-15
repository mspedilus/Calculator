/*********************************************************************************
Description: Area and perimeter calculator for rectangles/squares and triangles
**********************************************************************************/
#include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class
#include <cmath> //for sqrt & floor
using namespace std;

//Declaration of shape
struct shape{double area = 0.0;
						double perimeter = 0.0;
						double side1 = 0.0;
						double side2 = 0.0;
						double side3 = 0.0;};

void MenuChoices(string& choice);
//Precondition: choice is initialized
//Postcondition: choice gains a string value
//Description: Receives an input for the string variable choice

void ProcessChoice(string& choice, shape& shapes);
//Precondition: shapes is initialized and choice has a value
//Postcondition: chose which function to run
//Description: Chooses which function to run depending on the user input

void TriangleCalculator(shape& shapes);
//Precondition: shapes is initialized
//Postcondition: area and perimeter is calculated and the results are displayed
//Description: Recieves input for sides, calculates the area and perimeter of a triangle, and displays the results

void RectangleCalculator(shape& shapes);
//Precondition: shapes is initialized
//Postcondition: area and perimeter is calculated and the results are displayed
//Description: Recieves input for sides, calculates the area and perimeter of a rectangle, and displays the results

int main()
{
	//Declared variables
	shape shapes;
	string choice;

	//Sets the number of decimal places for doubles
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);

	//Welcome message
	cout << "Welcome to the area and perimeter calculator\n";

	do{
			MenuChoices(choice);	//Gathers input for choice
			ProcessChoice(choice, shapes); 	//Chooses which function to run depending on the string variable choice
	}while(!(choice == "Q" || choice == "q")); //Aborts if user inputs Q or q

	//Final message
	cout << "\nGoodbye, Have a great day!\n";
	return 0;
}


void MenuChoices(string& choice)
//Description: Receives an input for the choice variable
{
	cout << "----------------------------------------------\n";
	cout << "Please enter a T, R, or Q.\nTo calculate:\n";
	cout << "The area and perimeter of a triangle, enter T\nThe area and perimeter of a rectangle, enter R\n";
	cout << "----------------------------------------------\nEnter Q to quit: ";
	cin >> choice;
}

void ProcessChoice(string& choice, shape& shapes)
//Description: Chooses which function to run depending on the user input for choice
{
	//Runs different functions depending on the value in choice
	if(choice == "T" || choice == "t")
		TriangleCalculator(shapes);
	else if(choice == "R" || choice == "r")
		RectangleCalculator(shapes);
	else if(choice == "Q" || choice == "q"){
	}
	else{
		cout << "\nThat input is not recognized";
		cout << "\nThe area is 0.000\nThe perimeter is 0.000\n\n";
	}
}

void TriangleCalculator(shape& shapes)
//Description: Recieves input for sides, calculates the area and perimeter of a triangle, and displays the results
{
	//Recives input for side1, side2, and side 3
	cout << "\n*********************************************\n";
	cout << "Enter the length of side one: ";
	cin >> shapes.side1;
	cout << "Enter the length of side two: ";
	cin >> shapes.side2;
	cout << "Enter the length of side three: ";
	cin >> shapes.side3;

	//Rounds the variables to the nearest tenth palce
	double side1 = floor(shapes.side1*10+0.5)/10;
	double side2 = floor(shapes.side2*10+0.5)/10;
	double side3 = floor(shapes.side3*10+0.5)/10;

	//Calculates the sum of 2 sides
	double sum1 = shapes.side1 + shapes.side2,
				 sum2 = shapes.side1 + shapes.side3,
				 sum3 = shapes.side2 + shapes.side3;

	//Displays the results when the sum of 2 sides is greater than the third
	if((sum1 < shapes.side3) || (sum2 < shapes.side2) || (sum3 < shapes.side1)){
		cout << "\nNot a valid triangle\nThe area is 0.000\n";
		cout << "The perimeter is 0.000\n\n";
	}
	else{
		//Calculates the area and perimeter
		double s = (shapes.side1 + shapes.side2 + shapes.side3)/2;
		shapes.perimeter = shapes.side1 + shapes.side2 + shapes.side3;
		shapes.area = sqrt(s * (s - shapes.side1) * (s - shapes.side2) * (s - shapes.side3));

		//Displays the results
		cout.precision(1); //Displays the sides to 1 decimal place
		cout << "\nSide A\tSide B\tSide C\n";
		cout << side1 << "\t" << side2 << "\t" << side3 << endl;
		cout.precision(3); //Displays the area and perimeter to 3 decimal places
		cout << "\nThe area is " << shapes.area;
		cout << "\nThe perimeter is " << shapes.perimeter << "\n\n";
	}
}

void RectangleCalculator(shape& shapes)
//Description: Recieves input for sides, calculates the area and perimeter of a rectangle, and displays the results
{
	//Recives input for side1 and side2
	cout << "\nEnter the length of side one: ";
	cin >> shapes.side1;
	cout << "Enter the length of side two: ";
	cin >> shapes.side2;

	//Rounds the variables to the nearest tenth palce
	double side1 = floor(shapes.side1*10+0.5)/10;
	double side2 = floor(shapes.side2*10+0.5)/10;

	//Calculates the area and perimeter
	shapes.area = shapes.side1 * shapes.side2;
	shapes.perimeter = (shapes.side1 * 2) + (shapes.side2 * 2);

	//Displays the results
	cout.precision(1); //Displays the sides to 1 decimal place
	cout << "\nSide X\tSide Y\n";
	cout << side1 << "\t" << side2 << "\n";
	cout.precision(3); //Display the area and perimeter to 3 decimal places
	cout << "\nThe area is " << shapes.area;
	cout << "\nThe perimeter is " << shapes.perimeter << "\n\n";
}
