#include <stdio.h>
#include <stdlib.h>
void caesarCipherEncrypt(char *message, int key)
{
    for (int i = 0; message[i] != '\0'; ++i)
    {
        if (message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = (message[i] + key - 'A') % 26 + 'A';
        }
        else if (message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = (message[i] + key - 'a') % 26 + 'a';
        }
    }
}
void caesarCipherDecrypt(char *message, int key)
{
    caesarCipherEncrypt(message, -key);
}
int main()
{
    char message[100];
    int key;
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter the key: ");
    scanf("%d", &key);
    caesarCipherEncrypt(message, key);
    printf("Encrypted Message: %s", message);
    caesarCipherDecrypt(message, key);
    printf("Decrypted Message: %s", message);
    return 0;
}
