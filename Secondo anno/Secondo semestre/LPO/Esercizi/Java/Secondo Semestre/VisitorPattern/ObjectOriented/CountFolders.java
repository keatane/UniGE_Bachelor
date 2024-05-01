import java.util.List;
public class CountFolders implements Visitor<Integer> {
	public Integer visitFile(int size) {return 0;} // no file visited
	public Integer visitFolder(List<FileSysTree> children) {
		var res = 1;
		for (var node : children)
			res += node.accept(this);
		return res;
	}
}

