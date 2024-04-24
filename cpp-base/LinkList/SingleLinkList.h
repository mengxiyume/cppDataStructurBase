#pragma once

//˫����洢���ݵ�����
typedef int SingleLinkListDataType, SLData;

/// <summary>
/// ��������
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
/// <para><seealso cref="m_pFront - �����һ����Ч�ڵ�"/></para>
/// <para><seealso cref="m_pBack - �������һ����Ч�ڵ�"/></para>
/// <para><seealso cref="m_nSize - ������Ч�ڵ������"/></para>
/// </summary>
typedef class SingleLinkList {
	//����һ����������
public:

	/// <summary>
	/// һ��������ڵ�
	/// <para>-��Ա-</para>
	/// <para><remarks>data - �ڵ��ŵ�����</remarks></para>
	/// <para><remarks>next - ��һ���ڵ�ĵ�ַ</remarks></para>
	/// </summary>
	typedef struct Node {
		SLData data;		//�ڵ��ŵ�����
		struct Node* next;	//��һ���ڵ�ĵ�ַ
	}Node, node;

	/*--------------------------------------//
	* �벻Ҫ���и��ĸ�ָ��ָ�������		//
	* ����ֵ�����Ĳ�Ӱ��ʵ�ʽṹ			//
	* �������ú������Ľṹ��д */			//
	node* m_pFront;	//�����һ����Ч�ڵ�	//
	node* m_pBack;	//�������һ����Ч�ڵ�	//
	size_t m_nSize;	//������Ч�ڵ������	//
	/*--------------------------------------*/

#pragma region �����������

	SingleLinkList();
	~SingleLinkList();

#pragma endregion

#pragma region �����������

	/// <summary>
	/// ������ͷ���ڵ���в���
	/// </summary>
	/// <param name="value">������Ҫ��¼��ֵ</param>
	void pushFront(SLData value);
	/// <summary>
	/// ������β���ڵ���в���
	/// </summary>
	/// <param name="value">������Ҫ��¼��ֵ</param>
	void pushBack(SLData value);
	/// <summary>
	/// ��ָ���ڵ�ǰ��������
	/// <para>*�ڵ���Чʱ����*</para>
	/// </summary>
	/// <param name="prev">ָ���ڵ��ָ�� | nullptr ����������������ڵ�</param>
	/// <param name="value">������Ҫ��¼��ֵ</param>
	void insert(node* next, SLData value);
	/// <summary>
	/// ��ָ���������ڵ�
	/// <para>*������Чʱ����*</para>
	/// </summary>
	/// <param name="position">ָ���ڵ������  /*��ƫ������ʽ*/</param>
	/// <param name="value">������Ҫ��¼��ֵ</param>
	void insert(size_t position, SLData value);

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

private:

	node* pHead = nullptr;		//����ͷ
	node* pFront = nullptr;		//�����һ����Ч�ڵ�
	node* pBack = nullptr;		//�������һ����Ч�ڵ�
	size_t nodeCount = 0;		//������Ч�ڵ������

	/// <summary>
	/// ����һ������ڵ�
	/// <para>*����ʧ�ܱ���*</para>
	/// </summary>
	/// <returns>������Ľڵ�</returns>
	node* buyOneNode();

}SLList;