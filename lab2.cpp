//18 вариант: f(x) = 2x1^2 + 0.5x1x2 + 2x2^2 , x0(0;0,5) , e1 = 0.15 , e2 = 0.2 , M = 10
#include <locale>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


double f(double A, double B, double C, vector<double> x) {
    return A * x[0] * x[0] + B * x[0] * x[1] + C * x[1] * x[1];
}

vector<double> gradient(double A, double B, double C, vector<double> x) {
    return { 2 * A * x[0] + B * x[1], B * x[0] + 2 * C * x[1] };
}

int main() {
    setlocale(LC_ALL, "Rus");
    double A, B, C;
    cout << "Введите коэффициенты A, B, C: ";
    cin >> A >> B >> C;

    cout << "Заданная функция: f(x) = "
        << A << "x1^2 + " << B << "x1x2 + " << C << "x2^2\n";


    cout << "Введите начальную точку x0 = (x0, y0):\n";
    vector<double> x0(2);
    for (int i = 0; i < 2; i++) {
        cin >> x0[i];
    }

  
    cout << "Введите e1, e2 и M:\n";
    double e1, e2;
    int M;
    cin >> e1 >> e2 >> M;

    vector<double> grad = gradient(A, B, C, x0);

    double alpha;
    cout << "Введите шаг градиентного спуска: ";
    cin >> alpha;

    int k = 0;
    while (k < M) {
       
        vector<double> x1(2);
        for (int i = 0; i < 2; i++) {
            x1[i] = x0[i] - alpha * grad[i];
        }

        grad = gradient(A, B, C, x1);

        if (sqrt(grad[0] * grad[0] + grad[1] * grad[1]) < e1 &&
            sqrt((x1[0] - x0[0]) * (x1[0] - x0[0]) + (x1[1] - x0[1]) * (x1[1] - x0[1])) < e2) {
            break;
        }

        x0 = x1;
        k++;
    }
    cout << "\n\tМинимум x* = (" << x0[0] << ", " << x0[1] << ")\n";
    cout << "\tЗначение функции f(x*) в точке минимума: " << f(A, B, C, x0) << "\n";
    cout << "\tКоличество итераций: " << k << "\n";

    return 0;
}
