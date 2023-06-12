#include <stdio.h>
#include <conio.h>
#define MAX 100

int A[MAX + 1], B[MAX + 1], C[2 * (MAX + 1)], D[MAX + 1]; //C = reunion, D = intersection
int c, d; //c = elem. of reunion, d = elem. of intersection

void read(char m, int M[], int n) { // read function
    for (int i = 0; i < n; i++) {
        printf("\n%c{%d}= ", m, i);
        scanf("%d", &M[i]);
    }
}

void display_set(char m[], char m1, char m2, int V[], int n) { // display function
    printf("\n%s %c with %c: ", m, m1, m2);

    for (int i = 0; i < n; i++) {
        printf("%d, ", V[i]);
    }

    printf("\b\b ");
}

void elim_dup(int V[], int *n) { // eliminate duplicates function
    for (int i = 0; i < *n; i++) {
        for (int j = i + 1; j < *n; j++) {
            if (V[i] == V[j]) {
                do {
                    for (int k = j; k < *n; k++) {
                        V[k] = V[k + 1];
                    }

                    *n -= 1;
                } while (V[i] == V[j]);
            }
        }
    }
}

void reunion(char m1, char m2, int n, int m) { // reunion function between set m1 and m2
    int VEC[MAX + 1];

    for (int i = 0; i < m; i++) {
        VEC[i] = B[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i] == VEC[j]) {
                for (int k = j; k < (m - 1); k++) {
                    VEC[k] = VEC[k + 1];
                }

                m--;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        C[c++] = A[i];
    }

    for (int i = 0; i < m; i++) {
        C[c++] = VEC[i];
    }

    display_set("Reunion", m1, m2, C, c);
}

void intersection(char m1, char m2, int n, int m) { // intersection function between set m1 and m2
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            int ok = 0;
            if (A[i] == B[j]) {
                ok = 1;
            }

            if (ok) {
                D[d++] = A[i];
            }
        }
    }

    display_set("Intersection", m1, m2, D, d);
}

void difference(char m1, char m2, int P[], int Q[], int n, int m) { // difference function between set m1 and m2
    int ok, print = 0;

    printf("Difference between A and B: ");

    for (int i = 0; i < n; i++) {
        ok = 0;
        for (int j = 0; j < m; j++) {
            if (P[i] == Q[j]) {
                ok = 1;
            }
        }

        if (!ok) {
            printf("%d, ", P[i]);
            print = 1;
        }
    }

    if (!print) {
        printf("-");
    }

    printf("\b\b ");
}

void sym_diff(char m1, char m2, int n, int m) // symmetrical difference function
{
    int print = 0;

    reunion(m1, m2, n, m);

    printf("\n");

    intersection(m1, m2, n, m);

    printf("\n\n");

    difference(m1, m2, A, B, n, m);

    printf("\n");

    printf("\nSymmetrical difference %c with %c: ", m1, m2);

    for(int i = 0; i < c; i++) {
        int ok = 1;
        for(int j = 0; j < d; j++) {
                if (C[i] == D[j]) {
                    ok = 0;
                    break;
                }
        }

        if (ok) {
            print = 1;
            printf("%d, ", C[i]);
        }
    }

    if (!print) {
        printf("-");
    }

    printf("\b\b \n");
}

int main()
{
    int a, b;

    printf("Introduce a number of values for set A: ");
    scanf("%d", &a);

    printf("\nIntroduce a number of values for set B: ");
    scanf("%d", &b);

    read('A', A, a);
    read('B', B, b);

    elim_dup(A, &a);
    elim_dup(B, &b);

    sym_diff('A', 'B', a, b);

    return 0;
}