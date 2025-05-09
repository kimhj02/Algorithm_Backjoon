//
// Created by 김현진 on 25. 5. 9.
//
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
  string s;
  cin>>s;
  int count = 0;
  for(int i=0;i<s.length();i++){
    if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') count++;
  }
  cout<<count<<endl; return 0;
}