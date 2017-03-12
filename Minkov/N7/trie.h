/* ����� "trie-������":

*/

#ifndef __TRIE_H__
#define __TRIE_H__

const int aLength = 26;
const char a = 'a';

struct node { //������ ��-� ����� ������ ���� ����� � ���-�� ������� � �����; ������ � ���� ���������� ���� �����
	bool end; //������ �� �������� - ��������
	bool parent; //����� ��� ������ � missionX, ��� ������ � ����������
	char key;
	int length;
	int vowQuant; //���-�� �������
	node* child[aLength];
};

class Trie {

private:
	node* Head;

public:
	//���������������:
	Trie();
	void init(node*);
	int countCons(node*);
	node* getHead() { return Head; };

	//��������:
	void push(char*);
	int missionX(int, node*);

	void print(char* indent, bool last, node* root);
};
#endif // !__TRIE_H__
