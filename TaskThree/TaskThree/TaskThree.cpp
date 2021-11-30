#include "stdafx.h"
#include "BufferList.h"
#include "locale.h"


int main()
{
	setlocale(LC_ALL, "ru");
	BufferList *firstBL = new BufferList();
	BufferList::ListIterator itr(firstBL);
	firstBL->addElem(1,itr);
	itr.next();
	firstBL->addElem(3, itr);
	itr.next();
	firstBL->addElem(2, itr);
	itr.next();
	firstBL->addElem(4, itr);

	itr.start();
	std::cout << "Вывод буферного списка:" << std::endl;
	while (!itr.finish())
	{
		itr.next();
		std::cout << itr.getElement() << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;
	Iterator *itr2 = firstBL->findElem(3);
	firstBL->deleteElem(*itr2);
	std::cout << "После удаления элемента со значением 3" << std::endl;
	itr.start();
	while (!itr.finish())
	{
		itr.next();
		std::cout << itr.getElement() << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Размер: "<< firstBL->getSize() << std::endl;
	std::cout << "Проверка на пустоту: " << firstBL->isEmpty() << std::endl;
	std::cout << "Обнуляем буферный список." << std::endl;
	firstBL->makeEmpty();
	std::cout << "Проверка на пустоту: " << firstBL->isEmpty() << std::endl;
	itr.start();
	std::cout << "--------------------------------" << std::endl;
	while (!itr.finish())
	{
		itr.next();
		std::cout << itr.getElement() << std::endl;
	}
	system("pause");
    return 0;
}

