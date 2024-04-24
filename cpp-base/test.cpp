#define _CRT_SECURE_NO_WARNINGS

#include <cassert>
#include <iostream>
using namespace std;

#pragma region 测试代码

#pragma region 链表
//LinkList

#include "./LinkList/SingleLinkList.h"
/// <summary>
/// 单链表测试
/// </summary>
void LinkListTest_01() {
	SLList* sList = new SLList();

	for (int i = 0; i < 10; i++) {
		sList->pushBack(i + 1);
	}
	sList->print();

	for (int i = 0; i < 10; i++) {
		sList->popBack();
	}
	sList->print();

	for (int i = 0; i < 10; i++) {
		sList->pushFront(i + 1);
	}
	sList->print();

	for (int i = 0; i < 10; i++) {
		sList->popFront();
	}
	sList->print();

	delete(sList);
	sList = nullptr;
}

#include "./LinkList/DoubleLinkList.h"
/// <summary>
/// 双链表测试
/// </summary>
void LinkListTest_02() {
	DLList* dList = new DLList();

	for (int i = 0; i < 10; i++) {
		dList->pushBack(i + 1);
	}
	dList->print();

	for (int i = 0; i < 10; i++) {
		dList->popBack();
	}
	dList->print();

	for (int i = 0; i < 10; i++) {
		dList->pushFront(i + 1);
	}
	dList->print();

	for (int i = 0; i < 10; i++) {
		dList->popFront();
	}
	dList->print();

	delete(dList);
	dList = nullptr;
}


#include "./LinkList/LinkList.h"
void LinkListTest_03() {
	LList* lList = new LList();

	for (int i = 0; i < 10; i++) {
		lList->pushBack(i + 1);
	}
	lList->print();

	for (int i = 0; i < 10; i++) {
		lList->popBack();
	}
	lList->print();

	for (int i = 0; i < 10; i++) {
		lList->pushFront(i + 1);
	}
	lList->print();

	for (int i = 0; i < 10; i++) {
		lList->popFront();
	}
	lList->print();

	delete(lList);
	lList = nullptr;
}

/*
#define _SINGLELINK_
#include "./LinkList/LinkList.h"
void LinkListTest_04() {
	LList* lList = new LList();

	for (int i = 0; i < 10; i++) {
		lList->pushBack(i + 1);
	}
	lList->print();

	for (int i = 0; i < 10; i++) {
		lList->popBack();
	}
	lList->print();

	for (int i = 0; i < 10; i++) {
		lList->pushFront(i + 1);
	}
	lList->print();

	for (int i = 0; i < 10; i++) {
		lList->popFront();
	}
	lList->print();

	delete(lList);
	lList = nullptr;
}
#undef _SINGLELINK_
*/

#pragma endregion

#pragma region 顺序表
//SequenceTable

#include "./SequenceTable/SequenceTable.h"

void SequeneceTableTest_01() {
	//STable st = *new STable();
	
}

#pragma endregion


#pragma endregion

int main() {
	
	#pragma region 链表
	//LinkListTest_01();
	//LinkListTest_02();
	//LinkListTest_03();
	//LinkListTest_04();
	#pragma endregion

	//_wassert(_CRT_WIDE("节点无效"), _CRT_WIDE(__FILE__), (unsigned)(__LINE__));
	//cout << "Hello DataStructur!" << endl;

	return 0;
}