#define _CRT_SECURE_NO_WARNINGS

//第一次写类，有些生疏，爱来自2024/04/23 - 03:00

#include <cstdlib>
#include <cassert>
#include "SingleLinkList.h"

SLList::node* SLList::buyOneNode() {
		node* temp = (node*)malloc(sizeof(node));
		assert(temp);
		return temp;
	}

#pragma region 构造相关重载
SLList::SingleLinkList() {

		//头节点空间申请
		pHead = buyOneNode();
		pHead->next = nullptr;

		//首尾节点初始化
		pFront = nullptr;
		pBack = nullptr;
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
		pFront = pHead->next;							//首节点的更新
		pBack = pBack != nullptr ? pBack : newNode;		//尾节点的更新
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
		pFront = pHead != nullptr ? pHead : newNode;	//首节点的更新
		pBack = newNode;								//尾节点的更新
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
		pFront = pHead->next;							//首节点的更新
		pBack = pFront != nullptr ? pBack : nullptr;	//尾节点的更新
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
		pFront = pHead->next;							//首节点的更新
		pBack = last;									//尾节点的更新
	}

/// <summary>
	/// 获取当前链表的第一个有效节点
	/// </summary>
	/// <returns>节点指针 | 无有效节点时返回nullptr</returns>
SLList::node* SLList::getFront() {
		return pFront;
	 }
/// <summary>
	/// 获取当前链表的最后一个有效节点
	/// </summary>
	/// <returns>节点指针 | 无有效节点时返回nullptr</returns>
SLList::node* SLList::getBack() {
		return pBack;
	}

//TODO:	根据数据查找节点
	
//TODO:	删除指定节点

#pragma endregion
