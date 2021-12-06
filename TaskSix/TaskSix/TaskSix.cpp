#include "stdafx.h"
#include "TreeDictionary.h"


int main()
{
	setlocale(LC_ALL, "ru");

	TreeDictionary *tree = new TreeDictionary();
	std::cout << "__________________________________" << std::endl;
	tree->addWord("�����");
	tree->addWord("����");
	tree->addWord("���");
	tree->addWord("����");
	tree->addWord("����");
	tree->addWord("���");
	tree->addWord("�����");
	tree->addWord("�����");
	tree->addWord("�����");
	tree->addWord("�����");
	tree->addWord("�����");
	tree->addWord("�����");
	tree->addWord("����");
	
	std::cout << *tree << std::endl;
	std::cout << "���-�� ���� � ������: "<<tree->countWords() << std::endl;
	std::cout <<"������������� ����� \"�����\" : " <<tree->findWord("�����") << std::endl;
	std::cout << "������������� ����� \"���\" : " << tree->findWord("���") << std::endl;
	std::cout << "������������� ����� \"�����\" : " << tree->findWord("�����") << std::endl;
	//std::cout << "__________________________________" << std::endl;
	std::cout << "�������� ����: �����, �����, ����" <<std :: endl;
	std::cout << "__________________________________" << std::endl;
	tree->deleteWord("�����");
	tree->deleteWord("�����");
	tree->deleteWord("���");
	tree->deleteWord("����");
	std::cout << *tree << std::endl;
	std::cout << "���-�� ���� � ������: "<<tree->countWords() << std::endl;
	std::cout << "������������� ����� \"�����\" :" << tree->findWord("�����") << std::endl;
	std::cout << "������������� ����� \"���\" :" << tree->findWord("���") << std::endl;
	std::cout << "������������� ����� \"�����\" :" << tree->findWord("�����") << std::endl;
	std::cout << "__________________________________" << std::endl;
	system("pause");
	delete tree;
    return 0;
}

