public class AnotherTimerClass { 
   // total time (in seconds) equals seconds+60*minutes     
   private int seconds;// invariant: 0<=seconds<=59  
   private int minutes;// invariant: 0<=minutes<=60 && (minutes<60 || seconds==0)
   public boolean isRunning() {
      return this.getTime() > 0;
   }
   public int getTime() { 
      return seconds + minutes*60;
   }
   public void tick() {
      if(seconds > 0){
      	this.seconds--;
      	return;
      }
      else if(minutes > 0){
      	this.minutes--;
      	this.seconds = 59; // reset seconds
      }
      //else nothing
   }
   public int reset(int minutes) {
      if(minutes<0 || minutes > 60)
      	throw new IllegalArgumentException();
      int prevTime = this.minutes;
      this.minutes = minutes;
      
      return seconds + prevTime*60;
   }
}
