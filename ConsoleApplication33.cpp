// ConsoleApplication33.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include "stdafx.h"
using namespace std;

const int abSize = 25; 
const string cons = "bcdfghjklmnpqrstvwxz"; 
int consEndNum = 0;

struct Node 
{
	bool isWord = false;
	Node* next[abSize] ;
};

void add(Node* tree, string str) 
{
	Node* ptr = tree;
	for (int i = 0; i < str.length(); i++) //���� �� ����� ��������� ��� �����
	{
		if (ptr->next[str[i] - 'a'] != NULL) //��������, ���� �� ��� � ������� ������� �����
		{
			if (i == str.length() - 1) //���� ���������� ��������� �����, ��������, ��� ��� �����
			{
				ptr->next[str[i] - 'a']->isWord = true;
			}
			else ptr = ptr->next[str[i] - 'a']; 
		}
		else //����� �� �������, ���������
		{
			Node* newNode = new Node;
			if (i == str.length() - 1)  //���� ���������� ��������� �����, ��������, ��� ��� �����
			{
				newNode->isWord = true;
			}
			else newNode->isWord = false;
			ptr->next[str[i] - 'a'] = newNode;
			ptr = ptr->next[str[i] - 'a']; 
		}
	}
}

void getLexicon(Node* tree, string prefix) //����� ���� ���� �� �����
{
	for (int i = 0; i < abSize; i++)
	{
		if (tree->next[i] != NULL)
		{
			if (tree->next[i]->isWord)
			{
				cout << prefix << char('a' + i) << endl;
			}
			string str = prefix;
			str.append(1, char('a' + i));
			getLexicon(tree->next[i], str);
		}
	}
}

void SearchConsEnd(Node* tree) 
{
	for (int i = 0; i < abSize; i++) //���� �� ���� ��������
	{
		if (tree->next[i] != NULL) //���� ������� ����������,
		{
			if (tree->next[i]->isWord) //���������, ��� ��� �����, � �� ������������� �����
			{
				if (cons.find(char('a' + i)) != -1) //��������, �������� �� ����� ���������
					consEndNum++;
			}
			SearchConsEnd(tree->next[i]); //� ���� ������ �� ������
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Node* tree = new Node;
	//���������� ����
	add(tree, "hello");
	add(tree, "hi");
	add(tree, "ann");
	add(tree, "anna");
	//����� ���� ���� �� �����
	cout << "�����, ����������� � ���������: " << endl;
	getLexicon(tree, "");
	//����� ����, �������������� �� ���������
	SearchConsEnd(tree);
	cout << "����� ����, �������������� �� ���������: " << consEndNum << endl;
	return 0;
}




