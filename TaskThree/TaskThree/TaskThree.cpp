#include "stdafx.h"
#include "BufferList.h"
#include "locale.h"


int main()
{
	setlocale(LC_ALL, "ru");
	
	// �������� �� ����������
	//--------------------------------------------------------------------------------
	BufferList *example = new BufferList();
	BufferList::ListIterator itr0(example);
	try {
		itr0.getElement();
	}
	catch (BufferException) {
		std::cout << "������ ����. ���������� �������� ��������� �������!" << std::endl;
	}
	try {
		example->deleteElem(itr0);
	}
	catch (BufferException) {
		std::cout << "������ ����. ���������� ������� ��������� �������!" << std::endl;
	}

	example->addElem(1, itr0);
	itr0.next();
	try {
		example->findElem(5);
	}
	catch (NoElemException) {
		std::cout << "������� � ������ ��������� ���������� � ������!" << std::endl;
	}
	system("pause");
	system("cls");
	//-------------------------------------------------------------------------------


	//������ �������
	//----------------------------------------------
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
	std::cout << "����� ������:" << std::endl;
	while (!itr.finish())
	{
		itr.next();
		std::cout << itr.getElement() << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;
	
	std::cout << "������� ������� �� ��������� 3" << std::endl;
	Iterator *itr2 = firstBL->findElem(3);
	firstBL->deleteElem(*itr2);
	std::cout << "��������� �������� 5, 6" << std::endl;
	firstBL->addElem(5, itr);
	itr.next();
	firstBL->addElem(6, itr);
	itr.start();
	while (!itr.finish())
	{
		itr.next();
		std::cout << itr.getElement() << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;
	
	std::cout << firstBL->findElem(5)->getElement() << std::endl;
	std::cout << "������: "<< firstBL->getSize() << std::endl;
	std::cout << "�������� �� �������: " << firstBL->isEmpty() << std::endl;
	std::cout << "�������� �������� ������." << std::endl;
	firstBL->makeEmpty();
	std::cout << "�������� �� �������: " << firstBL->isEmpty() << std::endl;
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

