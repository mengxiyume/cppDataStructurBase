#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>
#include <cassert>
#include <iostream>

#include "DoubleLinkList.h"

#define assert_set(expression, str) (void)(                                          \
            (!!(expression)) ||                                                      \
            (_wassert(_CRT_WIDE(str), _CRT_WIDE(__FILE__), (unsigned)(__LINE__)), 0) \
        )

#pragma region private

//FIXME:��pop��push�����ظ����ַ���

/// <summary>
/// ����һ������ڵ�
/// <para>*����ʧ�ܱ���*</para>
/// </summary>
/// <returns>������Ľڵ�</returns>
DLList::node* DLList::buyOneNode() {
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

	this->m_pFront	= nullptr;
	this->m_pBack	= nullptr;
	nodeCount		= 0;
	this->m_nSize	= 0;
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
	this->m_pFront	= nullptr;
	this->m_pBack	= nullptr;
	nodeCount		= 0;
	this->m_nSize	= 0;
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
	newNode		->next = pHead->next;
	newNode		->prev = pHead;
	pHead->next	->prev = newNode;
	pHead		->next = newNode;

	//����ֵ����
	this->m_pFront	= pHead->next;
	this->m_pBack	= pHead->prev;
	nodeCount		++;
	this->m_nSize	= nodeCount;
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
	newNode		->next = pHead;
	newNode		->prev = pHead->prev;
	pHead->prev	->next = newNode;
	pHead		->prev = newNode;

	//����ֵ����
	this->m_pFront	= pHead->next;
	this->m_pBack	= pHead->prev;
	nodeCount		++;
	this->m_nSize	= nodeCount;
}
/// <summary>
/// ��ָ���ڵ�ǰ��������
/// <para>*�ڵ���Чʱ����*</para>
/// </summary>
/// <param name="next">ָ���ڵ��ָ�� | nullptr ����������������ڵ�</param>
/// <param name="value">������Ҫ��¼��ֵ</param>
void DLList::insert(node* next, DLData value) {
	//������Ч�Լ��
	if (next != nullptr) {
		//��鴫��ڵ��Ƿ������Ľڵ�
		node* curNode = pHead->next;
		bool haveNode = false;
		while (curNode != pHead) {
			if (curNode == next)
				haveNode = true;
			curNode = curNode->next;
		}
		//�Ǳ�����ڵ���Ч
		assert_set(haveNode, "����ڵ���Ч");
	}

	//������ע��
	node* newNode = buyOneNode();
	newNode->data = value;
	
	//�Ӳ�����
	next = next != nullptr ? next : pHead;
	newNode		->next = next;
	newNode		->prev = next->prev;
	next->prev	->next = newNode;
	next		->prev = newNode;

	//����ֵ����
	this->m_pFront	= pHead->next;
	this->m_pBack	= pHead->prev;
	nodeCount		++;
	this->m_nSize	= nodeCount;
}
/// <summary>
/// ��ָ���������ڵ�
/// <para>*������Чʱ����*</para>
/// </summary>
/// <param name="position">ָ���ڵ������  /*��ƫ������ʽ*/</param>
/// <param name="value">������Ҫ��¼��ֵ</param>
void DLList::insert(size_t position, DLData value) {
	//������Ч�Լ��
	if (position > nodeCount) {
		//Խ����Ч
		assert_set(0, "ָ��������Ч");
	}

	//������ע��
	node* newNode = buyOneNode();
	newNode->data = value;

	//Ѱ������ǰһ���ڵ�
	node* prev = getPos(position)->prev;

	//�Ӳ�����
	prev = prev != nullptr ? prev : pHead;
	newNode		->prev = prev;
	newNode		->next = prev->next;
	prev->next	->prev = newNode;
	prev		->next = newNode;

	//����ֵ����
	this->m_pFront	= pHead->next;
	this->m_pBack	= pHead->prev;
	nodeCount		++;
	this->m_nSize	= nodeCount;
}

/// <summary>
/// ɾ������ͷ�ĵ�һ����Ч�ڵ�
/// <para>*�޽ڵ�ʱ����*</para>
/// </summary>
void DLList::popFront() {
	//��Ч���ж�
	assert_set(pHead->next != pHead, "�޿�ɾ���ڵ�");

	node* delNode = pHead->next;
	//�ڵ��޳�
	pHead->next->next	->prev = pHead;
	pHead				->next = delNode->next;

	//����ռ�ÿռ�
	free(delNode);
	delNode = nullptr;

	//����ֵ����
	this->m_pFront	= pHead->next != pHead ? pHead->next : nullptr;
	this->m_pBack	= pHead->next != pHead ? pHead->prev : nullptr;
	nodeCount		--;
	this->m_nSize	= nodeCount;
}
/// <summary>
/// ɾ����������һ����Ч�ڵ�
/// <para>*�޽ڵ�ʱ����*</para>
/// </summary>
void DLList::popBack() {
	//��Ч���ж�
	assert_set(pHead->prev != pHead, "�޿�ɾ���ڵ�");

	node* delNode = pHead->prev;
	//�ڵ��޳�
	pHead->prev->prev->next = pHead;
	pHead->prev = delNode->prev;

	//����ռ�ÿռ�
	free(delNode);
	delNode = nullptr;

	//����ֵ����
	this->m_pFront	= pHead->prev != pHead ? pHead->next : nullptr;
	this->m_pBack	= pHead->prev != pHead ? pHead->prev : nullptr;
	m_nSize			--;
	this->m_nSize	= nodeCount;
}
/// <summary>
/// ɾ��ָ���ڵ�
/// <para>*�ڵ���Чʱ����*</para>
/// </summary>
/// <param name="delNode">ָ���ڵ��ָ��</param>
void DLList::del(node* delNode) {
	//������Ч�Լ��
	assert_set(delNode, "����ڵ���Ч");

	//��鴫��ڵ��Ƿ������Ľڵ�
	bool haveNode = false;
	node* curNode = pHead->next;
	//�Ǳ�����ڵ���Ч
	while (curNode != pHead) {
		if (curNode == delNode)
			haveNode = true;
		curNode = curNode->next;
	}
	//������ͷ�ڵ���Ч
	haveNode = (haveNode == false ? (delNode == pHead ? true : false) : haveNode);
	assert_set(haveNode, "����ڵ���Ч");

	//�ڵ��޳�
	delNode->prev->next = delNode->next;
	delNode->next->prev = delNode->prev;

	//����ռ�ÿռ�
	free(delNode);
	delNode = nullptr;

	//����ֵ����
	this->m_pFront	= pHead->next != pHead ? pHead->next : nullptr;
	this->m_pBack	= pHead->next != pHead ? pHead->prev : nullptr;
	nodeCount		--;
	this->m_nSize	= nodeCount;
}
/// <summary>
/// ɾ��ָ���ڵ�
/// <para>*������Чʱ����*</para>
/// </summary>
/// <param name="position">ָ���ڵ������  /*��ƫ������ʽ*/</param>
void DLList::del(size_t position) {
	if (position > nodeCount) {
		//Խ����Ч
		assert_set(0, "ָ��������Ч");
	}

	//��ȡ��һ���ڵ�ĵ�ַ
	node* delNode = getPos(position);

	//�ڵ��޳�
	delNode->prev->next = delNode->next;
	delNode->next->prev = delNode->prev;

	//����ռ�ÿռ�
	free(delNode);
	delNode = nullptr;

	//����ֵ����
	this->m_pFront	= pHead->prev != pHead ? pHead->next : nullptr;
	this->m_pBack	= pHead->prev != pHead ? pHead->prev : nullptr;
	nodeCount		--;
	this->m_nSize	= nodeCount;
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
/// </summary>
/// <param name="position">�ڵ������ /*��ƫ������ʽ*/</param>
/// <returns>���ҵ��Ľڵ��ָ�� | δ���ҵ�ʱ����nullptr</returns>
DLList::node* DLList::getPos(size_t position) {
	//������Ч�Լ��
	if (position > nodeCount) {
		//Խ����Ч
		return nullptr;
	}

	//ѭ�����ʲ���pos�ڵ�
	node* curNode = pHead->next;
	for (size_t i = 0; i < position; i++) {
		curNode = curNode->next;
	}

	return curNode;
}

/// <summary>
/// �������е����ݴ�ӡ
/// </summary>
void DLList::print() {

	if (pHead->next == pHead) {
		//����������ʱ��ӡ
		std::cout << "null" << std::endl;
		return;
	}

	//����������ʱ��ӡ
	std::cout << "null <- ";

	node* curNode = pHead->next;
	while (curNode != pHead) {
		assert(curNode);	//��һ�нṹ����ʱ����Ҫ
		std::cout << curNode->data;
		curNode->next != pHead && std::cout << " <=> ";
		curNode = curNode->next;
	}

	std::cout << " -> null" << std::endl;
}

#pragma endregion

#pragma endregion