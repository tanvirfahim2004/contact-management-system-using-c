#include <stdio.h>
#include <string.h>

struct contact {
    char name[100], phone[100], email[100];
};

void addcontact() {
    FILE *file;
    file = fopen("contact.txt", "a");
    if (file == NULL) {
        printf("File does not exist.");
    } else {
        struct contact contact;
        fflush(stdin);
        printf("Enter Name : ");
        fgets(contact.name, sizeof(contact.name), stdin);

        printf("Enter Phone : ");
        fgets(contact.phone, sizeof(contact.phone), stdin);

        printf("Enter Email : ");
        fgets(contact.email, sizeof(contact.email), stdin);

        // Save each field on a new line
        fprintf(file, "%s", contact.name);
        fprintf(file, "%s", contact.phone);
        fprintf(file, "%s", contact.email);

        fclose(file);
        printf("Added to contact management system.\n");
    }
}

void displaycontacts() {
    struct contact contact;
    FILE *file;
    file = fopen("contact.txt", "r");
    if (file == NULL) {
        printf("File does not exist.");
    } else {
        printf("Contacts:\n");

        while (fgets(contact.name, sizeof(contact.name), file) &&
               fgets(contact.phone, sizeof(contact.phone), file) &&
               fgets(contact.email, sizeof(contact.email), file)) {
            printf("Name : %sPhone : %sEmail : %s\n", contact.name, contact.phone, contact.email);
        }

        fclose(file);
    }
}

void searchcontact() {
    struct contact contact;
    char searchname[100];
    int found = 0;

    FILE *file;
    file = fopen("contact.txt", "r");
    if (file == NULL) {
        printf("File does not exist.\n");
    } else {
        fflush(stdin);
        printf("Enter name to search: ");
        fgets(searchname, sizeof(searchname), stdin);

        while (fgets(contact.name, sizeof(contact.name), file) &&
               fgets(contact.phone, sizeof(contact.phone), file) &&
               fgets(contact.email, sizeof(contact.email), file)) {
            if (strstr(contact.name, searchname) != NULL) {
                printf("\nContact Found:\n");
                printf("Name : %sPhone : %sEmail : %s\n", contact.name, contact.phone, contact.email);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Contact not found.\n");
        }

        fclose(file);
    }
}

int main() {
    int choice;
    do {
        printf("\nContact Management System\n");
        printf("1. Add contact\n");
        printf("2. Display contacts\n");
        printf("3. Search contact\n");
        printf("4. Exit\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addcontact();
                break;
            case 2:
                displaycontacts();
                break;
            case 3:
                searchcontact();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
