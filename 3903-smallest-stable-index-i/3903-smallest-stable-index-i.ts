function firstStableIndex(nums: number[], k: number): number {
    const n = nums.length;
    for(let i = 0; i < n; i++) {
        let mx = nums[i];
        let mn = nums[i];
        for(let j = 0; j < i;j ++){
            mx = Math.max(mx,nums[j]);
        }
        for(let j = i + 1; j < n; j++){
            mn = Math.min(mn,nums[j]);
        }
        if(mx - mn <= k)return i;
    }
    return -1;
};