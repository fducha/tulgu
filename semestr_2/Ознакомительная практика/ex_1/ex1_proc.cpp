#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void get_middle_primes(double &middle, string &message) {
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
        message = "Среднее арифметическое простых чисел: ";
        middle = float(sum) / count;
    } else {
        message = "Простых чисел в последовательности нет.";
        middle = -1.0;
    }
}

int main() {
    double result{0.0};
    string mes{""};

    get_middle_primes(result, mes);

    if (result > 0) {
        cout << mes << result << endl;
    } else {
        cout << mes << endl;
    }

    return 0;
}
