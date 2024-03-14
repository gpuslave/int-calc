#include <iostream>
#include <cmath>
#include <cstdarg>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

void permutation_with_repetition(int r, int n, int k, std::vector<int> temp, std::vector<std::vector<int>> &res)
{
    if (k == r)
    {
        res.push_back(temp);
        return;
    }
    else
    {
        for (int y = 0; y <= n; y++)
        {
            temp[k] = y;
            permutation_with_repetition(r, n, k + 1, temp, res);
        }
    }
}

double integral_func(std::vector<double> args)
{
    double sum = 0.0;
    for (auto &&arg : args)
    {
        sum += arg * arg;
    }
    return sum;
}

double calc_integral(std::vector<double> limits, int partitioning)
{
    double integral_sum = 0.0;

    std::vector<double> partition;
    for (int i = 0; i < limits.size() - 1; i += 2)
    {
        partition.push_back(1.0 * (limits[i + 1] - limits[i]) / partitioning);
    }

    for (auto &&i : partition)
    {
        cout << i << " ";
    }
    cout << endl;

    std::vector<std::vector<int>> res;
    int r = limits.size() / 2;
    int n = partitioning;
    int k = 0;
    std::vector<int> temp_vec(r, k);

    permutation_with_repetition(r, n, k, temp_vec, res);

    for (auto &&vec : res)
    {
        for (auto &&elem : vec)
            cout << elem << " ";
        cout << endl;
    }

    for (auto &&vec : res)
    {
        std::vector<double> temp;
        for (int i = 0; i < vec.size(); i++)
        {
            temp.push_back(limits[2 * i] + vec[i] * partition[i]);
        }
        double integral_part_sum = integral_func(temp);
        for (auto &&part : partition)
        {
            integral_part_sum *= part;
        }
        integral_sum += integral_part_sum;
    }
    return integral_sum;
}

int main()
{
    std::vector<double> limits;

    cout << "Введите границы интегрирования: " << endl;
    double temp;
    while (cin >> temp)
        limits.push_back(double(temp));

    if (limits.size() % 2 != 0)
    {
        cout << "Ошибка ввода" << endl;
        return 1;
    }

    double calculated = calc_integral(limits, 40);
    cout << calculated << endl;
    return 0;
}