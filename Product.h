/*
 * Item.h
 *
 *  Created on: Nov 19, 2018
 *      Author: Pazuz
 */

#ifndef PRODUCT_H_
#define PRODUCT_H_
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

class Product{
	private:
		string key;
		string value;
	public:
		Product(string _upc="", string _descript="");
		int getHashCode();
		friend ostream& operator<<(ostream&, const Product&);
		friend bool operator<(const Product&, const Product&);
		friend bool operator>(const Product&, const Product&);
		friend bool operator==(const Product&, const Product&);
		friend bool operator!=(const Product&, const Product&);
};
Product::Product(string _upc, string _descript){
	key = _upc;
	value = _descript;
}
int Product::getHashCode(){
	int hashVal = 0;
	for (unsigned int i = 0; i < key.length(); i++){
		hashVal += 37 * key[i];
	}
	return hashVal;
}
ostream& operator<<(ostream& os, const Product& item){
	os<<item.key << " " << item.value<< endl;
	return os;
}
bool operator<(const Product& item1, const Product& item2){
	return item1.key < item2.key;
}
bool operator>(const Product& item1, const Product& item2){
	return item1.key > item2.key;
}
bool operator==(const Product& item1, const Product& item2){
	return item1.key == item2.key;
}
bool operator!=(const Product& item1, const Product& item2){
	return item1.key != item2.key;
}

#endif /* PRODUCT_H_ */
