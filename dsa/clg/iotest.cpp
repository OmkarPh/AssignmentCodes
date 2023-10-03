#include <iostream>
#include <string>
#include <regex>

using namespace std;

regex prime_regexp("/^1?$|^(11+?)\1+$/");
bool isPrime(int n)
{
    return std::regex_match(string(n, '1'), prime_regexp);
}

int main()
{
    for (int number = 1; number <= 100; ++number)
    {
        if (isPrime(number))
            cout << number << " is prime." << endl;
        // else
        //     cout << number << " is not prime." << endl;
    }

    cout<<"Bye"<<endl;
    return 0;
}
