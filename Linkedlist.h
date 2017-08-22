#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_h
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Link {
	private:
		struct listNode {
			string name;
			listNode * next;
		};
		listNode * root;
	public:
		Link();
		listNode * create_node(string);
		void insert_back(string);
		void displayList();
		void updateOrderList(vector<string> &);
		void deleteNode(string);

};

#endif