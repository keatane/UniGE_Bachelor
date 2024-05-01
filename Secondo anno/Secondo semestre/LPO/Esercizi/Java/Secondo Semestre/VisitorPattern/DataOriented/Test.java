public class Test {
public static void main(String[] args) {
	var folder = new Folder(new File(10), new Folder(new File(2), new File(21)), new File(5), new File(42));
	
	  assert folder.countFolders() == 2;
	  var f = new File(35);
	  assert f.countFolders() == 0;
	  }
}

