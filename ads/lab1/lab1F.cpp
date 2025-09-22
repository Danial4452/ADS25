#include <iostream>
#include <vector>
using namespace std;


vector<int> prime_numbers(int n) {
    const int MAX_N = 10000; 
    vector<int> a(MAX_N, 0); 
    vector<int> primes;

    // Решето Эратосфена
    for (int i = 2; i < MAX_N && primes.size() < n; i++) {
        if (a[i] == 0) { 
            primes.push_back(i);
            for (int j = i * i; j < MAX_N; j += i) {
                a[j] = 1; 
            }
        }
    }
    return primes;
}

int main() {
    int n;
    cin >> n;
    vector<int> primes = prime_numbers(n);
    if (n > 0 && n <= primes.size()) {
        cout << primes[n - 1] << endl;
    }
    return 0;
}