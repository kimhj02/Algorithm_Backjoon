//
// Created by 김현진 on 2025. 4. 17..
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr(3,0);
    for(int i=0;i<3;i++)
      cin>>arr[i];
    sort(arr.begin(),arr.end());
    for(int i=0;i<3;i++)
      cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}