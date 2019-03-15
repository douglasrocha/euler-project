#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> digits = {
  "zero",
  "one",
  "two",
  "three",
  "four",
  "five",
  "six",
  "seven",
  "eight",
  "nine"
};

vector<string> smallerThanTwenty = {
  "ten",
  "eleven",
  "twelve",
  "thirteen",
  "fourteen",
  "fifteen",
  "sixteen",
  "seventeen",
  "eighteen",
  "nineteen"
};

vector<string> biggerThanTwenty = {
  "twenty",
  "thirty",
  "forty",
  "fifty",
  "sixty",
  "seventy",
  "eighty",
  "ninety"
};

string hundred = "hundred";

string less_than_hundred_to_str(int n) {
  int smallest_digit = n % 10;
  int decimal_digit = n / 10 % 10;
  stringstream ss;
  ss << biggerThanTwenty[decimal_digit - 2];
  if (smallest_digit > 0) {
    ss << "-" << digits[smallest_digit];
  }
  return ss.str();
}

string bigger_than_hundred_to_str(int n) {
  if (n > 1000) return "";
  if (n == 1000) return "one thousand";
  if (n == 100) return "one hundred";
  int hundred_digit = n / 100 % 10;
  stringstream ss;
  ss << digits[hundred_digit] << " hundred" ;

  if (n % 100 >= 10 && n % 100 < 20) {
    ss << " and " << smallerThanTwenty[n % 10];
  } else if (n % 100 >= 20){
    ss << " and " << less_than_hundred_to_str(n % 100);
  } else if (n % 100 > 0) {
    ss << " and " << digits[n % 100];
  }
  
  return ss.str();
}

string num_to_str(int n) {
  if (n < 10)
    return digits[n];
  
  if (n >= 10 && n < 20)
    return smallerThanTwenty[n % 10];

  if (n >= 20 && n < 100)
    return less_than_hundred_to_str(n);

  return bigger_than_hundred_to_str(n);
}

int main (void) {
  stringstream ss;
  for (int i = 1; i <= 1000; i++) {
    ss << num_to_str(i);
    cout << num_to_str(i) << endl;
  }
  

  string output = ss.str();

  int count = 0;
  for (char& c : output)
    if (c >= 'a' && c <= 'z')
      ++count;

  cout << "Answer: " << count << endl;
  
  return 0;
}
