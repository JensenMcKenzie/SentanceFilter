/*
SentanceFilter.cpp -
Author: Jensen McKenzie
Module: 9
Project: Homework 9
Problem Statement: Parse through a file changing the first letter of each sentant to upppercase, and everything else to lowercase, and output the result to a file.

Algorithm/Plan:
  1. Open the input file
  2. Get each line of the input file, and store it in contents.
   2a. Loop through each character in the line.
   2b. Check to see if the current character is the first letter in the string, or the start of a sentance, if so, change it to uppercase.
   2c. If not, change the character to lowercase.
   2d. Add the changed character to the contents string.
  3. Close the input file.
  4. Open the output file.
  5. Write the string contents to the output file.
  6. Close the output file.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream input ("input.txt");
    string line, contents;
    while(getline(input,line)){
        for (int i = 0; i < line.length(); i++){
            if (i > 0){
                if (i - 2 > 0){
                    if (line[i-2] != '.'){
                        contents += tolower(line[i]);
                    }else{
                        contents += toupper(line[i]);
                    }
                }else{
                    contents += tolower(line[i]);
                }
            }else{
                contents += toupper(line[i]);
            }
        }
    }
    input.close();
    ofstream output ("output.txt");
    output << contents;
    output.close();
}
