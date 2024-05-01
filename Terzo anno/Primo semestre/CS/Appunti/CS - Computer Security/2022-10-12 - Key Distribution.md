# Key Distribution
## Possible approaches
- A deliver to B physically the key
- A and B use third party to deliver the key
- A and B use a key to encrypt another key
- if A and B trust C to whom communicate, C deliver key

## Hierarchy of keys
- **master key**: used for long period of time, used to encrypt session keys
- **session key**: is temporaly key thrown away after encrypt some data

## Needham - Schroder shared key protocol
Obj: share a fresh key between A and B

![[Key_Distribution_Scenario.png]]

**Properties to met**
- *secrecy* of the session key (Ks)
- *freshness* of Ks, each couple A and B has a different shared generated key
- *key authentication*

The protocol consists of 5 steps
1) A send message with identity of A (IDa) concatenated with IDb and a number N1 that is the request ID, to a trusted third party agent (KDC, Key Distribution Center)
	- KDC server is open to DOS attack
	- to avoid DOS, the message from A to KDC can be encrypted, but that would add more work on KDC server (=overload), that we want to avoid
2) KDC reply to A with two parts concatenated (both encrypted with Ka, that only A can decrypt):
	- first part A can decrypt and obtain the generated session key Ks, concatenated with IDa, IDb and a number (N1)
		- **note_1**: N1 is important because in case of overloading of requests, they can be identified correctly and moreover shows if an attacker altered the message.
		- **note_2**: master key can be derived and distributed from user credentials (exhanged with the server); other devices (e.g. a printer) uses different protocols to distribute the key.
		- secrecy and freshness of Ks is guaranteed
	- second part consists of Ks with IDa encrypted with Kb, that A doesn't know
3) A forwards the Kb encrypted part to B. KDC doesn't talk with B directly to avoid more overload of communication and so limits to A (of couple A,B).
   B can send encrypted message with Ks but has to be secure that only A can decrypt. This is ensured on the message received by B, where Ks is bind to IDa (and so to A).

Possible threat: **replay attack**
Assuming that N1 on 2) doesn't exists, an old response (where Ks has been already created) that KDC sent to A can be picked by an attacker (KDC refuse more identical request) and send again the same Ks to A. So future message between A and B will be encrypted with the same key for a long period of time.
**Weakness of protocol**: B cannot check freshness of Ks. If Ks is compromised, it can replayed by an attacker.

**NONCE property** (Number used only once) - replay protection mechanism: every request should use a new fresh key

4) B send to A an encrypted message, but if had no protection from replay attack, an attacker can create a vulnerability. So a new number N2 is used to identify the request.
5) A reply with another encrypted message with Ks and a known (by A and B) function applied to N2 (function different from identity) and so that B can recognize and so use securely the key to exhange securely message between A and B

That is a possible approach to key distribution. 
Internet use a different approach based on public key distribution (Kerberos protocol).