public class Parser{

public enum NUM{
	ZERO, UNO;
}

public static void main(String[] args){
	NUM num = NUM.ZERO;
	assert num == NUM.UNO; 
}
}
