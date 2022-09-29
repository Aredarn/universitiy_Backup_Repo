import java.io.*;
 
class ContentReader {
	public static void main(String[] args) {        		
		readFromKeyBoard();
		readFromFile(filename);
		

		void readFromKeyBoard(){
			
		BufferedReader keyboardInput = new BufferedReader( new InputStreamReader(System.in));
			try	{	
				System.out.print("Neve");
				String name = keyboardInput.readLine();
				
				System.out.print("Leírás");
				String description = keyboardInput.readLine();
				
				System.out.print("Nap: ");
				int day = Integer.valueOf(keyboardInput.readLine());
				
				System.out.print("Óra: ");
				int hour = Integer.valueOf(keyboardInput.readLine());
				
				Event myEvent = new Event(name,description,day,hour);
				
				System.out.println(myEvent);	
			}
			catch(IOException e)
			{
				e.printStackTrace();
			}
		}
		
		public static void readFromFile(String filename) {    
		filename = "inout.txt";
			try
			{
				InputStreamReader fileInput = new InputStreamReader(new FileInputStream(filename));
			}catch(FileNotFoundException e)
			{
				e.printStackTrace();
				
			}catch(IOException e)
			{
				e.printStackTrace();
				
			}
		}	
	}	
}