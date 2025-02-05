//selection sort
#include <iostream>
using namespace std;

void printElements(int *array,int length) //print array elements
{
    int i=0;
    //for(i=0;i<10;i++)
	//	cout<<array[i]<<",";
	//cout<<endl;
	for(i=0;i<10;i++)
        std::cout<<array[i]<<endl;
}

void selectionSort(int *array,int length)//selection sort function 
{
    int i,j,min,minat;
    for(i=0;i<(length-1);i++)
    {
        minat=i;
        min=array[i];

      for(j=i+1;j<(length);j++) //select the min of the rest of array
      {
          if(min>array[j])   //ascending order for descending reverse
          {
              minat=j;  //the position of the min element 
              min=array[j];
          }
      }
      int temp=array[i] ;
      array[i]=array[minat];  //swap 
      array[minat]=temp; 
	  //printElements(array,10);
    }
}



void main()
{

    int a[]={9,6,5,23,2,6,2,7,1,8};   // array to sort 
    selectionSort(a,10);                 //call to selection sort  
    printElements(a,10);               // print elements 
}
