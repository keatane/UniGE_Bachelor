# Web Security

Hypertexts are transfered via HTTP protocol (application level) between the server and the browser.
- user navigates via URL
- HTTP doesn't supports sessions (stateless)

Moreover data can be:
- static (e.g. HTML pages)
- dynamic (e.g. computed on demand by a web application)

Scripting can occur on:
- server side (e.g. php)
- client side (e.g. javascript)

HTTP transfers are managed in a three tier architecture:
- presentation
- business logic
- backend (with DB)

Two type of request: GET and POST
- POST: we have a separate payload attached to the body of the request
- GET: the requested info can be seen in the URL (so in the header)
	- if some parameters are passed, they are stored in the history!

HTTP header contains:
- requested language
- requested char encoding
- cookies
- other info

Critical info:
- FROM: user email address
- AUTHORIZATION (authentication)
- COOKIE
- REFERER: page from which the client cam including search terms
With FROM and REFERER + IP Address, for the server is possible to track the user

Note that HTTP sends these info unencrypted, HTTPS does encryption


## Cookies

Note: HTTP remains stateless

Allow session management. Structure: Name = Value
- server can include cookie
- client send cookie back in every request

Cookie has a lifetime and can contain any data 
Used to distribute information with the client
	- server can restore the session with the client by reading info stored in cookie SESSION_ID
	- servers use less resources (no cookie storing on server machines)

Obj of attacker is to obtain the session_id cookie (to impersonate another user)
If server drops the session it means that every other connection with that session_id is rejected.
	- so we have lifetime on cookies for security purpose (past the estimated lifetime session is dropped)

## HTTP Authentication

Two modes
- basic authentication:
	- login/psw based
	- info sent unencrypted
	- credentials sent for every request
- digest authentication
	- server sends nonce
	- client hashes nonce based on login/psw
		- e.g. h(U||P||n) is sent
	- client sends only hash values over the net

## Web vulnerabilities / attacks

These attacks don't involve cryptography attack, authorization neither
They exploit programming or configuration flaws.

- **Injection flaw - Unvalidated input**
	- idea: to send unexpected data (exploiting the correct char sequence)
	- attack examples: SQL injection, XSS, XSRF, exploiting buffer overflow, privileged system command insertions
	- solutions: validate inputs **server-side** (just javascript on client-side isn't enough!!)
	Note that browser allocates a virtual memory for each tab opened; that means that if malicious code came from one tab, this can't access to other opened pages.
	This is known as **Same Origin Policy**: only code coming from a certain server can access the DOM of that response page; same origin = same domain, protocol and port.

	**Cross-site scripting** can bypass that policy:
	a basilar XSS vulnerability is when a site echo part of HTTP request in the response without sanitizing it; some malicious code can be injected and some non-foreseen code still coming from the same domain is executed -> but no more Same Origin Policy in fact!
	Moreover note that some sensitive infos can be shown (e.g. cookies) but also sent to another site.
	
	*Solutions*:
	- validate input
	- use X-XSS protection HTTP response header done by the browser XSS auditor
	- using some directives to instruct the browser
	
	**Cross-site Request Foregery (CSRF)** attack occurs when a malicious site, email, program causes a web browser to perform unwanted action of trusted site in which user is authenticated. For example by changing the code behind a button (done by injecting some script)
	
	**Clickjacking** attack consists of "steal" clicks from users: there is some "UI redressing" of a target page through frames that overlap and through transparency. This can be injected into a page or use the target page as a frame.
	
	*Solution*s
	The page can assert not to be loaded in a frame, so that the same page can't be loaded in different domains: X-Frame-Options: DENY.

- **Broken Access Control vulnerability**: set of critical possible flaws on session and credential management.