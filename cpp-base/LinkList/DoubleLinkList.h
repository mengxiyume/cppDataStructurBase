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
/// <para><seealso cref="insert() - ����"/></para>
/// <para><seealso cref="popFront() - ͷɾ"/></para>
/// <para><seealso cref="popBack() - βɾ"/></para>
/// <para><seealso cref="del() - ɾ��"/></para>
/// <para><seealso cref="getPos() - ��ȡָ���ڵ�"/></para>
/// <para><seealso cref="print() - ��ӡ����"/></para>
/// <para><seealso cref="front - �����һ����Ч�ڵ�"/></para>
/// <para><seealso cref="back - �������һ����Ч�ڵ�"/></para>
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
	/// ��ָ���ڵ���������
	/// <para>*�ڵ���Чʱ����*</para>
	/// </summary>
	/// <param name="prev">ָ���ڵ��ָ�� | nullptr ����������������ڵ�</param>
	/// <param name="value">������Ҫ��¼��ֵ</param>
	void insert(node* prev, DLData value);
	/// <summary>
	/// ��ָ���������ڵ�
	/// <para>*������Чʱ����*</para>
	/// </summary>
	/// <param name="position">ָ���ڵ������  /*��ƫ������ʽ*/</param>
	/// <param name="value">������Ҫ��¼��ֵ</param>
	void insert(size_t position, DLData value);

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
	/// <summary>
	/// ɾ��ָ���ڵ�
	/// <para>*�ڵ���Чʱ����*</para>
	/// </summary>
	/// <param name="delNode">ָ���ڵ��ָ��</param>
	void del(node* delNode);
	/// <summary>
	/// ɾ��ָ���ڵ�
	/// <para>*������Чʱ����*</para>
	/// </summary>
	/// <param name="position">ָ���ڵ������  /*��ƫ������ʽ*/</param>
	void del(size_t position);

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
	/// ��ȡָ���ڵ�
	/// <para>*������Чʱ����*</para>
	/// </summary>
	/// <param name="position">�ڵ������ /*��ƫ������ʽ*/</param>
	/// <returns></returns>
	node* getPos(size_t position);

	/// <summary>
	/// �������е����ݴ�ӡ
	/// </summary>
	void print();

#pragma endregion

}DLList;