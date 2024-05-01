# Message Authentication
Obj: not to repudiate the authority of a message
Must preserve message **integrity**: check if received message has been altered while transiting.

The function of authentication creates an **authenticator**: a string of bits that can be used to authenticate the message. 
Possible authentication functions:
- message encryption: ciphertext alone server as authenticator (can be very long to be sufficient to integrity check)
- message authentication code (MAC): add a secret key over the message to create the authenticator (that is of fixed-length)
- cryptographic hash function: maps a message of any length into a fixed-length value that serves as authenticator

## Message Authentication Code
MAC function produces fixed-size output: C(M,K) with M and K of same length, that allow to verify the message
- MAC length is independent from length of M and K
- MAC function is many-to-one function: many M can have same MAC (called also cryptographic checksum)
- if an intruder alter the message M between A and B, when B receive M' and try to do the checksum, recognize the difference of MAC values. That is because the attacker doesn't know K (between A and B)
- MAC algorithm is based on DES (deprecated today)
	- idea: M splitted into Di blocks: M = D1D2...DN

![[Data Auth Algorithm.png]]

Because it's a many-to-one function, the objective of an attacker is to try to find a "good" M' such that E(M',Kab) = E(M,Kab). Every message should have a different auth code but it isn't the case; so we have a **collision**: M and M' with same MAC
	- note: **to find those different M and M' isn't still so easy** (depends moreover on DAC - number of bits of cipher text)

## Hash function
- Doesn't use a key, but applies just to the message. The output is fixed (e.g. 64,128)
- Has a strong avalanche effect
- h(M) is called hash code (message digest)
- in general, h functions are known to attackers
	- so an intruder could alter the message in transit and re-calculate the hash function of altered message M', so that B receive just the altered version

To avoid alteration, over the message M, the encryption E(Kab, h(M)) is send as auth code. So Kab (whose size depends on E) isn't known to the attacker, moreover the authentication code is not so long anymore: h(M) is fixed-length (so authentication code size remains fixed)

h(M) is called **digital fingerprint** or **hash code** of M
Still can have same hash code for two different M and M', but still so difficult is to find these two messages.
An alternative to E(Kab,h(M)) is using h(M || S) where S is a secret (not necessarily "a key" shared between A and B; note that a "key" is a secret itself but it has its structure and definition, the secret here is more general)

Hash function overview:
[[2022-10-17 - Hash functions]]
