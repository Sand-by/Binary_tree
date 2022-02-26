#include<iostream>
#include<list>
#include<windows.h>
using namespace std;
struct mystruct {
	int key;
	string name;
	string description;
};
struct node {
	int key;
	string name;
	string description;
	node* left, * right;
};
typedef node* pnode;
typedef list<mystruct> mylist;

pnode maketree(mylist &myls,mylist::iterator iter,int n)
{
	pnode tree;
	int n1, n2;
	if (n == 0) return NULL;//граница выхода из рекурсии
	tree = new node;
	tree->key = iter->key;
	tree->name = iter->name;
	n1 = n / 2;
	n2 = n - n1 - 1;

	tree->left = maketree(myls, ++iter, n1);

	advance(iter, n1);
	
	tree->right = maketree(myls, iter, n2);
	return tree;
}

void printklp(pnode &tree) {
	if (!tree) return;
	printklp(tree->left);
	cout << tree->name<<" key: "<<tree->key << endl;
	printklp(tree->right);
}
//void AddToTree(pnode& Tree, int data) // добавляемый ключ
//{
//	if (!Tree) {
//		Tree = new node; // создать новый узел
//		Tree->key = data;
//		Tree->left = NULL;
//		Tree->right = NULL;
//		return;
//	}
//	if (data < Tree->key) // добавить в нужное поддерево
//		AddToTree(Tree->left, data);
//	else AddToTree(Tree->right, data);
//}

int countNodes(struct node* root)
{
	if (root == NULL)
		return 0;
	return countNodes(root->left) + countNodes(root->right) + 1;
}
void storeInorder(struct node* node, int inorder[], int* index_ptr)
{
	if (node == NULL)
		return;

	storeInorder(node->left, inorder, index_ptr);

	inorder[*index_ptr] = node->key;
	(*index_ptr)++; 

	storeInorder(node->right, inorder, index_ptr);
}
int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
void arrayToBST(int* arr, struct node* root, int* index_ptr)
{
	if (root == NULL)
		return;

	arrayToBST(arr, root->left, index_ptr);

	root->key = arr[*index_ptr];
	(*index_ptr)++;

	arrayToBST(arr, root->right, index_ptr);
}
void binaryTreeToBST(struct node* root)
{
	if (root == NULL)
		return;

	int n = countNodes(root);

	int* arr = new int[n];
	int i = 0;
	storeInorder(root, arr, &i);

	qsort(arr, n, sizeof(arr[0]), compare);

	i = 0;
	arrayToBST(arr, root, &i);

	delete[] arr;
}
void printInorder(struct node* node)
{
	if (node == NULL)
		return;

	printInorder(node->left);
	cout << " " << node->name<<" " << node->key << endl;
	printInorder(node->right);
}


pnode Search(pnode Tree, int what)
{
	if (!Tree) return NULL; // ключ не найден
	if (what == Tree->key) return Tree; // ключ найден!
	if (what < Tree->key) // искать в поддеревьях
		return Search(Tree->left, what);
	else return Search(Tree->right, what);
}
int main() {
	SetConsoleOutputCP(1251);
	list<mystruct> list = { 
		{1,"name 1","asdasd"},
		{2,"name 2","asdasd"},
		{3,"name 3","asdasd"},
		{4,"name 4","asdasd"},
		{5,"name 5","asdasd"},
		{6,"name 6","asdasd"},
		{7,"name 7","asdasd"},
		{8,"name 8","asdasd"},
		{9,"name 9","asdasd"}
	};
	for (auto n : list)
		cout <<"key: " << n.key 
		<<" name: " << n.name 
		<<" descr: " << n.description << endl;
	cout << "____________________________" << endl;
	pnode tree;
	tree = maketree(list, list.begin(), list.size());
	cout << "дерево построено!" << endl;

	cout << "______________ЛКП_____________" << endl;
	printklp(tree);
	binaryTreeToBST(tree);
	////Конвертируем бинарное дерево в бинарное дерево поиска
	//cout << "Бинарное дерево поиска:" << endl;
	////AddToTree(tree,5);
	//cout << "________Вывод ЛКП Бинарного дерева поиска_________\n";
	printInorder(tree);

	//auto n = tree;
	////cout << tree->right;
	//advance(n, 2);
	//cout << " Элемент " << Search(tree, n->key)->name <<" по адресу = "<<n<<endl;
	cout << " Элемент " << Search(tree, 5)->name;
	system("pause");
}