#include <iostream>
using namespace std;

class Node{
public:
	int val;
	Node* next;
};

class List{
private:
	int index = 0;

public:
	Node* head;
	Node* temp;

	List() {
		head = NULL;
	}

	void insertNode(int val) {
		Node* insert = new Node;
		
		insert->val = val;
		insert->next = head;

		head = insert;
		index++;
	}

	void printList() {
		temp = head;

		for (int i = 0; i < index-1; i++) {
			cout << temp->val << " -> ";
			temp = temp->next;
		}
		cout << temp->val << endl;
	}
	
	void InsertFirst(int val) {
		Node* insert = new Node;

		insert->val = val;
		insert->next = head;

		head = insert;
		index++;
	}

	void RemoveFirst() {
		Node* remove = head;

		head = remove->next;
		delete remove;
		index--;
	}

	void InsertLast(int val) {
		temp = head;
		Node* insert = new Node;

		insert->val = val;
		for (int i = 0; i < index - 1; i++) {
			temp = temp->next;
		}

		temp->next = insert;
		insert->next = NULL;
		index++;
	}

	void RemoveLast() {
		temp = head;
		Node* remove = new Node;

		for (int i = 0; i < index - 1; i++) {
			remove = temp;
			temp = temp->next;
		}

		remove->next = NULL;
		delete temp;
		index--;
	}

	void RemoveNumber(int val) {
		temp = head;
		Node* remove = new Node;
		Node* oldNode = new Node;

		for (int i = 0; i < index; i++) {
			remove = temp;
			temp = temp->next;
			if (remove->val == val) {
				if (remove == head) {
					head = remove->next;
					delete remove;
				}
				else if(remove->next != NULL){
					oldNode->next = temp;
					delete remove;
				}
				else {
					remove->next = NULL;
					delete temp;
				}
			}
			oldNode = remove;
		}
		index--;
	}
};



	
int main() {
	List* Linkedlist = new List();
	int removeNumber = 0;

	Linkedlist->insertNode(1);
	Linkedlist->insertNode(2);
	Linkedlist->insertNode(3);
	Linkedlist->insertNode(4);
	Linkedlist->insertNode(5);
	Linkedlist->printList();

	cout << "머리 부분 삽입" << endl;
	Linkedlist->InsertFirst(6);
	Linkedlist->printList();
	
	cout << "머리 부분 삭제" << endl;
	Linkedlist->RemoveFirst();
	Linkedlist->printList();

	cout << "꼬리 부분 삽입" << endl;
	Linkedlist->InsertLast(0);
	Linkedlist->printList();

	cout << "꼬리 부분 삭제" << endl;
	Linkedlist->RemoveLast();
	Linkedlist->printList();

	cout << "삭제하려는 숫자를 입력하세요." << endl;
	cin >> removeNumber;
	Linkedlist->RemoveNumber(removeNumber);
	Linkedlist->printList();
	
	return 0;
}