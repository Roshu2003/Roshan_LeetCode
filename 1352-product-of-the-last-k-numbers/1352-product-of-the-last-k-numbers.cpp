class ProductOfNumbers {
public:
    vector<int> nums;
    int size;
    ProductOfNumbers() {
        nums.push_back(1);
        size = 0;
    }
    
    void add(int num) {
        if(num == 0){
            nums.clear();
            nums.push_back(1);
            size = 0;
        }
        else{
            nums.push_back(nums[size]*num);
            size++;
        }
    }
    
    int getProduct(int k) {
       
       if(k > size)return 0;
        return nums[size] / nums[size - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */