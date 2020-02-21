#include <iostream>
#include <fstream>
#include <string>
#include <cctype> //to use tolower functionality


using namespace std;

int main(){

  string input_file;
  string verify;
  cout << "Please enter the name of the text file containing DNA strings." << endl;
  cin >> input_file;
  cout << "You entered: " << input_file << endl;
  cout << "Is this correct? Y or N " << endl;
  cin >> verify;

  while(verify == "N" || verify == "n"){
    cout << "Please enter the name of the text file containing DNA strings." << endl;
    cin >> input_file;
    cout << "You entered: " << input_file << endl;
    cout << "Is this correct? Y or N " << endl;
    cin >> verify;
    }

    ifstream inFile;

    inFile.open(input_file);

    if(!inFile){
      cout << "Unable to open file: " << input_file << endl;
      cout << "File not found." << endl;
      exit(1);
    }else{
      cout << "File found. " << endl;
      cout << "" << endl;
    }


    string line;
    int charCount = 0;

    //Testing that I can read in the correct file and print line by line
    while(!inFile.eof()){
     getline(inFile,line);



     for (string::size_type i = 0; i < line.length(); i++){
       line[i] = tolower (line[i]);
     }
     line.erase(line.find_last_not_of(" \t\n\r\f\v") + 1); //Removes trailing whitespace to get corret character count
     charCount = charCount + line.size();


    }

  cout << "There are a total of " << charCount << " characters in this file." << endl;


}
