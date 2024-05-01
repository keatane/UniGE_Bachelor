# Security Protocols

Problems without: **replay attack**, messages can be replicated by an attacker impersonating a trusted person

**Procol**: set of rules that determine the exchange of messages
**Security protocols** uses cryptographic mechanism to achieve security objectives (such as message authentication, integrity...)
Example: Remote Keyless System

In general we have an Initiator (I) and a Responder (R) that are roles. Those can be instantiated by any principal in a communication.

Example of actions depends on context:
I -> R: {I, Ti, PRK(R)}(PUK(R))
R -> I: {R,I}(PRK(R))

Note that R can't verify the autenticity of I and authenticate I. Moreover confidentiality of keys is preserved.
Protocols specify actions of principals and defines a set of event sequences (**traces**).
Communication is asynchronous between different runs of protocol: when we have **concurrency** there could be some problems.

*Assumptions for principals*
- must know their PR and PU of others
- can generate /check nonce, timestamps, encrypt, decrypt
- (Honest) principals implement correctly the protocol

*Goal of security protocols*
- authenticate message, binding them to their originator
- ensure timeliness of message (recent, fresh...)
- guarantee secrecy of certain items (e.g. generated keys)

An attacker:
- knows the protocol but cannot break crypto (assumption)
- is passive but overhears all communications
- (or) is active and can intercept and generate message
- could be one of the principals running the protocol

## Dolev-Yao attacker model

The attacker:
- can intercept and read all messages
- can decompose messages but can't break crypto
- can build new messages
- can send messages anytime

Strongest assumption: even if an attacker is in control of the network, the protocol still impossibilitate the attacker achieving the message.

## Kinds of attack
- replay message
- man in the middle
- reflection
- type flow

## NSPK protocol

Goal: mutual authentication

1) A produces nonce Na
2) B reads Na, so he asserts that the is B. Send challenge Nb to A
	- here B gather the security of identity of A (because B use PU of A to encrypt the challenge)
3) A reads Nb. Sinche only A can read Nb and sent it back, she must be A.

The message is authentic and is fresh thanks to the nounce (A and B just check if the received nounce is the same of their one sent)

![[NSPK_Protocol.png]]


Goal must be hold between different runs of the protocol.


Suffer to **man-in-the-middle attack**:
- concurrent runs of the protocol
- A wants to talk with C
- A doesn't know that C is bad: the protocol is initiated
- then C impersonate A in a communication with B
- When B sends {Na, Nb}(Ka) C has only to replay it
- The idea is that Na and Nb (replied, assumed of C by A) are sent by A using PU of C
- As result B believes he is talking to A (note that A didn't want to talk with B, but now C can impersonate A and make B believe on some actions of 'A')

### Possible fix: NPSK with Lowe's fix

If the encrypted message sent by B has the identity in, A can recognize the identity of B that differs from C!
We obtain {Na, Nb, B}(Ka)

## Type flow attacks

Message consists of a sequence of submessages. Those are strings of bits, no type information.

Type flow is when A->B: M and B accepts M as valid but parses/interprets it differently.
Examples following.


## The Otway-Rees Protocol

![[Otway-Rees_Protocol.png]]


Type flow / reflection attack: if |{I,A,B}| = |{Kab}|
A -> M(B): I,A,B, {Na, I, A, B}(Kas)
M(B) -> A: I, {Na, I, A, B}(Kas)
where M is an attacker who intercepts messages of A; Kab is a key shared between A and B

We have the same message as before
I,A,B interpreted as session key!

Another kind of attack is by impersonating the server and replay back the message to the agents A and B (**Andrew Secure RPC protocol**, suffers to the same attack)

### How to fix type flow vulnerability?

Must assume the type information
The idea is to add some bits to types and encode them in the message (following a certain encoding agreed by the two parts)

{Na, I, A, B}(Kas)
{Na, Kab}(Kas)

We have 4 types (e.g):
- nounce - 16
- protocols runs - 32
- agents - 16
- keys - 128
We can add a prefix for each type, respectevely 00, 01, 10, 11


## Key exchange with CA (Denning & Sacco)

A -> S: A,B
S->A: Ca, Cb
A->B: Ca, Cb, {{Ta, Kab}(Ka-1)}(Kb)
where C is certificate, T timestamp and Ka-1 the private key used to sign

Problem: Man-in-the-middle-attack

A->C: Ca, Cc, {{Ta, Kac}(Ka-1)}(Kc)
C->B: Ca, Cb, {{Ta, Kac}(Ka-1)}(Kb)

We can defend by adding identities: {{Ta, Kac}(Ka-1)}(Kb) transform into {{A, C, Ta, Kac}(Ka-1)}(Kb)
B recognize C and not him in the communication!

## Principles of Abadi-Needham

![[Prudent_engineer_prop_1.png]]![[Prudent_engineer_prop_2.png]]


## Kerberos
Based on Needham-Schroder shared-key protocol
Is a protocol for authentication / access control for client-server applications
-> allow clients to perform a secure connection to a server

*Aims*
- user's password must not traver over the network
- user's password must not be stored in the client machine (secondary memory)
- user's password must not be stored in unencrypted way even in the server auth DB
- single sign-on per work session (key is shared once)
- authentication info resides only on the authentication server (app server must not have those info)
- mutual authentication: as client demonstrate their identity, so the server has to do (client authenticate the server)
- client and server must be able to establish an encrypted connection


*Requirements*
- Secure: one person can't impersonate another
- Reliable: must have a system backup and support distributed architecture
- Transparent: user should enter a single psw, otherwise must be unaware of underlying protocols
- Scalable: must support large number of users and servers
	- modular, distributed architecture
	- federation of auth server if two companies merge

*Protocol differences from Needham-Schroder*:
- no nested encryption
- timestamp instead of nonce to assure freshness of session keys (less steps)

![[Kerberos_Auth_Protocol.png]]
(A,T2) is sent to show that A commits into Kab


### Version IV

**KAS** (auth server) - Authentication - once per user login session
**TGS** (ticket granting server) - Authorization - once per type of service
**Service** - once per service session

### Authentication phase
1) A -> KAS: A, TGS
2) KAS -> A: {{Ka,tgs, TGS, T1}Kas}, {A, TGS, Ka,tgs T1}Kas,tgs}Kas
	note: external encryption is removed in kerberos V

- A wants a session key with TGS (Ka,tgs)
- Kas is derived from user psw, this is a temporaly sessione key used to encrypt the session key between A and TGS
- Ka,tgs has lifetime of several hours
- Both user and server keys must be registered in the KAS db
- After decrypting received info with their password, the user's password is forgotten, ticket ad session key are saved. The user A is logged out when Ka,tgs expires

### Authorization phase
3) A -> TGS: {A, TGS, Ka,tgs, T1}Kkas,tgs, {A,T2}Ka,tgs, B
4) TGS -> A: {Ka,b, B, T3}Ka,tgs, {A,B, Ka,b, T3}Kbs

Here user is no longer necessary: if tickets have to be renowed, it is done automatically.

### Service phase
5) A -> B: {A,B,Kab,T3}Kbs, {A,T4}Kab
6) B -> A: {T4+1}

## Inter-realm communication

When client wants to access to remote server, the client asks to local TGS the ticket for accessing remote TGS (instead of a service). Then the client can communicate with remote TGS to get accesso to remote app server.

## Limitation of Kerberos IV
- encryption not necessary but an attacker can flood S (DOS attack)
- nested encryption not necessary (removed in Kerberos V)
- relies on clock and their synchronization