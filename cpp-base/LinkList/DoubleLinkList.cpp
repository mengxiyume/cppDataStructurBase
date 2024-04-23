#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;

#include "DoubleLinkList.h"

#pragma region private

DLList::node* pHead;	//����ͷ

/// <summary>
/// ����һ������ڵ�
/// <para>*����ʧ�ܱ���*</para>
/// </summary>
/// <returns>������Ľڵ�</returns>
DLList::node* buyOneNode() {
	DLList::node* temp = (DLList::node*)malloc(sizeof(DLList::node));
	assert(temp);
	return temp;
}

#pragma endregion

#pragma region public

#pragma region �����������

DLList::DoubleLinkList() {
	//ͷ�ڵ�����
	pHead = buyOneNode();

	//ͷ�ڵ�ѭ�����ӳ�ʼ��
	pHead->next = pHead;
	pHead->prev = pHead;

	this->front = nullptr;
	this->back = nullptr;
}

DLList::~DoubleLinkList() {
	//�Ͽ�ѭ������
	pHead->prev->next = nullptr;
	pHead->prev = nullptr;

	//�����ͷ�
	node* curNode = pHead;

	while (curNode != nullptr) {
		//�����ͷ�
		node* prevNode = curNode;
		curNode = curNode->next;
		free(prevNode);
		prevNode = nullptr;
	}

	//ָ�����
	pHead = nullptr;
	this->front = nullptr;
	this->back = nullptr;
}

#pragma endregion

#pragma region �����������

/// <summary>
/// ������ͷ���ڵ���в���
/// </summary>
/// <param name="value">������Ҫ��¼��ֵ</param>
void DLList::pushFront(DLData value) {
	//������ע��
	node* newNode = buyOneNode();
	newNode->data = value;

	//�Ӳ�����
	newNode->next = pHead->next;
	newNode->prev = pHead;
	pHead->next->prev = newNode;
	pHead->next = newNode;

	//����ֵ����
	this->front = pHead->next;
	this->back = pHead->prev;
}
/// <summary>
/// ������β���ڵ���в���
/// </summary>
/// <param name="value">������Ҫ��¼��ֵ</param>
void DLList::pushBack(DLData value) {
	//������ע��
	node* newNode = buyOneNode();
	newNode->data = value;

	//�Ӳ�����
	newNode->next = pHead;
	newNode->prev = pHead->prev;
	pHead->prev->next = newNode;
	pHead->prev = newNode;

	//����ֵ����
	this->front = pHead->next;
	this->back = pHead->prev;
}

/// <summary>
/// ɾ������ͷ�ĵ�һ����Ч�ڵ�
/// <para>*�޽ڵ�ʱ����*</para>
/// </summary>
void DLList::popFront() {
	assert(pHead->next != pHead);

	node* delNode = pHead->next;
	//�ڵ��޳�
	pHead->next->next->prev = pHead;
	pHead->next = delNode->next;

	//����ռ�ÿռ�
	free(delNode);

	//����ֵ����
	this->front = pHead->next != pHead ? pHead->next : nullptr;
	this->back = pHead->next != pHead ? pHead->prev : nullptr;
}
/// <summary>
/// ɾ����������һ����Ч�ڵ�
/// <para>*�޽ڵ�ʱ����*</para>
/// </summary>
void DLList::popBack() {
	assert(pHead->next != pHead);

	node* delNode = pHead->prev;
	//�ڵ��޳�
	pHead->prev->prev->next = pHead;
	pHead->prev = delNode->prev;

	//����ռ�ÿռ�
	free(delNode);

	//����ֵ����
	this->front = pHead->next != pHead ? pHead->next : nullptr;
	this->back = pHead->next != pHead ? pHead->prev : nullptr;
}

///// <summary>
///// ��ȡ��ǰ����ĵ�һ����Ч�ڵ�
///// </summary>
///// <returns>�ڵ�ָ�� | ����Ч�ڵ�ʱ����nullptr</returns>
//DLList::node* DLList::getFront() {
//	return pHead->next;
//}
///// <summary>
///// ��ȡ��ǰ��������һ����Ч�ڵ�
///// </summary>
///// <returns>�ڵ�ָ�� | ����Ч�ڵ�ʱ����nullptr</returns>
//DLList::node* DLList::getBack() {
//	return pHead->prev;
//}

//TODO:	�������ݲ��ҽڵ�

//TODO:	ɾ��ָ���ڵ�

/// <summary>
/// �������е����ݴ�ӡ
/// </summary>
void DLList::print() {

	if (pHead->next == pHead) {
		//����������ʱ��ӡ
		cout << "null" << endl;
		return;
	}

	//����������ʱ��ӡ
	cout << "null <=";

	node* curNode = pHead->next;
	while (curNode != pHead) {
		cout << "> " << curNode->data << " <=";
		curNode = curNode->next;
	}

	cout << "> null" << endl;
}

#pragma endregion

#pragma endregion