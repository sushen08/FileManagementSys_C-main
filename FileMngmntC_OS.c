#include <stdio.h>
#include <stdlib.h>
void main_menu();
void create_file();
void delete_file();
void rename_file();
void display_file();
void append_file();
void edit_file();
void delete_content();
void copy_file();
void move_file();
void change_file_permissions();
void invalid_choice();
int main() {
    main_menu();
    return 0;
}
void main_menu() {
    system("clear");
    printf("File Management System\n");
    printf("----------------------\n");
    printf("1. Create a file\n");
    printf("2. Delete a file\n");
    printf("3. Rename a file\n");
    printf("4. Display file contents\n");
    printf("5. Append to a file\n");
    printf("6. Edit file contents\n");
    printf("7. Delete file contents\n");
    printf("8. Copy a file\n");
    printf("9. Move a file\n");
    printf("10. Change file permissions\n");
    printf("11. Exit\n");
    printf("\nEnter your choice: ");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            create_file();
            break;
        case 2:
            delete_file();
            break;
        case 3:
            rename_file();
            break;
        case 4:
            display_file();
            break;
        case 5:
            append_file();
            break;
        case 6:
            edit_file();
            break;
        case 7:
            delete_content();
            break;
        case 8:
            copy_file();
            break;
        case 9:
            move_file();
            break;
        case 10:
            change_file_permissions();
            break;
        case 11:
            exit(0);
        default:
            invalid_choice();
            break;
    }
}
void create_file() {
    char filename[100];
    printf("Enter file name: ");
    scanf("%s", filename); 
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        printf("File already exists.\n");
        fclose(file);
    } else {
        file = fopen(filename, "w");
        if (file != NULL) {
            printf("File created successfully.\n");
            fclose(file);
        } else {
            printf("Error creating file.\n");
        }
    } 
    system("read -n 1 -s -r -p \"Press any key to continue...\"");
}
void delete_file() {
    char filename[100];
    printf("Enter file name: ");
    scanf("%s", filename);
    if (remove(filename) == 0) {
        printf("File deleted successfully.\n");
    } else {
        printf("File not found or unable to delete.\n");
    }
    system("read -n 1 -s -r -p \"Press any key to continue...\"");
}
void rename_file() {
    char filename[100];
    printf("Enter current file name: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        char new_filename[100];
        printf("Enter new file name: ");
        scanf("%s", new_filename);  
        if (rename(filename, new_filename) == 0) {
            printf("File renamed successfully.\n");
        } else {
            printf("Error renaming file.\n");
        }
        fclose(file);
    } else {
        printf("File not found.\n");
    }  
    system("read -n 1 -s -r -p \"Press any key to continue...\"");
}
void display_file() {
    char filename[100];
    printf("Enter file name: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        char ch;
        while ((ch = fgetc(file)) != EOF) {
            putchar(ch);
        }
        fclose(file);
    } else {
        printf("File not found.\n");
    }
    system("read -n 1 -s -r -p \"Press any key to continue...\"");
}
void append_file() {
    char filename[100];
    printf("Enter file name: ");
    scanf("%s", filename); 
    FILE *file = fopen(filename, "a");
    if (file != NULL) {
        char text[100];
        printf("Enter text to append: ");
        scanf(" %[^\n]s", text);  
        fprintf(file, "%s\n", text);
        fclose(file);       
        printf("Text appended successfully.\n");
    } else {
        printf("File not found.\n");
    }   
    system("read -n 1 -s -r -p \"Press any key to continue...\"");
}
void edit_file() {
    char filename[100];
    printf("Enter file name: ");
    scanf("%s", filename); 
    FILE *file = fopen(filename, "r+");
    if (file != NULL) {
        char text[100];
        printf("Enter new text: ");
        scanf(" %[^\n]s", text);   
        fseek(file, 0, SEEK_SET);
        fprintf(file, "%s\n", text);
        fclose(file);      
        printf("File content edited successfully.\n");
    } else {
        printf("File not found.\n");
    } 
    system("read -n 1 -s -r -p \"Press any key to continue...\"");
}
void delete_content() {
    char filename[100];
    printf("Enter file name: ");
    scanf("%s", filename); 
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        fclose(file);
        printf("File content deleted successfully.\n");
    } else {
        printf("File not found.\n");
    } 
    system("read -n 1 -s -r -p \"Press any key to continue...\"");
}
void copy_file() {
    char source_file[100], destination_file[100];
    printf("Enter source file name: ");
    scanf("%s", source_file);   
    FILE *source = fopen(source_file, "r");
    if (source != NULL) {
        printf("Enter destination file name: ");
        scanf("%s", destination_file);      
        FILE *destination = fopen(destination_file, "w");
        if (destination != NULL) {
            char ch;
            while ((ch = fgetc(source)) != EOF) {
                fputc(ch, destination);
            }
            fclose(destination);
            printf("File copied successfully.\n");
        } else {
            printf("Error creating destination file.\n");
        }    
        fclose(source);
    } else {
        printf("Source file not found.\n");
    }
    system("read -n 1 -s -r -p \"Press any key to continue...\"");
}
void move_file() {
    char source_file[100], destination_dir[100];
    printf("Enter source file name: ");
    scanf("%s", source_file);   
    FILE *file = fopen(source_file, "r");
    if (file != NULL) {
        printf("Enter destination directory: ");
        scanf("%s", destination_dir);       
        char command[200];
        snprintf(command, sizeof(command), "mv %s %s/%s", source_file, destination_dir, source_file);
        int result = system(command);
        if (result == 0) {
            printf("File moved successfully.\n");
        } else {
            printf("Error moving file.\n");
        }       
        fclose(file);
    } else {
        printf("File not found.\n");
    }    
    system("read -n 1 -s -r -p \"Press any key to continue...\"");
}
void change_file_permissions() {
    char filename[100];
    printf("Enter file name: ");
    scanf("%s", filename);   
    printf("Enter new file permissions (in octal): ");
    int permissions;
    scanf("%o", &permissions);   
    if (chmod(filename, permissions) == 0) {
        printf("File permissions changed successfully.\n");
    } else {
        printf("Error changing file permissions.\n");
    }   
    system("read -n 1 -s -r -p \"Press any key to continue...\"");
}
void invalid_choice() {
    printf("Invalid choice. Please try again.\n");
    system("read -n 1 -s -r -p \"Press any key to continue...\"");
}
