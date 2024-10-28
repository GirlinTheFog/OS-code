#include <stdio.h>

struct {
    char dname[10];
    char sdname[10][10];
    char fname[10][10][10];
    int ds, sds[10];
} dir[10];

int main() {
    int n, i, j, k;
    
    printf("Enter number of users: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter user directory %d name: ", i + 1);
        scanf("%s", dir[i].dname);
        printf("Enter number of subdirectories: ");
        scanf("%d", &dir[i].ds);

        for (j = 0; j < dir[i].ds; j++) {
            printf("Enter subdirectory name and size: ");
            scanf("%s %d", dir[i].sdname[j], &dir[i].sds[j]);
            for (k = 0; k < dir[i].sds[j]; k++) {
                printf("Enter file name: ");
                scanf("%s", dir[i].fname[j][k]);
            }
        }
    }

    // Displaying the directory structure
    printf("\nDirectory Structure:\n");
    printf("dirname\t\tsize\tsubdirname\tsize\tfiles\n");
    for (i = 0; i < n; i++) {
        printf("%s\t\t%d", dir[i].dname, dir[i].ds);
        for (j = 0; j < dir[i].ds; j++) {
            printf("\t%s\t\t%d\t", dir[i].sdname[j], dir[i].sds[j]);
            for (k = 0; k < dir[i].sds[j]; k++) {
                printf("%s\t", dir[i].fname[j][k]);
            }
            printf("\n\t\t");
        }
        printf("\n");
    }
    return 0;
}
