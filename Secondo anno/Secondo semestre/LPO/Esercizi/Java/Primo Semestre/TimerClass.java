public class TimerClass {
    // private instance variables
    private int time; 
    /* invariant 0 <= time && time <= 3600; */
    
    public TimerClass(int minutes){
    	this.time = minutes*60;
    }
    // public instance methods
    public boolean isRunning() {                                  
        /* ensures result == this.time > 0 && this.time == old(this.time); */ 
        return this.getTime() > 0;
    }

    public int getTime() { 
        /* ensures result == this.time && this.time == old(this.time); */   
        return this.time;
    }
    
    public TimerClass tick() { 
        /* ensures this.time >= 0 && result == this; */
        if (this.isRunning()){
        	this.time--;
        	return this;
        }
        return this;
    }

    public int reset(int minutes) { 
        /* requires 0 <= minutes && minutes <= 60;
           ensures result == old(this.time)
                   && this.time == minutes * 60; */
        if (minutes < 0 || minutes > 60)
	          throw new IllegalArgumentException();
        int prevTime = this.getTime();
        this.time = minutes * 60;
        return prevTime;
	}

	public static void main(String[] args){
		TimerClass t = new TimerClass(1);
		System.out.println("Time before: " + t.getTime());
		t.tick().tick(); // two ticks
		assert t.getTime()==58;
		System.out.println("Time after: " + t.getTime());
	}
}


