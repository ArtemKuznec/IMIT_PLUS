#pragma once

#include "iostream"
#include "string"


//узлы дерева
struct Node {
	std::string word;
	unsigned int frequency;
	int bal;
	Node *right, *left;
	Node(std::string word, unsigned int frequency = 1U, int bal = 0, Node *right = nullptr, Node *left = nullptr);
};

class TreeDictionary
{
private:
	Node* root;
	int size;
	void del2(Node *& rootLeft, Node *& toDel);
	void copyTree(Node *root, Node *copy);
	void deleteTree(Node *root);
	unsigned int findWord(Node *root, std::string word);
	void addWord(Node *& root, std::string& word);
	void deleteWord(Node *& root, std::string& word);
	void printTree(std::ostream& os, Node* root);
public:
	TreeDictionary();
	TreeDictionary(const TreeDictionary &copy);
	TreeDictionary(TreeDictionary &&move);
	~TreeDictionary();
	TreeDictionary& operator=(const TreeDictionary &copy);
	TreeDictionary& operator=(TreeDictionary &&move);
	unsigned int findWord(std::string word);
	void addWord(std::string word);
	void deleteWord(std::string word);
	unsigned int countWords();
	friend std::ostream& operator<< (std::ostream& os, TreeDictionary& obj);
};

