#define _CRT_SECURE_NO_WARNINGS

//第一次写类，有些生疏，爱来自2024/04/23 - 03:00

#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;

#include "SingleLinkList.h"

#pragma region private

SLList::node* pHead;	//链表头
SLList::node* pFront;	//链表第一个有效节点
SLList::node* pBack;	//链表最后一个有效节点

/// <summary>
/// 申请一个链表节点
/// <para>*申请失败报错*</para>
/// </summary>
/// <returns>已申请的节点</returns>
SLList::node* buyOneNode() {
	SLList::node* temp = (SLList::node*)malloc(sizeof(SLList::node));
	assert(temp);
	return temp;
}

#pragma endregion

#pragma region public

#pragma region 构造相关重载

SLList::SingleLinkList() {
	//头节点空间申请
	pHead = buyOneNode();
	pHead->next = nullptr;

	//首尾节点初始化
	pFront = nullptr;
	pBack = nullptr;

	this->front = nullptr;
	this->back = nullptr;
}

SLList::~SingleLinkList() {
	node* curNode = pHead;

	while (curNode != nullptr) {
		//迭代释放
		node* prevNode = curNode;
		curNode = curNode->next;
		free(prevNode);
		prevNode = nullptr;
	}

	//所有记录指针归零
	pHead = pFront = pBack = nullptr;
	this->front = nullptr;
	this->back = nullptr;
}

#pragma endregion

#pragma region 常规链表操作

/// <summary>
/// 从链表头部节点进行插入
/// </summary>
/// <param name="value">插入需要记录的值</param>
void SLList::pushFront(SLData value) {
	//申请与注入
	node* newNode = buyOneNode();
	newNode->data = value;

	//接驳链表
	newNode->next = pFront;
	pHead->next = newNode;

	//其他记录指针的处理
	this->front = pFront = pHead->next;							//首节点的更新
	this->back = pBack = pBack != nullptr ? pBack : newNode;	//尾节点的更新
}
/// <summary>
/// 从链表尾部节点进行插入
/// </summary>
/// <param name="value">插入需要记录的值</param>
void SLList::pushBack(SLData value) {
	//申请与注入
	node* newNode = buyOneNode();
	newNode->data = value;

	//接驳链表
	node* prevNode = pBack != nullptr ? pBack : pHead;
	newNode->next = nullptr;
	prevNode->next = newNode;

	//其他记录指针的处理
	this->front = pFront = pFront != nullptr ? pFront : newNode;	//首节点的更新
	this->back = pBack = newNode;									//尾节点的更新
}
/// <summary>
/// 在指定节点后插入数据
/// <para>*节点无效时报错*</para>
/// </summary>
/// <param name="prev">指定节点的指针 | nullptr 代表插入坐标第零个节点</param>
/// <param name="value">插入需要记录的值</param>
void SLList::insert(node* prev, SLData value) {
	//TODO:	根据数据查找节点
	//非本链表节点无效
	_wassert(_CRT_WIDE("传入节点无效"), _CRT_WIDE(__FILE__), (unsigned)(__LINE__));
}
/// <summary>
/// 在指定坐标插入节点
/// <para>*坐标无效时报错*</para>
/// </summary>
/// <param name="position">指定节点的坐标  /*以偏移量形式*/</param>
/// <param name="value">插入需要记录的值</param>
void SLList::insert(size_t position, SLData value) {
	//越界无效
	_wassert(_CRT_WIDE("指定坐标无效"), _CRT_WIDE(__FILE__), (unsigned)(__LINE__));
}


/// <summary>
/// 删除链表头的第一个有效节点
/// <para>*无节点时报错*</para>
/// </summary>
void SLList::popFront() {
	assert(pFront);

	//首节点断开链接
	pHead->next = pFront->next;

	//回收占用的空间
	free(pFront);

	//其他记录指针的处理
	this->front = pFront = pHead->next;							//首节点的更新
	this->back = pBack = pFront != nullptr ? pBack : nullptr;	//尾节点的更新
}
/// <summary>
/// 删除链表的最后一个有效节点
/// <para>*无节点时报错*</para>
/// </summary>
void SLList::popBack() {
	assert(pBack);

	//找到尾节点的前一个节点
	node* last = pHead;
	while (last->next != pBack) {
		last = last->next;
	}

	//删除尾节点
	free(pBack);
	last->next = nullptr;

	//其他记录指针的处理
	this->front = pFront = pHead->next;							//首节点的更新
	this->back = pBack = last;									//尾节点的更新
}
/// <summary>
/// 删除指定节点
/// <para>*节点无效时报错*</para>
/// </summary>
/// <param name="delNode">指定节点的指针</param>
/// <summary>
/// 删除指定节点
/// <para>*节点无效时报错*</para>
/// </summary>
/// <param name="delNode">指定节点的指针</param>
void SLList::del(node* delNode) {
	//TODO:	删除指定节点
	//非本链表节点无效
	_wassert(_CRT_WIDE("传入节点无效"), _CRT_WIDE(__FILE__), (unsigned)(__LINE__));
}
/// <summary>
/// 删除指定节点
/// <para>*坐标无效时报错*</para>
/// </summary>
/// <param name="position">指定节点的坐标  /*以偏移量形式*/</param>
void SLList::del(size_t position) {
	//越界无效
	_wassert(_CRT_WIDE("指定坐标无效"), _CRT_WIDE(__FILE__), (unsigned)(__LINE__));
}

///// <summary>
///// 获取当前链表的第一个有效节点
///// </summary>
///// <returns>节点指针 | 无有效节点时返回nullptr</returns>
//SLList::node* SLList::getFront() {
//	return pFront;
//}
///// <summary>
///// 获取当前链表的最后一个有效节点
///// </summary>
///// <returns>节点指针 | 无有效节点时返回nullptr</returns>
//SLList::node* SLList::getBack() {
//	return pBack;
//}

/// <summary>
/// 获取指定节点
/// <para>*坐标无效时报错*</para>
/// </summary>
/// <param name="position">节点的坐标 /*以偏移量形式*/</param>
/// <returns></returns>
SLList::node* SLList::getPos(size_t position) {
	//TODO:获取指定节点指针
	return nullptr;
	_wassert(_CRT_WIDE("指定坐标无效"), _CRT_WIDE(__FILE__), (unsigned)(__LINE__));
}

/// <summary>
/// 将链表中的内容打印
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