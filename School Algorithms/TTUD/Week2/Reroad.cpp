#include <iostream>
using namespace std;
int intialSegment(int asphalt[], int numofSegment)
{
    int cnt = 1;
    for (int i = 1; i < numofSegment; i++)
    {
        if (asphalt[i] != asphalt[i - 1])
            cnt++;
    }
    return cnt;
}
int reValue(int asphalt[], int n, int segment, int newValue, int cnt)
{
    int oldValue = asphalt[segment];
    asphalt[segment] = newValue;
    if (newValue == oldValue)
        return cnt;
    if (n == 1)
        return 1;
    if (segment == 0)
    {
        if (oldValue == asphalt[1])
        {
            return cnt + 1;
        }
        else
        {
            if (newValue != asphalt[1])
                return cnt;
            else
                return cnt - 1;
        }
    }
    if (segment == n - 1)
    {
        if (oldValue == asphalt[n - 2])
        {
            return cnt + 1;
        }
        else
        {
            if (newValue != asphalt[n - 2])
                return cnt;
            else
                return cnt - 1;
        }
    }
    if (asphalt[segment - 1] == asphalt[segment + 1])
    {
        if (oldValue == asphalt[segment - 1])
        {
            return cnt + 2;
        }
        else
        {
            if (newValue == asphalt[segment - 1])
                return cnt - 2;
            else
                return cnt;
        }
    }
    else
    {
        if (oldValue == asphalt[segment - 1])
        {
            if (newValue == asphalt[segment + 1])
                return cnt;
            else
                return cnt + 1;
        }
        else if (oldValue == asphalt[segment + 1])
        {
            if (newValue == asphalt[segment - 1])
                return cnt;
            else
                return cnt + 1;
        }
        else
        {
            if (newValue == asphalt[segment - 1] && newValue == asphalt[segment + 1])
                return cnt - 2;
            else if (newValue == asphalt[segment - 1] || newValue == asphalt[segment + 1])
                return cnt - 1;
            else
                return cnt;
        }
    }
}
int main()
{
    int numofSegment;
    cin >> numofSegment;
    int *asphalt = new int[numofSegment];
    for (int i = 0; i < numofSegment; i++)
        cin >> asphalt[i];
    int FixNum, *segment, *newValue;
    cin >> FixNum;
    segment = new int[FixNum];
    newValue = new int[FixNum];
    for (int i = 0; i < FixNum; i++)
    {
        cin >> segment[i];
        cin >> newValue[i];
    }
    int initialValue = intialSegment(asphalt, numofSegment);
    for (int i = 0; i < FixNum; i++)
    {
        initialValue = reValue(asphalt, numofSegment, segment[i]-1, newValue[i], initialValue);
        cout << initialValue << endl;
    }
    // system("pause");
}