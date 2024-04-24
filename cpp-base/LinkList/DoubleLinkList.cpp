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
/// ��ָ���ڵ���������
/// <para>*�ڵ���Чʱ����*</para>
/// </summary>
/// <param name="prev">ָ���ڵ��ָ�� | nullptr ����������������ڵ�</param>
/// <param name="value">������Ҫ��¼��ֵ</param>
void DLList::insert(node* prev, DLData value) {
	//TODO:	�������ݲ��ҽڵ�
	//�Ǳ�����ڵ���Ч
	_wassert(_CRT_WIDE("����ڵ���Ч"), _CRT_WIDE(__FILE__), (unsigned)(__LINE__));
}
/// <summary>
/// ��ָ���������ڵ�
/// <para>*������Чʱ����*</para>
/// </summary>
/// <param name="position">ָ���ڵ������  /*��ƫ������ʽ*/</param>
/// <param name="value">������Ҫ��¼��ֵ</param>
void DLList::insert(size_t position, DLData value) {
	//Խ����Ч
	_wassert(_CRT_WIDE("ָ��������Ч"), _CRT_WIDE(__FILE__), (unsigned)(__LINE__));
}

/// <summary>
/// ɾ������ͷ�ĵ�һ����Ч�ڵ�
/// <para>*�޽ڵ�ʱ����*</para>
/// </summary>
void DLList::popFront() {
	//��Ч���ж�
	if (pHead->next != pHead)
		_wassert(_CRT_WIDE("�޿�ɾ���ڵ�"), _CRT_WIDE(__FILE__), (unsigned)(__LINE__));

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
	//��Ч���ж�
	if (pHead->prev != pHead)
		_wassert(_CRT_WIDE("�޿�ɾ���ڵ�"), _CRT_WIDE(__FILE__), (unsigned)(__LINE__));

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
/// <summary>
/// ɾ��ָ���ڵ�
/// <para>*�ڵ���Чʱ����*</para>
/// </summary>
/// <param name="delNode">ָ���ڵ��ָ��</param>
void DLList::del(node* delNode) {
	//TODO:	ɾ��ָ���ڵ�
	//�Ǳ�����ڵ���Ч
	_wassert(_CRT_WIDE("����ڵ���Ч"), _CRT_WIDE(__FILE__), (unsigned)(__LINE__));
}
/// <summary>
/// ɾ��ָ���ڵ�
/// <para>*������Чʱ����*</para>
/// </summary>
/// <param name="position">ָ���ڵ������  /*��ƫ������ʽ*/</param>
void DLList::del(size_t position) {
	//Խ����Ч
	_wassert(_CRT_WIDE("ָ��������Ч"), _CRT_WIDE(__FILE__), (unsigned)(__LINE__));
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

/// <summary>
/// ��ȡָ���ڵ�
/// <para>*������Чʱ����*</para>
/// </summary>
/// <param name="position">�ڵ������ /*��ƫ������ʽ*/</param>
/// <returns></returns>
DLList::node* DLList::getPos(size_t position) {
	//TODO:��ȡָ���ڵ�ָ��
	return nullptr;
	_wassert(_CRT_WIDE("ָ��������Ч"), _CRT_WIDE(__FILE__), (unsigned)(__LINE__));
}

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