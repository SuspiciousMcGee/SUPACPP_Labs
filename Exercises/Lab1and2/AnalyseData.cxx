#include <iostream>
#include <string>
#include <fstream>

int main(){

    std::ifstream data_file("input2D_float.txt");


    std::string line;
    while(std::getline(data_file,line)){
        std::cout << line << std::endl;
    }

return 0;
}