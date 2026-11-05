// task 1

#include <stdio.h>
#include <math.h>
// 10 вариант
int main() {
    double m, n, res;
    printf("m и n: ");
    scanf("%lf %lf", &m, &n);
    if (n!=3 && m<=3) {
        res = (2*m) / (n-3);
    } 
    else if (m>3) {
        res = sqrt(m-3)-n;
    } 
    else {
        res = m+n;
    }
    printf("Вывод: %lf\n", res);
    return 0;
}

// task 2

#include <stdio.h>
#include <math.h>
int main() {
    double a,b;
    printf("a и b: ");
    scanf("%lf %lf", &a,&b);
    // ln(a) и корень из b существуют только при a>0 и b>0
    if (a<=0 || b<=0) {
        printf("нужно a>0 и b>0\n");
        return 0;
    }
    double part1 = (2* exp(a)) / (3*pow(b,2.5));
    double part2 = pow(cos(a/(2*b+1)),2) / (1+1/ (log(a)+b));
    printf("K = %lf\n" , part1 * part2);
    return 0;
}

// task 3

#include <stdio.h>
int main() {
    double a,b;
    printf("a и b: ");
    scanf("%lf %lf", &a, &b);
    // a положительное, знак остается
    if (a>0) {
        printf("x > %lf\n", -b/a);
    } 
    // a отрицательное, знак переворачивается
    if (a<0) {
        printf("x < %lf\n", -b/a);
    } 
    // если a=0, то x пропадает, и проверяем только b
    if (a==0) {
        if (b>0) printf("любое x\n"); // по типу 0*x+5>0, всегда верно
        else printf("нет решений\n"); // или же 0*x-3>0 неверно
    }
    return 0;
}

// task 4

#include <stdio.h>

int main() {
    int n;
    printf("n: ");
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        if (n%i==0 && i%2!=0) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}

// task 5

#include <stdio.h>
int main() {
    int n = 1;
    int fact = 1;
    // проверяем следующий факториал, пока он не станет больше 100000
    while (fact*(n+1)<= 100000){
        n++; 
        fact = fact*n;
    }
    // условие нарушается - цикл прерывается 
    printf("наибольшее число n = %d\n",n);
    return 0;
}

// task 6

#include <stdio.h>
int main() { 
    long long n, rev = 0;
    printf("N: ");
    scanf("%lld", &n);
    // запоминаем знак и дальше работаем с модулем числа
    int minus = 0;
    if (n < 0) {
        minus = 1;
        n = -n; 
    }
    // берем последнюю цифру n и дописываем ее справа к rev
    while (n > 0) {
        rev = rev * 10 + n % 10; 
        n = n / 10; 
    }
    if (minus) rev = -rev;
    printf("result: %lld\n", rev);
    return 0;
}

// task 7

#include <stdio.h>
#include <math.h>
int main() {
    double x, eps = 1e-5;
    printf("x: ");
    scanf("%lf", &x);
    double term = x;   // первый член ряда
    double sum = 0;
    int n = 0;
    // пока очередной член по модулю не меньше eps - прибавляем его к сумме
    while (fabs(term) >= eps) {
        sum += term;
        n++;
        // следующий член получаем из предыдущего, факториал заново не считаем
        term = -term * x * x / ((2*n) * (2*n + 1));
    }
    printf("сумма ряда = %lf\n", sum);
    printf("sin(x)     = %lf\n", sin(x));
    return 0;
}

// task 8

#include <stdio.h>
#include <math.h>
int main() {
    double x, eps = 1e-5;
    printf("x: ");
    scanf("%lf", &x);
    // по условию |x| > 1
    if (fabs(x) <= 1) {
        printf("нужно |x| > 1\n");
        return 0;
    }
    double pw = 1/x;     // 1/x^(2n+1)
    double term = pw;    // первый член ряда
    double sum = 0;
    int k = 1;           // знаменатель 2n+1
    // пока очередной член по модулю не меньше eps - прибавляем его к сумме
    while (fabs(term) >= eps) {
        sum += term;
        pw = pw / (x*x); // степень x в знаменателе растет на 2
        k += 2;
        term = pw / k;
    }
    sum = 2 * sum;       // двойка стоит перед скобкой
    printf("сумма ряда = %lf\n", sum);
    printf("ln((x+1)/(x-1)) = %lf\n", log((x+1)/(x-1)));
    return 0;
}

// task 9

#include <stdio.h>
int main() {
    int n;
    long long sum = 0;
    printf("n: ");
    scanf("%d", &n);
    // при n > 15 сумма уже не помещается в long long
    if (n > 15) {
        printf("слишком большое n (максимум 15)\n");
        return 0;
    }
    for (int i=1; i<=n; i++) {
        long long p = 1;
        // возводим i в степень i обычным умножением
        for (int j=1; j<=i; j++) {
            p = p * i;
        }
        sum = sum + p;
    }
    printf("S = %lld\n", sum);
    return 0;
}
