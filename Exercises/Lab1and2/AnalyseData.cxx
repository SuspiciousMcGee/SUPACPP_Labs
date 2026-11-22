#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include "CustomFunctions.h"


int main(){

    Data data = readFile("input2D_float.txt");

    int choice;
   
    while(true){

        std::cout << "Choose an option:\n"
                << "1. Print N lines of data\n"
                << "2. Print the magnitude of every data point\n"
                << "3. Perform a least squares fit to the data\n"
                << "4. Calculate x^y values for data points\n"
                << "5. Exit \n"
                << "Enter 1, 2, 3, 4 or 5: ";

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
                printData(mag);
                saveOutput(mag,"magnitudes.txt");
                break;

            }
            case 3: {
                std::string linfit;
                linfit = fitLSQ(data);
                printData(linfit);
                saveOutput(linfit);
                break;
            }
            case 4: {
                std::vector<float> xpowy = xPOWy(data);
                printData(xpowy);
                saveOutput(xpowy,"xPOWy_values.txt");
                break;
            }
            case 5: {
                std::cout << "Exiting. " << std::endl;
                return 0; 
            }
            default: {
                std::cerr << "Invalid choice. Enter a number from 1 to 5.\n";
                break;
            }

        }

    }

return 0;
}


