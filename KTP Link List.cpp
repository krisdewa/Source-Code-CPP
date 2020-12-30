#include <iostream>
using namespace std;


struct node{
	string nik;
	string nama;
	string ttl;
	string jk;
	string alamat;
	string rt_rw;
	string agama;
	string sp;
	string pekerjaan;
	string kewarganegaraan;
	node* next;
};
	node* head;
	node* akhir;
	node* cekData;
	node* insert;
	node* del;
	
class post4{
	public:
		void inisialisasi(){
			head  = 0;
			akhir = 0;
		}
	void input(string nik,string nama, string ttl, string jk, string alamat, string rt_rw, string agama,string sp, string pekerjaan, string kewarganegaraan){
		insert = new node();
		insert -> nik = nik;
		insert -> nama = nama;
		insert -> ttl = ttl;
		insert -> jk = jk;
		insert -> alamat = alamat;
		insert -> rt_rw = rt_rw;
		insert -> agama = agama;
		insert -> sp = sp;
		insert -> pekerjaan = pekerjaan;
		insert -> kewarganegaraan = kewarganegaraan;
		insert -> next = 0;
		if(head == 0){
			head = akhir = insert;
		} else{
			insert -> next = head;
			head = insert;
		}
	}
	void hapus(){
		string nik;
		string nama;
		string ttl;
		string jk;
		string alamat;
		string rt_rw;
		string agama;
		string sp;
		string pekerjaan;
		string kewarganegaraan;
		
		if(head==0){
			cout<<"List yang di input tidak ada"<<endl;
		}else{
			nik			= head -> nik;
			nama		= head -> nama;
			ttl			= head -> ttl;
			jk			= head -> jk;
			alamat		= head -> alamat;
			rt_rw		= head-> rt_rw;
			agama		= head -> agama;
			sp 			= head -> sp;
			pekerjaan 	= head -> pekerjaan;
			kewarganegaraan = head -> kewarganegaraan;
			del 		= head;
			head 		= head -> next;
			delete del;
			cout << "\t";
			
			cout << " Data yang dihapus !!!"<< endl;
			cout<<"Masukkan NIK\t\t\t: "<< nik << endl;
			cout<<"Masukkan Nama\t\t\t: "<< jk << endl;
			cout<<"Masukkan TTL\t\t\t: "<< ttl << endl;
			cout<<"Masukkan Jenis Kelamin\t\t: "<< jk <<endl;
			cout<<"Masukkan Alamat\t\t\t: "<< alamat <<endl;
			cout<<"Masukkan RT/RW\t\t\t: "<< rt_rw <<endl;
			cout<<"Masukkan Agama\t\t\t: "<< agama <<endl;
			cout<<"Masukkan Status\t\t\t: "<< sp <<endl;
			cout<<"Masukkan Pekerjaan\t\t: "<< pekerjaan <<endl;
			cout<<"Masukkan Kewarganegaraan\t: "<< kewarganegaraan <<endl;
			}
			
		}
	void cetak(){
		cekData = head;
		if(head == 0)
			cout<<"tidak ada data dalam link list"<<endl;
		else{
			cout<<"List Data : ";
			while(cekData != NULL){
				cout << "\n";
				cout<<"Masukkan NIK\t\t\t: "<< cekData -> nik <<endl;
				cout<<"Masukkan Nama\t\t\t: "<< cekData -> jk<<endl;
				cout<<"Masukkan TTL\t\t\t: "<< cekData -> ttl<<endl;
				cout<<"Masukkan Jenis Kelamin\t\t: "<< cekData -> jk<<endl;
				cout<<"Masukkan Alamat\t\t\t: "<< cekData -> alamat<<endl;
				cout<<"Masukkan RT/RW\t\t\t: "<< cekData -> rt_rw<<endl;
				cout<<"Masukkan Agama\t\t\t: "<< cekData -> agama<<endl;
				cout<<"Masukkan Status\t\t\t: "<< cekData -> sp<<endl;
				cout<<"Masukkan Pekerjaan\t\t: "<< cekData -> pekerjaan<<endl;
				cout<<"Masukkan Kewarganegaraan\t: "<< cekData -> kewarganegaraan<<endl;
				
				cekData = cekData -> next;
				if(cekData != NULL){
					cout << endl;
				}
		
		}
		cout << "NULL" << endl;
		}
	}
	void menu(){
		char pilih, ulang;
		string nik;
		string nama;
		string ttl;
		string jk;
		string alamat;
		string rt_rw;
		string agama;
		string sp;
		string pekerjaan;
		string kewarganegaraan;
	do{
		system("cls");
		cout <<"===< Menu >===\n"
			 <<"1. Input data \n"
			 <<"2. Hapus data \n"
			 <<"3. Cetak Data \n"
			 <<"4. Exit\n\n"
			 <<"Masukkan pilihan Anda : ";
		cin >> pilih;
		cin.ignore();
		cout << endl;
		
		switch(pilih){
			case '1' :
				cout<<"Masukkan NIK\t\t\t: "; getline(cin, nik);
				cout<<"Masukkan Nama\t\t\t: "; getline(cin, nama);
				cout<<"Masukkan TTL\t\t\t: "; getline(cin, ttl);
				cout<<"Masukkan Jenis Kelamin\t\t: "; getline(cin, jk);
				cout<<"Masukkan Alamat\t\t\t: "; getline(cin, alamat);
				cout<<"Masukkan RT/RW\t\t\t: "; getline(cin, rt_rw);
				cout<<"Masukkan Agama\t\t\t: "; getline(cin, agama);
				cout<<"Masukkan Status\t\t\t: "; getline(cin, sp);
				cout<<"Masukkan Pekerjaan\t\t: "; getline(cin, pekerjaan);
				cout<<"Masukkan Kewarganegaraan\t: "; getline(cin, kewarganegaraan);
				
				input(nik ,nama,ttl,jk,alamat,rt_rw,agama,sp,pekerjaan,kewarganegaraan);
				break;
			case '2' :
				hapus();
				break;
			case '3' :
				cetak();
				break;
			case '4' :
				exit(0);
				break;
			default :
				cout<<"\nPilih ulang"<<endl;
		}
		cout << "\nKembali ke menu ?(y/n) : ";
		cin >> ulang;
		} while(ulang=='y' || ulang=='Y');
	}
};

int main(){
	post4 *linklist = new post4();
	linklist -> inisialisasi();
	linklist -> menu();
	delete linklist;
}
