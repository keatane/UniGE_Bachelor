# Symmetric Cryptography algorithms
Two categories of ciphers:
- <span style="color:#008000">block ciphers</span>: process message in blocks when encrypting/decrypting
	- fixed size of blocks (64-128 bit)
	- larger message can be splitted in smaller blocks
- <span style="color:#008000">stream cipher</span>: process message a bit / byte a time when encrypting/decrypting
	- unbounded length of message
	- SSL/TLS used by browser

## Block ciphers
The idea looks like a big substitution: it needs a table of 2^n entries (4 bit input = 16 possible combinations; key size of n * 2^n for a total of (2^n)! possible transformations.

### Feistel cipher
We can product <span style="color:yellow; font-weight:bold">stronger ciphers from combining simpler ciphers</span>. 
Of a block cipher length of n, key has size of k bits and so we have 2^k possible transformations than (2^n)!

### Claude Shannon and Substitution-Permutation cipher
- Create the base of modern ciphers
- objective: <span style="color:#008000">confusion</span> (substitution) and <span style="color:#008000">diffusion</span> (permutation) of messages and keys
- confusion and diffusion <span style="color:yellow; font-weight:bold">are applied multiple times</span>

### Feistel cipher structure
Partition input of length r in two halves L0 and R0: 
	- process the round function on first half (with subkey formed from key)
	- process XOR between L0 and F(k,R0)
	- invert the operation input: the new L0 is R1 and the R0 is L1.

![[Feistel Structure.png]]

The functionality of en(de)cryption is made through the same structure: decryption just starts with Lr, Rr and kr, stepping to Lr-1, Rr-1 and kr-1.
Lr = Rr-1
Rr = Lr-1 xor F(kr, Rr-1)
Fact: Rr xor Lr-1 = F(kr, Rr-1)
and we can decrypt: Rr xor F(kr, Lr) = Rr xor F(kr, Rr-1) = Rr xor (Rr xor Lr-1) = Lr-1

![[Feistel Structure Decryption.png]]

*Features*
- block and key size
- num of rounds
- fast en/decr.
- ease of analysis

### Data Encryption Standard (DES)
Block cipher, key uses 56 bit expressed as 64 (8 bit are used for parity check).
Is successful but key is very short (and so deprecated, now we use 3DES).

Uses 16 rounds of Feistel + key-scheduler (derives ki from K where k1 is compressed from 56 to 48 bit). The function F consists of two permutation and one s-box substitution; implements expansion permutation to 48, together with the key.

![[DES - 1 round.png]]

DES exhibits strong **avalanche effect**: if 1 bit in plain text or key changes, half bits of cipher text change. 
DES 56 bit keys have 2^56 possible values, brute force looks hard but is possible.
DES is strong against analyst and timing attack (depending on the input value)
Moreover it produces an electromagnetic emission, so for example on a smartcard, it is possible to exploit the time spent to encrypt or decrypt the cipher.

### Double-DES
It performs two encryptions: P -> E(k1) -> (produces X) -> E(k2) -> C where the keys used may differ.
Attack: **Meet-In-The-Middle**
	- given P and C encrypt all 2^56 keys
	- sort by X
	- decrypt C with all possible 2^56 k2, looking for a match
	- each hit must be validated against a new pair of P and C (for P, the average num of 112 bit keys that will produce C is 2^112/2^64 = 2^48 (less secure))
	- effort of encrypt can be associated 2^56 operations

### Triple DES
P -> E -> D -> E -> C where E1 produces X1 and E2 produces X2.
The key for E can be the same and so is like having 112 bit key.
Reverting order is for decrypting.

No known practical attack: brute force with 2^112 bit operation.
We could use different keys for better and strong security (used for PGP and S-MIME): it is called 3DES: C = Ek3(Dk2(Ek1(P)))

### Advanced Encryption Standard (AES)
Family of Rijndael (block size between 128 and 256 bits)
- block size of 128 bit
- three different key size (depending on security we need): 128, 192, 256 bits.
- fast both on software and hardware

Do not use Feistel network, but uses permutations and substitutions.
The key size specify the num of repetition of transformation rounds for converting P to C: 
	- 10 cycles of repetition for 128 bit keys
	- 12 " " 192
	- 14 " " 256