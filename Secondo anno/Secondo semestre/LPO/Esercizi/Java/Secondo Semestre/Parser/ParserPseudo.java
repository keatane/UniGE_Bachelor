public class Parser{

parseExp(){ // recognizes string generated from Exp

	this.parseMul() // recursively returns the next token...
	if(tokenizer.tokenType()==ADD){ // ...so here analize a new token
		tokenizer.nextToken()
		this.parseExp()
	}

}


parseMul(){ // recognizes string generated from Mul

	this.parseAtom()
	if(tokenizer.tokenType()==MUL){
		tokenizer.nextToken()
		this.parseMul()
	}

}


parseAtom(){ // recognizes string generated from Atom

	if(tokenizer.tokenType()==OPEN_PAR){
		tokenizer.nextToken()
		this.parseExp()
		this.consume(CLOSE_PAR)
	}
	else
		this.consume(NUM)

}
}