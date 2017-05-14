#include <iostream>
#include <string>

using namespace std;


char* comp(string word);

int int main(int argc, char const *argv[])
{
  char* a = "aabbbccaad";
   cout << comp(a) << endl;

  return 0;
}

char* comp(string word){
  char* compressedString;
  int repeat = 1;

  int len = word.length();

  for(int i = 1; i < len; i++){
     if(word[i] == word[i-1]){
        repeat++;
     } else {
        *compressed++ = word[i-1] + repeat;
     }
  }

  return compressedString;
}

