#include <stdio.h> // Includes the Standard Input Output library for functions like printf,scanf, etc.
#include <string.h> // Includes the String library to enable string handling functions like strcpy, strlen, etc.
#define SIZE 50 //Defines a named SIZE with value 50 students
#define ROWS 5 // Defines a named ROWS with value 5 for 5 rows 
#define COLS 20 // Defines a named COLS with value 20 for 20 rows

// Function declarations
void showLine(); // Function prototype (prototype is a declaration of a function) for 'showLine' 
// Likely displays a dividing line in the code (e.g.----------------")
void studentLogin(); // Function prototype for 'studentLogin'
// Handles student login logic (e.g., inputting credentials, verifying identity)
void adminLogin(); // Function prototype for 'adminLogin'
// Handles admin login logic, which have more options or powers than student login
void saveDataToFile();  // Function prototype for 'saveDataToFile'                        
// Saves student and seating information to a file so it doesn't get lost when the program closes
void showSeatingArrangement(); // Function prototype for 'showSeatingArrangement'
// // This shows the current seating — like which seats are taken and which are free
void assignSeat(int seatNumber, int *row, int *col);
// Function prototype for 'assignSeat'
// Assigns a seat to a student based on seatNumber
// It figures out the row and column for the seat and gives them back using pointers (A pointer in C is a special kind of variable that stores the memory address of another variable)


// student data
char names[SIZE][20] = { // Array of student names. Each name can hold up to 20 characters

// List of 50 names representing registered students or users
    "Adil", "Nadia", "Samir", "Hira", "Fahim",
    "Kiran", "Zeeshan", "Maya", "Kashan", "Rida",
    "Bilal", "Sana", "Arif", "Naila", "Raza",
    "Alina", "Usman", "Sarah", "Faizan", "Nashit",
    "Ayesha", "Hassan", "Imran", "Saira", "Danish",
    "Adeel", "Bushra", "Khalid", "Rabia", "Waleed",
    "Neha", "Tariq", "Fariha", "Asad", "Lubna",
    "Yasir", "Mehwish", "Jaweria", "Shahzaib", "Komal",
    "Adnan", "Huda", "Zohaib", "Beenish", "Irfan",
    "Areej", "Salman", "Zunaira", "Mobeen", "Hafsa"
};

char passwords[SIZE][20] = { // The password strings are currently same as names, stored with max length 20 characters.

// Passwords are in the same order as the names so we can check login easily
    "Adil", "Nadia", "Samir", "Hira", "Fahim",
    "Kiran", "Zeeshan", "Maya", "Kashan", "Rida",
    "Bilal", "Sana", "Arif", "Naila", "Raza",
    "Alina", "Usman", "Sarah", "Faizan", "Nashit",
    "Ayesha", "Hassan", "Imran", "Saira", "Danish",
    "Adeel", "Bushra", "Khalid", "Rabia", "Waleed",
    "Neha", "Tariq", "Fariha", "Asad", "Lubna",
    "Yasir", "Mehwish", "Jaweria", "Shahzaib", "Komal",
    "Adnan", "Huda", "Zohaib", "Beenish", "Irfan",
    "Areej", "Salman", "Zunaira", "Mobeen", "Hafsa"
};

int ids[SIZE] = { // Array of unique student IDs corresponding to each student.

// Used for identification, authentication, or record-keeping purposes.
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
// The main function starts the exam seating system,
// asks the user if they are an Admin or Student,
// and then directs them to the appropriate login process.


    int choice; // Variable to store user's choice (Admin or Student)
    saveDataToFile(); // Save data to a file so it’s ready to use later

    do { // Start of the main menu loop
        showLine(); // Print a decorative line
        printf(" WELCOME TO CREDENTIAL BASED EXAM SEATING ARRANGEMENT\n"); // Display welcome message
        showLine(); // Print another decorative line

        // Nested loop for delay effect (pure nested loop use)
        printf("Loading"); // Print another decorative line
        for (int i = 0; i < 20; i++) { // Outer loop runs 20 times for visible loading
            printf(".\a\a\a\a"); // Print dots and beep sounds
            for (int j = 0; j < 100000000; j++);  // Inner loop creates a time delay (dummy delay)
        }
        printf("\n"); // New line after loading

        //Ask user for role
        printf("Are you:\n1. Admin\n2. Student\n3. Exit\nChoice: "); 
        scanf("%d", &choice); // Take input from user
        showLine(); // Print decorative line

        switch (choice) { 
            case 1: // If Admin is selected
                adminLogin(); // Call admin login function
                break;
            case 2: // If Student is selected
                studentLogin(); // Call student login function
                break;
            case 3:  // Exit case
                printf("Exiting the system. Goodbye!\n"); // Farewell message
                break;
            default: // Invalid input handling
                printf("Invalid choice. Please enter 1, 2, or 3.\n"); // Show error message
        }
    } while (choice != 3);  // Exit only if user enters 3

    showLine(); // Final decorative line
    return 0; // End of main function
}

// Function to print a horizontal line
void showLine() {
    printf("======================================================\n");
}

// Function to save student data to a file
void saveDataToFile() {
    FILE *fp = fopen("students.txt", "w"); // Open file in write mode
    if (fp == NULL) { // Check for file open error
        printf(" Error opening file for writing!\n");
        return;
    }
    for (int i = 0; i < SIZE; i++) { // Loop through student data
        fprintf(fp, "ID: %d\tName: %s\tPassword: %s\n", ids[i], names[i], passwords[i]); // Write student info to file
    }
    fclose(fp); // Close the file
}

// Function to handle student login
void studentLogin() {
    char name[50]; // Variable to store student name
    int roll, found = 0; // Roll number and flag to check if student is found

    printf(" STUDENT LOGIN\n"); // Student login header
    printf("Enter your Name: ");
    scanf("%s", name); // Get student name
    printf("Enter your Roll Number: ");
    scanf("%d", &roll);

    for (int i = 0; i < SIZE; i++) { // Search through the student list
        if (strcmp(name, names[i]) == 0 && roll == ids[i]) { // Check if credentials match
            printf("\n Login Successful!\n"); // Success message
            printf("Your Record:\nID: %d\nName: %s\n", ids[i], names[i]); // Show student details

            int row, col;  // Variables to hold assigned seat position
            assignSeat(i + 1, &row, &col); // Assign seat based on student index
            printf("Your Exam Seat: Row %d, Column %d\n", row + 1, col + 1); // Show seat assignment

            found = 1;  // Mark student as found
            break; // Exit loop once found
        }
    }

    if (!found) // If student not found
        printf(" Student record not found!\n"); // Error message
}

// Function to handle admin login and display data
void adminLogin() {
    char adminName[50]; // Variable to store admin name
    char adminPassword[50]; // Variable to store admin password

    printf("ADMIN LOGIN\n"); // Admin login header
    printf("Enter Admin Name: ");
    getchar(); // Clear newline character from buffer
    fgets(adminName, sizeof(adminName), stdin); // Get admin name
    adminName[strcspn(adminName, "\n")] = 0; // Remove trailing newline from input

    printf("Enter Admin Password: ");
    scanf("%s", adminPassword); // Get admin password

// Check admin credentials
    if (strcmp(adminName, "Farzeen Ali") == 0 && strcmp(adminPassword, "Techzeen") == 0) {
        printf("\n Welcome Admin %s\n", adminName); // Welcome message
        printf("Showing student records from file:\n\n");

        FILE *fp = fopen("students.txt", "r"); // Open file in read mode
        if (fp == NULL) { // Open file in read mode
            printf("Error reading file!\n");
            return;
        }

        char line[200]; // Buffer to read each line
        while (fgets(line, sizeof(line), fp)) { // Read lines from file
            printf("%s", line); // Display line
        }
        fclose(fp); // Display line

        showLine();  // Decorative line
        printf(" SEATING ARRANGEMENT OVERVIEW:\n"); // Seating map header
        showSeatingArrangement(); // Show seat layout
    } else {
        printf("Access Denied: Invalid credentials.\n"); // Access denied message
    }
}

// Function to show exam seating arrangement
void showSeatingArrangement() {
    int seat = 1; // Start seat numbering from 1
    for (int i = 0; i < ROWS; i++) { // For each row
        printf("Row %d: ", i + 1); // Display row number
        for (int j = 0; j < COLS; j++) { // For each column in the row
            if (seat <= SIZE) // If seat number is within student count
                printf("[%2d] ", seat); // Print seat number
            else
                printf("[--] "); // Empty seat placeholder
            seat++; // Move to next seat
        }
        printf("\n"); // Newline after each row
    }
}

// Function to assign a seat based on seat number
void assignSeat(int seatNumber, int *row, int *col) {
    seatNumber--; // Convert to zero-based index
    *row = seatNumber / COLS; // Calculate row index
    *col = seatNumber % COLS; // Calculate column index
}
