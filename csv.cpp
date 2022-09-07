#include "csv_read.h"
#include "csv_write.h"
#include "csv_remove.h"
#include <vector>

using namespace std;

string file_input(){
    string filename;
    cout << "Enter the file name (without extension): ";
    cin >> filename;
    filename.append(".csv");
    return(filename);
}
int main(){
    int cont = 1;
    Remove r;
    vector<string> files;
    while(cont){
        char response;
        cout << "Do you want to read or write? (r/w): ";
        cin >> response;
        switch(response){
            case 'r':
            {
                Read fileObj;
                // call the file open function from the 
                // read class with the generic user question
                fileObj.File_O(file_input());
                break;
            }
            case 'w':
            {
                Write newFile;
                newFile.populate_file(file_input());
                // keep track of the created files for garbage collection
                // remove if file is needed
                files.insert(files.end(), newFile.created_file.begin(),newFile.created_file.end());
                break;
            }
            default:
            {
                cout << "error! please try again! ";
                break;
            }
        }
        cout << "input another file? (y/n): ";
        cin >> response;
        if(response != 'y'){
            if(files.size() != 0){
                cout << "delete created files? (y/n): ";
                cin >> response;
                if(response != 'n'){
                    for(int i = 0; i < files.size(); i++)
                        r.remove_file(files[i]);                      
                }
            }
            cont = 0;
        }
    }
}