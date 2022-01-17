#include <iostream>
#include <string>
#include<unordered_map>
using namespace std;

unordered_map<char,char> hashMap;

string Mono_Encrypt(string msg)
{
  string ciphertext;
  for(int i=0; i<msg.size(); i++)
  {
    ciphertext.push_back(hashMap[msg[i]]);
  }
  
  return ciphertext;
}

string Mono_Decrypt(string msg)
{
  string plaintext;
  for(int i=0; i<msg.size(); i++)
  {
    plaintext.push_back(hashMap[msg[i]]);
  }
  
  return plaintext;
}

void hashFn(string a, string b)
{
  // hash map을 먼저 비운다.
  hashMap.clear();
  // 문자열 a의 사이즈만큼 hash에 a와 b의 쌍을 집어 넣는다.
  for(int i=0; i<a.size(); i++)
  {
    hashMap.insert(make_pair(a[i],b[i]));
  }
}

int main() 
{
    // 알파벳에 해당하는 문자열
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    // 각 알파벳에 해당하는 암호문 알파벳
    string substitution = "qwertyuiopasdfghjklzxcvbnm";
    // 메시지에 해당하는 문자열
    string msg = "absdhj";
    
    // hash에 알파벳과 대응하는 암호문 알파벳을 넣는다.
    hashFn(alphabet, substitution);
    
    // 암호문은 Mono_Enc의 결과 값이다.
    string cipher = Mono_Encrypt(msg);
    cout<<"Encrypted Cipher Text: "<<cipher<<endl;
    
    // hash에 대응하는 암호문과 알파벳을 집어넣는다.
    hashFn(substitution, alphabet);
    // 암호문에 해당하는 평문은 Dec의 결과 값이 나온다ㅣ.
    string plain = Mono_Decrypt(cipher);
    cout<<"Decrypted Plain Text: "<<plain<<endl;
    
    return 0;
}