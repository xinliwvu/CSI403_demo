#include <iostream>  
      
    using namespace std;  
      
    void merge(int*,int,int,int);  
    void mergesort(int *a, int low,int high)  
    {  
        int pivot;  
        if(low<high)  
        {  
            pivot=(low+high)/2;  
            mergesort(a,low,pivot);  
            mergesort(a,pivot+1,high);  
            merge(a,low,pivot,high);  
        }  
    }  
    void merge(int *a,int low,int pivot,int high)  
    {  
        int h,i,j,b[50],k;  
        h=low;  
        i=low;  
        j=pivot+1;  
      
        while((h<=pivot)&&(j<=high))  
        {  
            if(a[h]<=a[j])  
            {  
                b[i]=a[h];  
                h++;  
            }  
            else  
            {  
                b[i]=a[j];  
                j++;  
            }  
            i++;  
        }  
        if(h>pivot)  
        {  
            for(k=j; k<=high; k++)  
            {  
                b[i]=a[k];  
                i++;  
            }  
        }  
        else  
        {  
            for(k=h; k<=pivot; k++)  
            {  
                b[i]=a[k];  
                i++;  
            }  
        }  
        for(k=low; k<=high; k++) a[k]=b[k];  
    }  
     
    int main()  
    {  
        //int a[] = {12,10,43,23,-78,45,123,56,98,41,90,24};
		int a[] = {6,5,3,1,8,7,2,4};
        int num;  
      
        num = sizeof(a)/sizeof(int);  
      
        mergesort(a,0,num-1);  
      
        for(int i=0; i<num; i++)  
            cout<<a[i]<<" ";  
        cout<<endl;  
    }  
