// File name: CalTest.cpp
// Author: Andrew Dellapina
// VUnetid: dellapaj
// Email: andrew.j.dellapina@vanderbilt.edu
// Class: CS201
// Date: 1/22/2014
// Honor statement:
// Assignment Number: 1
// Description: This program will test the Calendar class

#include <iostream>
#include <string>
#include <stdexcept>
#include "Calendar.h"
using namespace std;


int main(void)
{
	// Here is some sample code that does some simple testing of the Calendar class.
	// It creates an empty Calendar and performs some test on it.
	// It then adds a Reminder to the Calendar and performs some other tests on it.
	// This is only a simple sample, and is not considered to be very thorough.


	Calendar cal1;   // create an empty Calendar object via default ctor

	if (cal1.getNumRem() != 0) {  // test getNumRem()
		cout << "Default ctor failed to create an empty calendar" << endl;
		cout << "Reported that " << cal1.getNumRem() << " reminders exist" << endl;
	}

	if (cal1.displayRem() != "") {  // test displayRem()
		cout << "Default ctor should produce an empty calendar" << endl;
		cout << "displayRem returned the following reminders: " << cal1.displayRem() << endl;
	}


	Date d1("01/06/2014");
	Reminder rem1(d1, "First day of classes");

	size_t index = cal1.addRem(rem1);   // test addRem(); Calendar how has one Reminder

	if (index != 0 ) {
		cout << "addRem failed to return index 0 for first insertion" << endl;
		cout << "Returned index == " << index << endl;
	}

	if (cal1.getNumRem() != 1) {
		cout << "addRem/getNumRem failed after inserting one reminder" << endl;
		cout << "Reported that " << cal1.getNumRem() << " reminders exist" << endl;
	}

	if (cal1.displayRem() != "On 01/06/2014: First day of classes\n") {
		cout << "Unexpected reminder in calendar" << endl;
		cout << "displayRem returned the following reminders: " << cal1.displayRem() << endl;
	}

	if (cal1.displayRem(index) != "On 01/06/2014: First day of classes") {
		cout << "Unexpected reminder in calendar" << endl;
		cout << "displayRem returned the following reminders: " << cal1.displayRem(index) << endl;
	}

	if (cal1.displayRem(d1) != "01/06/2014") {
		cout << "Unexpected reminder in calendar" << endl;
		cout << "displayRem returned the following reminders: " << cal1.displayRem(index) << endl;
	}

	string str = rem1.toString();

	if (cal1.displayRem(str) != "On 01/06/2014: First day of classes\n") {
		cout << "Unexpected reminder in calendar" << endl;
		cout << "displayRem returned the following reminders: " << cal1.displayRem(str) << endl;
	}

	Date d2("01/07/2014");
	Reminder rem2(d2, "Second day of classes");

	if (cal1.displayRem(d1, d2) != "") {
		cout << "Unexpected reminder in calendar" << endl;
		cout << "displayRem returned the following reminders: " << cal1.displayRem(d1, d2) << endl;
	}

	if (cal1.findRem(d1) != 0) {
		cout << "Unexpected reminder in calendar" << endl;
		cout << "findRem returned the following reminders: " << cal1.findRem(d1) << endl;
	}

	if (cal1.deleteRem() != index) {
		cout << "Unexpected reminder in calendar" << endl;
		cout << "deleteRem did not delete the following reminders:" << cal1.displayRem(cal1.deleteRem()) << endl;
	}

	size_t orig = cal1.getNumRem();

	if (cal1.deleteRem(index) != orig-1) {
		cout << "Unexpected reminder in calendar" << endl;
		cout << "deleteRem did not delete the following reminders: " << cal1.displayRem(cal1.deleteRem(index)) << endl;
	}

	if (cal1.deleteRem(str) != orig - 1) {
		cout << "Unexpected reminder in calendar" << endl;
		cout << "deleteRem did not delete the following reminders: " << cal1.displayRem(cal1.deleteRem(str)) << endl;
	}

	if (cal1.deleteRem(d1) != orig - 1) {
		cout << "Unexpected reminder in calendar" << endl;
		cout << "deleteRem did not delete the following reminders: " << cal1.displayRem(cal1.deleteRem(d1)) << endl;
	}

	size_t befored1 = cal1.getRem(d1);
	size_t afterd2 = cal1.getRem(d2);

	if (cal1.deleteRem(d1, d2) != orig - afterd2 + befored1) {
		cout << "Unexpected reminder in calendar" << endl;
		cout << "deleteRem did not delete the following reminders: " << cal1.displayRem(cal1.deleteRem(d1, d2)) << endl;
	}

	// Here is an example of using a try-catch block to test exception throwing.
	// You place your code that should generate an exception in the "try" block, and you
	// specify the exception you are catching in the "catch" expression. If an exception is
	// thrown, control will branch immediately to the "catch" block. If an excetion is not
	// thrown, the "try" block will fully execute and then control goes to whatever follows
	// the try-catch block.
	// Experiement: change the number of iterations of the loop and observe the behavior. Try 10 & 100.
	try
	{
		for (int i=0; i<100; i++)  // attempt to insert 100 reminders in a calendar that can only hold 50
		{
			cal1.addRem(rem1);
		}
		cout<<"\nTHIS MESSAGE SHOULD NOT BE SEEN. An overflow exception was not thrown!!"<<endl;
	}
	catch(std::overflow_error &excpt)
	{
		cout<<"Exception successfully thrown & caught:: "<< excpt.what() << endl;
	}




	cout<<"\nEnd of tests. Press enter to exit.";
	char tt;
	tt = cin.get();

}

