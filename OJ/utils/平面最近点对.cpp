
// closest pairs of points, O(n (log n) ^ 2)

#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
#include <cfloat>
using namespace std;

struct Point
{
    int x, y;
};


float dist(const Point& p1, const Point& p2) {
    const auto& [x1, y1] = p1; 
    const auto& [x2, y2] = p2;
    return sqrt( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) );
}

float brute_force(Point P[], int n) {
    auto mindist = FLT_MAX;
    for (int i = 0; i < n; ++i) 
        for (int j = i+1; j < n; ++j) 
            mindist = min(mindist, dist(P[i], P[j]));
    return mindist;
}

bool cmpX(const Point& p1, const Point& p2) {
    return p1.x < p2.x;
}

bool cmpY(const Point& p1, const Point& p2) {
    return p1.y < p2.y;
}

float stripClosest(Point strip[], int m, float d) {
    auto mindist = d;

    sort(strip, strip+m, cmpY);

    for (int i = 0; i < m; ++i) { 
        for (int j = i+1; j < m; ++j) { 
            if (strip[j].y - strip[i].y >= mindist) break;
            mindist = min(mindist, dist(strip[i], strip[j]));
        }
    }
    return mindist;
}


float _closest(Point P[], int n) {
    if (n <= 3) return brute_force(P, n);

    int mid = n / 2; auto midPoint = P[mid];
    auto dl = _closest(P, mid);
    auto dr = _closest(P+mid, n-mid);
    auto d = min(dl, dr);

    Point* strip = new Point[n];
    int m = 0;
    for (int i = 0; i < n; ++i) { 
        if ( abs(P[i].x - midPoint.x) < d ) {
            strip[m] = P[i]; ++m;
        }
    }
    return stripClosest(strip, m, d);
}

float closest(Point P[], int n) {
    sort(P, P+n, cmpX);
    return _closest(P, n);
}

int main(int argc, char const *argv[])
{
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};  
    int n = sizeof(P) / sizeof(P[0]);  
    cout << "The smallest distance is " << closest(P, n);  
    return 0;
}
