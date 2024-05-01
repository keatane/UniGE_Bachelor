public class StringBuilder_test{
public static void main (String[] args){
	assert Strings.catAll().equals("");
	assert Strings.catAll("Hello", " ", "world", "!").equals("Hello world!");
	assert Strings.catAll("Hello", " ", null, "!").equals("Hello null!");
}
}
