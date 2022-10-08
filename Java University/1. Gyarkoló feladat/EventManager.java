import java.io.*;
import java.io.Writer;
import java.util.*;
class EventManager{
	private static Vector<Event> eventCollection = new Vector<Event>();
	
	public static void main(String[] args)
	{
		String filename = "events.txt";
		int dontExit = 0;
		
		while(dontExit != 4)
		{
			commandPromptApp();
			
			Scanner in = new Scanner(System.in);
			dontExit = in.nextInt();
			
			switchActivity(dontExit, filename);
		}
	}

	public static void commandPromptApp()
	{
		System.out.println("1. Add new event");
		System.out.println("2. List events");
		System.out.println("3. Save events to file");
		System.out.println("4. Exit");
		System.out.println();
		
		System.out.print("enter the number of the activity: ");
		
	}
	
	public static void switchActivity(int selector, String filename)
	{
		switch(selector){
			case 1:
				System.out.println("Event name: ");
				Scanner s = new Scanner(System.in);
				String name = s.nextLine();
				System.out.println("Event time: ");
				Scanner r = new Scanner(System.in);
				int day = r.nextInt();
				
				Event newEvent = new Event(name,day);
				addEvent(newEvent);
				break;
			case 2:
				listEvents();
				break;
			case 3:
				for(int i = 0;i<eventCollection.size(); i++)
				{
					writeEventToFile(eventCollection.get(i), filename);
				}
				System.out.println("Successful");
				
				break;
			case 4:
				break;
			
		}
	}
	
	
	
	public static void addEvent(Event event)
	{
		eventCollection.add(event);		
	}
	
	public static void listEvents()
	{
		System.out.println("----------------EVENTEK-------------------");
		
		for(int i = 0;i<eventCollection.size(); i++)
		{
			System.out.println(eventCollection.get(i) + " ");
			System.out.println();
		}
		System.out.println("------------------------------------------");
	}
	

	public static void writeEventToFile(Event event, String filename)
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
	
}
	