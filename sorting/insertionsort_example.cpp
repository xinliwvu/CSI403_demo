#include<iostream>
using namespace std;

#define N 10

int main(){
    int i, key;
    
    //create array and store numbers to sort
    //int num[N] = {15,65,23,76,4,12,33,54,28,70};
    // a nearly-sorted array: each value is no more than 2 elements away from its right position
	int num[N] = {15,4,12,23,33,28,54,65,76,70};
	int l=N;
	int cnt;
    
    // Display unsorted array
    cout<<endl<<"Unsorted array\t";
    for(i=0;i<N;i++)
       cout<<num[i]<<"\t";
       
	cnt=0;
    // perform insertion sort
    for(int j=1;j<N;j++)
    {
        i=j-1;
        key=num[j];
        while(i>=0 && num[i]>key)
        {
                    num[i+1]=num[i];
                    i--;
					cnt++;
        }
        num[i+1]=key;
    }
    
    //Display sorted array
    cout<<endl<<"Sorted Array\t";
     for(i=0;i<N;i++)
       cout<<num[i]<<"\t"; 
	 printf("\ncnt=%d\n",cnt);
    cout<<endl;   
    //system("Pause");
}