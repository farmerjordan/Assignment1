#include <iostream>

using namespace std;

int main(){

  string input_file;
  string verify;
  cout << "Please enter the name of the text file containing DNA strings." << endl;
  cin >> input_file;
  cout << "You entered: " << input_file << endl;
  cout << "Is this correct? Y or N " << endl;
  cin >> verify;

  while(verify == "N"){
    cout << "Please enter the name of the text file containing DNA strings." << endl;
    cin >> input_file;
    cout << "You entered: " << input_file << endl;
    cout << "Is this correct? Y or N " << endl;
    cin >> verify;
    }



}
