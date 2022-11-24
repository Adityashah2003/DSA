import java.util.*;

class Myexception extends Exception{
    public Myexception(String s ){
        super(s);
    }
}
class Operation{
    Scanner sc = new Scanner(System.in);
    synchronized void search(int size, int[] arr){
        System.out.println("Enter no. to be searched");
        int elem = sc.nextInt();
        int flag= 0;
        for(int i=0;i<size;i++){
            if(arr[i]==elem)
                flag =1;
        }
        if(flag ==1)
            System.out.println("Found"); 
        else
            System.out.println("Not Found");
    }
    synchronized void sort(int size, int[] arr){
        int temp =0;
        for(int i=0;i<size;i++){
            for(int j=1;j<size-i;j++){
                if(arr[j-1]>arr[j]){
                temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j ] = temp;
                }
            }
        }
        for(int i=0 ; i<size;i++){
            System.out.println(arr[i]);   
        }
        
    }
}    
class Thread1 extends Thread{
    Operation o = new Operation();
    int s=0;
    int[] a;
    Thread1(int s,int[] a){
        this.s=s;
        this.a=a;
    }
    public void run(){
        o.search(s,a);
    }
}
class Thread2 extends Thread{
    Operation o1 = new Operation();
    int s1=0;
    int[] a1;
    Thread2(int s1,int[] a1){
        this.s1=s1;
        this.a1=a1;
    }
    public void run(){
        o1.sort(s1,a1);
    }
}

class Main{
    public static void main(String[] args)
    {
        Operation op = new Operation();
        try {
            int i=0;
            Scanner sc = new Scanner(System.in);
            int size = sc.nextInt();
            int[] arr = new int[size];
            for(i=0 ; i<size;i++){
                arr[i] = sc.nextInt();
                if(arr[i]<0){
                    throw new Myexception("Lmao not this time nigga");
                }
            }
            Thread1 t1 = new Thread1(size, arr);
            Thread2 t2 = new Thread2(size, arr);
            t2.start();
            t1.start();
        }
        catch(Myexception e){
            System.out.println("Gotcha");
            System.out.println(e.getMessage());
        }

    }
}
