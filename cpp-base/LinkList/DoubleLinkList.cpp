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

//FIXME:将pop与push功能重复部分分离

/// <summary>
/// 申请一个链表节点
/// <para>*申请失败报错*</para>
/// </summary>
/// <returns>已申请的节点</returns>
DLList::node* DLList::buyOneNode() {
	DLList::node* temp = (DLList::node*)malloc(sizeof(DLList::node));
	assert(temp);
	return temp;
}

#pragma endregion

#pragma region public

#pragma region 构造相关重载

DLList::DoubleLinkList() {
	//头节点申请
	pHead = buyOneNode();

	//头节点循环链接初始化
	pHead->next = pHead;
	pHead->prev = pHead;

	this->m_pFront	= nullptr;
	this->m_pBack	= nullptr;
	nodeCount		= 0;
	this->m_nSize	= 0;
}

DLList::~DoubleLinkList() {
	//断开循环链接
	pHead->prev->next = nullptr;
	pHead->prev = nullptr;

	//迭代释放
	node* curNode = pHead;

	while (curNode != nullptr) {
		//迭代释放
		node* prevNode = curNode;
		curNode = curNode->next;
		free(prevNode);
		prevNode = nullptr;
	}

	//指针归零
	pHead = nullptr;
	this->m_pFront	= nullptr;
	this->m_pBack	= nullptr;
	nodeCount		= 0;
	this->m_nSize	= 0;
}

#pragma endregion

#pragma region 常规链表操作

/// <summary>
/// 从链表头部节点进行插入
/// </summary>
/// <param name="value">插入需要记录的值</param>
void DLList::pushFront(DLData value) {
	//申请与注入
	node* newNode = buyOneNode();
	newNode->data = value;

	//接驳链表
	newNode		->next = pHead->next;
	newNode		->prev = pHead;
	pHead->next	->prev = newNode;
	pHead		->next = newNode;

	//表面值更新
	this->m_pFront	= pHead->next;
	this->m_pBack	= pHead->prev;
	nodeCount		++;
	this->m_nSize	= nodeCount;
}
/// <summary>
/// 从链表尾部节点进行插入
/// </summary>
/// <param name="value">插入需要记录的值</param>
void DLList::pushBack(DLData value) {
	//申请与注入
	node* newNode = buyOneNode();
	newNode->data = value;

	//接驳链表
	newNode		->next = pHead;
	newNode		->prev = pHead->prev;
	pHead->prev	->next = newNode;
	pHead		->prev = newNode;

	//表面值更新
	this->m_pFront	= pHead->next;
	this->m_pBack	= pHead->prev;
	nodeCount		++;
	this->m_nSize	= nodeCount;
}
/// <summary>
/// 在指定节点前插入数据
/// <para>*节点无效时报错*</para>
/// </summary>
/// <param name="next">指定节点的指针 | nullptr 代表插入坐标第零个节点</param>
/// <param name="value">插入需要记录的值</param>
void DLList::insert(node* next, DLData value) {
	//参数有效性检查
	if (next != nullptr) {
		//检查传入节点是否该链表的节点
		node* curNode = pHead->next;
		bool haveNode = false;
		while (curNode != pHead) {
			if (curNode == next)
				haveNode = true;
			curNode = curNode->next;
		}
		//非本链表节点无效
		assert_set(haveNode, "传入节点无效");
	}

	//申请与注入
	node* newNode = buyOneNode();
	newNode->data = value;
	
	//接驳链表
	next = next != nullptr ? next : pHead;
	newNode		->next = next;
	newNode		->prev = next->prev;
	next->prev	->next = newNode;
	next		->prev = newNode;

	//表面值更新
	this->m_pFront	= pHead->next;
	this->m_pBack	= pHead->prev;
	nodeCount		++;
	this->m_nSize	= nodeCount;
}
/// <summary>
/// 在指定坐标插入节点
/// <para>*坐标无效时报错*</para>
/// </summary>
/// <param name="position">指定节点的坐标  /*以偏移量形式*/</param>
/// <param name="value">插入需要记录的值</param>
void DLList::insert(size_t position, DLData value) {
	//参数有效性检查
	if (position > nodeCount) {
		//越界无效
		assert_set(0, "指定坐标无效");
	}

	//申请与注入
	node* newNode = buyOneNode();
	newNode->data = value;

	//寻找坐标前一个节点
	node* prev = getPos(position)->prev;

	//接驳链表
	prev = prev != nullptr ? prev : pHead;
	newNode		->prev = prev;
	newNode		->next = prev->next;
	prev->next	->prev = newNode;
	prev		->next = newNode;

	//表面值更新
	this->m_pFront	= pHead->next;
	this->m_pBack	= pHead->prev;
	nodeCount		++;
	this->m_nSize	= nodeCount;
}

/// <summary>
/// 删除链表头的第一个有效节点
/// <para>*无节点时报错*</para>
/// </summary>
void DLList::popFront() {
	//有效性判断
	assert_set(pHead->next != pHead, "无可删除节点");

	node* delNode = pHead->next;
	//节点剔除
	pHead->next->next	->prev = pHead;
	pHead				->next = delNode->next;

	//回收占用空间
	free(delNode);
	delNode = nullptr;

	//表面值更新
	this->m_pFront	= pHead->next != pHead ? pHead->next : nullptr;
	this->m_pBack	= pHead->next != pHead ? pHead->prev : nullptr;
	nodeCount		--;
	this->m_nSize	= nodeCount;
}
/// <summary>
/// 删除链表的最后一个有效节点
/// <para>*无节点时报错*</para>
/// </summary>
void DLList::popBack() {
	//有效性判断
	assert_set(pHead->prev != pHead, "无可删除节点");

	node* delNode = pHead->prev;
	//节点剔除
	pHead->prev->prev->next = pHead;
	pHead->prev = delNode->prev;

	//回收占用空间
	free(delNode);
	delNode = nullptr;

	//表面值更新
	this->m_pFront	= pHead->prev != pHead ? pHead->next : nullptr;
	this->m_pBack	= pHead->prev != pHead ? pHead->prev : nullptr;
	m_nSize			--;
	this->m_nSize	= nodeCount;
}
/// <summary>
/// 删除指定节点
/// <para>*节点无效时报错*</para>
/// </summary>
/// <param name="delNode">指定节点的指针</param>
void DLList::del(node* delNode) {
	//参数有效性检查
	assert_set(delNode, "传入节点无效");

	//检查传入节点是否该链表的节点
	bool haveNode = false;
	node* curNode = pHead->next;
	//非本链表节点无效
	while (curNode != pHead) {
		if (curNode == delNode)
			haveNode = true;
		curNode = curNode->next;
	}
	//该链表头节点无效
	haveNode = (haveNode == false ? (delNode == pHead ? true : false) : haveNode);
	assert_set(haveNode, "传入节点无效");

	//节点剔除
	delNode->prev->next = delNode->next;
	delNode->next->prev = delNode->prev;

	//回收占用空间
	free(delNode);
	delNode = nullptr;

	//表面值更新
	this->m_pFront	= pHead->next != pHead ? pHead->next : nullptr;
	this->m_pBack	= pHead->next != pHead ? pHead->prev : nullptr;
	nodeCount		--;
	this->m_nSize	= nodeCount;
}
/// <summary>
/// 删除指定节点
/// <para>*坐标无效时报错*</para>
/// </summary>
/// <param name="position">指定节点的坐标  /*以偏移量形式*/</param>
void DLList::del(size_t position) {
	if (position > nodeCount) {
		//越界无效
		assert_set(0, "指定坐标无效");
	}

	//获取上一个节点的地址
	node* delNode = getPos(position);

	//节点剔除
	delNode->prev->next = delNode->next;
	delNode->next->prev = delNode->prev;

	//回收占用空间
	free(delNode);
	delNode = nullptr;

	//表面值更新
	this->m_pFront	= pHead->prev != pHead ? pHead->next : nullptr;
	this->m_pBack	= pHead->prev != pHead ? pHead->prev : nullptr;
	nodeCount		--;
	this->m_nSize	= nodeCount;
}

///// <summary>
///// 获取当前链表的第一个有效节点
///// </summary>
///// <returns>节点指针 | 无有效节点时返回nullptr</returns>
//DLList::node* DLList::getFront() {
//	return pHead->next;
//}
///// <summary>
///// 获取当前链表的最后一个有效节点
///// </summary>
///// <returns>节点指针 | 无有效节点时返回nullptr</returns>
//DLList::node* DLList::getBack() {
//	return pHead->prev;
//}

/// <summary>
/// 获取指定节点
/// </summary>
/// <param name="position">节点的坐标 /*以偏移量形式*/</param>
/// <returns>查找到的节点的指针 | 未查找到时返回nullptr</returns>
DLList::node* DLList::getPos(size_t position) {
	//参数有效性检查
	if (position > nodeCount) {
		//越界无效
		return nullptr;
	}

	//循环访问查找pos节点
	node* curNode = pHead->next;
	for (size_t i = 0; i < position; i++) {
		curNode = curNode->next;
	}

	return curNode;
}

/// <summary>
/// 将链表中的内容打印
/// </summary>
void DLList::print() {

	if (pHead->next == pHead) {
		//链表无内容时打印
		std::cout << "null" << std::endl;
		return;
	}

	//链表有内容时打印
	std::cout << "null <- ";

	node* curNode = pHead->next;
	while (curNode != pHead) {
		assert(curNode);	//这一行结构完整时不必要
		std::cout << curNode->data;
		curNode->next != pHead && std::cout << " <=> ";
		curNode = curNode->next;
	}

	std::cout << " -> null" << std::endl;
}

#pragma endregion

#pragma endregion