#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

struct Data{
    std::vector<float> x_vals;
    std::vector<float> y_vals;
};

Data readFile( const char* filename){

    std::ifstream data_file(filename);

    Data result;

    std::string firstline;
    std::vector<float> x_vals;
    std::vector<float> y_vals;


    std::getline(data_file, firstline); // skip first line 
    char comma;
    int line_num = 0;

    float x,y;
    while(data_file >> x >> comma >> y){

        
        result.x_vals.push_back(x);
        result.y_vals.push_back(y);

        line_num++;
        
    }
    std::cout<< "file reading complete. Number of data lines: " << line_num << std::endl;

    return result;
}

void printData(const Data& data, int N){

    if (N < 0) {
        std::cout << "N cannot be negative; no lines will be printed.\n";
        return;
    }
    if(N > data.x_vals.size() || N > data.y_vals.size()){
        std::cout << "Warning: N is larger than the number of data points. Printing first 5 lines:" << std::endl;
        
        for(int i=0;i<5;i++){
            std::cout << "Line " << i + 1 << ": (x, y) = (" << data.x_vals[i] << ", " << data.y_vals[i] << ")\n";
        }
    
    }else{

        for(int i=0;i<N;i++){
            std::cout << "Line " << i + 1 << ": (x, y) = (" << data.x_vals[i] << ", " << data.y_vals[i] << ")\n";
        }

    }


}


int main(){

    Data data = readFile("input2D_float.txt");

    int N;
    std::cout << "Insert number of data lines to be printed :  ";

    if (!(std::cin >> N)) {
        std::cerr << "Please enter a valid integer for N.\n";
        return 1;
    }

    printData(data, N);


return 0;
}

