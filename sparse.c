#include<stdio.h>
#define MAX 100

int main() {
    int m, n;
    int A[10][10], B[10][10];
    int sp1[MAX][3], sp2[MAX][3], result[MAX][3], tr[MAX][3];
    int i, j;
    int k = 1, p = 1, r = 1, t = 1;

    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter Matrix A:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            if (A[i][j] != 0) {
                sp1[k][0] = i;
                sp1[k][1] = j;
                sp1[k][2] = A[i][j];
                k++;
            }
        }
    }
    sp1[0][0] = m;
    sp1[0][1] = n;
    sp1[0][2] = k - 1;

    printf(" Enter Matrix B:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            if (B[i][j] != 0) {
                sp2[p][0] = i;
                sp2[p][1] = j;
                sp2[p][2] = B[i][j];
                p++;
            }
        }
    }
    sp2[0][0] = m;
    sp2[0][1] = n;
    sp2[0][2] = p - 1;
    printf("Tuple representation of Matrix A\n");
     for(i = 0; i < k; i++) {
        printf("%3d %3d %5d\n", sp1[i][0], sp1[i][1], sp1[i][2]);
    }

    printf("Tuple representation of Matrix B\n");
     for(i = 0; i < p; i++) {
        printf("%3d %3d %5d\n", sp2[i][0], sp2[i][1], sp2[i][2]);
    }



    int i1 = 1, j1 = 1;
    while(i1 <= sp1[0][2] && j1 <= sp2[0][2]) {
        if(sp1[i1][0] == sp2[j1][0] && sp1[i1][1] == sp2[j1][1]) {
            result[r][0] = sp1[i1][0];
            result[r][1] = sp1[i1][1];
            result[r][2] = sp1[i1][2] + sp2[j1][2];
            i1++;
            j1++;
            r++;
        } else if(sp1[i1][0] < sp2[j1][0] || 
                  (sp1[i1][0] == sp2[j1][0] && sp1[i1][1] < sp2[j1][1])) {
            result[r][0] = sp1[i1][0];
            result[r][1] = sp1[i1][1];
            result[r][2] = sp1[i1][2];
            i1++;
            r++;
        } else {
            result[r][0] = sp2[j1][0];
            result[r][1] = sp2[j1][1];
            result[r][2] = sp2[j1][2];
            j1++;
            r++;
        }
    }

    while(i1 <= sp1[0][2]) {
        result[r][0] = sp1[i1][0];
        result[r][1] = sp1[i1][1];
        result[r][2] = sp1[i1][2];
        i1++;
        r++;
    }

    while(j1 <= sp2[0][2]) {
        result[r][0] = sp2[j1][0];
        result[r][1] = sp2[j1][1];
        result[r][2] = sp2[j1][2];
        j1++;
        r++;
    }

    result[0][0] = m;
    result[0][1] = n;
    result[0][2] = r - 1;

    printf("\nSum of matrix A and B in tuple format:\n");
    for(i = 0; i < r; i++) {
        printf("%3d %3d %5d\n", result[i][0], result[i][1], result[i][2]);
    }

    // Transpose
    tr[0][0] = result[0][1];
    tr[0][1] = result[0][0];
    tr[0][2] = result[0][2];
    
    for(j = 0; j < n; j++) {
        for(i = 1; i < r; i++) {
            if(result[i][1] == j) {
                tr[t][0] = result[i][1];
                tr[t][1] = result[i][0];
                tr[t][2] = result[i][2];
                t++;
            }
        }
    }

    printf("\nTranspose of the sum matrix tuple format:\n");
    for(i = 0; i < t; i++) {
        printf("%3d %3d %5d\n", tr[i][0], tr[i][1], tr[i][2]);
    }

    return 0;
}
