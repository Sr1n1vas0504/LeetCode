//ch.sc.u4cse24146
int characterReplacement(char* s, int k) {
    int count[26] = {0};       
    int left = 0, right = 0;
    int maxCount = 0;          
    int maxLength = 0;
    while (s[right] != '\0') {
        count[s[right] - 'A']++;
        if (count[s[right] - 'A'] > maxCount)
            maxCount = count[s[right] - 'A'];
        if ((right - left + 1) - maxCount > k) {
            count[s[left] - 'A']--;
            left++;
        }
        int windowSize = right - left + 1;
        if (windowSize > maxLength)
            maxLength = windowSize;

        right++;
    }return maxLength;
}
