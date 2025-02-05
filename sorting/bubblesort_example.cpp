#include <stdio.h>
#include <iostream>
using namespace std;

void printElements(int *array,int length) //print array elements
{
    int i=0;
    for(i=0;i<10;i++)
        std::cout<<array[i]<<", ";
    std::cout << endl;
}

void bubbleSort(int *array,int length)//Bubble sort function 
{
    int i,j;
    for(i=0;i<10;i++)
    {
        for(j=0;j<i;j++)
        {
            if(array[i]<array[j])
            {
				// conventional swap
                int temp=array[i];  
                array[i]=array[j];
                array[j]=temp;

				// XOR swap
				//array[i]^=array[j];
				//array[j]^=array[i];
				//array[i]^=array[j];

				printElements(array, length);
            }

        }

    }

}
/*
void printElements(int *array,int length) //print array elements
{
    int i=0;
    for(i=0;i<10;i++)
        cout<<array[i]<<endl;
}
*/


int main()
{

    int a[]={9,6,5,23,2,6,2,7,1,8};   // array to sort 
    bubbleSort(a,10);                 //call to bubble sort  
    printElements(a,10);               // print elements
}