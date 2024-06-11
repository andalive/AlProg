//
// DATA EKSPERIMEN
// SEARCHING ALGORITHM
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "LINEARSEARCH.h"
#include "BINARYSEARCH.h"

#define MAX_ITER_COUNT 1000000


//Definisi struktur node
struct node {
   int key;
   struct node *leftChild, *rightChild;
};

//Fungsi untuk membuat node BST baru
struct node *newNode(int item){
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   temp->key = item;
   temp->leftChild = temp->rightChild = NULL;
   return temp;
}

//Fungsi untuk menyisipkan node
struct node* insert(struct node* node, int key){
	if(node == NULL) {
    	return newNode(key);
	}
	
	if (key < node->key){
		node->leftChild = insert(node->leftChild, key);
	} else if (key > node->key) {
		node->rightChild = insert(node->rightChild, key);
	}
	
	return node;
}

//Fungsi untuk mencari node dengan kunci tertentu
struct node* search(struct node* root, int key){
	if (root == NULL || root->key == key) {
		return root;
	}
	
	if (root->key < key) {
		return search(root->rightChild, key);
	}
	
	return search(root->leftChild, key);
}

// Function to print the tree nodes and their children
void inOrder(struct node* root){
    if (root != NULL) {
        inOrder(root->leftChild);
        printf("%d; ", root->key);
        inOrder(root->rightChild);
    }
}

/*===========================================================================================================*/

int main (void) {
	//int arr1[] = {32, 5, 100, 6, 41, 1, 73, 14, 9, 11, 12, 15, 21, 58, 7, 3, 37, 201, 13, 911, 59};
	//int size1 = sizeof(arr1) / sizeof(arr1[0]);
	
	struct node *root = NULL;
	struct node* result;
	
	root = insert(root, 21);
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
	
	int arr[] = {1, 5, 7, 11, 13, 14, 19, 21, 37, 51, 69, 84, 91, 99, 100};
	int size = sizeof(arr) / sizeof(arr[0]);
	int k1, /*k2,*/ result1, result2, iter, i;
	
	printf("InOrder BST: ");
    inOrder(root);
	printf("\nElemen array: [1, 5, 7, 11, 13, 14, 19, 21, 31, 51, 69, 84, 91, 99, 100]\n");
	printf("Size-array: %d\n\n>> Cari nilai: ", size);
	scanf("%d", &k1);
	
	for (i = 0; i < 10; i++) {
		printf("--------------------------------------------------\n");
		printf("DATA-%d\n", i+1);
		
		/*============================================[  linear search  ]============================================*/
		//kalkulasi execution time algorithm
		clock_t start1, end1;
		start1 = clock();
		for (iter = 0; iter < MAX_ITER_COUNT; iter++) {
			//result1 = linearSearch(size1, arr1, k1);
			result1 = linearSearch(size, arr, k1);
		}
		end1 = clock();
		double excTime1 = (double)(end1 - start1) * 100000 / CLOCKS_PER_SEC / MAX_ITER_COUNT;
		
		//hasil search algorithm
		if (result1 != -1) {
			printf("<LINEAR SEARCH>\nElement found at index: %d\n", result1);
		} else {
			printf("<LINEAR SEARCH>\nElement not found\n");
		}
		
		printf("Run time: %lf s\n", excTime1);
		
		
		/*============================================[  binary search  ]============================================*/	
		//printf("Cari nilai: ");
		//scanf("%d", &k2);
		
		clock_t start2, end2;
		start2 = clock();
		for (iter = 0; iter < MAX_ITER_COUNT; iter++) {
			//result2 = binarySearch(arr2, k2, 0, size2 - 1);
			result2 = binarySearch(arr, k1, 0, size - 1);
		}
		end2 = clock();
		double excTime2 = (double)(end2 - start2) * 100000 / CLOCKS_PER_SEC / MAX_ITER_COUNT;
		
		
		if (result2 != -1) {
			printf("<BINARY SEARCH>\nElement found at index: %d\n", result2);
		} else {
			printf("<BINARY SEARCH>\nElement not found\n");
		}
		
		printf("Run time: %lf s\n", excTime2);
		
		
		/*============================================[  BST  ]============================================*/
		clock_t start3, end3;
		start3 = clock();
		for (iter = 0; iter < MAX_ITER_COUNT; iter++) {
			result = search(root, k1);
		}
		end3 = clock();
		double excTime3 = (double)(end3 - start3) * 100000 / CLOCKS_PER_SEC / MAX_ITER_COUNT;
		
		
		if (result != NULL) {
			printf("<BST>\nElement found in the tree\n");
		} else {
			printf("<BST>\nElement not found\n");
		}
		
		printf("Run time: %lf s\n", excTime3);
	}
	
	
	return 0;
}


