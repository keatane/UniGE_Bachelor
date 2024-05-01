# First view on security

## Key words

- <span style="color:yellow; font-weight:bold">accountability</span>: someone is responsible of problems which affect the computer infrastructure. 
- <span style="color:yellow; font-weight:bold">digital identity</span>: provided by an Identity Provider, is visually equivalent to an 'account' and allow to identify people in the cyber world, but not guarantee for example that mario.rossi is Mario Rossi indeed.
- <span style="color:yellow; font-weight:bold">security policy</span>: is a statement to declare who can and cannot operate certain actions.
- <span style="color:yellow; font-weight:bold">security VS safety</span>: while the first is applied against intentional attacks the latter is a physical protection
- <span style="color:yellow; font-weight:bold">privacy VS confidentiality</span>: confidentiality is to protect info that are never shared outside a group (of at least 2 people); when confidentiality is focused on one single person and so data have to be accessed only by that person, who can share them with selected people, it is called privacy.

## Computer Security
Deals with security of computer machines. Differs from <span style="color:#008000">Information Security</span> which deals with the information, so it's indipendent from computer systems.

**Objective**: security of <span style="color:#008000">asset</span> from *<span style="color:#008000">threats</span>
*Assets* (data and services) are owned by *owners* who want to protect them.
<span style="color:#008000">Threat agents</span> try to abuse and get assets to damage the *owner*.
Security 'obstacles' *usability*, that is the ease of use (e.g. password complexity: more security, less ease)

Owners analyze threats and determines <span style="color:#008000">risks</span>, then operate some <span style="color:#008000">countermisures</span> to reduce <span style="color:#008000">vulnerabilities</span>. Risks can be outsourced, that is to create a potential risk to other (e.g. driving a car). Some risks can be accepted and tollerated, depending on the context.

## Security properties
- **confidentiality** - data is not learned from unauthorized principals
- **integrity** - data has not (malicious) altered
- **authentication** - principals or data origin can be identified accurately
- **availability** - data / services can be accessed when desired
- **accountability** - ability to bind actions to people

The objective is to try to get all properties, depending on the context it is possible to prioritize.

## Protection countermisures
- **prevention** of security breaches, can choose not to do that (and so having only *detection*, better safety)
- **detection** if an event of security breach occures, through:
	- logging and MACs
	- intrusion detection
- **response** after a security breach with a recovery asset or other response