#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;

#include "DoubleLinkList.h"

#pragma region private

DLList::node* pHead;	//链表头

/// <summary>
/// 申请一个链表节点
/// <para>*申请失败报错*</para>
/// </summary>
/// <returns>已申请的节点</returns>
DLList::node* buyOneNode() {
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

	this->front = nullptr;
	this->back = nullptr;
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
	this->front = nullptr;
	this->back = nullptr;
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
	newNode->next = pHead->next;
	newNode->prev = pHead;
	pHead->next->prev = newNode;
	pHead->next = newNode;

	//表面值更新
	this->front = pHead->next;
	this->back = pHead->prev;
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
	newNode->next = pHead;
	newNode->prev = pHead->prev;
	pHead->prev->next = newNode;
	pHead->prev = newNode;

	//表面值更新
	this->front = pHead->next;
	this->back = pHead->prev;
}

/// <summary>
/// 删除链表头的第一个有效节点
/// <para>*无节点时报错*</para>
/// </summary>
void DLList::popFront() {
	assert(pHead->next != pHead);

	node* delNode = pHead->next;
	//节点剔除
	pHead->next->next->prev = pHead;
	pHead->next = delNode->next;

	//回收占用空间
	free(delNode);

	//表面值更新
	this->front = pHead->next != pHead ? pHead->next : nullptr;
	this->back = pHead->next != pHead ? pHead->prev : nullptr;
}
/// <summary>
/// 删除链表的最后一个有效节点
/// <para>*无节点时报错*</para>
/// </summary>
void DLList::popBack() {
	assert(pHead->next != pHead);

	node* delNode = pHead->prev;
	//节点剔除
	pHead->prev->prev->next = pHead;
	pHead->prev = delNode->prev;

	//回收占用空间
	free(delNode);

	//表面值更新
	this->front = pHead->next != pHead ? pHead->next : nullptr;
	this->back = pHead->next != pHead ? pHead->prev : nullptr;
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

//TODO:	根据数据查找节点

//TODO:	删除指定节点

/// <summary>
/// 将链表中的内容打印
/// </summary>
void DLList::print() {

	if (pHead->next == pHead) {
		//链表无内容时打印
		cout << "null" << endl;
		return;
	}

	//链表有内容时打印
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