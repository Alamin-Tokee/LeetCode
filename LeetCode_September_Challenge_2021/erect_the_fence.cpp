//TC O(nlogn)
//SC O(n)

class Solution {
public:



class Point
{
public:
        int x;
        int y;

        bool operator < (Point(&P))
        {
                if (P.x == x)
                        return y < P.y;
                else
                        return x < P.x;
        }

        bool operator == (Point(&P))
        {
                return (x == P.x and y == P.y);
        }

};

bool cw(Point a, Point b, Point c)
{
        return (((b.y - a.y) * (c.x - b.x)) - ((c.y - b.y) * (b.x - a.x))) > 0;
}
bool acw(Point a, Point b, Point c)
{
        return (((b.y - a.y) * (c.x - b.x)) - ((c.y - b.y) * (b.x - a.x))) < 0;
}
bool col(Point a, Point b, Point c)
{
        return (((b.y - a.y) * (c.x - b.x)) - ((c.y - b.y) * (b.x - a.x))) == 0;
}



void convex_hull(vector<Point> &p)
{
        if (p.size() <= 2) return;

        int n = p.size();

        sort(p.begin(), p.end());

        Point p1 = p[0], p2 = p[n - 1];

        vector <Point> up, down;
        up.push_back(p1);
        down.push_back(p1);

        for (int i = 1; i < n; i++)
        {
                /// upper half
                if (i == n - 1 or (!acw(p1, p[i], p2)))
                {
                        while (up.size() >= 2 and (acw(up[up.size() - 2], up[up.size() - 1], p[i])))
                        {
                                up.pop_back();
                        }
                        up.push_back(p[i]);
                }

                /// lower half
                if (i == n - 1 or (!cw(p1, p[i], p2)))
                {
                        while (down.size() >= 2 and (cw(down[down.size() - 2], down[down.size() - 1], p[i])))
                        {
                                down.pop_back();
                        }
                        down.push_back(p[i]);
                }
        }

        p.clear();
        for (int i = 0; i < up.size(); i++)
                p.push_back(up[i]);
        for (int i = 0; i < down.size(); i++)
                p.push_back(down[i]);

        //  deb(p.size())
        // deb2(up.size(),down.size())
        sort(p.begin(), p.end());

        p.resize(unique(p.begin(), p.end()) - p.begin());

}



    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
       
     vector<Point> p;
     for(int i=0;i<trees.size();i++)
     {
        Point temp;
        temp.x = trees[i][0];
        temp.y = trees[i][1];
        p.push_back(temp);
     }

     convex_hull(p);

     vector<vector<int> > ans;
     for(int i=0;i<p.size();i++)
     {
        ans.push_back({p[i].x, p[i].y});
     }

     return ans;

    }
};


// List hullhull grows upto size mm.

class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<vector<int>> res;
        vector<int> first = trees[0];
        int firstIdx = 0, n = trees.size();
        for (int i = 1; i < n; ++i) {
            if (trees[i][0] < first[0]) {
                first = trees[i];
                firstIdx = i;
            }
        }
        res.push_back(first);
        vector<int> cur = first;
        int curIdx = firstIdx;
        while (true) {
            vector<int> next = trees[0];
            int nextIdx = 0;
            for (int i = 1; i < n; ++i) {
                if (i == curIdx) continue;
                int cross = crossProduct(cur, trees[i], next);
                if (nextIdx == curIdx || cross > 0 || (cross == 0 && dist(trees[i], cur) > dist(next, cur))) {
                    next = trees[i];
                    nextIdx = i;
                }
            }
            for (int i = 0; i < n; ++i) {
                if (i == curIdx) continue;
                int cross = crossProduct(cur, trees[i], next);
                if (cross == 0) {
                    if (check(res, trees[i])) res.push_back(trees[i]);
                }
            }
            cur = next;
            curIdx = nextIdx;
            if (curIdx == firstIdx) break;
        }
        return res;
    }
    int crossProduct(vector<int> A, vector<int> B, vector<int> C) {
        int BAx = A[0] - B[0];
        int BAy = A[1] - B[1];
        int BCx = C[0] - B[0];
        int BCy = C[1] - B[1];
        return BAx * BCy - BAy * BCx;
    }
    int dist(vector<int> A, vector<int> B) {
        return (A[0] - B[0]) * (A[0] - B[0]) + (A[1] - B[1]) * (A[1] - B[1]);
    }
    bool check(vector<vector<int>>& res, vector<int> p) {
        for (vector<int> r : res) {
            if (r[0] == p[0] && r[1] == p[1]) return false;
        }
        return true;
    }
};