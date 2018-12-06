/*
 * BSTScanner.h
 *
 *  Created on: Dec 3, 2018
 *      Author: Pazuz
 */

#ifndef BSTSCANNER_H_
#define BSTSCANNER_H_
#include <iostream>
#include "Scanner.h"
#include "BinarySearchTree.h"
using namespace std;

template <class T>
class BSTScanner: public Scanner<T>{
	BinarySearchTree<T> database;
	public:
		BSTScanner(BinarySearchTree<T> _database):database(_database){}
		void scan(T& product){
			if(database.search(product) == true){
				cout<<"found"<<endl;
			}
		}
		void setDatabase(BinarySearchTree<T> _database){
			database = _database;
		}
		~BSTScanner(){};
};

#endif /* BSTSCANNER_H_ */
