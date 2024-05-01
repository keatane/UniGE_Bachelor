# Review questions

## Introduction
- Describe the meaning of assets and threats, with their relation.
- Tell the 5 Security Properties.

## Cryptography
- What does cryptography do?
- What is steganography?
- Explain in general the two kinds of encryption.
- Who is the cryptoanalyst?
- Describe the two kinds of security.
- What is and why isn't used the "security of obscurity"?
- Describe the 5 type of attacks to a cryptographic system.
- Describe the Monoalphabetic substitution cipher and Affine cipher.
- Describe the Homophonic cipher.
- Describe the Polyalphabetic substitution cipher and Vigenère cipher.
- Describe the One time pads (Vernam cipher).
- What is frequency analysis? What kind of cipher could crack easily?
- Which is the ideal of Homomorphic encryption? How is it obtained?
- Explain the idea of Transposition ciphers.
- Explain the idea of Composite ciphers.

## Symmetric Cryptography
- What is the difference between block and stream ciphers?
- What is the idea of Feistel cipher structure?
- What are the objectives of Claude Shannon S-P ciphers?
- Describe DES and why is deprecated today. Which versions have been developed?
- Describe AES.

## Modes of operation
- Describe the difference between Electronic Codebook and Cipher-Block Chaining
- What are Stream ciphers?
- Where to place encryptions? Which layers?
- Tell the possible countermeasures to traffic analysis.

## Key Distribution
- Tell the difference between master and session key.
- What are the properties to met about key distribution?
- Describe the Needham-Schroder shared key protocol.

## Message Authentication & Digital Signature
- Why message authentication is important?
- What are MAC?
- Describe the concept of collision and why it can or not be problematic.
- Describe the hash function
- What is and why the digital signature is important over authentication? In what differs?

## Hash functions
- What are the properties of hash functions?
- Describe some applications of hash function.
- What is a birthday attack?

## PGP
- List some of the services provided by PGP. What is GPG?
- Explain the cryptographic functions of PGP (confidentiality and authentication)
- How is generated a message in PGP?
- Talk about data protection, which kinds exist? What is the problem of key-rings integrity?

## Public key encryption
- What are the requirements in order to apply public key encryption?
- What are one-way function (in this context)?
- What trapdoor means?
- What kinds of attack can be done against this kind of encryption?
- What are modular arithmetic and euler totient function applied to?
- Explain how RSA algorithm works.
- What does mean that RSA is malleable? Is it a problem?
- What are the problems about key distribution with RSA? What is the Perfect Forward Secrecy property? 
- Describe the Diffie-Hellman algorithm.
- What is man in the middle attack?
- What is the HW security model? Why is it useful with RSA?
- What are some possible approaches to protect private keys in digital signature?

## Digital Certificates & Public Key Infrastructure

- What is man-in-the-middle attack and why digital certificates are useful to counter that?
- Describe generally the PKI.
- Describe the two (three) types of Digital Certificates.

## Security Protocols
- What is a protocol?
- What are the goals of security protocols?
- Descibe the Dolev-Yao attacker model.
- List kinds of attack that exists in this context.
- What is NSPK protocol? Which attack suffer and why?
- What is type flow attack?
- Describe the Otway-Rees protocol and its vulnerability. Which is an example of similar protocol that suffers to same kind of attack?
- How would you fix the type flow vulnerability?
- Explain how key-exchange with CA (Denning & Sacco) works and how to fix its vulnerability.
- List some of the principles of Abadi-Needham.
- What is Kerberos? What are its aims?
- Describe the three phases of Kerberos.
- What are the limitation for Kerberos IV?

## Internet Security
- How is transport layer implemented in SSL and IPsec?
- Describe IPsec with AH, ESP, IKE.

## Buffer overflow
- Describe the threat and the possible solutions.

## Web Security
- Describe the HTTP protocol.
- What are cookies, why are they useful?
- Describe the two types of HTTP authentication.
- What is a injection flaw by unvalidated input?
- What is SQL Injection?
- What is XSS?
- What is CSRF?
- What is Clickjacking?
- What does Broken Access Control vulnerability mean?

## Access Control

- What is a security policy? Describe the three main categories.
- What is a reference monitor?
- What does mean that a system is 'secure'?
- How can a protection system be represented?
- How UNIX manage control access?
- What vulnerability is DAC open to?
- Describe MAC and tell some model examples.
- What is RBAC?
- For which purpose is ARBAC used to?