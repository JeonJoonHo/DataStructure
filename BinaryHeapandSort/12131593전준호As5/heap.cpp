#include <iostream>
using namespace std;

class Node {
public:
	int key;
	int value;
	int childNumber;
	Node* leftChild;
	Node* rightChild;
	Node* parent;

	Node() {
		this->key = 0;
		this->value = 0;
		this->childNumber = 0;
		leftChild = NULL;
		rightChild = NULL;
		parent = NULL;
	}
};

class Heap {
public:
	Heap();
	void create(int n);
	void insertNode(Node* node, int key, int value);
	void peek(Node* node);
	void etract(Node* node);
	void heapify(Node* node, int arrSize, int* arr);
	void printSize(Node* node);
	void inOrder(Node* node);
	void descendOrder(Node* node);
	void swap(Node* swap, Node* swap2);
	void sort(Node* node, int key, int value);

	Node* heap;
	Node* last;
	bool maxHeap;
	int size;
};

Heap::Heap() {
	heap = NULL;
	last = NULL;
	maxHeap = true;
	size = 0;
}

void Heap::create(int n) {
	if (n == 1) {
		maxHeap = true;
	}
	else if (n == 2) {
		maxHeap = false;
	}
}

void Heap::insertNode(Node* node, int key, int value) {
	if (maxHeap == true) {
		if (heap == NULL) {
			heap = new Node;
			heap->parent = NULL;
			heap->key = key;
			heap->value = value;
			last = heap;
			size++;
		}
		else {
			if (node->leftChild == NULL) {
				node->leftChild = new Node;
				node->leftChild->parent = node;
				node->leftChild->key = key;
				node->leftChild->value = value;
				node->childNumber++;
				last = node->leftChild;
				size++;
			}
			else if (node->rightChild == NULL) {
				node->rightChild = new Node;
				node->rightChild->parent = node;
				node->rightChild->key = key;
				node->rightChild->value = value;
				node->childNumber++;
				last = node->rightChild;
				size++;
			}
			else if (last->parent->rightChild == NULL) {
				insertNode(last->parent, key, value);
			}
			else if (last->parent->rightChild != NULL) {
				if (node->leftChild->childNumber == 0) {
					insertNode(node->leftChild, key, value);
				}
				else if (last->parent->parent->leftChild->childNumber > last->parent->parent->rightChild->childNumber) {
					insertNode(last->parent->parent->rightChild, key, value);
				}
				else {
					insertNode(node->leftChild, key, value);
				}
			}
			Node* temp = last;
			while (temp->parent != NULL) {
				if (temp->key > temp->parent->key) {
					swap(temp, temp->parent);
				}
				temp = temp->parent;
			}
		}
	} else if (maxHeap == false) {
		if (heap == NULL) {
			heap = new Node;
			heap->parent = NULL;
			heap->key = key;
			heap->value = value;
			last = heap;
			size++;
		}
		else {
			if (node->leftChild == NULL) {
				node->leftChild = new Node;
				node->leftChild->parent = node;
				node->leftChild->key = key;
				node->leftChild->value = value;
				last = node->leftChild;
				size++;
			}
			else if (node->rightChild == NULL) {
				node->rightChild = new Node;
				node->rightChild->parent = node;
				node->rightChild->key = key;
				node->rightChild->value = value;
				last = node->rightChild;
				size++;
			}
			else if (last->parent->rightChild == NULL) {
				insertNode(last->parent, key, value);
			}
			else if (last->parent->rightChild != NULL) {
				if (node->leftChild->childNumber == 0) {
					insertNode(node->leftChild, key, value);
				}
				else if (last->parent->parent->leftChild->childNumber > last->parent->parent->rightChild->childNumber) {
					insertNode(last->parent->parent->rightChild, key, value);
				}
				else {
					insertNode(node->leftChild, key, value);
				}
			}
			Node* temp = last;
			while (temp->parent != NULL) {
				if (temp->key < temp->parent->key) {
					swap(temp, temp->parent);
				}
				temp = temp->parent;
			}
		}
	}
}

void Heap::peek(Node* node) {
	if (node == NULL) {
		cout << "empty" << endl;
	}
	else {
		cout << node->key << " " << node->value << endl;
	}
}

void Heap::etract(Node* node) {
	if (node == NULL) {
		cout << "empty" << endl;
	}
	else if (maxHeap == true) {
		cout << node->key << " " << node->value << endl;
		swap(node, last);
		if (last->parent->rightChild != NULL) {
			last = last->parent->leftChild;
			last->parent->rightChild = NULL;
		} else if (last->parent->rightChild == NULL) {
			last = last->parent;
			last->leftChild = NULL;
		}
		Node* temp = last;
		while (temp->parent != NULL) {
			if (temp->key > temp->parent->key) {
				swap(temp, temp->parent);
			}
			temp = temp->parent;
		}
		size--;
	} else if (maxHeap == false) {
		cout << node->key << " " << node->value << endl;
		swap(node, last);
		if (last->parent->rightChild != NULL) {
			last = last->parent->leftChild;
			last->parent->rightChild = NULL;
		}
		else if (last->parent->rightChild == NULL) {
			last = last->parent;
			last->leftChild = NULL;
		}
		Node* temp = last;
		while (temp->parent != NULL) {
			if (temp->key < temp->parent->key) {
				swap(temp, temp->parent);
			}
			temp = temp->parent;
		}
		size--;
	}
}

void Heap::heapify(Node* hea ,int arrSize, int* arr) {
	if (maxHeap == true) {
			heap = new Node;
			heap->parent = NULL;
			heap->key = arr[0];
			last = heap;
			size++;
			for (int i = 1; i < arrSize; i++) {
				if (heap->leftChild == NULL) {
					heap->leftChild = new Node;
					heap->leftChild->parent = heap;
					heap->leftChild->key = arr[i];
					heap->leftChild->value = 0;
					last = heap->leftChild;
					size++;
				}
				else if (heap->rightChild == NULL) {
					heap->rightChild = new Node;
					heap->rightChild->parent = heap;
					heap->rightChild->key = arr[i];
					heap->rightChild->value = 0;
					last = heap->rightChild;
					size++;
				}
				else if (last->parent->rightChild == NULL) {
					last->rightChild = new Node;
					last->rightChild->parent = heap;
					last->rightChild->key = arr[i];
					last->rightChild->value = 0;
					last = last->rightChild;
					size++;
				}
				else if (last->parent->rightChild != NULL) {
					if (heap->leftChild->childNumber == 0) {
						heap->leftChild->leftChild = new Node;
						heap->leftChild->leftChild->parent = heap->leftChild;
						heap->leftChild->leftChild->key = arr[i];
						heap->leftChild->leftChild->value = 0;
						last = heap->leftChild->leftChild;
						size++;
					}
					else if (last->parent->parent->leftChild->childNumber > last->parent->parent->rightChild->childNumber) {
						last->parent->parent->rightChild = new Node;
						heap->leftChild->leftChild = new Node;
						last->parent->parent->rightChild = last->parent->parent;
						last->parent->parent->rightChild->key = arr[i];
						last->parent->parent->rightChild->value = 0;
						last = last->parent->parent->rightChild;
						size++;
					}
				}
				Node* temp = last;
				while (temp->parent != NULL) {
					if (temp->key > temp->parent->key) {
						swap(temp, temp->parent);
					}
					temp = temp->parent;
				}
				heap->value = 0;
			}
		}
	if (maxHeap == false) {
		heap = new Node;
		heap->parent = NULL;
		heap->key = arr[0];
		last = heap;
		size++;
		for (int i = 1; i < arrSize; i++) {
			if (heap->leftChild == NULL) {
				heap->leftChild = new Node;
				heap->leftChild->parent = heap;
				heap->leftChild->key = arr[i];
				heap->leftChild->value = 0;
				last = heap->leftChild;
				size++;
			}
			else if (heap->rightChild == NULL) {
				heap->rightChild = new Node;
				heap->rightChild->parent = heap;
				heap->rightChild->key = arr[i];
				heap->rightChild->value = 0;
				last = heap->rightChild;
				size++;
			}
			else if (last->parent->rightChild == NULL) {
				insertNode(last->parent, arrSize, *arr);
			}
			else if (last->parent->rightChild != NULL) {
				if (heap->leftChild->childNumber == 0) {
					heap->leftChild->leftChild = new Node;
					heap->leftChild->leftChild->parent = heap->leftChild;
					heap->leftChild->leftChild->key = arr[i];
					heap->leftChild->leftChild->value = 0;
					last = heap->leftChild->leftChild;
					size++;
				}
				else if (last->parent->parent->leftChild->childNumber > last->parent->parent->rightChild->childNumber) {
					last->parent->parent->rightChild = new Node;
					heap->leftChild->leftChild = new Node;
					last->parent->parent->rightChild = last->parent->parent;
					last->parent->parent->rightChild->key = arr[i];
					last->parent->parent->rightChild->value = 0;
					last = last->parent->parent->rightChild;
					size++;
				}
			}
		}
		Node* temp = last;
		while (temp->parent != NULL) {
			if (temp->key < temp->parent->key) {
				swap(temp, temp->parent);
			}
			temp = temp->parent;
		}
		heap->value = 0;
	}
}

void Heap::printSize(Node* node) {
	cout << size << endl;
}

void Heap::inOrder(Node* node) {
	if (NULL == node) {
		return;
	}

	if (NULL != node->key) {
		this->inOrder(node->leftChild);
	}
	cout << node->key << " " << node->value << endl;
	if (NULL != node->key) {
		this->inOrder(node->rightChild);
	}
}

void Heap::descendOrder(Node* node) {
	if (NULL == node) {
		return;
	}
	this->descendOrder(node->rightChild);
	cout << node->key << " " << node->value << endl;
	this->descendOrder(node->leftChild);
}

void Heap::swap(Node* swap1, Node* swap2) {
	int key = swap1->key;
	swap1->key = swap2->key;
	swap2->key = key;
	int value = swap1->value;
	swap1->value = swap2->value;
	swap2->value = value;
}

void Heap::sort(Node* node, int key, int value) {
		if (node == NULL) {
			heap = new Node;
			heap->key = key;
			heap->value = value;
		}
		else {
			if (node->key > key) {
				if (node->leftChild == NULL) {
					node->leftChild = new Node;
					node->leftChild->key = key;
					node->leftChild->value = value;
				}
				else {
					sort(node->leftChild, key, value);
				}
			}
			else if (node->key < key) {
				if (node->rightChild == NULL) {
					node->rightChild = new Node;
					node->rightChild->key = key;
					node->rightChild->value = value;
				}
				else {
					sort(node->rightChild, key, value);
				}
			}
		}
	}


int main() {
	Heap hp;

	int makeHeap = 0; // 힙 = 1, 정렬 = 2;
	cout << " 힙 관련은 1, 정렬은 2를 입력하세요." << endl;
	cin >> makeHeap;
	// 1 입력 시 힙
	if (makeHeap == 1) {
		int index = 0; // 라인 수
		int i = 0; // i가 index만큼 커지면 while문 종료
		cin >> index;
		while (i < index) {
			char inputChar;
			cin >> inputChar;
			switch (inputChar) {
			case 'c': {
				int inputNum;
				cin >> inputNum;
				hp.create(inputNum);
				i++;
				break;
			}
			case 'i': {
				int inputKey, inputValue;
				cin >> inputKey >> inputValue;
				hp.insertNode(hp.heap, inputKey, inputValue);
				i++;
				break;
			}
			case 'p': {
				hp.peek(hp.heap);
				i++;
				break;
			}
			case 'e': {
				hp.etract(hp.heap);
				i++;
				break;
			}
			case 'h': {
				int inputSize = 0;
				cin >> inputSize;
				int *inputArr = new int[inputSize];
				for (int i = 0; i < inputSize; i++) {
					cin >> inputArr[i];
				}
				hp.heapify(hp.heap, inputSize, inputArr);
				i++;
				break;
			}
			case 's': {
				hp.printSize(hp.heap);
				i++;
				break;

			}
			}
		}
	}
	// 2 입력 시 정렬
	else if (makeHeap == 2) {
		hp.create(1);
		int index = 0;
		int sort = 0; // 1번은 오름차순 2번은 내림차순
		cout << "오름차순은 1번, 내림차순은 2번" << endl;
		cin >> sort;
		cin >> index; // 라인 수
		int i = 0; // i가 index만큼 커지면 while문 종료
		while (i < index) {
			int key, value;
			cin >> key >> value;
			hp.sort(hp.heap, key, value);
			i++;
		}
		char menu;
		cin >> menu;
		if (menu == 'q') {
			if (sort == 1) {
				hp.inOrder(hp.heap);
			}
			else if (sort == 2) {
				hp.descendOrder(hp.heap);
			}
		}
	}
}