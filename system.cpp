#include <iostream>
#include <string>

int main(int argc,char* argv[]){
    int BUFSIZE = 128;
    std::string programeName = argv[1];
    std::string logFileName = programeName+"_log.txt";
    for(int i=1;i<=1000;i++){
        FILE *logFile=fopen(logFileName.c_str(),"a");
        fprintf(logFile,"%d",i);
        fclose(logFile);
        for(int j=1;j<=10;j++){
            char buf[BUFSIZE];
            snprintf(buf, BUFSIZE, "./%s %d",programeName.c_str(),i);
            system(buf);
        }
        FILE *log=fopen(logFileName.c_str(),"a");
        fprintf(log,"\n");
        fclose(log);
    }

}