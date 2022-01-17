#include <iostream>
#include <string>
using namespace std;

string Ceasar_Encoder(string message, int key)
{
    for(char &c : message) 
    c += key;
    return message;
}

string Ceasar_Decoder(string message, int key)
{
    for(char &c : message)
    c-= key;
    return message;
}

int main(void)
{
    string message = "This is for Ceaser Cipher Test";
    cout << (message = Ceasar_Encoder(message, 3)) << endl;

    cout << (message = Ceasar_Decoder(message, 3)) << endl;
    return 0;
}