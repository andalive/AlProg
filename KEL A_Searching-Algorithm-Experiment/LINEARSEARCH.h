//Definisi fungsi linear search
int linearSearch(int size_arr, int arr[], int key) {
	int i;
	
	for (i = 0; i < size_arr; i++) {
		if (arr[i] == key) {
			return i;            //mengembalikan indeks array jika elemen ditemukan
		}
	}
	
	return -1;                   //mengembalikan -1 jika elemen tidak ditemukan
}
