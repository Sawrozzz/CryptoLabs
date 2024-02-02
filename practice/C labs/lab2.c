#include <stdio.h>
#include <string.h>
void encryptRailFence(char *message, int rails) {
    int len = strlen(message);
    char railMatrix[rails][len];
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            railMatrix[i][j] = ' ';
        }
    }
    int direction = 0;  
    int row = 0;
    for (int i = 0; i < len; i++) {
        railMatrix[row][i] = message[i];
        if (row == 0 || row == rails - 1) {
            direction = 1 - direction;  
        }
        row += direction ? 1 : -1;
    }
    printf("Encrypted Message: ");
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            if (railMatrix[i][j] != ' ') {
                printf("%c", railMatrix[i][j]);
            }
        }
    }
    printf("\n");
}

int main() {
    char message[100];
    int rails;
    printf("Enter the message to be encrypted: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';
    printf("Enter the number of rails: ");
    scanf("%d", &rails);
    encryptRailFence(message, rails);
    return 0;
}
