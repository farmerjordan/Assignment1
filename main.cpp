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

    int countA = 0;
    int countC = 0;
    int countG = 0;
    int countT = 0;

    //Testing that I can read in the correct file and print line by line
    while(!inFile.eof()){
     getline(inFile,line);

     //Removes trailing whitespace to get correct character count
     line.erase(line.find_last_not_of(" \t\n\r\f\v") + 1);

     //Making all characters lowercase
     for (string::size_type i = 0; i < line.length(); i++){


       line[i] = tolower (line[i]);

       if(line[i] == 'a'){
         countA += 1;
       }else if(line[i] == 'c'){
         countC += 1;
       }else if(line[i] == 'g'){
         countG += 1;
       }else{
         countT += 1;
       }


     }


     charCount = charCount + line.size();
     lineCount += 1;

    }

    //Calculation of mean number of characters in a DNA string
    mean = (float)charCount / (float)lineCount;




    int lengthString = 0;
    float varianceNumerator = 0;
    float variance = 0;
    float stdev = 0;

    //Returning to top of file to perform variance calculations
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


  float probA = 0;
  float probC = 0;
  float probG = 0;
  float probT = 0;

  probA = (float)countA / (float)charCount;
  probC = (float)countC / (float)charCount;
  probG = (float)countG / (float)charCount;
  probT = (float)countT / (float)charCount;

  ofstream outFile;

  outFile.open("jordanfarmer.out", ios::out | ios::app);



  //All of this will be outputted to the output file

  outFile << "Full Name: Jordan Farmer" << endl;
  outFile << "Student ID: 2289033" << endl;
  outFile << "Chapman Email: farmer@chapman.edu" << endl;
  outFile << "Course Number and Section: 350-02" << endl;
  outFile << "Assignment: Assignment #1" << endl;  
  outFile << "Total number of characters in the file: " << charCount << endl;
  outFile << "Total number of DNA strings in the file: " << lineCount << endl;
  outFile << " " << endl;
  outFile << "The mean length of the DNA strings is: " << mean << endl;
  outFile << "The variance of the length of the DNA strings is: " << variance << endl;
  outFile << "The standard deviation of the length of the DNA strings is: " << stdev << endl;
  outFile << " " << endl;
  outFile << "The relative probability of the A nucleotide is:  " << probA << endl;
  outFile << "The relative probability of the C nucleotide is:  " << probC << endl;
  outFile << "The relative probability of the G nucleotide is:  " << probG << endl;
  outFile << "The relative probability of the T nucleotide is:  " << probT << endl;




}
