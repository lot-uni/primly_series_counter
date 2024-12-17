#include <iostream>
#include <chrono>
using namespace std;


int main(int argc,char* argv[]){
    std::chrono::high_resolution_clock::time_point start=std::chrono::high_resolution_clock::now();
    int number = std::stoi(argv[1]);
    int counter = 0;
    for(int i=1;i<number;i++){
        if(number%i==0){
            counter++;
            if(counter==2){
                i=number;
            }
        }
    }
    if(counter==1){
        printf("素数\n");
    }else{
        printf("素数以外\n");
    }
    std::chrono::high_resolution_clock::time_point end=std::chrono::high_resolution_clock::now();
    std::chrono::microseconds duration=std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    long long microseconds=duration.count();
    FILE *logFile=fopen("naive_log.txt","a");
    fprintf(logFile,",%lld",microseconds);
    fclose(logFile);
    return 0;
}