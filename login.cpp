#include <stdio.h>
#include<stdio.h>

void sq();

int main() {
    int roll, admin;
    char name[50];
    sq();

    printf("Are you admin???\n");
    printf("Yes = 1\n");
    printf("No  = 2\n");
    scanf("%d", &admin);

    if(admin == 2) {
        printf("Enter your Name: ");
        scanf("%s", name);
        printf("Enter your Roll number: ");
        scanf("%d", &roll);
        printf("Hello Mr. %s\n", name);
        // TIP : isko JUST iska seating arrangement show huga 
    } else {
        char adminname[50];
        int adminid;
        printf("Enter your Name: ");
        scanf("%s", adminname);
        printf("Enter your Identification Number: ");
        scanf("%d", &adminid);
        printf("Welcome Admin %s (ID: %d)\n", adminname, adminid);
        // TIP : isko pura show huga 50 bachun ka arrange ment
    }

    sq();
    return 0;
}

void sq() {
    printf("=========================\n");
}
