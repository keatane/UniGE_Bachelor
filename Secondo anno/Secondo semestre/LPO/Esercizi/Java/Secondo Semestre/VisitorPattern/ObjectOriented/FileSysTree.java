public interface FileSysTree {
	// unique generic method for any type of tree visit
	<T> T accept(Visitor<T> v);
}
