#include<iostream>
using namespace std;
void input(int **mas, int n)
{
	cout << "\n ������� ������� ���������\n ";
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		{
			cin >> mas[i][j];
			if (i ==j &&mas[i][j] != 0)
				do
				{
					cout << "\n ������� �� ������� ��������� ������ ���� �������, ������� ������� ������\n ";
					cin >> mas[i][j];
				} while (mas[i][j] != 0);
			if (abs(mas[i][j]>100))
				do
				 {
					cout << "\n ������� �� ������> 100,������� ������� ������\n ";
					cin >> mas[i][j];
				} while (abs(mas[i][j]>100));
	}
}
 int min(int x, int y)
	{
		if (x < y) return x;
		return y;
	}
void search(int **&mas,int n)
 {
	 for (int k = 0; k < n; k++)
	 {
		 for (int i = 0; i <n; i++)
			 for (int j = 0; j < n; j++)
				 mas[i][j] = min(mas[i][j], mas[i][k] + mas[k][j]);
	 }
 }
 void Print(int **mas,int n)
 {
	 cout << "\n ������� ���������� ����� ����� ������ ������:\n";
	 for (int i = 0; i < n; i++)
	 {
		 for (int j = 0; j < n; j++)
			 cout << mas[i][j]<<" ";
		 cout << endl;
	 }
 }
int main()
{
	setlocale(LC_ALL, "Russian");
	int n, **mas;
	do 
	{
		cout << "\n ������� ���������� �����<=100\n";
		cin >> n;
	}
	while (n>100);
	mas = new int*[n];
	for (int i = 0; i < n; i++)
		mas[i] = new int[n];
	input(mas, n);
	search(mas, n);
	Print(mas, n);
	system("pause");
	return 0;

}