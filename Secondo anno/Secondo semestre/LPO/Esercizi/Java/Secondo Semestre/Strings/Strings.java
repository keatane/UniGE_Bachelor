import java.util.Objects;

public class Strings{

public static String catAll(CharSequence... args){
	StringBuilder aux = new StringBuilder("");
	//for(int i=0; i<args.length; ++i)
		//aux.append(Objects.toString(args[i]));
		
	for(CharSequence a : args)
		aux.append(Objects.toString(a)); // a è un elemento di args
		// aux.append(a); soluzione
	
	//System.out.println(Objects.toString(null));
	return aux.toString();
}

}
