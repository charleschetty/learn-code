#include<iostream>
#include<memory>
#include<exception>
#include<string>
#include<algorithm>
#include<cassert>
#include<functional>
#include<deque>
// #include "myExceptions.h"

using std::exception;
using std::shared_ptr;
using std::make_shared;
using std::cout;
using std::endl;
using std::string;
using std::deque;

template<class T>
void changelength1d(T *&a,int oldleng,int newleng){
    T *temp=new T[newleng];
    int num=std::min(oldleng,newleng);
    std::copy(a,a+num,temp);
    delete []a;
    a=temp;
}

//sequential search
template<typename Key,typename value>
struct Node_of_seq
{
    Key key;
    value val;
    Node_of_seq<Key,value> *next;

    Node_of_seq(){}
    Node_of_seq(const Key &k, const value &v,Node_of_seq<Key,value> *next){
        this->next=next;
        this->val=v;
        this->key=k;
    }
    Node_of_seq(const Key &k,const value &v){
        this->val=v;
        this->key=k;
    }

    void show(){cout<<"key:"<<this->key<<" value:"<<this->val<<endl;}
};


template<typename Key,typename value>
class sequential_search{
    private:
        Node_of_seq<Key,value> *first;

    protected:
        static int compare_base(const Key &a,const Key &b){
            if(a<b)return -1;
            else if(a>b) return 1;
            else return 0;
        }

        int (*compare)(const Key &,const Key &)=compare_base;

    public:
        sequential_search(){this->first=nullptr;}
        sequential_search(Node_of_seq<Key,value> *node){
                this->first=node;
        };

        ~sequential_search(){
            while (this->first!=nullptr)
            {
                Node_of_seq<Key,value> *nextnode=first->next;
                delete first;
                first=nextnode;
                // cout<<"del"<<endl;
            }
        }

        sequential_search(const sequential_search<Key,value> & seq){
            Node_of_seq<Key,value> *node=seq.first;
            if(node==NULL){first=NULL;return;}
            first=new Node_of_seq<Key,value>(node->key,node->val);
            node=node->next;
            Node_of_seq<Key,value> *tarnode=first;

            while(node !=nullptr){
                tarnode->next=new Node_of_seq<Key,value>(node->key,node->val);
                tarnode=tarnode->next;
                node=node->next;
            }
            tarnode->next=nullptr;
        }

        sequential_search &operator=(const sequential_search<Key,value>& seq){
            if(this==&seq){return *this;}
            while (this->first!=nullptr)
            {
                Node_of_seq<Key,value> *nextnode=first->next;
                delete first;
                first=nextnode;
            }
            Node_of_seq<Key,value> *node=seq.first;
            if(node==NULL){first=NULL;return *this;}
            first=new Node_of_seq<Key,value>(node->key,node->val);
            node=node->next;
            Node_of_seq<Key,value> *tarnode=first;
            while(node !=nullptr){
                tarnode->next=new Node_of_seq<Key,value>(node->key,node->val);
                tarnode=tarnode->next;
                node=node->next;
            }
            tarnode->next=nullptr;
            return *this;
        }
        
        void set_compare(int (*comp)(const Key &,const Key &)){
            compare=comp;
        }     

        bool contains(Key k){
            return get(k)!=NULL;
        }

        value *get(Key k){
            if(first==NULL){return NULL;}

            for (Node_of_seq<Key,value> *x=first; x!=nullptr; x=x->next){
                if (compare(k,x->key)==0){return &x->val;}    
            }
            return NULL;
        }

        void put(Key k,value val){
            for (Node_of_seq<Key,value> *x=first;x!=nullptr;x=x->next){
                if (compare(x->key,k)==0)
                {x->val=val;return;}   
            }
            first=new Node_of_seq(k,val,first);
        }

        void delete_key(Key key) {
            this->first = delete_key(this->first, key);
        }

        Node_of_seq<Key,value> *delete_key(Node_of_seq<Key,value> *x, Key key) {
            if (x == NULL) return nullptr;
            if (compare(key,x->key)==0) {return x->next;}
            x->next = delete_key(x->next, key);
            return x;
        }

        void show(){
            for(Node_of_seq<Key,value> *x=this->first; x!=nullptr;x=x->next){
                cout<<"key:"<<x->key<<" value:"<<x->val<<endl;
            }
        }

        deque<Key> keys(){
            deque<Key> d1;
            for(Node_of_seq<Key,value> *x=this->first; x!=nullptr;x=x->next){
                d1.push_back(x->key);
            }
            return d1;
        }
};

template<typename T,typename K>
sequential_search<T,K> seq_search(T *a1,T *a2,K *b1,K *b2 ){
    int i=a2-a1,j=b2-b1;
    if(i!=j) throw exception();
    sequential_search<T,K> s1;
    for(int k=0;k<i;k++){
        s1.put(*(a1+k),*(b1+k));
    }
    return s1;
}

//binary search


template<class Key,class value>
class binarysearch{
    private:
        int N;
        Key *key;
        value *val;
        int cap;

    protected:
        static int compare_base(const Key &a,const Key &b){
            if(a<b)return -1;
            else if(a>b) return 1;
            else return 0;
        }

        int (*compare)(const Key &,const Key &)=compare_base;

    public:
        binarysearch(int n=4){
            key=new Key[n];
            val=new value[n];
            cap=n;    
            N=0;
        }   

        ~binarysearch(){delete [] key;delete [] val;}
        binarysearch(const binarysearch<Key,value> & bise1){
            N=bise1.N;
            cap=bise1.cap;
            key=new Key[cap];
            val=new value[cap];
            std::copy(bise1.key,bise1.key+N,key);
            std::copy(bise1.val,bise1.val+N,val);
        }

        binarysearch &operator=(const binarysearch &)=delete;

        void set_compare(int (*comp)(const Key &,const Key &)){
            compare=comp;
        }
        
        int size(){
            return N;
        }

        int rank(Key k){
            int lo=0;int hi=N-1;
            while (lo<=hi){
                int themide=lo+(hi-lo)/2;
                int cmp=compare(k,key[themide]);
                if(cmp<0) hi=themide-1;
                else if(cmp>0) lo=themide+1;
                else return themide;
            }
            return lo;        
        }

        bool isEmpty(){
            return N==0;
        }

        value *get(Key k){
            if(isEmpty()){return NULL;}
            int i=rank(k);
            if(i>=N) {return NULL;}
            if(isEmpty()) {return NULL;}
            else if(compare(key[i],k)==0) {return val+i;}
            else { return NULL;}
        } 

        void put(Key k,value val){
            if(N>=cap-1){
                changelength1d(this->key,cap,2*cap);
                changelength1d(this->val,cap,2*cap);
                cap=2*cap;
            }

            if(isEmpty()){
                key[0]=k;
                this->val[0]=val;
                N++;
                return;
            }

            int i=rank(k);
            if(i<N&&compare(key[i],k)==0){
                this->val[i]=val;
                return;
            }

            for(int j=N;j>i;j--){
                key[j]=key[j-1];this->val[j]=this->val[j-1];
            }

            key[i]=k; this->val[i]=val;
            N++;
        }

        void show(){
            for(int i=0;i<N;i++){
                cout<<"key:"<<key[i]<<" value:"<<val[i]<<endl;
            }
        }
    
        Key *min() {
            if (isEmpty()) {return NULL;}
            return key; 
        }

        Key *max() {
            if (isEmpty()){return NULL;}
            return (key+N-1);
        }

        void delete_key(Key thekey) {
            if (isEmpty()) return;
            int i = rank(thekey);

            if (i==N |compare(key[i],thekey)!=0){
                return;
            }
            for (int j = i; j < N-1; j++)  {
                key[j] = key[j+1];
                val[j] = val[j+1];
            }

            N--;
            key[N].~Key();  
            val[N].~value();

            if (N>0&&N==cap/4){
                changelength1d(key,cap,cap/2);
                changelength1d(val,cap,cap/2);
                cap=cap/2;
            }
        }   

        void delete_min(){
            Key *k=min();
            delete_key(*k);
        }      

        void delete_max(){
            Key *k=max();
            delete_key(*k);
        }

        bool contains(Key key) {
            return get(key) != NULL;
        }

        Key *select(int k) {
            if(isEmpty()){return NULL;}
            if (k < 0 || k >= size()) {return NULL;}
            return key+k;
        }

        Key *floor(Key the_key) {
            if(isEmpty()){return NULL;}
            int i = rank(the_key);
            if (i<N&&compare(the_key ,key[i])==0) {return key+i;}
            if (i==0){return NULL;}
            else {return key+i-1;}
        }

        Key *ceiling(Key the_key) {
            if(isEmpty()){return NULL;}
            int i = rank(the_key);
            if (i == N) {return NULL;}
            else return key+i;
        }

};


template<typename T,typename K>
binarysearch<T,K> bin_search(T *a1,T *a2,K *b1,K *b2 ){
    int i=a2-a1,j=b2-b1;
    if(i!=j) throw exception();
    binarysearch<T,K> b3(i+2);
    for(int k=0;k<i;k++){
        b3.put(*(a1+k),*(b1+k));
    }
    return b3;
}

//bst
template<typename Key,typename value>
struct BST_Node{
    Key key;
    value val;
    BST_Node *left,*right;
    int N;

    BST_Node(const Key &key,const value &val,const int &N){
        this->val=val;
        this->key=key;
        this->N=N;
    }

    void show(){cout<<"key:"<<this->key<<" value:"<<this->val<<endl;}
};

template<typename Key,typename value>
class bst{
    protected:
        BST_Node<Key,value> *root;
        static void dispose(BST_Node<Key,value> *t){delete t;}

        static int compare_base(const Key &a,const Key &b){
            if(a<b)return -1;
            else if(a>b) return 1;
            else return 0;
        }

        void postoder(BST_Node<Key,value> *t){
            if(t!=NULL){
                postoder(t->left);
                postoder(t->right);
                visit(t);
                // cout<<"visit"<<endl;
            }
        }

        void postoder(void(*thevisit)(BST_Node<Key,value>*)){
            visit=thevisit;
            postoder(root);
        }

        void (*visit) (BST_Node<Key,value> *);

        int (*compare)(const Key &,const Key &)=compare_base;
    
    private:
        value *get(BST_Node<Key,value> *x, Key key){
            if (x == NULL) return   NULL; 
            int cmp = compare(key,x->key);
            if      (cmp < 0){return get(x->left, key); }
            else if (cmp > 0) {return get(x->right, key); }
            else {value *V1=&x->val;return V1; }
        }

        BST_Node<Key,value> *put(BST_Node<Key,value> *node,Key k,value v){
            if(node==NULL) return new BST_Node<Key,value>(k,v,1);    
            int cmp=compare(k,node->key);
            if(cmp<0) {node->left = put(node->left,k,v);}
            else if (cmp>0) {node->right=put(node->right,k,v);}
            else {node->val=v;}
            node->N=size(node->left)+size(node->right)+1;
            return node;
        } 

        BST_Node<Key,value> *min(BST_Node<Key,value> *thnode){
            if(thnode->left==NULL)  return thnode;
            else return min(thnode->left);
        }

        BST_Node<Key,value> *floor(BST_Node<Key,value> *thnode, Key key){
            if(thnode==NULL) return NULL;
            int cmp=compare(key,thnode->key);
            if(cmp==0) return thnode;
            else if(cmp<0) return floor(thnode->left, key);
            BST_Node<Key,value> *cmpnode=floor(thnode->right, key);
            if(cmpnode!=NULL) return cmpnode;
            else return thnode;
        }    

        BST_Node<Key,value> *select(BST_Node<Key,value> *thnode,int k){
            if (thnode==NULL) return NULL;
            int cmp=size(thnode->left);
            if(cmp>k) return select(thnode->left, k);
            else if(cmp<k) return select(thnode->right, k-cmp-1);
            else return thnode;
        }    

        int rank(Key k,BST_Node<Key,value> *thenode){
            if (thenode==NULL) return 0;
            int cmp=compare(k,thenode->key);
            if(cmp<0) return rank(k, thenode->left);
            else if(cmp>0) return rank(k, thenode->right)+size(thenode->left)+1;
            else return size(thenode->left);
        }

        BST_Node<Key,value> *delete_key(BST_Node<Key,value>  *x, Key key) { 
            if(x==NULL) {return NULL;} 
            int cmp=compare(key,x->key); 
            if(cmp<0) {x->left=delete_key(x->left,key);} 
            else if(cmp>0) {x->right=delete_key(x->right, key);} 
            else{ 
                if(x->right==NULL) {return x->left;} 
                if(x->left==NULL) {return x->right;} 
                BST_Node<Key,value> *t=x; 
                x=min(t->right);   
                x->right=delete_min(t->right); 
                x->left=t->left; 
            } 
            x->N=size(x->left)+size(x->right)+1; 
            return x; 
        }

        BST_Node<Key,value> *delete_min(BST_Node<Key,value> *thenode){
            if(thenode->left==NULL) return thenode->right;
            thenode->left=delete_min(thenode->left);
            thenode->N=size(thenode->left)+size(thenode->right)+1;
            return thenode;
        }

        BST_Node<Key,value> *delete_max(BST_Node<Key,value> *x) {
            if (x->right==NULL) return x->left;
            x->right = delete_max(x->right);
            x->N=size(x->left)+size(x->right)+1;
            return x;
        }

        BST_Node<Key,value> *ceiling(BST_Node<Key,value> *x, Key key) {
            if (x==NULL) {return NULL;}
            int cmp=compare(key,x->key);
            if (cmp==0) {return x;}
            if (cmp<0){ 
                BST_Node<Key,value> *t=ceiling(x->left,key); 
                if(t!=NULL) {return t;}else {return x;} 
            } 
            return ceiling(x->right, key); 
        }

    public :
        bst() {root=NULL;}
        ~bst() {
            visit=dispose;
            postoder(root);
            root=NULL;
        }
        bst(const bst<Key,value> &)=delete;
        bst<Key,value> operator=(const bst<Key,value> &)=delete;

        void set_compare(int (*comp)(const Key &,const Key &)){
            compare=comp;
        }

        int size(BST_Node<Key,value> *x){
            if(x ==NULL) return 0;
            else return x->N;
        }

        int size(){
            return size(root);
        }

        value *get(Key key){  
            return get(root, key);  
        } 

        void put(Key k,value v){
            root=put(root,k,v);
        }

        Key *min(){
            BST_Node<Key,value> *b=min(root);
            if(b!=NULL){return &(b->key);}
            else {return NULL;}
        }

        Key *max(){
            BST_Node<Key,value> *b=max(root);
            if(b!=NULL){return &(b->key);}
            else {return NULL;}
        }

        BST_Node<Key,value> *max(BST_Node<Key,value> *thnode){
           if(thnode->right==NULL) return thnode;
           else return max(thnode->right);
        }

        Key *floor(Key key){
            BST_Node<Key,value> *b=floor(root,key);
            if(b!=NULL){return &(b->key);}
            else {return NULL;}
        }

        Key *select(int k){
            BST_Node<Key,value> *b=select(root,k);
            if(b!=NULL){return &(b->key);}
            else {return NULL;}
        }

        Key *ceiling(Key key) {
            BST_Node<Key,value> *b=ceiling(root,key);
            if(b!=NULL){return &(b->key);}
            else {return NULL;}
        }

        int rank(Key k){
            return rank(k,root);
        }

        void delete_key(Key key){  
            root = delete_key(root, key);  
        }

        void delete_min(){
            root=delete_min(root);
        }

        void delete_max() {
            root = delete_max(root);
        }

        void show(){
            for(int i=0;i<size();i++){
                cout<<"Key:"<<*(select(i))<<" value:"<<*(get(*select(i)))<<endl;
            }
        }

};
/*red-black-tree*/
template<typename Key,typename Value>
struct R_B_Node {
    Key key;           
    Value val;         
    R_B_Node<Key,Value> *left=NULL, *right=NULL;  
    bool color;     
    int size;          

    R_B_Node(Key key, Value val, bool color, int size) {
            this->key = key;
            this->val = val;
            this->color = color;
            this->size = size;
        }
    
    // R_B_Node (){this->left=NULL;this->right=NULL;}
    R_B_Node(){}

    void show(){cout<<"Key:"<<this->key<<" value:"<<this->val<<endl;}
};

template<typename Key,typename Value>
class RedBlackBST{
    protected:
        const static bool RED=true;
        const static bool BLACK=false;

        static void dispose(R_B_Node<Key,Value> *t){delete t;}

        static int compare_base(const Key &a,const Key &b){
            if(a<b)return -1;
            else if(a>b) return 1;
            else return 0;
        }

        void postoder(R_B_Node<Key,Value> *t){
            if(t!=NULL){
                postoder(t->left);
                postoder(t->right);
                visit(t);
                // cout<<"visit"<<endl;
            }
        }

        void postoder(void(*thevisit)(R_B_Node<Key,Value>*)){
            visit=thevisit;
            postoder(root);
        }

        void (*visit) (R_B_Node<Key,Value> *);

        int (*compare)(const Key &,const Key &)=compare_base;
    private:   
        R_B_Node<Key,Value> *root;

        int size(R_B_Node<Key,Value> *x) {
            if (x==NULL) return 0;
            return x->size;
        }

        bool isRed(R_B_Node<Key,Value> *x) {
            if (x==NULL) return false;
            return x->color==RED;
        }

        Value *get(R_B_Node<Key,Value> *x, Key key) {
            while (x != NULL) {
                int cmp=compare(key,x->key);
                if(cmp < 0) {x=x->left;}
                else if(cmp>0) {x=x->right;}
                else {return &x->val;}
            }
            return NULL;
        }

        R_B_Node<Key,Value> *rotateRight(R_B_Node<Key,Value> *h) {
        // assert (h != null) && isRed(h->left);
            R_B_Node<Key,Value> *x=h->left;
            h->left=x->right;
            x->right=h;
            x->color=x->right->color;
            x->right->color=RED;
            x->size=h->size;
            h->size=size(h->left)+size(h->right)+1;
            return x;
        }

        R_B_Node<Key,Value> *rotateLeft(R_B_Node<Key,Value> *h) {
            // assert (h != null) && isRed(h.right);
            R_B_Node<Key,Value> *x=h->right;
            h->right=x->left;
            x->left=h;
            x->color=x->left->color;
            x->left->color=RED;
            x->size=h->size;
            h->size=size(h->left)+size(h->right)+1;
            return x;
        }

        void flipColors(R_B_Node<Key,Value> *h) {
            h->color=!h->color;
            h->left->color=!h->left->color;
            h->right->color=!h->right->color;
        }

        R_B_Node<Key,Value> *moveRedLeft(R_B_Node<Key,Value> *h) {
            flipColors(h);
            if (isRed(h->right->left)) { 
                h->right=rotateRight(h->right);
                h=rotateLeft(h);
                flipColors(h);
            }
            return h;
        }

        R_B_Node<Key,Value> *moveRedRight(R_B_Node<Key,Value> *h) {
            flipColors(h);
            if (isRed(h->left->left)) { 
                h=rotateRight(h);
                flipColors(h);
            }
            return h;
        }

        R_B_Node<Key,Value> *balance(R_B_Node<Key,Value> *h) {
            if (isRed(h->right)&&!isRed(h->left))    {h = rotateLeft(h);}
            if (isRed(h->left)&&isRed(h->left->left)) {h = rotateRight(h);}
            if (isRed(h->left)&&isRed(h->right))     {flipColors(h);}
            h->size=size(h->left)+size(h->right)+1;
            return h;
        }

        R_B_Node<Key,Value> *put(R_B_Node<Key,Value> *h, Key key, Value val) { 
            if(h==nullptr) return new R_B_Node<Key,Value> (key,val,RED,1);
            int cmp=compare(key,h->key);
            if (cmp < 0) {h->left=put(h->left,key,val); }
            else if (cmp > 0) {h->right=put(h->right,key,val); }
            else {h->val=val;}

            if (isRed(h->right)&&!isRed(h->left)) {h=rotateLeft(h);}
            if (isRed(h->left)&&isRed(h->left->left)) {h=rotateRight(h);}
            if (isRed(h->left)&&isRed(h->right))     {flipColors(h);}
            h->size=size(h->left)+size(h->right)+1;
            return h;
        }

        R_B_Node<Key,Value> *delete_key(R_B_Node<Key,Value> *h, Key key) { 
            if (compare(key,h->key)<0)  {
                if (!isRed(h->left) && !isRed(h->left->left)){h = moveRedLeft(h);}
                h->left = delete_key(h->left, key);
            }
            else {
                if (isRed(h->left)){h = rotateRight(h);}
                if (compare(key,h->key)==0&&(h->right==NULL)){return NULL;}
                if (!isRed(h->right) && !isRed(h->right->left)){h = moveRedRight(h);}
                if (compare(key,h->key)==0) {
                    R_B_Node<Key,Value> *x = min(h->right);
                    h->key = x->key;
                    h->val = x->val;
                    h->right = delete_min(h->right);
                }
                else {h->right = delete_key(h->right, key);}
            }
            return balance(h);
        }

        R_B_Node<Key,Value> *delete_min(R_B_Node<Key,Value> *h) { 
            if (h->left==NULL){return NULL;}
            if (!isRed(h->left)&&!isRed(h->left->left)){h=moveRedLeft(h);}
            h->left=delete_min(h->left);
            return balance(h);
        }

        R_B_Node<Key,Value> *delete_max(R_B_Node<Key,Value> *h) { 
            if (isRed(h->left)){h=rotateRight(h);}
            if (h->right==NULL){return NULL;}
            if (!isRed(h->right)&&!isRed(h->right->left)){h=moveRedRight(h);}
            h->right=delete_max(h->right);
            return balance(h);
        }

        int rank(Key key, R_B_Node<Key,Value> *x) {
            if (x==NULL) return 0; 
            int cmp=compare(key,x->key); 
            if (cmp<0) {return rank(key, x->left);} 
            else if (cmp > 0) {return 1+size(x->left)+rank(key,x->right);}
            else {return size(x->left);} 
        }

        R_B_Node<Key,Value> *min(R_B_Node<Key,Value> *x) { 
            if (x->left==NULL) {return x;} 
            else {return min(x->left);} 
        }

        R_B_Node<Key,Value> *max(R_B_Node<Key,Value> *x) { 
            if (x->right==NULL) {return x; }
            else{return max(x->right);} 
        }

        R_B_Node<Key,Value> *floor(R_B_Node<Key,Value> *x, Key key) {
            if (x==NULL) {return NULL;}
            int cmp=compare(key,x->key);
            if (cmp==0) {return x;}
            if (cmp<0)  {return floor(x->left, key);}
            R_B_Node<Key,Value> *t = floor(x->right, key);
            if (t!=NULL) {return t;} 
            else {return x;}
        }

        R_B_Node<Key,Value> *ceiling(R_B_Node<Key,Value> *x, Key key) {  
            if (x==NULL) return NULL;
            int cmp = compare(key,x->key);
            if (cmp==0) {return x;}
            if (cmp>0)  {return ceiling(x->right, key);}
            R_B_Node<Key,Value> *t = ceiling(x->left, key);
            if (t!=NULL) {return t;} 
            else {return x;}
        }

        Key *select(R_B_Node<Key,Value> *x, int rank) {
            if (x==NULL) return NULL;
            int leftSize = size(x->left);
            if (leftSize>rank) {return select(x->left,rank);}
            else if (leftSize<rank) {return select(x->right,rank-leftSize-1);} 
            else {return &x->key;}
        }

    public: 
        RedBlackBST(){this->root=NULL;}
        ~RedBlackBST(){
            visit=dispose;
            postoder(root);
            root=NULL;
        }
        RedBlackBST(const RedBlackBST<Key,Value> &)=delete;
        RedBlackBST<Key,Value> operator=(const RedBlackBST<Key,Value> &)=delete;

        void set_compare(int (*comp)(const Key &,const Key &)){
            compare=comp;
        }

        int size() {
            return size(root);
        }

        bool isEmpty() {
            return root==NULL;
        }

        Value *get(Key key) {
            return get(root, key);
        }

        bool contains(Key key) {
            return get(key) != NULL;
        }
    
        void put(Key key, Value val) {
            root=put(root, key, val);
            root->color=BLACK;
        }

        void delete_min() {
            if (isEmpty()) {return;}
            if (!isRed(root->left) && !isRed(root->right)){root->color = RED;}
            root = delete_min(root);
            if (!isEmpty()) root->color = BLACK;
        }

        void delete_max() {
            if (isEmpty()) return;
            if (!isRed(root->left) && !isRed(root->right)){root->color = RED;}
            root = delete_max(root);
            if (!isEmpty()) root->color =BLACK;
        }

        void delete_key(Key key) { 
            if (!contains(key)) return;
            if (!isRed(root->left)&&!isRed(root->right)){ root->color = RED;}
            root=delete_key(root, key);
            if (!isEmpty()) {root->color=BLACK;}
        }
    
        Key *min() {
            if (isEmpty()) return NULL;
            return &min(root)->key;
        } 

        Key *max() {
            if (isEmpty()) return NULL;
            return &max(root)->key;
        } 

        Key *floor(Key key) {
            if (isEmpty()) {return NULL;}
            R_B_Node<Key,Value> *x = floor(root, key);
            if (x == NULL) {return NULL;}
            else {return &x->key;}
        }    

        Key *ceiling(Key key) {
            if (isEmpty()) return NULL;
            R_B_Node<Key,Value> *x = ceiling(root, key);
            if (x==NULL) {return NULL;}
            else {return &x->key;}  
        }

        Key *select(int rank) {
            if (rank<0||rank>=size()) {return NULL;}
            return select(root, rank);
        }

        int rank(Key key) {
            return rank(key, root);
        } 

        void show(){
            for(int i=0;i<size();i++){
                cout<<"Key:"<<*(select(i))<<" value:"<<*(get(*select(i)))<<endl;
            }
        }

};

/*SeparateChainingHashST*/

template<typename Key,typename Value>
class separate_chain_hash{
    private:
        int cap=4;
        int n;                               
        int m;   
        sequential_search<Key,Value> *st;

        int hash_this(Key k){
            return (int)(hash_of_Key(k)%m);
        }

        void resize(int chains){
            separate_chain_hash<Key, Value> temp(chains);
            temp.set_hash(this->hash_of_Key);
            for (int i=0;i<m;i++) {
                for (Key key:st[i].keys()) {
                    temp.put(key,*st[i].get(key));
                }
            }
            this->m =temp.m;
            this->n =temp.n;
            delete [] st;st=new sequential_search<Key,Value> [m];
            std::copy(temp.st,(temp.st+m),st);
        }
    protected:  
        size_t (*hash_of_Key)(const Key &);

    public:
        separate_chain_hash(int m=4) {
            this->m=m;
            st = new sequential_search<Key,Value> [m];
            this->n=0;
        }

        ~separate_chain_hash(){
            delete [] st;
        }
        separate_chain_hash(const separate_chain_hash<Key,Value> & sep){
            n=sep.n;
            m=sep.m;
            cap=sep.cap;
            st=new sequential_search<Key,Value> [m];
            for(int i=0;i<m;i++){
                std::copy(sep.st,sep.st+m,st);
            }
        }

        separate_chain_hash &operator=(const separate_chain_hash<Key,Value> & sep){
            if(this==&sep){return *this;}
            delete [] st;
            n=sep.n;
            m=sep.m;
            cap=sep.cap;
            st=new sequential_search<Key,Value> [m];
            std::copy(sep.st,sep.st+m,st);
        };

        void set_hash(size_t (*hash)(const Key &)){
            hash_of_Key=hash;
        }

        int size() {
            return n;
        } 

        bool isEmpty() {
            return size()==0;
        }

        Value *get(Key key) {
            int i=hash_this(key);
            return st[i].get(key);
        } 

        bool contains(Key key) {
            return get(key)!=NULL;
        }

        void put(Key key, Value val) {
            if (n>=10*m){resize(2*m);}
            int i = hash_this(key);
            // cout<<i<<endl;
            if (!st[i].contains(key)) n++;
            st[i].put(key, val);
        } 

        void delete_key(Key key) {
            int i = hash_this(key);
            if (st[i].contains(key)) n--;
            st[i].delete_key(key);
            if (m>cap&&n<=2*m) {resize(m/2);}
        } 

        void show(){
            for(int i=0;i<m;i++){
                st[i].show();
            }
        }
};
template<typename Key>
size_t hash_std(const Key & s1){
    return std::hash<Key>()(s1);
}

template<typename Key,typename Value>
separate_chain_hash<Key,Value> sep_hash(int i=4){
    separate_chain_hash<Key,Value> s1(i);
    s1.set_hash(hash_std);
    return s1;
}
















 