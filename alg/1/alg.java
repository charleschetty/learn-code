import java.util.Comparator;
import java.util.Iterator;
import java.util.concurrent.PriorityBlockingQueue;
import java.math.BigInteger;
import java.util.Random;
import edu.princeton.cs.algs4.*;

public class alg {
    public static void show(Comparable[] a) {
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i]+" ");
        }
        System.out.println(" ");
    }

    public static void print(Object A){
        System.out.println(A);
    }
    public static void main(String[] argv){
        String[] j={"0","4","1","2","3","1","2","6","5","2","1"};
        String[] h={"0","1"};
        show(h);
        // System.out.println("");
        // show(j);
        // System.out.println("");
        // selectsort.sort(j);
        // shellsort.sort(j);
        // insertsort.sort(j);
        // mergesort.sort(j);
        // QuickSort1.sort3(j);
        maxpqsort.sort(h);
        // Heap.sort(h);
        show(h);
        // QuickSort1.sort(j);
        // String [] a={"a","b","c","d","d"};
        // squfind<String,Integer> thefind=new squfind();
        // baintresearch<String,Integer> bins=new baintresearch(10);
        // thefind.put("a",1);
        // thefind.put("a",2);

        // for (int i=0;i<a.length;i++){
            // thefind.put(a[i],i);
            // bins.put(a[i],i);
        // }
        // bins.show();
        // System.out.println(bins.get("a"));
        // thefind.show();
        // show(j);
        // System.out.println("");
        // BAG<Integer> a=new BAG();
        // for(int i=0;i<5;i++){
            // a.add(i);
        // }
        // for (int x:a){
            // System.out.println(x);
        // }
        // graph1 a=new graph1(3);
        // a.put(1,2);
        // a.show();
        // Graph a=new Graph(5);
        // a.addEdge(1, 2);
        // a.addEdge(0,1);
        // a.addEdge(2,3);
        // a.addEdge(1, 4);
        // a.addEdge(0, 4);
        // cc1 c1=new cc1(a);
        // print(c1.isconnected());
        // System.out.println(a);
        // depfs a1=new depfs(a,0);
        // bredfirtfs b1=new bredfirtfs(a, 0);
        // a1.showpathto(2);      
        // b1.showpathto(2);
        // cycle11 c1=new cycle11(a);
        // print(c1.hascycle());

        // Graph b=new Graph(4);
        // b.addEdge(0, 3);
        // b.addEdge(1, 2);
        // b.addEdge(0, 2);
        // b.addEdge(1, 3);
        // twocolor1 t1=new twocolor1(b);
        // print(t1.isbir());
        // digraph1 a1=new digraph1(5);
        // Digraph a1=new Digraph(5);
        // a1.addEdge(1, 2);
        // a1.addEdge(0,1);
        // a1.addEdge(2, 3);
        // a1.addEdge(1, 4);
        // a1.addEdge(0, 4);
        // a1.show();
        // Digraph h1=new Digraph(4);
        // h1.addEdge(0, 1);
        // h1.addEdge(1, 2);
        // h1.addEdge(2, 3);
        // h1.addEdge(3, 1);
        // Digraph thd=new Digraph(3);
        // thd.addEdge(0, 1);
        // thd.addEdge(1, 2);
        // thd.addEdge(2, 0);
        // dcc1 dcc=new dcc1(thd);
        // print(dcc.count());
        // dirextdfs1 d1=new dirextdfs1(h1, 1);
        // d1.show();
        // dircycy1 dd1=new dircycy1(h1);
        // print(dd1.hascycle());
        // dirextdfs1 dir=new dirextdfs1(a, S)
        // edge1 e1=new edge1(1, 2, 0.1);
        // print(e1);

        // EdgeWeightedGraph e3=new EdgeWeightedGraph(3);
        // // edweigra e3=new edweigra(3);
        // e3.addEdge(new Edge(0,1,0.1));
        // e3.addEdge(new Edge(1, 2, 0.2));
        // e3.addEdge(new Edge(2, 0, 0.3));
        // // e3.show();
        // // lazyprim laz=new lazyprim(e3);
        // // laz.show();
        
        // krusjkamst k11=new krusjkamst(e3);
        // k11.show();
        // EdgeWeightedDigraph e4=new EdgeWeightedDigraph(3);
        // e4.addEdge(new DirectedEdge(0, 1, 0.1));
        // e4.addEdge(new DirectedEdge(1, 2, 0.2));
        // e4.addEdge(new DirectedEdge(2, 0, 0.3));
        // dijkkasa das=new dijkkasa(e4, 0);
        // print(das.haspathto(2));
        // das.showpath(2);
        // // print(laz.pq.isEmpty());
        // String [] astr=new String[2];
        // astr[1]="hhh";
        // astr[0]="xxx";
        // lsd.shot(astr, 3);
        // msd.sort(astr);
        // quick3string.sort(astr);
        // print(astr[0]);
        // terst<Integer> ts=new terst();
        // ts.put("key", 0);
        // ts.put("kehhy", 1);
        // print(ts.get("keey"));
        // print(ts.size());
        // for(String s:ts.keys()){
        //     print(s);
        // }
        // print(ts.longestper("key2"));
        String aa="abcdef";
        String pat="bcd";
        print(seartxt1.search2(pat, aa));
        kmp k1=new kmp(pat);
        print(k1.search(aa));
        nyporm n1=new nyporm(pat);
        print(n1.search(aa));
    }    
}

class sortclass{
    public static boolean less (Comparable v, Comparable w){
        return v.compareTo(w)<0;
    }

    public static void exch(Comparable[] a,int i,int j){
        Comparable t=a[i];
        a[i]=a[j];
        a[j]=t;
    }

    public static void show(Comparable[] a) {
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i]+" ");
        }
    }
}

class selectsort extends sortclass{
    public static int slelsct_find_min(Comparable [] a,int i, int j) {
        int min=i;
        for (int k=i;k<j;k++){
            if (less(a[k],a[min])){
                min=k;
            }
        }
        return min;
    }
    public static void sort(Comparable [] a) {
        int alen=a.length;
        for (int i=0;i<alen;i++){
            exch(a,i,slelsct_find_min(a, i, alen));
        }
   }
}

class insertsort extends sortclass{
    public static void sort(Comparable[] a){
        for (int i =1;i<a.length;i++){
            for (int j=i;j>0&&less(a[j],a[j-1]);j--){
                exch(a,j,j-1);
            }
        }
    }
}

class shellsort extends sortclass{
    public static void sort(Comparable[] a){
        int h=1;
        while(h<(a.length/3)){
            h=h*3+1;
        }
        while (h>=1){
            for (int i =h;i<a.length;i++){
                for (int j=i;j>=h&&less(a[j],a[j-h]);j-=h){
                    exch(a,j,j-h);
                }
            }
            h=h/3;
        }
    }
}
class mergesort extends sortclass{
    public static Comparable [] auk;

    public static void sort(Comparable[] a){ 
        auk = new Comparable[a.length];    // 一次性分配空间 
        sort(a, 0, a.length - 1); 
    }

    public static void sort(Comparable[] a,int begin,int end){
        if(end<=begin)return;
        int median=begin+(end - begin)/2;
        sort(a,begin,median);
        sort(a,median+1,end);
        mergeone(a,begin,median,end);

    }

    public static void mergeone(Comparable[] a,int l, int med,int r){
        int thebegin=l;
        int themedian=med+1;
        for(int k=l;k<=r;k++){
            auk[k]=a[k];
        }
        for (int i=l;i<=r;i++){
            if(thebegin>med) a[i]=a[themedian++];
            else if (themedian>r) a[i]=auk[thebegin++];
            else if(less(auk[themedian],auk[thebegin])) a[i]=auk[themedian++];
            else a[i]=auk[thebegin++];
        }

    }
}

class QuickSort1 extends sortclass{
    public static int partition(Comparable[] a,int lo, int hi){
        int i=lo,j=hi+1;
        Comparable v= a[lo];
        while (true){
            while(less(a[++i],v)) if (i==hi) break;
            while(less(v,a[--j])) if (j==lo) break;
            if(i>=j) break;
            exch(a,i,j);
        }
        exch(a,lo,j);
        return j;
    }
    public static void sort(Comparable[] a){
        StdRandom.shuffle(a);
        sort(a,0,a.length-1);
    }

    public static void sort(Comparable[] a,int lo,int hi){
        if(hi<=lo) return;
        int j= partition(a, lo, hi);
        sort(a,lo,j-1);
        sort(a,j+1,hi);
    }

    public static void sort3(Comparable[] a){
        StdRandom.shuffle(a);
        sort(a,0,a.length-1);
    }

    public static void sort3(Comparable[] a, int lo, int hi) {
        if (hi <= lo) return; 
        int lt = lo, i = lo+1, gt = hi; 
        Comparable v = a[lo]; 
        while (i <= gt) 
        { 
             int cmp = a[i].compareTo(v); 
             if      (cmp < 0) exch(a, lt++, i++); 
             else if (cmp > 0) exch(a, i, gt--); 
             else              i++; 
        }   
        sort(a, lo, lt - 1); 
        sort(a, gt + 1, hi); 
   } 
}

class maxpqsort{
    private static boolean less(Comparable[] pq, int i, int j) {
        return pq[i-1].compareTo(pq[j-1]) < 0;
    }

    private static void exch(Object[] pq, int i, int j) {
        Object swap = pq[i-1];
        pq[i-1] = pq[j-1];
        pq[j-1] = swap;
    }
    public static void sort(Comparable[] pq) {
        int n = pq.length;

        for (int k = n/2; k >= 1; k--)
            sink(pq, k, n);

        int k = n;
        while (k > 1) {
            exch(pq, 1, k--);
            sink(pq, 1, k);
        }
    }
    private static void sink(Comparable[] pq, int k, int n) {
        while (2*k <= n) {
            int j = 2*k;
            if (j < n && less(pq, j, j+1)) j++;
            if (!less(pq, k, j)) break;
            exch(pq, k, j);
            k = j;
        }
    }

} 

class MaxPQ1<Key extends Comparable<Key>>{
    public Key[] pq;
    public int N=0;

    public MaxPQ1(int manx){
        pq=(Key []) new Comparator[manx+1];
    }

    public boolean isEmpty() {
        return N==0;
    }

    public int size() {
        return  N;
    }
    public boolean less(int i ,int j){
        return pq[i].compareTo(pq[j])<0;
    }

    public void exch(int i, int j){
        Key t=pq[i];pq[i]=pq[j];pq[j]=t;
    }

    public void swim(int k){
        while(k>1&&less(k/2,k)){
            exch(k,k/2);
            k=k/2;
        }
    }

    public void sink(int k){
        while (2*k<=N){
            int j=2*k;
            if(j<N&&less(j,j+1)) j++;
            if(!less(k,j)) break;
            exch(k,j);
            k=j;
        }
    }

    public void insert(Key v){
        pq[++N]=v;
        swim(N);
    }
    
    public Key delMax(){
        Key max=pq[1];
        exch(1,N--);
        sink(1);
        return max;
    }


}

class squfind<Key,value>{
    public Node first;
    public  class Node {
       public Key key;
       public value val;
       public Node next;
       
       public Node(Key k,value v,Node next){
           this.next=next;
           this.val=v;
           this.key=k;
       }
    }

    public value get(Key k){
        for (Node x = first; x != null; x = x.next){
            if (k.equals(x.key))
            return x.val;    
        }
        return null;           
    }

    public void put(Key k,value val){
        for (Node x=first;x!=null;x=x.next){
            if (x.key==k)
            {x.val=val;return;}   
        }
        first=new Node(k,val,first);
    }
    
    public void show(){
        for(Node x=first; x!=null;x=x.next){
            String s="key:"+x.key.toString()+" value:"+x.val.toString();
            System.out.println(s);
        }
    }
}


class baintresearch<Key extends Comparable<Key>,value>{
    public Key [] key;
    public value[] val;
    public int N;

    public baintresearch(int N){
        key=(Key []) new Comparable[N];
        val= (value []) new Object[N];

    }

    public int size(){
        return N;
    }

    public int rank(Key k){
        int lo=0;int hi=N-1;
        while (lo<=hi){
            int themide=lo+(hi-lo)/2;
            int cmp=k.compareTo(key[themide]);
            if(cmp<0) hi=themide-1;
            else if(cmp>0) lo=themide+1;
            else return themide;
        }
        return lo;        
    }

    public boolean isEmpty(){
        return N==0;
    }

    public value get(Key k){
        int i=rank(k);
        if(isEmpty()) return null;
        else if(key[i].compareTo(k)==0) return val[i];
        else return null;
    } 

    public void put(Key k,value val){
        if(isEmpty()){
            key[0]=k;
            this.val[0]=val;
            N++;
            return;
        }
        int i=rank(k);
        if(i<N&&key[i].compareTo(k)==0){
            this.val[i]=val;
            return;
        }
        for(int j=N;j>i;j--){
            key[j]=key[j-1];this.val[j]=this.val[j-1];
        }
        key[i]=k; this.val[i]=val;
        N++;
    }

    public void show(){
        for(int i=0;key[i]!=null;i++){
            String s="key:"+key[i].toString()+" value:"+val[i].toString();
            System.out.println(s);
        }
    }
}

class bst<Key extends Comparable<Key>,value>{
    public Node root;
    public class Node{
        Key key;
        value val;
        Node left,right;
        int N;

        public Node(Key key,value val,int N){
            this.val=val;
            this.key=key;
            this.N=N;
        }
    }

    public int size(Node x){
        if(x ==null) return 0;
        else return x.N;
    }

    public int size(){
        return size(root);
    }

    public value get(Key key){  
        return get(root, key);  
    } 
    public value get(Node x, Key key){
        if (x == null) return null; 
        int cmp = key.compareTo(x.key);
        if      (cmp < 0) return get(x.left, key); 
        else if (cmp > 0) return get(x.right, key); 
        else return x.val; 
    }

    public void put(Key k,value v){
        root=put(root,k,v);
    }

    public Node put(Node node,Key k,value v){
        if(node==null) return new Node(k,v,1);    
        int cmp=node.key.compareTo(k);
        if(cmp<0) node.left = put(node.left,k,v);
        else if (cmp>0) node .right=put(node.right,k,v);
        else node.val=v;
        node.N=size(node.left)+size(node.right)+1;
        return node;
   } 

   public Node min(){
       return min(root);
   }

   public Node min(Node thnode){
       if(thnode.left==null)  return thnode;
       else return min(thnode.left);
   }

   public Node max(){
       return max(root);
   }

   public Node max(Node thnode){
       if(thnode.right==null) return thnode;
       else return max(thnode.right);
   }

   public Node floor(Key key){
       return floor(root,key);
   }

   public Node floor(Node thnode, Key key){
       if(thnode==null) return null;
       int cmp=thnode.key.compareTo(key);
       if(cmp==0) return thnode;
       else if(cmp<0) return floor(thnode.left, key);
       Node cmpnode=floor(thnode.right, key);
       if(cmpnode==null) return thnode;
       else return cmpnode;
   }

   public Key select(int k){
       return select(root,k).key;
   }

   public Node select(Node thnode,int k){
       if (thnode==null) return null;
       int cmp=size(thnode);
       if(cmp>k) return select(thnode.left, k);
       else if(cmp<k) return select(thnode.right, cmp-k-1);
       else return thnode;
   }

   public int rank(Key k){
       return rank(k,root);
   }

   public int rank(Key k,Node thenode){
       if (thenode==null) return 0;
       int cmp=thenode.key.compareTo(k);
       if(cmp>0) return rank(k, thenode.left);
       else if(cmp>0) return rank(k, thenode.right)+size(thenode)+1;
       else return rank(k, thenode);
   }
   public void deletemin(){
       root=deletemin(root);
   }

   public Node deletemin(Node thenode){
       if(thenode.left==null) return thenode.right;
       thenode.left=deletemin(thenode.left);
       thenode.N=size(thenode.left)+size(thenode.right)+1;
       return thenode;
   }

   public void delete(Key key){  
       root = delete(root, key);  
    }

    public Node delete(Node x, Key key) { 
        if (x == null) return null; 
        int cmp = key.compareTo(x.key); 
        if      (cmp < 0) x.left  = delete(x.left,  key); 
        else if (cmp > 0) x.right = delete(x.right, key); 
        else{ 
            if (x.right == null) return x.left; 
            if (x.left == null) return x.right; 
            Node t = x; 
            x = min(t.right);   
            x.right = deletemin(t.right); 
            x.left = t.left; 
        } 

        x.N = size(x.left) + size(x.right) + 1; 
        return x; 
    }

}

class redandblack<Key extends Comparable<Key>,value>{
    private static final boolean RED=true;
    private static final boolean BLACK=false;

    public Node root;

    public class Node{
        public int N;
        public boolean color;
        public Key k;
        public value val;
        public Node left;
        public Node right;

        Node(int N,boolean red,Key k,value v){
            this.N=N;
            this.k=k;
            this.val=v;
            this.color=red;
        }
    }

    public boolean isred(Node thnode){
        if (thnode==null) return false;
        return thnode.color==RED;
    }

    public int size(Node thenode){
        if(thenode==null) return 0;
        else return thenode.N;
    }

    public int size(){
        return size(root);
    }

    public Node roteleft(Node h){
        Node x=h.right;
        h.right=x.left;
        x.left=h;
        x.color=h.color;
        h.color=RED;
        x.N=h.N;
        h.N=1+size(h.left)+size(h.right)+1;
        return x;
    }

    public Node roteright(Node h){
        Node x=h.left;
        h.left=x.right;
        x.right=h;
        x.color=h.color;
        h.color=RED;
        x.N=h.N;
        h.N=1+size(h.left)+size(h.right)+1;
        return x;
    }
    
    public void flapolor(Node X){
        X.color=RED;
        X.left.color=BLACK;
        X.right.color=BLACK;
    }
    
    public void put(Key k,value val){
        root=put(root, k, val); 
        root.color=BLACK;
    }

    public Node put(Node X,Key k,value val){
        if(X==null) return new Node(1,RED,k,val);
        int cmp=k.compareTo(X.k);
        if (cmp<0) X.left=put(X.left, k, val);
        else if(cmp>0) X.right=put(X.right, k, val);
        else X.val=val;     
        
        if(isred(X.right)&&!isred(X.left)) X=roteleft(X);
        if(isred(X.left)&&isred(X.left.left)) X=roteleft(X);
        if(isred(X.left)&&isred(X.right)) flapolor(X);
        X.N=size(X.left)+size(X.right)+1;
        return X;
    }
}

class BAG<ITEM> implements Iterable<ITEM>{
    public class Node{
        ITEM iteml;
        Node next;
    }

    public Node first;

    public void add(ITEM it){
        Node oldnode=first;
        first=new Node();
        first.iteml=it;
        first.next=oldnode;
    }

    public Iterator<ITEM> iterator() {
        return new LISTITER();
    }

    public class LISTITER implements Iterator<ITEM>{
        public Node current=first;
        public boolean hasNext(){
            return current!=null;
        }
        public void remove(){}
        public ITEM next(){
            ITEM item=current.iteml;
            current=current.next;
            return item;
        }
    }
}


class seqsearchhash<Key,Item>{
    public int N;
    public int M;
    public SequentialSearchST<Key,Item>[] st;

    public seqsearchhash(){
        this(997);
    }

    public seqsearchhash(int M){
        this.M=M;
        st=(SequentialSearchST<Key,Item> []) new SequentialSearchST[M];
        for(int i=0;i<M;i++){
            st[i]=new SequentialSearchST<>();
        }
    }

    public int hash(Key k){
     return (k.hashCode() & 0x7fffffff) % M; 
    }

    public Item get(Key k){
        return (Item) st[hash(k)].get(k);
    }

    public void put(Key k,Item it){
        st[hash(k)].put(k, it);
    }
}

class hashper<KEY,ITEM>{
    public int N;
    public int M=16;
    public KEY[] key;
    public ITEM[] item;

    public hashper(int M){
        this.M=M;
        key=(KEY []) new Object[M];
        item=(ITEM[]) new Object[M];
    }

    public int hash(KEY k){
     return (k.hashCode() & 0x7fffffff) % M; 
    }

    public void put(KEY k,ITEM items){
        if(2*N>M) resize(2*M);
        int i;
        for(i=hash(k);key[i]!=null;i=(i+1)%M){
            if(key[i].equals(k)){item[i]=items;}
        }
        key[i]=k;
        item[i]=items;
        N++;
    }

    public void resize(int cap){
        hashper<KEY,ITEM> t=new hashper(cap);
        for (int i=0;i<M;i++){
            if(key[i]!=null) t.put(key[i], item[i]);
        }
        this.key=t.key;
        this.M=t.M;
        this.item=t.item;
    }

    public ITEM get(KEY k){
        for(int i=hash(k);key[i]!=null;i=(i+1)%M){
            if(key[i].equals(k)) return item[i];
        }
        return null;
    }

    public boolean contains(KEY K){
        if(get(K)==null) return false;
        else return true;
    }

    public void delete(KEY k){
        if(!contains(k)) return ;
        int i=hash(k);
        while(!k.equals(key[i])){
            i=(i+1)%M;
        }
        key[i]=null;item[i]=null;
        i = (i + 1) % M; 
        while (key[i] != null){ 
            KEY keyToRedo = key[i]; 
            ITEM valToRedo = item[i]; 
            key[i] = null; 
            item[i] = null; 
            N--;   
            put(keyToRedo, valToRedo); 
            i = (i + 1) % M; 
        } 
        N--;    
        if (N > 0 && N == M/8) resize(M/2); 
    }
}



class graph1{
    public int V;
    public int E;
    public Bag<Integer> [] adj;
    
    public graph1(int v){
        this.V=v;
        this.E=0;
        adj=(Bag<Integer> []) new Bag[v];
        for(int i=0;i<v;i++){
            adj[i]=new Bag<Integer>();
        }
    }

    public graph1(In in){ 
        this(in.readInt());          
        int E = in.readInt();        
        for (int i = 0; i < E; i++){  
            int v = in.readInt();        
            int w = in.readInt();        
            put(v, w);
        }
    }    

    public int edge(){
        return E;
    }

    public int verctor(){
        return V;
    }

    public void put(int i,int j){
        adj[i].add(j);
        adj[j].add(i);
        E++;
    }

    public Iterable<Integer> adj(int v){
        return adj[v];
    }

    public void show(){
        for (int i=0;i<V;i++){
            String str="";
            for(int j:adj[i]){
                str+=j;
                str+=" ";
            }
            System.out.println(i+":"+str);
        }
    }

}

class xfs1{
    public boolean[] marked ;
    public int [] edgeto;
    public int s;

    public boolean haspaath(int v){
        return marked[v];
    }

    public Iterable<Integer> pathto(int v){
        Stack<Integer> path=thpath(v);
        return path;
    }

    public Stack<Integer> thpath(int v){
        if(!haspaath(v)) return null;
        Stack<Integer> path=new Stack<Integer>();
        for(int x=v;x!=s;x=edgeto[x]){
            path.push(x);
        }
        path.push(s);
        return path;
    }

    public void showpathto(int v){
        if(!haspaath(v)) return;
        Stack<Integer> path=thpath(v);
        int a=path.size();
        String str="";
        for(int w=0;w<a-1;w++){
            str=str+path.pop()+"->";
        }
        str=str+path.pop();
        System.out.println(str);
    }
}

class depfs extends xfs1{
    public depfs(Graph G,int v){
        marked=new boolean[G.V()];
        edgeto =new int[G.V()];
        this.s=s;
        dfs(G,v);
    }

    public void dfs(Graph G,int v){
        marked[v]=true;
        for(int w:G.adj(v)){
            if(!marked[w]){
                edgeto[w]=v;
                dfs(G,w);
            }
        }
    }

}


class bredfirtfs extends xfs1{
    public bredfirtfs(Graph g,int s){
        marked=new boolean[g.V()];
        this.s=s;
        edgeto=new int[g.V()];
        bsf(g,s);
        // bfs1(g,s);
    }

    public void bsf(Graph g,int v){
        Queue<Integer> AUEUE=new Queue<Integer>();
        marked[v]=true;
        AUEUE.enqueue(v);
        
        while(!AUEUE.isEmpty()){
            int c=AUEUE.dequeue();
            for(int w:g.adj(c)){
                if(!marked[w]){
                    edgeto[w]=c;
                    marked[w]=true;
                    AUEUE.enqueue(w);
                }
            }
        }
    }
}


class cycle11{
    public boolean[] marked;
    public boolean hascycle;

    public cycle11(Graph g){
        marked=new boolean[g.V()];
        hascycle=false;
        for(int i=0;i<g.V();i++){
            if(!marked[i]){
                dfs1(g, i, i);
            }
        }
    }

    public void dfs1(Graph g,int v,int u){
        marked[v]=true;
        for(int w:g.adj(v)){
            if(!marked[w]){
                dfs1(g, w, v);
            }
            else if(w!=u) hascycle=true;
        }
    }

    public boolean hascycle(){
        return hascycle;
    }
}



class twocolor1{
    public boolean[] marked;
    public boolean [] color;
    public boolean istc=true;

    public twocolor1(Graph g){
        marked=new boolean[g.V()];
        color =new boolean[g.V()];
        for(int i=0;i<g.V();i++){
            if(!marked[i]){

            }
        }
    }

    public void dfs1(Graph g,int v){
        marked[v]=true;
        for(int i:g.adj(v)){
            if (!marked[i]) 
            { 
                color[i] = !color[v]; 
                dfs1(g, v); 
            } 
            else if (color[i] == color[v]) 
                istc = false; 
        }
    }

    public boolean isbir(){
        return istc;
    }
}

class digraph1{
    public int v;
    public int E;
    public Bag<Integer>[] adj;

    public digraph1(int v){
        this.v=v;
        this.E=0;
        adj=(Bag<Integer>[]) new Bag[v];
        for(int i=0;i<v;i++){
            adj[i]=new Bag<Integer>();
        }
    }

    public void addedge(int v,int u){
        adj[v].add(u);
        E++;
    }

    public Iterable<Integer> adj(int v){
        return adj[v];
    }

    public digraph1 reverse(){
        digraph1 r=new digraph1(v);
        for(int i=0;i<v;i++)
        {
            for(int u:adj[v]){
                r.addedge(u, v);
            }
        }
        return r;
    }

    public void show(){
        for (int i=0;i<v;i++){
            String str="";
            for(int j:adj[i]){
                str+=i;
                str+="->";
                str+=j;
                str+=" ";
            }
            System.out.println(i+":"+str);
        }
    }
}

class dirextdfs1{
    public boolean [] marked;
   
    public dirextdfs1(Digraph g,int s){
        marked=new boolean[g.V()];
        dfs(g,s);
    }

    public dirextdfs1(Digraph g,Iterable<Integer> S){
        marked=new boolean[g.V()];
        for(int i:S){
            if(!marked[i])  dfs(g, i);
        }
    }

    public void dfs(Digraph g,int v){
        marked[v]=true;
        for(int i:g.adj(v)){
            if(!marked[i]) dfs(g, i);
        }
    }

    public boolean ismarked(int v){
        return marked[v];

    }

    public void show(){
        String s="";
        int stat=0;
        for(int i=0;i<marked.length;i++){
            if(marked[i]){
                s+="point:";s+=i;s+=" ";
                if(stat==0){
                    s+="-> ";stat=1;
                }
            }
        }
        System.out.println(s);
    }


}

class thecc{
    public boolean[] marked;
    public int[] id;
    public int count;


    public int id(int v){
        return id[v];
    }

    public int count(){
        return count;
    }

}
class cc1 extends thecc{
    public cc1(Graph g){
        marked=new boolean[g.V()];
        id=new int [g.V()];
        count=0;
        for(int i=0;i<g.V();i++){
            if(!marked[i]){
                dfs(g, i);
                count++;
            }
        }
    }

    public void dfs(Graph g,int v){
        marked[v]=true;
        id[v]=count;
        for(int i:g.adj(v)){
            if(!marked[i]){
                dfs(g, i);
            }
        }
    }

    public boolean connetc(int v,int u){
        return id[v]==id[u];
    }
    public boolean isconnected(){
        return count==1;
    }
}

class dcc1 extends thecc{
    public dcc1(Digraph g){
        marked=new boolean[g.V()];
        id=new int [g.V()];
        DepthFirstOrder order=new DepthFirstOrder(g.reverse());
        count=0;
        for(int i:order.reversePost()){
            if(!marked[i]){
                dfs(g, i);
                count++;
            }
        }
    }
    public void dfs(Digraph g,int v){
        marked[v]=true;
        id[v]=count;
        for(int i:g.adj(v)){
            if(!marked[i]){
                dfs(g, i);
            }
        }
    }
    public boolean connetc(int v,int u){
        return id[v]==id[u];
    }
    public boolean isconnected(){
        return count==1;
    }
}
class dircycy1{
    public boolean [] marked;
    public int [] edgeto;
    public Stack<Integer> cycle;
    public boolean[] onstack;

    public dircycy1(Digraph d){
        onstack=new boolean[d.V()];
        marked=new boolean[d.V()];
        edgeto=new int [d.V()];
        for(int i=0;i<d.V();i++){
            if(!marked[i]) dfs(d, i);
        }
    }   
    
    public void dfs(Digraph g,int v){
        onstack[v]=true;
        marked[v]=true;
        for(int i:g.adj(v)){
            if(!marked[i]){
                edgeto[i]=v;dfs(g, i);
            }
            else if(this.hascycle()) return;
            else if(onstack[i]){
                cycle=new Stack<Integer>();
                for(int z=v;z!=i;z=edgeto[z]){
                    cycle.push(z);
                }
                cycle.push(i);
                cycle.push(v);
            }
        }    
        onstack[v]=false;   
    }

    public boolean hascycle(){
        return cycle!=null;
    }


    public Iterable<Integer> cycle(){
        return cycle;
    }

}

class depfits1{
    public boolean[] marked;
    public Queue<Integer> post;
    public Queue<Integer> pre;
    public Stack<Integer> reverpost;

    public depfits1(Digraph d1){
        pre=new Queue<Integer>();
        post=new Queue<Integer>() ;
        reverpost=new Stack<Integer>();
        marked=new boolean[d1.V()];
        for(int i=0;i<d1.V();i++){
            if(!marked[i]) dfs(d1, i);
        }
    }

    public void dfs(Digraph d1,int v){
        pre.enqueue(v);
        marked[v]=true;
        for(int w:d1.adj(v)){
            if(!marked[w]){
                dfs(d1,w);
            }
        }
        post.enqueue(v);
        reverpost.push(v);     
    }

    public Iterable<Integer> pre(){
        return pre;
    }


    public Iterable<Integer> post(){
        return post;
    }


    public Iterable<Integer> reverpost(){
        return reverpost;
    }
}

class topiclal{
    public Iterable<Integer> order;
    public topiclal(Digraph d1){
        DirectedCycle cyc=new DirectedCycle(d1);
        if(!cyc.hasCycle()){
            DepthFirstOrder dfs=new DepthFirstOrder(d1);
            order=dfs.reversePost();
        }
    }

    public Iterable<Integer> order(){
        return order;
    }

    public boolean isdag(){
        return order!=null;
    }
}

class edge1 implements Comparable<edge1>{
    public int v;
    public int w;
    public double wei;

    public edge1(int v,int w,double wei){
        this.v=v;
        this.w=w;
        this.wei=wei;
    }

    public double weight(){
        return wei;
    }


    public int either(){
        return v;
    }

    public int other(int verc){
        if(verc==v) return w;
        else if(verc==w) return v;
        else throw new RuntimeException("error");
    }

    public int compareTo(edge1 that){
        if(this.wei<that.wei) return -1;
        else if(this.wei>that.wei) return 1;
        else return 0;
    }

    public String toString(){
        String s="";
        s+=v;s+=" -> ";s+=w;s+=" weight: ";s+=wei;
        return s;
    }

}

class edweigra{
    public int v;
    public int E;
    public Bag<edge1>[] adj;

    public edweigra(int v){
        this.v=v;
        this.E=0;
        adj=(Bag<edge1>[]) new Bag[v];
        for(int j=0;j<v;j++){
            adj[j]=new Bag<edge1>();
        }
    }

    public int V(){return v;}
    public int E() {return E;}

    public void addedge(edge1 e){
        int v=e.either(),w=e.other(v);
        adj[v].add(e);
        adj[w].add(e);
        E++;
    }

    public Iterable<edge1> adj(int v){
        return adj[v];
    }

    public void show(){
        for (int i=0;i<v;i++){
            System.out.println(i+" : ");
            for(edge1 e:adj[i]){
                System.out.println(e+" ");
            }
        }
    }
}

class lazyprim{
    public boolean [] marked;
    public Queue<edge1> mst;
    public MinPQ<edge1> pq;

    public lazyprim(edweigra G){
        pq=new MinPQ<edge1>();
        mst=new Queue<edge1>();
        marked=new boolean[G.V()];

        visit(G, 0);
        while(!pq.isEmpty()){
            edge1 e=pq.delMin();
            // System.out.println("ex");
            int v=e.either(),w=e.other(v);
            if(marked[v]&&marked[w]) continue;
            mst.enqueue(e);
            if(!marked[v]) visit(G, v);
            if(!marked[w]) visit(G, w);
        }
    }

    public void visit(edweigra g,int v){
        // System.out.println(v);
        marked[v]=true;
        for(edge1 e:g.adj(v)){
            if(!marked[e.other(v)]) pq.insert(e);
        }
    }

    public Iterable<edge1> edgeas(){
        return mst;
    }

    public void show(){
        for(edge1 e:mst){
            System.out.println(e);
        }
    }
}

class krusjkamst{
    public Queue<Edge> mst;

    public krusjkamst(EdgeWeightedGraph g1){
        mst=new Queue<Edge>();
        MinPQ<Edge> pq=new MinPQ<Edge>();
        for(Edge w:g1.edges()){
            pq.insert(w);
        }
        UF uf=new UF(g1.V());

        while(!pq.isEmpty()&&mst.size()<g1.V()-1){
            Edge e=pq.delMin();
            int v=e.either(),w=e.other(v);
            if(uf.connected(v, w)) continue;
            uf.union(v, w);
            mst.enqueue(e);
        }
    }

    public Iterable<Edge> EDGES(){
        return mst;
    }

    public void show(){
        for(Edge e:mst){
            System.out.println(e);
        }
    }
}


class dijkkasa{
    public DirectedEdge[] edgeto;
    public double [] distto;
    public IndexMinPQ<Double> pq;

    public dijkkasa (EdgeWeightedDigraph g,int s){
        edgeto=(DirectedEdge[]) new DirectedEdge[g.V()];
        distto =new double[g.V()];
        pq = new IndexMinPQ<Double>(g.V());

        for(int i=0;i<g.V();i++){
           distto[i]=Double.POSITIVE_INFINITY;
        } 

        distto[0]=0.0;
        pq.insert(s, 0.0);
        while(!pq.isEmpty()){
            relex(g,pq.delMin());
        }
    }



    public void relex(DirectedEdge e){
        int v=e.from(),w=e.to();
        if(distto[w]>distto[v]+e.weight()){
            distto[w]=distto[v]+e.weight();
            edgeto[w]=e;
        }
    }

    public void relex(EdgeWeightedDigraph g,int v){
        for(DirectedEdge e:g.adj(v)){
            int w=e.to();
            if(distto[w]>distto[v]+e.weight()){
                distto[w]=distto[v]+e.weight();
                edgeto[w]=e;
                if(pq.contains(w)) pq.change(w, distto[w]);
                else pq.insert(w, distto[w]);
            }
        }
    }

    public double distto(int v){
        return distto[v];
    }    


    public boolean haspathto(int v){
        return distto[v]<Double.POSITIVE_INFINITY;
    }

    public Iterable<DirectedEdge> pathto(int v){
        if(!haspathto(v)) return null;
        Stack<DirectedEdge> path=new Stack<DirectedEdge>();
        for(DirectedEdge e=edgeto[v];e!=null;e=edgeto[e.from()]){
            path.push(e);
        }

        return path;
    }

    public void showpath(int v){
        Iterable<DirectedEdge> dir=this.pathto(v);
        for(DirectedEdge e:dir){
            System.out.println(e);
        }
    }

}


class bellmanforedsp1{
    public double[] distto;
    public DirectedEdge[] edgeto;
    public boolean[] onQ;
    public Queue<Integer> queue;
    public int cost;
    public Iterable<DirectedEdge> cycle;

    public bellmanforedsp1(EdgeWeightedDigraph g,int s){
        distto=new double[g.V()];
        edgeto=(DirectedEdge[]) new DirectedEdge[g.V()];
        onQ=new boolean[g.V()];
        queue=new Queue<Integer>();

        for(int v=0;v<g.V();v++){
            distto[v]=Double.POSITIVE_INFINITY;
        }
        distto[s]=0.0;
        queue.enqueue(s);
        onQ[s]=true;
        while(!queue.isEmpty()&&!hasnecyc()){
            int v=queue.dequeue();
            onQ[v]=false;
            relax(g, v);
        }
    }

    public void relax(EdgeWeightedDigraph g,int v){
        for(DirectedEdge e:g.adj(v)){
            int w=e.to();
            if(distto[w]>distto[v]+e.weight()){
                distto[w]= distto[v]+e.weight();
                edgeto[w]=e;
                if(!onQ[w]){
                    queue.enqueue(w);
                    onQ[w]=true;
                }
            }
            if(cost++%g.V()==0){
                findneight();
            }
        }
    }

    public void findneight(){
        int V=edgeto.length;
        EdgeWeightedDigraph spt;
        spt=new EdgeWeightedDigraph(V);
        for(int v=0;v<V;v++){
            if(edgeto[v]!=null) spt.addEdge(edgeto[v]);
        }
       EdgeWeightedDirectedCycle cf;
       cf=new EdgeWeightedDirectedCycle(spt) ;
       cycle=cf.cycle();
    }

    public boolean hasnecyc(){
        return cycle!=null;
    }

    public Iterable<DirectedEdge> negacticyc(){
        return cycle;
    }
}


class lsd{
    public static void shot(String [] a,int w){
        int N =a.length;
        int R =256;
        String [] aux=new String[N];
        for(int d=w-1;d>=0;d--){
            int count[] =new int [R+1];
            for(int i=0;i<N;i++){
                count[a[i].charAt(d)+1]++;
            }
            for(int r =0;r<R;r++){
                count[r+1]+=count[r];
            }
            for(int i=0;i<N;i++){
                aux[count[a[i].charAt(d)]++]=a[i];
            }
            for(int i=0;i<N;i++){
                a[i]=aux[i];
            }
        }
    }

}

class sortchar{
    public static void exch(String[] a, int i, int j) {
        String temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    public static boolean less(String v, String w, int d) {
        for (int i = d; i < Math.min(v.length(), w.length()); i++) {
            if (v.charAt(i) < w.charAt(i)) return true;
            if (v.charAt(i) > w.charAt(i)) return false;
        }
        return v.length() < w.length();
    }

    public static int charat(String s,int d){
        if(d<s.length()){
            return s.charAt(d);
        }
        else{
            return -1;
        }
    }
}

class msd extends sortchar{
    private static int R=256;
    private static final int M=15;
    private static String [] aux;

    public static void sort(String [] a){
        int N=a.length;
        aux=new String[N];
        sort(a,0,N-1,0);
    }

    public static void sort(String[] a,int lo,int hi, int d){
        if(hi<lo+M){
            insertion(a, lo, hi ,d);
            return;
        }

        int [] count=new int[R+2];
        for(int i=lo;i<=hi;i++){
            count[charat(a[i], d)+2]++;
        }

        for(int r=0;r<R+1;r++){
            count[r+1]=count[r];
        }

        for(int i=lo;i<=hi;i++){
            aux[count[charat(a[i], d)+1]++]=a[i];
        }

        for(int i=lo;i<=hi;i++){
            a[i]=aux[i-lo];
        }

        for(int r=0;r<R;r++){
            sort(a,lo+count[r],lo+count[r+1],d+1);
        }

    }

    public static void insertion(String[] a, int lo, int hi, int d) {
        for (int i = lo; i <= hi; i++)
            for (int j = i; j > lo && less(a[j], a[j-1], d); j--)
                exch(a, j, j-1);
    }
}

class quick3string extends sortchar{
    public static void sort(String[] a){
        sort(a,0,a.length-1,0);
    }

    public static void sort(String [] a,int lo, int hi, int d){
        if(hi<=lo) return;
        int lt=lo,gt=hi;
        int v=charat(a[lo], d);
        int i=lo+1;

        while(i<=gt){
            int t=charat(a[i], d);
            if(t<v) exch(a, lt++, i++);
            else if(t>v) exch(a, i, gt--);
            else i++;
        }

        sort(a,lo,lt-1,d);
        if(v>=0) sort(a,lt,gt,d+1);
        sort(a,gt+1,hi,d);
    }
}


class terst<value>{
    private static int R=256;
    private Node root;

    private static class Node{
        private Object val;
        private Node[] next=new Node[R];
    }

    public value get(String key){
        Node x=get(root,key,0);
        if(x==null) return null;
        return (value) x.val;
    }

    public Node get(Node x,String k,int d){
        if(x==null) return null;
        if(d==k.length()) return x;
        char c=k.charAt(d);
        return get (x.next[c],k,d+1);
    }

    public void put(String key,value val){
        root=put(root, key, val, 0);
    }

    public Node put(Node x,String key,value val,int d){
        if(x==null) x=new Node();
        if(d==key.length()){
            x.val=val;
            return x;
        }
        char c=key.charAt(d);
        x.next[c]=put(x.next[c],key,val,d+1);
        return x;
    }

    public int size(){
        return size(root);
    }

    public int size(Node x){
        if(x==null) return 0;
        int count=0;
        if(x.val!=null) count++;
        for(char c=0;c<R;c++){
            count+=size(x.next[c]);
        }
        return count;
    }

    private void collect(Node x,String pre,Queue<String> q){
        if(x==null) return;
        if(x.val!=null) q.enqueue(pre);
        for(char c=0;c<R;c++){
            collect(x.next[c], pre+c, q);
        }
    }

    public Iterable<String> keywitfix(String pre){
        Queue<String> q=new Queue<String>();
        collect(get(root, pre, 0),pre,q);
        return q;
    }

    public Iterable<String> keys(){
        return keywitfix("");
    }

    private void collect(Node x,String pre,String pat,Queue<String> q){
        int d=pre.length();
        if(x==null) return;
        if(d==pat.length()&&x.val!=null) q.enqueue(pre);
        if(d==pat.length()) return;
        
        char next=pat.charAt(d);
        for(char c=0;c<R;c++){
            if(next == '.'||next==c){
                collect(x.next[c], pre+c, q);
            }
        }
    } 

    public Iterable<String> ketmatch(String pat){
        Queue<String> q=new Queue<String>();
        collect(root, "", pat,q);
        return q;
    }

    public String longestper(String s){
        int length=search(root, s, 0, 0);
        return s.substring(0,length);
    }

    private int search(Node x,String s,int d,int length){
        if(x==null) return length;
        if(x.val!=null) length=d;
        if(d==s.length()) return length;
        char c=s.charAt(d);
        return search(x.next[c], s, d+1, length);
    }

    private Node delete(Node x,String key,int d){
        if(x==null) return null;
        if(d==key.length()){
            x.val=null;
        }
        else{
            char c=key.charAt(d);
            x.next[c]=delete(x.next[c], key, d+1);
        }
        if(x.val!=null) return x;
        for(char c=0;c<R;c++){
            if(x.next[c]!=null) return x;
        }
        return null;
    }

    public void delete(String key){
        root=delete(root, key, 0);
    }
}

class tsts<value>{
    private Node root;
    private class Node{
        char c;
        Node left,mid,right;
        value val;
    }

    public value get(String key){
        Node x=get (root,key,0);
        if(x==null)return null;
        return x.val;
    }

    public Node get(Node x,String key,int d){
        if(x==null) return null;
        char c=key.charAt(d);
        if(c<x.c) return get(x.left,key,d);
        else if(c>x.c) return get(x.right ,key,d);
        else if(d<key.length()-1) return get (x.mid,key,d+1);
        else return x;
    }

    public Node put(Node x,String key,value val,int d){
        char c=key.charAt(d);
        if(x==null){
            x=new Node();
            x.c=c;
        }
        if(c<x.c) x.left=put(x.left, key, val, d);
        else if(c>x.c) x.right=put(x.right, key, val, d);
        else if(d<key.length()-1) x.mid=put(x.mid, key, val, d);
        else x.val=val;
        return x;
    }

    public void put(String key,value val){
        root=put(root, key, val, 0);
    }
}


class seartxt1{
   public static int search1(String pat,String txt){
       int M=pat.length();
       int N=txt.length();
       for(int i=0;i<=N-M;i++){
           int j;
           for(j=0;j<M;j++){
               if(txt.charAt(i+j)!=pat.charAt(j)) {break;}
           }
           if(j==M) return i;
       }
       return N;
   } 


   public static int search2(String pat,String txt){
       int j,M=pat.length();
       int i,N=txt.length();
       for(i=0,j=0;i<N&&j<M;i++){
           if(txt.charAt(i)==pat.charAt(j)) j++;
           else{i-=j;j=0;}
       }

       if(j==M) return i-M;
       else return N;
   }
}

class kmp{
    private String pat;
    private int [][] dfa;
    public kmp(String pat){
        this.pat=pat;
        int M=pat.length();
        int R=256;
        dfa=new int[R][M];
        dfa[pat.charAt(0)][0]=1;
        for(int x=0,j=1;j<M;j++){
            for(int c=0;c<R;c++){
                dfa[c][j]=dfa[c][x];
            }
            dfa[pat.charAt(j)][j]=j+1;
            x=dfa[pat.charAt(j)][x];
        }
    }
    
    public int search(String txt){
        int i,j,N=txt.length(),M=pat.length();
        for(i=0,j=0;i<N&&j<M;i++){
            j=dfa[txt.charAt(i)][j];
        }
        if(j==M) return i-M;
        else return N;
    }
}


class nyporm{
    private int[] right;
    private String pat;
    nyporm(String pat){
        this.pat=pat;
        int M=pat.length();
        int R=256;
        right=new int [R];
        for(int c=0;c<R;c++){
            right[c]=-1;
        }
        for(int j=0;j<M;j++){
            right[pat.charAt(j)]=j;
        }
    }
    public int search(String txt){
        int N=txt.length();
        int M=pat.length();
        int skip;
        for(int i=0;i<N-M;i+=skip){
            skip=0;
            for(int j=M-1;j>=0;j--){
                if(pat.charAt(j)!=txt.charAt(i+j)){
                    skip=j-right[txt.charAt(i+j)];
                    if(skip<1) skip=1;
                    break;
                }
            }
            if(skip==0) return i;
        }
        return N;
    }
}


class rabinkerp{
    private String pat;
    private long pathash;
    private int M;
    private long Q;
    private int R=256;
    private long Rm;
    
    public rabinkerp(String pat){
        this.pat=pat;
        this.M=pat.length();
        Q=longRandomPrime();
        Rm=1;
        for(int i=1;i<=M-1;i++){
            Rm=(R*Rm)%Q;
        }
        pathash=hash(pat,M);
    }

    public long hash(String key,int M){
        long h=0;
        for(int j=0;j<M;j++){
            h=(R*h+key.charAt(j))%Q;
        }
        return h;
    }

    public boolean check(int i){
        return true;
    }

    public int search(String txt){
        int N=txt.length();
        long txthash=hash(txt, M);
        if(pathash==txthash&&check(0)) return 0;
        for(int i=M;i<N;i++){
            txthash=(txthash+Q-Rm*txt.charAt(i-M)%Q)%Q;
            txthash=(txthash*R+txt.charAt(i))%Q;
            if(pathash==txthash){
                if(check(i-M+1)) return i-M+1;
            }
        }
        return N;
    }
    
    private static long longRandomPrime() {
        BigInteger prime = BigInteger.probablePrime(31, new Random());
        return prime.longValue();
    }
}



