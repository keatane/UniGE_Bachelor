import java.util.LinkedList;
import java.util.List;
import static java.util.Objects.requireNonNull;

public class Folder implements FileSysTree {
	private final List<FileSysTree> children = new LinkedList<>();
	
	public Folder(FileSysTree... children) {
		for (var node : children) this.children.add(requireNonNull(node));
	}
	public int countFilesLargerThan(int minSize) {
		var res = 0;
		for (var node : children)
		res += node.countFilesLargerThan(minSize);
		return res;
	}
	
	public int countFolders() {
		var res = 1;
		for (var node : children)
			res += node.countFolders();
		return res;
	}
	
}

