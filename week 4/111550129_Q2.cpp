#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print_Array(int *arr, int len)
{
    // TODO:
   for(int i=0;i<len ; i++){
    cout << arr[i] <<" ";
   }
   cout << endl;
}

void fill_Array(int *arr, int len)
{
    // TODO:
    for(int i=0;i<len;i++){
        cin >> arr[i];
    }
}

void reverse_Array(int *arr, int len)
{
    // TODO:
   reverse(arr,arr + len);
}


int main()
{
    int *arr;
    int arrSize;
    // TODO:    (Hint: input)
        cin >> arrSize;

    // TODO:    (Hint: create a dynamic array...)
    arr = new int [arrSize];

    fill_Array(arr, arrSize);
    reverse_Array(arr, arrSize);
    print_Array(arr, arrSize);

    return 0;
}
