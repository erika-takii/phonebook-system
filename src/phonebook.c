#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "../include/phonebook.h"

void initialize(struct Phonebook* phonebook){
    phonebook->number = 0;
}

bool contains(struct Phonebook* phonebook, char* name){
    for(int i = 0; i < phonebook->number; i++){
        if(strcmp (phonebook->names[i], name) == 0){
            return true;
        }
    }
    return false;
}

void trim(char* str){
    int length = strlen(str);
    if(str[length - 1] == '\n'){
        str[length - 1] = '\0';
    }
}

void insert(struct Phonebook* phonebook, char* name, char* phoneNumber){
    if(phonebook->number == MAX_ENTRIES){
        printf("The phone book is full.\n");
    }
    
    if(contains(phonebook, name)){
        printf("This name is already registered.\n");
    }
    else{
        phonebook->names[phonebook->number] = (char*)malloc(strlen(name) + 1);
        if (phonebook->names[phonebook->number] == NULL){
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        phonebook->phoneNumbers[phonebook->number] = (char*)malloc(strlen(phoneNumber) + 1);

        strcpy(phonebook->names[phonebook->number], name);
        strcpy(phonebook->phoneNumbers[phonebook->number], phoneNumber);

        phonebook->number++;
    }
    
}

char* search(struct Phonebook* phonebook, char* name){
    char* result;
    for(int i = 0; i < phonebook->number; i++){
        if(strcmp(phonebook->names[i], name) == 0){
            return phonebook->phoneNumbers[i];
        }
    }
    return NULL;

}

void print(struct Phonebook* phonebook){
    for(int i = 0; i < phonebook->number; i++){
        printf("%d: %s, %s\n", i+1, phonebook->names[i], phonebook->phoneNumbers[i]);
    }
}

void destruct(struct Phonebook* phonebook){
    for(int i = 0; i < phonebook->number; i++){
        free(phonebook->names[i]);
        free(phonebook->phoneNumbers[i]);
    }
}

void phonebook_export_csv(struct Phonebook* phonebook, char* filename){
    FILE* fp = fopen(filename, "w");
    if (!fp){
        perror("Failed to open file");
        return;
    }
    
    fprintf(fp, "Name,Phone Number\n");
    for (size_t i = 0; i < phonebook->number; i++){
        fprintf(fp, "\"%s\",\"%s\"\n", phonebook->names[i], phonebook->phoneNumbers[i]);
    }
    
    fclose(fp);
}
    