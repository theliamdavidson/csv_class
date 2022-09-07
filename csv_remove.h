#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include "csv_write.h"

using namespace std;

#ifndef CSV_REMOVE_H
#define CSV_REMOVE_H
class Remove{
    public:
        void remove_file(string given_filename){
            try{
                if(filesystem::remove(given_filename)){
                    cout << "file " << given_filename << " removed";
                }
                else{
                    cout << "failure";
                }
                }
            catch(const std::filesystem::filesystem_error& err){
                std::cout << "filesystem error: " << err.what() << '\n';
            }
        }
};
#endif