#pragma once

//双链表存储数据的类型
typedef int DoubleLinkListDataType, DLData;

/// <summary>
/// 双链表类
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
typedef class DoubleLinkList {
	//这是一个双链表类
public:

	/// <summary>
	/// 一个单链表节点
	/// <para>-成员-</para>
	/// <para><remarks>data - 节点存放的数据</remarks></para>
	/// <para><remarks>next - 下一个节点的地址</remarks></para>
	/// </summary>
	typedef struct Node {
		DLData data;		//节点存放的数据
		struct Node* prev;	//上一个节点的地址
		struct Node* next;	//下一个节点的地址
	}Node, node;

	/*--------------------------------------//
	* 请不要自行更改该指针指向的内容		//
	* 表面值，更改不影响实际结构			//
	* 调用内置函数更改结构后覆写 */			//
	node* front;	//链表第一个有效节点	//
	node* back;		//链表最后一个有效节点	//
	/*--------------------------------------*/

#pragma region 构造相关重载

	DoubleLinkList();
	~DoubleLinkList();

#pragma endregion

#pragma region 常规链表操作

	/// <summary>
	/// 从链表头部节点进行插入
	/// </summary>
	/// <param name="value">插入需要记录的值</param>
	void pushFront(DLData value);
	/// <summary>
	/// 从链表尾部节点进行插入
	/// </summary>
	/// <param name="value">插入需要记录的值</param>
	void pushBack(DLData value);

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

	///// <summary>
	///// 获取当前链表的第一个有效节点
	///// </summary>
	///// <returns>节点指针 | 无有效节点时返回nullptr</returns>
	//node* getFront();
	///// <summary>
	///// 获取当前链表的最后一个有效节点
	///// </summary>
	///// <returns>节点指针 | 无有效节点时返回nullptr</returns>
	//node* getBack();

	/// <summary>
	/// 将链表中的内容打印
	/// </summary>
	void print();

#pragma endregion

}DLList;