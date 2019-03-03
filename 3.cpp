//Реализуйте класс char_deque -  дек символов чисел переменного размера. Класс должен содержать конструктор, деструктор,
//методы push_front, push_back,pop_front, pop_back


#include <iostream>
#include <string>
using namespace std;

struct Node {
	char data;
	Node* next = NULL;
	Node* prev = NULL;
};

class char_deque {
	Node* head;
	Node* tail;
public:
	char_deque(): head(NULL){}
	void push_front(char x) {
		if (head == NULL) {
			head = new Node;
			tail = head;
			head -> data = x;
		}
		head -> prev = new Node;
		head -> prev->next = head;
		head = head->prev;
		head -> data = x;
	}
	void push_back(char x) {
		if (head == NULL) {
			head = new Node;
			tail = head;
			head -> data = x;
		}
		tail -> next = new Node;
		tail -> next->prev = tail;
		tail = tail->next;
		tail -> data = x;
	}
	char pop_front() {
		if (head == NULL) {
			cout << "дек пустой";
			return 0;
		}
		Node* temp = head;
		head = head -> next;
		char x = temp -> data;
		delete temp;
		return x;
	}
	char pop_back() {
		if (head == NULL) {
			cout << "дек пустой";
			return 0;
		}
		Node* temp = tail;
		tail = tail -> prev;
		char x = temp -> data;
		delete temp;
		return x;
	}
	~char_deque() {
		while (head != NULL) {
			Node* temp = head;
			head = head -> next;
			delete temp;
		}
	}
};


int main() {

	char_deque d;

	d.push_front('a');
	d.push_front('b');
	cout << d.pop_front() << endl << d.pop_front() << endl;

	d.push_back('c');
	d.push_back('d');
	cout << d.pop_back() << endl << d.pop_back();

	return 0;
}
