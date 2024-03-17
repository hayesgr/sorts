void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int partition(int *arr,int s){
    int pivot_value = arr[s-1];
    int i = 0;
    for(int j =0;j<s-1;j++){
        if(arr[j]<=pivot_value){
            swap(&arr[i],&arr[j]);
            i++;
        }
    }
    swap(&arr[i],&arr[s-1]);
    return i;
}
//quicksort clang  2.4 seconds 10,000,000 mingw-w64 gcc 2.4 seconds
//clang 93 second 100,000,000 mingw-w64 100 seconds
void quicksort(int *arr, int s){
    if(s>1){
        int pivot_index = partition(arr,s);
        quicksort(arr,pivot_index);
        quicksort(arr+pivot_index,s-pivot_index);
    }
}
//Buoyancy is just an insertion sort
//buoyancy 4.3 seconds 100,000 clang mingw_w64 gcc 15 seconds -O2 on both
//clang 381 seconds for 1,000,000 mingw-w64 1513 seconds
void buoyancy(int *arr,int s){
    int n=1,p=0;
    while(n<s){
        p=n>p?n:p;
        if(n>0 && arr[n-1]>arr[n]){
            swap(&arr[n],&arr[n-1]);
            n--;
        }
        else{
            n = n<p?p+1:n+1;
        }
    }
}
//bubblesort2 clang 14.7 seconds 100,000 mingw_w64 28 seconds
void bubblesort2(int arr[],int n){
    for (int i=n-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
//bubblesort clang 14.7 seconds 100,000 mingw_w64 27 seconds
void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
/*
potential performance improvements:
This can be reduced to fewer loops probably just 1.
*/
//heapsort 4 clang 10 seconds for 100,000 gcc mingw-w64 28seconds
void heapsort4(int *arr,int s){
	unsigned int p=1,n=0,t=0;
	while(p<s){
		n = p>n?p:n;
		while(t=p%2?p/2:p/2-1,p>0 && arr[p]<arr[t]){
            swap(&arr[p],&arr[t]);
            p=t;
		}
		p=n+1;
	}
	if(s>1){
        swap(&arr[1],&arr[s-1]);
        heapsort4(arr+1,s-1);
    }
}
//heapsort 3 clang 10 seconds for 100,000 gcc mingw-w64 12 seconds
#define tt p%2?p/2:p/2-1
void heapsort3(int *arr,int s){
	unsigned int p=1,n=0;
	while(p<s){
		n = p>n?p:n;
		while(p>0 && arr[p]<arr[tt]){
            swap(&arr[p],&arr[tt]);
            p=tt;
		}
		p=n+1;
	}
	if(s>1){
        swap(&arr[1],&arr[s-1]);
        heapsort3(arr+1,s-1);
    }
}
//heapsort 2 clang 11seconds for 100,000 gcc mingw-w64 12 seconds
void heapsort2(int *arr,int s){
	unsigned int p=1,t=0,n=0;
	while(p<s-1){
		n = p>n?p:n;
		t = p%2?p/2:p/2-1;
		if(p>0 && arr[p]<arr[t]){
			swap(&arr[p],&arr[t]);
			p=t;
		} else{
            p=n+1;
		}
	}
	if(s>1){
        swap(&arr[1],&arr[s-1]);
        heapsort2(arr+1,s-1);
    }
}
//heapsort clang 10seconds for 100,000 gcc mingw-w64 11 second
//clang 838 seconds 1,000,000 mingw-w64 945 seconds
void heapsort(int arr[],int s){
    int p,t;
    for (int i=1;i<s-1;i++){
        p=i;
        while(p>0){
            t = p%2?p/2:p/2-1;
            if(arr[p]<arr[t]){
                swap(&arr[p],&arr[t]);
                p=t;
            } else {
                break;
            }
        }
    }
    if(s>1){
        swap(&arr[1],&arr[s-1]);
        heapsort(arr+1,s-1);
    }
}
