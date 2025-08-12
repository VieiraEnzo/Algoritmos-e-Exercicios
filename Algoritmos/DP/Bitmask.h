
// Merging Subsets
//Complexity: O(n^3)

for (int mask = 0; mask < (1 << n); mask++) {
    for (int submask = mask; submask != 0; submask = (submask - 1) & mask) {
        int subset = mask ^ submask;
        // do whatever you need to do here
    }
}

