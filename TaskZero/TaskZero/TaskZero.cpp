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

	Box *box1 = new Box(1, 1, 1, 3, 6);
	Box *box2 = new Box(2, 2, 2, 4, 10);
	Box *box3 = new Box(3, 3, 3, 5, 8);

	Box array[3] = { *box1, *box2, *box3 };

	for (int i = 0; i < 3; i++) {
		std::cout << "Коробка "<< i+1 << ": " << array[i] << std::endl;
	}


	std::cout << "Cумма цен в массиве коробок: " << sumValue(array, 3) << std::endl;

	std::cout << "Размер коробок не превосходит 30: " << isLessMaxDim(array, 3, 28) << std::endl;
	
	std::cout << "Кол-во коробок, вес которых не больше 4: " << maxWeightDimLess(array, 3, 4) << std::endl;

	system("pause");
	system("cls");


	Container *container = new Container(15, 15, 15, 30);
	Box *box4 = new Box(4, 6, 7, 2, 7);
	Box *box5 = new Box(5, 6, 2, 3, 8);
	Box *box6 = new Box(5, 6, 2, 14, 5);
	
	container->add(*box1);
	container->add(*box2);
	container->add(*box3);
	container->add(*box4);
	container->add(*box5);

	try{
		container->add(*box6);
	}
	catch (invalid_argument exeption) {
		std::cout << "Ошибка при добавлении box6!" << std::endl << std::endl;
	}

	std::cout << "Кол-во коробок в контейнере: " << container->getCount() << std::endl;
	std::cout << "Cуммарный вес содержимого контейнера: " << container->getWeight() << std::endl;
	std::cout << "Cуммарная стоимость содержимого: " << container->sum() << std::endl;


	std::cout << *container << std::endl;
	system("pause");

}


