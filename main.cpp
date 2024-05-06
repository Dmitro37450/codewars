// #1
int solution(int number) 
{
  int S = 0;
  for (int i = 1; i < number; i++) {
    if (i % 3 == 0 || i % 5 == 0) {
      S += i;
    }
  }
  return S;
}


// #2
#include <string>
#include <cctype>

std::string duplicate_encoder(const std::string& word){
  std::string result = "";
  for (char letter : word) {
    int count = 0;
    for (char letter2 : word) {
      if (tolower(letter) == tolower(letter2)) { ++count; }
    }
    if (count <= 1) {
      result.append("(");
    } else {
      result.append(")");
    }
  }
  return result;
}


// #3
#include <cctype>

bool XO(const std::string& str)
{
  int count[2] = {0,0};
  for (char letter : str) {
    if (tolower(letter) == 'x') {
      ++count[0];
    } else if (tolower(letter) == 'o') {
      ++count[1];
    }
  }
  return (count[0] == count[1]) ? true : false;
}


// #4
class Printer
{
public:
    static std::string printerError(const std::string &s);
};

std::string Printer::printerError(const std::string &s) {
  int error = 0, size = 0;
  for (char letter : s) {
    error += (letter > 'm');
    ++size;
  }
  return std::to_string(error) + "/" + std::to_string(size);
}


// #5
#include <string>
#include <cctype>

std::string to_camel_case(std::string text) {
  std::string result;
  bool upper = false;
  for (char letter : text) {
    if (letter == '-' || letter == '_') {
      upper = true;
    } else {
      result += (upper ? toupper(letter) : letter);
      upper = false;
    }
  }
  return result;
}


// #6
#include <string>

using namespace std;

int getCount(const string& inputStr){
  int num_vowels = 0;
  //your code here
  
  string vowels = "aeiou";
  
  for (char letter : inputStr) {
    num_vowels += ((vowels.find(letter) == string::npos) ? 0 : 1);
  }
  
  return num_vowels;
}


// #7
std::vector<int> deleteNth(std::vector<int> arr, int n)
{
  std::vector<int> result;
  
  for (int num : arr) {
    int count = std::count(result.begin(), result.end(), num);
    if (count < n) {
      result.push_back(num);
    }
  }
  
  return result;
}


// #8
#include<vector>

bool isValidWalk(std::vector<char> walk) {
  if (walk.size() != 10) { return false; }
  int x = 0;
  for (char p : walk) {
    switch(p) {
        case 'n': x += 1; break;
        case 'e': x += 2; break;
        case 's': x -= 1; break;
        case 'w': x -= 2; break;
        default: break;
    }
  }
  std::cout << x << std::endl;
  return (x == 0);
}


// #9
#include <vector>

char findMissingLetter(const std::vector<char>& chars)
{
  std::cout << chars.front();
  for (int i = chars.front(); i < chars.back(); i++) {
    if (std::find(chars.begin(), chars.end(), i) == chars.end()) {return i;}
  }
  return ' ';
}


// #10
#include <string>
#include <vector>

std::vector<std::string> solution(const std::string &s)
{
  std::vector<std::string> result;
  std::string temp;
  bool next = false;
  for (char letter : s) {
    if (not next) {
      next = true;
      temp += letter;
    } else {
      next = false;
      temp += letter;
      result.push_back(temp);
      temp = "";
    }
  }
  if (temp != "") {
      temp += "_";
      result.push_back(temp);
  }
  return result; // Your code here
}
