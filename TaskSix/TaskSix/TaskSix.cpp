#include "stdafx.h"
#include "TreeDictionary.h"


int main()
{
	setlocale(LC_ALL, "ru");

	TreeDictionary *tree = new TreeDictionary();
	std::cout << "__________________________________" << std::endl;
	tree->addWord("Артем");
	tree->addWord("Саша");
	tree->addWord("Аня");
	tree->addWord("Олег");
	tree->addWord("Лера");
	tree->addWord("Оля");
	tree->addWord("Артем");
	tree->addWord("Денис");
	tree->addWord("Роман");
	tree->addWord("Артем");
	tree->addWord("Роман");
	tree->addWord("Павел");
	tree->addWord("Лера");
	
	std::cout << *tree << std::endl;
	std::cout << "Кол-во слов в дереве: "<<tree->countWords() << std::endl;
	std::cout <<"Встречаемость слова \"Артем\" : " <<tree->findWord("Артем") << std::endl;
	std::cout << "Встречаемость слова \"Оля\" : " << tree->findWord("Оля") << std::endl;
	std::cout << "Встречаемость слова \"Роман\" : " << tree->findWord("Роман") << std::endl;
	//std::cout << "__________________________________" << std::endl;
	std::cout << "Удаление слов: Павел, Роман, Саша" <<std :: endl;
	std::cout << "__________________________________" << std::endl;
	tree->deleteWord("Павел");
	tree->deleteWord("Роман");
	tree->deleteWord("Оля");
	tree->deleteWord("Саша");
	std::cout << *tree << std::endl;
	std::cout << "Кол-во слов в дереве: "<<tree->countWords() << std::endl;
	std::cout << "Встречаемость слова \"Артем\" :" << tree->findWord("Артем") << std::endl;
	std::cout << "Встречаемость слова \"Оля\" :" << tree->findWord("Оля") << std::endl;
	std::cout << "Встречаемость слова \"Роман\" :" << tree->findWord("Роман") << std::endl;
	std::cout << "__________________________________" << std::endl;
	system("pause");
	delete tree;
    return 0;
}

