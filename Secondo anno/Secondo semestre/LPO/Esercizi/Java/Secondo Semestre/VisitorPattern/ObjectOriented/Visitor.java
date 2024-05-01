import java.util.List;
public interface Visitor<T> {
	// a method for each type of node
	T visitFile(int size);
	T visitFolder(List<FileSysTree> children);
}
