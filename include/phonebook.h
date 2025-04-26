#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20

struct Phonebook{
    char* names[MAX_ENTRIES];
    char* phoneNumbers[MAX_ENTRIES];
    int number;
};

void initialize(struct Phonebook* phonebook);
bool contains(struct Phonebook* phonebook, char* name);
void trim(char* str);
void insert(struct Phonebook* phonebook, char* name, char* phoneNumber);
char* search(struct Phonebook* phonebook, char* name);
void print(struct Phonebook* phonebook);
void destruct(struct Phonebook* phonebook);
// phonebook.h
void phonebook_export_csv(struct Phonebook* phonebook, char* filename); 

#endif