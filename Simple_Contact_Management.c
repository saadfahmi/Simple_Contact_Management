#include "lib.h"
Contact contacts[MAX_CONTACTS];

int contact_count = 0;

void add_contact()
{
        if (contact_count >= MAX_CONTACTS)
        {
                printf("Contact list is full.\n");
                return;
        }

        printf("Enter Your Name: ");
        scanf(" %[^\n]", contacts[contact_count].name);
        printf("Enter Phone: ");
        scanf(" %[^\n]", contacts[contact_count].phone);
        printf("Enter Email: ");
        scanf(" %[^\n]", contacts[contact_count].email);

        contact_count++;
        printf("Contact added successfully!\n");
}

void display_contacts()
{
        if (contact_count == 0)
        {
                printf("No contacts available.\n");
                return;
        }

        printf("\nContacts:\n");
        for (int i = 0; i < contact_count; i++)
        {
                printf("%d. Name: %s, Phone: %s, Email: %s\n",
                       i + 1, contacts[i].name, contacts[i].phone, contacts[i].email);
        }
}

void search_contact()
{
        char search_name[NAME_LEN];
        printf("Enter Name to search: ");
        scanf(" %[^\n]", search_name);

        for (int i = 0; i < contact_count; i++)
        {
                if (strcmp(contacts[i].name, search_name) == 0)
                {
                        printf("Contact found: Name: %s, Phone: %s, Email: %s\n",
                               contacts[i].name, contacts[i].phone, contacts[i].email);
                        return;
                }
        }
        printf("Contact not found.\n");
}

void delete_contact()
{
        char delete_name[NAME_LEN];
        printf("Enter Name to delete: ");
        scanf(" %[^\n]", delete_name);

        for (int i = 0; i < contact_count; i++)
        {
                if (strcmp(contacts[i].name, delete_name) == 0)
                {
                        for (int j = i; j < contact_count - 1; j++)
                        {
                                contacts[j] = contacts[j + 1];
                        }
                        contact_count--;
                        printf("Contact deleted successfully.\n");
                        return;
                }
        }
        printf("Contact not found.\n");
}

void save_file()
{
        FILE *file = fopen("contacts.txt", "w");
        if (!file)
        {
                printf("Error saving contacts.\n");
                return;
        }

        for (int i = 0; i < contact_count; i++)
        {
                fprintf(file, "%s,%s,%s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
        }

        fclose(file);
        printf("Contacts saved to file.\n");
}

int main()
{
        int choice;

        do
        {
                printf("\nContact Management System\n");
                printf("1. Add Contact\n");
                printf("2. Display Contacts\n");
                printf("3. Search Contact\n");
                printf("4. Delete Contact\n");
                printf("5. Save Contacts to File\n");
                printf("6. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                getchar();

                switch (choice)
                {
                case 1:
                        add_contact();
                        break;
                case 2:
                        display_contacts();
                        break;
                case 3:
                        search_contact();
                        break;
                case 4:
                        delete_contact();
                        break;
                case 5:
                        save_file();
                        break;
                case 6:
                        printf("Exiting the program.\n");
                        break;
                default:
                        printf("Invalid choice. Please try again.\n");
                }
        } while(choice != 6);
        return 0;
}
