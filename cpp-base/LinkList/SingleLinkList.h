#pragma once

//数据类型及相应指针命名
typedef int SingleLinkListDataType, * pSingleLinkListDataType, SLData, * pSLData;

/// <summary>
/// 单链表类
/// <para>-结构-</para>
/// <para><seealso cref="node - 一个链表节点"/></para>
/// <para>-成员-</para>
/// <para><seealso cref="pushFront() - 头插"/></para>
/// <para><seealso cref="pushBack() - 尾插"/></para>
/// <para><seealso cref="popFront() - 头删"/></para>
/// <para><seealso cref="popBack() - 尾删"/></para>
/// <para><seealso cref="getFront() - 获取头节点"/></para>
/// <para><seealso cref="getBack() - 获取尾节点"/></para>
/// <para><seealso cref="print() - 打印链表"/></para>
/// </summary>
typedef class SingleLinkList {
	//这是一个单链表类
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

}SLList, *pSLList;