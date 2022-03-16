#include <iostream>
using namespace std;

//Deklarasi struktur circular single linked list
struct Buku{
	string judul, pengarang;
	int terbit;
	
	Buku *next;
};

	Buku *head, *tail, *cur, *newNode, *del;
	
	//create circular Single Linked List
	void createCircularSingleLinkedList(string judul, string pengarang, int terbit) {
		head = new Buku();
		head->judul=judul;
		head->pengarang=pengarang;
		head->terbit=terbit;
		tail=head;
		tail->next=head;
	}
	
	//add first
	void addfirst (string judul, string pengarang, int terbit) {
		if (head == NULL ) {
			cout <<"Buat Linked List dulu "<<endl;
		} else{
		newNode = new Buku();
		newNode->judul=judul;
		newNode->pengarang=pengarang;
		newNode->terbit=terbit;
		newNode->next = head;
		tail->next = newNode;
		head = newNode;
		}
	}
	
	
	//add last
	void addlast (string judul, string pengarang, int terbit) {
		if (head == NULL ) {
			cout <<"Buat Linked List dulu "<<endl;
		} else{
		newNode = new Buku();
		newNode->judul=judul;
		newNode->pengarang=pengarang;
		newNode->terbit=terbit;
		newNode->next = head;
		tail->next = newNode;
		tail = newNode;
		}
	}
	
	//add middle
	void addmiddle(string judul, string pengarang, int terbit, int posisi) {
			if (head == NULL ) {
			cout <<"Buat Linked List dulu "<<endl;
		} else{
			if(posisi == 1){
				cout<<"Posisi satu bukan posisi tengah "<<endl;
			} else {
				newNode = new Buku();
				newNode->judul=judul;
				newNode->pengarang=pengarang;
				newNode->terbit=terbit;
				
				//transversing
				int nomor = 1;
				cur = head;
				while (nomor < posisi-1) {
					cur = cur->next;
					nomor++;
				}
				newNode->next = cur->next;
				cur->next = newNode;
			}
		}
	}
	
	//delete first
	void deletefirst() {
		if (head == NULL ) {
			cout <<"Buat Linked List dulu "<<endl;
		} else{
		del = head;
		head = head->next;
		tail->next = head;
		delete del;
		}
	}
	
	//delete last
	void deletelast() {
		if (head == NULL ) {
			cout <<"Buat Linked List dulu "<<endl;
		} else{
		del = tail;
		cur = head;
		
		while (cur->next != tail) {
			cur = cur->next;
		}
		tail = cur;
		tail->next = head;
		delete del;
		}
	}
	
	//delete middle
	void deletemiddle (int posisi) {
		if (head == NULL ) {
			cout <<"Buat Linked List dulu "<<endl;
		} else{
		//transversing
		int nomor = 1;
		cur = head;
		while ( nomor < posisi -1 ) {
			cur = cur->next;
			nomor++;
		}
		del = cur->next;
		cur->next = del->next;
		delete del;
		}
	}
	
	//print circular single linked list
	void printCircular() {
		if (head == NULL ) {
			cout <<"Buat Linked List dulu "<<endl;
		} else{
		cout<<"Data Buku "<<endl;
		cur=head;
		while (cur->next != head) {
			//print
			cout << "Judul Buku   : "<< cur->judul<<endl;
			cout << "Pengarang    : "<< cur->pengarang<<endl;
			cout << "Tahun Terbit : "<< cur->terbit<<endl;
			cur = cur->next;
		}
		cout << "Judul Buku   : "<< cur->judul<<endl;
		cout << "Pengarang    : "<< cur->pengarang<<endl;
		cout << "Tahun Terbit : "<< cur->terbit<<endl;
		}
	}

int main() {
	createCircularSingleLinkedList("Matematika", "Erlangga", 2009);
	printCircular();
	cout<<"\n\n"<<endl;
	
	addfirst("Kimia", "Suryadi", 2012);
	printCircular();
	cout<<"\n\n"<<endl;
	
	addlast("Bahasa Indonesia", "Suryono", 2018);
	printCircular();
	cout<<"\n\n"<<endl;
	
	addmiddle("Biologi", "Siswanto", 2008, 5); //menambahakan data baru di posisi ke-5
	printCircular();
	cout<<"\n\n"<<endl;
	
	/*deletefirst();
	printCircular();
	
	deletelast();
	printCircular();
	
	deletemiddle(6); //menghapus data pada posisi ke-6
	printCircular(); */
	
}
