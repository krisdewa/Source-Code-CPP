#include <iostream>
#include <cstdlib>
#define JUMLAH 10
using namespace std;

class Stack {
    struct data{
        int top;
		int data[JUMLAH];
    } TStack;
    
public :
    bool Kosong();
    bool Penuh();
    void Push();
    void Pop();
    void TampilkanStack();
    void clear();
}; 

void Stack::clear(){
    TStack.top = -1;
}

bool Stack::Kosong(){
    return TStack.top == -1;
}

bool Stack::Penuh(){
    return TStack.top == JUMLAH - 1;
}

void Stack::Push() {
    if (Penuh()){
        cout << "\n Stack sudah Penuh \n\n";
    } else {
        TStack.top++;
        cout << "\n Masukkan Data : ";
        cin >> TStack.data[TStack.top];
        cout << " Data " << TStack.data[TStack.top] << " Masuk ke stack \n\n";
    }
}

void Stack::Pop() {
    if (Kosong()) {
        cout << "\n Data kosong \n\n" ;
    } else {
        cout << "\n Data " << TStack.data[TStack.top] << " Sudah Diambil \n\n";
        TStack.top--;
    }
}

void Stack::TampilkanStack() {
    if(Kosong()) {
        cout << "           Stack : "     <<"\n"
        	 << "||=======================|| \n"
        	 << "          Kosong !          \n"
			 << "||=======================|| \n";
    } else {
        cout << "          Stack : ";
        cout << "\n||=======================|| \n";
        for(int i = TStack.top; i >= 0; i--){
        	cout << "||   =====[ " << TStack.data[i] << " ]=====    || \n";
        } 
		cout << "||=======================|| \n";
    }
}

int main() {
    int pilih,data;
    Stack Arrdinamis;
    Arrdinamis.clear();
    do {
        Arrdinamis.TampilkanStack();
        cout << " \n\n"
			 << " MENU PILIHAN :   \n"
        	 << " [1] PUSH (INPUT)  \n" 
			 << " [2] POP  (HAPUS)  \n" 
			 << " [3] EXIT (KELUAR) \n \n" 
			 << " Masukkan pilihan : "; cin >> pilih;
		cout << "========================= \n";
        switch (pilih) {
            case 1 :
                Arrdinamis.Push();
                system("pause");
                system("cls");
                break;
            case 2 :
                Arrdinamis.Pop();
                system("pause");
                system("cls");
                break;
            default:
                cout << "pilihan anda tidak tersedia \n";
                system("pause");
                system("cls");
                break;
        }
    } 
	while (pilih != 3);
	cout << " =====< Terimakasih >===== ";
    
    
}
