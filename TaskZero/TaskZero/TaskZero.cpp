// TaskZero.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "box.h"
#include "container.h"
#include "stdafx.h"
#include <iostream>

using namespace ContBox;

int main()
{
	setlocale(LC_ALL, "Russian");

	//Проверка на исключения
	//-------------------------------------------------------------
	//1.Создание Box с некорректными параметрами
	try{
		Box box = Box(0, 0, 0, 0, 0);
	}
	catch (invalid_argument ex) {
		std::cout << ex.what() << std::endl;
	}
	
	Box box = Box(1, 1, 4, 3, 6);

	//2.Задание неверной длины   
	try {
		box.setLength(0);
	}
	catch (invalid_argument ex) {
		std::cout << "Length " << ex.what() << std::endl;
	}

	//3.Задание неверной ширины
	try {
		box.setWidth(0);
	}
	catch (invalid_argument ex) {
		std::cout << "Width " << ex.what() << std::endl;
	}

	//4.Задание неверной высоты
	try {
		box.setHeight(0);
	}
	catch (invalid_argument ex) {
		std::cout << "Height " << ex.what() << std::endl;
	}

	//5.Задание неверного веса
	try {
		box.setWeight(0);
	}
	catch (invalid_argument ex) {
		std::cout << "Weight " << ex.what() << std::endl;
	}

	//6.Задание неверной цены
	try {
		box.setValue(0);
	}
	catch (invalid_argument ex) {
		std::cout << "Value " << ex.what() << std::endl;
	}

	//8. Создание Container с некорректными параметрами
	try {
		Container container = Container(0, 0, 0, 0);
	}
	catch (invalid_argument ex) {
		std::cout << ex.what() << std::endl;
	}

	Container container1 = Container(2, 4, 4, 5);
	Box box1 = Box(1, 1, 1, 3, 6);
	Box box2 = Box(2, 2, 2, 3, 10);

	//9.Добавление коробки с превышением максимальной величины
	try {
		container1.add(box1);
		container1.add(box2);
	}
	catch (invalid_argument ex) {
		std::cout << ex.what() << std::endl << std::endl;
	}

	system("pause");
	system("cls");
	//-------------------------------------------------------------
	


	//Проверка конструкторов, методов классов 
	//-------------------------------------------------------------

	Box box3 = Box(3, 3, 3, 5, 8);

	Box array[3] = { box2, box1, box3 };

	putEachOther(array, 3);



	for (int i = 0; i < 3; i++) {
		std::cout << "Коробка "<< i+1 << ": " << array[i] << std::endl;
	}

	std::cout << "Cумма цен в массиве коробок: " << sumValue(array, 3) << std::endl;
	std::cout << "Размер коробок не превосходит 30: " << isLessMaxDim(array, 3, 28) << std::endl;
	std::cout << "Кол-во коробок, вес которых не больше 4: " << maxWeightDimLess(array, 3, 4) << std::endl;
	system("pause");
	system("cls");

	Container container2 = Container(15, 15, 15, 40);
	Box box4 = Box(4, 6, 7, 2, 7);
	Box box5 = Box(5, 6, 2, 3, 8);
	Box box6 = Box(5, 6, 2, 14, 5);
	
	container2.add(box1);
	container2.add(box2);
	container2.add(box3);
	container2.add(box4);
	container2.add(box5);
	container2.add(box6);

	std::cout << "Кол-во коробок в контейнере: " << container2.getCount() << std::endl;
	std::cout << "Cуммарный вес содержимого контейнера: " << container2.getWeight() << std::endl;
	std::cout << "Cуммарная стоимость содержимого: " << container2.sum() << std::endl;
	container2.del(2);
	std::cout << "Вывод 3ей коробки: \n" << container2[2] << std::endl;

	Box* array2 = new Box[3];
	array2 = putEachOther(array, 3);
	
	std::cout << "Вложенность коробок" << std::endl;
	for (int i = 0; i < 3; i++) {
		std::cout << "Коробка " << i + 1 << ": " << array2[i] << std::endl;
	}
	
	//std::cout << putEachOther(array, 3) << std::endl;
	system("pause");

}


