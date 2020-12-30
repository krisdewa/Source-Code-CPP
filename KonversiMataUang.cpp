#include <iostream>
using namespace std;

double a,b,c,d,e,f,g;
int pilih;

void konversi(double a){
	
	b = a / 14192;
	c = a / 9871;
	d = a / 10028;
	e = a / 1702;
	f = a / 18017;
	g = a / 11634;
	
	awal :
		
	cout << " Pilih : \n";
	cout << " 1. Rupiah ke USD \n";
	cout << " 2. Rupiah ke SGD \n";
	cout << " 3. Rupiah ke AUD \n";
	cout << " 4. Rupiah ke EUR \n";
	cout << " 5. Rupiah ke HKD \n";
	cout << " 6. Rupiah ke JPY \n";
	cout << " 7. Tampilkan Semua \n";
	cout << "Masukkan Pilihan anda : ";cin >> pilih;
	
	switch(pilih){
		case 1 :
			cout<<"\nRupiah ke USD\n(US Dollar)\t\t= " 		<< b << endl;
			break;
		case 2 :
			cout<<"\nRupiah ke SGD\n(Singapore Dollar)\t= " << c << endl;
			break;
		case 3 :
			cout<<"\nRupiah ke AUD\n(Australian Dollar)\t= "<< d << endl;
			break;
		case 4 :
			cout<<"\nRupiah ke EUR\n(EURO)\t\t\t= "			<< e << endl;
			break;
		case 5 :
			cout<<"\nRupiah ke HKD\n(Hongkong Dollar)\t= "	<< f << endl;
			break;
		case 6 :
			cout<<"\nRupiah ke JPY\n(Japanese Yen)\t\t= "	<< g << endl;
			break;
			
		case 7 :
			cout<<"\nRupiah ke USD\n(US Dollar)\t\t= " 		<< b << endl;
			cout<<"\nRupiah ke SGD\n(Singapore Dollar)\t= " << c << endl;
			cout<<"\nRupiah ke AUD\n(Australian Dollar)\t= "<< d << endl;
			cout<<"\nRupiah ke EUR\n(EURO)\t\t\t= "			<< e << endl;
			cout<<"\nRupiah ke HKD\n(Hongkong Dollar)\t= "	<< f << endl;
			cout<<"\nRupiah ke JPY\n(Japanese Yen)\t\t= "	<< g << endl;
			break;
			
		default :
			cout << "Pilihan anda gk ada woi ";
			
	}
}

main(){
	cout << "Masukan Nominal Uang Rupiah anda = " << " Rp. "; cin >> a;
	konversi(a);
}
