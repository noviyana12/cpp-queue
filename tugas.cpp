#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define max 10
using namespace std;

struct queue{
	int head, tail;
	int data[max];
} antrian;

int create(){
	antrian.head = antrian.tail = 0;
}

int isEmpty(){
	if(antrian.tail==0){
		return 1;
	}else{
		return 0;
	}
}

int isFull(){
	if(antrian.tail == max-1){
		return 1;
	}else{
		return 0;
	}
}

int enqueue(int data){
	if(isEmpty()==1){
		antrian.head = antrian.tail = 1;
		antrian.data[antrian.tail] = data;
		cout << "Notifikasi : Data " << antrian.data[antrian.tail] << " berhasil dimasukkan!\n";
	}else if(isFull()==0){
		antrian.tail++;
		antrian.data[antrian.tail] = data;
		cout << "Notifikasi : Data " << antrian.data[antrian.tail] << " berhasil dimasukkan!\n";
	}
}

int dequeue(){
	int i;
	int e = antrian.data[antrian.head];
	if(isEmpty()==0){
		cout << "Notifikasi : Data " << antrian.data[antrian.head] << " telah dihapus!\n";
		for(i=antrian.head;i<=antrian.tail-1;i++){
			antrian.data[i] = antrian.data[i+1];
		}
		antrian.tail--;

		return e;
	}
}

int clear(){
	while(isEmpty()==0){
		dequeue();
	}
}

int rerata(){
	float rata;
	float total;
	int n = 0;
	
	for(int i=antrian.head; i<=antrian.tail; i++){
		total += antrian.data[i];
		n++;
	}

	rata = total / n;
	cout << "Total data adalah " << total << endl;
	cout << "Rata-rata adalah " << rata << endl;
}

int total_data(){
	float total;
	
	cout << "Data kamu adalah ";
	for(int i=antrian.head; i<=antrian.tail; i++){
		cout << antrian.data[i] << " " ;
		total += antrian.data[i];
	}
	cout << "\nTotal Data adalah " << total << endl;
}

int tampil(){
	if(isEmpty()==0){
		cout << "Data dalam antrian: ";
		for(int i=antrian.head; i<=antrian.tail; i++){
			cout << antrian.data[i] << " " ;
		}
	} else{
		cout << "Data masih kosong!\n";
	}
}

int nilai_terkecil(){
	int temp = 0;
	int i = antrian.head;
	temp = antrian.data[i];
	
	cout << "Data kamu adalah: ";
	do{
		if( antrian.data[i]<temp){
			temp = antrian.data[i];
		}
		cout << antrian.data[i] << " ";
		i++;
	}
	while(i<=antrian.tail);
	cout << "\nNilai terkecil adalah " << temp << endl;
}

int nilai_terbesar(){
	int temp = 0;
	int i = antrian.head;
	temp = antrian.data[i];
	
	cout << "Data kamu adalah: ";
	do{
		if( antrian.data[i]>temp){
			temp = antrian.data[i];
		}
		cout << antrian.data[i] << " ";
		i++;
	}
	while(i<=antrian.tail);
	cout << "\nNilai terbesar adalah " << temp << endl;
}

int perhitungan(){
	int pilih;
	
	do{
	system("cls");
	cout << "Apa yang ingin kamu Hitung? \n";
	cout << "1. Total Data\n";
	cout << "2. Nilai Rata-rata\n";
	cout << "3. Nilai Terbesar\n";
	cout << "4. Nilai Terkecil\n";
	cout << "5. Kembali ke Menu Utama\n";
	cout << "Kamu memilih nomor : ";
	cin >> pilih;
	cout << endl;
	
	switch(pilih){
		case 1:
			total_data();
			break;
		case 2:
			rerata();
			break;
		case 3:
			nilai_terbesar();
			break;
		case 4:
			nilai_terkecil();
			break;
		case 5:
			cout << "Tekan 2x enter untuk melanjutkan\n";
			break;
		default:
			cout << "Kamu salah memasukkan kode" << endl;
			break;
	}
	getch();
	}
	while(pilih!=5);
	
}



int main(){
	int pil, data;
	create();

	do{
		system("cls");
			
		cout<< " ===================================================== "<<endl;
		cout<< "                  Noviyana- 20200801048                "<<endl;
		cout<< " ===================================================== "<<endl << endl;
	
		cout << "Pilih Menu yang ada:\n";
		cout << "1. Input Data" << endl;
		cout << "2. Hapus Data" << endl;
		cout << "3. Perhitungan Data " << endl;
		cout << "4. Tampil Data " << endl;
		cout << "5. Bersihkan Data"      << endl;
		cout << "6. Keluar"      << endl << endl;
		cout << "Kamu memilih nomor: ";
		cin >> pil;
		
		switch(pil){
			case 1:
				cout << "Masukkan data yang ingin dimasukkan: ";
				cin >> data;
				enqueue(data);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				perhitungan();
			case 4:
				tampil();
				break;
			case 5:
				clear();
				break;
			case 6:
				cout << "Terimakasih! Tekan Enter untuk keluar\n";
				break;
			default:
				cout << "Kamu salah memasukkan kode" << endl;
				break;
		}
		
		getch();
	}
	while(pil!=6);
}
