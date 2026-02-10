//ch.sc.u4cse24146
#include <stdbool.h>
#include <string.h>

bool checkIfPangram(char* sentence) {
    int freq[26] = {0}; 
    
    int len = strlen(sentence);
    for (int i = 0; i < len; i++) {
        char c = sentence[i];
        if (c >= 'a' && c <= 'z') {
            freq[c - 'a'] = 1;  
        }
    }
    
    for (int i = 0; i < 26; i++) {
        if (freq[i] == 0) {
            return false;  
        }
    }
    return true;  
}
