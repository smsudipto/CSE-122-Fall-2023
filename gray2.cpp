
#include <bits/stdc++.h>

using namespace std;

struct Package
{
    int reach;
    int cost;
    double reachPerCost;
};

bool compareByRatio(Package a, Package b)
{
    return a.reachPerCost > b.reachPerCost;
}

double maxReach(vector<pair<int, int>>& packages, int W)
 {
    vector<Package> packageList;

    for (const auto& p : packages)
        {
        packageList.push_back({p.first, p.second, (double)p.first / p.second});
    }

    sort(packageList.begin(), packageList.end(), compareByRatio);

    double totalReach = 0.0;
    int currentBudget = W;

    for (const auto& pkg : packageList)
        {
        if (currentBudget >= pkg.cost)
        {
            totalReach += pkg.reach;
            currentBudget -= pkg.cost;
        }
        else
        {
            totalReach += pkg.reachPerCost * currentBudget;
            break;
        }
    }

    return totalReach;
}

int main()
{
    int n;
    cout << "Enter the number of packages: ";
    cin >> n;

    vector<pair<int, int>> packages(n);

    cout << "Enter the reach and cost for each package:" << endl;
    for (int i = 0; i < n; ++i)
        {
        int reach, cost;
        cin >> reach >> cost;
        packages[i] = {reach, cost};
    }

    int W;
    cout << "Enter the available budget: ";
    cin >> W;

    double result = maxReach(packages, W);

    cout << "Maximum Reach: " << result << " people" << endl;

    return 0;
}


