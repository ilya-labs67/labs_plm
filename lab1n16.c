#include <stdio.h>
#include <math.h>

int main() {
    float hx = 0.2, ha = 1.0;
    float x0 = 0.1, x1 = 0.3;
    float a0 = 2.0, a1 = 4.0;

    for (float xn = x0; xn <= x1; xn += hx) {
        for (float an = a0; an <= a1; an += ha) {

            float z1 = sqrt(sin(an / xn));
            float z2 = sin(an) / xn;
            float z3 = cbrt(an) * asin(xn);

            float min_val = pow(2, 50);  // большое число для проверки *

            if (z1 < min_val) {
                min_val = z1;
            }
            if (z2 < min_val) {
                min_val = z2;
            }
            if (z3 < min_val) {
                min_val = z3;
            }

            printf("xn=%f, an=%f", xn, an);

            printf(", z1=%f, z2=%f, z3=%f, minZ=%f\n", z1, z2, z3, min_val);
        }
    }

    return 0;
}
