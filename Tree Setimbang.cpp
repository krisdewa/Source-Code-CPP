#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#define pow2(n) (1 << (n))
using namespace std;

//Node Deklarasi
struct avl_node{
	int data;
	struct avl_node *kiri;
	struct avl_node *kanan;
}*root;

//Deklarasi Class
class TreeSetimbang {
	public:
		int tinggi(avl_node *);
		int selisih(avl_node *);
		avl_node *kanankanan_rotasi(avl_node *);
		avl_node *kirikiri_rotasi(avl_node *);
		avl_node *kirikanan_rotasi(avl_node *);
		avl_node *kanankiri_rotasi(avl_node *);
		avl_node* setimbang(avl_node *);
		avl_node* input(avl_node *, int );
		void output(avl_node *, int);
		void inorder(avl_node *);
		void preorder(avl_node *);
		void postorder(avl_node *);
		TreeSetimbang(){
			root = NULL;
		}
};

//tinggi of AVL Tree

int TreeSetimbang::tinggi(avl_node *tmp) {
	int h = 0;
	if (tmp != NULL) {
		int l_tinggi = tinggi (tmp -> kiri);
		int r_tinggi = tinggi (tmp -> kanan);
		int max_tinggi = max (l_tinggi, r_tinggi);
		h = max_tinggi + 1;
	}
	return h;
}

//tinggi Selisih

int TreeSetimbang::selisih(avl_node *tmp) {
	int l_tinggi = tinggi (tmp -> kiri);
	int r_tinggi = tinggi (tmp -> kanan);
	int b_factor = l_tinggi - r_tinggi;
	return b_factor;
}

//kanan- kanan rotasi

avl_node *TreeSetimbang::kanankanan_rotasi(avl_node *parent) {
	avl_node *tmp;
	tmp = parent-> kanan;
	parent -> kanan = tmp->kiri;
	tmp -> kiri = parent;
	return tmp;
}

//memutar kekiri

avl_node *TreeSetimbang::kirikiri_rotasi(avl_node *parent) {
	avl_node *tmp;
	tmp = parent -> kiri;
	parent -> kiri = tmp -> kanan;
	tmp -> kanan = parent;
	return tmp;
}

//Kiri - Kanan rotasi

avl_node *TreeSetimbang::kirikanan_rotasi(avl_node *parent) {
	avl_node *tmp;
	tmp = parent -> kiri;
	parent -> kiri = kanankanan_rotasi (tmp);
	return kirikiri_rotasi (parent);
}

//kanan - kiri rotasi

avl_node *TreeSetimbang::kanankiri_rotasi(avl_node *parent) {
	avl_node *tmp;
	tmp = parent -> kanan;
	parent -> kanan = kirikiri_rotasi (tmp);
	return kanankanan_rotasi (parent);
}

//Seimbang tree

avl_node *TreeSetimbang::setimbang(avl_node *tmp) {
	int bal_factor = selisih (tmp);
	if (bal_factor > 1) {
		if (selisih (tmp -> kiri) > 0)
			tmp = kirikiri_rotasi (tmp);
		else
			tmp = kirikanan_rotasi (tmp);
	} else if (bal_factor < -1) {
		if (selisih (tmp -> kanan) > 0)
			tmp = kanankiri_rotasi (tmp);
		else
			tmp = kanankanan_rotasi (tmp);
	}
	return tmp;
}

//input value tree
avl_node *TreeSetimbang::input(avl_node *root, int value) {
	if (root == NULL) {
		root = new avl_node;
		root -> data = value;
		root -> kiri = NULL;
		root -> kanan = NULL;
		return root;	
	} else if (value < root -> data) {
		root -> kiri = input(root -> kiri, value);
		root = setimbang (root);
	} else if (value >= root -> data) {
		root -> kanan = input(root -> kanan, value);
		root = setimbang (root);
	}
	return root;
}

//Hasil tree
void TreeSetimbang::output(avl_node *ptr, int level) {
	int i;
	if (ptr!=NULL) {
		output(ptr -> kanan, level + 1);
		cout << "\n";
		if (ptr == root)
			cout<<"Root -> ";
		for (i = 0; i < level && ptr != root; i++)
			cout<<"       ";
			cout<<ptr -> data;
			output(ptr -> kiri, level + 1);
	} 
}

//Inorder Traversal of AVL Tree
void TreeSetimbang::inorder(avl_node *tree) {
	if (tree == NULL)
		return;
		inorder (tree -> kiri);
		cout << tree -> data <<" ";
		inorder (tree -> kanan);
	}

//Preorder Traversal of AVL Tree
void TreeSetimbang::preorder(avl_node *tree) {
	if (tree == NULL)
		return;
		cout<<tree -> data<<" ";
		preorder (tree -> kiri);
		preorder (tree -> kanan);
}

//Postorder Traversal of AVL Tree
void TreeSetimbang::postorder(avl_node *tree) {
	if (tree == NULL)
		return;
		postorder ( tree -> kiri );
		postorder ( tree -> kanan );
		cout<<tree->data<<" "; 
}

//Main
int main() {
	int pilih, value;
	TreeSetimbang tree;
	while (1) {
		cout <<"\n===================================\n"
			 <<"    Implementasi Pohon Setimbang   \n"
			 <<"===================================\n"
			 << " 1. Input Value	\n"
			 << " 2. Tampilkan Pohon\n"
			 << " 3. InOrder	 	\n"
			 << " 4. PreOrder  		\n"
			 << " 5. PostOrder 		\n"
			 << " 6. Keluar	 		\n"
			 <<"===================================\n"
			 <<" Masukkan Pilihan : "; cin >> pilih;
		cout <<"===================================\n\n";
		switch(pilih) {
			case 1:
				cout<<" Masukkan Value : "; cin >> value;
				root = tree.input(root, value);
				system("pause"); system("cls");
				break;
				
			case 2:
				if (root == NULL) {
					cout<<" Pohon Kosong"<<endl;
					continue;
					system("pause"); system("cls");
				}
				cout<<" Pohon Setimbang:"<<endl;
				tree.output(root, 1);
				cout << "\n\n\n";
				system("pause"); system("cls");
				break;
			case 3:
				cout <<" Inorder :"<<endl;
				tree.inorder(root);
				cout <<endl;
				system("pause"); system("cls");
				break;
			case 4:
				cout<<" Preorder :"<<endl;
				tree.preorder(root);
				cout<<"\n";
				system("pause"); system("cls");
				break;
			case 5:
				cout<<" Postorder :"<<endl;
				tree.postorder(root); 
				cout<<"\n";
				system("pause"); system("cls");
				break;
			case 6:
				exit(1); 
				break;
			default:
				cout<<" Pilihan Anda Tidak ada"<<endl;
		}
	}
	return 0; 
}
