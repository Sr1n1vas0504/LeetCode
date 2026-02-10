//ch.sc.u4cse24146
int numJewelsInStones(char* jewels, char* stones) {
    bool isJewel[128] = {false};
    for (int i = 0; jewels[i] != '\0'; i++) {
        isJewel[(int)jewels[i]] = true;
    }
    int count = 0;
    for (int i = 0; stones[i] != '\0'; i++) {
        if (isJewel[(int)stones[i]]) {
            count++;
        }
    }

    return count;
}
