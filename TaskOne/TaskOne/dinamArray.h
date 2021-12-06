#pragma once

#include "stdafx.h"
#include "iostream"

using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;



class DinamArray {
	private: 
		int *arr;
		int size;
		int reserv;
	public:
		DinamArray();
		DinamArray(int size);
		DinamArray(int size, int n);
		DinamArray(const DinamArray &copy);
		DinamArray(DinamArray &&copy);
		DinamArray(int size, int reserv, int n);
		~DinamArray();
		int length();
		int& operator [] (int i);
		DinamArray& operator = (const DinamArray& obj);
		DinamArray& operator = (DinamArray&& obj);
		void resize(int newSize);
		bool operator == (const DinamArray& obj);
		bool operator != (const DinamArray& obj);
		bool operator < (const DinamArray& obj);
		bool operator <= (const DinamArray& obj);
		bool operator > (const DinamArray& obj);
		bool operator >= (const DinamArray& obj);
		DinamArray& operator + (const DinamArray& obj);
		friend istream& operator>> (istream& is, DinamArray& obj);
		friend ostream& operator<< (ostream& os, const DinamArray& obj);
		void reserve(int n);
		int capacity();
		void pushBack(int x);
		int popBack();
};

