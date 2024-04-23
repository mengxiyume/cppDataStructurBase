#define _CRT_SECURE_NO_WARNINGS

#include "SequenceTable.h"

STData* data;		//数据存放的地址
size_t size;		//有效数据的数量
size_t capacity;	//指针结构的大小
size_t front;		//第一个有效数据的偏移量
size_t back;		//最后一个有效数据的偏移量