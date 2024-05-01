import java.util.List;
public class CountFilesLargerThan implements Visitor<Integer> {
	private final int minSize;
	public CountFilesLargerThan(int minSize) {this.minSize = minSize;}
	public Integer visitFile(int size) {return size > minSize ? 1 : 0;}
	public Integer visitFolder(List<FileSysTree> children) {
	var res = 0;
	for (var node : children)
	res += node.accept(this);
	return res;
	}
}

