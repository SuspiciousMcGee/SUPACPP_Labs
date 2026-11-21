#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

int main(){

    std::ifstream data_file("input2D_float.txt");


    std::string firstline;
    std::vector<float> x_vals;
    std::vector<float> y_vals; 
    

    std::getline(data_file, firstline); // skip first line 
    char comma;
    int line_num = 0;

    float x,y;
    while(data_file >> x >> comma >> y){

        
        x_vals.push_back(x);
        y_vals.push_back(y);

        line_num++;

        std::cout << "Line "<< line_num << ":  (x,y) = (" << x << " , " << y << " ) " << std::endl;
        
    }




return 0;
}