/*
 * BarcodeTimeTester.cpp
 *
 * Fatma, I tried to implement your suggestions, However, eclipse keeps giving me these wild errors.
 * I know we keep the virtual keyword in the scanner base class because we want to override that function in the derived classes
 * however, eclipse does not like this. To be more specific, eclipse does not like you overriding ~ArrayScanner() despite ~Scanner()
 * is virtual.
 * I also understand the polymorphic function; we are passing a scanner object in general but due to polymorphism, this scanner object
 * can either be bst or array. The function will call the appropriate scanner type and scan the product.
 *
 *
 *  Created on: Nov 20, 2018
 *      Author: Pazuz
 */
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include "BinarySearchTree.h"
#include "HashTable.h"
#include "Product.h"
#include "Scanner.h"
#include "BSTScanner.h"
#include "ArrayScanner.h"
#include "HashScanner.h"
using namespace std;

void scan(Scanner<Product>* scanner, Product item) { //polymorphic function
	scanner->scan(item);
}

int main(){

	//Initialize database
	BinarySearchTree<Product> bst;
	Product* array = new Product[454531];
	HashTable<Product> ht;

	string line;
	string upc;
	string descript;
	int length = 0;
	clock_t startTime;

 /* parses text from file into UPC and description,
 *  saves tokens into item object,
 *  saves item object into BST Tree
 *  saves item object into Array
 */

	//populate the databases
	ifstream file;
	file.open("upc_corpus.txt");
	while(!file.eof()){
		getline(file, line);
		istringstream ss(line);
		getline(ss, upc, ',');					//save UPC
		getline(ss, descript);					//save Description
		Product item(upc,descript);				//create item
		bst.insert(item);						//save item to tree
		ht.put(item);							//save item to hashTable
		array[length] = item; 					//save item to array
		length++;
	}
/*******************************************************************************************************************************************
start program*/

	//create Scanners to search databases
	Scanner<Product>* scanner1 = new ArrayScanner<Product>(array);
	Scanner<Product>* scanner2 = new BSTScanner<Product>(bst);
	Scanner<Product>* scanner3 = new HashScanner<Product>(ht);


//Entry 100, upc: 797776236787
	cout<<"Sample Run-1"<<endl;
	Product item1("797776236787","");

	//arrayScanner
	startTime = clock();					//start clock
	scan(scanner1,item1);					//arrayScanner
	startTime = clock() - startTime;		//take difference between times
	cout<<"Array time: "<< startTime <<" milliseconds"<<endl;

	//BSTScanner
	startTime = clock();
	scan(scanner2, item1);					//BSTScanner
	startTime = clock() - startTime;
	cout<<"BST time: "<< startTime <<" milliseconds"<<endl;

	//HashScanner
	startTime = clock();
	scan(scanner3, item1);					//HashScanner
	startTime = clock() - startTime;
	cout<<"Hash time: "<< startTime <<" milliseconds"<<endl;

//Entry 10,000 upc: 799439155022
	cout<<"Sample Run-2"<<endl;
	Product item2("799439155022","");

	//arrayScanner
	startTime = clock();
	scan(scanner1,item2);					//arrayScanner
	startTime = clock() - startTime;
	cout<<"Array time: "<< startTime <<" milliseconds"<<endl;

	//BSTScanner
	startTime = clock();
	scan(scanner2, item2);					//BSTScanner
	startTime = clock() - startTime;
	cout<<"BST time: "<< startTime <<" milliseconds"<<endl;

	//HashScanner
	startTime = clock();
	scan(scanner3, item2);					//HashScanner
	startTime = clock() - startTime;
	cout<<"Hash time: "<< startTime <<" milliseconds"<<endl;

//Entry 15,500, upc: 8370380006
	cout<<"Sample Run-3"<<endl;
	Product item3("8370380006","");

	//arrayScanner
	startTime = clock();
	scan(scanner1,item3);					//arrayScanner
	startTime = clock() - startTime;
	cout<<"Array time: "<< startTime <<" milliseconds"<<endl;

	//BSTScanner
	startTime = clock();
	scan(scanner2, item3);					//BSTScanner
	startTime = clock() - startTime;
	cout<<"BST time: "<< startTime <<" milliseconds"<<endl;

	//HashScanner
	startTime = clock();
	scan(scanner3, item3);					//HashScanner
	startTime = clock() - startTime;
	cout<<"Hash time: "<< startTime <<" milliseconds"<<endl;

//Entry 100,000 upc: 32458960315
	cout<<"Sample Run-4"<<endl;
	Product item4("32458960315","");

	//arrayScanner
	startTime = clock();
	scan(scanner1,item4);					//arrayScanner
	startTime = clock() - startTime;
	cout<<"Array time: "<< startTime <<" milliseconds"<<endl;

	//BSTScanner
	startTime = clock();
	scan(scanner2, item4);					//BSTScanner
	startTime = clock() - startTime;
	cout<<"BST time: "<< startTime <<" milliseconds"<<endl;

	//HashScanner
	startTime = clock();
	scan(scanner3, item4);					//HashScanner
	startTime = clock() - startTime;
	cout<<"Hash time: "<< startTime <<" milliseconds"<<endl;

//Entry 500,000 upc: 741152500207
	cout<<"Sample Run-5"<<endl;
	Product item5("741152500207","");
	//arrayScanner
	startTime = clock();
	scan(scanner1,item5);					//arrayScanner
	startTime = clock() - startTime;
	cout<<"Array time: "<< startTime <<" milliseconds"<<endl;

	//BSTScanner
	startTime = clock();
	scan(scanner2, item5);					//BSTScanner
	startTime = clock() - startTime;
	cout<<"BST time: "<< startTime <<" milliseconds"<<endl;

	//HashScanner
	startTime = clock();
	scan(scanner3, item5);					//HashScanner
	startTime = clock() - startTime;
	cout<<"Hash time: "<< startTime <<" milliseconds"<<endl;

//Entry 590,093 upc: 41600010631
	cout<<"Sample Run-6"<<endl;
	Product item6("41600010631","");

	//arrayScanner
	startTime = clock();
	scan(scanner1,item6);					//arrayScanner
	startTime = clock() - startTime;
	cout<<"Array time: "<< startTime <<" milliseconds"<<endl;

	//BSTScanner
	startTime = clock();
	scan(scanner2, item6);					//BSTScanner
	startTime = clock() - startTime;
	cout<<"BST time: "<< startTime <<" milliseconds"<<endl;

	//HashScanner
	startTime = clock();
	scan(scanner3, item6);					//HashScanner
	startTime = clock() - startTime;
	cout<<"Hash time: "<< startTime <<" milliseconds"<<endl;

//End
	delete []array;
	return 0;
}

