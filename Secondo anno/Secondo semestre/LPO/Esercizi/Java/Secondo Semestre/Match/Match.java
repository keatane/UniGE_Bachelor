import java.lang.Throwable;
import java.util.regex.*;
import java.io.IOException;
import java.lang.AutoCloseable;
import java.io.FileWriter;
import java.io.BufferedWriter;

public class Match{

	public static void main(String[] args) {
		if (args.length < 1) {
			System.err.println("Error: Missing necessary argument reg_exp");
			return;
		}
		Matcher mtch;
		try{
			mtch = Pattern.compile(args[0]).matcher("");// may not be correct regex
		} catch (PatternSyntaxException e) {
			System.err.println(e.getMessage());
			return;
		}
		
		var string = "";
		var group = 0;
		var filename = "";
		try{
		for(int i=1; i < args.length; i++){
			if(args[i].equals("-s")){
				string = args[i+1];
				i++; // jump to next option if any
			}
			if(args[i].equals("-g")){
				group = Integer.parseInt(args[i+1]); // may throw NumberFormatException
				i++; // jump to next option if any
			}
			if(args[i].equals("-o")){
				filename = args[i+1];
				i++; // jump to next option if any
			}
				
		}
		} catch (Throwable e) {
			System.err.println(e.getMessage());
		}
		if (group < 0 || group > mtch.groupCount()) {
			System.out.println("Argument 'group' is not a valid group, using 0 as default");
			group = 0;
		}
		mtch.reset(string);

		
		if(filename.equals("")){
			if (mtch.lookingAt() && mtch.group().equals(mtch.group(group))) // observe if the group passed is by itself the entire group that has been matched (otherwise the string doesn't belong to the group or belongs only partly)
				System.out.println("String '" + string + "' matches group " + group);
			else System.out.println("String '" + string + "' does not match group " + group);
			return;
		}
			
		try (FileWriter file = new FileWriter(filename)) {
			BufferedWriter output = new BufferedWriter(file);
			if (mtch.lookingAt() && mtch.group().equals(mtch.group(group)))
				output.write("String '" + string + "' matches group " + group);
			else output.write("String '" + string + "' does not match group " + group);
			output.flush();
			return;
		} catch (IOException e) {
			System.err.println(e.getMessage());
		}
		
		
	}
}
