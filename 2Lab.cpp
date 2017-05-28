#include <iostream>
#include <set>
#include <string>

using namespace std;

const int p = 127; // ������ �������
const int Table_Size = 99991; //������ ���� (�� 0 �� 99991 (������ �������)) // 1e9+7 ������ �������

class HashTable {

	struct hash_Node // ���� ���-�������
	{
		hash_Node *Next; // ��������� ���� � ��� �� ������
		int count_name; // ��������� ���������� �����
		string name; // ���
	};

	hash_Node *Table[Table_Size];

	~HashTable() // ������� ������
	{
		for (int i = 0; i < Table_Size; i++)
		{
			if (Table[i] != NULL)
				dell(Table[i]);
		}
	}

	void dell(hash_Node *T) // �������� ���� ������ � ���������� �����
	{
		if (T->Next == NULL)
		{
			delete T;
		}
		else
		{
			hash_Node *p;
			p = T->Next;
			T->Next = NULL;
			dell(p);
			delete T;
		}
	}

public:
	void print() // ������ ���� ����
	{
		for (int i = 0; i < Table_Size; i++) 
		{
			Print_Node_line(Table[i]);
		}
	}

	void Add_name(string name) // ���������� ����� � �������
	{
		int hash_s = bild_hash(name); // ��������� ����
		if (Table[hash_s] == NULL) // ���� ��� ������ ���� �� ������� ���
		{
			Table[hash_s] = bild_Node(name);
		}
		else // ���� ���� �� ��������� ���� �� ����� ���
		{
			hash_Node *TNode = Table[hash_s];
			while ((TNode->Next != NULL) && (TNode->name != name))
				TNode = TNode->Next;
			if (TNode->name != name) // ���� ��� �� ������� ��� 1 ���� � ��� �� �����
			{
				TNode->Next = bild_Node(name);
			}
			else
				TNode->count_name++; // ����� (���� ����) ��������� ���������� ����������
		}
	}

private:

	long long bild_hash(string s) //��������� ����
	{
		long long hash = 0;
		for (int i = s.length() - 1; i >= 0; i--)
		{
			hash *= p;
			hash += s[i];
			hash %= Table_Size;
		}
		return (hash);
	}

	hash_Node *bild_Node(string name) // �������� ������ ����
	{
		hash_Node *NewNode = new hash_Node;
		NewNode->name = name;
		NewNode->count_name = 1;
		NewNode->Next = NULL;
		return (NewNode);
	}

	void Print_Node_line(hash_Node *TNode) // ������ ���� ���� � ���������� �����
	{
		if (TNode != NULL)
		{
			cout << TNode->name << " " << TNode->count_name << endl;
			Print_Node_line(TNode->Next);
		}
	}

};

HashTable Table;

int main()
{
	int n;
	cin >> n; // ����� ���������� ����

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s; // ���� �����
		Table.Add_name(s); // �������� ��������� ��� � �������
	}

	Table.print(); // ����� ���� �������

	

	system("pause");

	return (0);
}