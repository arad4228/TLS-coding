#include <stdio.h>
#include <string.h>

void Ceasar_Encoder(char* message, int key)
{
    int len = strlen(message);
    for(int i = 0; i < len ;i++)
    {
        message[i] = message[i] + key;
    }
}
void Ceasar_Decoder(char* message, int key)
{   
    int len = strlen(message);
    for(int i =0; i <len; i++)
    {
        message[i] = message[i] - key;
    }
}

int main(void)
{
    char message[] = "This is for Ceasar Cipher Test";
    Ceasar_Encoder(message,3);
    printf("%s\n", message);
    Ceasar_Decoder(message, 3);
    printf("%s\n",message);
    return 0;
}