/*
 * HashTable.h
 *
 *  Created on: Dec 2, 2018
 *      Author: Pazuz
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

template <class T>
struct HashNode{
	T data;
	HashNode<T>* next;
};

const int hashTableSize = 1000;

template <class T>
class HashTable{
	protected:
		int tableSize;
		HashNode<T>* hashTable[hashTableSize];
	public:
		HashTable();	//constructor
		HashTable(HashTable<T>&);	//copy constructor
		int hashFunction(T& item);
		void put(T& item);
		T get(T& item);
		void remove(T& key);
		void destroyHashTable();
		void copyTable(HashTable<T>&);
		HashTable<T>& operator=(HashTable<T>&);
		template <class S>
			friend ostream& operator<<(ostream& os, const HashTable<S>& hTable);
			~HashTable();
};
template <class T>
HashTable<T>::HashTable(){		//constructor
	tableSize = hashTableSize;
	for(int i=0; i<tableSize; i++){
		hashTable[i] = NULL;
	}
}
template <class T>
HashTable<T>::HashTable(HashTable<T>& other){	//copy constructor
	copyTable(other);
}
template <class T>
int HashTable<T>::hashFunction(T& item){
	int hashVal = item.getHashCode();
	hashVal %=tableSize;
	if (hashVal < 0){  /* in case overflows occurs */
		hashVal += tableSize;
	}
	return hashVal;
}
template <class T>
void HashTable<T>::put(T& item){

	//create newNode
	HashNode<T>* newNode = new HashNode<T>;
	newNode->data = item;
	newNode->next = NULL;

	//Retrieve hashValue
	int hashVal = hashFunction(item);

	//insert
	if(hashTable[hashVal] == NULL){				//empty
		hashTable[hashVal] = newNode;
	}else{	//not NULL
		HashNode<T>* p = hashTable[hashVal]; 		//p points to first hashNode
		while(p!= NULL && p->data != item){
			p=p->next;
		}
		if(p == NULL){	//insert last
			p->next = newNode;
		}else if(p->data == item){
			cerr<<"Key already exists"<<endl;
		}
	}
}
template <class T>
T HashTable<T>::get(T& item){
	int hashVal = hashFunction(item);
	if(hashTable[hashVal] == NULL){
		cerr<<"Key does not exist"<<endl;
	}else{
		HashNode<T>* p = hashTable[hashVal];
		while(p!= NULL && p->data != item){
			p=p->next;
		}
		if(p==NULL){
			cerr<<"Key does not exist"<<endl;
		}else if(p->data == item){
			return p->data;
		}
	}
}
template <class T>
void HashTable<T>::remove(T& item){
	int hashVal = hashFunction(item);
	if(hashTable[hashVal] == NULL){
		cerr<<"Key does not exist"<<endl;
	}else{
		HashNode<T>* p = hashTable[hashVal];
		HashNode<T>* temp = NULL;
		while(p!= NULL && p->data != item){
			if(p->next->data == item){
				temp = p;
			}
			p=p->next;
		}
		if(p==NULL){	//key not found
			cerr<<"Key does not exist"<<endl;
		}else if(p->data == item){	//key found
			if(temp != NULL){	//key is in middle or last
				if(p->next != NULL){ //delete p from middle
					temp->next = p->next;
					delete p;
				}else{	//delete p from end
					temp->next = NULL;
					delete p;
				}
			}else{	//key is first
				delete p;
				hashTable[hashVal] = NULL;
			}
		}
	}
}

template <class T>
ostream& operator<<(ostream& os, const HashTable<T>& hTable){
	int otherSize = hTable.tableSize;
	for(int i=0; i<otherSize; i++){
		HashNode<T>* p = hTable.hashTable[i];
		while(p!=NULL){
			os<<p->data;
			p=p->next;
		}
	}
	return os;
}
/****************************************************BIG 3**************************************************************************************************/
template <class T>
HashTable<T> &HashTable<T>:: operator=(HashTable<T> &table){
	if (this != &table) {
		copyTable(table);
	}
	return *this;
}
template <class T>
void HashTable<T>::copyTable(HashTable<T>& other){
	destroyHashTable();

	//copy from other
	tableSize = other.tableSize;

	for(int i=0; i<tableSize; i++){
		if(other.hashTable[i]!=NULL){
			HashNode<T>* q = other.hashTable[i];
			HashNode<T>* p = hashTable[i];
			HashNode<T>* newNode = new HashNode<T>;
			newNode->data = q->data;
			newNode->next = NULL;
			hashTable[i] = p = newNode;
			q=q->next;
			//cout<<p->data<<endl;	//6 are already in

			while(q!=NULL){
				//cout<<q->data;

				HashNode<T>* nextNode = new HashNode<T>;
				nextNode->data = q->data;
				nextNode->next = NULL;

				//cout<< nextNode->data<<endl;
				p->next = nextNode;
				p=p->next;
				//cout<<p->data<<endl;
				q=q->next;
			}
			p->next = NULL;
		}
	}
}
template <class T>
void HashTable<T>:: destroyHashTable(){
	for(int i=0; i<tableSize; i++){
		if(hashTable[i] != NULL){
			HashNode<T>* p = hashTable[i];
			while(p!=NULL){
				HashNode<T>* temp = p;
				p=p->next;
				delete temp;
			}
		}
	}
	tableSize=0;
}
template <class T>
HashTable<T>::~HashTable(){
	destroyHashTable();
}
/***********************************************************************************************************************************************************/
#endif /* HASHTABLE_H_ */
