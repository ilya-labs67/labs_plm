#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int is_natural_string(const char *str) {
    if (str[0] == '\0' || str[0] == '0' || str[0] == '-') {
	return 0;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int is_integer_string(const char *str) {
    int start = 0;
    if (str[0] == '-' || str[0] == '+') {
    	start += 1;
    }

    if (str[start] == '\0') {
	return 0;
    }

    for (int i = start; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int is_float_string(const char *str) {
    int start = 0;
    if (str[0] == '-' || str[0] == '+') {
    	start += 1;
    }
    
    if (str[start] == '\0') {
	return 0;
    }
    
    int dot_count = 0;
    int digit_count = 0;
    
    for (int i = start; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            dot_count++;
            if (dot_count > 1) {
                return 0;
            }
        } 
        else if (str[i] >= '0' && str[i] <= '9') {
            digit_count++;
        } 
        else {
            return 0;
        }
    }

    if (digit_count == 0) {
        return 0;
    }

    return 1;
}


int main() {
    char *N_str = NULL;
    char *M_str = NULL;
    int M, N;

    while (1) {
        printf("Введите N: ");
        if (scanf("%ms", &N_str) != 1) {
            printf("Ошибка чтения.\n");
            free(N_str);
	    continue;
        }
        if (is_natural_string(N_str)) {
    	    N = atoi(N_str);
	    free(N_str);
	    break;
        } else {
	    free(N_str); 
	    printf("Чичло должно быть натуральным!\n");
        }
    }

    while (1) {
        printf("Введите M: ");
        if (scanf("%ms", &M_str) != 1) {
            printf("Ошибка чтения.\n");
            free(M_str); 
            continue;
        }
        if (is_natural_string(M_str)) {
            M = atoi(M_str);
	    free(M_str);
            break;
        } else {
	    printf("Чичло должно быть натуральным!\n");
	    free(M_str); 
	}
    }
    //Proverka
    if (N < 2) {
        printf("Ошибка: для 16 задания матрица должна иметь хотя бы 2 строки\n");
        return 1;
    }
    if (M < 4) {
        printf("Ошибка: для 16 задания матрица должна иметь хотя бы 4 столбцa\n");
        return 1;
    }
    //Proverka

    
    float *Matrix = malloc(M * N * sizeof(*Matrix));
    
    for (int i = 0; i < N; i++) {
    	 for (int j = 0; j < M; j++) {
   	     char *element = NULL;
   	     float value;
   	     
   	     while (1) {
        	 printf("Введите элемент [%i][%i]: ", i, j);
        	 if (scanf("%ms", &element) != 1) {
            	     printf("Ошибка чтения.\n");
            	     free(element);
	    	     continue;
        	 }
        	 if (is_float_string(element)) {
    	    	     value = atof(element);
	    	     free(element);
	    	     break;
        	 } else {
	    	     free(element); 
	    	     printf("Некорректный ввод!\n");
        	 }
	    }
   	    Matrix[i*M + j] = value;
   	}
    }
   
    for (int i = 0; i < N; i++) {
    	 for (int j = 0; j < M; j++) {
   	     printf("| %f |", Matrix[i*M + j]);
     	 }
     	 printf("\n");
    }

    //max 4 col
    int col4 = 3; 
    float max_col4 = Matrix[0*M + col4];
    int max_col4_i = 0;

    for (int i = 1; i < N; i++) {
        if (Matrix[i*M + col4] > max_col4) {
            max_col4 = Matrix[i*M + col4];
            max_col4_i = i;
        }
    }
    printf("max 4 col: %f (row %i numeraziya s 0)\n", max_col4, max_col4_i);
    //max 4 col

    //sum S
    int row2 = 1;
    float S = 10;

    for (int j = 0; j < M; j++) {
        float a_2j = Matrix[row2*M + j];
        S += expf(1 - a_2j); 
    }
    printf("sum S for row 2: %f\n", S);

    Matrix[max_col4_i*M + col4] = S;
    printf("elemen in row %i, 4 col replacment: %f\n", max_col4_i, S);
    //sum S

    // zamena
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("| %f |", Matrix[i*M + j]);
        }
        printf("\n");
    }
    //zamena

    return 0;
}
