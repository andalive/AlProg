//Definisi fungsi binary search
int binarySearch (int arr[], int key, int low, int high) {
	while (low <= high) {
		int mid = low + (high - low) / 2;
		
		if (arr[mid] == key) {
			return mid;        //mengembalikan nilai mid jika elemen ditemukan
		}
		
		if (arr[mid] < key) {
			low = mid + 1;     //cek sisi kanan nilai mid
		} else {
			high = mid - 1;    //cek sisi kiri nilai mid
		}
	}
	
	return -1;                 //mengembalikan -1 jika elemen tidak ditemukan
}
