
#include "stdafx.h"
#include "iostream"
#include "dinamArray.h"
#include "conio.h"
#include "locale.h"

using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;


struct BadArrayLengthException {};
struct EndOfReservException {};
struct EndSizeOfArrayException {};
struct BadIndexException {};
struct BadSizeException {};
struct BadReservException {};



DinamArray::DinamArray() {
	arr = new int[15];
	size = 15;
	reserv = 0;
}

DinamArray::DinamArray(int size) {
	arr = new int[size];
	this->size = size;
	reserv = 0;
}

DinamArray::DinamArray(int size, int n) {
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = n;
	}
	this->size = size;
	reserv = 0;
}

DinamArray::DinamArray(const DinamArray &copy) {
	this->arr = new int[copy.size];
	this->size = copy.size;
	for (int i = 0; i < copy.size; i++) {
		arr[i] = copy.arr[i];
	}
	reserv = 0;
}

DinamArray::DinamArray(DinamArray &&copy) {
	this->arr = new int[copy.size];
	this->size = copy.size;
	for (int i = 0; i < copy.size; i++) {
		arr[i] = copy.arr[i];
	}
	copy.size = 15;
	delete[] copy.arr;
	copy.arr = new int[15];
	reserv = 0;
}

DinamArray::DinamArray(int size, int reserv, int n) {
	arr = new int[size + reserv];
	this->size = size;
	for (int i = 0; i < size; i++) {
		arr[i] = n;
	}
	this->reserv = reserv;
}

DinamArray::~DinamArray() {
	delete[] arr;
	reserv = NULL;
	size = NULL;
}

int DinamArray::length() {
	return size;
}

int DinamArray::operator [] (int i) {
	if (i >= this->size) {
		throw BadIndexException();
	}
	return arr[i];
}

DinamArray& DinamArray::operator = (const DinamArray& obj) {
	delete[] this->arr;
	this->arr = new int[obj.size];
	for (int i = 0; i < obj.size; i++) {
		arr[i] = obj.arr[i];
	}
	this->size = obj.size;
	return *this;
}

DinamArray& DinamArray::operator = (DinamArray&& obj) {
	delete[] this->arr;
	this->arr = new int[obj.size];
	for (int i = 0; i < obj.size; i++) {
		arr[i] = obj.arr[i];
	}
	this->size = obj.size;
	delete[] obj.arr;
	obj.size = 15;
	obj.arr = new int[15];
	return *this;
}

void DinamArray::resize(int newSize) {
	if (newSize < 0) {
		throw BadSizeException();
	}
	if (newSize > this->size + this->reserv) {
		int *buf = new int[newSize];
		for (int i = 0; i < newSize; i++) {
			if (i < size) {
				buf[i] = this->arr[i];
			}
			else {
				buf[i] = 0;
			}
		}
		size = newSize;
		delete[]arr;
		this->arr = buf;
	}
	else {
		newSize = newSize - size;
		size = size + newSize;
		reserv = reserv - newSize;
	}
}

bool DinamArray::operator == (const DinamArray& obj) {
	bool flag = true;
	if (this->size != obj.size) {
		throw BadArrayLengthException();
	}
	else {
		for (int i = 0; i < this->size; i++) {
			if (this->arr[i] != obj.arr[i]) {
				flag = false;
			}
		}
		return flag;
	}
}

bool DinamArray::operator != (const DinamArray& obj) {
	bool flag = false;
	if (this->size != obj.size) {
		throw BadArrayLengthException();
	}
	else {
		for (int i = 0; i < this->size; i++) {
			if (this->arr[i] != obj.arr[i]) {
				flag = true;
			}
		}
		return flag;
	}
}

bool DinamArray::operator < (const DinamArray& obj) {
	bool flag = false;
	int n = this->size, i = 0;
	if (n < obj.size) {
		n = obj.size;
	}
	while (i < n && this->arr[i] <= obj.arr[i]) {
		if (this->arr[i] < obj.arr[i]) {
			flag = true;
		}
		i++;
		if (i == n && !flag && n == obj.size && obj.size != this->size) {
			flag = true;
		}
	}
	return flag;
}

bool DinamArray::operator <= (const DinamArray& obj) {
	bool flag = false;
	int n = this->size, i = 0;
	if (n < obj.size) {
		n = obj.size;
	}
	while (i < n && this->arr[i] <= obj.arr[i]) {
		if (this->arr[i] < obj.arr[i]) {
			flag = true;
		}
		i++;
		if (i == n && !flag && n == obj.size) {
			flag = true;
		}
	}
	return flag;
}

bool DinamArray::operator > (const DinamArray& obj) {
	bool flag = false;
	int n = obj.size, i = 0;
	if (n < this->size) {
		n = this->size;
	}
	while (i < n && this->arr[i] >= obj.arr[i]) {
		if (this->arr[i] > obj.arr[i]) {
			flag = true;
		}
		i++;
		if (i == n && !flag && n == this->size && obj.size != this->size) {
			flag = true;
		}
	}
	return flag;
}

bool DinamArray::operator >= (const DinamArray& obj) {
	bool flag = false;
	int n = obj.size, i = 0;
	if (n < this->size) {
		n = this->size;
	}
	while (i < n && this->arr[i] >= obj.arr[i]) {
		if (this->arr[i] > obj.arr[i]) {
			flag = true;
		}
		i++;
		if (i == n && !flag && n == this->size) {
			flag = true;
		}
	}
	return flag;
}

DinamArray& DinamArray::operator + (const DinamArray& obj) {
	int newSize = this->size + obj.size;
	DinamArray *sumArr = new DinamArray(newSize);
	sumArr->reserve(this->reserv + obj.reserv);
	for (int i = 0; i < this->size; i++) {
		sumArr->arr[i] = arr[i];
	}
	for (int i = 0; i < obj.size; i++) {
		sumArr->arr[this->size + i] = obj.arr[i];
	}
	return *sumArr;
}

istream& operator>> (istream& is, DinamArray& obj) {
	cout << "¬ведите размер" << endl;
	int newSize, reserv;
	is >> newSize;
	obj.resize(newSize);
	obj.size = newSize;
	cout << "\n¬ведите резерв" << endl;
	is >> reserv;
	obj.reserve(reserv);
	obj.reserv = reserv;
	cout << "\n¬ведите элементы" << endl;
	for (int i = 0; i < obj.size; i++) {
		is >> obj.arr[i];
	}
	return is;
}

 ostream& operator<< (ostream& os, const DinamArray& obj) {
	os << "size = " << obj.size << " reserv = " << obj.reserv << " array = { ";
	for (int i = 0; i < obj.size; i++) {
		os << obj.arr[i] << ' ';
	}
	os << "}" << endl;
	return os;
}

void DinamArray::reserve(int n) {
	if (n < 0) {
		throw BadReservException();
	}
	if (n > 0) {
		reserv = n;
		int *buf = new int[size + n];
		for (int i = 0; i < size; i++) {
			buf[i] = arr[i];
		}
		delete[]arr;
		arr = buf;
	}
}

int DinamArray::capacity() {
	return reserv;
}

void DinamArray::pushBack(int x) {
	if (reserv == 0) {
		reserv = 13;
		int *buf = new int[size + reserv];
		for (int i = 0; i < size; i++) {
			if (i < size) {
				buf[i] = this->arr[i];
			}
			else {
				buf[i] = 0;
			}
		}
		buf[size] = x;
		size++;
		delete[]arr;
		this->arr = buf;
	}
	else {
		reserv--;
		arr[size] = x;
		size++;
	}
}

int DinamArray::popBack() {
	if (size == 0) {
		throw EndSizeOfArrayException();
	}
	reserv++;
	size--;
	return arr[size];
}

