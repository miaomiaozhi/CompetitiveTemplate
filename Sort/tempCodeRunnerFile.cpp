sort (int q[] , int n) {
	int right = n , left = 1;
	int cnt = 0;
	for (int i = 0 ; i < n; i ++) {
		int flag = 0 , j;
		for (j = 1 ; j < right ; j ++) {
			if (q[j - 1] > q[j]) {
				swap (q[j - 1] , q[j]);
				flag = 1;
				cnt ++;
			}
		} 
		right = j - 1;
		if (!flag) break;
		for (j = n - 1 ; j >= left ; j --) {
			if (q[j - 1] > q[j]) {
				swap (q[j - 1] , q[j]);
				flag = 1;
				cnt ++;
			}
		}
		left = j + 1;
		if (!flag) break;
	}
	printf ("cnt = %d\n" , cnt);
}