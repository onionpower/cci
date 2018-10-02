#include <iostream>
#include <unordered_map>

using namespace std;

bool isPalPerm(string s){
  unordered_map<char, int> map;
  for (int i = 0; i < s.size(); i++){
    auto c = s[i];
    if (c == ' '){
      continue;
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
  auto palPerm = "hemo moeh";
  auto notPalPerm = "hemo moah";
  cout << palPerm << " is palindrome permutation: " << isPalPerm(palPerm) << endl;
  cout << notPalPerm << " is palindrome permutation: " << isPalPerm(notPalPerm) << endl;
  return 0;
}