#include "stdafx.h"
#include "LinkedHashTable.h"
#include "iostream"

using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");

	LinkedHashTable* firstTable = new LinkedHashTable();
	firstTable->addElem(22, 0);
	firstTable->addElem(4, 1);
	firstTable->addElem(3, 2);
	firstTable->addElem(10, 4);
	firstTable->addElem(8, 3);
	firstTable->addElem(6, 12);
	cout << "Вывод с ключом:" << endl;
	firstTable->printElem();
	Iterator iter1(firstTable);
	cout << endl <<"Вывод с сохранением порядка: " << endl;
	iter1.start();
	
	while (iter1.hasNext()) {
		cout << iter1.seeElem() << endl;
		iter1.next();
	}
	cout << iter1.seeElem() << endl;
	cout << endl << "Вывод после удаления элемента с ключом \"3\": " << endl;
	firstTable->removeElem(3);
	iter1.start();
	
	while (iter1.hasNext()) {
		cout << iter1.seeElem() << endl;
		iter1.next();
	}
	cout << iter1.seeElem() << endl;
	cout << endl << "Поиск элементов с ключами \"0\" и  \"4\": " << endl;
	cout<< firstTable->findElem(0)<<endl;
	cout << firstTable->findElem(4) << endl;
	cout <<"Проверка на пустоту: " <<firstTable->isEmpty()<<endl;
	cout << "Сделать пустой." << endl;
	firstTable->doEmpty();
	cout << "Проверка на пустоту: " << firstTable->isEmpty() << endl;
	system("pause");
	return 0;
}

