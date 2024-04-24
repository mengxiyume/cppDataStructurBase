#pragma once

typedef int SequenceTableDataType, STDataType, STData;

typedef class SequenceTable {
	//TODO:���ݼ��ӿڵĶ���
public:

		/*--------------------------------------//
	* �벻Ҫ���и��ĸ�ָ��ָ�������		//
	* ����ֵ�����Ĳ�Ӱ��ʵ�ʽṹ			//
	* �������ú������Ľṹ��д */			//
	size_t size;		//��Ч���ݵ�����	//
	/*--------------------------------------*/

	//TODO:���롢ɾ�������ҡ���ӡ�����졢���������� [ ] �±�����������ز�����ʹ��ʹ�÷�ʽ�ӽ�string��

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
	void insert(size_t position, DLData value);

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
	/// �������е����ݴ�ӡ
	/// </summary>
	void print();

#pragma endregion

	//...
}STable;