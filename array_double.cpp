#include "array_double.hpp"
#include <iomanip>



bool checkMovieToBeIncluded(string movieMpaRating, string mpaRatingToBeExcluded){
    // TODO
    if(movieMpaRating == mpaRatingToBeExcluded){
        return false;
    }
    else{
    return true;
    }
}

void doubleArray(movieRecord *&movieArray, int &arrCapacity)
{
    // TODO
    movieRecord* new_arr = new movieRecord[arrCapacity * 2];

    for(int i = 0; i < arrCapacity; i++){
        new_arr[i] = movieArray[i];
    }
    
    arrCapacity = arrCapacity*2;


    delete[] movieArray;
    movieArray = NULL;

    movieArray = new_arr;

}

int getTotalMoviesCount(movieRecord* distinctMovies, int length) {
    // TODO

    int sum = 0;
    for(int i = 0; i < length; i++){
        if(distinctMovies[i].movieCount > 0){
            sum = sum + distinctMovies[i].movieCount;
        }
    }
    return sum;
}

void sortArray(movieRecord* distinctMovies, int length) {
    // TODO
    movieRecord temp; 

    for(int i = 0; i < length; i++){
        for(int j = i + 1; j < length; j++){
            if(distinctMovies[i].avgUserRating < distinctMovies[j].avgUserRating){
                temp = distinctMovies[i];
                distinctMovies[i] = distinctMovies[j];
                distinctMovies[j] = temp;
            }
            else if(distinctMovies[i].avgUserRating == distinctMovies[j].avgUserRating){
                if(distinctMovies[i].movieName > distinctMovies[j].movieName){
                    temp = distinctMovies[i];
                    distinctMovies[i] = distinctMovies[j];
                    distinctMovies[j] = temp;
                }
            }
        }
    }
}

void printTopNMovies(movieRecord* movieArray,int numberOfMovies)
{
    // TODO
    cout << fixed << setprecision(3);
    cout << "Movie Ratings\n---------------------------------------\n";
    for(int i = 0; i < numberOfMovies; i++){
        cout << movieArray[i].avgUserRating << " " << movieArray[i].movieName << endl;
    }
}



