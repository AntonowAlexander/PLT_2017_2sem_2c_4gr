// N7: � trie-������ ���������� ���-�� ����, ������� �������� ����������� ���-�� ��������� (��� ������ �-��� missionX � trie.h)

#include "stdafx.h"
#include "iostream"
#include "trie.h"
#include "string"

using namespace std;

void main()
{
	setlocale(0, "");
	Trie Tree;
	Tree.push("cat"); // 2 ����
	Tree.push("cata"); // 2 ����
	Tree.push("cattingham"); // 7 ����
	Tree.push("catoraptor"); // 6 ����
	Tree.push("car"); // 2 ����
	Tree.push("carpet"); // 4 ����
	Tree.push("dog"); // 2 ����
	Tree.push("dog");
	Tree.print("", true, Tree.getHead());
	cout << "������� ��������� ������ ���� � �����?\n";
	int cq; cin >> cq;
	//cout << Tree.countCons(Tree.getHead()->child[2]->child[0]->child[17]);
	//cout << Tree.getHead()->child[2]->key;
	cout << "� ������ ������� " << Tree.missionX(cq,Tree.getHead()) << " c��� � �������� ���-��� ���������\n";
	system("pause");
}

