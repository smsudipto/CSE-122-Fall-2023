#include <bits/stdc++.h>

using namespace std;

int maxNonOverlappingTalks(vector<pair<int, int>>& talks)
{
    sort(talks.begin(), talks.end(), [](pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    });

    int count = 0;
    int last_end_time = 0;

    for (const auto& talk : talks)
    {
        if (talk.first >= last_end_time)
        {
            count++;
            last_end_time = talk.second;
        }
    }

    return count;
}

int main()
{
    int n;

    cout << "Enter the number of talks: ";
    cin >> n;

    vector<pair<int, int>> talks(n);

    cout << "Enter the start and end times of each talk:" << endl;
    for (int i = 0; i < n; ++i)
    {
        int start, end;
        cin >> start >> end;
        talks[i] = {start, end};
    }

    int result = maxNonOverlappingTalks(talks);

    cout << "Maximum non-overlapping talks: " << result << endl;

    return 0;
}
