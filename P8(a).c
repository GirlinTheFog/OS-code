#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {
    char dname[10], fname[10][10];
    int fcnt;
} dir;

int main() {
    int i, ch;
    char f[30];

    printf("Enter directory name: ");
    scanf("%s", dir.dname);

    while (1) {
        printf("\n1.Create 2.Delete 3.Search 4.Display 5.Exit\nChoice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: 
                printf("Enter file name: ");
                scanf("%s", dir.fname[dir.fcnt++]);
                break;

            case 2: 
                printf("Enter file to delete: ");
                scanf("%s", f);
                for (i = 0; i < dir.fcnt; i++) {
                    if (strcmp(f, dir.fname[i]) == 0) {
                        printf("Deleted %s\n", f);
                        strcpy(dir.fname[i], dir.fname[--dir.fcnt]);
                        break;
                    }
                }
                if (i == dir.fcnt) printf("File %s not found\n", f);
                break;

            case 3: 
                printf("Enter file to search: ");
                scanf("%s", f);
                for (i = 0; i < dir.fcnt; i++)
                    if (strcmp(f, dir.fname[i]) == 0) {
                        printf("Found %s\n", f);
                        break;
                    }
                if (i == dir.fcnt) printf("File %s not found\n", f);
                break;

            case 4: 
                if (dir.fcnt == 0) 
                    printf("Directory is empty\n");
                else {
                    printf("Files: ");
                    for (i = 0; i < dir.fcnt; i++) 
                        printf("%s ", dir.fname[i]);
                    printf("\n");
                }
                break;

            case 5: 
                exit(0);

            default: 
                printf("Invalid choice\n");
        }
    }
    return 0;
}
