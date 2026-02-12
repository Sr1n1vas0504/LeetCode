bool isPalindrome(int x) {
   if(x < 0) return false;
    if(x % 10 == 0 && x != 0) return false;
    int rec = 0;
    while(x>rec){
        rec = rec*10 + x%10;
        x = x/10;
    }
    return (rec==x || x==(rec/10));
}