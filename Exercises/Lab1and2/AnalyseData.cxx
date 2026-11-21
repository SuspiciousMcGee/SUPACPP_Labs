#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include "CustomFunctions.h"


int main(){

    Data data = readFile("input2D_float.txt");

    int choice;
   
    std::cout << "Choose an option:\n"
              << "1. Print N lines of data\n"
              << "2. Print the magnitude of every data point\n"
              << "Enter 1 or 2: ";

      if (!(std::cin >> choice)) {
        std::cerr << "Please enter a valid choice.\n";
        return 1;
    }

    switch(choice){

        case 1: 
        {
            int N;
            std::cout << "Insert number of data lines to be printed :  ";

            if (!(std::cin >> N)) {
                std::cerr << "Please enter a valid integer for N.\n";
                return 1;
            }

            printData(data, N);
            break;
        }
        case 2: 
        {

            std::vector<float> mag;
            mag = getMagnitude(data);
            break;

        }
        default: 
        {
            std::cerr << "Invalid choice. Enter 1 or 2.\n";
            return 1;
        }

    }



return 0;
}

