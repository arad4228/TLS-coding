#include <iostream>

using namespace std;

long mod(int a, int b)
{
    return (a % b + b)% b;
}

// 평문을 암호화 하는 함수
string Encrypt_Plaintext(string message, string key)
{
    // Cipher를 저장할 공간.
    string ciphertext = "";
    
    // 메시지의 길이만큼 for문을 반복하며 평문의 ASCII에 Key값을 순차적으로 더한다.
    for(int i = 0; i < message.length(); i++)
    {
        // 입력받는 문자가 대문자라고 가정하기에 ASCII에서 65만큼 빼서 소문자로 작업을 하며 이 char는 26을 넘어서 안되므로 mod를 취해준다.
        ciphertext += char(mod(int(message[i] - 65 + key[i]-65), 26)+65);
    }
    return ciphertext;
}

string Decrypt_Ciphertext(string ciphertext, string key)
{
    string plaintext = "";

    // 암호문의 길이만큼 for문을 반복하며 복호화 작업을 진행한다.
    for (int i = 0; i< ciphertext.length(); i++)
    {
        // 암호화와 동일하게 작업을 한다.
        plaintext += char(mod(int(ciphertext[i] - 65) - (key[i] - 65), 26) +65);
    }
    return plaintext;
}

int main(void)
{
    string plaintext;
    cout << "Enter the Plaintext " << endl;
    cin >> plaintext;
    string key;
    cout << "Enter the Key for this Cipher " << endl;
    cin >> key;
    // 평문을 암호화 작업을 한다.
    string ciphertext = Encrypt_Plaintext(plaintext, key);

    cout << "CipherText:" << ciphertext << endl;
    cout << "PlainText:" << Decrypt_Ciphertext(ciphertext,key) << endl;
    return 0;
}