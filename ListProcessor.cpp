// ListProcessor.cpp

// tom bailey   1540  30 sep 2011

// tom bailey   1030  27 jan 2012
// Exercise the List class with verbose Node constructor
//   and destructor.

#include "LinkedList.h"


int main()
{
	List cows;
	cout << "cows list  :  " << cows << endl << endl;

	cows.insertAsFirst(1.23);
	cows.insertAsFirst(2.34);
	cout << "cows list  :  " << cows << endl << endl;

	cows.removeFirst();
	cout << "cows list  :  " << cows << endl << endl;

	List horses(cows);
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl << endl;

	horses.removeFirst();
	horses.insertAsFirst(5.67);
	cows.insertAsFirst(6.78);
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl << endl;

	List pigs;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl << endl;

	pigs = cows;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl << endl;

	pigs = horses;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl << endl;

	//Added more tests to test the getSize method, the sum method, and insertAsLast method
	cout << "size of cows: " << cows.getSize() << endl;
	cout << "size of horses " << horses.getSize() << endl;
	cout << "size of pigs " << pigs.getSize() << endl << endl;

	cout << "The sum of cows: " << cows.sum() << endl;
	cout << "The sum of horses " << horses.sum() << endl;
	cout << "The sum of pigs " << pigs.sum() << endl << endl;

	List sheep;
	sheep.insertAsLast(2.44);
	cows.insertAsLast(3.4);
	cout << "sheep list: " << sheep << endl;
	cout << "cows list: " << cows << endl << endl;

	cout << "End of code" << endl;

	return 0;
}
