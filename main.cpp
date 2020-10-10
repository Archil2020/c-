#include <iostream>
#include <string.h>
#include <fstream>
#include <functional>
#include <vector>
using namespace std;

void FIllArr(int* arr,int length){
    for (int i = 0; i < length; i++)
    {
        *(arr+i) = rand() % 1000;
    }
}

void PrintArr(int* arr,int length,void(*Fill)(int*,int)){
    Fill(arr,length);
    for (int i = 0; i < length; i++)
    {
        cout<<*(arr+i)<<"\t";
    }
    cout<<endl;
}

int* FindIndex(int* arr,int length,bool(*find)(int*,int)){
    static int indexes[10];
    for (int i = 0; i < 10; i++)
    {
        indexes[i] = 0;
    }
    
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (find(arr,arr[i]))
        {
            if(indexes[count]==0){
                indexes[count]=i;
                count++;
            }
        }
    }
    return indexes;
}
bool check(int* arr,int i){
    return i>arr[7]?true:false;
}
int main(){
    //srand(time(0));
    int* arr = new int[10];
    PrintArr(arr,10,FIllArr);
    int num = arr[7];
    int* index = FindIndex(arr,10,check);
    //cout<<index<<endl;
    for (int i = 0; i < 10; i++)
    {
        if(*(index+i)!=0){
            cout<<*(index+i)<<endl;
        }
    }
    
    delete [] arr;

    return 0;
}