#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void bubble(int *arr, int n);
int* merge(int *arr, int *buff, unsigned int l, unsigned int r);
void inser(int *arr, int n);

void random_filler(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
}

void copy_arr(int *imp, int *out, int n) {
    for (int i = 0; i < n; i++) {
        out[i] = imp[i];
    }
}

int main() {
    int sizes[] = {10, 1000, 10000, 100000};
    int num_size = 4;

    printf("| ArrSize|  bubble      | insert       | sliyaniye      |\n");

    srand(time(NULL));

    for (int a = 0; a < num_size; a++) {
        int n = sizes[a];
        int *arr   = malloc(n * sizeof(int));
        int *arr_b = malloc(n * sizeof(int));
        int ((*arr_m)) = malloc(n * sizeof(int));
        int *arr_i = malloc(n * sizeof(int));

        if (!arr || !arr_b || !arr_m || !arr_i) {
            printf("Array_error\n");
            return 1;
        }

        random_filler(arr, n);
        copy_arr(arr, arr_b, n);
        copy_arr(arr, arr_m, n);
        copy_arr(arr, arr_i, n);

        double t_b, t_m, t_i;
        clock_t start, end;

        start = clock();
        bubble(arr_b, n);
        end = clock();
        t_b = (double)(end - start) / CLOCKS_PER_SEC;

        int *buff = malloc(n * sizeof(int));
        start = clock();
        merge(arr_m, buff, 0, n - 1);
        end = clock();
        t_m = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        inser(arr_i, n);
        end = clock();
        t_i = (double)(end - start) / CLOCKS_PER_SEC;

        printf("| %d     | %f     | %f     | %f     |\n", n, t_b, t_m, t_i);

        free(arr);
        free(arr_b);
        free(arr_m);
        free(buff);
        free(arr_i);
    }
    return 0;
}

int* merge(int *arr, int *buff, unsigned int l, unsigned int r) {
    if (l == r) {
        buff[l] = arr[l];
        return buff;
    }

    unsigned int middle = l + (r - l) / 2;
    int *l_buff = merge(arr, buff, l, middle);
    int *r_buff = merge(arr, buff, middle + 1, r);

    int *target = (l_buff == arr) ? buff : arr;
    unsigned int l_cur = l, r_cur = middle + 1;

    for (unsigned int i = l; i <= r; i++) {
        if (l_cur <= middle && r_cur <= r) {
            target[i] = (l_buff[l_cur] < r_buff[r_cur]) ? l_buff[l_cur++] : r_buff[r_cur++];
        } else if (l_cur <= middle) {
            target[i] = l_buff[l_cur++];
        } else {
            target[i] = r_buff[r_cur++];
        }
    }
    return target;
}

void inser(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void bubble(int *arr, int n) {
    for (int i = 1; i <= n - 1; i++) {
        int f = 0;
        for (int j = 0; j <= n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                f = 1;
            }
        }
        if (!f) break;
    }
}
