#include<iostream>

using namespace std;

void binarySearchIterative(int[], int, int);

int main(){

	//get test coutn
	int test;
	cin>>test;

	while(test--){

		//get array size
		int size;
		cin>>size;


		//get array elems
		int bucket[size];
		for(int i=0; i< size; ++i){
			cin>>bucket[i];
		}

		//get elem to be searched
		int search;
		cin>>search;

		//call binary sub routine - iterative version
		binarySearchIterative(bucket, size, search);
		cout<<endl;
		
	}
}

void binarySearchIterative(int bucket[], int size, int search){


	//make ptr
	int left = 0, right = size -1, mid;

	while( left <= right ){

		//mid calculation
		mid = left + ( ( right - left ) / 2);

		//cout<<" middle elem : "<<bucket[mid] << " search : "<<search<<endl;

		if( bucket[mid] == search ){
			cout<<"Found elem at index : "<<mid;
			return;
		}
		else if( bucket[mid] > search ){
			right = mid -1;
		}
		else{
			left = mid +1;
		}

	}

	cout<<"Element doesn't exist";
}