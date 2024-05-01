import java.util.Arrays;
import java.util.Collection;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class Max{

public static Integer max(Collection<Integer> col) {
	var res = Integer.MIN_VALUE;
	if(col.isEmpty()) return null; // non significa che punta a null!
	for (int i : col) // Collection<E> ≤ Iterable<E>
		if(i > res) res = i;

	return res;
}

public static void main(String[] args) {
	Set<Integer> s = new HashSet<>();

	// s refers to set {}
	assert max(s) == null;

	s.addAll(Arrays.asList(1, 2, 3, 4));

	// s refers to set {1,2,3,4}
	assert max(s) == 4;
}
   
}
