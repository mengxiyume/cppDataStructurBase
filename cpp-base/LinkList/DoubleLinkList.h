#pragma once

//˫����洢���ݵ�����
typedef int DoubleLinkListDataType, DLData;

/// <summary>
/// ˫������
/// <para>-�ṹ-</para>
/// <para><seealso cref="node - һ������ڵ�"/></para>
/// <para>-��Ա-</para>
/// <para><seealso cref="pushFront() - ͷ��"/></para>
/// <para><seealso cref="pushBack() - β��"/></para>
/// <para><seealso cref="popFront() - ͷɾ"/></para>
/// <para><seealso cref="popBack() - βɾ"/></para>
/// <para><seealso cref="getFront() - ��ȡͷ�ڵ�"/></para>
/// <para><seealso cref="getBack() - ��ȡβ�ڵ�"/></para>
/// <para><seealso cref="print() - ��ӡ����"/></para>
/// </summary>
typedef class DoubleLinkList {
	//����һ��˫������
public:

	/// <summary>
	/// һ��������ڵ�
	/// <para>-��Ա-</para>
	/// <para><remarks>data - �ڵ��ŵ�����</remarks></para>
	/// <para><remarks>next - ��һ���ڵ�ĵ�ַ</remarks></para>
	/// </summary>
	typedef struct Node {
		DLData data;		//�ڵ��ŵ�����
		struct Node* prev;	//��һ���ڵ�ĵ�ַ
		struct Node* next;	//��һ���ڵ�ĵ�ַ
	}Node, node;

	/*--------------------------------------//
	* �벻Ҫ���и��ĸ�ָ��ָ�������		//
	* ����ֵ�����Ĳ�Ӱ��ʵ�ʽṹ			//
	* �������ú������Ľṹ��д */			//
	node* front;	//�����һ����Ч�ڵ�	//
	node* back;		//�������һ����Ч�ڵ�	//
	/*--------------------------------------*/

#pragma region �����������

	DoubleLinkList();
	~DoubleLinkList();

#pragma endregion

#pragma region �����������

	/// <summary>
	/// ������ͷ���ڵ���в���
	/// </summary>
	/// <param name="value">������Ҫ��¼��ֵ</param>
	void pushFront(DLData value);
	/// <summary>
	/// ������β���ڵ���в���
	/// </summary>
	/// <param name="value">������Ҫ��¼��ֵ</param>
	void pushBack(DLData value);

	/// <summary>
	/// ɾ������ͷ�ĵ�һ����Ч�ڵ�
	/// <para>*�޽ڵ�ʱ����*</para>
	/// </summary>
	void popFront();
	/// <summary>
	/// ɾ����������һ����Ч�ڵ�
	/// <para>*�޽ڵ�ʱ����*</para>
	/// </summary>
	void popBack();

	///// <summary>
	///// ��ȡ��ǰ����ĵ�һ����Ч�ڵ�
	///// </summary>
	///// <returns>�ڵ�ָ�� | ����Ч�ڵ�ʱ����nullptr</returns>
	//node* getFront();
	///// <summary>
	///// ��ȡ��ǰ��������һ����Ч�ڵ�
	///// </summary>
	///// <returns>�ڵ�ָ�� | ����Ч�ڵ�ʱ����nullptr</returns>
	//node* getBack();

	/// <summary>
	/// �������е����ݴ�ӡ
	/// </summary>
	void print();

#pragma endregion

}DLList;