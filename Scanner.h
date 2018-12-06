/*
 * Scanner.h
 *
 *  Created on: Dec 5, 2018
 *      Author: Pazuz
 */

#ifndef SCANNER_H_
#define SCANNER_H_
#include <iostream>
using namespace std;

template <class T>
class Scanner{
	public:
		virtual void scan(T& item) = 0;	//virtual function can be override in derived classes
		virtual ~Scanner(){};
};

#endif /* SCANNER_H_ */

