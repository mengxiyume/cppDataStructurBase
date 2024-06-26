#pragma once

//双链表存储数据的类型
typedef int SingleLinkListDataType, SLData;

/// <summary>
/// 单链表类
/// <para>-结构-</para>
/// <para><seealso cref="node - 一个链表节点"/></para>
/// <para>-成员-</para>
/// <para><seealso cref="pushFront() - 头插"/></para>
/// <para><seealso cref="pushBack() - 尾插"/></para>
/// <para><seealso cref="insert() - 插入"/></para>
/// <para><seealso cref="popFront() - 头删"/></para>
/// <para><seealso cref="popBack() - 尾删"/></para>
/// <para><seealso cref="del() - 删除"/></para>
/// <para><seealso cref="getPos() - 获取指定节点"/></para>
/// <para><seealso cref="print() - 打印链表"/></para>
/// <para><seealso cref="m_pFront - 链表第一个有效节点"/></para>
/// <para><seealso cref="m_pBack - 链表最后一个有效节点"/></para>
/// <para><seealso cref="m_nSize - 链表有效节点的数量"/></para>
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

	/*----------------------------------------------//
	* 请不要自行更改该指针指向的内容				//
	* 表面值，更改不影响实际结构					//
	* 调用内置函数更改结构后覆写 */					//
	const node* m_pFront;	//链表第一个有效节点	//
	const node* m_pBack;	//链表最后一个有效节点	//
	size_t m_nSize;			//链表有效节点的数量	//
	/*----------------------------------------------*/

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
	/// 在指定节点前插入数据
	/// <para>*节点无效时报错*</para>
	/// </summary>
	/// <param name="next">指定节点的指针 | nullptr 代表插入坐标第零个节点</param>
	/// <param name="value">插入需要记录的值</param>
	void insert(node* next, SLData value);
	/// <summary>
	/// 在指定坐标插入节点
	/// <para>*坐标无效时报错*</para>
	/// </summary>
	/// <param name="position">指定节点的坐标  /*以偏移量形式*/</param>
	/// <param name="value">插入需要记录的值</param>
	void insert(size_t position, SLData value);

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
	/// 删除指定节点
	/// <para>*节点无效时报错*</para>
	/// </summary>
	/// <param name="delNode">指定节点的指针</param>
	void del(node* delNode);
	/// <summary>
	/// 删除指定节点
	/// <para>*坐标无效时报错*</para>
	/// </summary>
	/// <param name="position">指定节点的坐标  /*以偏移量形式*/</param>
	void del(size_t position);

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
	/// 获取指定节点
	/// </summary>
	/// <param name="position">节点的坐标 /*以偏移量形式*/</param>
	/// <returns>查找到的节点的指针 | 未查找到时返回nullptr</returns>
	node* getPos(size_t position);

	/// <summary>
	/// 将链表中的内容打印
	/// </summary>
	void print();

#pragma endregion

private:

	node* pHead = nullptr;		//链表头
	node* pFront = nullptr;		//链表第一个有效节点
	node* pBack = nullptr;		//链表最后一个有效节点
	size_t nodeCount = 0;		//链表有效节点的数量

	/// <summary>
	/// 申请一个链表节点
	/// <para>*申请失败报错*</para>
	/// </summary>
	/// <returns>已申请的节点</returns>
	node* buyOneNode();

}SLList;