#include <iostream>
#include <time.h>

using namespace std;

int Powm(int base, int exp, int mod)
{
    time_t start, end;
    // 이는 r의  0승이 1인것을 착안해서 1로 설정.
    int r = 1;
    start = time(NULL);
    double tiemresult;
    for(int i = 0; i <exp; i++)
    {
        // r의 1승을 곱하고 이 값을 mod를 취해 값을 작게 유지한다.
        r *= base;
        r %= mod;
    }
    end = time(NULL);
    tiemresult = double(end - start);
    printf("계산에 걸린 소요시간은 %07f 입니다.\n",tiemresult);
    return r;
}

int main(void)
{
    // 
   
    int base = 3;
    int exp = 1000000;
    int mod = 23;
    // 3의 100승에 대한 mod 23을 취하면?
    int result  = Powm(base,exp, mod);
    
    cout << "결과 값은 " << result << "입니다. " << endl;
    return 0;
}