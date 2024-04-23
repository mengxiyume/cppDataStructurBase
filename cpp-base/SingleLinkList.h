#pragma once

//数据类型及相应指针命名
typedef int SingleLinkListDataType, * pSingleLinkListDataType, SLData, * pSLData;

typedef class SingleLinkList {
	//这是一个链表类
public:

	/// <summary>
	/// 一个单链表节点
	/// <para>-成员-</para>
	/// <para><remarks>data - 节点存放的数据</remarks></para>
	/// <para><remarks>next - 下一个节点的地址</remarks></para>
	/// </summary>
	typedef struct Node {
		SLData data;		//节点存放的数据
		struct Node* next;	//下一个节点的地址
	}Node, node;

#pragma region 构造相关重载
	SingleLinkList();
	~SingleLinkList();
#pragma endregion

#pragma region 常规链表操作

	/// <summary>
	/// 从链表头部节点进行插入
	/// </summary>
	/// <param name="value">插入需要记录的值</param>
	void pushFront(SLData value);
	/// <summary>
	/// 从链表尾部节点进行插入
	/// </summary>
	/// <param name="value">插入需要记录的值</param>
	void pushBack(SLData value);

	/// <summary>
	/// 删除链表头的第一个有效节点
	/// <para>*无节点时报错*</para>
	/// </summary>
	void popFront();
	/// <summary>
	/// 删除链表的最后一个有效节点
	/// <para>*无节点时报错*</para>
	/// </summary>
	void popBack();

	/// <summary>
	/// 获取当前链表的第一个有效节点
	/// </summary>
	/// <returns>节点指针 | 无有效节点时返回nullptr</returns>
	node* getFront();
	/// <summary>
	/// 获取当前链表的最后一个有效节点
	/// </summary>
	/// <returns>节点指针 | 无有效节点时返回nullptr</returns>
	node* getBack();

	/// <summary>
	/// 将链表中的内容打印
	/// </summary>
	void print();
#pragma endregion

private:
	node* pHead;	//链表头
	node* pFront;	//链表第一个有效节点
	node* pBack;	//链表最后一个有效节点

	/// <summary>
	/// 申请一个链表节点
	/// <para>*申请失败报错*</para>
	/// </summary>
	/// <returns>已申请的节点</returns>
	node* buyOneNode();
}SLList, *pSLList;