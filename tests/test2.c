#include "../include/phonebook.h"
#include <stdio.h>
#include <string.h>

int main(){
    printf("=== TEST 2: Multiple Entries ===\n");
    
    struct Phonebook phonebook;
    initialize(&phonebook);
    
    // Test data
    char* names[] = {"Alice Smith", "Bob Johnson", "Charlie Brown"};
    char* phones[] = {"111-222-3333", "444-555-6666", "777-888-9999"};
    int count = 3;
    
    // Add multiple entries
    for (int i = 0; i < count; i++){
        insert(&phonebook, names[i], phones[i]);
        printf("Added %d: %s, %s\n", i+1, names[i], phones[i]);
    }
    
    // Verify count
    if (phonebook.number == count){
        printf("All %d entries added\n", count);
    }else{
        printf("Wrong count (%d/%d)\n", phonebook.number, count);
    }
    
    // Print all entries
    printf("\nAll entries:\n");
    print(&phonebook);
    
    destruct(&phonebook);
    printf("Test completed\n");
    return 0;
}