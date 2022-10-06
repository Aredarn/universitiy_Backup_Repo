import java.io.*;
import java.io.Writer;
import java.util.*;
class EventManager{
	private Vector<Event> eventCollection = new Vector<Event>();
	public static void main(String[] args)
	{
		
		Event myEvent = new Event("Meemlekezes", 10);
		Event myOtherEvent = new Event("Megemlekezes", 21);
		
		//Új eventmanager létrehozása, hogy a tárolót tudjuk használni privateban.
		EventManager manager = new EventManager();
		
		//2 új Event hozzáadása
		manager.addEvent(myEvent);
		manager.addEvent(myOtherEvent);
		
		//Kilistázza az eventeket
		manager.listEvents();
		
		//System.out.println(myEvent);
		String filename = "events.txt";


		//Törli a myOtherEvent eventet a tárolóból
		manager.deleteEvent(myOtherEvent);

		//write Event fileba
		writeEventToFile(myEvent, filename);
		writeEventToFile(myOtherEvent,filename);
	}

	
	
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