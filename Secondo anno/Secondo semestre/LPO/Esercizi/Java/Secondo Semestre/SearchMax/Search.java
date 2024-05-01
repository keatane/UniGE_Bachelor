import java.util.LinkedList;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;


public class Search{

public static <E> int search(E e, List<E> ls) {
	int res = 0;
	
	//Iterator<E> it = ls.iterator();
	//while (it.hasNext()){
	//	if (it.next() == e) return res;
	//	res++;
	//}
	
	// Soluzione alternativa compatta
	for (E el : ls) { // for-each with iterable objects or arrays
		if (el == e) return res;
		res++;
	}

	
	return -1;
}

public static void main(String[] args) {
	List<Integer> llist = new LinkedList<>(); // the diamond notation <> is allowed in this case
	for (int i = 1; i <= 6; i++)
		llist.add(i); // appends i to the end of list

	// llist refers to [1,2,3,4,5,6]
	assert search(5, llist) == 4;
		
	List<String> alist= new ArrayList<>(Arrays.asList("one","two","three","four"));

	// alist refers to ["one","two","three","four"]
	assert search("three",alist) == 2;
}

}
