#pragma once

typedef int SequenceTableDataType, STDataType, STData;

/// <summary>
/// ˳�����
/// <para>-������-</para>
/// <para><seealso cref="[] - �±���ʲ�����"/></para>
/// <para>-��Ա-</para>
/// <para><seealso cref="pushFront() - ͷ��"/></para>
/// <para><seealso cref="pushBack() - β��"/></para>
/// <para><seealso cref="insert() - ����"/></para>
/// <para><seealso cref="popFront() - ͷɾ"/></para>
/// <para><seealso cref="popBack() - βɾ"/></para>
/// <para><seealso cref="del() - ɾ��"/></para>
/// <para><seealso cref="print() - ��ӡ˳���"/></para>
/// <para><seealso cref="m_nSize - ˳�����Ч���ݵ�����"/></para>
/// </summary>
typedef class SequenceTable {
public:

	/*--------------------------------------//
	* �벻Ҫ���и��ĸ�ָ��ָ�������		//
	* ����ֵ�����Ĳ�Ӱ��ʵ�ʽṹ			//
	* �������ú������Ľṹ��д */			//
	size_t m_nSize;		//��Ч���ݵ�����	//
	/*--------------------------------------*/

	//TODO:���ҡ����ز�����ʹ��ʹ�÷�ʽ�ӽ�string��

#pragma region �����������

	SequenceTable();
	~SequenceTable();

#pragma endregion

#pragma region ����������

	/// <summary>
	/// �±������
	/// </summary>
	/// <param name="position">Ԫ����˳����е�λ��</param>
	/// <para>*��Ԫ��ʱ����*</para>
	/// <para>*posԽ��ʱ����*</para>
	/// <returns>��pos��Ԫ�ص�����</returns>
	STData& operator[](size_t position);

#pragma endregion

#pragma region ����˳������

	/// <summary>
	/// ��˳���ĵ����Ԫ��λ�ò���ֵ
	/// </summary>
	/// <param name="value">������Ҫ��¼��ֵ</param>
	void pushFront(STData value);
	/// <summary>
	/// ��˳���ĵ����һ��Ԫ��λ�ò���ֵ
	/// </summary>
	/// <param name="value">������Ҫ��¼��ֵ</param>
	void pushBack(STData value);
	/// <summary>
	/// ��ָ���������ڵ�
	/// <para>*�ڵ���Чʱ����*</para>
	/// </summary>
	/// <param name="position">ָ���ڵ������  /*��ƫ������ʽ*/</param>
	/// <param name="value">������Ҫ��¼��ֵ</param>
	void insert(size_t position, STData value);

	/// <summary>
	/// ɾ��˳���ĵ��������
	/// <para>*������ʱ����*</para>
	/// </summary>
	void popFront();
	/// <summary>
	/// ɾ��˳�������һ������
	/// <para>*������ʱ����*</para>
	/// </summary>
	void popBack();
	/// <summary>
	/// ��ָ���������ڵ�
	/// <para>*�ڵ���Чʱ����*</para>
	/// </summary>
	/// <param name="position">ָ���ڵ������  /*��ƫ������ʽ*/</param>
	void del(size_t position);

	/// <summary>
	/// �������е����ݴ�ӡ
	/// </summary>
	void print();

#pragma endregion

private:

	STData* pData;		//���ݴ�ŵĵ�ַ
	size_t size;		//��Ч���ݵ�����
	size_t capacity;	//ָ��ṹ�Ĵ�С
	
	/// <summary>
	/// �Զ�����
	/// </summary>
	void increase();
	/// <summary>
	/// ����
	/// </summary>
	/// <param name="isForce">true ʱǿ������ | false ʱ�Զ�����</param>
	void increase(bool isForce);

	//...
}STable;