class Solution {
public:
    long long gcd(long long a, long long b)
    {
        while (b)
        {
            long long temp = a % b;
            a = b;
            b = temp;
        }

        return a;
    }

    long long lcm(long long a, long long b)
    {
        long long g = gcd(a, b);

        // Overflow se bachne ke liye
        if (a > LLONG_MAX / (b / g))
            return LLONG_MAX;

        return a / g * b;
    }

    long long countNumbers(long long x, vector<int>& coins)
    {
        int n = coins.size();
        long long ans = 0;

        // Inclusion-Exclusion
        for (int mask = 1; mask < (1 << n); mask++)
        {
            long long L = 1;
            int bits = 0;
            bool overflow = false;

            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                {
                    bits++;

                    L = lcm(L, coins[i]);

                    if (L > x)
                    {
                        overflow = true;
                        break;
                    }
                }
            }

            if (overflow)
                continue;

            long long current = x / L;

            if (bits % 2 == 1)
                ans += current;
            else
                ans -= current;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, long long k)
    {
        long long low = 1;

        long long high =
            1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (low < high)
        {
            long long mid = low + (high - low) / 2;

            if (countNumbers(mid, coins) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};