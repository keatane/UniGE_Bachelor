public class Person{
	private static long nextSN = 0;
	public final String name;
	public final String surname;
	private final long socialSN;
	private Person spouse;

	
	public Person GetSpouse(){
		return this.spouse;
	}
	
	private boolean isValidPerson(){
		return(this.name.matches("[A-Z][a-z]+( [A-Z][a-z]+)*") && this.surname.matches("[A-Z][a-z]+([A-Z][a-z]+)*")); 
	}

	private boolean isSingle(){
		return this.spouse==null;
	}

	private static void NothingToDo(){
		System.out.println("Nothing to do");
	}

	public static void join(Person p1, Person p2){
		if(p1.socialSN == p2.socialSN) { Person.NothingToDo(); return;}

		if(!(p1.isSingle() && p2.isSingle())) { Person.NothingToDo(); return;}
	       	p1.spouse = p2;
		p2.spouse = p1;
	}

	public static void divorce(Person p1, Person p2){
		if(p1.socialSN == p2.socialSN) { Person.NothingToDo(); return;}
		if(p1.spouse != p2 || p2.spouse != p1) { Person.NothingToDo(); return;}
		p1.spouse = null;
		p2.spouse = null;
	}

	public Person(String name, String sur){
		this.name = name;
		this.surname = sur;
		this.socialSN = nextSN++;
		if(!isValidPerson())
			throw new IllegalArgumentException();
	}


	public Person(String name, String sur, Person spouse){
		this.name = name;
		this.surname = sur;
		this.socialSN = nextSN++;
		this.spouse = spouse;
		spouse.spouse = this;
		if(!isValidPerson())
			throw new IllegalArgumentException();
	}

}
