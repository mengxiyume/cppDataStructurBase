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

	//TODO:插入、删除、查找、打印、构造、析构、重载 [ ] 操作符、重载操作符使其使用方式接近string类

	/// <summary>
	/// 获取顺序表的第pos个元素
	/// </summary>
	/// <param name="position">元素在顺序表中的位置</param>
	/// <para>*无元素时报错*</para>
	/// <para>*pos越界时报错*</para>
	/// <returns>第pos个元素的引用</returns>
	STData& operator[](size_t position);

	//...
}STable;