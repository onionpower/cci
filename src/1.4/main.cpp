#include <iostream>
#include <unordered_map>

using namespace std;

int getShift(char c){
  return c - 'a';
}

bool isPalPermSpaceEfficient(string s) {  
  int check = 0;
  for (int i = 0; i < s.size(); i++){
    auto c = s[i];
    if (c == ' '){
      continue;
    }
    if (c > 'z' || c < 'a'){
      return false;
    }
    int shift = getShift(s[i]);
    check = check ^ 1 << shift;
  }
  if (check == 0) {
    return true;
  }
  return (check & (check - 1)) == 0;
}

bool isPalPerm(string s){
  unordered_map<char, int> map;
  for (int i = 0; i < s.size(); i++){
    auto c = s[i];
    if (c == ' '){
      continue;
    }
    if (c > 'z' || c < 'a'){
      return false;
    }
    auto occ = map[c];
    map[c] = occ + 1;    
  }
    
  auto singleSymbolFound = false; 
  auto evenSymbols = s.size() % 2 == 0;
  for (auto& e : map){
    if (e.second % 2 != 0) {
      if (evenSymbols) {
        return false;
      }
      if (singleSymbolFound) {
        return false;
      }
      singleSymbolFound = true;
    }
  }
  return true;
}

int main() {
  string test[] = {"hemo moeh", "hemo moah", "aaa11 1", "bbaaccd", "bba abbssdde e", "b baed d", "mmmaaa", "aa11b"};
  cout << "isPalPerm" << endl;
  for (auto t : test){
    cout << t << " is palindrome permutation: " << isPalPerm(t) << endl;
  }

  cout << "isPalPermSpaceEfficient" << endl;
  for (auto t : test){
    cout << t << " is palindrome permutation: " << isPalPermSpaceEfficient(t) << endl;
  }  
  return 0;
}