# Modes of operation
The objective is to encrypt more than 64 bits message

## Electronic codebook
To split message in 64 bit blocks and then encrypt them with the same key
- parallelism can be used (multi-processor)
- problem: identical ciphertext blocks leak to same plaintext blocks
- problem: decryption doesn't check if cipher has been altered

## Cipher-Block Chaining
Uses XOR applied to first ciphertext block produced and the second plaintext block, before encryption. Uses initialization vector to start the chain.

To decrypt, the XOR is applied between the first cipher block and the second *decrypted* cipher text block.

![[CipherBlockChaining.png]]


*Properties*
- same plain blocks are mapped to different cipher blocks
- Cj depends on the previous plaintext
- if an error occurs at Cj but not Cj+1, then Cj+2 is correctly decrypted

# Stream ciphers
Same idea of Vernam Cipher but use pseudorandom generator for keys.
Vernam Cipher:
- assumes that key is 'random'
- problem: key with same length of plain (too long)
- problem: no re-using

In stream ciphers we don't have "keys" given, but a string called **seed** that generate the key (so not truly random) with a chosen length.
The idea behind **pseudorandom** is that even knowing the previous bits, the next bit has the same probability of being 0 and 1 (50%) anyway.

Stream ciphers are usually faster and can obtain security as block cipher of certain key length. But no re-use of keys in stream-ciphers.

Example: RC4


# Placements of encryptions
Where to place our encryptions?
At a network level, it can be placed on various level of ISO/OSI model.
- **link encryption** at layers 1 or 2.
	- problem: intermediate nodes know plaintext
	- needs trust on intermediate nodes
- **end-to-end** encryption at layer 4 (IP) between **hosts**
	- the intermediate nodes don't have to decrypt, they just have to transport the message
	- needs trust on other hosts
	
## Note on hosts
Usually as host we refer to the whole **server machine**.
On end-to-end encryption we refer to single **web-apps** running on the server machine; so if we trust only the web-app and not the entire server machine we can apply security on TCP/application layer, in particular using **ports**: each port in the machine refer to a specific application that we trust.

## Traffic analysis
Just by observing the flow of encrypted data the attacker can obtain information.
Countermeasures:
- link encryption protects header details
- use spourious traffic to confuse (padding)
- use anonymous traffic (TOR)