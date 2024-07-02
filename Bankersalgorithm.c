#include<stdio.h>
#include<stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int m, n, safeseq[MAX_PROCESSES], avail[MAX_RESOURCES], max[MAX_PROCESSES][MAX_RESOURCES], alloc[MAX_PROCESSES][MAX_RESOURCES], need[MAX_PROCESSES][MAX_RESOURCES], finish[MAX_PROCESSES];

void calneed() {
    int i, j;
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    printf("The need matrix is:");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",need[i][j]);
        }
        printf("\n");
    }
}

bool safe() {
    int work[MAX_RESOURCES];
    int i, j;
    for(i = 0; i < n; i++) {
        work[i] = avail[i];
    }
    for(j = 0; j < m; j++) {
        finish[j] = false;
    }
    int count = 0;
    while(count < m) 
    { 
        bool found = false;
        for(i = 0; i < m; i++)
        {
            if(!finish[i]) 
            {
                bool can_allocate = true; 
                for(j = 0; j < n; j++) 
                {
                    if(need[i][j] > work[j]) 
                    {
                        can_allocate = false; 
                        break;
                    }
                }
                if(can_allocate) { 
                    for(int k = 0; k < n; k++)
                    {
                        work[k] += alloc[i][k];
                    }
                    finish[i] = true;
                    safeseq[count++] = i;
                    found = true;
                }
            }
        }
        if(!found) {
            return false;
        }
    }
    return true;
}

int main() {
    int i, j;
    printf("Enter the number of processes:");
    scanf("%d", &m);
    printf("Enter the number of resources:");
    scanf("%d", &n);
    printf("Enter the allocation matrix for %d process and %d resources\n", m, n);
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("Enter the maximum matrix for %d process and %d resources\n", m, n); 
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the available resources:");
    for(i = 0; i < n; i++) {
        scanf("%d", &avail[i]);
    }
    calneed();
    if(safe()) {
        printf("\nSafe\n");
        for(i = 0; i < m; i++) {
            printf("%d->", safeseq[i]);
        }
        printf("\n");
    }
    else {
        printf("\nUnsafe\n");
    }
    return 0;
}
