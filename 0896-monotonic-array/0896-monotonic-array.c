//ch.sc.u4cse24146
bool isMonotonic(int* nums, int numsSize) {
    int inc =0 ;
    int dec = 0;
    for(int i=0;i<numsSize-1;i++){
        if(nums[i]>nums[i+1]){
            inc = 1;
        }
        else if(nums[i]<nums[i+1]){
            dec = 1;
        }
    }
    if(dec && inc){
        return false;
    }
    else if(inc!=0){
        return true;
    }
    else{
        return true;
    }
}
