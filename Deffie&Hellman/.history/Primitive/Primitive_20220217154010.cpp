#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool is_primitive(int base, int mod)
{
    int exp = 2;
    int r = base * mod;
    for(; r != base; exp++)
    {
        r*= base;
        r%= mod;
    }
    return exp == mod;
}

vector<int> primitive_root(int mod)
{
    vector<int> v;
    for(int base = 2; base < mod; base++)
        if(is_primitive(base, mod))
            v.push_back(base);

    return v;
}

int main(void)
{
    int mod = 29;
    vector<int> result = primitive_root(mod);
    for(int num : result)
        cout << num <<endl;
    return 0;
}