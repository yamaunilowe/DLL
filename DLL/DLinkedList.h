//My name is Yamauni Lowe and this is my own work plus the work that was provided
#ifndef DLINKLIST_H
#define DLINKLIST_H

#include <iostream>

using namespace std;

template <class T>
class DLinkedList {

	//PROVIDED
	friend ostream& operator<<(ostream& out, const DLinkedList<T>& rhs) {
		DNode* curr = rhs.header->next;
		while (curr != rhs.header) {
			out << curr->data << " ";
			curr = curr->next;
		}
		return out;
	}

public:

	//inner class DNode PROVIDED
	class DNode {
	public:
		DNode* next;
		DNode* prev;
		T data;

		DNode(T val = T()) {
			data = val;
			next = prev = this;
		}

	};

	//create an empty list:  PROVIDED
	DLinkedList() {
		//create the header
		header = new DNode();
	}

	//add method  PROVIDED
	DNode* add(T item) {
		//add a new node and return a 
		//pointer to this node
		DNode* newNode = new DNode(item);
		newNode->prev = header;
		newNode->next = header->next;
		header->next->prev = newNode;
		header->next = newNode;
		return newNode;
	}

	/**
	* ASSIGNED
	* remove val from the list
	*
	* @param val
	* @return true if successful, false otherwise
	*/
	bool remove(T val) {
		DNode* tail;
		if (header == tail) {
			delete val;
		}
		else {
			tail = val->tail->prev;
			delete val->next;
			val->next = 0;
		}
		return true;
	}


	/**
	* ASSIGNED
	*
	* @param item
	*/
	void insertOrder(T item) {
		DNode* insrt = new DNode(item);
		DNode* curr = header;
		if (header == NULL) {
			header = insrt;
		}
		if (curr->data >= insrt->data) {
			insrt->next = curr;
			curr->prev = insrt;
			curr->next = curr;
		}
		if (curr->data < insrt->data) {
			insrt= curr->next;
			insrt->prev = curr;
			curr->next->prev = insrt;
			curr->next = insrt;
			curr->next = curr;
		}
	}

	/**
	* ASSIGNED
	*
	* @param item
	*/
	bool insertOrderUnique(T item) {
		DNode* insrt = new DNode(item);
		DNode* curr = header;
		if (header == NULL) {
			header = insrt;
		}
		if (curr->data >= insrt->data) {
			insrt->next = curr;
			curr->prev = insrt;
			curr->next = curr;
		}
		if (curr->data < insrt->data) {
			insrt = curr->next;
			insrt->prev = curr;
			curr->next->prev = insrt;
			curr->next = insrt;
			curr->next = curr;
		}
		return true;
	}

	/**
	* ASSIGNED
	* PRE:  this and rhs are sorted lists
	* @param rhs
	* @return list that contains this and rhs merged into a sorted list
	* POST:  returned list will not contain duplicates, both rhs and this
	* will have no elements
	*/
	//DLinkedList merge(DLinkedList rhs) {
	//	DLinkedList result;
	//	DNode* Aptr, Bptr;
	//	Aptr = header->next;
	//	Bptr = rhs.header->next;
	//	while (Aptr != header && Bptr != rhs.header) {
	//		if (Aptr->data < Bptr->data) {
	//			//bypass node
	//			Bptr.prev.next = Bptr.next;
	//			Bptr->next->prev = Bptr->next;
	//			//hook node thats being passed in into new sorted/ merged node
	//			Bptr = result->header;
	//			Bptr->prev = result->header->prev;
	//			//update merged headers prev and next
	//			result->header->prev->next = Bptr;
	//			result->header->prev = Bptr;
	//			//update relevant pointer
	//			Bptr = rhs.header->next;
	//		}
	//	}
	//	return result;
	//}


private:
	//DLinkedList fields:  PROVIDED
	DNode* header;

};


#endif
