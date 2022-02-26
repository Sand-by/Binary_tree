#include<iostream>
#include <set>
#include<windows.h>
using namespace std;
struct node {
	int key = 0;
	string name = "����������";
	string description = "��� ��������";
	void info() {
		cout <<"����: " << key <<",\t ���: " << name <<",\t\t ��������: " << description << endl;
	}
	void set_info(int k, string n, string d) {
		key = k;
		name = n;
		description = d;
	}
	node* left, * right;
};
typedef node* pnode;
typedef set<node> TreeStruct;
typedef TreeStruct::iterator NodeIter;

//���������� ���������� ������� ��� ��������� ������ ��������� ����������� � ��������� set
//��� �������� ����������� � set �����������, ������� ���������� ����� ������� �� ���������� ��� insert
inline bool operator<(const node& lhs, const node& rhs) {
	return lhs.key < rhs.key;
}

pnode maketree(node obj[], int from, int n) {
	pnode tree;
	int n1, n2;

	if (n == 0) return NULL;//������� ������ �� ��������

	tree = new node;
	/*tree->key = obj[from].key;
	tree->name = obj[from].name;
	tree->description = obj[from].description;*/

	tree->set_info(obj[from].key, obj[from].name, obj[from].description);//�������� ����� �� ��������� ��� ���������� ������

	n1 = n / 2;
	n2 = n - n1 - 1;

	tree->left = maketree(obj, from+1, n1);
	tree->right = maketree(obj,from+1+n1, n2);

	return tree;
}

void extractKeys(node* root, set<node>& set)
{
	if (root == nullptr) {
		return;
	}
	extractKeys(root->left, set);

	node obj
	{ 
		root->key,
		root->name 
	};
	set.insert(obj);

	extractKeys(root->right, set);
}

void convertToBST(node* root, NodeIter& it, NodeIter& end_it)
{
	if (root == nullptr) {
		return;
	}

	convertToBST(root->left, it,end_it);
	if (it != end_it) {
		root->key = it->key;
		root->name = (*it).name;//��� ���� �� �������� ��������� � ����
		it++;
	}
	convertToBST(root->right, it,end_it);
}

void convertToBST(node* root)
{
	set<node> set_s;

	extractKeys(root, set_s);

	NodeIter it = set_s.begin();
	NodeIter end_it = set_s.end();

	convertToBST(root, it,end_it);
}
void print_lkp(pnode& tree) {
	if (!tree) return;
	print_lkp(tree->left);
	tree->info();
	//cout << tree->name << " key: " << tree->key << endl;
	print_lkp(tree->right);
}
pnode Search(pnode Tree, int what)
{
	if (!Tree) return NULL; // ���� �� ������
	if (what == Tree->key) return Tree; // ���� ������!
	if (what < Tree->key) // ������ � �����������
		return Search(Tree->left, what);
	else return Search(Tree->right, what);
}
void AddToTree(pnode& Tree, node data) // ����������� ����
{
	if (!Tree) {
		Tree = new node; // ������� ����� ����
		Tree->key = data.key;
		Tree->name = data.name;
		Tree->description = data.description;
		Tree->left = NULL;
		Tree->right = NULL;
		return;
	}
	if (data.key < Tree->key) // �������� � ������ ���������
		AddToTree(Tree->left, data);
	else AddToTree(Tree->right, data);
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	node myobjects[] =
	{ 
		{1,"������_1","����_1"},
		{2,"������_2","����_2"},
		{3,"������_3","����_3"},
		{4,"������_4","����_4"},
		{5,"������_5","����_5"},
		{6,"������_6","����_6"},
		{7,"������_7","����_7"},
		{8,"������_8","����_8"},
		{9,"������_9","����_9"}
	};
	pnode tree;
	int n = sizeof(myobjects) / sizeof(myobjects[0]);
	tree = maketree(myobjects, 0, n);
	cout << "\t\t������ ���������!" << endl;

	cout << "______________������� �������� ������ ���_____________________________" << endl;
	print_lkp(tree);

	cout << "______________������������ �������� ������ � ������ ������____________" << endl;
	convertToBST(tree);
	print_lkp(tree);
	cout<<endl;

	cout << "______________���������� � ������_____________________________________" << endl;
	cout << " ������ ������: " << endl;
	cout << tree->name << " key: " << tree->key << endl;

	cout << "______________����� �� ������_________________________________________" << endl;
	cout << " ������� " << Search(tree, 1)->name<<" �� ������: "<<Search(tree,1)<<endl;

	cout << "______________���������� ��������� � ������ ������____________________" << endl;
	AddToTree(tree, node{5,"������_�����","����_�����"});
	AddToTree(tree, {});
	print_lkp(tree);
	cout << endl;
	system ("pause");
}