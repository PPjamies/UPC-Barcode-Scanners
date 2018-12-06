/*
 * BinarySearchTree.h
 *
 *  Created on: Nov 20, 2018
 *      Author: Pazuz
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include <iostream>
using namespace std;

template <class T>
struct node{
	T data;
	node<T>* left;
	node<T>* right;
};

template <class T>
class BinarySearchTree{
public:
	BinarySearchTree();
	void printInOrder(){
		printInOrder(root);
	}
	void printPreOrder(){
		printPreOrder(root);
	}
	void printPostOrder(){
		printPostOrder(root);
	}
	int height(){
		return height(root);
	}
	void insert(T& item){
		insert(root, item);
	}
	bool search(T& item){
		return search(root,item);
	}
	T findMax(T& e){
		return findMax(root,e);
	}
	T findMin(T& e){
		return findMin(root,e);
	}
	void deletenode(T& item){
		deletenode(root, item);
	}
	~BinarySearchTree(){
		destroy(root);
	}

private:
	node<T>* root;
	void printInOrder(node<T>*);
	void printPreOrder(node<T>*);
	void printPostOrder(node<T>*);
	void destroy(node<T>*);
	int height(node<T>*);
	int max(int, int);
	void insert(node<T>*&, T&);
	bool search(node<T>*, T&);
	T findMax(node<T>*,T&);
	T findMin(node<T>*, T&);
	void deletenode(node<T>*&, T&);
};


template <class T>
BinarySearchTree<T>::BinarySearchTree(){
	root = NULL;
}

template <class T>
void BinarySearchTree<T>::printInOrder(node<T>* p){
	if(p!=NULL){
		printInOrder(p->left);
		cout<<p->data<<" ";
		printInOrder(p->right);
	}
}

template <class T>
void BinarySearchTree<T>::printPreOrder(node<T>* p){
	if(p!=NULL){
		cout<<p->data<<" ";
		printPreOrder(p->left);
		printPreOrder(p->right);
	}
}

template <class T>
void BinarySearchTree<T>::printPostOrder(node<T>* p){
	if(p!=NULL){
		printPostOrder(p->left);
		printPostOrder(p->right);
		cout<<p->data<<" ";
	}
}
template <class T>
int BinarySearchTree<T>::max(int x, int y){
	if (x>y)
		return x;
	return y;
}

template <class T>
int BinarySearchTree<T>::height(node<T>* p){
	if(p!=NULL){
		return 1 + max(height(p->left), height(p->right));
	}
	return -1;
}

template <class T>
void BinarySearchTree<T>::destroy(node<T>* p){
	if(p!= NULL){
		destroy(p->left);
		destroy(p->right);
		delete p;
		p= NULL;
	}
}

template <class T>
void BinarySearchTree<T>::insert(node<T>*& p, T& item){
	if(p == NULL){
		p = new node<T>;
		p->data = item;
		p->left = p->right = NULL;
	}
	else if(item<p->data){
		insert(p->left, item);
	}else{
		insert(p->right, item);
	}
}

template <class T>
bool BinarySearchTree<T>::search(node<T>* p, T& item){
	if(p == NULL)
		return false;
	else if(item<p->data)
		return search(p->left, item);
	else if(item>p->data)
		return search(p->right, item);
	else
		return true;
}

template <class T>
T BinarySearchTree<T>::findMax(node<T>* p, T& e){
	if (p==NULL)
		return e;
	else if(p->right == NULL)
		return p->data;
	else
		return findMax(p->right,e);
}

template <class T>
T BinarySearchTree<T>::findMin(node<T>* p, T& e){
	if (p==NULL)
		return e;
	else if(p->left == NULL)
		return p->data;
	else
		return findMin(p->left,e);
}

template <class T>
void BinarySearchTree<T>::deletenode(node<T>*& p, T& item){
	//item not found, do nothing
	if(p == NULL)
		return;
	else if (item<p->data)	//item is on the left subtree
		deletenode(p->left, item);
	else if (item>p->data)	//item is on the right subtree
		deletenode(p->right, item);
    else{//item is equal to data,  it is found
		if(p->left!= NULL && p->right != NULL){// with two children
			int e=-1;
			p->data = findMax(p->left,e);
			deletenode(p->left, p->data);
		}else{
			node<T>* old = p;
			if(p->left != NULL)
				p = p->left;
			else
				p = p->right;

			delete old;
		}
	}
}

#endif /* BINARYSEARCHTREE_H_ */
