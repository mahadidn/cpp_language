#include <iostream>
using namespace std;

// stack pake array statis
int maksimal = 5;
string arrayBuku[5];
int top = 0;


// push data ke stack
int push (string data){
	if (top >= maksimal){
		cout << "Data sudah penuh!\n" << endl;
	}
	else {
		arrayBuku[top] = data;
		top++;
	}

}

// nanya full atau tidak
bool isFull (){
	if (top >= maksimal){
		return true;
	}
	else {
		return false;
	}

}

// nanya, kosong atau tidak
bool isEmpty (){
	if (top == 0){
		return true;
	}
	else {
		return false;
	}

}

// menghapus
void pop(){
	if (isEmpty()){
		cout << "Data Kosong!" << endl;
	}
	else {
		arrayBuku[top-1] = "";
		top--;
	}
}

// menampilkan
void displayarray(){
	cout << "===Data stack array===" << endl;
	if (isEmpty()){
		cout << "Data Kosong!" << endl;
	}
	for (int i = maksimal - 1; i >= 0; i--){
		if (arrayBuku[i] != ""){
			cout << "Data ke-" << i << " : "  << arrayBuku[i] << endl;
		}
	}
	cout << endl;
}

// peek untuk mengintip posisi array
void peek(int posisi){
	if (isEmpty()){
		cout << "Data Kosong!" << endl;
	}
	else {
		int index = top;
		for (int i = 0; i < posisi; i++){
			index--;
		}
		cout << "Posisi ke-" << posisi << " : " << arrayBuku[index] << endl;
	}
}

void change(string data, int posisi){
	if (isEmpty()){
		cout << "Data Kosong!" << endl;
	}
	else {
		int index = top;
		for (int i = 0; i < posisi; i++){
			index--;
		}
		arrayBuku[index] = data;
	}
}

// menghitung jumlah data
int count(){
	if (isEmpty()){
		return 0;
	}
	else {
		return top;
	}

}

// menghapus semua data
void destroy(){
	for (int i = 0; i < top; i++){
		arrayBuku[i] = "";
	}
	top = 0;
}

// cek penuh atau kosong datanya
void PenuhAtauKosong(){
	if (isFull()){
	cout << "Data Full : "<< isFull() << endl;
	}
	else if (isEmpty()) {
	cout << "Data Kosong : " << isEmpty() << endl;
	}
}

int main (){

	 push("Fisika");
	 push ("Matematika");
	 push ("Bahasa");
	 push ("Inggris");
	 push ("Kimia");
	 displayarray();

	 pop();
	 push ("Sejarah");
	 displayarray();

	 peek(3);

	 change("Struktur Data", 3);
	 displayarray();

	cout << "Banyak Data : " << count() << endl;

	PenuhAtauKosong();
	
	destroy ();
	cout << "\nSetelah destroy maka" << endl;
	PenuhAtauKosong();
	return 0;
}