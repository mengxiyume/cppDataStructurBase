#pragma once

typedef int SequenceTableDataType, STDataType, STData;

/// <summary>
/// 顺序表类
/// <para>-操作符-</para>
/// <para><seealso cref="[] - 下标访问操作符"/></para>
/// <para>-成员-</para>
/// <para><seealso cref="pushFront() - 头插"/></para>
/// <para><seealso cref="pushBack() - 尾插"/></para>
/// <para><seealso cref="insert() - 插入"/></para>
/// <para><seealso cref="popFront() - 头删"/></para>
/// <para><seealso cref="popBack() - 尾删"/></para>
/// <para><seealso cref="del() - 删除"/></para>
/// <para><seealso cref="print() - 打印顺序表"/></para>
/// <para><seealso cref="m_nSize - 顺序表有效数据的数量"/></para>
/// </summary>
typedef class SequenceTable {
public:

	/*--------------------------------------//
	* 请不要自行更改该指针指向的内容		//
	* 表面值，更改不影响实际结构			//
	* 调用内置函数更改结构后覆写 */			//
	size_t m_nSize;		//有效数据的数量	//
	/*--------------------------------------*/

	//TODO:查找、重载操作符使其使用方式接近string类

#pragma region 构造相关重载

	SequenceTable();
	~SequenceTable();

#pragma endregion

#pragma region 操作符重载

	/// <summary>
	/// 下标操作符
	/// </summary>
	/// <param name="position">元素在顺序表中的位置</param>
	/// <para>*无元素时报错*</para>
	/// <para>*pos越界时报错*</para>
	/// <returns>第pos个元素的引用</returns>
	STData& operator[](size_t position);

#pragma endregion

#pragma region 常规顺序表操作

	/// <summary>
	/// 在顺序表的第零个元素位置插入值
	/// </summary>
	/// <param name="value">插入需要记录的值</param>
	void pushFront(STData value);
	/// <summary>
	/// 在顺序表的第最后一个元素位置插入值
	/// </summary>
	/// <param name="value">插入需要记录的值</param>
	void pushBack(STData value);
	/// <summary>
	/// 在指定坐标插入节点
	/// <para>*节点无效时报错*</para>
	/// </summary>
	/// <param name="position">指定节点的坐标  /*以偏移量形式*/</param>
	/// <param name="value">插入需要记录的值</param>
	void insert(size_t position, STData value);

	/// <summary>
	/// 删除顺序表的第零个数据
	/// <para>*无数据时报错*</para>
	/// </summary>
	void popFront();
	/// <summary>
	/// 删除顺序表的最后一个数据
	/// <para>*无数据时报错*</para>
	/// </summary>
	void popBack();
	/// <summary>
	/// 在指定坐标插入节点
	/// <para>*节点无效时报错*</para>
	/// </summary>
	/// <param name="position">指定节点的坐标  /*以偏移量形式*/</param>
	void del(size_t position);

	/// <summary>
	/// 将链表中的内容打印
	/// </summary>
	void print();

#pragma endregion

private:

	STData* pData;		//数据存放的地址
	size_t size;		//有效数据的数量
	size_t capacity;	//指针结构的大小
	
	/// <summary>
	/// 自动扩容
	/// </summary>
	void increase();
	/// <summary>
	/// 扩容
	/// </summary>
	/// <param name="isForce">true 时强制扩容 | false 时自动扩容</param>
	void increase(bool isForce);

	//...
}STable;