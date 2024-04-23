#define _CRT_SECURE_NO_WARNINGS

//��һ��д�࣬��Щ���裬������2024/04/23 - 03:00

#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;

#include "SingleLinkList.h"

#pragma region private

SLList::node* pHead;	//����ͷ
SLList::node* pFront;	//������һ����Ч�ڵ�
SLList::node* pBack;	//�������һ����Ч�ڵ�

/// <summary>
/// ����һ�������ڵ�
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
}

#pragma endregion

#pragma region ������������

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
	pFront = pHead->next;							//�׽ڵ�ĸ���
	pBack = pBack != nullptr ? pBack : newNode;		//β�ڵ�ĸ���
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
	pFront = pFront != nullptr ? pFront : newNode;	//�׽ڵ�ĸ���
	pBack = newNode;								//β�ڵ�ĸ���
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
	pFront = pHead->next;							//�׽ڵ�ĸ���
	pBack = pFront != nullptr ? pBack : nullptr;	//β�ڵ�ĸ���
}
/// <summary>
/// ɾ�����������һ����Ч�ڵ�
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
	pFront = pHead->next;							//�׽ڵ�ĸ���
	pBack = last;									//β�ڵ�ĸ���
}

/// <summary>
/// ��ȡ��ǰ�����ĵ�һ����Ч�ڵ�
/// </summary>
/// <returns>�ڵ�ָ�� | ����Ч�ڵ�ʱ����nullptr</returns>
SLList::node* SLList::getFront() {
	return pFront;
}
/// <summary>
/// ��ȡ��ǰ���������һ����Ч�ڵ�
/// </summary>
/// <returns>�ڵ�ָ�� | ����Ч�ڵ�ʱ����nullptr</returns>
SLList::node* SLList::getBack() {
	return pBack;
}

//TODO:	�������ݲ��ҽڵ�

//TODO:	ɾ��ָ���ڵ�

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