#include<iostream>
#include<cstdio>
 
using namespace std;
 
int main(int argc, char **argv)
{
    // making the u matrix
    void lu(float[][10], float[][10], float[][10], int n);
    void print_mat(float[][10], int);
    float a[10][10], l[10][10], u[10][10];
    int n = 0, i = 0, j = 0;
    cout << "Enter The dimensions of the matrix for LU decompositon ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << "Enter value for " << i << "th ," << j << "th element : ";
            cin >> a[i][j];
        }
    }
    lu(a, l, u, n);
    cout<<endl;
    cout<<"******************"<<endl;
    cout << "\nThe L decompistion matrix is:\n\n";

    print_mat(l, n);
    cout<<"******************"<<endl;
    cout<<endl;
    cout << "\nU Decomposition\n\n";
    print_mat(u, n);
    cout<<endl;
    cout<<"******************"<<endl;
    return 0;
}
void lu(float a[][10], float l[][10], float u[][10], int n)
{
    int i = 0, j = 0, k = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j < i)
                l[j][i] = 0;
            else
            {
                l[j][i] = a[j][i];
                for (k = 0; k < i; k++)
                {
                    l[j][i] = l[j][i] - l[j][k] * u[k][i];
                }
            }
        }
        for (j = 0; j < n; j++)
        {
            if (j < i)
                u[i][j] = 0;
            else if (j == i)
                u[i][j] = 1;
            else
            {
                u[i][j] = a[i][j] / l[i][i];
                for (k = 0; k < i; k++)
                {
                    u[i][j] = u[i][j] - ((l[i][k] * u[k][j]) / l[i][i]);
                }
            }
        }
    }
}
void print_mat(float x[][10], int n)
{
    int i = 0, j = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("[%f ]", x[i][j]);
        }
        cout << "\n";
    }
}
