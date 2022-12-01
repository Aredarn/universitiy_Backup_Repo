import java.io.*;

class Photo
{
	private String name;
	private int photosize;
	
	public Photo(String name, int photosize)
	{
		this.name = name;
		this.photosize = photosize;
	}
	
	public String getName()
	{
		return this.name;
	}
	
	public int getPhotoSize()
	{
		return this.photosize;
	}
	
	public String toString()
	{
		return name + "," + photosize;
	}
	
	
}