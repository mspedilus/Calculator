/*********************************************************************************************************************
Description: Calculates the calculate the tax, the net cost, and the total cost of an online order from an input file.
**********************************************************************************************************************/

#include <iostream> //standard library for i/o
#include <fstream>//you must include this library if you wish to do file i/o
#include <string> // always include this when you use the string class
using namespace std;

//Declaration of orderRecord
struct orderRecord
{
	string cellNum;
	string itemNum;
	int quantity = 0, locationID;
	double price = 0.0,
			   tax = 0.0,
				 netCost = 0.0,
				 totalCost = 0.0,
				 taxRate = 0.0;
};

void DataFromFile(ifstream&, orderRecord&);
//Precondition: Input stream is open
//Postcondition: Sets the values for cellNum, itemNum, quantity, price, and locationID
//Description:  Reads data from the input data to the corresponding variables

void ProcessData(orderRecord& currentRecord);
//Precondition: orderRecord is initialized
//Postcondition: Sets the values for tax, net cost, and total cost
//Description: Calculates the tax, net cost, and total cost from the variables in orderRecord

void PrintToScreen(const orderRecord& currentRecord);
//Precondition: currentRecord variables are declared and defined
//Postcondition: Prints the calculations and variables to the screen
//Description:  Displays the final results in columns

void GetTaxRate(double& taxRate, int locationID, double& price);
//Precondition: taxRate, locationID, price are initialized
//Postcondition: Sets the value for taxRate
//Description: Calculates the tax rate based on the location ID

int main()
{
	//Declares orderRecord, name, and input stream
	orderRecord recordData;
	string name;
	ifstream in;

	//Greets the user and displays a message
	cout << "Enter your first name: ";
	cin >> name;
	cout << name << ", Let's get started processing the file data.\n\n";
	cout << "Phone Number\tItem Number\tQty\tPrice\tLocID\tRate\tTax\tNet\tTotal\n";


  //Opens the input file stream
	in.open("purchaseOrderData.txt"); //connect to the input file add the file name

	if (in.fail())
	{
		cout << "Input file did not open correctly" << endl;
	}
	else
	{
		while (!in.eof()) //has not reached the end of the file
		{
			DataFromFile(in, recordData); //Stores values from the input file into the variables
			ProcessData(recordData); //Calculates the data
			PrintToScreen(recordData); //Displays the data
		}
	}

	//Closes the input file stream
	in.close();

	//Final message to the user
	cout << "\n" << name << ", have a nice day!\n";
	return 0;
}

void DataFromFile(ifstream& in, orderRecord& currentRecord)
///Stores values from the input file into the variables
{
	in >> currentRecord.cellNum >> currentRecord.itemNum >> currentRecord.quantity >>
	      currentRecord.price >>currentRecord.locationID;
}

void ProcessData(orderRecord& currentRecord)
//Description: Calculates the data for tax, netCost, and totalCost
{
	//Calls the GetTaxRate function to get the tax rate based on the locationID
	GetTaxRate(currentRecord.taxRate, currentRecord.locationID, currentRecord.price);

	//Calculates the tax, net cost, and total cost
	currentRecord.tax = currentRecord.quantity * currentRecord.price * currentRecord.taxRate;
	currentRecord.netCost = currentRecord.quantity * currentRecord.price;
	currentRecord.totalCost = currentRecord.netCost + currentRecord.tax;

}

void GetTaxRate(double& taxRate, int locationID, double& price)
//Description: Calculates the tax rate based on the location ID
{
		//Sets the value of taxRate based on locationID
		if((locationID >= 1) && (locationID <= 15)){
			taxRate = 0.0444;
		}
		else if((locationID >= 16) && (locationID <= 30)){
			taxRate = 0.0525;
		}
		else if((locationID >= 31) && (locationID <= 45)){
			taxRate = 0.061;
		}
		else if(locationID > 45){
			taxRate = 0.0953;
		}
		else{
			cout << "ZERO or a negative number for the location ID is not a valid entry.\n";
			taxRate = 0;
			price = 0;
		}
}

void PrintToScreen(const orderRecord& currentRecord)
//Description: Displays the data and calculations
{
	//set the number of decimal places for doubles
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2); //use any number here for the number of decimal places

	cout << currentRecord.cellNum << "\t";
	cout << currentRecord.itemNum << "\t";
	cout << currentRecord.quantity << "\t";
	cout << currentRecord.price << "\t";
	cout << currentRecord.locationID << "\t";

	cout.precision(4);//4 decimal places
	cout << currentRecord.taxRate << "\t";

	cout.precision(2);//back to 2 decimal places
	cout << currentRecord.tax << "\t";
	cout << currentRecord.netCost << "\t";
	cout << currentRecord.totalCost << "\n";

}
