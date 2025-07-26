class Solution {
public:
    int nthUglyNumber(int n) {
        int i2 =1;
        int i3 = 1;
        int i5 = 1; 
        int arr[n+1];
        arr[1] = 1;

        for(int i=2;i<=n; i++){
        int i2Ugly = arr[i2]*2;
        int i3Ugly = arr[i3]*3;
        int i5Ugly = arr[i5]*5;

        int no = min({i2Ugly,i3Ugly,i5Ugly});

        arr[i] = no ;
        
        if(i2Ugly == no) i2++;
        if(i3Ugly == no) i3++;
        if(i5Ugly == no) i5++;
        }

        return arr[n];
    }
};