#include <iostream>

using namespace std;

string Urlify(string s) {
  auto spaces = 0;
  for (int i = 0; i < s.length(); i++){
    if (s[i] == ' '){
      spaces++;
    }
  }
  char url[s.length() + 2 * spaces];
  for (int i = 0, j = 0; i < s.length(); i++, j++){
    if (s[i] == ' '){
      url[j] = '%';
      url[j+1] = '2';
      url[j+2] = '0';
      j+=2;
      continue;
    }
    url[j] = s[i];
  }  
  return url;
}

void UrlifyM(string& s) {
  int spaces = 0, size = s.length();
  for (int i = 0; i < size; i++){
   if (s[i] == ' '){
      spaces++;
    }
  }  
  int newSize = s.length() + spaces * 2;
  s.resize(newSize);
  for (int i = size - 1, j = newSize - 1; i >= 0; i--, j--){
    if (s[i] == ' '){
      s[j] = '0';
      s[j-1] = '2';
      s[j-2] = '%';
      j -= 2;
      continue;
    }
    s[j] = s[i];
  }
}

int main() {
  string s = "a string with spaces";
  cout << s << endl;
  auto url = Urlify(s);
  cout << url << endl;
  UrlifyM(s);
  cout << s << endl;
  return 0;
}