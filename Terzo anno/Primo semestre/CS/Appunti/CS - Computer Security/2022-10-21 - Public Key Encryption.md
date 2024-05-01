# Public Key encryption

Born as discovery of two problems: key exhange and signature patter problem.

![[PublicKeyEncryption.png]]

## Requirements
- computationally easy for B to generate a pair (PUb and Prb) (generation isn't done often)
- computationally easy for sender knowing PUb and M to generate C = E(PUb,M)
- computationally easy for B to decrypt C using PRb to recover M = D(PRb,C)
- computationally infeasible for attacker knowing PUb to determine PRb
- computationally infeasible for attacker knowing PUb and C to recover M
- (useful but not necessary) two keys can be applied in either order: 
  M = D(PUb,E(PRb,M)) = D(PRb, E(PUb,M))

At the moment these requirements focus on authenticity (everyone can decrypt and recognize me) not confidentiality (secrecy of message)

Examples: RSA, Elliptic curve, Diffie-Hellman, DSS (specification of RSA for digital signatures)

## One-way functions
We consider functions that are 'easy' to compute for all x of X but hard f^-1 to compute.
Note that these are different from one-way functions that map an input to a fixed-length output.
Example: modular cube roots
f(x) = x^3 mod n
- easy to compute for x
- hard to invert: knowing y ad n is difficult to find x such that x^3 = y mod n

## Trapdoor one-way functions
We want to invert the function if certain conditions (a "key") are met.

fk: X -> Y such that
y = fk(x) - easy if k and x are known
x = fk^-1(y) - easy if k and y are known
x = fk^-1(y) - infeasible if y known but not k (which is the **trapdoor**)

In the example above if we know the factorization of n, is not difficult to find x given y.

## Public Key Cryptoanalysis
- brute force attack: a possible countermeasure is to use large keys (note that public-key encryption is not so fast)
- computing private key from public key (no proof that's infeasible!)
- probable message attack: if M is short and PUa is known, an attacker can try all possible plaintexts Xi: Yi = E(PUa, Xi)
	- possible solution: append some random bits to M (salt)

## Prime factorization

Idea: write n as product of power of primes: n = a * b * c
Two numbers are **relatively prime** if they have no common factors (divisors) **from 1** (note that they can be not prime singularily)
The greatest common divisor (GCD) is the number determined by composing their factorization and using the least powers.

## Modular arithmetic
A property of modular arithmetic:
(a . b) =n (a mod n) . (b mod n) where . is one of {+,-,* }
=n means that "a mod n = b mod n, so a =n b"

## Euler Totient Function
Residues of mod n are 0..n-1
**Reduced set of residues** is a set of residues relatively prime to n, called Phi(n).
Phi(p) = p - 1 if p prime
Phi(pq) = Phi(p) - Phi(q) = (p-1)(q-1) if p and q primes

Euler theorem: if a and n relatively prime (GCD(a,n) = 1) then a^(Phi(n)) =n 1

## RSA algorithm
Security comes from difficulty of factoring large numbers.
Keys are functions of a pair of large prime numbers.

Let be n a number not secret. 
Plaintext split in blocks of |log2(n)| (floor) bits. Each block represents a number 0 <= M < n.
C = M^e mod n
M = C^d modn n = M^ed mod n
for some e and d

Requirements:
- possible to find values e,d,n such that M^ed mod n = M for M < n
- relatively easy to calculate
- unfeasible to determine d given e and n

The correctness of RSA rely on multiplicative inverser (x and y multiplicative inverse if xy mod r = ! )

![[RSA_Algorithms.png]]

- note that compute Phi(n) is very hard not knowing the factorization of n (in p and q)
- non deterministic (run twice, possible different but correct results)
- security on factorization: as long as we can compute factor of n = pq, we can compute 
  Phi = (p-1)(q-1) and hence d
	  no known polynomial algorithm (n at least of 1024 bits)
- no proof only by knowing PU = (e,n) and Ci we can derive Mi

**RSA is malleable**: an attacker can obtain another C by transform the first C applying F (the other C is likely a result as if computed on a message G(M)), with a message chosen by him.
So ciphertext can be altered and that can be a problem. As countermeasure we can attach some random bits (before computing RSA) such that if an alteration occurs, it is detected.

## Asymmetric key distribution
### Secret key distribution with RSA
Problem: browser talk to a 'server', but it doesn't know if server is malicious or is a pretending attacker. So an attacker can recover symmetric key (as countemeasure digital certificates are used + PKI).
Moreover server is complex, no-one knows if someone can attack and get PR; (d,n) can't be protect at rest, because we don't know who can access the server: future message can be compromised (as countermeasure I can change PR).
Note that RSA doesn't protect even against the problem that even previous encrypted session can be decrypted. To counter this we use the **Perfect Forward Secrecy**, which RSA doesn't have but **Diffie-Hellman** does.

### Diffie-Hellman Key Exchange Protocol
Cannot be used for digital signature, but enjoys perfect forward secrecy (thanks to a secret generated).

Some maths:
Primitive root 's' of a prime 'p' is a number that generate 1...p-1.
So s mod p, s^2 mod p...
For each integer b exists an i of {0,...,p-1} such that b = s^i mod p.
'i' is the **discrete logarithm** of b for base s, mod p
Apparently is infeasible to find the discrete logarithm (following as X)

![[DiffieHellman_Algorithm.png]]

Xa and Xb can (must) be deleted, no longer necessary and there is no use to store them.
Today no known method exists to break the protocol.

Weakness: **no authenticity of keys**
We have no security that the person to whom we are talking is really that person, or the possibility of that person talking with malicious ones.
Suffer to **man-in-the-middle attack**.

![[DiffieHellman_Weaknesses.png]]

### RSA problem
When the web service (server) receive the encrypted message (that is the session key) it has to access to private key and that doesn't guarantee security (anyone could access the server).
A possible solution is to introduce an external device: **HW security model (HSW)** designed only to compute cryptography. This device is strictly analyzed and assumed to be secure.
In it are uploaded and stored the private keys: when the encrypted message comes to the server, it sent it to HSW that answer with Ks.

## Protection of private key in digital signature
We can proceed with different approaches:
- using smartcards and cardreaders, such that a document can be securely signed:
	- we want to generate secrely E(pr-key, h(M))
	- smartcard is inserted into cardreader
	- cardreader dialogue with the computer who give h(M); 
	- cardreader respond with the encrypted signature
	- the signature can be embedded with the document or sent separately
	- idea: secure but not very practical
- using smartphones and NFC technology (close-range comunication)
	- the smartcard is 'internal' to the device, within itself or a computer
- remote signature
	- computer dialogue with a server which contains private keys. Server is assumed to be secure
	- server has to be certain to talk with the right person, so asks to call a phone number (with an associated sim)
	- that phone number gives to the user a pin that is inserted to authenticate and sent to the server
	- the server responds with the signature