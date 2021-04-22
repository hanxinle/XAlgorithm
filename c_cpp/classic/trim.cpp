#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
using namespace std;

auto is_not_space = [&](char i) {return !isspace(i); };

static string trimLeft(string & s) {
   s.erase(s.begin(), find_if(s.begin(), s.end(), is_not_space));
   return s;
}

static string trimRight(string & s) {
   s.erase(find_if(s.rbegin(), s.rend(), is_not_space).base(), s.end());
   return s;
}

string trim(string & s) {
   string t = trimRight(s);
   return trimLeft(t);
}


int main() {
   string s1 = "   12 223333   ";
   string s2 = "   a b c    ";
   //s2.erase((find_if(s2.begin(), s2.end(), isspace)), s2.end()); // ""

   cout << "after trim s=" << trim(s1) << endl; // 12 223333
   cout << "after trim s=" << trim(s2) << endl; // a b c


   return 0;
}