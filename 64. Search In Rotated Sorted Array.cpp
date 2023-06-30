int search(int* arr, int n, int key) {
    // Write your code here.
    int left = 0;
    int right = n-1;
    int mid;
    while(left<=right){
        mid = (left + right)/2;
        if(arr[mid]==key)
        return mid;
        if(arr[left] <= arr[mid]){
            if(key>= arr[left] && key <= arr[mid]){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }else{
            if(key>= arr[mid] && key <= arr[right]){
                left = mid+1;
            } else {
              right = mid - 1;
            }
        }
    }
    
    return -1;
}