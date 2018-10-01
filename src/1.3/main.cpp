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
  for (int i = 0; i < s.length(); i++){
    if (s[i] == ' '){
      url[i] = '%';
      url[i+1] = '2';
      url[i+2] = '0';
      continue;
    }
    url[i] = s[i];
  }  
  return url;
}

int main() {
  auto s = "a string with spaces";
  cout << s << endl;
  auto url = Urlify(s);
  cout << url << endl;
  return 0;
}