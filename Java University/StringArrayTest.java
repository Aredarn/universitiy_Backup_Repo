/** 
 * The HelloWorldApp class implements an application that
 * simply prints "Hello World!" to standard output.
 */
class StringArrayTest {
    public static void main(String[] args) {
        System.out.println("Hello World!"); // Display the string.
		
		//2________________________________
		String mondat = new String("Teljes egesz mondat");
		String test = "csutortok";
		
		System.out.println(mondat +" "+ test);
		
		
		//3________________________________
		if(mondat.equals(test))
		{
			System.out.println("Egyenlőek");
		}
		else
		{
			System.out.println("Nem egyenlőek");
		}
		
		
		System.out.println("A mondat és test közti különbség: " + mondat.compareTo(test));
		
		//4________________________________
		String hashTest = "egy";
		System.out.println(hashTest.hashCode());
		
		hashTest = "egy ketto";
		System.out.println(hashTest.hashCode());
		
		hashTest = "egy ketto hraom";
		System.out.println(hashTest.hashCode());
		
		
		//Az objektumból kiszámol egy intet és visszaadja.
		
		
		System.out.println("\n");
		//5_________________________________
		String randomSzoveg = "The Java String class equals() method compares the Two GIVEN strings based on the content of the string.";
		
		//Kisbetű
		System.out.println(randomSzoveg.toLowerCase());
		//nagybetű
		System.out.println(randomSzoveg.toUpperCase());
		
		
		//6_________________________________
		String forditsad = "nem van megfordítva";
		System.out.println(forditsad);
		
		
		StringBuilder fordit = new StringBuilder(forditsad);
		fordit.reverse();
		System.out.println(fordit);
		
		//7__________________________________
		String str = new String("Új string amiben keresni kell");
        int index = str.indexOf('a');
        System.out.println("Az 'a' betű helye :: "+index);
		
		//8_________________________________
		String md = "Ebben a mondatban VAN amit meg kell keresenie a programnak";
		System.out.println(str);
		
		String find = "VAN";
		int i = md.indexOf(find);
		if(i>0)
			System.out.println(md.substring(i, i+find.length()));
		else 
			System.out.println("Nincs ilyen string");
		
		//9_________________________________
		String file = "measurements.dat";
		
		file = file.replaceAll(".dat",".txt");
		System.out.println(file);
		//10________________________________
		
		int value=30;  
		String s1=String.valueOf(value);  
		boolean bol = true;    
        boolean bol2 = false;    
        String s2 = String.valueOf(bol);    
        String s3 = String.valueOf(bol2); 
		char ch2 = 'B';  
        String s4 = String.valueOf(ch2);
		double d5 = 6534.432;
		String s5 = String.valueOf(d5);

		System.out.println(s1 +" "+  s2 +" "+"" + s3 +" "+ s4 + " " + s5);
		
		
		System.out.println("\n");
		//12,13__________________________________
		String[] tomb = {"Hetfo", "Kedd", "Szerda", "Csutortok", "Pentek", "Szombat", "Vasarnap" };
		
		for(int x = 0; x<tomb.length;x++)
			System.out.println(tomb[x]);
		
		//14_________________________________
		for(int x = 0; x<tomb.length;x++)
			System.out.println(tomb[x].toUpperCase());
		
		//15__________________________________
		tomb[6] = null;
		/*for(int x = 0; x<tomb.length;x++)
			System.out.println(tomb[x].toUpperCase());
		NULLPOINTERXECEPTION*/
		
		
		//16_________________________________
		
		class Event{
			String name;
			String description;
			int day, hour;
			
		};
    }
}