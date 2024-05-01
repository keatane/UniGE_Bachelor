public class CreditAccount{
	
	public static final int default_limit = 0;
	private static long nextID = 0;
	private int limit;
	private int balance;
	private Person owner;
	private long ID;

	public int GetLimit(){
		return this.limit;
	}

	public int GetBalance(){
		return this.balance;
	}

	public Person GetOwner(){
		return this.owner;
	}

	public long GetID(){
		return this.ID;
	}

	private int deposit(int amount){
		if(amount < 0) throw new IllegalArgumentException();
		balance += amount;
		return balance;
	}

	private int withdraw(int amount){
		if(amount < 0) throw new IllegalArgumentException();
		if((balance = balance - amount) < this.limit){
			balance += amount;
			System.out.println("You do not have so much money");	
		}
		return balance;
	}

	private void setLimit(int limit){
		if(this.balance < limit){
			System.out.println("You wanted to delete your debit eheh!");
			return;
		}
		this.limit = limit;
		return;
	}

	public static CreditAccount newOfLimitBalanceOwner(int limit, int balance, Person owner){
		
		CreditAccount profile = new CreditAccount(limit, balance, owner);
		return profile;
	}

	public static CreditAccount newOfLimitBalanceOwner(int balance, Person owner){

                CreditAccount profile = new CreditAccount(balance, owner);
		return profile;
        }

	public CreditAccount(int limit, int balance, Person owner){
		if(balance <= 0) {
                        System.out.println("Initial balance has to be greater than zero");
                        return;
                }

                this.setLimit(default_limit);
                this.balance = balance;
                this.owner = owner;
                this.ID = nextID++;
	}
	
	public CreditAccount(int balance, Person owner){

                if(balance <= 0) {
                        System.out.println("Initial balance has to be greater than zero");
                        return;
                }

                this.setLimit(default_limit);
                this.balance = balance;
                this.owner = owner;
                this.ID = nextID++;
	}
}
