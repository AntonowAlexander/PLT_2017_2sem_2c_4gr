#include "stdafx.h"
#include "iostream"
#include "trie.h"
#include "string"

using namespace std;

//��������������� �-���:

void Trie::init(node* Node) { //����� ��� ���������� ������ ����
	Node->end = false;
	Node->parent = false;
	Node->length = 0;
	Node->vowQuant = 0;
	for (unsigned int i = 0; i < aLength; Node->child[i++] = nullptr);
}

Trie::Trie() { //�����������
	Head = new node;
	Head->key = ' ';
	Head->end = false;
	Head->parent = false;
	Head->length = 0;
	Head->vowQuant = 0;
	for (unsigned int i = 0; i < aLength; Head->child[i++] = nullptr);
}

bool isVowel(char c) { //��������� ����� �� ���������
	if ((c == 'a') || (c == 'A')) return true;
	if ((c == 'e') || (c == 'E')) return true;
	if ((c == 'i') || (c == 'I')) return true;
	if ((c == 'o') || (c == 'O')) return true;
	if ((c == 'u') || (c == 'U')) return true;
	if ((c == 'y') || (c == 'Y')) return true;
	else return false;
}

 int Trie::countCons(node* Node) { //������� ���-�� ���������, ����� ����� ������ ��� ��������� ��-��
	return (Node->length) - (Node->vowQuant);
}

/////////////

//�������� �-���:

void Trie::push(char* word) { //��������� �����
	node* Current = Head;
	int letter;

	while (*word) { //���� ����� �� ����������� ������������ �� �� ������
		letter = (int)(*word) - (int)a; //����������� ����� ����� ������ � � �������� � ������ ��������
		if (Current->child[letter] == nullptr) { //���� ��� ������ �� ������
			Current->child[letter] = new node;
			init(Current->child[letter]);
			Current->parent = true;
		}

		//���������� ������ ����������� ��� missionX
		Current->child[letter]->key = *word;
		Current->child[letter]->length = Current->length + 1;
		Current->child[letter]->vowQuant = Current->vowQuant;
		if (isVowel(Current->child[letter]->key)) Current->child[letter]->vowQuant++;
		Current = Current->child[letter];
		word++;
	}

	Current->end = true;
}

int Trie::missionX(int cq, node* Node) { //������� ���-�� ���� � ���. ������ ���������, �����������
	node* Current = Node;
	int X = 0;
	if ((Current->parent == false)) { //���� � �������� ��-�� ��� �����, ��� �� ���� �� ��������,
		if (countCons(Current) == cq) X++;
	} //�� ��������� ������������� �� ��� ����� �������.
	else {
		if ((Current->end) && (countCons(Current) == cq)) X++;
		for (unsigned int i = 0; i < aLength; i++)
			if (Current->child[i] != nullptr)
				X += missionX(cq, Current->child[i]); //����� ��� �� ��� ��������
	}
	return X;
}

void Trie::print(char* indent, bool last, node* root) //����� ������. ������ ��������, ����� ����������������.
{
	cout << indent;

	if (last)
	{
		cout << "+-";
		//*indent += " ";
	}
	else
	{
		std::cout << "|- ";
		//indent += "| ";
	}

	std::cout << root->key << std::endl;

	for (unsigned int i = 0; i< aLength; i++)
		if (root->child[i] != nullptr)
			print(indent, root->child[i]->end, root->child[i]);
};

/////////////