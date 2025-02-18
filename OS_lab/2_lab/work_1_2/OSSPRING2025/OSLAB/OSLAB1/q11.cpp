#include<iostream>
using namespace std;

int main(int argc, char *arg[]){
	int arr[8] = {12,54,13,1,2,5,6,3};
	int sum =0;
	for(int i =0;i<8	;++i){
		sum += arr[i];
	}
	
	
	cout<<"Sum :"<<sum <<endl;
	

return 0;
}
