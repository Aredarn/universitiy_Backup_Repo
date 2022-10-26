import java.io.*;
import java.io.Writer;
import java.util.*;
class EventManagerApp{
	
	private Vector<Event> eventCollection = new Vector<Event>();
	String filename = "events.txt";
	
	
	public static void main(String[] args){
		EventManagerApp prog = new EventManagerApp();
		prog.start();
	}
	
	public void start()
	{
		int key = -1;
		while(key != 6)
		{
			//show menu to user
			displayMenu();
			// receive user input
			key = getUserInput();
			//Exec if possible
			switch (key)
			{
				case 1:
				//1. Add & store new event
					addEvent();
					break;
				case 2:
				//2. List events
					listEvents();
					break;
				case 3:
				//3. Delete events
					deleteEvent();
					break;
				case 4: 
				//4. write to file events
					writeToFile();
					break;
				case 5:
				//Read from files  (While inicialisaton)
					readFromFile();
					break;
			}
		}
	}
	
	public void displayMenu()
	{
		System.out.print("\n \n");
		System.out.println("1. Add & store new event");
		System.out.println("2. List events");
		System.out.println("3. Delete events");
		System.out.println("4. Write events to file");
		System.out.println("5. Read from file");
		System.out.println("6. EXIT");
		
		System.out.print("enter the number of the activity: ");	
		
		System.out.print("\n");
	}
	
		
	public void addEvent()
	{
		System.out.println("Event name: ");
		Scanner s = new Scanner(System.in);
		String name = s.nextLine();
		
		System.out.println("Event desc: ");
		Scanner x = new Scanner(System.in);
		String desc = x.nextLine();
		
		System.out.println("Day: ");
		Scanner r = new Scanner(System.in);
		int day = r.nextInt();
		
		System.out.println("Hour: ");
		Scanner p = new Scanner(System.in);
		int hour = p.nextInt();
					
		Event newEvent = new Event(name,desc,day,hour);
		eventCollection.add(newEvent);		
	}
	
	
	public int getUserInput()
	{
		Scanner userinput = new Scanner(System.in);
		try 
		{ 
			return userinput.nextInt();
		}  
		catch (NumberFormatException e)  
		{ 
			return 0; 
		} 
	}
	
	
	public void listEvents()
	{
		System.out.println("----------------EVENTEK-------------------");
		
		for(int i = 0;i<eventCollection.size(); i++)
		{
			System.out.println(eventCollection.get(i) + " ");
			System.out.println();
		}
		System.out.println("------------------------------------------");
	}
	
	public void deleteEvent()
	{
		System.out.println("Select event's number which you want to delete: ");
		int deleteNum = getUserInput();
		
		if(deleteNum >= eventCollection.size() || deleteNum < 0)
		{
			System.out.println("Nem megfelelő érték");
		}
		else
			eventCollection.remove(deleteNum);
	}
	

	
	public void writeToFile(Event event, String filename)
	{
		PrintWriter fileOutput = null;
		try{
			//eleje
			fileOutput = new PrintWriter(
				new OutputStreamWriter( 
					new FileOutputStream(filename, true)
				)
			);
			//VÉGE
			
			//Kiiratás
			fileOutput.println(event);
			
			fileOutput.flush();
		}
		catch(FileNotFoundException e)
		{
			e.printStackTrace();
		}
		finally
		{
			if(fileOutput != null)
				fileOutput.close();
		}
	}	

	
	public void writeToFile()
	{
		EventManager forWrite = new EventManager();
		if(eventCollection.size() != 0)
		{
			for(int i = 0; i < eventCollection.size(); i++)
			{
				forWrite.writeEventToFile(eventCollection.get(i), filename);
			}
			System.out.println("SUCCESSFUL WRITE TO FILE");
		}
		else
			System.out.println("ERROR, NO EVENTS FOUND");
	}


	public void readFromFile()
	{
			try
			{
				List<String> words = new ArrayList<String>();
				BufferedReader reader = new BufferedReader(new FileReader(filename));
				String line;
				

					while ((line = reader.readLine()) != null) 
					{
						words.add(line);
					}
					/*
					for(int i = 0; i < words.size(); i+=4)
					{
						string correctrow = words.get(i).split(); 
						for(int i = 0; i < 4; i++)
						{
							
						}
						
						
						Event tempevent = new Event(words.get(i),words.get(i),Integer.parseInt(words.get(i+2)), Integer.parseInt(words.get(i+3)));
						eventCollection.add(tempevent);
					}*/
					reader.close();

			}
			catch(FileNotFoundException e)
			{
				e.printStackTrace();
				
			}
			catch(IOException e) 
			{
				e.printStackTrace();
			}

	}

}


