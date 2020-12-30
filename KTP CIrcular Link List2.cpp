//1900018336_KrisnaDewaPratama_SELASA16.30
#include <iostream>
using namespace std;

struct node{
    string nik;
    string nama;
    string ttl;
    string jenis_kelamin;
    string alamat;
    string rt_rw;
    string agama;
    string status_perkawinan;
    string pekerjaan;
    string kwn;
    
    node* next; 
    node* prev;
} *depan = NULL, *belakang = NULL, *nd, *temp, *temp1;

class circular_linklist{
    public :
	    void enqueue();
	    void dequeue();
	    void tampilkanlist();
};
    
void circular_linklist::enqueue() {
    nd = new node();
    nd -> next = nd;
    nd -> prev = nd;
    
    cout << "\n";
    cout << " Masukkan NIK\t\t\t: "; 	getline(cin, nd -> nik);
	cout << " Masukkan Nama\t\t\t: "; 	getline(cin, nd -> nama);
	cout << " Masukkan TTL\t\t\t: "; 	getline(cin, nd -> ttl);
	cout << " Masukkan Jenis Kelamin\t\t: "; getline(cin, nd -> jenis_kelamin);
	cout << " Masukkan Alamat\t\t: "; 	getline(cin, nd -> alamat);
	cout << " Masukkan RT/RW\t\t\t: "; 	getline(cin, nd -> rt_rw);
	cout << " Masukkan Agama\t\t\t: "; 	getline(cin, nd -> agama);
	cout << " Masukkan Status\t\t: "; 	getline(cin, nd -> status_perkawinan);
	cout << " Masukkan Pekerjaan\t\t: "; getline(cin, nd -> pekerjaan);
	cout << " Masukkan Kewarganegaraan\t: "; getline(cin, nd -> kwn);
	
    if (depan == NULL){
        depan = nd;
        nd -> next = depan;
        nd -> prev = depan;
    } else {
        belakang = depan -> prev;
        belakang -> next = nd;
        nd -> prev = belakang;
        nd -> next = depan;
        depan -> prev = nd;
    }
}

void circular_linklist::dequeue() {
    string hapus;
    temp = depan;
    if ( depan == NULL ) {
        cout << "\n\n Queue Kosong / Belum diisi !!! \n\n";
    } else {
        if (depan -> next != depan) {
            hapus = depan -> nama;
            belakang = depan -> prev;
            depan = depan -> next;
            belakang -> next = depan;
            depan -> prev = belakang;
            delete (temp);
        } else {
            hapus = depan -> nama;
            depan = NULL;
        } 
		cout << " Data dengan nama " << hapus << " Berhasil dihapus " << endl;
    	tampilkanlist();
    }
}

void circular_linklist::tampilkanlist() {
    temp = depan;
    temp1 = NULL;
    if ( depan == NULL ) {
        cout << "\n\n Queue Kosong / Belum diisi !!!\n";
    } else {
        cout << "\n\n ISI QUEUE CIRCULAR LINK LIST : \n\n";
        while (temp != temp1) {
            cout << "\n==================================================\n";
            cout << " NIK\t\t\t: " << temp -> nik  <<"\n"
            	 << " Nama\t\t\t: " << temp -> nama <<"\n"
				 << " TTL\t\t\t: " << temp -> ttl  <<"\n"
				 << " Jenis Kelamin\t\t: " << temp -> jenis_kelamin <<"\n"
				 << " Alamat\t\t\t: " << temp -> alamat <<"\n"
				 << " RT/RW\t\t\t: " << temp -> rt_rw <<"\n"
				 << " Agama\t\t\t: " << temp -> agama <<"\n"
				 << " Status\t\t\t: " << temp -> status_perkawinan <<"\n"
				 << " Pekerjaan\t\t: "<< temp -> pekerjaan << "\n"
				 << " Kewarganegaraan\t: "<< temp -> kwn ;
            cout << "\n ==================================================\n";
            
            if( temp -> next != temp1 ){
                cout << " --> ";
            }
            temp = temp -> next;
            temp1 = depan;
        }
        cout<<" NULL"<<endl;
    }
    cout << endl;
}

int main(){
    circular_linklist queuecll;
    int pilih;
    do{
        system("cls");
        cout << "\n"
             << " ======================================= \n"
			 << " === Queue Berprioritas Circular KTP === \n"
		 	 << " ======================================= \n"
			 << "	 1.Tambah Data (Enqueue)  	\n"
			 << "  	 2.Hapus Data  (Dequeue)	\n"
			 << "  	 3.Tampilkan   		 		\n"
			 << "  	 4.Exit 	        	 	\n"
			 << " ======================================= \n";
        cout << " Masukan Pilihan: "; cin >> pilih; cin.ignore();
        cout << " ======================================= \n";
        switch (pilih){
            case 1 :
                queuecll.enqueue();
                system("pause");
                break;
            case 2 :
                queuecll.dequeue();
                cout << endl;
                system("pause");
                break;
            case 3 :
                queuecll.tampilkanlist();
                cout << endl;
                system("pause");
                break;
            case 4 :
                break;
            default:
                cout << "\n\n Pilihan anda salah!!" << endl;
                system("pause");
                cout <<"\n";
        }
    } while (pilih != 4);
    return 0;
}
