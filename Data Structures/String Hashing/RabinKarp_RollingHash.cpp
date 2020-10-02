#include <iostream>
#include <string.h>
using namespace std;
#define LL long long int

void RabinKarp();

class RollingHash
{
private:
    LL _hash = 0;
    LL multiplier = 1;
    LL base = 256;
    LL prime = 1000000007;
    LL inverseBase = mul_inv(base, prime);
    LL baseprime = base * prime;

    // code for finding inverse moudular arithmatic
    LL mul_inv(LL a_base, LL b_prime)
    {
        LL b0 = b_prime, t, q;
        LL x0 = 0, x1 = 1;
        if (b_prime == 1)
        {
            return 1;
        }
        while (a_base > 1)
        {
            q = a_base / b_prime;
            t = b_prime, b_prime = a_base % b_prime, a_base = t;
            t = x0, x0 = x1 - q * x0, x1 = t;
        }

        if (x1 < 0)
        {
            x1 = x1 + b0;
        }

        return x1;
    }

public:
    void append(char c)
    {
        _hash = (_hash * base + c) % prime;
        cout << _hash << endl;
        multiplier = (multiplier * base) % prime;
    }

    void skip(char c)
    {
        multiplier = (multiplier * inverseBase) % prime;

        //calculating new hash value by minus the skip char
        _hash = (_hash - c * multiplier + baseprime) % prime;
    }

    LL hashValue()
    {
        return _hash;
    }
};

void RabinKarp(string sub_string, string main_string)
{
    //here index system is
    cout << "Entering rabinkarp with" << sub_string << " and " << main_string << endl;
    RollingHash rs, rm;
    for (int i = 0; i < sub_string.size(); i++)
    {
        rs.append(sub_string[i]);
        rm.append(main_string[i]);
    }

    if (rs.hashValue() == rm.hashValue() && sub_string == main_string.substr(0, sub_string.size()))
    {
        //found  a match at the first step of rolling at 0 index
        cout << "Found a matching for " << sub_string << " in " << main_string << " at "
             << "0"
             << " position ." << endl;
    }

    for (int i = sub_string.size(); i < main_string.size(); i++)
    {
        rm.skip(main_string[i - sub_string.size()]);
        rm.append(main_string[i]);
        if (rs.hashValue() == rm.hashValue() && sub_string == main_string.substr(i - sub_string.size() + 1, sub_string.size()))
        {
            //we found a match at 1 index
            cout << "Found a matching for " << sub_string << " in " << main_string << " at " << i - sub_string.size() + 1 << " position ." << endl;
        }
    }
}

int main()
{

    string main, sub;
    cin >> main >> sub;
    cout << "Main ->" << main << "  Sub ->" << sub << endl;
    RabinKarp(sub, main);
}
