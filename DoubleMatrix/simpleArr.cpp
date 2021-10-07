#include <iostream>
using namespace std;
#include "simpleArr.h"



simpleArr::simpleArr(int n) :n{ n }
{
	//set_n(n);
	arr = new int[n];
}

simpleArr::~simpleArr()
{
	delete[] arr;
}

simpleArr& simpleArr::fillRand()
{
		int digit = 0;
	for (int i = 0; i < n; i++) {
		arr[i] = digit;
		digit++;
	}
	return *this;
}

void simpleArr::display()
{
	for (int i = 0; i < n; i++) {
	
		cout << arr[i] << " * ";
	}
	cout << endl;
}
