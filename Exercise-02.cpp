/*Program : Exercise-02
Nama : Anugerah Prima Bagaskara
NPM : 140810180006
Deskripsi : Antrian
Tanggal : 8/5/2019
*/
#include <iostream>
using namespace std;

const int maxElement=5;

struct node{
	char info;
	node *next;
};
struct queue{
	node *head;
	node *tail;
};

typedef node* pointer;
typedef pointer List;

void createQ(queue &Q);
void createList(pointer &pBaru);
void insertLast(queue &Q, pointer &pBaru);
void deleteFirst(queue &Q);
void print(queue Q);

int main(){
	queue Q;
	pointer p;
	int banyak,pil;
	char loop;
	createQ(Q);
	do{
		cout<<"Banyak Data [MAX = 5] : ";
		cin>>banyak;
	}while(banyak>maxElement);
	cout<<"Masukkan Data : "<<endl;
	for(int i=0; i<banyak; i++){
		createList(p);
		insertLast(Q,p);
	}
	do{
		system("CLS");
		cout<<"1. Tambah Antrian"<<endl;
		cout<<"2. Hapus Antrian"<<endl;
		cout<<"3. Print Antrian"<<endl;
		do{
			cin>>pil;
		}while(pil<1 && pil>3);
		switch(pil){
			case 1:
				if(banyak<5){
					cout<<"Masukkan Data : ";
					createList(p);
					insertLast(Q,p);
					banyak++;
				}else{
					cout<<"Antrian Penuh";
				}
				break;
			case 2:
				deleteFirst(Q);
				if(banyak>0){
					banyak--;
				}
				break;
			case 3:
				print(Q);
				break;
		}cout<<endl<<"Kembali ke menu? (Y/N) ";
		do{
			cin>>loop;
		}while(loop!='Y' && loop!='y' && loop!='N' && loop!='n');
	}while(loop=='Y' || loop=='y');
	if(loop=='N' || loop=='n'){
		return 0;
	}
}

void createQ(queue &Q){
	Q.head=NULL;
	Q.tail=NULL;
}
void createList(pointer &pBaru){
	pBaru=new node;
	cin>>pBaru->info;
	pBaru->next=NULL;
}
void insertLast(queue &Q, pointer &pBaru){
	if(Q.head==NULL){
		Q.head=pBaru;
		Q.tail=pBaru;
	}else{
		Q.tail->next=pBaru;
		Q.tail=pBaru;
	}
}
void deleteFirst(queue &Q){
	if(Q.head==NULL){
		cout<<"Antrian Kosong."<<endl;
	}else{
		pointer pHapus;
		pHapus=Q.head;
		Q.head=Q.head->next;
		pHapus->next=NULL;
	}
}
void print(queue Q){
	if(Q.head==NULL){
		cout<<"Antrian Kosong."<<endl;
	}else{
		pointer pBantu=Q.head;
		cout<<endl<<"Q = [";
		while(pBantu!=NULL){
			cout<<pBantu->info;
			if(pBantu->next!=NULL){
				cout<<", ";
			}
			pBantu=pBantu->next;
		}
		cout<<"]"<<endl;
	}
}
