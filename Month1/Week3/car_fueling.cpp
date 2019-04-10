/*
Ivaylo Kirov
-- April 10, 2019 --
UC San Diego - Data Structures And Algorithms
Fibonacci Last Digit
*/

#include <iostream>
#include <vector>
#include <numeric>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    //std::sort(std::begin(stops), std::end(stops));
    // write your code here
    if (tank >= dist) return 0;
    
    int current_location = 0;
    int num_stops = 0;
    int i  = 0;
    int j = stops.size();
    
    while (current_location + tank < dist) {
        // get furthest reachable from stops
        while (stops[i] <= tank + current_location && j - i > 0) {
            ++i;
        }
        
        // i - 1 now represents where the car can go
        current_location = stops[i-1];
        //cout << "Current stop: " << stops[i-1] << '\n';
        ++num_stops;
        
        // we can reach the destination
        if (current_location + tank >= dist) {
            return num_stops;
        }
        
        
        // if you can't reach the next gas station, return -1
        if (j - i > 0 && current_location + tank < stops[i]) {
            return -1;
        }
        
        if (i == j && current_location + tank < dist) {
            return -1;
        }
        
        
        // if nothing can be reached
        // OR we are at the end and adding that value is still insufficient
        // return -1
        // if (j - i <= 1 && (current_location + tank < dist || current_location + stops[i] < dist)) return -1;
    }
    
    return num_stops;
}

int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;
    
    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);
    
    cout << compute_min_refills(d, m, stops) << "\n";
    /*vector<int> stops (299);
     std::iota(stops.begin(), stops.end(), 0);
     stops.push_back(10000);
     cout << compute_min_refills(100000, 1, stops) << "\n";*/
    cin.get();
    return 0;
}
