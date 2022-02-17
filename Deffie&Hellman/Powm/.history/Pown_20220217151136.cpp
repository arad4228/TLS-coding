#include <iostream>
#include <time.h>

using namespace std;

int Powm(int base, int exp, int mod)
{
    // 이는 r의  0승이 1인것을 착안해서 1로 설정.
    int r = 1;

    for(int i = 0; i <exp; i++)
    {
        // r의 1승을 곱하고 이 값을 mod를 취해 값을 작게 유지한다.
        r *= base;
        r %= mod;
    }
    return r;
}

int main(void)
{
    // 
    time_t start, end;
    int base = 3;
    int exp = 100;
    int mod = 23;
    double tiemresult;
    // 3의 100승에 대한 mod 23을 취하면?
    start = time(NULL);
    int result  = Powm(base,exp, mod);
    end = time(NULL);
    tiemresult = double(end - start);
    cout << "결과 값은 " << result << "입니다. " << endl;
    printf("계산에 걸린 소요시간은 %d 입니다.\n",tiemresult);
    return 0;
}