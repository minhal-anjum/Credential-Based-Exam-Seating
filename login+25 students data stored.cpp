#include <stdio.h>
#include <string.h>

#define SIZE 25 //in case agr students barh jaen to yahin se size barhyga 

// Function declarations
void showLine();  // line main ==== show karne k liye 
void studentLogin(); // 2 select karne k bad student login par jaega USER DEFINED FUNCTIONS 
void adminLogin();  // 1 SELECT KARNE K bad Admin portal par chala jaega admin ko students ka data show karega USER DEFINED FUNCTION
void saveDataToFile(); // file handling use hurhi hai data ko store karne k liye 

char names[SIZE][20] = {  // names storing currently 25 students hain ( batool ka data rehta hai ) size uper defined hai baad main barh jaega max 20 characters hungy aik name main 
    "Omar", "Nadia", "Samir", "Hira", "Fahim",
    "Kiran", "Zeeshan", "Maya", "Kashan", "Rida",
    "Bilal", "Sana", "Arif", "Naila", "Raza",
    "Alina", "Usman", "Sarah", "Faizan", "Nashit",
    "Ayesha", "Hassan", "Imran", "Saira", "Danish"
};

char passwords[SIZE][20] = { // same scene hai but yeh password hai  
   "Omar", "Nadia", "Samir", "Hira", "Fahim",
    "Kiran", "Zeeshan", "Maya", "Kashan", "Rida",
    "Bilal", "Sana", "Arif", "Naila", "Raza",
    "Alina", "Usman", "Sarah", "Faizan", "Nashit",
    "Ayesha", "Hassan", "Imran", "Saira", "Danish"
};

int ids[SIZE] = { // max user 4 digits ka roll number input de sakhta hai 
    1026, 1027, 1028, 1029, 1030,
    1031, 1032, 1033, 1034, 1035,
    1036, 1037, 1038, 1039, 1040,
    1041, 1042, 1043, 1044, 1045,
    1046, 1047, 1048, 1049, 1050
};

int main() {
    int choice;

    saveDataToFile(); // using user defined functions file handling k liye 

    showLine(); // yahan bhi user defined function hai but sirf line ka kaam kar rha h === yeh wali
    printf("Are you Admin or Student?\n1. Admin\n2. Student\nChoice: ");
    scanf("%d", &choice);

    if (choice == 1)  // agr choice 1 hugi to admin portal par jaega otherwise 2 hugi to student portal pr 
        adminLogin();
    else
        studentLogin(); // same student login pr chala jaega

    showLine(); // no need to explain 
    return 0; // matlab seccussfully execute karega with no errors 
}

void showLine() { // user defined function hai line show k liye ===
    printf("============================\n");
}

void studentLogin() { // student login user defined 
    char name[50];
    int roll, found = 0; // found student ka data match karega shuroo main no data input to iski value 0 assume kari hai 

    printf("Enter your Name: ");
    scanf("%s", name);
    printf("Enter your Roll Number: ");
    scanf("%d", &roll);

    for (int i = 0; i < SIZE; i++) { // loop chalega 0 se lkr 24 times 
        if (strcmp(name, names[i]) == 0 && roll == ids[i]) { // strcmp do strings ko compare kara ta hai "NAME" wo data h jo user ne input dia hai or "NAMES" wo hai jo ham ne store karwaya h agr same hungi to 0 return huga login and operator use kia hai agr agy roll number match huga stored id se to condition chlegi 
            printf("Login Successful!\n");
            printf("Your Record:\n ID: %d\tName: %s\tPassword: %s\n", ids[i], names[i], passwords[i]);
            found = 1; // 1 matlab condition true hai 
            break;
        }
    }

    if (!found) // agr condition false huti hai to to yeh print karega 
        printf("Student record not found!\n");
}


void adminLogin() { // admin login hai no condition simple chlega no data stored
    char adminName[50];
    int adminID;

    printf("Enter Admin Name: ");
    scanf("%s", adminName);
    printf("Enter Admin ID: ");
    scanf("%d", &adminID);

    printf("Welcome Admin %s (ID: %d)\n", adminName, adminID);
    printf("Showing all student records from file:\n\n");

    FILE *fp = fopen("students.txt", "r"); // file handling yahan se file open hui hai pointer k through plus "r" se file read karega 
    if (fp == NULL) { //condition hai agr file null hui to error dega matlab agr data stoed nhi hua to 
        printf("Error reading file!\n");
        return; // error generate kareag a
    }

    char line[200]; 
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }

    fclose(fp); // file close kardi hai 
}


void saveDataToFile() {// file main data ko save karega user defined function hai 
    FILE *fp = fopen("students.txt", "w"); // file handling hai pointer se file ko open kia hai "w" file handling main code ko ya to write ya rewrite karne k liye use kartyt hain 
    if (fp == NULL) { // whi same scene agr null hua to error generate karega 
        printf("Error opening file for writing!\n");
        return; //error 
    }

    for (int i = 0; i < SIZE; i++) {
        fprintf(fp, "ID: %d\tName: %s\tPassword: %s\n", ids[i], names[i], passwords[i]);
    }

    fclose(fp); // file closed 
}

