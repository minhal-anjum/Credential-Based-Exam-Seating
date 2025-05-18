#include <stdio.h>

int main() {
    // Custom student names (aap chahein to ye apne hisaab se change kar sakte hain)
    char names[25][50] = {
        "Adeel", "Bushra", "Khalid", "Rabia", "Waleed",
        "Neha", "Tariq", "Fariha", "Asad", "Lubna",
        "Yasir", "Mehwish", "Jaweria", "Shahzaib", "Komal",
        "Adnan", "Huda", "Zohaib", "Beenish", "Irfan",
        "Areej", "Salman", "Zunaira", "Mobeen", "Hafsa"
    };

    int ids[25];
    for (int i = 0; i < 25; i++) {
        ids[i] = 1001 + i; // IDs from 1001 to 1025
    }

    printf("Stored Student Data:\n\n");
    for (int i = 0; i < 25; i++) {
        printf("ID: %d\tName: %s\n", ids[i], names[i]);
    }

    return 0;
}