// ����� ��������� ����. ������������ ����� �������������� �� ��� � ����� �����, ������������� � ������ �� ����� ���� ���.

#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "string"
#include "Hash.h"

using namespace std;

static const char* filename = "Input.txt";

void main()
{
	setlocale(0, "");
	ifstream fin;
	fin.open(filename);
	cout << "��������� ����� �� Input.txt..\n";
	string strfin;
	int q = 0;

// ���������� ������� ���-�������, ��� ����. ����. ������������� = 90%
	while (getline(fin, strfin)) { 
		q++;
		HASHTABLE_SIZE = round(q / 0.90);
	}
	cout << "� ������ " << q << " ����(�). ����������� ������ ���-������� - " << HASHTABLE_SIZE << endl;
	fin.close();

// ���������� ���-������� (����������� ��� ������ ����������� �������)
	fin.open(filename);
	HashEl* HashTable = new HashEl[HASHTABLE_SIZE];
	unsigned int i = 0;

	while (getline(fin, strfin)) {
		char* word = new char[strfin.size() + 1];
		copy(strfin.begin(), strfin.end(), word);
		word[strfin.size()] = '\0';
		unsigned int index = Hash(word);
		cout << endl;
		HashTable[index].Add(word);
	}

	fin.close();

// ����������� ���-�� ������������� ���� (���������� twoormore) � ����� ���-�������
	int twoormore = 0;
	cout << "� ������ ������� ������������� ����. �������:\n";
	for (i = 0; i < HASHTABLE_SIZE; i++) {
		cout << "������: " << i << ", ����������: ";
		HashTable[i].Show(); 
		cout << endl; 
		twoormore += HashTable[i].TwoOrMore();
	}

// ������������ �������[twoormore] ���� 
	char** SentenceX = new char*[twoormore];
	unsigned int j = 0;
	for (i = 0; i < HASHTABLE_SIZE; i++) {
		Node* tmp = HashTable[i].getHead();
		while (tmp) {
			if (tmp->quantity >= 2) {
				*(SentenceX + j) = tmp->key;
				j++;
			}
			tmp = tmp->next;
		}
	}

// ����� ��������������
	cout << "�������������� ������������� ����:\n";
	MissionX(SentenceX, twoormore);
	system("pause");
}

