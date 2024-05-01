import java.util.*;

public class ArrayString{
	
	private final char[] string;
	
	public ArrayString(String str){
		this.string = new char[str.length()]; // alternativa: this(str.length);
		for(int i = 0; i < str.length(); ++i)
			this.string[i] = str.charAt(i);
	}

	// internal use for concat
	private ArrayString(int l){
                this.string = new char[l];
    }

	public int length(){
		int i=0;
		for(char c : this.string) ++i;
		return i;
	}

	public char charAt(int index){
		return this.string[index];
	}

	public ArrayString concat(ArrayString str){
		ArrayString aux = new ArrayString(this.length()+str.length());	
		for(int i = 0; i < this.length(); ++i)
                         aux.string[i] = this.string[i];
		for(int i = 0; i < str.length(); ++i)
                         aux.string[i + this.length()] = str.string[i];
		return aux;
	}
}
