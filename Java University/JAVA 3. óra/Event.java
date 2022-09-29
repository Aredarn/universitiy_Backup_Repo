class Event{
	private String name;
	private String description;
	private int day;
	private int hour;
	
	public Event(String name, int day){
		this.name = name;
		this.day = day;
		
	}
	
	public Event(String name, String description, int day, int hour)
	{
		this(name, day);
		this.description = description;
		this.hour = hour;
	}
	
	public String toString()
	{
		return name + " " + description + " " + day + " " + hour;
	}
	
	
}