
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


int main()
{
	setlocale(LC_ALL, "ru");
	int status = 0;
	int numArr = 0;

	DinamArray arr1(5, 8);
	DinamArray arr2 = DinamArray(5);
	DinamArray arr3;
	while (status != -1) {
		if (status == 0) {
			cout << "1.Изменить массив\n2.Вывести массив" << endl;
			cout << "3.Узнать длинну массива\n4.Получить доступ к i-ому элементу массива(оператор [])" << endl;
			cout << "5.Оператор \"=\"\n6.Изменить размер" << endl;
			cout << "7.Сравнить массивы\n8.Сложить массивы" << endl;
			cout << "9.Зарезервировать место\n10.Вывести колличество зарезервированного места" << endl;
			cout << "11.Поместить элемент в конец массива\n12.Забрать элемент из конца массива" << endl;
			cout << "-1 для выхода" << endl;
			cin >> status;
			system("cls");
		}
		if (status == 1) {
			cout << "Какой массивы надо заполнить?(1/2)" << endl;
			cin >> numArr;
			if (numArr == 1) {
				cin >> arr1;
			}
			if (numArr == 2) {
				cin >> arr2;
			}
			status = 0;
			cout << "Готово!" << endl;
			_getch();
			system("cls");
		}
		if (status == 2) {
			cout << "Какой массивы надо вывести?(1/2)" << endl;
			cin >> numArr;
			if (numArr == 1) {
				cout << arr1;
			}
			if (numArr == 2) {
				cout << arr2;
			}
			status = 0;
			_getch();
			system("cls");
		}
		if (status == 3) {
			cout << "Длину какого массива надо узнать?(1/2)" << endl;
			cin >> numArr;
			if (numArr == 1) {
				cout << arr1.length();
			}
			if (numArr == 2) {
				cout << arr2.length();
			}
			status = 0;
			_getch();
			system("cls");
		}
		if (status == 4) {
			int i = 0, num;
			cout << "С каким массивом работаем?(1/2)" << endl;
			cin >> numArr;
			cout << "Какой элемент вытащить?" << endl;
			cin >> i;
		
			try {//добавлено 01.12
				if (numArr == 1) {
					cout << "array1[" << i << "]" << " = " << arr1[i] << endl;
					cout << "Введите число, чтобы изменить значение элемента" << endl;
					cin >> num;
					arr1[i] = num;
					cout << "array1[" << i << "]" << " = " << arr1[i] << endl;
				}
				if (numArr == 2) {
					cout << "array2[" << i << "]" << " = " << arr1[i] << endl;
					cout << "Введите число, чтобы изменить значение элемента" << endl;
					cin >> num;
					arr2[i] = num;
					cout << "array2[" << i << "]" << " = " << arr1[i] << endl;
				}
			}
			catch (BadIndexException e) {
				std::cerr << "Выход заграницы массива!" << endl;
			}

		

			status = 0;
			_getch();
			system("cls");


			
		}
		if (status == 5) {
			cout << "Какой массив приравнять?(1/2)" << endl;
			cin >> numArr;
			if (numArr == 1) {
				arr1 = arr2;
			}
			if (numArr == 2) {
				arr2 = arr1;
			}
			status = 0;
			_getch();
			system("cls");
		}
		if (status == 6) {
			int size;
			cout << "Длину какого массива надо изменить?(1/2)" << endl;
			cin >> numArr;
			cout << "Введите новую длинну." << endl;
			cin >> size;
			try {
				if (numArr == 1) {
					arr1.resize(size);
				}
				if (numArr == 2) {
					arr2.resize(size);
				}
			}
			catch (BadSizeException e) {
				std::cerr << "Длина должна быть положительной!" << endl;
			}
			status = 0;
			cout << "Готово!" << endl;
			_getch();
			system("cls");
		}
		if (status == 7) {
			bool flag = false;
			try {
				cout << "  ==  !=   <    >   <=   >=\n  " << (arr1 == arr2) << "  " << (arr1 != arr2) << "    ";
			}
			catch (BadArrayLengthException e) {
				std::cerr << "Размеры массивов разные" << endl;
				flag = true;
			}
			if (flag) {
				cout << "<    >   <=   >=" << endl;
			}
			cout << (arr1 < arr2) << "    " << (arr1 > arr2) << "    " << (arr1 <= arr2) << "    " << (arr1 >= arr2) << "    " << endl;
			status = 0;
			cout << "Готово!" << endl;
			_getch();
			system("cls");
		}
		if (status == 8) {
			arr3 = arr1 + arr2;
			status = 0;
			cout << arr3;
			cout << "Готово!" << endl;
			_getch();
			system("cls");
		}
		if (status == 9) {
			int reserv;
			cout << "В каком массиве надо зарезервировать память?(1/2)" << endl;
			cin >> numArr;
			cout << "Введите новую длинну." << endl;
			cin >> reserv;
			try {
				if (numArr == 1) {
					arr1.reserve(reserv);
				}
				if (numArr == 2) {
					arr2.reserve(reserv);
				}
			}
			catch (BadReservException e) {
				std::cerr << "Длина должна быть положительной!" << endl;
			}
			status = 0;
			cout << "Готово!" << endl;
			_getch();
			system("cls");
		}
		if (status == 10) {
			int size;
			cout << "Резерв какого массива надо узнать?(1/2)" << endl;
			cin >> numArr;
			if (numArr == 1) {
				cout << arr1.capacity();
			}
			if (numArr == 2) {
				cout << arr2.capacity();
			}
			status = 0;
			_getch();
			system("cls");
		}
		if (status == 11) {
			int elem;
			cout << "В конец какого массива поместить элемент?(1/2)" << endl;
			cin >> numArr;
			cout << "Введите элемент." << endl;
			cin >> elem;
			try {
				if (numArr == 1) {
					arr1.pushBack(elem);
				}
				if (numArr == 2) {
					arr2.pushBack(elem);
				}
			}
			catch (EndOfReservException e) {
				std::cerr << "Нет зарезервированного места!" << endl;
			}
			status = 0;
			cout << "Готово!" << endl;
			_getch();
			system("cls");
		}
		if (status == 12) {
			cout << "Из какого массива взять элемент?(1/2)" << endl;
			cin >> numArr;
			try {
				if (numArr == 1) {
					cout << arr1.popBack();
				}
				if (numArr == 2) {
					cout << arr2.popBack();
				}
			}
			catch (EndSizeOfArrayException e) {
				std::cerr << "Нечего извлекать!" << endl;
			}
			status = 0;
			_getch();
			system("cls");
		}
	}
	return 0;
}