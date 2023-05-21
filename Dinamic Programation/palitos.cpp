#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
#include <math.h>
#include <limits.h>

using namespace std;
#define INF INT_MAX

bool posibleCorte[1001];
int m[1001][1001];

int corteOptimo(int indexStart, int indexEnd)
{

    int resultadoMemorizado = m[indexStart][indexEnd];
    if (resultadoMemorizado != INF)
    {
        return resultadoMemorizado;
    }

    int minSubcutCost = INF;
    for (int c = indexStart + 1; c < indexEnd; c++)
    {
        if (posibleCorte[c])
        {
            int length = indexEnd - indexStart;
            int cost = length + corteOptimo(indexStart, c) + corteOptimo(c, indexEnd);

            if (cost < minSubcutCost){
                minSubcutCost = cost;
            }
        }
    }

    if (minSubcutCost == INF)
        minSubcutCost = 0;
    m[indexStart][indexEnd] = minSubcutCost;
    return minSubcutCost;
}

int main(){
    for (;;){
        int stickLength;
        cin >> stickLength;
        if (stickLength == 0)
            break;
        for (int i = 0; i <= 1000; i++){
            posibleCorte[i] = false;
            for (int j = 0; j <= 1000; j++){
                m[i][j] = INF;
            }
        }
        int numberOfCuts;
        int cutIndex;
        cin >> numberOfCuts;
        for (int cut = 0; cut < numberOfCuts; cut++)
        {
            cin >> cutIndex;
            posibleCorte[cutIndex] = true;
        }
        int optimalCost = corteOptimo(0, stickLength);
        printf("The minimum cutting is %d.\n", optimalCost);
    }

    return 0;
}