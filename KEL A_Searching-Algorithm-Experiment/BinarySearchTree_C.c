//PROGRAM       : BINARY SEARCH TREE ALGORITHM
//KELOMPOK A    :
//HANNA MALIKA AZ-ZAHRA   (NPM: 2206055914)
//VIVA INOVA PINKY        (NPM: 2206056002)
//HANA RAISSA EARLABIBA   (NPM: 2206056160)
//CAMELIA PUTRI           (NPM: 2206812804)

//TANGGAL       : 08/06/2024
//VERSI         : 1.1       (MODIFIED: 09/03/2024)


#include <stdio.h>
#include <stdlib.h>

#define RED    "\033[1;31m"  //format teks warna merah  + tebal
#define GREEN  "\033[1;32m"  //format teks warna hijau  + tebal
#define RESET  "\033[0m"     //mengembalikan format teks asli


//Definisi struktur node
struct node {
   int key;                              //kunci (key) atau nilai node
   struct node *leftChild, *rightChild;  //pointer leftChild dan righChild ke struct node
};

//Fungsi untuk membuat node BST baru
struct node *newNode(int item){
   struct node *temp = (struct node *)malloc(sizeof(struct node)); //alokasi memori node baru
   temp->key = item;                                               //isi kunci dengan nilai yang diberikan
   temp->leftChild = temp->rightChild = NULL;                      //inisialisasi pointer left dan right child ke NULL
   return temp;                                                    //mengembalikan pointer ke node baru
}

//Fungsi untuk menyisipkan node
struct node* insert(struct node* node, int key){
	//Jika tree kosong (empty)
	if(node == NULL) {
    	return newNode(key);                               //node baru dikembalikan sebagai root
	}
	
	if (key < node->key){                                    
		node->leftChild = insert(node->leftChild, key);    //traverse ke sisi kiri dan sisipkan node
	} else if (key > node->key) {                            
		node->rightChild = insert(node->rightChild, key);  //trancese ke sisi kanan dan sisipkan node
	}
	
	return node;                                           //mengembalikan node             
}

//Fungsi untuk mencari node dengan kunci tertentu
struct node* search(struct node* root, int key){
	//Jika root = NULL atau kunci ditemukan pada root
	if (root == NULL || root->key == key) {
		return root;
	}
	//Jika kunci lebih besar dari kunci root
	if (root->key < key) {
		return search(root->rightChild, key);  // mengembalikan node dari pencarian subtree kanan
	}
	//Jika kunci lebih kecil dari kunci root
	return search(root->leftChild, key);       // mengembalikan node dari pencarian subtree kiri
}

//Fungsi untuk menampilkan node dalam urutan traversal in-order
void inOrder(struct node* root){
    if (root != NULL) {
        inOrder(root->leftChild);   //traverse kiri
        printf("%d; ", root->key);  //traverse root
        inOrder(root->rightChild);  //traverse kanan
    }
}


int main(void){
	int k, cont = 1;
	struct node *root = NULL;    //inisialisasi root tree = NULL (kosong)
	struct node* result;         //deklarasi pointer untuk hasil pencarian
	
	root = insert(root, 21);     //inisialisasi root = 21
	insert(root, 14);
	insert(root, 11);
	insert(root, 19);
	insert(root, 5);
	insert(root, 13);
	insert(root, 1);
	insert(root, 7);
	insert(root, 51);
	insert(root, 37);
	insert(root, 84);
	insert(root, 69);
	insert(root, 99);
	insert(root, 91);
	insert(root, 100);
	
	//Menampilkan node pada binary tree
	printf("<BINARI SEARCH TREE>\nInOrder BST:\n");
    inOrder(root);
    printf("\n==============================================================================\n\n");
	
	while (cont == 1) {
		printf("Cari nilai: ");
		scanf("%d", &k);
		
		result = search(root, k);
		
		//Menampilkan hasil pencarian elemen
		if (result != NULL) {
			printf(GREEN"Element found in the tree"RESET"\n\n");
		} else {
			printf(RED"Element not found"RESET"\n\n");
		}
		
		printf("Lanjut [1]Y/[0]N: ");
		scanf("%d", &cont);
		while (cont != 0 && cont != 1) {
			printf(RED"<INVALID INPUT>"RESET" Lanjut [1]Y/[0]N: ");
			scanf("%d", &cont);
		}
		printf("==============================================================================\n");
	}	
	
	return 0;
}
