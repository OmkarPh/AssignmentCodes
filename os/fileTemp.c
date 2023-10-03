#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>
#include <fcntl.h>

char *FILE_NAME = "mytext.txt";

void readFile(){
    printf("Please wait (10 seconds) while reading the file  %s ...\n", FILE_NAME);

    FILE *file = fopen(FILE_NAME, "r");

    sleep(3);

    char * buffer = 0;
    long length;
    fseek (file, 0, SEEK_END);
    length = ftell (file);
    fseek (file, 0, SEEK_SET);
    buffer = malloc (length);
    if (buffer) {
        fread (buffer, 1, length, file);
    }
    printf("Text in file: %s", buffer);
    printf("\n");
    fclose(file);
    printf("Reading completed !!\n");
}
void writeToFile(char *text){
    printf("Please wait (10 seconds) while writing to file %s ...\n", FILE_NAME);

    FILE *file = fopen(FILE_NAME, "w");
    fprintf(file, "%s\n", text);

    sleep(3);

	fclose(file);
    printf("completed !!");
}


int main(){

    int choice;
    char text[500];
    
    while (1){    
        printf("Options:\t 1. Read file \t 2. Write file \t 3. Exit \n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                readFile();
                break;
            case 2:
                writeToFile("Hellllllo !!");
                break;
            case 3:
                printf("Bye !!");
                return 0;
            default:
                printf("Invalid choice, try again !\n");
                break;
        }
        printf("\n");
    }

    return 0;
}