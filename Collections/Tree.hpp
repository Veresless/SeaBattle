/**********************************************************************
 *  Project        SeaBattle ( Gen20x )
 *  (c) copyright  2020
 *  Company        Luxoft
 *  All rights reserved
 **********************************************************************/
/**
 * @file    Tree.hpp
 * @author  Kirieiev Ivan (ikirieiev@luxoft.com)
 * @brief   The Tree template class
 */

#ifndef H_TREE
#define H_TREE
#include "List.hpp"
namespace Collections
{
template<class T>
class Tree
{
    struct Node;
public:
    Tree();
    Tree(const Tree& tree);
    Tree(const Tree&& tree) noexcept;
    Tree& operator = (const Tree& tree);
    ~Tree();
    void insert(const T& data);
    template< class... Args >
    void emplace(Args&&... args);
    bool isExist(const T& data);
    bool erase(const T& data);
    List<T>& inorder(List<T>& list);
    List<T>& preorder(List<T>& list);
    List<T>& postorder(List<T>& list);
    void clear();
private:
    bool insertCont(Node *newNode, Node *head);
    bool isExistCont(const Node *root, const T& data);
    Node*  minimum(Node *node) const;
    Node*  maximum(Node *root) const;
    bool eraseCont(Node *newNode, const T& data);
    void inorderCont(List<T>& preorder, Node *node);
    void preorderCont(List<T>& preorder, Node *node);
    void postorderCont(List<T>& preorder, Node *node);
    void clearCont(Node *node);
private:
    struct Node
    {
        Node():
            left(nullptr),
            right(nullptr),
            parent(nullptr),
            value()
        {

        }
        Node(const T& value):
            left(nullptr),
            right(nullptr),
            parent(nullptr),
            value(value)
        {

        }
        Node(const Node &node):
            left(node.left),
            right(node.right),
            parent(node.parent),
            value(node.value)
        {

        }
        Node(const Node&& node):
            left(std::move(node.left)),
            right(std::move(node.right)),
            parent(std::move(node.parent)),
            value(std::move(node.value))
        {

        }
        Node* left;
        Node* right;
        Node* parent;
        T value;
    };
    Node* m_head;
};

template<class T>
Tree<T>::Tree()
    : m_head(nullptr)
{

}
template<class T>
Tree<T>::Tree(const Tree& tree)
    : m_head(nullptr)
{
    if (nullptr != tree.m_head){
            List<T> preorder = tree.preorder();

            for (T data : preorder) {
                insert(data);
            }
        }
}
template<class T>
Tree<T>::Tree(const Tree&& tree) noexcept
    : m_head(tree.m_top)
{
    tree.m_top = nullptr;
}
template<class T>
Tree<T>& Tree<T>::operator = (const Tree& tree)
{
    if (this == &tree) {
        return tree;
    }

    clear();

    if (nullptr != tree.m_head){
        List<T> preorder = tree.preorder();

        for (T data : preorder) {
            insert(data);
        }
    }
}
template<class T>
Tree<T>::~Tree()
{
    clear();
}
template<class T>
void Tree<T>::insert(const T& data)
{
    Node *newNode = new Node(data);
    if (nullptr == m_head)
    {
        m_head = newNode;
    }
    else
    {
        if (false == insertCont(newNode, m_head))
        {
            delete newNode;
        }
    }
}
template<class T>
template< class... Args >
void Tree<T>::emplace(Args&&... args)
{
    Node *newNode = new Node(args...);
    if (nullptr == m_head)
    {
        m_head = newNode;
    }
    else
    {
        if (false == insertCont(newNode, m_head))
        {
            delete newNode;
        }
    }
}
template<class T>
bool Tree<T>::insertCont(Node *newNode, Node* head)
{
    if (newNode->value > head->value)
    {
        if (head->right == nullptr)
        {
            head->right = newNode;
            head->right->parent = head;
            return true;
        }
        else
        {
            head = head->right;
            return insertCont(newNode, head);
        }
    }
    else if (newNode->value < head->value)
    {
        if (head->left == nullptr)
        {
            head->left = newNode;
            head->left->parent = head;
            return true;
        }
        else
        {
            head = head->left;
            return insertCont(newNode, head);
        }

    }
    else
    {
        return false;
    }
}
template<class T>
bool Tree<T>::erase(const T& data)
{
    return eraseCont(m_head, data);
}
template<class T>
typename Tree<T>::Node* Tree<T>::minimum(Node *root) const
{
    if (nullptr == root->left) return root;
    return minimum(root->left);
}
template<class T>
typename Tree<T>::Node*  Tree<T>::maximum(Node *root) const
{
    if (nullptr == root->right) return root;
    return minimum(root->right);
}
template<class T>
bool Tree<T>::eraseCont(Node *root, const T& data)
{
    if (nullptr == root)
    {
        return false;
    }
    //std::cout << root->value << std::endl;
    if (data < root->value)
    {
        return eraseCont(root->left, data);
    }
    else if (data > root->value)
    {
        return eraseCont(root->right, data);
    }
    else 
    {
		if (nullptr == root->left && nullptr == root->right)
		{
			if (nullptr != root->parent)
			{
                if (nullptr != root->parent->left && root->value == root->parent->left->value)
                {
                    root->parent->left = nullptr;
                }
				else
				if (nullptr != root->parent->right && root->value == root->parent->right->value)
				{
					root->parent->right = nullptr;
				}
			}
            else
            {
                m_head = nullptr;
            }
            
			delete root;
			
		}
		else if (nullptr != root->left && nullptr != root->right)
		{
			Node * newHead = minimum(root->right);
			root->value = newHead->value;
			eraseCont(newHead, newHead->value);
		}
		else
		{
			if (nullptr != root->left)
			{
				root->left->parent = root->parent;
				if (nullptr != root->parent)
				{
					if (nullptr != root->parent->left && root->value == root->parent->left->value)
					{
						root->parent->left = root->left;
					}
					else
					if (nullptr != root->parent->right && root->value == root->parent->right->value)
					{
						root->parent->right = root->left;
					}
				}
                else
                {
                    m_head = root->left;
                }
                
			}
            else if (nullptr != root->right)
            {
                root->right->parent = root->parent;
                if (nullptr != root->parent)
                {
                    if (nullptr != root->parent->left && root->value == root->parent->left->value)
                    {
                        root->parent->left = root->right;
                    }
                    else
                    if (nullptr != root->parent->right && root->value == root->parent->right->value)
                    {
                        root->parent->right = root->right;
                    }
                }
                else
                {
                    m_head = root->right;
                }
            }
            delete root;
        }
        return true;
    }
}
template<class T>
bool Tree<T>::isExist(const T& data)
{
    return isExistCont(m_head, data);
}

template<class T>
bool Tree<T>::isExistCont(const Node *root, const T& data)
{
    if (nullptr == root)
    {
        return false;
    }
    if (data < root->value)
    {
        return isExistCont(root->left, data);
    }
    else if (data > root->value)
    {
        return isExistCont(root->right, data);
    }
    else return true;
}
template<typename T>
List<T>& Tree<T>::inorder(List<T>& inorder)
{
	inorder.clear();
    inorderCont(inorder, m_head);
    return inorder;
}

template<typename T>
void Tree<T>::inorderCont(List<T>& inorder, Node* node)
{
    if (nullptr != node) {
        inorderCont(inorder, node->left);
        inorder.push_back(node->value);
        inorderCont(inorder, node->right);
    }
}

template<typename T>
List<T>& Tree<T>::preorder(List<T>& preorder)
{
    preorder.clear();
    preorderCont(preorder, m_head);
    return preorder;
}

template<typename T>
void Tree<T>::preorderCont(List<T>& preorder, Node *node) {
    if (nullptr != node) {
        preorder.push_back(node->value);
        preorderCont(preorder, node->left);
        preorderCont(preorder, node->right);
    }
}

template<typename T>
List<T>& Tree<T>::postorder(List<T>& postorder)
{
	postorder.clear();
    postorderCont(postorder, m_head);
    return postorder;
}

template<typename T>
void Tree<T>::postorderCont(List<T>& postorder, Node *node) {
    if (nullptr != node) {
        postorderCont(postorder, node->lefta);
        postorderCont(postorder, node->right);
        postorder.push_back(node->value);
    }
}
template<typename T>
void Tree<T>::clear()
{
    clearCont(m_head);
}
template<typename T>
void Tree<T>::clearCont(Node *node)
{
    if (nullptr != node)
    {
        clearCont(node->left);
        clearCont(node->right);
        delete node;
    }
}
}
#endif
