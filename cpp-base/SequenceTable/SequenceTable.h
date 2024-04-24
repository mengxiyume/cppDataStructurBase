#pragma once

typedef int SequenceTableDataType, STDataType, STData;

typedef class SequenceTable {
	//TODO:数据及接口的定义
public:

		/*--------------------------------------//
	* 请不要自行更改该指针指向的内容		//
	* 表面值，更改不影响实际结构			//
	* 调用内置函数更改结构后覆写 */			//
	size_t size;		//有效数据的数量	//
	/*--------------------------------------*/

	//TODO:插入、删除、查找、打印、构造、析构、重载 [ ] 下标操作符、重载操作符使其使用方式接近string类

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
	void insert(size_t position, DLData value);

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
	/// 将链表中的内容打印
	/// </summary>
	void print();

#pragma endregion

	//...
}STable;