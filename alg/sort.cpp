#include<iostream>
#include<memory>
#include<algorithm>
#include<random>
#include<chrono>
#include<string>
// #include<functional>

unsigned seed = std::chrono::system_clock::now ().time_since_epoch ().count ();
std::mt19937 engine1(seed);

using std::shared_ptr;
using std::make_shared;
using std::cout;
using std::endl;
using std::shuffle;
using std::size_t;
using std::string;

static const string LESS="less";
static const string GREATER="greater";


template<typename T ,size_t N>
constexpr size_t arraylen(T (&)[N])noexcept{
    return N;
}

template<typename T>
int arraylen(T *a,T*b){
    int i=0;
    while (a+i!=b){i++;}
    return i;
}


template<class T>
int compare_less(T a,T b){
    if(a<b) return 1;
    else return 0;
}

template<class T>
int compare_greater(T a,T b){
    if(a>b) return 1;
    else return 0;
}



//base class of sort
template<class T>
class sortclass{
    public:
        template<typename comp=int (*)>
        bool less(T v,T u,comp compfun){return compfun(v,u)==1;}
        void exch(T *a,int i,int j){T t=*(a+i);*(a+i)=*(a+j);  *(a+j)=t;}

};

//sort class 
template<class T>
class selectsort1:public sortclass<T>{
    public:
        template<typename compare>
        void sort(T * a,int len,compare com_fun) ;
    private:
        template<typename compare>
        int slelsct_find_min(T* a,int i, int j,compare com_fun);
        
};

template<class T>
class insertsort1:public sortclass<T>{
    public:
        template<typename compare>
        void sort(T * a,int len,compare com_fun) ;
};

template<class T>
class shellsort1:public sortclass<T>{
    public:
        template<typename compare>
        void sort(T * a,int len,compare com_fun) ;
};

template<class T>
class mergesort1:public sortclass<T>{
    public:
        T *auk;
        mergesort1(int n){auk=new T[n];}

        mergesort1(const mergesort1 &)=delete;          
        mergesort1 &operator =(const mergesort1 &)=delete;
        ~mergesort1(){delete [] auk;}

        template<typename compare>
        void sort(T * a,int len,compare com_fun) ;
    private:
        template<typename compare>
        void sort(T* a,int begin,int end,compare com_fun);
        template<typename compare>
        void mergeone(T* a,int l, int med,int r,compare com_fun);
};

template<class T>
class quicksort1:public sortclass<T>{
    public :
        template<typename compare>
        void sort(T * a,int len,compare com_fun) {sort(a,0,len-1,com_fun);};
        template<typename compare>
        void sort3(T* a,int len,compare com_fun){sort3(a,0,len-1,com_fun);}
    private:
        template<typename compare>
        int partition(T* a,int lo, int hi,compare com_fun);
        template<typename compare>
        void sort(T* a,int lo,int hi,compare com_fun);
        template<typename compare>
        void sort3(T* a, int lo, int hi,compare com_fun);
};

template<class T>
class heapsort1:public sortclass<T>{
    public:
        template<typename compare>
        void sort(T *pq,int n,compare com_fun); 
    private:
        template<typename compare>
        void sink(T* pq, int k, int n,compare com_fun);
};
//sort function
template<typename T,typename PTR>
void sort_fun(T *a,T *b,PTR p1,string str="less"){
    int n=arraylen(a,b);
    if(str==LESS){p1->sort(a,n,compare_less<T>);}
    else if(str==GREATER){p1->sort(a,n,compare_greater<T>);}
    else {cout<<"fuck you"<<endl;}
}

/*different sort methods*/

//select sort
template<class T>
void slectsort(T *a,T *b,string str="less"){
    shared_ptr<selectsort1<T>> p1=make_shared<selectsort1<T>>();
    sort_fun(a,b,p1,str);
}

template<class T,typename compare>
void slectsort(T *a,T *b,compare com_fun){
    int n=arraylen(a,b);
    shared_ptr<selectsort1<T>> p1=make_shared<selectsort1<T>>();
    p1->sort(a,n,com_fun);
}

//insert sort
template<class T>
void insertsort(T *a,T *b,string str="less"){
    shared_ptr<insertsort1<T>> p1=make_shared<insertsort1<T>> ();
    sort_fun(a,b,p1,str);
}

template<class T,typename compare>
void insertsort(T *a,T *b,compare com_fun){
    int n=arraylen(a,b);
    shared_ptr<insertsort1<T>> p1=make_shared<insertsort1<T>>();
    p1->sort(a,n,com_fun);
}

//shell sort
template<class T>
void shellsort(T *a,T *b,string str="less"){
    shared_ptr<shellsort1<T>> p1=make_shared<shellsort1<T>>();
    sort_fun(a,b,p1,str);
}

template<class T,typename compare>
void shellsort(T *a,T *b,compare com_fun){
    int n=arraylen(a,b);
    shared_ptr<shellsort1<T>> p1=make_shared<shellsort1<T>>();
    p1->sort(a,n,com_fun);
}

//merge sort
template<class T>
void mergesort(T *a,T *b,string str="less"){
    int n=arraylen(a,b);
    shared_ptr<mergesort1<T>> p1=make_shared<mergesort1<T>>(n);
    sort_fun(a,b,p1,str);
}

template<class T,typename compare>
void mergesort(T *a, T*b,compare com_fun){
    int n=arraylen(a,b);
    shared_ptr<mergesort1<T>> p1=make_shared<mergesort1<T>>(n);
    p1->sort(a,n,com_fun);
}

//quick sort
template<class T>
void quicksort(T *a,T *b, bool is_shuffle=false,string str="less"){
    int n=arraylen(a,b);
    if(is_shuffle){shuffle(a,a+n,engine1);} //随机快速排序
    shared_ptr<quicksort1<T>> p1=make_shared<quicksort1<T>>();
    sort_fun(a,b,p1,str);
}

template<class T,typename compare>
void quicksort(T *a,T *b, bool is_shuffle=false,compare com_fun=compare_less){
    int n=arraylen(a,b);
    if(is_shuffle){shuffle(a,a+n,engine1);} //随机快速排序
    shared_ptr<quicksort1<T>> p1=make_shared<quicksort1<T>>();
    p1->sort(a,n,com_fun);
}

//quick sort three ways
template<class T>
void quicksort_three_way(T *a,T *b,bool is_shuffle=false,string str="less"){
    int n=arraylen(a,b);
    if(is_shuffle){shuffle(a,a+n,engine1);} //随机快速排序
    shared_ptr<quicksort1<T>> p1=make_shared<quicksort1<T>>();
    if(str==LESS){p1->sort3(a,n,compare_less<T>);}
    else if(str==GREATER){p1->sort3(a,n,compare_greater<T>);}
    else {cout<<"fuck you"<<endl;}
}

template<class T,typename compare>
void quicksort_three_way(T *a,T *b, bool is_shuffle=false,compare com_fun=compare_less){
    int n=arraylen(a,b);
    if(is_shuffle){shuffle(a,a+n,engine1);} //随机快速排序
    shared_ptr<quicksort1<T>> p1=make_shared<quicksort1<T>>();
    p1->sort3(a,n,com_fun);
}

//heap sort
template<class T>
void heapsort(T *a,T *b,string str="less"){
    int n=arraylen(a,b);
    shared_ptr<heapsort1<T>> p1=make_shared<heapsort1<T>>();
    sort_fun(a,b,p1,str);
}

template<class T,typename compare>
void heapsort(T *a,T *b,compare com_fun){
    int n=arraylen(a,b);
    shared_ptr<heapsort1<T>> p1=make_shared<heapsort1<T>>();
    p1->sort(a,n,com_fun);
}
/*fun*/

//select sort
template<class T>
template<class compare>
void selectsort1<T>::sort(T *a,int len,compare compare_fun){
    for (int i=0;i<len;i++){
        this->exch(a,i,slelsct_find_min(a, i, len,compare_fun));
    }
}

template<class T>
template<typename compare>
int selectsort1<T>::slelsct_find_min(T* a,int i,int j,compare compare_fun){
    int min=i;
    for (int k=i;k<j;k++){
        if (this->less(*(a+k),*(a+min),compare_fun)){
            min=k;
        }
    }
    return min;
}

//insert sort
template<class T>
template<typename compare>
void insertsort1<T>::sort(T* a,int len,compare com_fun){
        for (int i =1;i<len;i++){
            for (int j=i;j>0&&this->less(*(a+j),*(a+j-1),com_fun);j--){
                this->exch(a,j,j-1);
            }
        }
}

//shell sort
template<class T>
template<typename compare>
void shellsort1<T>::sort(T *a,int len,compare com_fun){
    int h=1;
    while(h<(len/3)){
        h=h*3+1;
    }
    while (h>=1){
        for (int i =h;i<len;i++){
            for (int j=i;j>=h&&this->less(*(a+j),*(a+j-h),com_fun);j-=h){
                this->exch(a,j,j-h);
            }
        }
        h=h/3;
    }
}

//merge sort
template<class T>
template<typename compare>
void mergesort1<T>::sort(T* a,int len,compare com_fun){ 
    sort(a,0,len-1,com_fun); 
}

template<class T>
template<typename compare>
void mergesort1<T>::sort(T* a,int begin,int end,compare com_fun){
    if(end<=begin)return;
    int median=begin+(end - begin)/2;
    sort(a,begin,median,com_fun);
    sort(a,median+1,end,com_fun);
    mergeone(a,begin,median,end,com_fun);
}

template<class T>
template<typename compare>
void mergesort1<T>::mergeone(T* a,int l, int med,int r,compare com_fun){
    int thebegin=l;
    int themedian=med+1;
    for(int k=l;k<=r;k++){
        *(auk+k)=*(a+k);
    }
    for (int i=l;i<=r;i++){
        if(thebegin>med) *(a+i)=*(a+(themedian++));
        else if (themedian>r) *(a+i)=*(auk+(thebegin++));
        else if(this->less(*(auk+themedian),*(auk+thebegin),com_fun)) *(a+i)=*(auk+(themedian++));
        else *(a+i)=*(auk+(thebegin++));
    }
}


//quick sort
template<class T>
template<typename compare>
int quicksort1<T>::partition(T* a,int lo, int hi,compare com_fun){
    int i=lo,j=hi+1;
    T v= *(a+lo);
    while (true){
        while(this->less(*(a+(++i)),v,com_fun)) if (i==hi) break;
        while(this->less(v,*(a+(--j)),com_fun)) if (j==lo) break;
        if(i>=j) break;
        this->exch(a,i,j);
    }
    this->exch(a,lo,j);
    return j;
}

template<class T>
template<typename compare>
void quicksort1<T>::sort(T* a,int lo,int hi,compare com_fun){
    if(hi<=lo) return;
    int j= partition(a, lo, hi,com_fun);
    sort(a,lo,j-1,com_fun);
    sort(a,j+1,hi,com_fun);
}

template<class T>
template<typename compare>
void quicksort1<T>::sort3(T* a, int lo, int hi,compare com_fun) {
    if(hi<=lo) {return;} 
    int lt=lo,i=lo+1,gt=hi; 
    T v=*(a+lo); 
    while(i<=gt) 
    {
         int cmp=com_fun(*(a+i),v);
         if(cmp<0){this->exch(a,lt++,i++);}
         else if(cmp > 0){this->exch(a,i,gt--);} 
         else{i++;} 
    }   
    sort3(a,lo,lt-1,com_fun); 
    sort3(a,gt+1,hi,com_fun); 
} 

//heap sort
template<class T>
template<typename compare>
void heapsort1<T>::sort(T *a,int n,compare com_fun) {
    for (int k=n/2;k>=1;k--){sink(a,k,n,com_fun);}
    int k=n;
    while (k>1) {
        this->exch(a,0,(k--)-1);
        this->sink(a,1,k,com_fun);
    }
}

template<class T>
template<typename compare>
void heapsort1<T>::sink(T* a,int k,int n,compare com_fun) {
    while (2*k<=n) {
        int j = 2*k;
        if (j<n&&this->less(*(a+j-1),*(a+j),com_fun)) j++;
        if (!this->less(*(a+k-1),*(a+j-1),com_fun)) break;
        this->exch(a,k-1,j-1);
        k = j;
    }
}