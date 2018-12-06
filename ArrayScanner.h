/*
 * ArrayScanner.h
 *
 *  Created on: Dec 3, 2018
 *      Author: Pazuz
 */

#ifndef ARRAYSCANNER_H_
#define ARRAYSCANNER_H_
#include <iostream>
#include "Scanner.h"
using namespace std;

template <class T>
class ArrayScanner: public Scanner<T>{
	int size = 454531;
    T* database = new T*[size];
	public:
		ArrayScanner(T* _database):database(_database){}
		void scan(T& product){
			for(int i=0; i<size;i++){
				if(database[i] == product){
					cout<< database[i];
				}
			}
		}
		void setDatabase(T* _database){
		   database = _database;
		}
		~ArrayScanner(){
			delete database;
		}
};

#endif /* ARRAYSCANNER_H_ */
