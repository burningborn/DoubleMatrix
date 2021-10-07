#pragma once
class simpleArr
{
private:
	int n;
	int* arr;

public:
	
	simpleArr(int n);
	~simpleArr();

	int get_n() { return this->n; }
	void set_n(int n) { this->n = n; }

	simpleArr& fillRand();
	void display();
};

