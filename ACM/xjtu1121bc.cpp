#include <bits/stdc++.h>
using namespace std;
typedef map<int, int> Map;
Map odd, even;
int all[40];
int add(int flag, int beg, int end, int arr[]) {
    int temp = flag;
    int sum = 0;
    for (int i = beg; i < end; i++) {
        if ((temp & 1) >= 1) {
            sum += arr[i];
            //  printf("+%d",arr[i]);
        }
        temp >>= 1;
    }
    // printf("\n");
    return sum;
}
int count_one_bits(int n) {
    int count = 0;
    while (n) {
        n = (n & (n - 1));
        count++;
    }
    return count;
}
int main() {
    int n;
    scanf("%d", &n);
    int left = n / 2;
    // int right=n-left;
    // int le[left]={0},ri[right]={0};

    memset(all, 0, sizeof(all));
    for (int i = 0; i < n; i++) {
        cin >> all[i];
    }
    int flag = 1;
    while (flag < pow(2, left)) {
        int sum = add(flag, 0, left, all);
        // printf("%dsum1=%d count=%d\n",flag,sum,count_one_bits(flag));
        (count_one_bits(flag) % 2 == 0) ? even[sum]++ : odd[sum]++;
        // printf("!!%d ",odd[1]);
        flag++;
    }
    int k = even[0];
    flag = 1;
    while (flag < pow(2, n - left)) {
        int sum = add(flag, left, n, all);
        // printf("%dsum2=%d count=%d\n",flag,sum,count_one_bits(flag));
        if (count_one_bits(flag) % 2 == 0) {
            if (sum == 0)
                k++;
            k += even[-sum];
            // printf("k=%d\n",k);
        } else {
            k += odd[-sum];
            // printf("k=%d\n",k);
        }
        flag++;
    }
    // for(int i=0;i<n;i++){
    //  cout<<all[i]<<endl;
    //}
    cout << k << endl;
    return 0;
}