//Mark Zhang - 21 February 2021 - Palindrome: takes input and determines if it is a palindrome once spaces and punctuation is removed
#include <iostream>
#include <cstring>
using namespace std;

int main(){
  char rawinput [80];
  char nopunct [80];
  char lowercase [80];
  int length = 0;
  int counter = 0;
  bool isPalindrome = true; //palindrome is true until found to be false (see 6)
  

  //1 clear arrays
  for (int i = 0; i < 80; i++) {
    rawinput[i] = 0;
    nopunct[i] = 0;
    lowercase[i] = 0;
  }

  //2 store raw input to char array: "rawinput"
  cin.get(rawinput, 80);
  cin.get();
  
  //3 Take only numbers and letters from raw input and store it in char array with no spaces and punctuation: "nopunct"
  for (int i = 0; i < 80; i++) {
    if ((rawinput[i] >= 97 && rawinput[i] <= 122) || (rawinput[i] >= 65 && rawinput[i] <= 90) || (rawinput[i] >= 48 && rawinput[i] <= 57)){
      nopunct[counter] = rawinput[i];
      counter++;
    }
  }
  //4 Copy "nopunct" to "lowercase" but converts any capital letters to their lowercase versions
  //"lowercase" has no spaces, punctuations, and capital letters
  for (int i = 0; i < 80; i++) {
    if (nopunct[i] >= 65 && nopunct[i] <= 90) {
      lowercase[i] = nopunct[i] + 32;
    }
    else {
      lowercase[i] = nopunct[i];
    }
  }

  //5 find length so that the next for loop can go through the array backwards 
  for (int i = 0; i < 80; i++) {
    if ((lowercase[i] >= 97 &&  lowercase[i] <= 122) ||(lowercase[i] >= 48 && lowercase[i] <= 57)) {
      length++;
    }
  }

  //6 determine if the string is a palindrome by reading the string forwards and backwards and comparing corresponding characters
  for (int i = 0; i < length; i++) {
    if (lowercase[i] != lowercase[length - i - 1]) {//compares the ith character to ith character when reading backwards
      isPalindrome = false; //if any discrepancy is found between the forward reading and backwards reading, string is NOT a palindrome 
    }  
  } //if isPalindrome is not found to be false in loop, it is true by default

  //7 print out result
  if (isPalindrome == false) {
      cout << rawinput << " is not a palindrome" << endl;    
  }
  else {
      cout << rawinput << " is a palindrome" << endl;
  }
  return 0;
}
