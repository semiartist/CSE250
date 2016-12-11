// File: a1.cpp
// Author: Frank Chen fchen29

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

// declare some functions
int translate(char C);
int updateGene( int *gene, char C, int &jump, const int * increment, int);
string convertBack(int input, int intK , int * increment);
string decode(int input);

int main(int argc, char *argv[]) {
    // read from the input file

    if (argc <1) {
        cout << "there is no input file!" << endl;
        return -1;
    }

    string fileName = argv[1];

    std::ifstream input(fileName);
    if (!input) {
        cout << "error, your file does not exist!" << endl;
        return -1;
    }

    // read the firstint translate(char C) lines into file.
    string k = "", lines = "";
    input >> k >> lines;

    int intK = 0;
    intK = stoi(k);
    int intLines = 0;
    intLines = stoi(lines);

    if (intK >10 || intK < 3) {
        cout << "error" << endl;
        return -1;
    }

    // calculate the possibilities;
    int poss = 1;
    int *increment;
    increment = new int[intK];
    for (int i = 0; i < intK; ++i){
        increment[intK-1-i] = poss;
        poss*=4;
    }
    // initial the vectore storing the result;
    int *result;
    result = new int[poss];
    for (int i = 0; i < poss ; ++i){
        result[i] = 0;
    }

    int lineNumber = 0;
    // read file line by line
    while (!input.eof()){
        // this is for store the current Gene;
        int * gene;
        gene = new int[intK];
        for (int i = 0; i < intK ; ++i){
            gene[i] = 0;
        }
        string currentLine = "";

        // read entire line into the string;
        std::getline(input, currentLine);

        if (!currentLine.empty()){
            // if the line number is greater than the actrual line number in the file;
            if (++lineNumber > intLines) {
                cout << "error" << endl;
                return -1;
            }// if

            int jump = 0;
            int geneind = 1;

            for (char &c : currentLine){
                ++geneind;

                int index = updateGene(gene, c, jump, increment, intK);

                // see if we need to break the current loop;
                if (jump > 0) {
                    --jump;
                    continue;
                }

                if (geneind >= intK) {
                    result[index] += 1;
                }
            }

            // for (int i = 0 ; i < result.size() ; ++i) cout << result[i] << " ";
        }

        delete[] gene;
    } // while reading loop

    for (int i = 0; i < poss ; ++i ) {
        if (result[i] == 0) continue;
        cout << convertBack(i, intK, increment) << " " << result[i] << endl;
    }

    // close the file stream;
    input.close();
    delete[] result, increment;

    return 0;
} // main

int translate(char C){
    if (C == 'A') return 0;
    if (C == 'C') return 1;
    if (C == 'G') return 2;
    if (C == 'T') return 3;
    return 4;
}

int updateGene(int * gene, char C, int &jump, const int * increment, int intK){
    int current = translate(C);
    int geneSize = intK;

    if (current == 4) jump = geneSize;
    // update the existing value in GEne;
    for (int i = 0; i < geneSize-1 ; ++i) {
        int temp = gene[i+1];
        // cout << "temp -> " << temp << endl;
        gene[i] = temp;
        // cout << "gene[i] " << i <<" " << gene[i] << endl;
    }

    // update the last gene value;
    gene[intK-1] = current;

    int result = 0;

    // get the index;
    if (jump == 0){
        int i = 0;
        while (i < geneSize){
            //calculate increment
            result += gene[i]*increment[i];
            i++;
        }
    }
    return result;
}

string convertBack(int input, int intK , int * increment){
    string result = "";
    for (int i = 0 ; i < intK ; ++i){
        result += decode(input/increment[i]);
        input = input%increment[i];
    }

    return result;
}

string decode(int input){
    if (input == 0 ) return "A";
    if (input == 1 ) return "C";
    if (input == 2 ) return "G";
    if (input == 3 ) return "T";

    cout << "error, the convert can not be done!" << endl;
    return "ERROR IN DECODE";
}
