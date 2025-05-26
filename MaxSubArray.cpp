#include <iostream>
#include <limits>

using namespace std;

struct SubArrayResult{
    int start; 
    int end;
    int sum;
};

SubArrayResult findMaxSubArray(int a[], int low, int mid, int high){

    int left_sum = std::numeric_limits<int>::min();
    int sum = 0;
    int max_left = -1;

    for(int i = mid; i >= low; i--){
        sum += a[i];
        if(sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = std::numeric_limits<int>::min();
    sum = 0;
    int max_right = -1;

    for(int j = mid+1; j <= high; j++){
        sum += a[j];
        if(sum > right_sum){
            right_sum = sum;
            max_right = j;
        }
    }

    SubArrayResult result;
    result.start = max_left;
    result.end = max_right;
    result.sum = left_sum + right_sum;

    return result;
}

int main(){
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5};

    SubArrayResult r = findMaxSubArray(a, 0, 3, 7);
    cout << "Entrou no main\n";

    std::cout << "Start: " << r.start << "\n";
    std::cout << "End: " << r.end << "\n";
    std::cout << "Max Sum: " << r.sum << "\n";
    
    cin.get();
}


