#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

double get_middle_primes() {
    int sum{0};
    int count{0};

    int n{0};
    cin >> n;

    while (n > 0) {
        if (is_prime(n)) {
            sum += n;
            count++;
        }
        cin >> n;
    }

    if (count) {
        return float(sum) / count;
    } else {
        return -1.0;
    }
}

int main() {
    double result = get_middle_primes();

    if (result > 0) {
        cout << "Среднее арифметическое простых чисел: " << result << endl;
    } else {
        cout << "Простых чисел в последовательности нет." << endl;
    }

    return 0;
}
