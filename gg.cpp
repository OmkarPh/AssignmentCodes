//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

vector<int> getServerIndex(int n, vector<int>& arrival, vector<int>& burstTime) {
    int m = arrival.size();
    vector<int> result(m, -1);

    int validPos = 0;
    vector<pair<int, int>> servers(n); // Stores server end times and indices

    for (int i = 0; i < n; i++) {
        servers[i] = {0, i};
    }

    for (int i = 0; i < m; i++) {
        while (servers[validPos].first > arrival[i]) {
            validPos = (validPos + 1) % n;
        }

        int serverIndex = servers[validPos].second;
        result[i] = serverIndex;
        servers[validPos].first = arrival[i] + burstTime[i];
        validPos = (validPos + 1) % n;
    }

    return result;
}


int main() {
    int n = 4;
    vector<int> arrival = {3, 5, 1, 6, 8};
    vector<int> burstTime = {9, 2, 10, 4, 5};

    vector<int> output = getServerIndex(n, arrival, burstTime);

    // Print the output
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }
    cout << endl;

    return 0;
}