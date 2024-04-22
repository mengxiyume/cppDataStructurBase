#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#include "SingleLinkList.h"

int main() {
	SLList* sList = new SLList();

	sList->pushBack(1);
	cout << sList->getBack()->data << endl;

	delete(sList);
	sList = nullptr;

	cout << "Hello DataStructur!" << endl;
	return 0;
}