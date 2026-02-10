//ch.sc.u4cse24146
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int numRescueBoats(int* people, int peopleSize, int limit) {
    qsort(people, peopleSize, sizeof(int), compare);
    int i = 0, j = peopleSize - 1;
    int boats = 0;

    while (i <= j) {
        if (people[i] + people[j] <= limit) {
            i++;  
        }
        j--;      
        boats++; 
    }

    return boats;
}
