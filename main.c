#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "complex.h"


void skip_whites(char *s) {
    int i, k = 0;

    for (i = 0; s[i]; i++) {
        s[i] = s[i + k];

        if (s[i] == ' ' || s[i] == '\t') {
            k++;
            i--;
        }
    }
}

int no_extraneous_before(char buf[], char command[]) {
    char temp[MAX];
    strcpy(temp, buf);
    skip_whites(temp);
    if (strncmp(temp, command, strlen(command)) != 0) {
        return 1;
    }
    return 0;
}

int no_extraneous_after_stop(char *ret, char buf[]) {
    int i = 0;
    char temp[MAX];
    strcpy(temp, buf);
    skip_whites(temp);
    while (i != MAX && temp[strlen(temp) - 4 + i] != *ret + 4 + i) {
        if (temp[strlen(temp) - 4 + i] != '\n') {
            return 0;
        }
        i++;
    }
    return 1;
}

int no_extraneous_after_end(char buf[]) {
    char temp[MAX];
    strcpy(temp, buf);
    skip_whites(temp);
    if (temp[strlen(temp) - 1] != '\n') {
        printf("it is: %zu", strlen(temp));
        return 7;
    }
    return 1;
}

int check_Undefined_complex_var_read_comp(char buf[]) {
    double x;
    char nono[MAX];
    char yaya[MAX];
    char temp[MAX];
    strcpy(temp, buf);
    skip_whites(temp);
    if (strlen(temp) < 14) {
        if (temp[10] != ',' || temp[12] != ',') {
            return 2;
        } else {
            return 3;
        }
    }
    if (temp[9] < 'A' || temp[9] > 'F') {
        return 6;
    }
    if (strstr(temp, ",,") != NULL) {
        return 4;
    }
    if (temp[10] != ',') {
        return 1;
    }
    if (sscanf(temp, "%11s %lf %s", nono, &x, yaya) == EOF) {
        return 8;
    }
    if (yaya[0] != ',') {
        return 1;
    }
    return 0; // Return 0 for valid complex variable
}
int check_Undefined_complex_var_print_comp(char buf[]) {
    double x;
    char temp[MAX];
    strcpy(temp, buf);
    skip_whites(temp);
    if (strlen(temp) < 11) {
        return 3;
    }
    if (temp[10] < 'A' || temp[10] > 'F') {
        return 6;
    }
    if (strstr(temp, ",,") != NULL) {
        return 4;
    }
    return 0; // Return 0 for valid complex variable
}

int check_Undefined_complex_var_add_comp(char buf[]) {
    char temp[MAX];
    strcpy(temp, buf);
    skip_whites(temp);
    if (strlen(temp) < 11) {
        if (temp[9] != ',') {
            return 2;
        } else {
            return 3;
        }
    }
    if (temp[8] < 'A' || temp[8] > 'F') {
        return 6;
    }
    if (strstr(temp, ",,") != NULL) {
        return 4;
    }
    if (temp[9] != ',') {
        return 1;
    }
        if (temp[10] < 'A' || temp[10] > 'F') {
        return 6;
    }

    return 0; // Return 0 for valid complex variable
}

int check_Undefined_complex_var_mult_comp_real(char buf[]) {
    double x;
    char nono[MAX];
    char yaya[MAX];
    char temp[MAX];
    strcpy(temp, buf);
    skip_whites(temp);
    if (strlen(temp) < 17) {
        if (temp[15] != ',') {
            return 2;
        } else {
            return 3;
        }
    }
    if (temp[14] < 'A' || temp[14] > 'F') {
        return 6;
    }
    if (strstr(temp, ",,") != NULL) {
        return 4;
    }
    if (temp[15] != ',') {
        return 1;
    }
    if (sscanf(temp, "%16s %lf", nono, &x) == EOF) {
        return 8;
    }

    return 0; // Return 0 for valid complex variable
}
int check_Undefined_complex_var_mult_comp_img(char buf[]) {
    double x;
    char nono[MAX];
    char yaya[MAX];
    char temp[MAX];
    strcpy(temp, buf);
    skip_whites(temp);
    if (strlen(temp) < 16) {
        if (temp[14] != ',') {
            return 2;
        } else {
            return 3;
        }
    }
    if (temp[13] < 'A' || temp[13] > 'F') {
        return 6;
    }
    if (strstr(temp, ",,") != NULL) {
        return 4;
    }
    if (temp[14] != ',') {
        return 1;
    }
    if (sscanf(temp, "%15s %lf", nono, &x) == EOF) {
        return 8;
    }
    if (temp[15] < 'A' || temp[15] > 'F') {
        return 6;
    }
    return 0; // Return 0 for valid complex variable
}
int check_Undefined_complex_var_mult_comp_comp(char buf[]) {
    char temp[MAX];
    strcpy(temp, buf);
    skip_whites(temp);
    if (strlen(temp) < 17) {
        if (temp[15] != ',') {
            return 2;
        } else {
            return 3;
        }
    }
    if (temp[14] < 'A' || temp[14] > 'F') {
        return 6;
    }
    if (strstr(temp, ",,") != NULL) {
        return 4;
    }
    if (temp[15] != ',') {
        return 1;
    }
        if (temp[16] < 'A' || temp[16] > 'F') {
        return 6;
    }

    return 0; // Return 0 for valid complex variable
}
int check_Undefined_complex_var_abs_comp(char buf[]) {
    double x;
    char temp[MAX];
    strcpy(temp, buf);
    skip_whites(temp);
    if (strlen(temp) < 9) {
        return 3;
    }
    if (temp[8] < 'A' || temp[8] > 'F') {
        return 6;
    }
    if (strstr(temp, ",,") != NULL) {
        return 4;
    }
    return 0; // Return 0 for valid complex variable
}


Complex *complex_name(char input, Complex comp[]) {
    if (input == 'A') return &comp[0];
    if (input == 'B') return &comp[1];
    if (input == 'C') return &comp[2];
    if (input == 'D') return &comp[3];
    if (input == 'E') return &comp[4];
    else return &comp[5];
}
int main() {
    Complex comp[6];

    Complex A = {0, 0};
    Complex B = {0, 0};
    Complex C = {0, 0};
    Complex D = {0, 0};
    Complex E = {0, 0};
    Complex F = {0, 0};


    char buf[MAX];
    int i;
    double x, y;
    char comma;
    char halping[MAX];
    char temp[MAX];
    int val = MAX;

    i = 0;
    comp[0] = A;
    comp[1] = B;
    comp[2] = C;
    comp[3] = D;
    comp[4] = E;
    comp[5] = F;
    printf("Please enter something:\n");
    while (fgets(buf, MAX, stdin) != NULL) {
        if (strstr(buf, "stop") != NULL) {
            printf("Stopped the program\n");
            val = no_extraneous_before(buf, "stop");
            if (val == 0) {
                printf("Extraneous text before start of command\n");
                continue;
            }
            val = no_extraneous_after_stop(strstr(buf, "stop"), buf);
            if (val == 0) {
                printf("Extraneous text after end of command\n");
                continue;
            }
            break;
        }
        if (strstr(buf, "read_comp") != NULL) {
            val = no_extraneous_before(buf, "read_comp");
            if (val == 1) {
                printf("Extraneous text before start of command\n");
                continue;
            }
            val = check_Undefined_complex_var_read_comp(buf);
            if (val == 8) {
                printf("not a number\n");
                continue;
            }
            if (val == 2) {
                printf("Missing comma\n");
                continue;
            }
            if (val == 3) {
                printf("Missing parameter\n");
                continue;
            }
            if (val == 6) {
                printf("Undefined complex variable\n");
                continue;
            }
            if (val == 1) {
                printf("Missing comma\n");
                continue;
            }
            if (val == 4) {
                printf("Two consecutive commas\n");
                continue;
            }
            val = no_extraneous_after_end(buf);
            if (val == 7) {
                printf("Extraneous text after end of command\n");
                continue;
            }
            strcpy(temp, buf);
            skip_whites(temp);
            sscanf(temp, "%11s %lf %c %lf", halping, &x, &comma, &y);
            read_comp(complex_name(temp[9], comp), x, y);
            continue;
        }
        if (strstr(buf, "print_comp") != NULL) {
            val = no_extraneous_before(buf, "print_comp");
            if (val == 1) {
                printf("Extraneous text before start of command\n");
                continue;
            }
            val = check_Undefined_complex_var_print_comp(buf);
            if (val == 3) {
                printf("Missing parameter\n");
                continue;
            }
            if (val == 6) {
                printf("Undefined complex variable\n");
                continue;
            }
            if (val == 4) {
                printf("Two consecutive commas\n");
                continue;
            }
            val = no_extraneous_after_end(buf);
            if (val == 7) {
                printf("Extraneous text after end of command\n");
                continue;
            }
            strcpy(temp, buf);
            skip_whites(temp);
            print_comp(complex_name(temp[10], comp));
            continue;
        }
        if (strstr(buf, "add_comp") != NULL) {
            val = no_extraneous_before(buf, "add_comp");
            if (val == 1) {
                printf("Extraneous text before start of command\n");
                continue;
            }
            val = check_Undefined_complex_var_add_comp(buf);
            if (val == 2) {
                printf("Missing comma\n");
                continue;
            }
            if (val == 3) {
                printf("Missing parameter\n");
                continue;
            }
            if (val == 6) {
                printf("Undefined complex variable\n");
                continue;
            }
            if (val == 1) {
                printf("Missing comma\n");
                continue;
            }
            if (val == 4) {
                printf("Two consecutive commas\n");
                continue;
            }
            val = no_extraneous_after_end(buf);
            if (val == 7) {
                printf("Extraneous text after end of command\n");
                continue;
            }
            strcpy(temp, buf);
            skip_whites(temp);
            add_comp(complex_name(temp[8], comp), complex_name(temp[10], comp));
            continue;
        }
        if (strstr(buf, "sub_comp") != NULL) {
            val = no_extraneous_before(buf, "sub_comp");
            if (val == 1) {
                printf("Extraneous text before start of command\n");
                continue;
            }
            val = check_Undefined_complex_var_add_comp(buf);
            if (val == 2) {
                printf("Missing comma\n");
                continue;
            }
            if (val == 3) {
                printf("Missing parameter\n");
                continue;
            }
            if (val == 6) {
                printf("Undefined complex variable\n");
                continue;
            }
            if (val == 1) {
                printf("Missing comma\n");
                continue;
            }
            if (val == 4) {
                printf("Two consecutive commas\n");
                continue;
            }
            val = no_extraneous_after_end(buf);
            if (val == 7) {
                printf("Extraneous text after end of command\n");
                continue;
            }
            strcpy(temp, buf);
            skip_whites(temp);
            sub_comp(complex_name(temp[8], comp), complex_name(temp[10], comp));
            continue;
        }
        if (strstr(buf, "mult_comp_real") != NULL) {
            val = no_extraneous_before(buf, "mult_comp_real");
            if (val == 1) {
                printf("Extraneous text before start of command\n");
                return 0;
            }
            val = check_Undefined_complex_var_mult_comp_real(buf);
            if (val == 8) {
                printf("not a number\n");
                return 0;
            }
            if (val == 2) {
                printf("Missing comma\n");
                return 0;
            }
            if (val == 3) {
                printf("Missing parameter\n");
                return 0;
            }
            if (val == 6) {
                printf("Undefined complex variable\n");
                return 0;
            }
            if (val == 1) {
                printf("Missing comma\n");
                return 0;
            }
            if (val == 4) {
                printf("Two consecutive commas\n");
                return 0;
            }
            val = no_extraneous_after_end(buf);
            if (val == 7) {
                printf("Extraneous text after end of command\n");
                return 0;
            }
            strcpy(temp, buf);
            skip_whites(temp);
            sscanf(temp, "%16s %lf", halping, &x);
            mult_comp_real(complex_name(temp[14], comp), x);
            continue;
        }
        if (strstr(buf, "mult_comp_img") != NULL) {
            val = no_extraneous_before(buf, "mult_comp_img");
            if (val == 1) {
                printf("Extraneous text before start of command\n");
                continue;
            }
            val = check_Undefined_complex_var_mult_comp_img(buf);
            if (val == 8) {
                printf("not a number\n");
                continue;
            }
            if (val == 2) {
                printf("Missing comma\n");
                continue;
            }
            if (val == 3) {
                printf("Missing parameter\n");
                continue;
            }
            if (val == 6) {
                printf("Undefined complex variable\n");
                continue;
            }
            if (val == 1) {
                printf("Missing comma\n");
                continue;
            }
            if (val == 4) {
                printf("Two consecutive commas\n");
                continue;
            }
            val = no_extraneous_after_end(buf);
            if (val == 7) {
                printf("Extraneous text after end of command\n");
                continue;
            }
            strcpy(temp, buf);
            skip_whites(temp);
            sscanf(temp, "%15s %lf", halping, &x);
            mult_comp_img(complex_name(temp[13], comp), x);
            continue;
        }
        if (strstr(buf, "mult_comp_comp") != NULL) {
            val = no_extraneous_before(buf, "mult_comp_comp");
            if (val == 1) {
                printf("Extraneous text before start of command\n");
                continue;
            }
            val = check_Undefined_complex_var_mult_comp_comp(buf);
            if (val == 2) {
                printf("Missing comma\n");
                continue;
            }
            if (val == 3) {
                printf("Missing parameter\n");
                continue;
            }
            if (val == 6) {
                printf("Undefined complex variable\n");
                continue;
            }
            if (val == 1) {
                printf("Missing comma\n");
                continue;
            }
            if (val == 4) {
                printf("Two consecutive commas\n");
                continue;
            }
            val = no_extraneous_after_end(buf);
            if (val == 7) {
                printf("Extraneous text after end of command\n");
                continue;
            }
            strcpy(temp, buf);
            skip_whites(temp);
            mult_comp_comp(complex_name(temp[14], comp), complex_name(temp[16], comp));
            continue;
        }
        if (strstr(buf, "abs_comp") != NULL) {
            val = no_extraneous_before(buf, "abs_comp");
            if (val == 1) {
                printf("Extraneous text before start of command\n");
                continue;
            }
            val = check_Undefined_complex_var_abs_comp(buf);
            if (val == 3) {
                printf("Missing parameter\n");
                continue;
            }
            if (val == 6) {
                printf("Undefined complex variable\n");
                continue;
            }
            if (val == 4) {
                printf("Two consecutive commas\n");
                continue;
            }
            val = no_extraneous_after_end(buf);
            if (val == 7) {
                printf("Extraneous text after end of command\n");
                continue;
            }
            strcpy(temp, buf);
            skip_whites(temp);
            abs_comp(complex_name(temp[8], comp));
            continue;
        }
        // Additional code can be added here for other commands and functionalities

        return 0;
    }

    return 0;
}  
