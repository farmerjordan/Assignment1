#include <iostream>
#include <fstream>
#include <string>
#include <cctype> //to use tolower functionality
#include <cmath> //to calculate standard deviation


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

    //Initializing variables for use in the while loop that iterates through the input file
    string line;
    int charCount = 0;
    int lineCount = 0;
    float mean = 0;


    //Testing that I can read in the correct file and print line by line
    while(!inFile.eof()){
     getline(inFile,line);


     //Making all characters lowercase
     for (string::size_type i = 0; i < line.length(); i++){
       line[i] = tolower (line[i]);
     }

     //Removes trailing whitespace to get correct character count
     line.erase(line.find_last_not_of(" \t\n\r\f\v") + 1);

     charCount = charCount + line.size();
     lineCount += 1;

    }

    //Calculation of mean number of characters in a DNA string
    mean = (float)charCount / (float)lineCount;




    int lengthString = 0;
    float varianceNumerator = 0;
    float variance = 0;
    float stdev = 0;

    inFile.clear();
    inFile.seekg(0, ios::beg);
    //Calculating variance doing it after previous while loop so that the mean was available
    while(!inFile.eof()){
      getline(inFile,line);

      line.erase(line.find_last_not_of(" \t\n\r\f\v") + 1);

      lengthString = line.size();

      varianceNumerator += ((float)lengthString - (float)mean) * ((float)lengthString - (float)mean);

    }

    variance = (float)varianceNumerator / (float)lineCount;
    stdev = sqrt(variance);



  //All of this will later be outputted to the output file
  cout << "Total number of characters in the file: " << charCount << endl;
  cout << "Total number of DNA strings in the file: " << lineCount << endl;
  cout << "The mean length of the DNA strings is: " << mean << endl;
  cout << "The variance of the length of the DNA strings is: " << variance << endl;
  cout << "The standard deviation of the length of the DNA strings is: " << stdev << endl;


}
