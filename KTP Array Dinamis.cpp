//1900018336_KrisnaDewaPratama_RESPONSISTRUKTURDATA
#include <iostream>
using namespace std;

struct dataKtp{
	string nik, nama, ttl, jenis_kelamin, darah, alamat, agama, status, pekerjaan, warga, rt, rw, ds, kc;
}; dataKtp dataKTP[100];
	
class KTP {
	private :
		int N;
	public :
		void input();
		void output();
};

void KTP::input(){
	cout <<"\n Masukan Berapa Banyak Data(N) : "; cin >> N; cin.ignore();
	if(N <= 100){
		for(int i = 0; i < N; i++){			
			cout<<"\n=============== Input Data KTP ke-"<< i + 1 << "=====================\n";
	        cout << " Silahkan Input NIK 		: "; getline(cin,dataKTP[i].nik);
		    cout << " Silahkan Input Nama            : "; getline(cin,dataKTP[i].nama);
		    cout << " Silahkan Input TTL	        : "; getline(cin,dataKTP[i].ttl);
		    cout << " Silahkan Input Golongan Darah  : "; getline(cin,dataKTP[i].darah);
		    cout << " Silahkan Input Jenis Kelamin	: "; getline(cin,dataKTP[i].jenis_kelamin);
		    cout << " Silahkan Input alamat 		: "; getline(cin,dataKTP[i].alamat);
		    cout << " Silahkan Input	RT 		: "; getline(cin,dataKTP[i].rt);
		    cout << " Silahkan Input	RW		: "; getline(cin,dataKTP[i].rw);
		    cout << " Silahkan Input Desa 		: "; getline(cin,dataKTP[i].ds);
		    cout << " Silahkan Input kecamatan 	: "; getline(cin,dataKTP[i].kc);
		    cout << " Silahkan Input agama 		: "; getline(cin,dataKTP[i].agama);
		    cout << " Silahkan Input status 		: "; getline(cin,dataKTP[i].status);
		    cout << " Silahkan Input Pekerjaan 	: "; getline(cin,dataKTP[i].pekerjaan);
		    cout << " Silahkan Input kewarganegaraan : "; getline(cin,dataKTP[i].warga);
			cout<<"=======================================================\n";
		}
	}else {
		cout<<"Maaf inputan anda melebihi kapasitas yg bisa diisi !!!"<<endl;
	}
}
void KTP::output(){
	if(N <= 100){
		for(int i = 0; i < N; i++){
			cout<<"\n=============== Print Data KTP ke-"<< i + 1 << "=====================\n";
	        cout << " NIK                  : " << dataKTP[i].nik << endl;
		    cout << " Nama                 : " << dataKTP[i].nama << endl;
		    cout << " Tempat/Tgl Lahir     : " << dataKTP[i].ttl << endl;
		    cout << " Jenis Kelamin        : " << dataKTP[i].jenis_kelamin << "\tGol. Darah : " << dataKTP[i].darah << endl;
		    cout << " Alamat               : " << dataKTP[i].alamat << endl;
		    cout << "      RT/RW           : " << dataKTP[i].rt << "/" << dataKTP[i].rw << endl;
		    cout << "      Kel/Desa        : " << dataKTP[i].ds << endl;
		    cout << " Kecamatan            : " << dataKTP[i].kc << endl;
	    	cout << " Agama                : " << dataKTP[i].agama << endl;
		    cout << " Status               : " << dataKTP[i].status << endl;
		    cout << " Pekerjaan            : " << dataKTP[i].pekerjaan << endl;
		    cout << " Kewarganegaraan      : " << dataKTP[i].warga << endl;
		    cout << " Berlaku Hingga       : SEUMUR HIDUP" << endl;
			cout<<"=========================================================\n";
		}
	}
}

int main(){
	KTP *ResponsiKTP;
	ResponsiKTP = new KTP;
	ResponsiKTP -> input();
	ResponsiKTP -> output();
	return 0;
}
