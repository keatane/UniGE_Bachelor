# Hash functions
- allow to create fingerprint of a file or message
- useful for encryption at rest (over file that are saved on a disk)

## Properties
- H can be applied to any-size block data
- H produces fixed-length output
- H(x) is relatively easy to compute (ideally linear)
- **One way property**: for any given value y, is computationally infeasible (doesn't exist an efficient algorithm) to find x such that H(x) = y (cannot revert hash function)
- **Weak collision resistance**: is computationally infeasible to find y!=x such that H(x)=H(y), for any given x (the idea is to fix x and try different y)
- **Strong collision resistance**: is computationally infeasible to find a couple (x,y) such that H(x)=H(y) (stronger, implies various x and y)

## Application
*One way* is useful to authorization techniques: A->B: M||H(M||S) where S is a secret.
*Weak collision resistance*:
	- prevents forgery when encrypted hash code is used: A->B: M||E(K,H(M))
	- an attacker can't (efficiently) find a M' as already said, neither H(M) because is encrypted with a key K not known to him
	- useful to protect password p saved as H(p) in a password file (server will compare hash codes on login, looking to the corrispondence to username)
		- depending on context, hash code can be bruteforced (4 char long password can be bruteforced trying 26^4 possible tentatives (that corrisponds to hashcodes), where at least two have the same hash code; while 26^8 (8 chars long) is enough to be secure)
		- often combined with **salt** (e.g. E(s,H(s||p))) to protect against **dictionary attack** (attack based on lists of common password, with pre-computed hash codes)
			- attacker now have to get the right pre-computed hash code and salt value that has been concatenated to obtain the complete hash code; moreover the same password can now differ in hash code (because of the different value of salt)
			  In this case *having a not easy H function is useful*: if the server needs 1 sec to compute the function, an attacker will need 1 sec to try every tentative.
*Strong collision resistance* is useful against birthday attack.

### Birthday paradox
Let H have 2^m possible outputs. H must be applied to 2^(m/2) inputs so that probability of collision is greater than 0.5.

### Birthday attack explained
B (malicious) generate "good" messages x1,x2... for A (victim), which A accepts. In the meanwhile B generates some alternative "bad" messages y1,y2...; when h(xi) = h(yi) he stops and use y (which presents similar to x) to trick A who has signed with h(xi). 
We are assuming that B can generate both M and M'.
For A content is good and signed but the hash code of the documents is the same of the alternative y and so B can tell to the court that have received y with that hash code (that is the same of x)

64 bits hash code -> 2^64 messages to try?
Not really, on average work required is in the order of 2^32 to find collision (remembering that single changes of bits change completely the hash code)

Examples of hash function:
- MD5 (128 bit hashes) - known weakness
- SHA (160 bit hashes) - assumed secure today

Hash code structure:
![[HashCode_Structure.png]]