#define _CRT_SECURE_NO_WARNINGS

#include <cassert>
#include <iostream>
using namespace std;

#pragma region ���Դ���

#pragma region ����
//LinkList

#include "./LinkList/SingleLinkList.h"
/// <summary>
/// ���������
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
/// ˫�������
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

void LinkListTest_05() {
	//TODO:�����½ӿ�,����ɾ��

	LList* lList = new LList();

	for (int i = 0; i < 10; i++) {
		//�����±�
		lList->pushBack(i);
	}
	lList->print();

	//�۲쵽��״̬ӦΪ�����������ָ���±�λ��
	lList->insert((size_t)0, 2333);
	lList->insert((size_t)7, 2025);
	lList->print();

	//�۲쵽��״̬ӦΪɾ���ϴβ��������
	lList->del((size_t)7);
	lList->del((size_t)0);
	lList->print();

	//�۲쵽��״̬ӦΪɾ�����������ݵ�ָ���±꣬������Ĳ��Խ��������ͬ
	cout << lList->getPos((size_t)5)->data << endl;
	lList->del(lList->getPos(5));
	lList->print();
	lList->insert(lList->getPos(5), 1203);
	lList->print();

	lList->~DoubleLinkList();
	lList = nullptr;
}

#pragma endregion

#pragma region ˳���
//SequenceTable

#include "./SequenceTable/SequenceTable.h"

void SequeneceTableTest_01() {
	//STable st = *new STable();
	
}

#pragma endregion


#pragma endregion

int main() {
	
	#pragma region ����
	//LinkListTest_01();
	//LinkListTest_02();
	//LinkListTest_03();
	//LinkListTest_04();
	//LinkListTest_05();
	#pragma endregion


	//cout << "Hello DataStructur!" << endl;

	return 0;
}