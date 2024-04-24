#define _CRT_SECURE_NO_WARNINGS

//��һ��д�࣬��Щ���裬������2024/04/23 - 03:00

#include <cstdlib>
#include <cassert>
#include <iostream>

#include "SingleLinkList.h"

#define assert_set(expression, str) (void)(                                          \
            (!!(expression)) ||                                                      \
            (_wassert(_CRT_WIDE(str), _CRT_WIDE(__FILE__), (unsigned)(__LINE__)), 0) \
        )

#pragma region private

/// <summary>
/// ����һ������ڵ�
/// <para>*����ʧ�ܱ���*</para>
/// </summary>
/// <returns>������Ľڵ�</returns>
SLList::node* SLList::buyOneNode() {
	SLList::node* temp = (SLList::node*)malloc(sizeof(SLList::node));
	assert(temp);
	return temp;
}

#pragma endregion

//FIXME:�Ķ��ṹʱ��size�ĸ���

#pragma region public

#pragma region �����������

SLList::SingleLinkList() {
	//ͷ�ڵ�ռ�����
	pHead = buyOneNode();
	pHead->next = nullptr;

	//��β�ڵ��ʼ��
	pFront = nullptr;
	pBack = nullptr;

	this->m_pFront = nullptr;
	this->m_pBack = nullptr;

	nodeCount = 0;
	this->m_nSize = 0;
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
	this->m_pFront = nullptr;
	this->m_pBack = nullptr;

	nodeCount = 0;
	this->m_nSize = 0;
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
	this->m_pFront = pFront = pHead->next;							//�׽ڵ�ĸ���
	this->m_pBack = pBack = pBack != nullptr ? pBack : newNode;	//β�ڵ�ĸ���
	nodeCount++;
	this->m_nSize = nodeCount;
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
	this->m_pFront = pFront = pFront != nullptr ? pFront : newNode;	//�׽ڵ�ĸ���
	this->m_pBack = pBack = newNode;									//β�ڵ�ĸ���
	nodeCount++;
	this->m_nSize = nodeCount;
}
/// <summary>
/// ��ָ���ڵ�ǰ��������
/// <para>*�ڵ���Чʱ����*</para>
/// </summary>
/// <param name="prev">ָ���ڵ��ָ�� | nullptr ����������������ڵ�</param>
/// <param name="value">������Ҫ��¼��ֵ</param>
void SLList::insert(node* next, SLData value) {
	//TODO:	�������ݲ��ҽڵ�
	//�Ǳ�����ڵ���Ч
	assert_set(0, "����ڵ���Ч");

	//this->front = pFront = pFront != nullptr ? pFront : newNode;	//�׽ڵ�ĸ���
	//this->back = pBack = newNode;									//β�ڵ�ĸ���
	nodeCount++;
	this->m_nSize = nodeCount;
}
/// <summary>
/// ��ָ���������ڵ�
/// <para>*������Чʱ����*</para>
/// </summary>
/// <param name="position">ָ���ڵ������  /*��ƫ������ʽ*/</param>
/// <param name="value">������Ҫ��¼��ֵ</param>
void SLList::insert(size_t position, SLData value) {
	//Խ����Ч
	assert_set(0, "ָ��������Ч");

	//this->front = pFront = pFront != nullptr ? pFront : newNode;	//�׽ڵ�ĸ���
	//this->back = pBack = newNode;									//β�ڵ�ĸ���
	nodeCount++;
	this->m_nSize = nodeCount;
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
	this->m_pFront = pFront = pHead->next;							//�׽ڵ�ĸ���
	this->m_pBack = pBack = pFront != nullptr ? pBack : nullptr;	//β�ڵ�ĸ���
	nodeCount++;
	this->m_nSize = nodeCount;
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
	this->m_pFront = pFront = pHead->next;							//�׽ڵ�ĸ���
	this->m_pBack = pBack = last;									//β�ڵ�ĸ���
	nodeCount++;
	this->m_nSize = nodeCount;
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
	assert_set(0, "����ڵ���Ч");

	this->m_pFront = pFront = pHead->next;							//�׽ڵ�ĸ���
	this->m_pBack = pBack = pFront != nullptr ? pBack : nullptr;	//β�ڵ�ĸ���
	nodeCount++;
	this->m_nSize = nodeCount;
}
/// <summary>
/// ɾ��ָ���ڵ�
/// <para>*������Чʱ����*</para>
/// </summary>
/// <param name="position">ָ���ڵ������  /*��ƫ������ʽ*/</param>
void SLList::del(size_t position) {
	//Խ����Ч
	assert_set(0, "ָ��������Ч");

	this->m_pFront = pFront = pHead->next;							//�׽ڵ�ĸ���
	this->m_pBack = pBack = pFront != nullptr ? pBack : nullptr;	//β�ڵ�ĸ���
	nodeCount++;
	this->m_nSize = nodeCount;
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
	assert_set(0, "ָ��������Ч");
}

/// <summary>
/// �������е����ݴ�ӡ
/// </summary>
void SLList::print() {
	node* curNode = pFront;
	while (curNode != nullptr) {
		std::cout << curNode->data << " -> ";
		curNode = curNode->next;
	}
	std::cout << "null" << std::endl;
}

#pragma endregion

#pragma endregion