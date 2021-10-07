#include <iostream>
using namespace std;
#include "Matrix.h"

Matrix::Matrix()
{
	m = n = 0;
	arr = nullptr;
	//cout << "ConstructorWithout: " << endl;
}
Matrix::Matrix(size_t m, size_t n)
{
	set_m(m);
	set_n(n);
	arr = new double* [m] {}; // Выделяем память под массив строк
	for (int i = 0; i < m; i++)
		arr[i] = new double[n] {};     // Выделяем память под столбцы и заполняем нолями
	//cout << "ConstructorWithParameters: " << endl;
}
Matrix::Matrix(const Matrix& other)
{
		this->m = other.m;
		this->n = other.n;
	this->arr = new double* [other.m] {}; // Выделяем память под массив строк
	for (int i = 0; i < m; i++)
		this->arr[i] = new double[other.n] {};     // Выделяем память под столбцы и заполняем нолями
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			this->arr[i][j] = other.arr[i][j];		//копируем поэлементно
		}
	}
	//cout << "CopyConstructor: " << endl;	
}
Matrix::~Matrix()
{
	for (int i = 0; i < m; i++) {
		delete[] arr[i];				//стираем столбцы
	}
	delete[] arr;						//стираем укзатель на строки
	//cout << "Destructor: " << endl;
}

Matrix& Matrix::setElementData(int index_I, int index_J, double date)
{
	this->arr[index_I][index_J] = date;
	return *this;
}
double Matrix::getElementData(int index_I, int index_J)
{
	return this->arr[index_I][index_J];
}

Matrix& Matrix::fillRand()
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			
			arr[i][j] = (double)(rand() % 1000 - 500) / 10;
		}
	}
	return *this;	
}
Matrix& Matrix::operator=(const Matrix& other) {
	if (this->m == other.m && this->n == other.n) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				this->arr[i][j] = other.arr[i][j];
			}
		}
		//cout << "operator=(Matrix& other) " << endl;
	}
	else { cout << "Matrixes are not Equal!!!" << endl; }
	return *this;
}
Matrix Matrix::operator+(const Matrix& other)
{
	if (this->m == other.m && this->n == other.n) {
	Matrix temp(other.m, other.n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			temp.arr[i][j] = this->arr[i][j] + other.arr[i][j];			
		}
	}
	return temp;
	}
	else { cout << "Matrixes are not Equal!!!" << endl; }
}
Matrix Matrix::operator-(const Matrix& other)
{
	if (this->m == other.m && this->n == other.n) {
		Matrix temp(other.m, other.n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				temp.arr[i][j] = this->arr[i][j] - other.arr[i][j];
			}
		}
		return temp;
	}
	else { cout << "Matrixes are not Equal!!!" << endl; }
}


