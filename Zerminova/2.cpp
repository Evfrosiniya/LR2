#include <vector>
#include <iostream>
using namespace std;
vector <int> merge(vector <int> a, vector <int> b)
//������� ������� ��� �������
{
    vector<int> c(a.size()+b.size());//�������������� ������
    //���������� �������������� ������
    int kol1 = 0;//� ������� �
    int kol2 = 0;//� ������� b
    //�������� ������ c
    for(int i = 0; i < c.size(); i++)
    {
        //���� �� ��� ��������� ������������ ������� �,
        //�� ��� �������� �������� �������� ������� b
        if(kol1==a.size())
        {
            c[i] = b[kol2];
            kol2++;
            continue;
        }
        //��������
        if(kol2==b.size())
        {
            c[i] = a[kol1];
            kol1++;
            continue;
        }
        //��� ��� ���� ������� ��� �� ���������
        //������������, �� ����� �������� �����
        //�������� ������� �� ��������� �����
        if(a[kol1]<=b[kol2])
        {
            c[i] = a[kol1];
            kol1++;
        }
        else
        {
            c[i] = b[kol2];
            kol2++;
        }
    }
    return c;
}
//������� ��������� ������
vector<int> merge_sort(vector <int> a)
{
    //���� ������ ������� ������ 1,
    //�� �� ������������
    if(a.size()<=1)
        return a;
    vector<int> b,c;
    b.assign(a.begin(), a.end()-(a.size()/2));
    c.assign(a.end()-(a.size()/2), a.end());
    return merge(merge_sort(b),merge_sort(c));
}
int main()
{

    vector<int> a;
    for(int i = 0; i < 10; i++)
    {
        a.push_back(rand());
    }
    a = merge_sort(a);
    for(int i = 0;i < a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}