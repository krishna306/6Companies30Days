ull getNthUglyNo(int n) {
	vector<ull>a(n);
	a[0]=1;
	if(n==1){
	   return 1;
	}
	ull ugly =0,i2=0,i3=0,i5=0;
	for(int i=1;i<n;i++){
	    a[i] = min(min(a[i2]*2,a[i3]*3),a[i5]*5);
	    ugly = a[i];
	    if(ugly == a[i2]*2){
	        i2++;
	    }
	    if(ugly == a[i3]*3){
	        i3++;
	    }
	    if(ugly == a[i5]*5){
	        i5++;
	    }
	}
	return a[n-1];
}