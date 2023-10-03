#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

#define BASE 31     // put 256 for all ascii values
#define Q 1000000007

void printHighlighted(string text, int highlightFromIdx, int highlightLength){
    int textLength = text.length();
    for(int i=0; i<highlightFromIdx; i++){
        printf("%c", text[i]);
    }
    // printf("\x1B[32m");
    printf("[");
    for(int i=0; i<highlightLength && i<textLength; i++){
        printf("%c", text[highlightFromIdx+i]);
    }
    printf("]");
    // printf("\033[0m");
    for(int i=highlightFromIdx+highlightLength; i<textLength; i++){
        printf("%c", text[i]);
    }
}


vector<int> search(string text, string pattern) {
    vector<int> occurences;
    int m = pattern.length();

    long patternHash = (pattern[0] - 'a' + 1);
    long power = BASE;
    for(int i=1; i<pattern.length(); i++){
        patternHash += ((pattern[i] - 'a' + 1) * (power)) % Q;
        power *= BASE;
    }

    long windowHash = (text[0] - 'a' + 1);
    power = BASE;
    for(int i=1; i<m; i++){
        windowHash += ((text[i] - 'a' + 1) * (power)) % Q;
        power *= BASE;
    }

    printf("Pattern hash: (%s)%ld, text window hash: %ld\n", pattern.c_str(), patternHash, windowHash);
    
    for(int i=0; i<=text.length()-m; i++){
        bool matches = windowHash == patternHash;
        printf("Text window: %s (%ld) (%s)\n", text.substr(i, m).c_str(), windowHash, matches ? "Matches" : "Doesn't match");

        if(matches){
            // Cross verify hash
            bool verified = true;
            for(int counter=0; counter<m; counter++){
                if(text[i+counter] != pattern[counter]){
                    printf("Collided hash, doesn't match pattern !\n");
                    verified = false;
                    break;
                }
            }
            if(verified){
                occurences.push_back(i);
            }
        }
        

        if(i==text.length()-m)    break;

        // Rolling hash for next character
        windowHash -= (text[i] - 'a' + 1);
        // if(windowHash < 0)
        //     windowHash += Q;
        windowHash /= BASE;
        // if(windowHash < 0)
        //     windowHash += Q;
        windowHash += ((text[i+m] - 'a' + 1) * (long)(pow(BASE, m-1))) % Q;
        // printf("For %s, calc rolling hash: %ld, ", text.substr(i+1, m).c_str(), windowHash);
        

        // long tempHash = (text[i+1] - 'a' + 1);
        // power = BASE;
        // for(int j=i+2; j<=i+m; j++){
        //     tempHash += ((text[j] - 'a' + 1) * (power)) % Q;
        //     power *= BASE;
        // }
        // printf("ideal rolling hash value: %ld\n", tempHash);
        // printf("\n");
    }


    printf("\n");
    for(int idx : occurences){
        printHighlighted(text, idx, m);
        printf("\n");
    }

    return occurences;
}

int main()
{
    string text, pattern;
    // printf("Enter the text: ");
    // cin >> text;
    // printf("Enter the pattern to be searched: ");
    // cin >> pattern;

    text = "i am here everyone";
    pattern = "er";
    // text = "cabacabacaba";
    // pattern = "aba";

    search(text, pattern);

    printf("\nBye !!\n");
    return 0;
}
