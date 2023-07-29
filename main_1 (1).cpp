#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "../code_1/array_double.hpp"

using namespace std;


int main(int argc, char* argv[])
{

    if(argc < 4){

        cout << "Missing command line arguments" << endl;
        return -1;

    }

    // TODO
    int numDoubled = 0;
    int capacity = 10;
    movieRecord* arr = new movieRecord[capacity];
    
    string lineRead[3];
    string exclude = argv[2];
    int numPrints = stoi(argv[3]);


    string filename = argv[1];
    string line = "";

    ifstream file;
    file.open(filename);
    int numSplits = 0;
    int first = 0;
    int numElements = 0;
    bool movieFound = false;
    movieRecord temp;

    if(file.is_open()){
        while(getline(file, line)){

            movieFound = false;
            if(capacity == numElements){
                doubleArray(arr, capacity);
                numDoubled++;
            }
            if(line.length() > 0){

                for(int i = 0; i < line.length(); i++){
                    if(line[i] == '\t'){
                        lineRead[numSplits] = line.substr(first, i);
                        numSplits++;
                        first = i + 1;

                    }
                }
                lineRead[numSplits] = line.substr(first, line.length());
                numSplits++;


                numSplits = 0;
                first = 0;

                if(checkMovieToBeIncluded(lineRead[2], exclude) != false){
                    temp.movieName = lineRead[0];
                    for(int j = 0; j < numElements; j++){
                        if(arr[j].movieName == temp.movieName){
                            movieFound = true;
                            arr[j].movieCount++;
                            arr[j].avgUserRating = (float)((arr[j].movieCount - 1)*arr[j].avgUserRating + stod(lineRead[1]))/arr[j].movieCount;
                        }
                    }
                    if(movieFound == false){
                        temp.avgUserRating = (float)stod(lineRead[1]);
                        temp.movieCount = 1;
                        arr[numElements] = temp;
                        numElements++;
                        
                    }
                    
                }
            }
        }
        file.close();
    }
    else{
        cout << "There was a problem opening the file" << endl;
        return -1;
    }
    
    sortArray(arr, numElements);
    cout << "Array doubled: " << numDoubled << endl;
    cout << "Distinct # of movies except " << exclude << ": " << numElements << endl;
    cout << "Total # of movies excluding " << exclude << " ratings: " << getTotalMoviesCount(arr, numElements) << endl;

    printTopNMovies(arr, numPrints);



    return 0;
}
