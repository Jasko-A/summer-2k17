#include "Linkedlist.h"

Link::Link()
{
	root = NULL;
}

Link::listNode * Link::create_node(string name)
{
	listNode * temp;
	temp = new listNode;
	if (temp == NULL)
	{
		cout << "Memmory not allocated\n";
		return 0;
	}
	else
	{
		temp->name = name;
		temp->next = NULL;
	}
	return temp;
}

void Link::insert_back(string name)
{
	listNode * newNode = create_node(name);
	listNode * temp = root;
	if (root == NULL)
	{
		root = newNode;
		root->next = NULL;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next; 
		}
		temp->next = newNode;
		newNode->next = NULL;
		temp = newNode;
	}
}

void Link::displayList()
{
	listNode * temp;
	if (root == NULL)
	{
		cout << "the list is empty!!\n";
	}
	temp = root;
	cout << "Your Order is: ";
	while (temp != NULL)
	{
		cout << temp->name << ", ";
		temp = temp->next;
	}
}

void Link::updateOrderList(vector<string>&delItem)
{
	string x;
	listNode * temp;
	temp = root;
	for (int i = 0; i < delItem.size(); i++)
	{
		if (delItem[i] != temp->name)
			temp = temp->next;
		else if (delItem[i] == temp->name)
			deleteNode(delItem[i]);
		else
			cout << "Item: " << delItem[i] << " has not been found.\n";
	}
}

void Link::deleteNode(string x)
{
	listNode * nodeDel, * nodePre;

	if (root->name == x)	//takes care of the case if the root of linked list needs to be deleted.
	{
		nodeDel = root;
		root = nodeDel->next;
		delete nodeDel;
		return;
	}
	nodePre = root;
	nodeDel = nodePre->next;

	while (nodeDel != NULL)
	{
		if (nodeDel->name == x)
		{
			if (nodeDel->next = NULL)
				nodePre = nodeDel;
			else
				nodePre->next = nodeDel->next;
			delete nodeDel;
			break;
		}
		//delete nodeDel;
		//break;
	}

}
