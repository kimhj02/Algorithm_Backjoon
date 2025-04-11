//
// Created by 김현진 on 2025. 4. 11..
//
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin>>s;
    vector<int> arr(26,0);
    for(int i=0;i<s.size();i++){
      arr[s[i]-'a']++;
    }
    for(int i=0;i<26;i++){
      cout << arr[i] << " ";
    }
    return 0;
}