# Digital signature
The auth code discussed above can be seen as a **signature**.
But **doesn't bind A** (who sends the message) to the responsibility of sending M, so B (the receiver) can only check if that M hasn't been altered in the meanwhile (by thirds). If checks are okay don't tell if really has been A has sent M, and **so A can repudiate it**.
Moreover because in E(Kab, h(M)) K is shared between A and B, if A is accused, A can defends telling that B has used that Kab to send a different M: **B has no legal defense**.

## Arbitrated digital signature
(When a third party agent A is introduced, between X and Y)

Must assure that A can't see the signed message: applying E with K(xa) on the message will make the message visibile to A (that can be unnecessary!) while Y can't verify the sign because it's encrypted. The solution is t apply an E with K(xa) to the message that is already encrypted E with K(xy) so that A can't see the message; Y still can't decrypt the sign if not for legal reasons.