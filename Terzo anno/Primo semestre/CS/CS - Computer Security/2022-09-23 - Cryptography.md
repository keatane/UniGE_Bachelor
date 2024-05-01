
# Cryptography
Objective: turn an <span style="color:#008000">untrustworthy</span> channel to a <span style="color:#008000">trustworthy</span> one
	- confidentiality: info remains secret, no-one overhear
	- integrity: no info corruption or alteration
	- authentication: principals know who they are speaking to.

![[Cryptographic Scheme.png]]

What cryptography does is encrypt with a key a <span style="color:#008000">plain text</span> to a <span style="color:#008000">cypher text</span>.

## Steganography
Action of hide and embed a message in another one, which appear not much altered from the original (e.g. an image, an audio or a text).
About the image, it is represented as a matrix of pixel (each pixel is 8 byte)
<span style="color:orange; font-weight:bold">Idea</span>: to flip the least significant bit of each pixel for the number of pixel necessary to embed the entire message.
<span style="color:orange; font-weight:bold">Weakness</span>: altered images can be detected. After doing a zoom on the matrix, we expect similar and uniform colours surrounding, for example, a white pixel. If the surroundings aren't uniform or they're random, there can have been an alteration.

## Cryptography system
P - plain text
C - cipher text
E - encryption
D - decryption
k1, k2 - keys

<span style="color:yellow; font-weight:bold">E<sub>k1</sub> (P) = C</span>
<span style="color:yellow; font-weight:bold">D<sub>k2</sub> (C) = P</span>

Security depends on *secrecy of keys* and not of algorithms.
We have two kinds of encryption:
- <span style="color:#008000">symmetric encryption</span>: key1 = key2 (or derived)
- <span style="color:#008000">asymmetric (public key) encryption</span>: key1 != key2;
	- public key can be published *without comprimising* the private key

In a symmetric encryption the key has to be distributed in a secure way, this is known as the <span style="color:#008000">key exchange problem</span>.

## Cryptoanalyst
Is the person who try to get the plain text from the cypher text or the key, to show weakness of the crypthographic system. This is simply done by observing the cryptographic method; so using the same key to encrypt multiple message helps the cryptoanalyst learning the system, so key needs to be refreshed and shared securely again.
A malicious cryptoanalyst is an <span style="color:#008000">attacker</span>.

## Type of security
- **unconditional security**: the system is secure even if the adversary has unbounded computing power to break the system. Security is measured using Information Theory.
- **conditional security**: the system is mostly secure but can be broken, even if this requires more computing power than a realistic adversary would have. Security is measured using Complexity Theory.

## Cryptoanalysis
Science of recovering the plaintext from the cipher text without the key. Can be done through:
- <span style="color:#008000">brute force attack</span>, always possible but expensive, consist of trying every possible combination
- cryptoanalytic attack

In a cryptography system, keys assume values taken by a <span style="color:#008000">key space</span>.

As countermisures to attacks, it can be applied <span style="color:#008000">security of obscurity</span> that is not sharing info about the device / cryptographics algorithm that we want to protect and apply. The problems is that if a problem occur only the developers of that group can operate, no-one external can detect any problem and neither help.

## Kind of attacks
- **cipher text only**: cipher text is known only, so the cryptoanalyst (CA) must deduce the algorithm from the cipher text to decrypt it.
- **known plain text** (rare): plain text and cypher text are known; CA must inverse the key or deduce the algorithm.
- **chosen plain text**: as before but CA can choose the plain text to use.
- **adaptive chosen plain text**: as before but CA can edit plain text based on encryption results (at runtime).
- **chosen cypher text**: CA can choose the cypher text to decrypt.


## Mathematical formalization (28-09-22)
- A <span style="color:#008000">alphabet</span>, finite set
- M contained in A* is a <span style="color:#008000">message space</span>
- m of M is a <span style="color:#008000">plain text</span> (message)
- C <span style="color:#008000">cipher text space</span>, which alphabet can differ from A
- K <span style="color:#008000">keyspace</span> of keys
- e of K is a <span style="color:#008000">bijective function</span> (in order to be invertible) from M to C denoted Ee, which is the encryption function
- d of K is a bijective function (in order to be invertible) from C to M denoted Dd, which is the decryption function
- <span style="color:yellow; font-weight:bold">Invertibility is necessary to decrypt an encrypted message</span>
- Keys e and d forms a key pair (e,d)
- Property: <span style="color:yellow; font-weight:bold">Dd(Ee(m)) = m</span> for all m of M
- The number of bijection is n, as the cardinality of C

## Symmetric encryption
- Uses the <span style="color:yellow; font-weight:bold">same key to encrypt and decrypt</span> (e = d)
- There are different families

### Substitution family
- Idea: replace each plain text character with another
- Example:
	- Caesar cipher: shift right by 3 mod 26. The key is fixed and simple to break.
	- ROT13: same as before, but shift of 13. Used by Unix.
	- alphanumeric: replace numbers for letters

#### Monoalphabetic substitution cipher
Ee(m) = e(m1)e(m2)...e(mn) = c1c2...cn = c
Dd(c) = d(c1)d(c2)...d(cn) = m

- 26! permutation, can choose one and apply to A, obtaining a new set of characters

![[Monoalphabetic Example.png]]

_Affine cipher_
is an application of above
- e(m) = (a * m + b) mod|A| with a and b positive integers
- for the cipher to be invertible, a and |A| must be *relatively prime*: the only number that divides both is 1
- D(c) = a^-1 (c-b) mod|A|
- 1 = a * a^-1 mod|A|

_Frequency analysis_
From above we obtained 26! permutation, a huge amount of keys. But those can be easily cracked with a frequency analysis of letters and digrams. So a guess could be associate high frequent chars with low ones (e.g 'p' for 'w').

#### Homophonic substitution cipher
- Replace each char with a randomly chosen string from a set H
- The number of keys is the number of possibile sets H that can be formed

Example:
A = {x,y}
H(x) = {00,01}
H(y) = {10,11}
So 'xy' can be written 0010 or 0110 etc.
- Pro: more difficulty to apply frequency analysis
- Cons: more expensive data

#### Polyalphabetic substitution cipher
- Operates on blocks of char of t length
- is a sequence of permutations
- m = m1m2... under key e = (e1...et)
- Encryption is Ee(m) = c1c2... where ei = e(i mod t) (mi) for i = 1,2...
- Decryption for e is d = (e1^-1 ... et^-1)

Idea: for each letter (position) in a block I choose a permutation which iterate between blocks.
Note: if key is an entire alphabet (permutated) it's very long, and so 26! keys is expensive

_Vigenere cipher_
- is a specification of above: permutations are sets of numbers k1,k2...
- ei(b) = (b + ki) mod |A| for all b of A with i=1,...,t

![[Vigenere Example.png]]


#### One time pads (Vernam cipher)
- stream based cipher defined on A = {0,1}
- message is encrypted by a randomly chosen key string k = k1,...,kn using XOR bitwise.
	- note: usually k is very long (as the message)
- Ek1...kn(m1...mn) = (m1 xor k1)...(mn xor kn)
- Dk1...kn(c1...cn) = (c xor k1)...(cn xor kn)
- there are as many cipher texts as plain texts (each plaintext produces an unique cipher text)
- <span style="color:yellow; font-weight:bold">Unconditional Security</span> if key isn't reused
	-  Otherwise: 
		- given C1 = S xor m1 and C2 = S xor m2 with m1,m2 plain texts and S the same cipher key
		- C1 xor C2 = (S xor m1) xor (S xor m2) = m1 xor m2
		- Because of English redundancy, an attacker can obtain m1 and m2 (sufficently long) in clear.

#### Homomorphic encryption
We identify three approaches between a local machine and a cloud, in which we want to store our files (premise: the transfer channel is already a secure channel):
- no security, but efficient
	- we send the file in clear, without encryption
		- do we trust the cloud provider?
		- cloud platforms may be vulnerable
- secure, but inefficient
	- we encrypt (take time) the file and then send to the cloud
		- if we want to update our entry, we must download the file, modify it and then re-upload to the cloud (because cloud doesn't have the key to decrypt)
- Ideal: secure and efficient
	- the file is sent encrypted but we allow some transformation on encrypted data by provider itself without knowing the key
That ideal is obtained through <span style="color:#008000">malleability</span>.

##### Malleability of one-time pads
An encryption function is malleable if there exists two function F(X) and G(X) such that:
<span style="color:yellow; font-weight:bold">F(E(K,M)) = E(K,G(M))</span> for all keys K and message M

E(K,M) = K xor M is clearly malleable
F(X) = G(X) = N xor X
so F(E(K,M)) = N xor ( K xor M) = K xor (N xor M) = E(K,G(M))

**Corollary**: to turn C1 = K xor M1 to C2 = K xor M2 it sufficies to compute:
<span style="color:yellow; font-weight:bold">C1 xor (M1 xor M2) = (K xor M1) xor (M1 xor M2) = K xor M2</span>

This approach has its weaknesses and can be exploited.

### Transposition cipher family
The idea is not to replace but <span style="color:yellow; font-weight:bold">scramble</span> the characters (change their relative position).
E.g. "Hello" (12345) to "Lohle" (35142)

Ee = me(1)me(2)...me(t) where t is the length of the message (and not of alphabet 26!)
Dd = cd(1)cd(2)...cd(t) where d is inverse permutation

Weakness: letters unchanged so one can exploit by frequency analysis for dipthongs etc.

### Composite cipher family
Since combining two or more substitution cipher with another one, or transposition with another one is not more secure, it turns out that <span style="color:yellow; font-weight:bold">combining substitution with transposition is more secure</span>. 
- That permitted to invent cipher machines (since substitution and transposition were difficult by hand).
- Turing reached to break it with Enigma (through an attack similar to brute force)