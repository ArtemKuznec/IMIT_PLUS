#include "stdafx.h"
#include "BinarIntegerTree.h"
#include "locale.h"

int main()
{
	setlocale(LC_ALL, "rus");
	
	// �������� ���������� 
	//--------------------------------------------------------------------------------
	BinarIntegerTree testTree = BinarIntegerTree();
	try{
		std::vector<int> v = {1, 0};
		testTree.addElem(5, v);
	}
	catch (BadPathException) {
		std::cout << "���������� �������� �������, � ������ ���������� ������!" << std::endl;
	}
	try {
		testTree.findElem(2);
	}
	catch (NoElemException) {
		std::cout << "������� ���������� � ������!" << std::endl;
	}
	//--------------------------------------------------------------------------------
	
	

	
	
	// �������� �������
	//--------------------------------
	BinarIntegerTree tree;
	std::vector<int> v = {};				//					                10
	tree.addElem(10, v);					//								7		  21							
	v = { 1 };								//							 4	  9    16
	tree.addElem(21, v);					//						   2 			  19
	v = { 0 };
	tree.addElem(7, v);
	v = { 0, 0 };
	tree.addElem(4, v);
	v = { 0, 1 };
	tree.addElem(9, v);
	v = { 0, 0, 0 };
	tree.addElem(2, v);
	v = { 1, 0 };
	tree.addElem(16, v);
	v = { 1, 0, 1 };
	tree.addElem(19, v);
	std::cout << tree << std::endl;
	std::cout << "׸���� ��������� - " << tree.getEvenCount() << std::endl;
	std::cout << "� ������ ��� �������� ������������� - " << tree.checkPositive() << std::endl;
	std::cout << "������� �������������� - " << tree.getMiddle() << std::endl;
	v = tree.findElem(16);
	std::cout << "����� ��������: " << v[0] << "," << v[1] << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	v = { 0, 0, 0 };
	tree.addElem(-1, v);
	v = {};
	tree.addElem(45, v);
	std::cout << tree << std::endl;
	std::cout << "׸���� ��������� - " << tree.getEvenCount() << std::endl;
	std::cout << "� ������ ��� �������� ������������� - " << tree.checkPositive() << std::endl;
	std::cout << "������� �������������� - " << tree.getMiddle() << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	tree.deleteAllLeafs();
	std::cout << tree << std::endl;
	std::cout << "׸���� ��������� - " << tree.getEvenCount() << std::endl;
	std::cout << "� ������ ��� �������� ������������� - " << tree.checkPositive() << std::endl;
	std::cout << "������� �������������� - " << tree.getMiddle() << std::endl;
	system("pause");
	delete &tree;
    return 0;
}

