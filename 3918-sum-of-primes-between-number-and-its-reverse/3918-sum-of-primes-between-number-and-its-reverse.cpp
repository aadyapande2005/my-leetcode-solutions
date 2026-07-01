class Solution {
public:
    int rev(int num)
    {
        string temp = to_string(num);
        reverse(temp.begin(), temp.end());

        return stoi(temp);
    }
    int sumOfPrimesInRange(int n) {
        int rn = rev(n);
        int lim = max(n, rn);
        int st = min(n, rn);

        vector<bool> sieve(lim+1);

        sieve[0] = true;
        sieve[1] = true;

        for(int i=2; i<=sqrt(lim); i++)
        {
            // int cnt = 0;
            // for(int k=1; k<=lim; k++) 
            //     if(sieve[k] == true) cnt++;

            // cout<<i-1<<" "<<cnt<<endl;

            if(sieve[i] == true) continue;
            for(int j=2; i*j<=lim; j++)
            {
                sieve[i*j] = true;
            }
        }

        int ans = 0;
        for(int i=st; i<=lim; i++)
            if(sieve[i] == false) ans += i;

        // for(int i=0; i<=lim; i++) cout<<i<<" "<<sieve[i]<<endl;

        return ans;
    }
};