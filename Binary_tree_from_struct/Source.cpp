#include<iostream>
#include <set>
#include<windows.h>
using namespace std;
struct node {
	int key = 0;
	string name = "Áåçûìÿííûé";
	string description = "Áåç îïèñàíèÿ";
	void info() {
		cout <<"Êëþ÷: " << key <<",\t èìÿ: " << name <<",\t\t îïèñàíèå: " << description << endl;
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

//Èñïîëüçóåì âñòðîåííóþ ôóíêöèþ äëÿ ñðàâíåíèÿ êëþ÷åé ýëåìåíòîâ äîáàâëÿåìûõ â ìíîæåñòâî set
//Âñå ýëåìåíòû äîáàâëÿåìûå â set ñîðòèðóþòñÿ, ïîýòîìó íåîáõîäèìî çíàòü ïîðÿäîê èõ ñëåäîâàíèÿ ïðè insert
inline bool operator<(const node& lhs, const node& rhs) {
	return lhs.key < rhs.key;
}


pnode maketree(node obj[], int from, int n) {
	pnode tree;
	int n1, n2;

	if (n == 0) return NULL;//ãðàíèöà âûõîäà èç ðåêóðñèè

	tree = new node;
	/*tree->key = obj[from].key;
	tree->name = obj[from].name;
	tree->description = obj[from].description;*/

	tree->set_info(obj[from].key, obj[from].name, obj[from].description);//Âûçûâàåì ìåòîä èç ñòðóêòóðû äëÿ çàïîëíåíèÿ äàííûõ

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
		root->name = (*it).name;//åù¸ îäèí èç âàðèàíòà îáðàùåíèÿ ê ïîëþ
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
	if (!Tree) return NULL; // êëþ÷ íå íàéäåí
	if (what == Tree->key) return Tree; // êëþ÷ íàéäåí!
	if (what < Tree->key) // èñêàòü â ïîääåðåâüÿõ
		return Search(Tree->left, what);
	else return Search(Tree->right, what);
}
void AddToTree(pnode& Tree, node data) // äîáàâëÿåìûé êëþ÷
{
	if (!Tree) {
		Tree = new node; // ñîçäàòü íîâûé óçåë
		Tree->key = data.key;
		Tree->name = data.name;
		Tree->description = data.description;
		Tree->left = NULL;
		Tree->right = NULL;
		return;
	}
	if (data.key < Tree->key) // äîáàâèòü â íóæíîå ïîääåðåâî
		AddToTree(Tree->left, data);
	else AddToTree(Tree->right, data);
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	node myobjects[] =
	{ 
		{1,"äàííûå_1","îïèñ_1"},
		{2,"äàííûå_2","îïèñ_2"},
		{3,"äàííûå_3","îïèñ_3"},
		{4,"äàííûå_4","îïèñ_4"},
		{5,"äàííûå_5","îïèñ_5"},
		{6,"äàííûå_6","îïèñ_6"},
		{7,"äàííûå_7","îïèñ_7"},
		{8,"äàííûå_8","îïèñ_8"},
		{9,"äàííûå_9","îïèñ_9"}
	};
	pnode tree;
	int n = sizeof(myobjects) / sizeof(myobjects[0]);
	tree = maketree(myobjects, 0, n);
	cout << "\t\tÄåðåâî ïîñòðîåíî!" << endl;

	cout << "______________Îáõîäèì áèíàðíîå äåðåâî ËÊÏ_____________________________" << endl;
	print_lkp(tree);

	cout << "______________Êîíâåðòèðóåì áèíàðíîå äåðåâî â äåðåâî ïîèñêà____________" << endl;
	convertToBST(tree);
	print_lkp(tree);
	cout<<endl;

	cout << "______________Èíôîðìàöèÿ î äåðåâå_____________________________________" << endl;
	cout << " Êîðåíü äåðåâà: " << endl;
	cout << tree->name << " key: " << tree->key << endl;

	cout << "______________Ïîèñê ïî äåðåâó_________________________________________" << endl;
	cout << " Ýëåìåíò " << Search(tree, 1)->name<<" ïî àäðåñó: "<<Search(tree,1)<<endl;

	cout << "______________Äîáàâëåíèå ýëåìåíòîâ â äåðåâî ïîèñêà____________________" << endl;
	AddToTree(tree, node{5,"äàííûå_íîâûå","îïèñ_íîâîå"});
	AddToTree(tree, {});
	print_lkp(tree);
	cout << endl;
	system ("pause");
}
