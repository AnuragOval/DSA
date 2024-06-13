#include"BSTreeNode.h"

BSTNode::BSTNode(int data)
{
	m_data = data;
	m_left = nullptr;
	m_right = nullptr;
}




/*
	BST Operatins Implementation.
*/

BSTOperations::BSTOperations()
{
	m_root = nullptr;
}

BSTOperations::~BSTOperations()
{
	makeEmpty(m_root);
}

void BSTOperations::makeEmpty(BSTNode*& Node)
{
	if (Node!=nullptr)
	{
		makeEmpty(Node->m_left);
		makeEmpty(Node->m_right);
		cout << "Destorying " << Node->m_data<<std::endl;
		delete Node;
		Node = nullptr;
	}
	//Node = nullptr;

	/*if (!Node) return;
	makeEmpty(Node->m_left);
	makeEmpty(Node->m_right);
	delete Node;
	Node = nullptr;*/

	//if (Node == nullptr)
	//	return;

	//// recursion
	//makeEmpty(Node->m_left);  // L
	//makeEmpty(Node->m_right); // R

	//delete Node;            // N
	//Node = nullptr;
}
BSTOperations::BSTOperations(const BSTOperations& rhs)
{
	//m_root = clone(rhs.m_root);
	m_root = copyHelper(rhs.m_root);
}



BSTNode* BSTOperations::copyHelper(BSTNode* src)
{
	if (src == nullptr)
	{
		return nullptr;
	}
	BSTNode* newNode = new BSTNode(src->m_data);
	newNode->m_left = copyHelper(src->m_left);
	newNode->m_right = copyHelper(src->m_right);

	return newNode;
}

BSTNode* BSTOperations::clone(BSTNode* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	else
	{
		return new BSTNode(node->m_data, clone(node->m_left), clone(node->m_right));
	}
}

BSTOperations& BSTOperations::operator=(const BSTOperations& rhs)
{
	using std::swap;
	BSTOperations temp(rhs);
	swap(temp.m_root,m_root);
	return *this;
}


BSTOperations::BSTOperations(BSTOperations&& source) noexcept
{
	m_root = source.m_root;
	source.m_root = nullptr;
}

BSTOperations& BSTOperations::operator=(BSTOperations&& source) noexcept
{
	using std::swap;
	swap(m_root, source.m_root);

	return *this;
}


void BSTOperations::insert(int data)
{
	BSTNode* newNde = new BSTNode(data);
	BSTNode* parent = nullptr;
	if (m_root == nullptr)
	{
		m_root = newNde;
		return;
	}
	BSTNode* current = m_root;
	while (current!=nullptr)
	{
		if (data < current->m_data)
		{
			cout << "In Left";
			if (current->m_left == nullptr)
			{
				current->m_left = newNde;
				break;
			}
			else
			{
				current = current->m_left;
			}
		}
		if (data > current->m_data)
		{
			cout << "In Right";
			if (current->m_right == nullptr)
			{
				cout << "Inserting at rght";
				current->m_right = newNde;
				break;
			}
			else
			{
				current = current->m_right;
			}
		}
	}
	//while (current!=nullptr)
	//{
	//	if (data < current->m_data)
	//	{
	//		if (current->m_left == nullptr)
	//		{
	//			current->m_left = newNde;
	//			break;
	//		}
	//		else
	//		{
	//			current = current->m_left;
	//		}
	//			
	//	}
	//	if (data > current->m_data)
	//	{
	//		if (current->m_right == nullptr)
	//		{
	//			current->m_right = newNde;
	//			break;
	//		}
	//		else
	//		{
	//			current = current->m_right;
	//		}
	//	}
	//}
}

BSTNode* BSTOperations::getRoot()
{
	return m_root;
}

void BSTOperations::preorder(BSTNode* Node)
{
	if (Node == nullptr)
		return;
	cout << Node->m_data<<std::endl;
	preorder(Node->m_left);
	preorder(Node->m_right);
}

void BSTOperations::inorder(BSTNode* Node)
{
	if (Node==nullptr)
	{
		return;
	}
	inorder(Node->m_left);
	cout << Node->m_data<<std::endl;
	inorder(Node->m_right);
}

void BSTOperations::PostOrder(BSTNode* Node)
{
	if (Node == nullptr)
	{
		return;
	}
	PostOrder(Node->m_left);
	PostOrder(Node->m_right);
	cout << Node->m_data<<std::endl;
}