public class Bool{

public final static Bool FALSE; // costante che corrisponde a false
public final static Bool TRUE; // costante che corrisponde a true
private final boolean boolValue; // valore booleano rappresentato dall'oggetto

static{
	FALSE = new Bool(false);
	TRUE = new Bool(true);
	
	// alternativa
	// chiamare  costruttori a tempo di dichiarazione, senza questo blocco static
}

// metodo factory che resituisce Bool.FALSE/Bool.TRUE in funzione del parametro b
public static Bool valueOf(boolean b){
	if(!b) return FALSE;
	return TRUE;
	
	// alternativa
	// return b ? TRUE : FALSE;
}

// restituisce il valore booleano corrispondente
public boolean boolValue(){
	return boolValue;
} 

// unico costruttore
private Bool(boolean boolValue){
	this.boolValue = boolValue;
}

//Notare che l'unico costruttore della classe è private per garantire che esistano sempre solo due istanze della classe.

	public static void main(String[] args){
		Bool trueVal = Bool.valueOf(true);
		Bool falseVal = Bool.valueOf(false);
		assert (trueVal == Bool.TRUE && trueVal.equals(Bool.TRUE));
		assert trueVal.boolValue();
		assert trueVal != Bool.FALSE && !trueVal.equals(Bool.FALSE);
		assert trueVal != null && !trueVal.equals(null);
		assert falseVal == Bool.FALSE && falseVal.equals(Bool.FALSE);
		assert !falseVal.boolValue();
		assert falseVal != Bool.TRUE && !falseVal.equals(Bool.TRUE);
		assert falseVal != null && !falseVal.equals(null);
		System.out.println("Finished\n");
	}	
}
