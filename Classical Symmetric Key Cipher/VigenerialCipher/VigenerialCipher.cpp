#include <iostream>
#include <string>
using namespace std;

class Vigenerial {
   public:
      string k;
      // 클래스의 생성자
   Vigenerial(string k) {
      // key의 사이즈 만큼 동작을 진행한다.
      for (int i = 0; i < k.size(); ++i) 
      // 만약 입력받은 값의 i번째의 값이 A~Z의 사이의 값이라면 내부의 k에 값을 넣는다.
      {
         if (k[i] >= 'A' && k[i] <= 'Z')
            this->k += k[i];
         // 그렇지 않으면 A-a의 값을 빼서 넣는다.
         else if (k[i] >= 'a' && k[i] <= 'z')
            this->k += k[i] + 'A' - 'a';
      }
   }
   // Enc를 위한 코드
   string Vigenerial_Encryption(string t) {
      // 결과로 나올 암호문을 위한 공간
      string output;
      // 변환을 위한 과정이다.
      for (int i = 0, j = 0; i < t.length(); ++i) 
      {
         // i번째 문자의 값을 c에 넣는다.
         char c = t[i];
         // 그 값이 a~z의 사이라면 c에 A-a즉 31의 값을 더한다.
         if (c >= 'a' && c <= 'z')
            c += 'A' - 'a';
         // 만약 A~Z라면 그대로 진행한다.
         else if (c < 'A' || c > 'Z')
            continue;
         // 결과 값의 식으로 대문자로 나오니 이를 위한 방법이다.
         //added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
         output += (c + k[j] - 2 * 'A') % 26 + 'A'; 
         j = (j + 1) % k.length();
      }
      return output;
   }
   // Dec를 위한 코드
   string Vigenerial_Decryption(string t) {
      string output;
      // 변환을 위한 과정
      for (int i = 0, j = 0; i < t.length(); ++i) 
      {
         char c = t[i];
         if (c >= 'a' && c <= 'z')
            c += 'A' - 'a';
         else if (c < 'A' || c > 'Z')
            continue;
         // 암호화된 식을 복호화 하기 위한 방법이며 결과를 대문자로 출력하기에 이렇한 변환을 거친다.
         //added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
         output += (c - k[j] + 26) % 26 + 'A';
         j = (j + 1) % k.length();
      }
      return output;
   }
};

int main() {
   // Key에 해당하는 값으로 클래스의 내부에 저장해서 사용한다.
   // key의 값은 임의로 변경이 가능하다.
   Vigenerial vi("WELCOME");
   // 평문
   string ori ="Thisistutorialspoint";
   // 평문에 대해 key로 암호화를 진행한다.
   string encrypt = vi.Vigenerial_Encryption(ori);
   // 암호문에 대해 복호화를 진행하여 평문을 얻어낸다.
   string decrypt = vi.Vigenerial_Decryption(encrypt);
   // 값을 출력.
   cout << "Original Message: "<<ori<< endl;
   cout << "Encrypted Message: " << encrypt << endl;
   cout << "Decrypted Message: " << decrypt << endl;
}