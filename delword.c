/**
 * Author: Hair Albeiro Parra Barrera
 * The following program will scan a CSV file and 
 * */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

void del_occ(const char* filename, const char* WORD) ; 

int main(void){  

    const char* filename =  "sample.txt"; // place your CSV file here
    del_occ(filename, "WORD"); 

    return 0; 
}

// Scans the CSV file and deletes all occurrences of WORD.
// The flags mark important points in the program.
void del_occ( const char* filename, const char*  WORD) { 

    printf("FLAG 1\n"); 
    FILE *fp = fopen(filename, "r"); // Open the input file in read mode
    const char* tempFilename = "temp.txt"; 
    FILE *tempFile = fopen(tempFilename, "w+"); // create temp in write+ mode
    // allocate memory for all the required strings
    char *buffer = (char* )malloc(1000); // to read line by line
    char *temp = (char* ) malloc(1000); // to manipulate the line
    char *token = (char* )malloc(1000);  // tokens will go here

    // Go thorugh each line 
    while( (fgets(buffer, 1000, fp)) != NULL) { 
        printf("\n*LINE FLAG*\n");

        strcpy(temp, buffer); // copy contents of buffer to temp 
        token  = strtok(temp, " \n"); //obtain the first token

        while( token != NULL) {  // while there are available tokens
            printf("[Token: (%s)]\n", token); 
            if(strcmp(token, WORD) != 0 ) { // if no match 
                fprintf(tempFile, " %s", token); // copy to the documtns
            }
            token = strtok(NULL, " \n"); // get next token 
        }
        fprintf(tempFile, "\n"); // need to add this at the end of the line
        
    }

    // printf("flag2\n"); 

    fclose(fp); // close the file 

    // Now we will rewrite the file 
    fp = fopen(filename, "w"); // overwrite
    rewind(tempFile); // reset pointer to beginning of the file 

    // Copy the contents of the temporary file into the input csv file
    while( (fgets(buffer, 1000, tempFile)) != NULL)  {
        fprintf(fp, "%s", buffer); 
    }

    // Deallocate memory & close files 
    free(buffer); 
    free(temp); 
    free(token); 
    buffer = NULL; 
    temp = NULL; 
    token = NULL; 
    fclose(fp); 
    fclose(tempFile); 

    // printf("flag3\n"); 
}
