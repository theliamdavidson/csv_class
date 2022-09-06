#include "csv_read.h"
#include "csv_write.h"

using namespace std;

int main(){
    int cont = 1;
    while(cont){
        char response;
        cout << "Do you want to read or write? (r/w): ";
        cin >> response;
        switch(response){
            case 'r':
            {
                Read fileObj;
                break;
            }
            case 'w':
            {
                Write newFile;
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
            cont = 0;
        }
    }
}