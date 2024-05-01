# Internet Security

Based on a layered architecture (ISO-OSI) the network (internet) layer and transport layer rely on TCP/IP protocols
- tcp/ip model (also called iso model) is reduced to Application, Transport, Network, Link layers, that are abstractions
- tcp/ip model is defined on an old threat-model
- each layer adds its header to the message
- each layer communicate with the same layer of the other node

![[ISO_Protocols.png]]

Here the threat comes from the channel of communication
Usually the transport layer is implemented in the OS
- SSL (TLS/SSH): OS doesn't change, applications have the API to TCP
	- the application assumes that IP implements the transport on TCP, but the two interfaces are not equal
- IPsec: OS change, applications and TCP API rest unchanged
	- OS implements a variant of the IP that address the security problem
	- only authenticate IP addresses, no users
	- if more is wanted, API must be changed
	- security stops at host level, if more processes/operators run on it, this can be not enough

## IPSec

Provides secure channel for all applications with encryption (cryptography)
Installed
	- in OS (for end-to-end security)
	- in security gateways: route and firewall
Used for implementing VPNs
	- evolve from physical private network
	- messages flow on a dedicate owned network

IP header of a message is preserved
	- IPsec header is added
	- IP payload is transformed (cryptography) in a secure one
It can be done by networking devices or by a user system.
In this last case think the following case:
If a remote access is necessary, the user machine must be secure-aware to do IPSec such that the user can pass through the IPsec network device (otherwise it rejects the connection)

IPsec is an IETF standard, that covers a variety of purpose:
- Authentication Header (AH): protect integrity and authenticity of IP datagram
- Encapsulating Security Payload (ESP): protect confidentiality (optionally integrity)
- Key Management (IKE): key exchange

A security association is a one-way relationship between sender and receiver defining security services
	- define e.g AH, ESP, keys etc.
	- identified by field in AH/ESP including sec parameters index and destination address
	- SA established using IKE

### Authentication header (AH)

Is an extra-header between IP and ESP
There are two modes:
- transport mode:
	- AH after IP header, before IP payload
	- provides end-to-end protection between IPsec devices
	- MAC taken of the entire packet (no cover of mutuable info such as time to leave etc.)
- tunnel mode:
	- entire original packet authenticated
	- new outer ip header
	- the original one is covered by AH
	- more IP headers can be included (for firewall, gateways etc.)

### Encapsulating Security Payload (ESP)

Header specifies encryption
- Transport mode: encryption of data payload only
	- used for end-to-end between IP-Sec enabled devices
- Tunnel mode: the entire datagram is encrypted
	- can be used for VPN

#### Combining Security Associations (SA)

There can be more SA between two hosts with multiple SA tunnel (even between gateways)
So multiple encryptions.

![[Combining_Security_Associations.png]]

## Key Management (IKE)

It establishes SA
Based on Diffie-Hellman Exchange to generate and share the session key

**Note that the responder can be flooded by request** (DOS attack)
As countermeasure it can make the initiator of the request do some computation, for example cookies, that are randomly generated number, e.g. C = hash(IPaddress, secret)
So the attacker must complete (validate) cookies for each IP address it spoofs

Another problem is the suffering of man-in-the-middle attack on Diffie-Hellman (can be solved with RSA), but Diffie is still useful for Perfect Forward Secrecy.