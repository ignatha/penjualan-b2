#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iomanip>
void stackmenu();
void tambah_list(int jumlah,int harga,int laba);
int hitung_stock();
int hitung_laba();
void tampilkan_jual();
void jual(int jumlah,int harga);
void tambah(int jumlah,int harga,char keterangan[100]);
void tampilkan_stock();
int hitung_laba_stock();

using namespace std;

typedef struct barang
{
    int jumlah;
    int harga;
    char keterangan[100];
    struct barang *next;
}barang;

barang *top;

typedef struct list
{
    int jumlah;
    int harga;
    int laba;
    struct list *next;
}list;

list *first;
list *tail;

int main(){
stackmenu();
return 0;
}

void stackmenu(){

    int menu;
    int jumlah, harga;
    char keterangan[100];
    int loop=1;
    while(loop==1){
    system ("cls");
    cout<<"\tAplikasi Penjualan Stock Telur Puyuh"<<endl<<endl;
    cout<<"1. Tambah stock"<<endl;
    cout<<"2. Lakukan Penjualan"<<endl;
    cout<<"3. Lihat Stock Telur"<<endl;
    cout<<"4. Keluar dan Lihat History Transaksi"<<endl<<endl;
    cout<<"Masukkan Pilihan : ";
    cin>>menu;
    switch(menu)
    {
    case 1:
        system ("cls");
    cout<<"\tAplikasi Penjualan Stock Telur Puyuh"<<endl<<endl;
    cout<<"Tambah Stock : "<<endl<<endl;
        cout<<"Masukkan Jumlah Telur \t\t\t: ";
        cin>>jumlah;
        cout<<"Masukkan Harga Modal/Butir \t\t: ";
        cin>>harga;
        fflush(stdin);
        cout<<"isikan keterangan stock \t\t: ";
        gets(keterangan);
        tambah(jumlah,harga,keterangan);
    loop=1;
    break;
    case 3:
    int pilihan;
    system ("cls");
    cout<<"\tAplikasi Penjualan Stock Telur Puyuh"<<endl<<endl;
    cout<<"Jumlah"<<setw(10)<<"Harga"<<setw(20) <<"Keterangan"<<endl;
    tampilkan_stock();
    cout<<endl<<endl<<"tekan 1 untuk Kembali Ke Menu : ";
    cin>>pilihan;
    if(pilihan==1)
    loop=1;
    else
    loop=2;
    break;
    case 2:
    system ("cls");
    cout<<"\tAplikasi Penjualan Stock Telur Puyuh"<<endl<<endl;
    cout<<"Jual Barang : "<<endl<<endl;
    cout<<"Masukkan Jumlah telur \t\t: ";
        cin>>jumlah;
        cout<<"Masukkan Harga Jual/Butir \t: ";
        cin>>harga;
    jual(jumlah,harga);
    loop=1;
    break;
    case 4:
    system ("cls");
    cout<<"\tAplikasi Penjualan Stock Telur Puyuh"<<endl<<endl;
    cout<<"\t\tHISTORY TRANSAKSI PENJUALAN"<<endl;
    cout<<"--------------------------------------------------"<<endl;
    tampilkan_jual();
    cout<<"--------------------------------------------------"<<endl;
    cout<<"Grand Total \t\t\t\t : ";
    cout<<hitung_laba();
    cout<<endl<<endl;
    cout<<"Stock tersedia : ";
    cout<<hitung_stock();
    cout<<endl;
    cout<<"Kekayaan dari stock tersedia \t\t : ";
    cout<<hitung_laba_stock();
    cout<<endl;
    cout<<"--------------------------------------------------"<<endl;
    cout<<"Jumlah Kekayaan \t\t\t : ";
    cout<<hitung_laba()+hitung_laba_stock();
    cout<<endl<<endl;
    loop=0;
    break;
    }}}

int hitung_laba_stock()
{
    struct	barang *temp = top;
	int laba=0;
	while (temp != NULL)
	{
		laba+=temp->jumlah*temp->harga;
		temp = temp->next;
	}
	return laba;}


int hitung_laba()
{
    struct	list *temp = first;
	int laba=0;
	while (temp != NULL)
	{
		laba+=temp->laba;
		temp = temp->next;
	}return laba;}

void tambah_list(int jumlah,int harga,int laba){
	struct list *temp;
	temp = (list *)malloc(sizeof(list));
	temp->jumlah=jumlah;
	temp->harga=harga;
	temp->laba=laba;
	temp->next=NULL;
    if(first==NULL&&tail==NULL){
		first=tail=temp;
        return;
	}else {
	tail->next=temp;
	tail=tail->next;
    }}

void tampilkan_jual()
{
    struct	list *temp = first;
	int x=1;
	while (temp != NULL)
	{
		cout<<x<<". Transaksi "<<temp->jumlah<<"@"<<temp->harga<<"\t\t\t : "<<temp->laba<<endl;
		temp = temp->next;
		x++;
	}
	cout<<endl;
	return;}

void tampilkan_stock()
{
    struct	barang *temp = top;
	int x=1;
	while (temp != NULL)
	{
		cout<<temp->jumlah<<setw(10)<<temp->harga<<setw(20) <<temp->keterangan<<endl;
		temp = temp->next;
		x++;
	}
	cout<<endl;
	return;}

void tambah(int jumlah,int harga, char keterangan[100]){
	struct barang *temp;
	temp = (barang *)malloc(sizeof(barang));
	temp->jumlah=jumlah;
	temp->harga=harga;
	strcpy(temp->keterangan,keterangan);

	if(top==NULL){
		top=temp;
		top->next=NULL;

	}else{
	temp->next = top;
	top = temp;

	}}
int hitung_stock()
{
    struct	barang *temp = top;
	int stock=0;
	while (temp != NULL)
	{
		stock+=temp->jumlah;
		temp = temp->next;
	}
	return stock;}

void jual(int jumlah,int harga)
{
	int total_stock=hitung_stock();
	if(total_stock-jumlah>=0){
	if(top!=NULL){
    int laba=0;
    int kurangan = jumlah;
	do{
	    struct	barang *temp = top;
		if(temp->jumlah-kurangan>0){
            laba += (harga-temp->harga)*kurangan;

            temp->jumlah=temp->jumlah-kurangan;
            kurangan=0;
		}else if(temp->jumlah-kurangan<=0){
		laba += (harga-temp->harga)*temp->jumlah;
		kurangan-=temp->jumlah;
		top=top->next;
		free(temp);
		}
	}while (kurangan != NULL);
	tambah_list(jumlah,harga,laba);
	} else { cout<<"Stock Kosong"; }
	}else{ cout<<"Stock Tidak Cukup";  }
	return;}

