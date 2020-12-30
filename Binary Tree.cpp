#include <iostream>
#include <cstdlib>
using namespace std;

//Class Binarytree
class BinaryTree{

    private:
        struct nodeTree{
            nodeTree* kiri;
            nodeTree* kanan;
            char data;
        };
    	nodeTree* root;
    
    public:
        BinaryTree(){
        	root = NULL;
    	}
	    bool kosong()const{return root == NULL;}
	    void cetak_inorder();
	    void inorder(nodeTree*);
	    void cetak_preorder();
	    void preorder(nodeTree*);
	    void cetak_postorder();
	    void postorder(nodeTree*);
	    void insert_data(char);
    
};

//Input data
void BinaryTree::insert_data(char i){
    nodeTree* x = new nodeTree;
    nodeTree* parent;
    x -> data = i;
    x -> kiri= NULL;
    x -> kanan = NULL;
    parent = NULL;
    
    if(kosong())
        root = x;
    else{
        nodeTree* current;
        current = root;
        
        while(current){
            parent = current;
            if(x -> data > current -> data) current = current -> kanan;
            else current = current -> kiri;
        }     
        
        if(x -> data < parent -> data)
            parent -> kiri = x;
        else
            parent -> kanan = x;
    }
}
//fungsi inorder
void BinaryTree::cetak_inorder(){
    inorder(root);
}

void BinaryTree::inorder(nodeTree* y){
    if(y != NULL){
        if(y -> kiri)inorder(y -> kiri);
            cout <<" "<< y -> data <<" ";
        if(y -> kanan)inorder(y -> kanan);
    } else return;
}
//fungsi preorder
void BinaryTree::cetak_preorder(){
    preorder(root);
}

void BinaryTree::preorder(nodeTree* y){
    if(y != NULL){
        cout <<" " << y -> data <<" ";
        if(y -> kiri )preorder(y -> kiri);
        if(y -> kanan)preorder(y -> kanan);
    } else return;
}

//Fungsi postorder
void BinaryTree::cetak_postorder(){ 
    postorder(root);
}

void BinaryTree::postorder(nodeTree* y){
    if(y != NULL){
        if(y -> kiri)postorder(y -> kiri);
        if(y -> kanan)postorder(y -> kanan);
        cout << " " << y -> data << " ";
    }
    else return;
}

int main(){
    BinaryTree obj;
    int pilih;
    char tmp,tmp1;
    while(1){
        system("cls");
        cout << "\n\n";
        cout <<" =======================\n"
        	 <<" =====< POHON/TREE >====\n"
         	 <<" =======================\n"
        	 <<"  1. Insert Data \n"
        	 <<"  2. In-Order	 \n"
        	 <<"  3. Pre-Order	 \n"
        	 <<"  4. Post-Order	 \n"
        	 <<"  5. Exit		 \n"
        	 <<" =======================\n";
        cout <<" Masukan Pilihan : "; cin >> pilih;
        cout <<" =======================\n\n";
        switch(pilih){
        case 1:
            cout <<" Masukan Data : ";cin >> tmp;
            obj.insert_data(tmp);
            cout << "\n";
            system("PAUSE");
            break;
        case 2:
            cout<<"\nin-order:";
            obj.cetak_inorder();
            cout <<"\n";
            system("PAUSE");
            cout <<"\n";
            break;
        case 3:
            cout<<endl;
            cout <<"Pre-Order:";
            obj.cetak_preorder();
            cout <<"\n";
            system("PAUSE");
            break;
        case 4:
            cout <<"\n";
            cout<<"Post-Order:";
            obj.cetak_postorder();
            cout <<"\n";
            system("PAUSE");
            break;
        case 5:
            return 0;
        }
    }
}
