/*
 * HashScanner.h
 *
 *  Created on: Dec 3, 2018
 *      Author: Pazuz
 */

#ifndef HASHSCANNER_H_
#define HASHSCANNER_H_
#include <iostream>
#include "Scanner.h"
#include "HashTable.h"
using namespace std;

template <class T>
class HashScanner: public Scanner<T>{
	HashTable<T> database;
	public:
		HashScanner(HashTable<T> _database){
			database = _database;
		}
		void scan(T& item){
			T find = database.get(item);
			cout<< find << endl;
		}
		void setDatabase(HashTable<T> _database){
			database = _database;
		}
		~HashScanner(){};
};


#endif /* HASHSCANNER_H_ */
