#include "poly.h"
#include <future>
#include <thread>
#include <utility>
#include <vector>

template <typename T>
auto lagrange_inter_step(std::vector<T> &&vec, int &&k) -> polynomial<T>
{
    polynomial<T> res = {{1}};
    int num = 0;
    T k_val = vec[k];
    for (auto i = vec.begin(); i != vec.end(); i++)
    {
        if (num != k)
        {
            T k_val_step = k_val - (*i);
            res = res * polynomial<T>{(*i) * (-1) / k_val_step, 1 / k_val_step};
        }
        else
        {
            res = res;
        }
        num++;
    }
    return res;
}

template <typename T>
polynomial<T> lagrange_inter(std::vector<T> &&vec, std::vector<T> &&val)
{
    polynomial<T> res = {{0}};
    for (int i = 0; i < vec.size(); i++)
    {
        polynomial<T> temp = lagrange_inter_step(std::move(vec), std::move(i));
        res = res + temp * val[i];
    }
    return res;
}

double fun_test(double &&val)
{
    return 1 / val;
}

template <typename T>
polynomial<T> neville_inter(std::vector<T> &&vec, std::vector<T> &&val)
{
    typename std::vector<std::vector<polynomial<T>>> Q_vec;
    for (int i = 0; i < vec.size(); i++)
    {
        polynomial<T> Q_i0 = {{val[i]}};
        std::vector<polynomial<T>> Q_i;
        Q_i.push_back(std::move(Q_i0));
        Q_vec.push_back(std::move(Q_i));
    }
    for (int i = 1; i < vec.size(); i++)
    {
        for (int j = 1; j <= i; j++)
        {
            polynomial<T> q_ij_1 = {{-vec[i - j], 1}};
            polynomial<T> q_i_1_j_1 = {{-vec[i], 1}};
            polynomial<T> dev = {{vec[i] - vec[i - j]}};
            polynomial<T> Q_ij_ = (q_ij_1 * Q_vec[i][j - 1]) - (q_i_1_j_1 * Q_vec[i - 1][j - 1]);
            polynomial<T> Q_ij = Q_ij_ / dev;
            Q_vec[i].push_back(Q_ij);
        }
    }
    return Q_vec[vec.size() - 1][vec.size() - 1];
}

template <typename T>
polynomial<T> newton_inter(std::vector<T> &&vec, std::vector<T> &&val)
{
    typename std::vector<std::vector<T>> T_vec;
    for (int i = 0; i < vec.size(); i++)
    {
        std::vector<T> T_i;
        T_i.push_back(val[i]);
        T_vec.push_back(std::move(T_i));
    }
    for (int i = 1; i < vec.size(); i++)
    {
        for (int j = 1; j <= i; j++)
        {
            T num = (T_vec[i][j - 1] - T_vec[i - 1][j - 1]) / (vec[i] - vec[i - j]);
            T_vec[i].push_back(num);
        }
    }
    polynomial<T> res = {{T_vec[0][0]}};
    for (int i = 1; i < vec.size(); i++)
    {
        polynomial<T> po_i = {{T_vec[i][i]}};
        for (int j = 0; j <= i - 1; j++)
        {
            polynomial<T> temp = {{-vec[j], 1}};
            po_i = po_i * temp;
        }
        res = res + po_i;
    }
    return res;
}

template <typename T>
polynomial<T> hermite_inter(std::vector<T> &&x, std::vector<T> &&fx, std::vector<T> &&fdx)
{
    typename std::vector<std::vector<T>> Q;
    std::vector<T> Z;
    for (int i = 0; i < x.size(); i++)
    {
        Z.push_back(x[i]);
        Z.push_back(x[i]);
        std::vector<T> Q_2i;
        std::vector<T> Q_2i1;
        Q_2i.push_back(fx[i]);
        Q_2i1.push_back(fx[i]);
        Q_2i1.push_back(fdx[i]);
        if (i != 0)
        {
            T num = (fx[i] - Q[2 * i - 1][0]) / (x[i] - Z[2 * i - 1]);
            Q_2i.push_back(num);
        }
        Q.push_back(std::move(Q_2i));
        Q.push_back(std::move(Q_2i1));
    }
    for (int i = 2; i < 2 * x.size(); i++)
    {
        for (int j = 2; j <= i; j++)
        {
            T num = (Q[i][j - 1] - Q[i - 1][j - 1]) / (Z[i] - Z[i - j]);
            Q[i].push_back(num);
        }
    }
    polynomial<T> res = {{0}};
    polynomial<T> temp = {{1}};
    for (int i = 0; i < x.size(); i++)
    {
        res = res + Q[2 * i][2 * i] * temp;
        polynomial<T> t1 = {{-x[i], 1}};
        temp = temp * t1;
        res = res + Q[2 * i + 1][2 * i + 1] * temp;
        temp = temp * t1;
    }
    return res;
}

template <typename T>
polynomial<T> la_step_pal(std::vector<T> vec, std::vector<T> val, int beg, int end)
{
    polynomial<T> res = {{0}};
    for (int i = beg; i < end; i++)
    {
        polynomial<T> temp = lagrange_inter_step(std::move(vec), std::move(i));
        res = res + temp * val[i];
    }
    return res;
}

template <typename T>
polynomial<T> lagrange_inter_pal(std::vector<T> &&vec, std::vector<T> &&val)
{
    polynomial<T> res = {{0}};
    int midsize = vec.size() / 2;
    int si = vec.size();

    // std::future<polynomial<T>> res1=std::async(la_step_pal<T>,vec,val,0,midsize);
    // std::future<polynomial<T>> res2=std::async(la_step_pal<T>,vec,val,midsize,si);

    // res=res1.get()+res2.get();

    polynomial<T> res1ts = {{0}};
    polynomial<T> res2ts = {{0}};

    std::thread t1([&]()
                   {        
        for(int i=0;i<midsize;i++){
            polynomial<T> temp=lagrange_inter_step(std::move(vec),std::move(i));
            res1ts=res1ts+temp*val[i];
        } });
    t1.join();
    std::thread t2([&]()
                   {
        for(int i=midsize;i<si;i++){
            polynomial<T> temp=lagrange_inter_step(std::move(vec),std::move(i));
            res2ts=res2ts+temp*val[i];
        } });
    t2.join();
    res = res1ts + res2ts;
    return res;
}

double real_fun_test(double x)
{
    return -3 + 2 / (1 + std::exp(-2 * x));
}

double asd(int x)
{
    double asdas = 123.2;
    cout << x << endl;
    return asdas;
}

int main()
{
    // std::vector<double> vec1{2,2.75,4};
    // std::vector<double> vec2{fun_test(2),fun_test(2.75),fun_test(4)};

    // polynomial<double> poly=lagrange_inter(std::move(vec1),std::move(vec2));
    // cout<<formula_format(poly)<<endl;
    // cout<<eva_poly(std::move(poly.data()),3.0)<<endl;

    // polynomial<double> poly_pal=lagrange_inter_pal(std::move(vec1),std::move(vec2));
    // cout<<formula_format(poly_pal)<<endl;

    // std::vector<double> vec11{2.0,2.2,2.3};
    // std::vector<double> vec12{std::log(2.0),std::log(2.2),std::log(2.3)};
    // polynomial<double> pol1=neville_inter(std::move(vec11),std::move(vec12));
    // cout<<eva_poly(std::move(pol1.data()),2.1)<<endl;

    // std::vector<double> vec21{1.0,1.3,1.6,1.9,2.2};
    // std::vector<double> vec22{0.7651977,0.6200860,0.4554022,0.2818186,0.1103623};
    // polynomial<double> pol2=newton_inter(std::move(vec21),std::move(vec22));
    // cout<<eva_poly(std::move(pol2.data()),1.5)<<endl;

    std::vector<double> vec31 = {1.0, 1.2, 1.4};
    std::vector<double> vec32 = {-1.23843073814929, -1.16637354288998, -1.11467693804580};
    std::vector<double> vec33 = {0.419974341614026, 0.305019996207409, 0.216152459025537};
    polynomial<double> pol3 = hermite_inter(std::move(vec31), std::move(vec32), std::move(vec33));
    cout << eva_poly(std::move(pol3.data()), 1.3) << " " << real_fun_test(1.3) << endl;

    std::vector<double> vec31_test = {1.6, 1.8, 2.0};
    std::vector<double> vec32_test = {-1.07835820540806, -1.05321754719743, -1.03599222316296};
    std::vector<double> vec33_test = {0.150527075818285, 0.103558374038152, 0.0706508248531645};
    polynomial<double> pol3_test = hermite_inter(std::move(vec31_test), std::move(vec32_test), std::move(vec33_test));
    cout << eva_poly(std::move(pol3_test.data()), 1.93) << " " << real_fun_test(1.93) << endl;

    // std::vector<double> pro1={0.1,0.2,0.3,0.4};
    // std::vector<double> pro2={0.62049958,-0.28398668,0.00660095,0.24842440 };

    // polynomial<double> ll1=lagrange_inter(std::move(pro1),std::move(pro2));
    // cout<<formula_format(ll1)<<endl;
    // cout<<eva_poly(std::move(ll1.data()),0.25)<<endl;
    // cout<<" "<<endl;

    // polynomial<double> nev1=neville_inter(std::move(pro1),std::move(pro2));
    // cout<<formula_format(nev1)<<endl;
    // cout<<eva_poly(std::move(nev1.data()),0.25)<<endl;
    // cout<<" "<<endl;

    // polynomial<double> new1=newton_inter(std::move(pro1),std::move(pro2));
    // cout<<formula_format(new1)<<endl;
    // cout<<eva_poly(std::move(new1.data()),0.25)<<endl;
    // cout<<" "<<endl;

    // std::vector<double> prob1={0.1,0.2,0.3,0.4};
    // std::vector<double> prob2={-0.62049958,-0.28398668,0.00660095,0.24842440};
    // std::vector<double> prob3={3.58502082,3.14033271,2.66668043,2.16529366};

    // polynomial<double> he1=hermite_inter(std::move(prob1),std::move(prob2),std::move(prob3));
    // cout<<formula_format(he1)<<endl;

    return 0;
}