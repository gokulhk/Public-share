#include<iostream>

using namespace std;

void binarySearchRecursive(int[], int, int, int);

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

		//call binary search sub routine - recursive ver
		binarySearchRecursive(bucket, 0, size-1, search);

		cout<<endl;
	}
}

void binarySearchRecursive(int bucket[], int left, int right, int search){

	if( left > right ){
		cout<<"Rec : Element doesn't exist";
		return;
	}

	//mid calculation
	int mid  = left + ( right - left ) / 2;

	if( bucket[mid] == search){
		cout<<"Rec : Element exists at index : "<<mid;
		return;
	}
	else if( bucket[mid] > search ){
		binarySearchRecursive( bucket, left, mid-1, search );
	}
	else{
		binarySearchRecursive( bucket, mid+1, right, search );
	}
}