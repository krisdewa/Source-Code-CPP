#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct node{
    string nama;
	string nik,ttl,jk,alamat,rt_rw,agama,sp,pekerjaan,kewarganegaraan;
	struct node *next;
} *akhir;

class circular_list{
	public:
	void buat_node(string nik,string nama, string ttl, string jk, string alamat, string rt_rw, string agama, string sp, string pekerjaan, string kewarganegaraan);
	void insert_depan(string nik, string nama, string ttl, string jk, string alamat, string rt_rw, string agama, string sp, string pekerjaan, string kewarganegaraan);
	void hapus_node(string nama);
	void tampilkan_list();
	circular_llist(){
		akhir = NULL;
	}
};

int main(){
	string nik,ttl,jk,alamat,rt_rw,agama,sp,pekerjaan,kewarganegaraan;
    string nama;
	char choice, lanjut;
	circular_list cl;
	
	while (1) {
		cout << "========================== \n"
			 << "== Circular Linked List == \n"
		 	 << "========================== \n"
			 << "  1.Buat Node 			 	\n"
			 << "  2.Tambah Node didepan 	\n"
			 << "  3.Hapus Node 		 	\n"
			 << "  4.Cetak Node 		 	\n"
			 << "  5.Exit 					\n"
			 << "========================== \n\n";
		cout << " Masukan Pilihan : ";
		cin >> choice; cout << endl;
		cin.ignore();
		switch (choice){
			case '1':
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
				cl.buat_node(nik,nama, ttl, jk, alamat, rt_rw, agama, sp,pekerjaan, kewarganegaraan);
				cout << "\n";
				cout << "\nlanjut ke menu (Y/N) : "; cin >> lanjut;
				if (lanjut == 'y' || lanjut == 'Y'){
					system("cls");
				}else{
					exit(1);
				}
				break;
			case '2':
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
				
				cl.insert_depan(nik,nama, ttl, jk, alamat, rt_rw, agama, sp,pekerjaan, kewarganegaraan);
				cout << endl;
				cout << "\nlanjut ke menu (Y/N) : ";
				cin >> lanjut;
				if (lanjut == 'y' || lanjut == 'Y'){
					system("cls");
				}else{
					exit(1);
				}
				break;
			case '3':
				if (akhir == NULL){
					cout << "=====================" << endl;
					cout << "= List masih kosong =" << endl;
					cout << "=====================" << endl;
					break;
				}
				cout << "Masukan Nama data KTP yang ingin dihapus: "; cin >> nama;
				cl.hapus_node(nama);
				cout << endl;
				cout << "\nlanjut ke menu (Y/N) : ";  cin >> lanjut;
				if (lanjut == 'y' || lanjut == 'Y'){
					system("cls");
				}else{
					exit(1);
				}
				break;
			case '4':
				cl.tampilkan_list();
				cout << "\nlanjut ke menu (Y/N) : "; cin >> lanjut;
				if (lanjut == 'y' || lanjut == 'Y'){
					system("cls");
				}else{
					exit(1);
				}
				break;
			case '5':
				exit(1);
				break;
				default:
				cout << "=====================================" << endl;
				cout << "= Pilihan anda tidak ada dalam Data =" << endl;
				cout << "=====================================" << endl;
		}
	} 
	return 0;
}

void circular_list::buat_node(string nik, string nama, string ttl, string jk, string alamat, string rt_rw, string agama, string sp, string pekerjaan, string kewarganegaraan){
struct node *temp;
	temp = new (struct node);
	temp -> nik = nik;
	temp -> nama = nama;
	temp -> ttl = ttl;
	temp -> jk = jk;
	temp -> alamat = alamat;
	temp -> rt_rw = rt_rw;
	temp -> agama = agama;
	temp -> sp = sp;
	temp -> pekerjaan = pekerjaan;
	temp -> kewarganegaraan = kewarganegaraan;
	if (akhir == NULL){
		akhir = temp;
		temp -> next = akhir;
	}
	else{
		temp -> next = akhir -> next;
		akhir -> next = temp;
		akhir = temp;
	}
}


void circular_list::insert_depan(string nik, string nama, string ttl, string jk, string alamat, string rt_rw, string agama, string sp, string pekerjaan, string kewarganegaraan){
	if ( akhir == NULL){
		cout << "============================================================================"<< "\n";
		cout << "= penambahan data tidak berhasil, anda harus membuat node terlebih dahulu! ="<< "\n";
		cout << "============================================================================"<< "\n";
		return;
	}
	struct node *temp;
	temp = new (struct node);
	temp -> nik = nik;
	temp -> nama = nama;
	temp -> ttl = ttl;
	temp -> jk = jk;
	temp -> alamat = alamat;
	temp -> rt_rw = rt_rw;
	temp -> agama = agama;
	temp -> sp = sp;
	temp -> pekerjaan = pekerjaan;
	temp -> kewarganegaraan = kewarganegaraan;
	temp -> next = akhir->next;
	akhir -> next = temp;
}


void circular_list::hapus_node(string nama){
	struct node *temp, *s;
	s = akhir -> next;
	// jika hanya ada 1 data list
	if (akhir -> next == akhir && akhir -> nama == nama){
		temp = akhir;
		akhir = NULL;
		free(temp);
		cout << " Data dengan nama " << nama << " Berhasil dihapus dalam list " << endl;
		return;
	}
	if (s -> nama == nama) { // jika hapus data depan / pertama
		temp = s;
		akhir -> next = s -> next;
		free(temp);
		cout << " Data dengan nama " << nama << " Berhasil dihapus dalam list " << endl;
		return;
	}
	while (s -> next != akhir){
	//untuk menghapus data diantara / ditengah
		if (s -> next -> nama == nama) {
			temp = s -> next;
			s -> next = temp -> next;
			free(temp);
			cout << " Data dengan nama " << nama << " Berhasil dihapus dalam list " << endl;
			return;
		}s = s -> next;
	}
	//untuk menghapus data diakhir
	if ( s -> next -> nama == nama){
		temp = s -> next;
		s -> next = akhir -> next;
		free(temp);
		akhir = s;
		cout << " Data dengan nama " << nama << " Berhasil dihapus dalam list " << endl;
		return;
	}
	cout << " Data dengan nama " << nama << " Tidak terdaftar di list " << endl;
	}


void circular_list::tampilkan_list(){
	struct node *s;
	if (akhir == NULL){
		cout << "=====================" << endl;
		cout << "= List masih kosong =" << endl;
		cout << "=====================" << endl
		<< endl;
		return;
	}
	s = akhir -> next;
	cout << "============================" << endl;
	cout << "= Isi Circular Linked List =" << endl;
	cout << "============================" << endl;
	while (s != akhir){
		cout <<"NIK\t\t\t: "<< s -> nik << "\n";
		cout <<"Nama\t\t\t: "<< s -> nama << "\n";
		cout <<"TTL\t\t\t: "<< s -> ttl << "\n";
		cout <<"Jenis Kelamin\t\t: "<< s -> jk <<"\n";
		cout <<"Alamat\t\t\t: "<< s -> alamat <<"\n";
		cout <<"RT/RW\t\t\t: "<< s -> rt_rw <<"\n";
		cout <<"Agama\t\t\t: "<< s -> agama <<"\n";
		cout <<"Status\t\t\t: "<< s -> sp <<"\n";
		cout <<"Pekerjaan\t\t: "<< s -> pekerjaan <<"\n";
		cout <<"Kewarganegaraan\t: "<< s -> kewarganegaraan <<"\n";
		cout <<"\n";
		s = s -> next;

	}
		cout <<"NIK\t\t\t: "<< s -> nik << "\n";
		cout <<"Nama\t\t\t: "<< s -> nama << "\n";
		cout <<"TTL\t\t\t: "<< s -> ttl << "\n";
		cout <<"Jenis Kelamin\t\t: "<< s -> jk <<"\n";
		cout <<"Alamat\t\t\t: "<< s -> alamat <<"\n";
		cout <<"RT/RW\t\t\t: "<< s -> rt_rw <<"\n";
		cout <<"Agama\t\t\t: "<< s -> agama <<"\n";
		cout <<"Status\t\t\t: "<< s -> sp <<"\n";
		cout <<"Pekerjaan\t\t: "<< s -> pekerjaan <<"\n";
		cout <<"Kewarganegaraan\t: "<< s -> kewarganegaraan <<"\n";
		cout <<"\n";
}
