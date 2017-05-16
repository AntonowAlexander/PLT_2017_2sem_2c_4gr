// �8 �� trie-������ ������� ��� ����� , ������� �������� ��������� ���������
#include <iostream>
#include <string>

using namespace std;
const int MAXL = 100;

struct Node
{
	int info;
	Node *next[26]; //26 �������� � ���.��������
};

void add(Node *t, string s, int k) // ���������� ����� � ������
{
	if (s.length() > k)
	{
		int ind = s[k] - 'a';
		if (t->next[ind] == NULL)//���� ������� ���
		{
			Node *nt;// ������� �����
			nt = new Node;
			nt->info = 0;
			for (int i = 0; i < 26; i++)
				nt->next[i] = NULL;
			t->next[ind] = nt;
		}
		add(t->next[ind], s, k + 1);
	}
	else
		t->info += 1;
}

void dell(Node *t) // �������� ����� ���������
{
	for (int i = 0; i < 26; i++) // �������� ���� ����������� �� ������ �������
	{
		if (t->next[i] != NULL) // �������� ������� ��������� �� ������� �����������
		{
			dell(t->next[i]); // ���������� ��������
			t->next[i] = NULL;
		}
	}
	delete t;
}

bool faind(Node *t, string s, int k) // �������� ������� ��������� ������� � ������� t
{
	if (s.length() == k)
		return (true);
	else
		if (t->next[s[k] - 'a'] == NULL)
			return (false);
		else
			return (faind(t->next[s[k] - 'a'], s, k + 1));
}

void go(Node *t, string s) // ����� ����� ������ � ����� ���� ���������� ��������� S
{
	if (faind(t, s, 0)) // �������� ������� ��������� ������� � ������� T
	{
		Node *v;
		v = t;
		for (int i = 0; i < s.length(); i++) // ������ �������, �� ������� ������������� ������ ��������� ������� � T
		{
			v = v->next[s[i] - 'a'];
		}
		Node *p;
		p = t;
		for (int i = 0; i < s.length() - 1; i++) // ���������� ������� � v
		{
			p = p->next[s[i] - 'a'];
		}
		p->next[s[s.length() - 1] - 'a'] = NULL; // ���������� v �� ������ � ������ ��� ��������� ������� v
		dell(v);
	}
	for (int i = 0; i < 26; i++) // ����� ����� ���� � ���������� s ������
	{
		if (t->next[i] != NULL)
			go(t->next[i], s);
	}
}

void rebild(Node *t, Node *pr, int c) // ����������� ������ (�������� ������ ����� �������������� ��-�� �������� ����)
{
	for (int i = 0; i < 26; i++) // ����������� ��� ����������
	{
		if (t->next[i] != NULL)
			rebild(t->next[i], t, i);
	}
	if (pr != NULL)
		if (t->info == 0) // ����������� ������� ������� ���� ����������
		{
			bool f = true;
			for (int i = 0; i < 26; i++)
			{
				f &= (t->next[i] == NULL);
			}
			if (f)
			{
				pr->next[c] = NULL;
				delete t;
			}
		}
}

void print(Node *t, string s) // ����� �� ����� ����� ���� ��������������
{
	for (int i = 0; i < t->info; i++)
		cout << s << endl;
	for (int i = 0; i < 26; i++)
	{
		if (t->next[i] != NULL)
			print(t->next[i], s + (char)('a' + i));
	}
}

int main()
{
	int n;
	Node *tree;
	tree = new Node;
	tree->info = 0;
	for (int i = 0; i < 26; i++)
		tree->next[i] = NULL;
	cout << "Number of words :" << endl;
	cin >> n; // ���������� ����������� ����
	cout << "Enter the string :" << endl;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		add(tree, s, 0); // ���������� ���� � ������
	}

	string p;
	cout << "Enter the substring:" << endl;
	cin >> p; // �� ������ ���������
	go(tree, p); // �������� ���� ���� ���������� ��������� p
	rebild(tree, NULL, 0); //����������� ������ ����� ���� �������������� 

	cout << endl;
	cout << "New tree:" << endl;
	print(tree, "");

	system("pause");
	return 0;
}