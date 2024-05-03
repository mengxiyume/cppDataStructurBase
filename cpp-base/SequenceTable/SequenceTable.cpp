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

#pragma region �����������

STable::SequenceTable() {

	//�ṹ���Ƴ�ʼ��
	this->pData		= nullptr;
	this->size		= 0;
	this->capacity	= 0;
	//����ֵ��ʼ��
	this->m_nSize	= 0;
}
STable::~SequenceTable() {

	//�ռ��ͷ�
	if (this->pData != nullptr) {
		free(this->pData);
	}
	//�ṹ���Ƴ�ʼ��
	this->pData		= nullptr;
	this->capacity	= 0;
	this->size		= 0;
	//����ֵ��ʼ��
	this->m_nSize	= 0;
}

#pragma endregion

#pragma region ����������

/// <summary>
/// �±������
/// </summary>
/// <param name="position">Ԫ����˳����е�λ�� /*�±���ʽ*/</param>
/// <para>*��Ԫ��ʱ����*</para>
/// <para>*posԽ��ʱ����*</para>
/// <returns>��pos��Ԫ�ص�����</returns>
STData& STable::operator[](size_t position) {
	assert_set(this->pData, "�ṹ������");
	assert_set(position < this->size, "�±�Խ��");

	return this->pData[position];
}

#pragma endregion

#pragma region ����˳������

/// <summary>
/// ��˳���ĵ����Ԫ��λ�ò���ֵ
/// </summary>
/// <param name="value">������Ҫ��¼��ֵ</param>
void STable::pushFront(STData value) {
	//�ռ���
	increase();

	//�ṹ��������ƶ�
	for (long long i = (long long)this->size; i > 0; i--) {
		this->pData[i] = this->pData[i - 1];
	}

	//�ṹ�䶯����
	this->pData[0] = value;	//ͷ������ֵ
	this->size++;
	//����ֵ����
	this->m_nSize = this->size;
}
/// <summary>
/// ��˳���ĵ����һ��Ԫ��λ�ò���ֵ
/// </summary>
/// <param name="value">������Ҫ��¼��ֵ</param>
void STable::pushBack(STData value) {
	//�ռ���
	increase();

	//�ṹ�䶯����
	this->pData[this->size] = value;	//β������ֵ
	this->size++;
	//����ֵ����
	this->m_nSize = this->size;
}
/// <summary>
/// ��ָ���������ڵ�
/// <para>*�ڵ���Чʱ����*</para>
/// </summary>
/// <param name="position">ָ���ڵ������  /*��ƫ������ʽ*/</param>
/// <param name="value">������Ҫ��¼��ֵ</param>
void STable::insert(size_t position, STData value) {
	//�ռ���
	increase();

	//�ṹ����λ�ú󲿷�����ƶ�
	for (long long i = (long long)this->size; i > position; i--) {
		this->pData[i] = this->pData[i - 1];
	}

	//�ṹ�䶯����
	this->pData[position] = value;	//ͷ������ֵ
	this->size++;
	//����ֵ����
	this->m_nSize = this->size;
}

/// <summary>
/// ɾ��˳���ĵ��������
/// <para>*������ʱ����*</para>
/// </summary>
void STable::popFront() {
	//������Ч�Լ��
	assert_set(this->size != 0, "��˳���ṹ");

	//����0����֮���Ԫ��ȫ����ǰ�ƶ�
	for (long long i = (long long)1; i < this->size; i++) {
		this->pData[i - 1] = this->pData[i];
	}

	//�ṹ�䶯����
	this->size--;
	//����ֵ����
	this->m_nSize = this->size;
}
/// <summary>
/// ɾ��˳�������һ������
/// <para>*������ʱ����*</para>
/// </summary>
void STable::popBack() {
	//������Ч�Լ��
	assert_set(this->size != 0, "��˳���ṹ");

	//�ṹ�䶯����
	this->size--;
	//����ֵ����
	this->m_nSize = this->size;
}
/// <summary>
/// ��ָ���������ڵ�
/// <para>*�ڵ���Чʱ����*</para>
/// </summary>
/// <param name="position">ָ���ڵ������  /*��ƫ������ʽ*/</param>
void STable::del(size_t position) {
	//������Ч�Լ��
	assert_set(this->size != 0, "��˳���ṹ");

	//����0����֮���Ԫ��ȫ����ǰ�ƶ�
	for (long long i = (position + (long long)1); i < this->size; i++) {
		this->pData[i - 1] = this->pData[i];
	}

	//�ṹ�䶯����
	this->size--;
	//����ֵ����
	this->m_nSize = this->size;
}

/// <summary>
/// �������е����ݴ�ӡ
/// </summary>
void STable::print() {
	string strBuffer;		//�������������
	char szBuffer[1024];	//��ֵ���������

	//�����ݴ�ӡ
	if (this->size == 0) {
		cout << "null" << endl;
		return;
	}

	//ѭ��������ӡ
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
/// �Զ�����
/// </summary>
void STable::increase() {
	//�µ�����
	size_t newCapacity = (this->capacity != this->size)	?
		(this->capacity)								:	//��δ��������
		(this->capacity != 0 ? this->capacity * 2 : 4)	;	//�ޱ���������

	//����Ҫ����ʱ�����Ҳ�����
	if (newCapacity == this->capacity)
		return;
	else {
		//����
		STData* newData = (STData*)realloc(this->pData, (sizeof(STData) * newCapacity));
		assert(newData);

		//��������
		this->pData = newData;
		this->capacity = newCapacity;
	}
}
/// <summary>
/// ����
/// </summary>
/// <param name="isForce">true ʱǿ������ | false ʱ�Զ�����</param>
void STable::increase(bool isForce) {
	//�µ�����
	size_t newCapacity = this->capacity != 0 ? this->capacity * 2 : 4;
	//����
	STData* newData = (STData*)realloc(this->pData, (sizeof(STData) * newCapacity));
	assert(newData);

	//��������
	this->pData = newData;
	this->capacity = newCapacity;
}

#pragma endregion