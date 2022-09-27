/** 
 * The HelloWorldApp class implements an application that
 * simply prints "Hello World!" to standard output.
 */
class HelloWorldApp {
    public static void main(String[] args) {
        System.out.println("Hello World!"); // Display the string.
		
		int limit = 299;
		System.out.println("The max limit is: " + limit);
		
		
		int osszeg = 0;
		for(int i = 1; i<11;i++)
		{
			osszeg = osszeg + i;
		}
		System.out.println("Számok összege: " + osszeg);

		int nap = 2;
		
		
		switch(nap){
			case 0:
				System.out.println("Hétfő");
				break;
			case 1:
				System.out.println("Kedd");
				break;
			case 2:
				System.out.println("Szerda");
				break;
			case 3:
				System.out.println("Csütörtök");
				break;
			case 4:
				System.out.println("Péntek");
				break;
			case 5:
				System.out.println("Szombat");
				break;
			case 6:
				System.out.println("Vasárnap");
				break;
			
			}
		
		int[] myArray = new int[10];
		
		for(int i = 0; i<10;i++)
		{
			myArray[i] = i*5;
		}
		
		for(int i = 0; i<10;i++)
		{
			System.out.println (i+". szám a " + myArray[i]);
		}
	
	}

}