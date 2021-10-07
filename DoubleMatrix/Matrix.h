#pragma once

class Matrix
{
private:
	size_t m, n;    // m - строки, n -  столбцы
	double** arr;

public:
	Matrix();
	Matrix(size_t m, size_t n);
	Matrix(const Matrix& other);
	~Matrix();

	size_t get_n() { return n; }
	size_t get_m() { return m; }

	void set_n(size_t n) { this->n = n; }
	void set_m(size_t m) { this->m = m; }
	/*double operator[](int i)
	{
		return *arr[i];
	}
	const double operator[](int i)const
	{
		return *arr[i];
	} */
	Matrix& setElementData(int index_I, int index_J, double date);		 //установка значения элемента по его индексу
	double getElementData(int index_I, int index_J);					 //получение значения элемента по его индексу
	Matrix& fillRand();
	Matrix& operator=(const Matrix& other);
	Matrix operator+(const Matrix& other);
	Matrix operator-(const Matrix& other);

	void display() {

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) { cout << arr[i][j] << " * "; }
		cout << endl;
		}
			
	}
};
