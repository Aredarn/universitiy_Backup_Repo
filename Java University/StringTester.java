/** 
 * A simple class to show that using == for comparing Strings (and objects) 
 * can lead to different results based on context, so equals must be used instead.
 */
 import java.util.Scanner;
 import java.text.MessageFormat;
 
class StringTester {
	public static void main(String[] args) {
        firstStringTesting();
		secondStringTesting();
		thirdStringTesting();
    }
	
	private static void firstStringTesting(){
		//Comparing "hard coded " Strings
		System.out.print("Test no. 1.: ");
		String firstWord = "Java";
		String secondWord = "Java";				
		System.out.print("\"" + firstWord + "\" == \""+ secondWord + "\" is ");
		System.out.println(firstWord == secondWord);
		//Due to optimisation, the two String references firstWord and secondWord
		//will refer to the same object, thus == will yield true.
	}
	
	private static void secondStringTesting(){
		//Comparing two, separately created String objects
		System.out.print("Test no. 2.: ");
		String firstWord = new String("Java");
		String secondWord = new String("Java");
		System.out.print("\"" + firstWord + "\" == \""+ secondWord + "\" is ");
		System.out.println(firstWord == secondWord);
		//As two String objects were created separately, their respective
		//references are not the same, so == will yield false.
	}
	
	private static void thirdStringTesting(){
		//Comparing two input Strings received from the keyboard
		System.out.println("Test no. 3.");
		String firstWord = scanOneLine();		
		System.out.println("\tYour 1st word is \""+ firstWord +"\".");
		
		String secondWord = scanOneLine();		
		System.out.println("\tYour 2nd word is \""+ secondWord +"\".");		
		
		String result = firstWord == secondWord ? "equal" : "not equal";
		//Additional material:
		//The ternary ? operator has the following syntax:
		// <statement to evaluate> ? <value to return if true> : <value to return otherwise>
		
		System.out.println(
			MessageFormat.format("  Based on ==, the two words are {0}", result));		
		//Additional material:
		//The MessageFormat class offers different way to format/insert values and text.
		//It can be used to provide better readability compared to string + value + string...
		//by using placeholders like {0}, {1} etc.

		//we can do the two previous commands in "one step"
		System.out.println(
			MessageFormat.format("  Based on equals(), the two words are {0}equal",
			firstWord.equals(secondWord) ? "" : "not "));
	}
	
	public static String scanOneLine(){
		//A simple method to read a single line from the keyboard
		//Scanner can be used for "simple" testing/learning purposes,
		//but we will learn a more sophisticated  way to handle I/O
		
		System.out.print(" Please write a word and press enter: ");
		return new Scanner(System.in).nextLine();
		
		//First an instance of the Scanner class is created with new Scanner(System.in).
		//Then the nextline() method of this instance is called, which returns a String read from the keyboard
		
	}
	
}