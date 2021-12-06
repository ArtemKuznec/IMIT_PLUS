#include "stdafx.h"
#include "HashTable.h"
#include "iostream"


int main()
{
	setlocale(LC_ALL, "ru");

	//Проверка исключений
	//------------------------------------------------------
	
	//1
	try {
		HashTable *example = new HashTable(-4);
	}
	catch (WrongSizeException) {
		std::cout << "Отрицательный размер таблицы!" << std::endl;
	}
	
	//2
	try {
		HashTable *example = new HashTable(0);
	}
	catch (WrongSizeException) {
		std::cout << "Рамзмер таблицы не равен нулю!" << std::endl;
	}
	
	//3
	HashTable *example = new HashTable();
	try{
		example->printElem();
	}
	catch (NoElemException) {
		std::cout << "HashTable пуста!" << std::endl;
	}
	
	//4
	try {
		Iterator iter(example);
		iter.start();
	}
	catch (IteratorWrongCountException) {
		std::cout << "Итератор не может быть запущен, таблица пуста!" << std::endl;
	}

	//5
	example->addElem(4, 1);
	try {
		example->addElem(75, 1);
	}
	catch (CopyOfElementException) {
		std::cout << "Элемент уже существует в таблице!" << std::endl;
	}
	//--------------------------------------------------------------------------


	system("pause");
	system("cls");

	//Работа методов 
	//---------------------------------------------------------------
	HashTable *table = new HashTable(5);
	table->addElem(566, 1);
	table->addElem(3221, 2);
	table->addElem(221, 3);
	table->addElem(3234, 4);
	table->addElem(113578, 5);
	std::cout << "Ввод на экран" << std::endl;
	table->printElem();
	std::cout << std::endl;
	std::cout << "Удаляем элемент с ключом 3" << std::endl;
	std::cout << std::endl;
	table->removeElem(3);
	std::cout << "Поиск элемента с ключом 4:"<< table->findElem(4) << std::endl;
	std::cout << std::endl;

	std::cout << "Работа итератора" << std::endl;
	Iterator iter(table);
	iter.start();
	while (iter.hasNext()) {
		std::cout << iter.seeElem() << std::endl;
		iter.next();
	}

	std::cout << "Удаляем table" << std::endl;
	std::cout << table->isEmpty() << std::endl;
	table->doEmpty();
	std::cout << table->isEmpty() << std::endl;
	try {
		Iterator iter(table);
		iter.start();
	}
	catch (IteratorWrongCountException) {
		std::cout << "Итератор не может быть запущен, таблица пуста!" << std::endl;
	}

}
