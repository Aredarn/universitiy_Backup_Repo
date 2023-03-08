class VectorAdd{
	public static void main(String[] args)
	{
		new VectorAdd().start();
	}
	
	public void start()
	{
		System.out.println("Vector add test");
		
		double start = System.nanoTime();
		seqVectorAdd();
		double stop = System.nanoTime();
	
		System.out.println("SEQ time: " + (stop-start)*1e-9 + " sec");
	}

	private void seqVectorAdd()
	{
		
		System.out.println("SEQ Vector add");
		final int SIZE = 10000*1000;
		double[] a = new double[SIZE];
		double[] b = new double[SIZE];
		double[] c = new double[SIZE];
		
		//init rész
		
		for(int i = 0; i < SIZE ; i++)
		{
			a[i] = 1;
			b[i] = 4;
		}
		
		// compute
		
		for(int i = 0; i < SIZE ; i++)
		{
			c[i] = a[i] + b[i];	
		}
		
		// display
		
		for(int i = 0; i < 10 ; i++)
		{
			System.out.println(c[i] + " ");	
		}
		
		//***********************párhuzamos rész***************************//
		final int NUM_THREADS = 2;
		ParThread[] threads = new ParThread[NUM_THREADS];
			
		double start = System.nanoTime();
		for(int i =o;i< NUM_THREADS; i++)
		{
			threads[i] = new ParThread(a,b,c, SIZE, i);
			threads[i].start();
		}
		
		for(int i =0;i< NUM_THREADS; i++)
		{
			try{
				
				threads[i].join();
			}
			catch(InterruptedException ex)
			{
				
			}			
		}
		
		double stop = System.nanoTime();
		
		
		
		System.out.println("VectorAdd time: " + (stop-start)/SIZE + " ns");
	}
	
	
	
	class ParThread extends Thread{
		
		private double[] a;
		private double[] b;
		private double[] c;
		private int SIZE;
		final private int tid; //thread index;
		
		
		public ParThread(double[] a,double[] b,double[] c, int size, int tid )
		{
			this.a = a;
			this.b = b;
			this.c = c;
			this.SIZE = size;
			this.tid = tid;
		}
		
		
		public void run(){
			int offset = tid*size /2;
			int end = (tid+1)*SIZE/2;
			for(int i = offset; i < end ; i++)
			{
				c[i] = a[i] + b[i];	
			}
		}	
	}

}	