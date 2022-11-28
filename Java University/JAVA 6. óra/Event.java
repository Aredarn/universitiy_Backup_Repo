class Event{	
	private String name;
	private String description;
	private int day;
	private int hour;
	
	public Event(String name, int day){
		this.name = name;
		this.day = day;
		//what about description and hour?
	}
	
	public Event(String name, String description, int day, int hour){
		this(name, day);
		this.description = description;
		this.hour = hour;
	}
	
	public String toString(){
		return "Event name: " + name 
			+ ", description: " + description
			+ ", day: " + day 
			+ ", hour: " + hour;
	}	
		
	public String toFile(){
		return name  + " " + description + " " + day + " " + hour;
	}	
}