#define _CRT_SECURE_NO_WARNINGS

//��һ��д�࣬��Щ���裬������2024/04/23 - 03:00

#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;

#include "SingleLinkList.h"

#pragma region private

SLList::node* pHead;	//����ͷ
SLList::node* pFront;	//�����һ����Ч�ڵ�
SLList::node* pBack;	//�������һ����Ч�ڵ�

/// <summary>
/// ����һ������ڵ�
/// <para>*����ʧ�ܱ���*</para>
/// </summary>
/// <returns>������Ľڵ�</returns>
SLList::node* buyOneNode() {
	SLList::node* temp = (SLList::node*)malloc(sizeof(SLList::node));
	assert(temp);
	return temp;
}

#pragma endregion

#pragma region public

#pragma region �����������

SLList::SingleLinkList() {
	//ͷ�ڵ�ռ�����
	pHead = buyOneNode();
	pHead->next = nullptr;

	//��β�ڵ��ʼ��
	pFront = nullptr;
	pBack = nullptr;

	this->front = nullptr;
	this->back = nullptr;
}

SLList::~SingleLinkList() {
	node* curNode = pHead;

	while (curNode != nullptr) {
		//�����ͷ�
		node* prevNode = curNode;
		curNode = curNode->next;
		free(prevNode);
		prevNode = nullptr;
	}

	//���м�¼ָ�����
	pHead = pFront = pBack = nullptr;
	this->front = nullptr;
	this->back = nullptr;
}

#pragma endregion

#pragma region �����������

/// <summary>
/// ������ͷ���ڵ���в���
/// </summary>
/// <param name="value">������Ҫ��¼��ֵ</param>
void SLList::pushFront(SLData value) {
	//������ע��
	node* newNode = buyOneNode();
	newNode->data = value;

	//�Ӳ�����
	newNode->next = pFront;
	pHead->next = newNode;

	//������¼ָ��Ĵ���
	this->front = pFront = pHead->next;							//�׽ڵ�ĸ���
	this->back = pBack = pBack != nullptr ? pBack : newNode;	//β�ڵ�ĸ���
}
/// <summary>
/// ������β���ڵ���в���
/// </summary>
/// <param name="value">������Ҫ��¼��ֵ</param>
void SLList::pushBack(SLData value) {
	//������ע��
	node* newNode = buyOneNode();
	newNode->data = value;

	//�Ӳ�����
	node* prevNode = pBack != nullptr ? pBack : pHead;
	newNode->next = nullptr;
	prevNode->next = newNode;

	//������¼ָ��Ĵ���
	this->front = pFront = pFront != nullptr ? pFront : newNode;	//�׽ڵ�ĸ���
	this->back = pBack = newNode;									//β�ڵ�ĸ���
}
/// <summary>
/// ��ָ���ڵ���������
/// <para>*�ڵ���Чʱ����*</para>
/// </summary>
/// <param name="prev">ָ���ڵ��ָ�� | nullptr ����������������ڵ�</param>
/// <param name="value">������Ҫ��¼��ֵ</param>
void SLList::insert(node* prev, SLData value) {
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
void SLList::insert(size_t position, SLData value) {
	//Խ����Ч
	_wassert(_CRT_WIDE("ָ��������Ч"), _CRT_WIDE(__FILE__), (unsigned)(__LINE__));
}


/// <summary>
/// ɾ������ͷ�ĵ�һ����Ч�ڵ�
/// <para>*�޽ڵ�ʱ����*</para>
/// </summary>
void SLList::popFront() {
	assert(pFront);

	//�׽ڵ�Ͽ�����
	pHead->next = pFront->next;

	//����ռ�õĿռ�
	free(pFront);

	//������¼ָ��Ĵ���
	this->front = pFront = pHead->next;							//�׽ڵ�ĸ���
	this->back = pBack = pFront != nullptr ? pBack : nullptr;	//β�ڵ�ĸ���
}
/// <summary>
/// ɾ����������һ����Ч�ڵ�
/// <para>*�޽ڵ�ʱ����*</para>
/// </summary>
void SLList::popBack() {
	assert(pBack);

	//�ҵ�β�ڵ��ǰһ���ڵ�
	node* last = pHead;
	while (last->next != pBack) {
		last = last->next;
	}

	//ɾ��β�ڵ�
	free(pBack);
	last->next = nullptr;

	//������¼ָ��Ĵ���
	this->front = pFront = pHead->next;							//�׽ڵ�ĸ���
	this->back = pBack = last;									//β�ڵ�ĸ���
}
/// <summary>
/// ɾ��ָ���ڵ�
/// <para>*�ڵ���Чʱ����*</para>
/// </summary>
/// <param name="delNode">ָ���ڵ��ָ��</param>
/// <summary>
/// ɾ��ָ���ڵ�
/// <para>*�ڵ���Чʱ����*</para>
/// </summary>
/// <param name="delNode">ָ���ڵ��ָ��</param>
void SLList::del(node* delNode) {
	//TODO:	ɾ��ָ���ڵ�
	//�Ǳ�����ڵ���Ч
	_wassert(_CRT_WIDE("����ڵ���Ч"), _CRT_WIDE(__FILE__), (unsigned)(__LINE__));
}
/// <summary>
/// ɾ��ָ���ڵ�
/// <para>*������Чʱ����*</para>
/// </summary>
/// <param name="position">ָ���ڵ������  /*��ƫ������ʽ*/</param>
void SLList::del(size_t position) {
	//Խ����Ч
	_wassert(_CRT_WIDE("ָ��������Ч"), _CRT_WIDE(__FILE__), (unsigned)(__LINE__));
}

///// <summary>
///// ��ȡ��ǰ����ĵ�һ����Ч�ڵ�
///// </summary>
///// <returns>�ڵ�ָ�� | ����Ч�ڵ�ʱ����nullptr</returns>
//SLList::node* SLList::getFront() {
//	return pFront;
//}
///// <summary>
///// ��ȡ��ǰ��������һ����Ч�ڵ�
///// </summary>
///// <returns>�ڵ�ָ�� | ����Ч�ڵ�ʱ����nullptr</returns>
//SLList::node* SLList::getBack() {
//	return pBack;
//}

/// <summary>
/// ��ȡָ���ڵ�
/// <para>*������Чʱ����*</para>
/// </summary>
/// <param name="position">�ڵ������ /*��ƫ������ʽ*/</param>
/// <returns></returns>
SLList::node* SLList::getPos(size_t position) {
	//TODO:��ȡָ���ڵ�ָ��
	return nullptr;
	_wassert(_CRT_WIDE("ָ��������Ч"), _CRT_WIDE(__FILE__), (unsigned)(__LINE__));
}

/// <summary>
/// �������е����ݴ�ӡ
/// </summary>
void SLList::print() {
	node* curNode = pFront;
	while (curNode != nullptr) {
		cout << curNode->data << " -> ";
		curNode = curNode->next;
	}
	cout << "null" << endl;
}

#pragma endregion

#pragma endregion