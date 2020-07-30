#include<iostream>

using namespace std;

void printArray(int[], string, int);
void selectionSort(int[], int);
void bubbleSort(int[], int);
void insertionSort(int[], int);
void mergeSort(int[], int, int );
void merge(int[], int, int, int);
void quickSort(int[], int, int);
int partition(int[], int, int);

int main(){

	//intialise elements to sort -just a test array can be changed as required.
	int bucket[] = { 5, 3, 4, 8, 9, 2, 1, 7, 0};
	int bucket1[] = { 5, 3, 4, 8, 9, 2, 1, 7, 0};
	int bucket2[] = { 5, 3, 4, 8, 9, 2, 1, 7, 0};
	int bucket3[] = { 5, 3, 4, 8, 9, 2, 1, 7, 0};
	int bucket4[] = { 5, 3, 4, 8, 9, 2, 1, 7, 0};
	int len =9;

	printArray(bucket, "Before Sorting", len);
 	
 	selectionSort(bucket, len);
 	bubbleSort(bucket1, len);
 	insertionSort(bucket2, len);
 	mergeSort(bucket3, 0, len-1);
 	printArray(bucket3, "After MergeSort", len);
 	quickSort(bucket4, 0, len-1);
 	printArray(bucket4, "After quickSort:", len);

 	return 0;
}

void printArray(int bucket[], string msg, int len){

	cout<<"\n "<< msg <<" : [ ";
	for (int i = 0; i < len; ++i)
	{
		cout<<bucket[i]<<" ";
	}
	cout<<" ]"<<endl<<endl;
}

//T(n) = O(n^2)
//S(n) = O(1)
void selectionSort(int bucket[], int len){

	int min =0;

	for(int i=0; i<len-1; ++i){
		//Find min
		for(int j=i+1; j<len; ++j){
			if(bucket[min] > bucket[j]){
				min = j;
			}
		}

		//swap
		int temp = bucket[i];
		bucket[i] = bucket[min];
		bucket[min] = temp;
	}

	printArray(bucket, "After selectionSort", len);
}

//T(n) = O(n^2)
//S(n) = O(1)
void bubbleSort(int bucket[], int len){

	int swapped = 0;
	for (int i = 0; i < len; ++i)
	{
		swapped =0;
		for (int j = i+1; j < len; ++j)
		{
			if( bucket[i] > bucket[j]  ){
				int temp = bucket[i];
				bucket[i] = bucket[j];
				bucket[j] = temp;
				swapped =1;
			}
		}

		if(swapped == 0){
			break; // Best case T(n) = Omega(n)
		}
	}

	printArray(bucket, "After bubbleSort", len);
}

//T(n) = O(n^2)
//S(n) = O(1)
void insertionSort(int bucket[], int len){

	int key, j;

	for (int i = 1; i < len; ++i)
	{
		key = bucket[i];
		j=i-1;
		while( j>=0 && key < bucket[j] ){
			bucket[j+1] = bucket[j];
			--j;
		}

		bucket[j+1] = key;
	}

	printArray(bucket, "After insertionSort", len);
}

//T(n) = O(nlogn)
//S(n) = O(n)
void mergeSort(int bucket[], int left, int right){

	if(left<right){

		int middle = (left+right)/2;
		mergeSort(bucket, left, middle);
		mergeSort(bucket, middle+1, right);
		merge(bucket, left, right, middle);
	}
	//cout<<"Reached Depth"<<endl;
}

void merge(int bucket[], int left, int right, int middle){

	//new arrray for intermediate result storing
	int size1 = middle - left +1;
	int size2 = right - middle;
	int leftBucket[size1], rightBucket[size2];

	//copy first half to left bucket 
	for (int i = 0; i < size1; ++i)
	{
		leftBucket[i] = bucket[left + i];
	}

	//copy second half to right bucket 
	for (int i = 0; i < size2; ++i)
	{
		rightBucket[i] = bucket[middle +1 +i];
	}

	//cout<<"Left :"<<left<<" Right:"<<right<<" middle: "<<middle<<" size1: "<<size1<<" size2: "<<size2<<endl;

	int first =0, second = 0;
	while(first < size1 && second < size2){
		if(leftBucket[first] < rightBucket[second] ){
			bucket[left++] = leftBucket[first++];	
		}
		else{
			bucket[left++] = rightBucket[second++];
		}
	}

	if(first != size1){
		while(first<size1){
			bucket[left++] = leftBucket[first++]; 
		}
	}
	else if( second != size2){
		while(second < size2){
			bucket[left++] = rightBucket[second++];
		}
	}
	//printArray(leftBucket, "leftBucket", size1);
	//printArray(rightBucket, "rightBucket", size2);
	//printArray(bucket, "After merge", 9);
	//cout<<"-------------"<<endl;
}


//T(n) = O(n^2)
//S(n) = O(n) -- stack space itself in worst case
//Worst cases - already sorted(ASC, DESC), allsame elements -- it happens becasue split happend in ration of 0:n-1
//if split happens in 1:9 then T(n) = O(nlogn)  S(n) = O(logn)
void quickSort(int bucket[], int left, int right){

	if( left < right ){ //base case handler 

		int pos = partition( bucket, left, right);
		quickSort(bucket, left, pos-1);
		quickSort(bucket, pos+1, right);
	}
}

int partition(int bucket[], int left, int right){

	//printArray(bucket, "Bucket Received", 9);

	int pivot = bucket[right];

	int small = left-1;
	for(int j=left; j<right; j++){
		if( bucket[j] <= pivot ){
			small += 1;
			int temp = bucket[j];
			bucket[j] = bucket[small];
			bucket[small] = temp; 
		}
	}

	//swap last elem into its position
	int temp = bucket[small+1];
	bucket[small+1] = pivot;
	bucket[right] =temp;

	//printArray(bucket, "Bucket afterPartition", 9);
	//cout<<"-----------------------"<<endl;
	//return sorted elem position
	return small+1;
}
