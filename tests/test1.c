#include "../include/phonebook.h"
#include <stdio.h>
#include <string.h>

int main(){
    printf("=== TEST 1: Single Entry Addition ===\n");
    
    // 1. Initialize phonebook
    struct Phonebook phonebook;
    initialize(&phonebook);
    printf("Phonebook initialized\n");
    
    // 2. Add one entry
    insert(&phonebook, "John Doe", "123-456-7890");
    printf("Added: John Doe, 123-456-7890\n");
    
    // 3. Verify count
    if (phonebook.number == 1){
        printf("Correct count (1 entry)\n");
    }else{
        printf("Wrong count (%d entries)\n", phonebook.number);
    }
    
    // 4. Test search
    char* result = search(&phonebook, "John Doe");
    if (result && strcmp(result, "123-456-7890") == 0){
        printf("Found correct number\n");
    }else{
        printf("Number not found\n");
    }
    
    // 5. Cleanup
    destruct(&phonebook);
    printf("Test completed\n");
    return 0;
}