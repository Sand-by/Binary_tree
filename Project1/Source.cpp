#include<iostream>
#include<Windows.h>
#include<string>
#include<list>
struct MyStrcut {
	int key;
	string name;
	string descritption;
	char target;
};
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	list<MyStrcut> mylist = 
	{ 
		{1, "name1", "description1", 'd'}, 
		{2, "name2", "description2", 'd'}, 
		{3, "name3", "description3", 'w'}, 
		{4, "name4", "description4", 'd'}, 
		{5, "name5", "description5", 'd'}, 
		{6, "name6", "description6", 'w'}, 
		{7, "name7", "description7", 'w'}, 
		{8, "name8", "description8", 'w'} 
	};
	for (MyStrcut n : mylist)
		cout << "key: " << n.key 
		<< " name: " << n.name 
		<< " descr: " << n.descritption 
		<< " status: " << n.target << endl;

	system("pause");
}