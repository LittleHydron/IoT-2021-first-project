#include <stdio.h>
#include <math.h>

#define logg(a,b) (log(b)/log(a)) /// log b base a

void first(){
    double a, b, h;
    printf("===================== First Part =====================\nEnter numbers (a, b, and h)!: ");
    scanf("%lf %lf %lf", &a, &b, &h);
    while(a <= b){
        double f;
        if (a < 5){
            f = logg(5, fabs(logg(4, fabs(logg(3, a)))));
        }else{
            if (a < 7){
                f = 1.0 / (a*a + 16);
            }else{
                f = log(a) + cos(a);
            }
        }
        printf("f(%lf) = %lf\n", a, f);
        a += h;
    }
    return;
}

void second(){
    double a, b, h, d;
    printf("===================== Second Part =====================\nEnter Numbers (a, b, h and d)!: ");
    scanf("%lf %lf %lf %lf", &a, &b, &h, &d);
    while(a <= b){
        double sum = 0.0, e = 0.0, n = 1.0;
        do{
            double denominator = 1.0;
            for (double i = 1.0; i < n+n; i += 1.0) denominator *= i; /// Evaluating (2n-1)!
            /// a^2n = (a^n)^2, So:
            double numerator = 1;
            for (double i = 1.0; i <= n; i += 1.0) numerator *= a; /// Evaluating a^n
            numerator *= numerator; /// Evaluating (a^n)^2
            numerator -= 1.0; /// Evaluating (a^n)^2-1
            e = numerator / denominator;
            sum += e;
            n += 1.0;
        }while(fabs(e) >= d);
        printf("f(%lf) = ", a);
        printf("%.4lf\n", sum);
        a += h;
    }
    return;
}

int main(){
    first();
    second();
    return 0;
}