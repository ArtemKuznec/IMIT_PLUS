#include "stdafx.h"
#include "BinarIntegerTree.h"
#include "locale.h"

int main()
{
	setlocale(LC_ALL, "rus");
	BinarIntegerTree tree;
	std::vector<int> v = {};
	tree.addElem(10, v);
	v = { 1 };
	tree.addElem(21, v);
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
	std::cout << "Чётных элементов - " << tree.getEvenCount() << std::endl;
	std::cout << "В дереве все элементы положительные - " << tree.checkPositive() << std::endl;
	std::cout << "Среднее арифметическое - " << tree.getMiddle() << std::endl;
	std::cout << "Проверка на бинарный поиск - " << tree.checkBinaryFindTree() << std::endl;
	v = tree.findElem(16);
	std::cout << "Поиск элемента: " << v[0] << " " << v[1] << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	v = { 0, 0, 0 };
	tree.addElem(-1, v);
	v = {};
	tree.addElem(45, v);
	std::cout << tree << std::endl;
	std::cout << "Чётных элементов - " << tree.getEvenCount() << std::endl;
	std::cout << "В дереве все элементы положительные - " << tree.checkPositive() << std::endl;
	std::cout << "Среднее арифметическое - " << tree.getMiddle() << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	tree.deleteAllLeafs();
	std::cout << tree << std::endl;
	std::cout << "Чётных элементов - " << tree.getEvenCount() << std::endl;
	std::cout << "В дереве все элементы положительные - " << tree.checkPositive() << std::endl;
	std::cout << "Среднее арифметическое - " << tree.getMiddle() << std::endl;
	std::cout << "Проверка на бинарный поиск - " << tree.checkBinaryFindTree() << std::endl;
	system("pause");
    return 0;
}

