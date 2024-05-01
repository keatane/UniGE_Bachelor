public class File implements FileSysTree {
private int size;
// constructor as before
public File(int size){
if (size < 0)
throw new IllegalArgumentException("File size cannot be negative");
this.size = size;
}

public <T> T accept(Visitor<T> v) { return v.visitFile(size); }
}

