//Необходимо реализовать класс «Матрица» с хранение двумерного массива 
//данных внутри класса в виде динамического массива double.
//Реализовать конструктор, деструктор, перегрузить операторы[], +, - 
// для получения, установки элемента, сложения и вычитания(можно по выбору) двух матриц.

#include <iostream>
using namespace std;
#include "Matrix.h"
#define delimiter "\n==================================================\n"


void main()
{
	setlocale(LC_ALL, "Russian");

	Matrix mat(2, 4);
	mat.fillRand();
	cout << "mat: " << endl; mat.display();
	cout << delimiter;
	Matrix matX(2, 4);
	matX.fillRand();
	cout << "matX: " << endl; matX.display();
	cout << delimiter;
	Matrix matZ(2, 4);
	//matZ = mat + matX;
	cout << "matZ: " << endl; matZ.display();
	cout << delimiter;
	matZ = mat;
	cout << "matZ = mat: " << endl; matZ.display();
	cout << delimiter;
	matX = mat + matZ;
	//cout << delimiter;
	cout << "mat + matZ: " << endl; matX.display();
	mat = matX - matZ;
	//cout << delimiter;
	cout << "matX - matZ: " << endl; mat.display();
	cout << delimiter;
	cout << "Element of mat: " << mat.getElementData(0, 1) << endl;
	cout << delimiter;
	mat.setElementData(0, 1, -123.54);
	cout << "Element of mat: \n"; mat.display();

}