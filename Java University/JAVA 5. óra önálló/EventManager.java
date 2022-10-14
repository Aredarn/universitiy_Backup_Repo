import java.io.*;
import java.io.Writer;
import java.util.*;
class EventManager{
	private Vector<Event> eventCollection = new Vector<Event>();
		
	public void addEvent(Event event)
	{
		eventCollection.add(event);		
	}
	
	public void listEvents()
	{
		System.out.println("----------------EVENTEK-----------------------------------");
		System.out.println(eventCollection);
	}
	
	public void deleteEvent(Event event)
	{
		if(event != null)
		{
			eventCollection.remove(event);
			System.out.println("Sikeres volt a törlés");
		}
		else
		{
			System.out.println("Nem volt sikeres a törlés");
		}
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