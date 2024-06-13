#pragma once
#include<iostream>
using namespace std;
class BSTNode
{
public:
	int m_data{0};
	BSTNode* m_left{ nullptr };
	BSTNode* m_right{ nullptr };
	BSTNode(int data);
	BSTNode() = default;
	BSTNode(int data, BSTNode* left, BSTNode* right) :
		m_data{ data }, m_left{ left }, m_right{ right } {};

};




class BSTOperations
{
public:
	
	void insert(int data);
	void preorder(BSTNode* Node);
	void inorder(BSTNode* Node);
	void PostOrder(BSTNode* Node);
	BSTNode* getRoot();
	BSTOperations();
	~BSTOperations();
	void makeEmpty(BSTNode*& Node);
	BSTOperations(const BSTOperations& rhs);
	BSTOperations& operator=(const BSTOperations& rhs);
	BSTNode* clone(BSTNode * node);
	BSTNode* copyHelper(BSTNode * node);
	BSTOperations(BSTOperations&&) noexcept;
	BSTOperations& operator=(BSTOperations&&) noexcept;
	
private:
	BSTNode* m_root{ nullptr };
	
	
};




