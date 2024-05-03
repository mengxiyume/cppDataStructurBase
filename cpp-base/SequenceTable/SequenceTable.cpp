#define _CRT_SECURE_NO_WARNINGS

#include <cassert>
#include <cstdlib>
#include <iostream>
using namespace std;
#include "SequenceTable.h"

#define assert_set(expression, str) (void)(                                          \
            (!!(expression)) ||                                                      \
            (_wassert(_CRT_WIDE(str), _CRT_WIDE(__FILE__), (unsigned)(__LINE__)), 0) \
        )

#pragma region public

#pragma region 构造相关重载

STable::SequenceTable() {

	//结构控制初始化
	this->pData		= nullptr;
	this->size		= 0;
	this->capacity	= 0;
	//表面值初始化
	this->m_nSize	= 0;
}
STable::~SequenceTable() {

	//空间释放
	if (this->pData != nullptr) {
		free(this->pData);
	}
	//结构控制初始化
	this->pData		= nullptr;
	this->capacity	= 0;
	this->size		= 0;
	//表面值初始化
	this->m_nSize	= 0;
}

#pragma endregion

#pragma region 操作符重载

/// <summary>
/// 下标操作符
/// </summary>
/// <param name="position">元素在顺序表中的位置 /*下标形式*/</param>
/// <para>*无元素时报错*</para>
/// <para>*pos越界时报错*</para>
/// <returns>第pos个元素的引用</returns>
STData& STable::operator[](size_t position) {
	assert_set(this->pData, "结构不存在");
	assert_set(position < this->size, "下标越界");

	return this->pData[position];
}

#pragma endregion

#pragma region 常规顺序表操作

/// <summary>
/// 在顺序表的第零个元素位置插入值
/// </summary>
/// <param name="value">插入需要记录的值</param>
void STable::pushFront(STData value) {
	//空间检测
	increase();

	//结构整体向后移动
	for (long long i = (long long)this->size; i > 0; i--) {
		this->pData[i] = this->pData[i - 1];
	}

	//结构变动更新
	this->pData[0] = value;	//头部插入值
	this->size++;
	//表面值更新
	this->m_nSize = this->size;
}
/// <summary>
/// 在顺序表的第最后一个元素位置插入值
/// </summary>
/// <param name="value">插入需要记录的值</param>
void STable::pushBack(STData value) {
	//空间检测
	increase();

	//结构变动更新
	this->pData[this->size] = value;	//尾部插入值
	this->size++;
	//表面值更新
	this->m_nSize = this->size;
}
/// <summary>
/// 在指定坐标插入节点
/// <para>*节点无效时报错*</para>
/// </summary>
/// <param name="position">指定节点的坐标  /*以偏移量形式*/</param>
/// <param name="value">插入需要记录的值</param>
void STable::insert(size_t position, STData value) {
	//空间检测
	increase();

	//结构插入位置后部分向后移动
	for (long long i = (long long)this->size; i > position; i--) {
		this->pData[i] = this->pData[i - 1];
	}

	//结构变动更新
	this->pData[position] = value;	//头部插入值
	this->size++;
	//表面值更新
	this->m_nSize = this->size;
}

/// <summary>
/// 删除顺序表的第零个数据
/// <para>*无数据时报错*</para>
/// </summary>
void STable::popFront() {
	//操作有效性检测
	assert_set(this->size != 0, "无顺序表结构");

	//将第0个及之后的元素全部向前移动
	for (long long i = (long long)1; i < this->size; i++) {
		this->pData[i - 1] = this->pData[i];
	}

	//结构变动更新
	this->size--;
	//表面值更新
	this->m_nSize = this->size;
}
/// <summary>
/// 删除顺序表的最后一个数据
/// <para>*无数据时报错*</para>
/// </summary>
void STable::popBack() {
	//操作有效性检测
	assert_set(this->size != 0, "无顺序表结构");

	//结构变动更新
	this->size--;
	//表面值更新
	this->m_nSize = this->size;
}
/// <summary>
/// 在指定坐标插入节点
/// <para>*节点无效时报错*</para>
/// </summary>
/// <param name="position">指定节点的坐标  /*以偏移量形式*/</param>
void STable::del(size_t position) {
	//操作有效性检测
	assert_set(this->size != 0, "无顺序表结构");

	//将第0个及之后的元素全部向前移动
	for (long long i = (position + (long long)1); i < this->size; i++) {
		this->pData[i - 1] = this->pData[i];
	}

	//结构变动更新
	this->size--;
	//表面值更新
	this->m_nSize = this->size;
}

/// <summary>
/// 将链表中的内容打印
/// </summary>
void STable::print() {
	string strBuffer;		//最终输出缓冲区
	char szBuffer[1024];	//数值输出缓冲区

	//无数据打印
	if (this->size == 0) {
		cout << "null" << endl;
		return;
	}

	//循环遍历打印
	for (long long i = 0; i < this->size; i++) {
		sprintf(szBuffer, "%d ", this->pData[i]);
		strBuffer += szBuffer;
	}

	cout << strBuffer << endl;
}

#pragma endregion

#pragma endregion

#pragma region private

/// <summary>
/// 自动扩容
/// </summary>
void STable::increase() {
	//新的容量
	size_t newCapacity = (this->capacity != this->size)	?
		(this->capacity)								:	//表未满不扩容
		(this->capacity != 0 ? this->capacity * 2 : 4)	;	//无表或表满扩容

	//不需要扩容时返回且不操作
	if (newCapacity == this->capacity)
		return;
	else {
		//扩容
		STData* newData = (STData*)realloc(this->pData, (sizeof(STData) * newCapacity));
		assert(newData);

		//参数更新
		this->pData = newData;
		this->capacity = newCapacity;
	}
}
/// <summary>
/// 扩容
/// </summary>
/// <param name="isForce">true 时强制扩容 | false 时自动扩容</param>
void STable::increase(bool isForce) {
	//新的容量
	size_t newCapacity = this->capacity != 0 ? this->capacity * 2 : 4;
	//扩容
	STData* newData = (STData*)realloc(this->pData, (sizeof(STData) * newCapacity));
	assert(newData);

	//参数更新
	this->pData = newData;
	this->capacity = newCapacity;
}

#pragma endregion