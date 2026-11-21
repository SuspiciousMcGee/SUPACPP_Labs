#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>

struct Data {
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

std::vector<float> getMagnitude(const Data& data){

    int N_points = data.x_vals.size();
    std::vector<float> magnitudes;

    for(int i = 0; i<N_points;i++){
        float x = data.x_vals[i];
        float y = data.y_vals[i];
        magnitudes.push_back(sqrt(x*x + y*y));

        std::cout << "Data point " << i+1 << ": ||(x,y)|| = " << magnitudes[i] << std::endl;
    }

    return magnitudes;

}


std::string fitLSQ(const Data& data){


    float x_sum   = 0.0;
    float y_sum   = 0.0;
    float xy_sum  = 0.0;
    float xsq_sum = 0.0;

    int N;
    N = data.x_vals.size();

    for(int i=0;i<N;i++){

        const double x = data.x_vals[i];
        const double y = data.y_vals[i];

        x_sum += x;
        y_sum += y;
        xy_sum += x * y;
        xsq_sum += x * x;
    }

    float denom = N * xsq_sum - x_sum*x_sum;

    if(denom == 0.0) {
        std::cerr << "fit error : denominator is 0.\n";
        return {};
    }

    float p;
    p = (N * xy_sum - x_sum*y_sum)/denom;
    
    float q;
    q = (xsq_sum*y_sum - xy_sum*x_sum)/denom;


    char buffer[100];
    std::sprintf(buffer, "y = %.3f x + %.3f", p, q);

    std::string linfit = buffer;

    std::cout << "The final function using LSQ is: "
            << linfit << '\n';

    return linfit;
    

}
