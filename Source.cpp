#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

map<long long, int> map_name;
set<string> dif_name;

const int p = 127; // ������ �������
const long long mod = 1125899839733759; //������ ���� (�� 0 �� 1125899839733759 (������ �������)) // 1e9+7

long long bild_hash(string s)
{
	long long hash = 0;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		hash *= p;
		hash += s[i];
		hash %= mod;
	}
	return (hash);
}

int main()
{
	int n;
	cout << "The number of names = ";
	cin >> n; // ����� ���������� ����

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s; // ���� �����
		int sz = dif_name.size(); // ��������� ����� ��  i��� ����
		dif_name.insert(s); //  ���������� � ��������� ����� ���
		long long t = bild_hash(s); // ��������� ��� �����
		if (sz != dif_name.size()) // ���� ������� �� � ��� ���� ����� ���
		{
			map_name[t] = 1;
		}
		else
			map_name[t]++; // ����� + 1 ���
	}

	for (set<string>::iterator it = dif_name.begin(); it != dif_name.end(); it++) // ������� ���� ��������� ���� � ���������
	{
		long long t = bild_hash(*it); // ���������� ���� �����
		cout << *it << " " << map_name[t] << endl; // ����� ����� � ������� ��� ��� �����������
	}

	system("pause");

	return 0;
}