#include <iostream>
#include "node.h"
#include "list.h"
#include <cstdlib>
using namespace std;

class linkedlist : public list {
	node* head;
	node* tail;
	int size;
	
	public:
	linkedlist() {
		head = new node;
		tail = new node;
		size = 0;
		head->next = tail;
		head->prev = NULL;
		tail->prev = head;
		tail->next = NULL;
	}
	
	void add_between(int num, node* pred, node* succ) {
		node* n = new node;
		n->elem = num;
		n->next = succ;
		n->prev = pred;
		
		pred->next = n;
		succ->prev = n;
		size++;
	}
	
	void remove_node(node* n) {
		node* pred = n->prev;
		node* succ = n->next;
		pred->next = succ;
		succ->prev = pred;
		size--;
		delete n;
	}
	
//	void advance(string name, int forward) {
//       node* n = find_person(name);
//       
//       node *pred = n->prev;
//       node *succ = n->next;
//       
//       pred->next = succ;
//       succ->prev = pred;
//       
//       for (int i = 0; i < forward && pred != head; i++) {
//            pred = pred->prev;
//       }

//       succ = pred->next;
//       n->prev = pred;
//       n->next = succ;
//       pred->next = n;
//       succ->prev = n;
//	}
	
//	void delay(string name, int back) {
//        node* n = find_person(name);
//        
//        node* pred = n->prev;
//        node* succ = n->next;
//        
//        pred->next = succ;
//        succ->prev = pred;
//        
//        for (int i = 0; i < back && succ != tail; i++) {
//            succ = succ->next;
//        }
//        
//        pred = succ->prev;
//        n->prev = pred;
//        n->next = succ;
//        pred->next = n;
//        succ->prev = n;
//	}
	
	void flip(){
        node* pred = NULL;
        node* succ = NULL;
        tail = head;

        while(head){
            succ = head->next;
            head->next = pred;
            pred = head;
            head = succ;
        }

        head = pred;
    }

	
	~linkedlist() {
		node* current = head;
    	node* nextNode = NULL;
	
	    while (current != NULL) {
	        nextNode = current->next;  // Save the next node
	        delete current;            // Delete the current node
	        current = nextNode;        // Move to the next node
	    }
	    	head = NULL; 
	}
	
	void addNum(int num) {
		add_between(num, head, head->next); // add head ni
		return;
	}
	
	void addTail(int num) {
		add_between(num, tail->prev, tail);
		return;
	}
		
	void removeTail() {
		if(!tail->prev) {
			return;
		}
		
		remove_node(tail->prev);
	}
	
	void removeHead() {
		if (!head->next) {
			return;
		}
		
		remove_node(head->next);
	}
	
	void print() {
		node* curr = head->next;
		
		if (curr == tail) {
			cout << "the empty is list" << endl;
		}
		while(curr != tail) {
			cout << curr->elem << " <-> ";
			curr = curr->next;
		}
		
		cout << endl;
	}
	
};
