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
	//注意返回的是引用以及最后返回的是*this，传入的参数要加const修饰，检测是否给自身赋值
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

	//先序遍历  根左右
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
	//此处传参传引用时因为要改变_proot的指向，所以传参要传二级指针或传一级指针的引用
	//而此处的index不传引用时因为他每次作为函数参数传进去的时候已经++了
	void _CreateTree(BinaryTreeNode<T>* &pRoot, const T arr[], size_t size, size_t index)
	{
		if (index<size&&arr[index]!='#')
		{
			pRoot = new BinaryTreeNode<T>(arr[index]);
			_CreateTree(pRoot->_pLeft, arr, size, ++index);
			_CreateTree(pRoot->_pRight, arr, size, ++index);
		}
	}
	//先定义一个临时变量，然后如果根节点存在的话就进入递归，然后分别让根节点指向他的左右节点
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
	//销毁的时候直接将根节点传过来，传引用是因为要将跟节点的指向改变
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