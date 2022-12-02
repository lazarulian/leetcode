#include <iostream>
#include <string>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;


double distanceBetweenTwoPoints(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

bool checkTriangle(int x1, int y1, int x2,
                   int y2, int x3, int y3)
{
    int ab = abs(distanceBetweenTwoPoints(x1, y1, x2, y2));
    int bc = abs(distanceBetweenTwoPoints(x2, y2, x3, y3));
    int ac = abs(distanceBetweenTwoPoints(x1, y1, x3, y3));


    if ((ab+bc) < ac) return false;
    if ((bc+ac) < ab) return false;
    if ((ab+ac) < bc) return false;

    return true;
}

double area(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}


bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{  
   /* Calculate area of triangle ABC */
   double A = area (x1, y1, x2, y2, x3, y3);
  
   /* Calculate area of triangle PBC */ 
   double A1 = area (x, y, x2, y2, x3, y3);
  
   /* Calculate area of triangle PAC */ 
   double A2 = area (x1, y1, x, y, x3, y3);
  
   /* Calculate area of triangle PAB */  
   double A3 = area (x1, y1, x2, y2, x, y);
    
   /* Check if sum of A1, A2 and A3 is same as A */
   return (A == A1 + A2 + A3);
}


int doesBelong(int x1, int y1, int x2, int y2, int x3, int y3, int xp, int yp, int xq, int yq)
{

    bool degenerate = checkTriangle(x1, y1, x2, y2, x3, y3);
    bool pInside = isInside(x1, y1, x2, y2, x3, y3, xp, yp);
    bool qInside = isInside(x1, y1, x2, y2, x3, y3, xq, yq);

    if (degenerate == false) return 0;
    else if (pInside == true && qInside == false) return 1;
    else if (pInside == false && qInside == true) return 2;
    else if (pInside == true && qInside == true) return 3;
    else if (pInside == false && qInside == false) return 4;

}





int main()
{
    int val = doesBelong(2, 2, 7, 2, 5, 4, 4, 3, 7, 4);
    cout << "Answer: " << val << endl;
    cout << "Correct: " << 1 << endl;
}