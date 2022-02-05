#include <iostream>
#include <string>
#include <fstream>


#include "ExceptionList.h"
using namespace std;

struct Node {
	string company;
	string owner;
	string phone;
	string adress;
	string job;
	Node* next;
};
class List {
private:
	Node* head;
	size_t size;

	void addFirst(string company, string owner, string phone, string adress, string job) {
		this->head = new Node();
		this->head->company = company;
		this->head->owner = owner;
		this->head->phone = phone;
		this->head->adress = adress;
		this->head->job = job;
	}
public:
	List()
	{
		this->head = NULL;
		this->size = 0;
	}

	void add(string company, string owner, string phone, string adress, string job) {
		this->size++;
		if (this->head == NULL) {
			addFirst(company, owner, phone, adress, job);
			return;
		}
		Node* tmp = this->head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = new Node;

		tmp->next->next = NULL;
		tmp->next->company = company;
		tmp->next->owner = owner;
		tmp->next->phone = phone;
		tmp->next->adress = adress;
		tmp->next->job = job;
	}

	void show() {
		try {
			if (this->size == 0) {
				throw(ListException(1));
			}
		}
		catch (ListException error) {
			cout << error.what();
			throw;
		}
		Node* tmp = this->head;


		int i = 0;
		while (tmp != nullptr) {
			i++;
			cout << i << ": " << tmp->owner << "\t" << tmp->company << " (" << tmp->job << ")\n";
			cout << tmp->phone << "\n";
			cout << tmp->adress << "\n\n";
			tmp = tmp->next;
		}
	}
	void remove(int id) {

		try {
			if (id > this->size || id < 0) {
				throw(ListException(2));
			}
		}
		catch (ListException error) {
			cout << error.what();
			throw;
		}
		id--;

		if (id == 0) {
			this->head = this->head->next;
			this->size--;
			return;
		}

		Node* tmp = this->head;
		for (int i = 0; i < id - 1; i++) {
			tmp = tmp->next;
		}

		tmp->next = tmp->next->next;
		this->size--;

	}

	void findByCompany(string company) {
		Node* tmp = this->head;

		int i = 0;
		while (tmp != nullptr) {
			i++;
			if (company == tmp->company) {
				cout << i << ": " << tmp->owner << "\t" << tmp->company << " (" << tmp->job << ")\n";
				cout << tmp->phone << "\n";
				cout << tmp->adress << "\n\n";
			}
			tmp = tmp->next;
		}
	}
	void findByOwner(string owner) {
		Node* tmp = this->head;

		int i = 0;
		while (tmp != nullptr) {
			i++;
			if (owner == tmp->owner) {
				cout << i << ": " << tmp->owner << "\t" << tmp->company << " (" << tmp->job << ")\n";
				cout << tmp->phone << "\n";
				cout << tmp->adress << "\n\n";
			}
			tmp = tmp->next;
		}
	}
	void findByPhone(string phone) {
		Node* tmp = this->head;

		int i = 0;
		while (tmp != nullptr) {
			i++;
			if (phone == tmp->phone) {
				cout << i << ": " << tmp->owner << "\t" << tmp->company << " (" << tmp->job << ")\n";
				cout << tmp->phone << "\n";
				cout << tmp->adress << "\n\n";
			}
			tmp = tmp->next;
		}
	}
	void findByJob(string job) {
		Node* tmp = this->head;

		int i = 0;
		while (tmp != nullptr) {
			i++;
			if (job == tmp->job) {
				cout << i << ": " << tmp->owner << "\t" << tmp->company << " (" << tmp->job << ")\n";
				cout << tmp->phone << "\n";
				cout << tmp->adress << "\n\n";
			}
			tmp = tmp->next;
		}
	}

	void save() {
		ofstream fout("DataBase.txt", ios_base::out);


		try {
			if (!fout.is_open()) {
				throw(ListException(3));
			}
		}
		catch (ListException error) {
			cout << error.what();
			fout.close();
			throw;
		}

		Node* tmp = this->head;
		int i = 0;
		while (tmp != nullptr) {
			i++;
			fout << tmp->owner << ":" << tmp->company << ":" << tmp->phone << ":" << tmp->job << ":" << tmp->adress << ":\n";
			tmp = tmp->next;
		}

		fout.close();

	}
	void read() {
		ifstream fin("DataBase.txt", ios_base::in);

		try {
			if (!fin.is_open()) {
				throw(ListException(4));
			}
		}
		catch (ListException error) {
			cout << error.what();
			fin.close();
			throw;
		}
		string text;

		while (!fin.eof()) {
			getline(fin, text);
			string separator = ":";
			int pos = 0;
			
			string mas[5];
			int i = 0;
			while ((pos = text.find(separator)) !=-1) {
				mas[i] = text.substr(0, pos);
				text.erase(0, pos + separator.length());
				i++;
			}

			this->add(mas[1], mas[0], mas[2], mas[4], mas[3]);
		}

		fin.close();
	}
};


int main()
{
	List* СПРАВОЧНИК = new List();

	СПРАВОЧНИК->read();

	//СПРАВОЧНИК->add("fabric", "Vasya", "+38068123456", "Stonecutter 23", "Cleaner");
	//СПРАВОЧНИК->add("club", "Petya", "+38068653234", "Stonecutter 24", "CEO");
	//СПРАВОЧНИК->add("Banya", "Misha", "+708499033", "RedBar 37", "junior");

	СПРАВОЧНИК->show();

	//	СПРАВОЧНИК->remove(3);
		//cout << "\n\n\n";
		//СПРАВОЧНИК->show();
		//СПРАВОЧНИК->findByCompany("club");
		//СПРАВОЧНИК->save();
}

