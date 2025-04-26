#include "../include/phonebook.h"
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

void display_menu(){
    printf("\n=== Phonebook Manager ===\n");
    printf("1. Add new entries\n");
    printf("2. Search by name\n");
    printf("3. Display all contacts\n");
    printf("4. Export to CSV\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void clear_input_buffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void add_entries(struct Phonebook* phonebook){
    int num_entries;
    printf("Number of entries to add: ");
    
    if (scanf("%d", &num_entries) != 1 || num_entries <= 0){
        printf("Invalid input. Please enter a positive number.\n");
        clear_input_buffer();
        return;
    }
    clear_input_buffer();

    for (int i = 0; i < num_entries; i++){
        char name[MAX_NAME_LENGTH], phone[MAX_PHONE_LENGTH];
        
        printf("\nEntry %d/%d\n", i+1, num_entries);
        printf("Name: ");
        if (!fgets(name, MAX_NAME_LENGTH, stdin)){
            printf("Error reading input.\n");
            clear_input_buffer();
            continue;
        }
        trim(name);

        printf("Phone Number: ");
        if (!fgets(phone, MAX_PHONE_LENGTH, stdin)){
            printf("Error reading input.\n");
            clear_input_buffer();
            continue;
        }
        trim(phone);

        insert(phonebook, name, phone);
    }
}

void search_contact(struct Phonebook* phonebook){
    char name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    
    if (!fgets(name, MAX_NAME_LENGTH, stdin)){
        printf("Error reading input.\n");
        clear_input_buffer();
        return;
    }
    trim(name);

    char* result = search(phonebook, name);
    if (result){
        printf("\nContact Found:\n");
        printf("Name: %s\n", name);
        printf("Phone: %s\n", result);
    }else{
        printf("Contact not found.\n");
    }
}

void export_to_csv(struct Phonebook* phonebook){
    char filename[MAX_NAME_LENGTH];
    printf("Enter CSV filename (e.g., contacts.csv): ");
    
    if (!fgets(filename, MAX_NAME_LENGTH, stdin)){
        printf("Error reading input.\n");
        clear_input_buffer();
        return;
    }
    trim(filename);

    phonebook_export_csv(phonebook, filename);
    printf("Successfully exported to %s\n", filename);
}

int main(){
    struct Phonebook phonebook;
    initialize(&phonebook);
    
    int choice;
    do {
        display_menu();
        
        if (scanf("%d", &choice) != 1){
            printf("Invalid input. Please enter a number.\n");
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();

        switch (choice){
            case 1:
                add_entries(&phonebook);
                break;
            case 2:
                search_contact(&phonebook);
                break;
            case 3:
                printf("\n=== All Contacts ===\n");
                print(&phonebook);
                break;
            case 4:
                export_to_csv(&phonebook);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    destruct(&phonebook);
    return 0;
}
