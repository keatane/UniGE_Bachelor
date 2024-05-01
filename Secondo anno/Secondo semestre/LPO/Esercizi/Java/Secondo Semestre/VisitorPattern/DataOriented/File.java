public class File implements FileSysTree {
	private int size;
	public File(int size){
		if (size < 0)
			throw new IllegalArgumentException("File size cannot be negative");
		this.size = size;
	}
	public int countFilesLargerThan(int minSize){return size > minSize ? 1 : 0;}
	public int countFolders(){return 0; // because a file doesn't have folders
	}
}

