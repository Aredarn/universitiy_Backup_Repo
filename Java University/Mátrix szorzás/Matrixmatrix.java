public class Matrixmatrix {
    private int N;
    int NUMBER_OF_THREADS; 
    float [][]a; // A matrix
    float [][]b; //B matrix
    float [][]c; // result Matrix
    public Matrixmatrix(int size, int mag){
        N= size;
        NUMBER_OF_THREADS = mag;
        a = new float[size][size];
        b = new float[size][size];
        c = new float[size][size];
        
        for(int i=0; i<size;i++){
            for (int j = 0; j < size; j++) {
                a[i][j]=1;
                b[i][j]=1; 
            }
              
        }
    }
    
    
    public static void main(String[] args) {
       int dim =1000;
       int p = 2;
       new Matrixmatrix(dim,p).start();       
    }
    public void start(){
        System.out.println("Mátrix szorzás , Szálak: "+NUMBER_OF_THREADS+"\n");
        seqMult(N);
        
        parfourMult(N);
    }
	
	
     private void seqMult(int size)
    {
        System.out.println("SEQ M x M, N= "+size +"\n");

        //compute
        double startt = System.nanoTime();
        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                float result = 0;
                for (int k = 0; k < size; k++) {
                    result += a[i][k] * b[k][j];
                }
                c[i][j] = result;
            }
        }
        double stopt = System.nanoTime();
        //display results
        
        for(int i=0; i<10;i++){
            for (int j = 0; j < 10; j++) {
                System.out.print(c[i][j] + " ");
            }
            System.out.println("");
        }
               
        System.out.println();
        System.out.println("Szekvenciális futási idő (ms):" + (stopt-startt)*1e-6 +"\n \n");
    } 
    
    private void parfourMult(int size)
    { 
        Thread[] t = new Thread[NUMBER_OF_THREADS];
        for (int i = 0; i < NUMBER_OF_THREADS; i++) {
            final int tind = i;
            t[i]= new Thread(new Runnable(){
                public void run(){
                    int M = size / 2;
                    int offseta =0;
                    int offsetb = 0;
                    switch(tind){
                        case 0: offseta = 0*M; offsetb = 0*M; break;
                        case 1: offseta = 0*M; offsetb = 1*M; break;
                        case 2: offseta = 1*M; offsetb = 0*M; break;
                        case 3: offseta = 1*M; offsetb = 1*M; break;
                    }
                    for(int i=offseta; i<offseta+M; i++){
                        for (int j = offsetb; j < offsetb+M; j++) {
                            float result =0;
                            for (int k = 0; k < size; k++) {
                                result += a[i][k] * b[k][j];
                            } 
                            c[i][j] = result;
                        }  
                    }
                }
            });
        }

        double startpt = System.nanoTime();
        for(int i = 0; i< NUMBER_OF_THREADS; i++)
            t[i].start();
        for(int i = 0; i< NUMBER_OF_THREADS; i++)
        {
            try {
                t[i].join();
            } catch (InterruptedException ex) {
                
            }
        }
        double stoppt = System.nanoTime();
        
        for(int i=0; i<10;i++){
            for (int j = 0; j < 10; j++) {
                System.out.print(c[i][j] + " ");
            }
            System.out.println("");
        }
        System.out.println("Párhuzamos futási idő (ms):" + (stoppt-startpt)*1e-6);
    }
}