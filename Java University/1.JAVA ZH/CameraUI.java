import java.io.*;

class CameraUI
{
	Camera canoneos = new Camera("Good 55-250mm", 256, 100);
	
	
	public static void main(String[] args) {
        CameraUI cam = new CameraUI();	

		cam.startCameraUIMenu();		
    }
	
	
	public void startCameraUIMenu()
	{
		boolean turnoffcam = false;
		
		while(turnoffcam != true){
			
			listMenu();
			
			try{
				BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

					int button = Integer.valueOf(in.readLine());
			
				
				switch (button)
				{
					case 1:
						canoneos.listPhotoes();
						break;
					case 2:
						canoneos.exPose();
						break;			
					case 3:
						canoneos.writeToFile();
						break;
					case 4:
						canoneos.getStatusInfo();
						break;
					case 5:
						turnoffcam = true;
						break;
				}
			}
			catch(IOException e)
			{
				e.printStackTrace();
			}	
		}
	}
	
	
	public void listMenu()
	{
		System.out.println("\n \n ");
		
		System.out.println("1.	Show photoes: ");
		System.out.println("2.	New photoes: ");
		System.out.println("3.	Write photoes to file: ");
		
		System.out.println("4.	Show camera infos: ");
		System.out.println("5.	Turn off camera: ");
	}
	
}