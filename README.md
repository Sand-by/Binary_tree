# Binary_tree
#include<iostream>
#include <set>
#include<windows.h>
using namespace std;
struct node {
	int key = 0;
	string name = "Безымянный";
	string description = "Без описания";
	void info() {
		cout <<"Ключ: " << key <<",\t имя: " << name <<",\t\t описание: " << description << endl;
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

//Используем встроенную функцию для сравнения ключей элементов добавляемых в множество set
//Все элементы добавляемые в set сортируются, поэтому необходимо знать порядок их следования при insert
inline bool operator<(const node& lhs, const node& rhs) {
	return lhs.key < rhs.key;
}

pnode maketree(node obj[], int from, int n) {
	pnode tree;
	int n1, n2;

	if (n == 0) return NULL;//граница выхода из рекурсии

	tree = new node;
	/*tree->key = obj[from].key;
	tree->name = obj[from].name;
	tree->description = obj[from].description;*/

	tree->set_info(obj[from].key, obj[from].name, obj[from].description);//Вызываем метод из структуры для заполнения данных

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
		root->name = (*it).name;//ещё один из варианта обращения к полю
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
	if (!Tree) return NULL; // ключ не найден
	if (what == Tree->key) return Tree; // ключ найден!
	if (what < Tree->key) // искать в поддеревьях
		return Search(Tree->left, what);
	else return Search(Tree->right, what);
}
void AddToTree(pnode& Tree, node data) // добавляемый ключ
{
	if (!Tree) {
		Tree = new node; // создать новый узел
		Tree->key = data.key;
		Tree->name = data.name;
		Tree->description = data.description;
		Tree->left = NULL;
		Tree->right = NULL;
		return;
	}
	if (data.key < Tree->key) // добавить в нужное поддерево
		AddToTree(Tree->left, data);
	else AddToTree(Tree->right, data);
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	node myobjects[] =
	{ 
		{1,"данные_1","опис_1"},
		{2,"данные_2","опис_2"},
		{3,"данные_3","опис_3"},
		{4,"данные_4","опис_4"},
		{5,"данные_5","опис_5"},
		{6,"данные_6","опис_6"},
		{7,"данные_7","опис_7"},
		{8,"данные_8","опис_8"},
		{9,"данные_9","опис_9"}
	};
	pnode tree;
	int n = sizeof(myobjects) / sizeof(myobjects[0]);
	tree = maketree(myobjects, 0, n);
	cout << "\t\tДерево построено!" << endl;

	cout << "______________Обходим бинарное дерево ЛКП_____________________________" << endl;
	print_lkp(tree);

	cout << "______________Конвертируем бинарное дерево в дерево поиска____________" << endl;
	convertToBST(tree);
	print_lkp(tree);
	cout<<endl;

	cout << "______________Информация о дереве_____________________________________" << endl;
	cout << " Корень дерева: " << endl;
	cout << tree->name << " key: " << tree->key << endl;

	cout << "______________Поиск по дереву_________________________________________" << endl;
	cout << " Элемент " << Search(tree, 1)->name<<" по адресу: "<<Search(tree,1)<<endl;

	cout << "______________Добавление элементов в дерево поиска____________________" << endl;
	AddToTree(tree, node{5,"данные_новые","опис_новое"});
	AddToTree(tree, {});
	print_lkp(tree);
	cout << endl;
	system ("pause");
}
