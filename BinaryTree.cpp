#pragma once
#include<iostream>
using namespace std;
template <class T>
struct BinaryTreeNode
{
	BinaryTreeNode(const T &data)
	:_data(data)
	, _pLeft(NULL)
	, pRight(NULL)
	{}
	T _data;
	BinaryTreeNode<T> *_pLeft;
	BinaryTreeNode<T> *_pRight;
};

template <class T>
class BinaryTree
{
public:
	BinaryTree()
	:_pRoot(NULL)
	{}

	BinaryTree(const T arr[], size_t size)
	{
		size_t index = 0;
		_CreatTree(_pRoot, arr, size, index);
		cout << _pRoot->_data << "";
	}

	BinaryTree(const BinaryTree<T> &t)
	{
		_pRoot_Copy(t._pRoot);
	}
	//ע�ⷵ�ص��������Լ���󷵻ص���*this������Ĳ���Ҫ��const���Σ�����Ƿ������ֵ
	BinaryTree& operator=(const BinaryTree<T> &t)
	{
		if (this != &t)
		{
			_Distory(_pRoot);
			_pRoot = _Copy(t._pRoot);
		}
		return *this;
	}

	~BinaryTree()
	{
		_Distory(_pRoot);
	}

	//�������  ������
	void _PreOrder(BinaryTreeNode<T>* &pRoot)
	{
		if (pRoot)
		{
			cout << pRoot->_data << " ";
			_PreOrder(pRoot->_pLeft);
			_PreOrder(pRoot->_pRight);
		}
	}


private:
	//�˴����δ�����ʱ��ΪҪ�ı�_proot��ָ�����Դ���Ҫ������ָ���һ��ָ�������
	//���˴���index��������ʱ��Ϊ��ÿ����Ϊ������������ȥ��ʱ���Ѿ�++��
	void _CreateTree(BinaryTreeNode<T>* &pRoot, const T arr[], size_t size, size_t index)
	{
		if (index<size&&arr[index]!='#')
		{
			pRoot = new BinaryTreeNode<T>(arr[index]);
			_CreateTree(pRoot->_pLeft, arr, size, ++index);
			_CreateTree(pRoot->_pRight, arr, size, ++index);
		}
	}
	//�ȶ���һ����ʱ������Ȼ��������ڵ���ڵĻ��ͽ���ݹ飬Ȼ��ֱ��ø��ڵ�ָ���������ҽڵ�
	BinaryTreeNode<T>*  _Copy(BinaryTreeNode<T>* pRoot)
	{
		BinaryTreeNode<T>* newRoot = NULL;
		if (pRoot)
		{
			newRoot = new BinaryTreeNode<T>(pRoot->_data);
			newRoot->_pLeft = _Copy(pRoot->_pLeft);
			newRoot->_pRight = _Copy(pRoot->_pRight);
		}
		return newRoot;
	}
	//���ٵ�ʱ��ֱ�ӽ����ڵ㴫����������������ΪҪ�����ڵ��ָ��ı�
	void _Destory(BinaryTreeNode<T>* &pRoot)
	{
		if (pRoot)
		{
			_Distory(pRoot->pLeft);
			_Distory(pRoot->pRight);
			delete pRoot;
			pRoot = NULL;
		}
	}


private:
	BinaryTreeNode<T>* _pRoot;
};

void test()
{
	char arr[9] = { '0', '1', '3', '4', '#', '#', '2', '5', '#' };
	BinaryTree<char> b(const char arr[],sizeof(arr) / sizeof(arr[0]));
	
}
int main()
{
	test();
}