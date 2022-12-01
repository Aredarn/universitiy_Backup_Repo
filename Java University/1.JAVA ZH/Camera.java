import java.io.*;
import java.util.*;
class Camera
{
	private String objective;
	private int memcard, accumulator;
	private Vector<Photo> photoes = new Vector<Photo>();
	
	public Camera(String objective, int memcard, int accumulator)
	{
		this.objective = objective;
		this.memcard = memcard;
		this.accumulator = accumulator;
	}
	
	public int getMemCard()
	{
		return memcard;
	}
	
	public void exPose()
	{
		
		BufferedReader input = new BufferedReader( new InputStreamReader(System.in));
			
		//Ha lemerült akkor nem tud fotót csinálni 
		if(accumulator > 0)	
		{	
			
			try	{
				System.out.println("Focusing....");
				System.out.println("CAPTURED PHOTO \n");
				System.out.print("Name of the photo: ");
				String name = input.readLine();

				System.out.print("Size of the photo");
				int size = Integer.valueOf(input.readLine());

				
				Photo photo = new Photo(name, size);
				photoes.add(photo);
				accumulator--;
			}
			catch(IOException e)
			{
				e.printStackTrace();
			}
		}
		else
		{
			System.out.println("CHANGE BATTERY (Reset program :) )");
		}
	}
	
	public void listPhotoes()
	{
		if(accumulator > 0)	
		{
			if(photoes.size() == 0)
			{
				System.out.println("NO PHOTOES");
			}
			else
			{			
				for(int i = 0; i < photoes.size(); i++)
				{
					System.out.println("Name: " + photoes.get(i).getName() + " File size: " + photoes.get(i).getPhotoSize());
				}
			}
		}
		else
		{
			System.out.println("CHANGE BATTERY (Reset program :) )");
		}
	}

	
	public void writeToFile()
	{
		if(photoes.size() > 0)
		{
			PrintWriter fileOutput = null;
			try{
				fileOutput = new PrintWriter(new OutputStreamWriter(new FileOutputStream("photoes.txt", true)));
				
				for(int i = 0;i < photoes.size(); i++)
				{
					fileOutput.println(photoes.get(i).toString());
				}
				System.out.println("SUCCESSFUL WRITING");
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
		else
		{
			System.out.println("NO PHOTOES");
		}
	
	}
	
	public void getStatusInfo()
	{
		System.out.println("Objective type: " + objective);
		
		System.out.println("Memory space: " + memcard);
		
		System.out.println("Accu level: " + accumulator + "%");
		
	}
	
}