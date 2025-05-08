#include <stdio.h>

int main() {
    char names[25][50] = {
        "Omar", "Nadia", "Samir", "Hira", "Fahim",
        "Kiran", "Zeeshan", "Maya", "Kashan", "Rida",
        "Bilal", "Sana", "Arif", "Naila", "Raza",
        "Alina", "Usman", "Sarah", "Faizan", "Nashit",
        "Ayesha", "Hassan", "Imran", "Saira", "Danish"
    };

    char passwords[25][50] = {
        "omar2025", "nadia_01", "samir@123", "hira_22", "fahim_pass",
        "kiran321", "zeeshan#44", "maya_2000", "kashan@2025", "rida789",
        "bilal_pass", "sana@2023", "arif_1234", "naila_88", "raza@pass",
        "alina_01", "usman@xyz", "sarah123", "faizan_456", "nashit!@#",
        "ayesha_789", "hassan22", "imran@1", "saira2025", "danish#456"
    };

    int ids[25] = {
        1026, 1027, 1028, 1029, 1030,
        1031, 1032, 1033, 1034, 1035,
        1036, 1037, 1038, 1039, 1040,
        1041, 1042, 1043, 1044, 1045,
        1046, 1047, 1048, 1049, 1050
    };

    printf("Stored Student Data:\n\n");
    for (int i = 0; i < 25; i++) {
        printf("ID: %d\tName: %s\tPassword: %s\n", ids[i], names[i], passwords[i]);
    }

    return 0;
}
