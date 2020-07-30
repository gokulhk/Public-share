#include <iostream>

using namespace std;

int main(){


	//converts ascii num to orginal int num

	string value = "54";

	//extracting decimal value
	int val = value[0] - '0';
	val *= 10;
	val += value[1] - '0';

	cout<<val;

}
