#include<iostream>
#include<functional>
#include "sort.cpp"
#include<string>
#include<array>
#include<vector>
#include<iterator>
#include"search.cpp"

using std::vector;
using std::array;
using std::string;

template<typename T>
void show(const T& a){
    for(const auto & i:a){
        cout<<i<<" ";
    }
    cout<<endl;
}

template<class T>
int ccim(T a,T b){
    if(a<b) return 1;
    else if(a>b) return -1;
    else return 0;
}

template<class T>
void sort_auto(std::initializer_list<T> &a){
    vector<T> v1;
    for(auto i=a.begin();i!=a.end();i++){
        v1.push_back(*(i));
    }
    show(v1);
    slectsort(v1.data(),v1.data()+v1.size());
    show(v1);
}

int str_len_comp(const string &a,const string &b){
    if(a.length()<b.length()) return -1;
    else if(a.length()>b.length()) return 1;
    else return 0;
}


struct S {
    public:
        string first_name;
        string last_name;
};

bool operator<(S s1,S s2){return (s1.first_name<s2.first_name);}
bool operator>(S s1,S s2){return (s1.first_name>s2.first_name);}
bool operator==(S s1,S s2){return (s1.first_name==s2.first_name);}
template<class S>
size_t hashofs(const S &s){
        size_t h1=std::hash<std::string>()(s.first_name);
        size_t h2=std::hash<std::string>()(s.last_name);
        return h1^(h2 << 1);
}

std::ostream &operator<<(std::ostream &out,const S& s1){
    out<<"firt_name:"<<s1.first_name<<" last_name:"<<s1.last_name;
    return out;
}

int S_comp(const S &a,const S &b){
    if(a.first_name<b.first_name) return -1;
    else if(a.first_name>b.first_name) return 1;
    else return 0;
}

size_t hash_string(const string & s1){
    return std::hash<string>()(s1);
}

int main(){
    /*expamle of search*/
    string a[5]={"s","b","c","d","z"};
    int b[5]={1,2,3,4,5};


    // sequential_search<string,int> b1;
    // sequential_search<string,int> b2(b1);

    // sequential_search<string,int> s1= seq_search(a,a+4,b,b+4);
    // cout<<*(s1.get("s"))<<endl;
    // s1.put(a[0],10);
    // cout<<*(s1.get("s"))<<endl;
    // s1.show();cout<<""<<endl;
    // s1.delete_key("s");
    // s1.show();
    
    // sequential_search<string,int> b2;
    // b2.set_compare(str_len_comp);
    // string a11[4]={"s","bb","aaa","cc"};
    // int b11[3]={1,2,3};
    // for(int i=0;i<3;i++){b2.put(a11[i],b11[i]);}
    // b2.show();
    // cout<<""<<endl;
    // b2.put(a11[3],10);
    // b2.show();
    /*********************/

    // binarysearch<string,int> b1=bin_search(a,a+5,b,b+5);
    // binarysearch<string,int> b2(b1);
    // b2.show();
    // cout<<*(b1.get("s"))<<endl;
    // b1.put(a[0],10);
    // cout<<*(b1.get("s"))<<endl;
    // cout<<*(b1.min())<<endl;
    // cout<<*(b1.max())<<endl;
    // cout<<*(b1.floor("e"))<<endl;
    // cout<<*(b1.select(3))<<endl;
    // cout<<b1.rank("s")<<endl;
    // cout<<*(b1.ceiling("a"))<<endl;
    // cout<<b1.contains("a")<<endl;
    // b1.show();cout<<""<<endl;
    // b1.delete_key("s");
    // b1.show();
    // b1.delete_max();
    // b1.delete_min();
    // cout<<" "<<endl;
    // b1.show();
    
    // binarysearch<string,int> b2(5);
    // b2.set_compare(str_len_comp);
    // string a11[4]={"s","bb","aaa","cc"};
    // int b11[3]={1,2,3};
    // for(int i=0;i<3;i++){b2.put(a11[i],b11[i]);}
    // b2.show();
    // cout<<*(b2.min())<<endl;
    // b2.put(a11[3],10);
    // b2.show();
    /********************/

    // bst<string,int> b1;
    // for(int i=0;i<4;i++){b1.put(a[i],b[i]);}
    // cout<<b1.size()<<endl;
    // cout<<*(b1.get("b"))<<endl;
    // b1.put(a[1],10);
    // cout<<*(b1.get("b"))<<endl;
    // cout<<*(b1.min())<<endl;
    // cout<<*(b1.max())<<endl;
    // cout<<*(b1.floor("d"))<<endl;
    // cout<<*(b1.select(2))<<endl;
    // cout<<b1.rank("s")<<endl;
    // cout<<*(b1.ceiling("a"))<<endl;
    // b1.show(); cout<<" "<<endl;
    // b1.delete_key("s");
    // b1.show();cout<<""<<endl;
    // b1.delete_max();
    // b1.delete_min();
    // b1.show();

    // bst<string,int> b2;
    // b2.set_compare(str_len_comp);
    // string a11[4]={"s","bb","aaa","cc"};
    // int b11[3]={1,2,3};
    // for(int i=0;i<3;i++){b2.put(a11[i],b11[i]);}
    // b2.show();
    // cout<<*(b2.min())<<endl;
    // b2.put(a11[3],10);
    // b2.show();

    /*************/

    // RedBlackBST<string,int> b1;
    // for(int i=0;i<5;i++){b1.put(a[i],b[i]);}
    // cout<<b1.size()<<endl;
    // cout<<*(b1.get("b"))<<endl;
    // b1.put(a[1],10);
    // cout<<*(b1.get("b"))<<endl;
    // cout<<*(b1.min())<<endl;
    // cout<<*(b1.max())<<endl;
    // cout<<*(b1.floor("e"))<<endl;
    // cout<<*(b1.select(3))<<endl;
    // cout<<b1.rank("s")<<endl;
    // cout<<*(b1.ceiling("a"))<<endl;
    // b1.show(); cout<<" "<<endl;
    // b1.delete_key("s");
    // b1.show();cout<<""<<endl;
    // b1.delete_max();
    // b1.delete_min();
    // b1.show();

    // RedBlackBST<string,int> b2;
    // b2.set_compare(str_len_comp);
    // string a11[4]={"s","bb","aaa","cc"};
    // int b11[3]={1,2,3};
    // for(int i=0;i<3;i++){b2.put(a11[i],b11[i]);}
    // b2.show();
    // cout<<*(b2.min())<<endl;
    // b2.put(a11[3],10);
    // b2.show();

    /**********/
    separate_chain_hash<string,int>b1=sep_hash<string,int>(5);
    // separate_chain_hash<string,int> b1(5);
    // b1.set_hash(hash_string);
    for(int i=0;i<5;i++){b1.put(a[i],b[i]);}
    cout<<*(b1.get(a[0]))<<endl;
    cout<<b1.size()<<endl;
    b1.show();
    cout<<""<<endl;
    b1.delete_key(a[0]);
    b1.show();

    // S s1;s1.first_name="a";s1.last_name="A";
    // S s2;s2.first_name="b";s2.last_name="B";
    // S s3;s3.first_name="c";s3.last_name="C";
    // S ths[3]={s1,s2,s3};
    // cout<<s1<<endl;
    // separate_chain_hash<S,int> b2;
    // b2.set_hash(hashofs);
    // for(int i=0;i<3;i++){b2.put(ths[i],b[i]);}
    // b2.show();
    
    /*example of sort*/
    // int a[9]={2,1,3,4,5,6,2,1,0};
    // show(a);
    
    // slectsort(a,a+9);
    // slectsort(a,a+9,GREATER);
    // slectsort(a,a+9,ccim<int>);

    // insertsort(a,a+9);
    // insertsort(a,a+9,GREATER);
    // insertsort(a,a+9,ccim<int>);
    
    // shellsort(a,a+9);
    // shellsort(a,a+9,GREATER);
    // shellsort(a,a+9,ccim<int>);

    // mergesort(a,a+9);
    // mergesort(a,a+9,GREATER);
    // mergesort(a,a+9,ccim<int>);

    // quicksort(a,a+9);
    // quicksort(a,a+9,true);
    // quicksort(a,a+9,false,GREATER);
    // quicksort(a,a+9,true,GREATER);
    // quicksort(a,a+9,false,ccim<int>);
    // quicksort(a,a+9,true,ccim<int>);

    // quicksort_three_way(a,a+9);
    // quicksort_three_way(a,a+9,true);
    // quicksort_three_way(a,a+9,false,GREATER);
    // quicksort_three_way(a,a+9,true,GREATER);
    // quicksort_three_way(a,a+9,false,ccim<int>);
    // quicksort_three_way(a,a+9,true,ccim<int>);

    // heapsort(a,a+9);
    // heapsort(a,a+9,GREATER);
    // heapsort(a,a+9,ccim<int>);

    // slectsort(a,a+9,[](int a,int b){return a>b;});
    // show(a);
        
    // auto b={0,2,3,1,2}; //auto类型不可变，这就看个数
    // sort_auto(b);

    // array<string,3> arr={"a","c","b"};
    // show(arr);
    // slectsort(arr.begin(),arr.end(),ccim<string>);
    // slectsort(arr.begin(),arr.end());
    // slectsort(arr.begin(),arr.end(),GREATER);
    // show(arr);

    return 0;

}



