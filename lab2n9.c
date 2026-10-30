#include <stdio.h>


int sum_def(int x, int i) {
    if (i >= x) return 0;
    if (x % i == 0) return i + sum_def(x, i + 1);

    return sum_def(x, i + 1);
}
// Recursion
void find_par(int start, int max) {
    if (start > max) return;
    
    int sm_del1 = sum_def(start, 1);
    int sm_del2 = sum_def(sm_del1, 1);

    if (sm_del1 > start && sm_del1 <= max) {
        if (sm_del2 == start) {
            printf("%d: %d and %d: %d\n", start, sm_del1, sm_del1, sm_del2);

        }
    }

    find_par(start + 1, max);
}

int main(){

    int n, m;

    printf("Введите начало диапазона чисел N(натурально и N > 0): ");
    if (scanf("%d", &n) <= 0) {
        printf("Число N должно быть натуральныи и отличным от нуля!\n");
    return 1;
    }

    printf("Введите начало диапазона чисел M(натурально и M > N): ");
    if (scanf("%d", &m) > n) {
        printf("Число M должно быть bolshe N\n");
    return 1;
    }

    //
    find_par(n, m);
    //
    
    return 0;
}

