//Definisi fungsi untuk menampilkan array
void dispArray(int size_arr, int arr[]) {
	int i;
	
	for (i = 0; i < size_arr; i++) {
		printf("%d  ", arr[i]);
	}
	printf("\n");
}


//Fungsi untuk menambahkan data array
void addArray(int size_arr, int arr[]) {
	int i;
	
	for(i = 0; i < size_arr; i++) {
		printf("Index #%d: ", i);
		scanf("%d", &arr[i]);
	}
}
