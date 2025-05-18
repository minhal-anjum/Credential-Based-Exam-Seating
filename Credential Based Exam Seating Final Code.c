#include <stdio.h>
#include <string.h>

#define SIZE 50
#define ROWS 5
#define COLS 20


void showLine();
void studentLogin();
void adminLogin();
void saveDataToFile();
void showSeatingArrangement();
void assignSeat(int seatNumber, int *row, int *col);


char names[SIZE][20] = {
    "Adil", "Nadia", "Samir", "Hira", "Fahim",
    "Kiran", "Zeeshan", "Maya", "Kashan", "Rida",
    "Bilal", "Sana", "Arif", "Naila", "Raza",
    "Alina", "Usman", "Sarah", "Faizan", "Nashit",
    "Ayesha", "Hassan", "Imran", "Saira", "Danish" 
    "Adeel", "Bushra", "Khalid", "Rabia", "Waleed",
    "Neha", "Tariq", "Fariha", "Asad", "Lubna",
    "Yasir", "Mehwish", "Jaweria", "Shahzaib", "Komal",
    "Adnan", "Huda", "Zohaib", "Beenish", "Irfan",
    "Areej", "Salman", "Zunaira", "Mobeen", "Hafsa"
};

char passwords[SIZE][20] = {
    "Adil", "Nadia", "Samir", "Hira", "Fahim",
    "Kiran", "Zeeshan", "Maya", "Kashan", "Rida",
    "Bilal", "Sana", "Arif", "Naila", "Raza",
    "Alina", "Usman", "Sarah", "Faizan", "Nashit",
    "Ayesha", "Hassan", "Imran", "Saira", "Danish" 
    "Adeel", "Bushra", "Khalid", "Rabia", "Waleed",
    "Neha", "Tariq", "Fariha", "Asad", "Lubna",
    "Yasir", "Mehwish", "Jaweria", "Shahzaib", "Komal",
    "Adnan", "Huda", "Zohaib", "Beenish", "Irfan",
    "Areej", "Salman", "Zunaira", "Mobeen", "Hafsa"
};

int ids[SIZE] = {
    1001, 1002, 1003, 1004, 1005, 
    1006, 1007, 1008, 1009, 1010, 
    1011, 1012, 1013, 1014, 1015,
    1016, 1017, 1018, 1019, 1020,
    1021, 1022, 1023, 1024, 1025,
    1026, 1027, 1028, 1029, 1030,
    1031, 1032, 1033, 1034, 1035,
    1036, 1037, 1038, 1039, 1040,
    1041, 1042, 1043, 1044, 1045,
    1046, 1047, 1048, 1049, 1050
};

int main() {
    int choice;

    saveDataToFile();

    showLine();
    printf(" WELCOME TO EXAM SEATING SYSTEM\n");
    showLine();
    printf("Are you Admin or Student?\n1. Admin\n2. Student\nChoice: ");
    scanf("%d", &choice);

    showLine();

    if (choice == 1)
        adminLogin();
    else if (choice == 2)
        studentLogin();
    else
        printf("? Invalid choice! Please select 1 or 2.\n");

    showLine();
    return 0;
}

void showLine() {
    printf("========================================\n");
}

void saveDataToFile() {
    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf(" Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < SIZE; i++) {
        fprintf(fp, "ID: %d\tName: %s\tPassword: %s\n", ids[i], names[i], passwords[i]);
    }

    fclose(fp);
}

void studentLogin() {
    char name[50];
    int roll, found = 0;

    printf(" STUDENT LOGIN\n");
    printf("Enter your Name: ");
    scanf("%s", name);
    printf("Enter your Roll Number: ");
    scanf("%d", &roll);

    for (int i = 0; i < SIZE; i++) {
        if (strcmp(name, names[i]) == 0 && roll == ids[i]) {
            printf("\n Login Successful!\n");
            printf("Your Record:\nID: %d\nName: %s\n", ids[i], names[i]);

            
            int row, col;
            assignSeat(i + 1, &row, &col);
            printf("Your Exam Seat: Row %d, Column %d\n", row + 1, col + 1);

            found = 1;
            break;
        }
    }

    if (!found)
        printf(" Student record not found!\n");
}

void adminLogin() {
    char adminName[50];
    char adminPassword[50];

    printf("ADMIN LOGIN\n");
    printf("Enter Admin Name: ");
    getchar(); // consume newline left in buffer
    fgets(adminName, sizeof(adminName), stdin);
    adminName[strcspn(adminName, "\n")] = 0; // remove newline

    printf("Enter Admin Password: ");
    scanf("%s", adminPassword);

    if (strcmp(adminName, "Farzeen Ali") == 0 && strcmp(adminPassword, "Techzeen") == 0) {
        printf("\n Welcome Admin %s\n", adminName);
        printf("Showing student records from file:\n\n");

        FILE *fp = fopen("students.txt", "r");
        if (fp == NULL) {
            printf("Error reading file!\n");
            return;
        }

        char line[200];
        while (fgets(line, sizeof(line), fp)) {
            printf("%s", line);
        }
        fclose(fp);

        showLine();
        printf(" SEATING ARRANGEMENT OVERVIEW:\n");
        showSeatingArrangement();

    } else {
        printf("Access Denied: Invalid credentials.\n");
    }
}


void showSeatingArrangement() {
    int seat = 1;
    for (int i = 0; i < ROWS; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < COLS; j++) {
            if (seat <= SIZE)
                printf("[%2d] ", seat);
            else
                printf("[--] ");
            seat++;
        }
        printf("\n");
    }
}


void assignSeat(int seatNumber, int *row, int *col) {
    seatNumber--; // convert to 0-indexed
    *row = seatNumber / COLS;
    *col = seatNumber % COLS;
}