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

	//TODO:���롢ɾ�������ҡ���ӡ�����졢���������� [ ] �����������ز�����ʹ��ʹ�÷�ʽ�ӽ�string��

	/// <summary>
	/// ��ȡ˳���ĵ�pos��Ԫ��
	/// </summary>
	/// <param name="position">Ԫ����˳����е�λ��</param>
	/// <para>*��Ԫ��ʱ����*</para>
	/// <para>*posԽ��ʱ����*</para>
	/// <returns>��pos��Ԫ�ص�����</returns>
	STData& operator[](size_t position);

	//...
}STable;