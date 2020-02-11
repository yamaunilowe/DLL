//My name is Yamauni Lowe and this is my own work plus the work that was provided 
#include <iostream>
#include <fstream>
#include <string>
#include "DLinkedList.h"

using namespace std;

//string cleanUp(string str);

int main() {

	DLinkedList<string> lst1;
	DLinkedList<string> lst2;

	ifstream fin("Text1.in");

	string str;

	while (fin >> str) {
		//str = cleanUp(str);
		lst1.insertOrderUnique(str);
	}
	fin.close();

	fin.open("Text2.in");
	while (fin >> str) {
		//str = cleanUp(str);
		lst2.insertOrderUnique(str);
	}

	cout << "List 1: " << lst1 << endl;
	cout << "List 2: " << lst2 << endl;


	//DLinkedList<string> combined = lst1.merge(lst2);

	cout << "\nAFTER MERGE" << endl;
	cout << "List 1: " << lst1 << endl;
	cout << "List 2: " << lst2 << endl;
	//cout << "\nCombined: " << combined << endl;


	return 0;
}

/**
* ASSIGNED
* @param str
* @return str in all lower case with LEADING and TRAILING non-alpha
* chars removed
*/
//string cleanUp(string str) {
//	return str;
//}