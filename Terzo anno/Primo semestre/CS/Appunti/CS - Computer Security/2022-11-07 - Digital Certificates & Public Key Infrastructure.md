# Digital Certificates & Public Key Infrastructure

Provide
- key distribution
- authentication (with non-repudiation)
	- digital signature
Those are used in the web
Have expiration: the Public Key Infrastructure provides rules to organise them.

PK **suffer to authentication problem**: we must provide the guarantee of the identity of someone on the web (e.g. a website) who share his public key. Man-in-the-middle attack is possible.

Digital certificate allow the relying party to verify the authenticity of public key.
Binds PU to Owner's name (domain name). Issuer is the certification authority (CA).
Also certificates are digitally signed:
	- the validity of certificates is provided by checking the digital signature, that is the check of PU of the Issuer. This is simple because Issuers are in a little number and 'already known' to browsers.
This counter man-in-the-middle attack.

Issuer can be a private company which puts its computational power to create valid digital certificates (paid by who want to be verified).
Between the issuer and the customer there is a Registration Authority: while issuer craft certificate, the second provide their validation over the customers that meets some requirements.

Some **root certificate** are built-in by SW vendors on their SW (e.g. browsers), that consists of info on CA.
There exists an **hierarchy** of CA: a 'root CA' certificate the validity of other 'sub'-issuers. The root certificate is sent only by root CA to SW vendors.

## Certificate revocation

Any CA can revoke a certificate (e.g. if a corruption occurs). Those are contained in lists (CRL) and are managed by CRL distribution points towards clients (who can access and verify). Those lists can be long (so checking costs time) so a server called OCSP responder is introduced and dialogue with clients to query the list in a more efficient way (that is done once in while). 
	- Note: if a channel to CRL is slow, browser tends to assume that there is no revocation of certification for that site
Note that private key of customers (who wants to be certified) **mustn't** be shared with CA.

![[Public_Key_Infrastructure.png]]


## Types of digital certificates
- Domain Validation (DV): most popular. The validation is done by CA on the domain name, checking if the requester has effective control over that domain (no verification on real-world identity nor organization)
- Organization Validation (OV) and Extended Validation (EV) certificate has the process of verification (through form compilation) of real-world identity of requester.