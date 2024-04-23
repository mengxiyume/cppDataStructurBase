#pragma once

//�������ͼ���Ӧָ������
typedef int SingleLinkListDataType, * pSingleLinkListDataType, SLData, * pSLData;

typedef class SingleLinkList {
	//����һ��������
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
	/// ��ȡ��ǰ����ĵ�һ����Ч�ڵ�
	/// </summary>
	/// <returns>�ڵ�ָ�� | ����Ч�ڵ�ʱ����nullptr</returns>
	node* getFront();
	/// <summary>
	/// ��ȡ��ǰ��������һ����Ч�ڵ�
	/// </summary>
	/// <returns>�ڵ�ָ�� | ����Ч�ڵ�ʱ����nullptr</returns>
	node* getBack();

	/// <summary>
	/// �������е����ݴ�ӡ
	/// </summary>
	void print();
#pragma endregion

private:
	node* pHead;	//����ͷ
	node* pFront;	//�����һ����Ч�ڵ�
	node* pBack;	//�������һ����Ч�ڵ�

	/// <summary>
	/// ����һ������ڵ�
	/// <para>*����ʧ�ܱ���*</para>
	/// </summary>
	/// <returns>������Ľڵ�</returns>
	node* buyOneNode();
}SLList, *pSLList;