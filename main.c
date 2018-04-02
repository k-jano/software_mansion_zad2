#define _XOPEN_SOURCE 500
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {true, false} bool;

#define number 6
time_t arr_dates[number];
struct tm tmp[number];



bool printUsage(int size){
    if (size<6)
        return false;

    time_t now;
    time(&now);
    int date_processed=0;
    for(int i=size-1; i>=0; i--){
        if(date_processed<5){
            double difference;
            difference=difftime(now, arr_dates[i]);
            if(difference> 60*60*24*3){
                printf("This is not okay\n");
                return false;                
            }
            date_processed++;
        }
        else if(date_processed==5){
            double difference;
            difference=difftime(now, arr_dates[i]);
            if(difference> 60*60*24*3)
                return false;
            else
                return true;   
        }   
    }
    return false;
    
}

int main(){

    struct array{
        char* arg[30];
        int size;
    }myArray={{"2018-04-01 08:13:11", "2018-04-01 10:01:27", "2018-04-01 12:35:55", "2018-04-01 16:15:11", "2018-04-02 08:01:41", "2018-04-02 20:01:00"}, 6};
    
    int size=myArray.size;
    for(int i=0; i<size; i++){
        strptime(myArray.arg[i], "%Y-%m-%d %H:%M:%S", &tmp[i]);
        arr_dates[i]=mktime(&tmp[i]);
    } 

    printUsage(size);
}