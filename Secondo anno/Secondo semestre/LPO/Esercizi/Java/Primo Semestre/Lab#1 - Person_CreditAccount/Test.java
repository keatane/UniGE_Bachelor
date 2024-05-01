public class Test{
	public static void main(String[] args){
		Person p1 = new Person("Kevin", "Cattaneo");
		Person p2 = new Person("Giorgio", "Rossi");
		assert p1.GetSpouse() == null;
		Person p3 = new Person("Martina", "Pianelli", p1);
		assert p1.GetSpouse().name.equals(p3.name);
		assert p3.GetSpouse().name.equals(p1.name);
		assert !p3.GetSpouse().name.equals(p2.name);
		
		CreditAccount profile1 = new CreditAccount(100, p1);
		assert profile1.GetBalance() > 0;
		assert profile1.GetOwner() == p1;
		CreditAccount.newOfLimitBalanceOwner(-100, 55555, p1);
		assert profile1.GetOwner() == p3.GetSpouse();
	}

}
