class Solution {
public:
    long long snowball(int N, int weights[]) {
        /**
         * Calculates the total weight of the mega-snowball.
         *
         * @param N The number of snowballs.
         * @param weights An array of integers with the weight of each snowball.
         * @return The sum of all weights.
         */
        long long total_weight = 0; // Use 'long long' to be safe from overflow

        for (int i = 0; i < N; ++i) {
            total_weight += weights[i];
        }

        return total_weight;
    }
};