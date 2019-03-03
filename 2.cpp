//Реализуйте класс string_queue -  очередь строк. Класс должен содержать конструктор, деструктор, методы push,pop.


#include <iostream>
#include <string>
using namespace std;

struct Node {
	string data;
	Node* next = NULL;
};

class string_queue {
	Node* head;
  
public:
	string_queue():head(NULL) {}
	void push(string x) {
		if (head == NULL) {
			head = new Node;
			head->data = x;
		}
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new Node;
		temp->next->data = x;
	}
  
	 string pop() {
		if (head == NULL) {
			cout << "очередь пуста";
			return 0;
		}
    
		Node* temp = head;
		head = head->next;
		string x = head->data;
		delete temp;
		return x;
	}
  
	~string_queue() {
		while (head != NULL) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
};

int main() {
	string_queue str;
	str.push("здравствуйте");
	str.push("можно 4?");
	str.push("пожалуйста");
	cout << str.pop() << endl << str.pop() << endl << str.pop();
	return 0;
}
