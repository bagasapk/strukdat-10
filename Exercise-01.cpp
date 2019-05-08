/*Program : Exercise-01
Nama : Anugerah Prima Bagaskara
NPM : 140810180006
Deskripsi : Queue Circular
Tanggal Buat : 8/5/2019
*/
#include<iostream>
using namespace std;

const int maxElm = 5;
struct Queue{
	char data[maxElm];
	int head;
	int tail;
};

typedef Queue queue;

void createQueue(queue &Q){
	Q.head=-1;
	Q.tail=-1;
}

bool empty(queue Q){
	if(Q.head==-1){
		return true;
	}else{
		return false;
	}
}

void pop(queue &Q, char &delData){
	if(empty(Q)){
		cout<<"Antrian kosong, tidak ada yang didelete."<<endl;
	}else if(Q.head==Q.tail){
		delData=Q.data[Q.head];
		Q.head=-1;
		Q.tail=-1;
	}else{
		delData=Q.data[Q.head];
		Q.data[Q.head]=0;
		if(Q.head<maxElm-1){
			Q.head++;
		}else{
			Q.head=0;
		}
	}
}

void push(queue &Q, char newData,char delData){
	if(empty(Q)){
		Q.head=0;
		Q.tail=0;
		Q.data[Q.head]=newData;
	}else{
		if(Q.tail<maxElm-1){
			Q.tail++;
			Q.data[Q.tail]=newData;
		}else{
			if(Q.head==0){
				pop(Q,delData);
				Q.tail=0;
				Q.data[Q.tail]=newData;
			}else{
				Q.tail=0;
				Q.data[Q.tail]=newData;
			}
		}
	}
}

void print(queue Q){
	if(empty(Q)){
		cout<<"Antrian Kosong."<<endl;
	}else{
		int i=Q.head;
		cout<<endl<<"Antrian = [";
		if(Q.head>Q.tail){
			while(i<maxElm){
				cout<<Q.data[i];
				if(i!=Q.tail){
					cout<<", ";
				}
				i++;
			}
			i=0;
			while(i<=Q.tail){
				cout<<Q.data[i];
				if(i!=Q.tail){
					cout<<", ";
				}
				i++;
			}
		}
		else{
			while(i<=Q.tail){
				cout<<Q.data[i];
				if(i!=Q.tail){
					cout<<", ";
				}
				i++;
			}
		}
		cout<<"]"<<endl;
	}
}

int main(){
	queue Q;
	int deletedData,pil,banyak;
	char temp;
	char delData;
	char loop;
	createQueue(Q);
	do{
		system("CLS");
		cout<<"1. Tambahkan Antrian\t3. Check Antrian"<<endl
		<<"2. Kurangi Antrian\t4. Print Antrian"<<endl;
		do{
			cin>>pil;
		}while(pil>5 || pil<1);
		switch(pil){
			case 1:
				cout<<endl<<"Banyak Data : ";cin>>banyak;
				for(int i=0; i<banyak; i++){
					cout<<"data-"<<i+1<<" : ";cin>>temp;
					push(Q,temp,delData);
				}
				break;
			case 2:
				cout<<endl<<"Banyak Data yang didelete : ";cin>>banyak;
				for(int i=0; i<banyak; i++){
					pop(Q,delData);
				}
				break;
			case 3:
				if(empty(Q)){
					cout<<"Antrian Kosong!"<<endl;
				}else{
					cout<<"Antrian Tidak Kosong!"<<endl;
				}
				break;
			case 4:
				print(Q);
				break;
		}
		cout<<endl<<"Kembali ke menu? (Y/N) ";
		do{
			cin>>loop;
		}while(loop!='Y' && loop!='y' && loop!='N' && loop!='n');
	}while(loop=='Y' || loop=='y');
	if(loop=='N' || loop=='n'){
		cout<<endl<<"Terimakasih!"<<endl;
	}
}
