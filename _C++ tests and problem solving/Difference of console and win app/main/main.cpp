/*
 * main.cc
 *
 *  Created on: Feb 22, 2014
 *      Author: yyc
 */

//Process-oriented
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Node {
	string name;
	string phone_number;
	Node *next;
	Node() {
		name = "Default Content";
		phone_number = "Default Content";
		next = 0;
	}
};

//---------- declaration ----------

void print_contact(Node* head);
int get_size(Node* head);
int get_size_of_int(int i);
Node** get_by_num(Node* &head, int /* i start from 1 */i);
void set_one(Node* &head, int /* i start from 1 */i, string name,
		string number);
void set_one(Node* &head, int /* i start from 1 */i, string name, string number,
		Node* next);
void add_one(Node* &head, string name, string number);
void delete_one(Node* &head, int i);
bool index_not_available(Node* head, int i);
int select_by_name(Node* head, string name);
int select_by_number(Node* head, string number);
int select_by_name_and_number(Node* head, string name, string number);
int select(Node* head, string name, string number);
void ui(Node *&node_head);

//---------- declaration end ----------

//---------- main function ----------

int main() {
	Node *head1;
	ui(head1);
	return 0;
}

//---------- main function end ----------

void print_contact(Node* head) {
	/*
	 * Format:
	 * |---|-----------|---------|
	 * | # |      name |  number |
	 * | 1 | Some Body | 1234567 |
	 * |---|-----------|---------|
	 */
	int width_num = get_size_of_int(get_size(head)), width_name = 4,
			width_number = 6;
	Node* pointer = head;
	while (true) {
		if (pointer == 0)
			break;
		if (width_name < int(pointer->name.length())) {
			width_name = int(pointer->name.length());
		}
		if (width_number < int(pointer->phone_number.length())) {
			width_number = int(pointer->phone_number.length());
		}
		pointer = pointer->next;
	}
	//head
	cout << "| ";
	cout << setw(width_num) << '#';
	cout << " | ";
	cout << setw(width_name) << "name";
	cout << " | ";
	cout << setw(width_number) << "number";
	cout << " |\n";
	//head end
	//main
	pointer = head;
	for (int i = 1;; i++) {
		if (pointer == 0)
			break;
		cout << "| ";
		cout << setw(width_num) << i;
		cout << " | ";
		cout << setw(width_name) << pointer->name;
		cout << " | ";
		cout << setw(width_number) << pointer->phone_number;
		cout << " |\n";
		pointer = pointer->next;
	}
	cout << endl;
}

int get_size(Node* head) {
	int result = 0;
	Node* pointer = head;
	while (pointer != 0) {
		pointer = pointer->next;
		result++;
	}
	return result;
}

int get_size_of_int(int i) {
	int result = 1;
	if (i < 0) {
		i = -i;
		result++;
	}
	while (i /= 10)
		result++;
	return result;
}

Node** get_by_num(Node* &head, int i) {
	// start from 1
	if (index_not_available(head, i))
		return 0;
	i--;
	Node** pointer = &head;
	while (i) {
		if (!(*pointer))
			return 0;
		i--;
		pointer = &((*pointer)->next);
	}
	return pointer;
}

void set_one(Node* &head, int /* i start from 1 */i, string name,
		string number) {
	set_one(head, i, name, number, 0);
}

void set_one(Node* &head, int /* i start from 1 */i, string name, string number,
		Node* next) {
	Node** node = get_by_num(head, i);
	if (!node)
		return; //out of range
	(*node)->name = name;
	(*node)->phone_number = number;
	if (next)
		(*node)->next = next;
}

void add_one(Node* &head, string name, string number) {
	Node** pointer = &head;
	while (*pointer)
		pointer = &((*pointer)->next);
	*pointer = new Node();
	set_one(head, get_size(head), name, number, 0);
}

void delete_one(Node* &head, int i) {
	Node** pointer = get_by_num(head, i);
	Node** next = get_by_num(head, i + 1);
	if (pointer) {
		delete (*pointer);
		if (next)
			(*pointer) = *next;
		else
			(*pointer) = 0;
	}
}

bool index_not_available(Node* head, int i) {
	return (i <= 0 || i > get_size(head));
}

int select_by_name(Node* head, string name) {
	/*
	 * 0 means not found
	 */
	Node *pointer = head;
	for (int i = 1;; i++) {
		if (!pointer)
			return 0;
		if (pointer->name == name)
			return i;
		pointer = pointer->next;
	}
	return 0;
}

int select_by_number(Node* head, string number) {
	/*
	 * 0 means not found
	 */
	Node *pointer = head;
	for (int i = 1;; i++) {
		if (!pointer)
			return 0;
		if (pointer->phone_number == number)
			return i;
		pointer = pointer->next;
	}
	return 0;
}

int select_by_name_and_number(Node* head, string name, string number) {
	/*
	 * 0 means not found
	 */
	Node *pointer = head;
	for (int i = 1;; i++) {
		if (!pointer)
			return 0;
		if (pointer->name == name && pointer->phone_number == number)
			return i;
		pointer = pointer->next;
	}
	return 0;
}

int select(Node* head, string name = "", string number = "") {
	if ((name + number).length() == 0)
		return 0;
	else if (name.length() == 0)
		return select_by_number(head, number);
	else if (number.length() == 0)
		return select_by_name(head, name);
	else
		return select_by_name_and_number(head, name, number);
}

void ui(Node *&node_head) {
	cout << "Contact" << endl;
	node_head = 0;
	string c;
	while (true) {
		cout << "please enter command" << '\n'
				<< "p to print the list, a to add one, d to delete one, "
				<< '\n' << "s to search, " << '\n' << "and q to quit" << endl;
		getline(cin, c);
		switch (c[0]) {
		case 'q':
			return;
		case 'p':
			print_contact(node_head);
			break;
		case 'a': {
			string name, num;
			cout << "name:" << endl;
			getline(cin, name);
			bool invilid_num = true;
			while (cout << "number:" << endl) {
				getline(cin, num);
				for (int i = num.length() - 1; i >= 0; i--) {
					if (!(num[i] >= '0' && num[i] <= '9')) {
						invilid_num = false;
						break;
					}
				}
				if (invilid_num)
					break;
				else {
					cout << "invilid number" << endl;
					continue;
				}
			}
			add_one(node_head, name, num);
		}
			break;
		case 'd': {
			cout << "please enter the count of the item you want to delete:"
					<< endl;
			print_contact(node_head);
			int i;
			cin >> i;
			cin.ignore(100, '\n');
			delete_one(node_head, i);
		}
			break;
		case 's': {
			string name, num;
			cout << "please enter the infomations you want to search by, "
					<< '\n'
					<< "enter nothing means that the condition will not be used, "
					<< '\n' << "you shoule enter at least one condition."
					<< endl;
			cout << "name:" << endl;
			getline(cin, name);
			cout << "number:" << endl;
			getline(cin, num);
			int r = select(node_head, name, num);
			if (r > 0) {
				cout << "location: " << r << endl;
				cout << "name: " << (*get_by_num(node_head, r))->name << '\n'
						<< "name: " << (*get_by_num(node_head, r))->phone_number
						<< endl;
				cout << "do you want to delete or change it?" << endl;
				cout << "enter d to delete it and c to change it" << '\n'
						<< "any other key means doing nothing" << endl;
				string doc;
				getline(cin, doc);
				switch (doc[0]) {
				case 'd':
					delete_one(node_head, r);
					break;
				case 'c':
					string name, num;
					cout << "name:" << endl;
					getline(cin, name);
					cout << "number:" << endl;
					getline(cin, num);
					set_one(node_head, r, name, num);
					break;
				}
			} else {
				cout << "do not found!" << endl;
			}
		}
			break;
		}
	}
	return;
}
