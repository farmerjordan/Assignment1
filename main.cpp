#include <iostream>
#include <fstream>
#include <string>
#include <cctype> //to use tolower functionality
#include <cmath> //to calculate standard deviation
#include <cstdlib> //for gaussian distrbution
#include <math.h> //for gaussian distribution to provide value of pi
#include <time.h> //for gaussian distribution to initialize a random seed each time rand() is called


using namespace std;

int main(){

  //Checking for when user is prompted if they would like to test another file
  bool doAgain = true;

  while(doAgain == true){

    string input_file;
    string verify;

    //Obtaining user input for file to test
    cout << "Please enter the name of the text file containing DNA strings." << endl;
    cin >> input_file;
    cout << "You entered: " << input_file << endl;
    cout << "Is this correct? Y or N " << endl;
    cin >> verify;

    //Ensuring user provided the correct file
    while(verify == "N" || verify == "n"){
      cout << "Please enter the name of the text file containing DNA strings." << endl;
      cin >> input_file;
      cout << "You entered: " << input_file << endl;
      cout << "Is this correct? Y or N " << endl;
      cin >> verify;
    }

    ifstream inFile;
    inFile.open(input_file);

    //If the file cannot be found, it cannot be opened and user is prompted
    //Otherwise the user is told that their file was found and the testing will begin
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

      int countAA = 0;
      int countAC = 0;
      int countAG = 0;
      int countAT = 0;
      int countCA = 0;
      int countCC = 0;
      int countCG = 0;
      int countCT = 0;
      int countGA = 0;
      int countGC = 0;
      int countGG = 0;
      int countGT = 0;
      int countTA = 0;
      int countTC = 0;
      int countTG = 0;
      int countTT = 0;
      int bigramCount = 0;


      //Testing that I can read in the correct file and print line by line
      while(!inFile.eof()){
       getline(inFile,line);

       //Removes trailing whitespace to get correct character count
       line.erase(line.find_last_not_of(" \t\n\r\f\v") + 1);

       //Iterating through each character in the line
       for (string::size_type i = 0; i < line.length(); i++){

         //Converting current char to lowercase
         line[i] = tolower (line[i]);

         //Both uppercase and lower case are checked because letters are being converted
         //to lowercase one at a time, so the next index has not yet been converted
         if(line[i] == 'a'){
           countA += 1;
           if(line[i + 1] == 'a' || line[i + 1] == 'A'){
             countAA += 1;
             bigramCount += 1;
           }else if(line[i + 1] == 'c' || line[i + 1] == 'C'){
             countAC += 1;
             bigramCount += 1;
           }else if(line[i + 1] == 'g' || line[i + 1] == 'G'){
             countAG += 1;
             bigramCount += 1;
           }else if(line[i + 1] == 't' || line[i + 1] == 'T'){
             countAT += 1;
             bigramCount += 1;
           }else{
             ; //do nothing if a character other than a nucleotide is found
           }
         }else if(line[i] == 'c'){
           countC += 1;
           if(line[i + 1] == 'a' || line[i + 1] == 'A'){
             countCA += 1;
             bigramCount += 1;
           }else if(line[i + 1] == 'c' || line[i + 1] == 'C'){
             countCC += 1;
             bigramCount += 1;
           }else if(line[i + 1] == 'g' || line[i + 1] == 'G'){
             countCG += 1;
             bigramCount += 1;
           }else if(line[i + 1] == 't' || line[i + 1] == 'T'){
             countCT += 1;
             bigramCount += 1;
           }else{
             ; //do nothing if a character other than a nucleotide is found
           }
         }else if(line[i] == 'g'){
           countG += 1;
           if(line[i + 1] == 'a' || line[i + 1] == 'A'){
             countGA += 1;
             bigramCount += 1;
           }else if(line[i + 1] == 'c' || line[i + 1] == 'C'){
             countGC += 1;
             bigramCount += 1;
           }else if(line[i + 1] == 'g' || line[i + 1] == 'G'){
             countGG += 1;
             bigramCount += 1;
           }else if(line[i + 1] == 't' || line[i + 1] == 'T'){
             countGT += 1;
             bigramCount += 1;
           }else{
             ; //do nothing if a character other than a nucleotide is found
           }
         }else if(line [i] == 't'){
           countT += 1;
           if(line[i + 1] == 'a' || line[i + 1] == 'A'){
             countTA += 1;
             bigramCount += 1;
           }else if(line[i + 1] == 'c' || line[i + 1] == 'C'){
             countTC += 1;
             bigramCount += 1;
           }else if(line[i + 1] == 'g' || line[i + 1] == 'G'){
             countTG += 1;
             bigramCount += 1;
           }else if(line[i + 1] == 't' || line[i + 1] == 'T'){
             countTT += 1;
             bigramCount += 1;
           }else{
             ; //do nothing if a character other than a nucleotide is found
           }
         }else{
           ; //do nothing if a character other than a nucleotide is found
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

    //Initializing variables for probability calculations
    float probA = 0;
    float probC = 0;
    float probG = 0;
    float probT = 0;

    //Calculating nucleotide probabilities
    probA = (float)countA / (float)charCount;
    probC = (float)countC / (float)charCount;
    probG = (float)countG / (float)charCount;
    probT = (float)countT / (float)charCount;

    //Initializing variables for bigram probability calculations
    float probAA = 0;
    float probAC = 0;
    float probAG = 0;
    float probAT = 0;
    float probCA = 0;
    float probCC = 0;
    float probCG = 0;
    float probCT = 0;
    float probGA = 0;
    float probGC = 0;
    float probGG = 0;
    float probGT = 0;
    float probTA = 0;
    float probTC = 0;
    float probTG = 0;
    float probTT = 0;

    //Calculating bigram probabilities
    probAA = (float)countAA / (float)bigramCount;
    probAC = (float)countAC / (float)bigramCount;
    probAG = (float)countAG / (float)bigramCount;
    probAT = (float)countAT / (float)bigramCount;
    probCA = (float)countCA / (float)bigramCount;
    probCC = (float)countCC / (float)bigramCount;
    probCG = (float)countCG / (float)bigramCount;
    probCT = (float)countCT / (float)bigramCount;
    probGA = (float)countGA / (float)bigramCount;
    probGC = (float)countGC / (float)bigramCount;
    probGG = (float)countGG / (float)bigramCount;
    probGT = (float)countGT / (float)bigramCount;
    probTA = (float)countTA / (float)bigramCount;
    probTC = (float)countTC / (float)bigramCount;
    probTG = (float)countTG / (float)bigramCount;
    probTT = (float)countTT / (float)bigramCount;

    //Gaussian Distribution variable initialization
    float a = 0;
    float b = 0;
    float c = 0;
    float d = 0;
    int dRounded = 0;

    //Calculating variables for Guassian Distribution
    srand (time(NULL)); //Ensures values for a and b are different each time program is run
    a = (float)rand()/((float)RAND_MAX + 1);
    b = (float)rand()/((float)RAND_MAX + 1);
    c = sqrt(-2 * log(a)) * cos(2 * M_PI * b);
    d = ((float)stdev * c) + (float)mean;

    dRounded = round(d);

    //Initalizing output file
    ofstream outFile;
    outFile.open("jordanfarmer.out", ios::out | ios::app);

    //All of this will be outputted to the output file
    outFile << "Full Name: Jordan Farmer" << endl;
    outFile << "Student ID: 2289033" << endl;
    outFile << "Chapman Email: farmer@chapman.edu" << endl;
    outFile << "Course Number and Section: 350-02" << endl;
    outFile << "Assignment: Assignment #1" << endl;
    outFile << " " << endl;
    outFile << "The file being analyzed is:  " << input_file << endl;
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
    outFile << " " << endl;
    outFile << "The relative probability of the bigram AA is: " << probAA << endl;
    outFile << "The relative probability of the bigram AC is: " << probAC << endl;
    outFile << "The relative probability of the bigram AG is: " << probAG << endl;
    outFile << "The relative probability of the bigram AT is: " << probAT << endl;
    outFile << "The relative probability of the bigram CA is: " << probCA << endl;
    outFile << "The relative probability of the bigram CC is: " << probCC << endl;
    outFile << "The relative probability of the bigram CG is: " << probCG << endl;
    outFile << "The relative probability of the bigram CT is: " << probCT << endl;
    outFile << "The relative probability of the bigram GA is: " << probGA << endl;
    outFile << "The relative probability of the bigram GC is: " << probGC << endl;
    outFile << "The relative probability of the bigram GG is: " << probGG << endl;
    outFile << "The relative probability of the bigram GT is: " << probGT << endl;
    outFile << "The relative probability of the bigram TA is: " << probTA << endl;
    outFile << "The relative probability of the bigram TC is: " << probTC << endl;
    outFile << "The relative probability of the bigram TG is: " << probTG << endl;
    outFile << "The relative probability of the bigram TT is: " << probTT << endl;
    outFile << "Below are 1000 randomly generated DNA strings with length following a Guassian Distribution: " << endl;
    outFile << " " << endl;

    //Initializing variables for statistics for randomly generated DNA strings
    int randNuc;
    string currentStrand;
    int newCountA = 0;
    int newCountC = 0;
    int newCountG = 0;
    int newCountT = 0;
    int newTotalNuc = 0;

    //Generating 1000 random nucleotides based on the Gaussian Distribution
    for (string::size_type i = 0; i < 1000; i++){
      currentStrand = "";
      for (string::size_type i = 0; i < dRounded; i++){

        randNuc = (rand() % 4) + 1;

        //The 4 nucleotides are each assigned to a number between 1 and 4 for random assignment
        if(randNuc == 1){
          currentStrand += 'A';
          newCountA += 1;
        }else if(randNuc == 2){
          currentStrand += 'C';
          newCountC += 1;
        }else if(randNuc == 3){
          currentStrand += 'G';
          newCountG += 1;
        }else{
          currentStrand += 'T';
          newCountT += 1;
        }
      }

      //Outputting new strands to output file
      newTotalNuc += currentStrand.size();
      outFile << currentStrand << endl;

    }

    //Initializing variables for statistics for new DNA strings
    float newProbA = 0;
    float newProbC = 0;
    float newProbG = 0;
    float newProbT = 0;

    //Calculating probability for statistcs for new DNA strings
    newProbA = (float)newCountA / (float)newTotalNuc;
    newProbC = (float)newCountC / (float)newTotalNuc;
    newProbG = (float)newCountG / (float)newTotalNuc;
    newProbT = (float)newCountT / (float)newTotalNuc;

    //Outputting probability of new DNA strings to file
    outFile << "The relative probability of the A nucleotide in the generated strings is:  " << newProbA << endl;
    outFile << "The relative probability of the C nucleotide in the generated strings is:  " << newProbC << endl;
    outFile << "The relative probability of the G nucleotide in the generated strings is:  " << newProbG << endl;
    outFile << "The relative probability of the T nucleotide in the generated strings is:  " << newProbT << endl;

    string repeat;

    //Checking if user would like to check another file
    cout << "Would you like to compute with another file? Y or N " << endl;
    cin >> repeat;
    if(repeat == "N" || repeat == "n"){
      doAgain = false;
    }

  }
}
