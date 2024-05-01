import java.util.LinkedList;
import java.util.List;
import static java.util.Objects.requireNonNull;
public class Folder implements FileSysTree {
	private final List<FileSysTree> children = new LinkedList<>();
	// constructor as before
	public Folder(FileSysTree... children) {
		for (var node : children) this.children.add(requireNonNull(node));
	}

	
	public <T> T accept(Visitor<T> v) { return v.visitFolder(children); }
}

