#include <stdio.h>
#include <string.h>

#define d 256
#define q 31 

void printHighlighted(char text[], int textLength, int idx, int matchLength){
    for(int i=0; i<idx; i++){
        printf("%c", text[i]);
    }
    printf("[");
    for(int i=0; i<matchLength; i++){
        printf("%c", text[idx+i]);
    }
    printf("]");
    for(int i=idx+matchLength; i<textLength; i++){
        printf("%c", text[i]);
    }
}
void search(char pattern[], char text[], int prime)
{
    int m = strlen(pattern);
    int n = strlen(text);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }
    for (i = 0; i <= n - m; i++) {
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m){
                printf("Pattern found at idx %d - ", i);
                printHighlighted(text, n, i, m);
                printf("\n");
            }
        }

        // Rolling hash
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t += q;
        }
    }
}

int main()
{
    char pattern[100], text[100];

    printf("Enter the text: ");
    fgets(text, 100, stdin);
    printf("Enter the pattern to be searched: ");
    fgets(pattern, 100, stdin);

    pattern[strcspn(pattern, "\n")] = '\0';
    text[strcspn(text, "\n")] = '\0';

    search(pattern, text, q);

    return 0;
}
