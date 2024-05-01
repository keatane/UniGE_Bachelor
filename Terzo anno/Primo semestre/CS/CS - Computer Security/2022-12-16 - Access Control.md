# Access Control

A user is allowed to get access to given resources?
A **security policy** defines what is allowed (like set of laws)
	- describe **access restrictions** (subject-object)
	- customizable
A **security model** provides a formal representation of a security policy
	- useful for detect who violates the policy
	- e.g. firewall is a point in a sec model of a sec policy
A sec mechanism defines the low level sw/hw functions that implements the controls imposed by policy

## Security Policy
Three main classes:
- Discretionary (DAC): chosen by the user, based on authorization, identity of requestor and on access rules for the requestor
- Mandatory (MAC): based on mandated regulations determined by a central authority
- Role-based (RBAC): based on roles associated to users and permission of those roles

MAC and RBAC usually included in an administrative or governative policy/scenario

## Reference Architecture

A **reference monitor** is a trusted component between users and objects: every request passes through it and is elaborated.

It must be:
- of limited size
- tamper proof (not alterable)
- non-bypassable
- limited to a part of the system

## Protection state

A **state** is a system in the collection of all memory locations, storage, register, etc.
Protection state is a subset addressing protection.
E.g.
- filesystem
- network
- program as run-time image

System is seen as a **transaction system** that changes between states.
States can be **authorized** (or secure) and **unauthorized** (or nonsecure). Those states are partitionated by a security policy.

**A secure system is a system that start in an authorized state and cannot enter in an unauthorized state**.

## DAC

The owner of the resource is able to change its permission at his/her discretion.
A simple framework to describe a protection system is a **matrix model** with **subjects, objects and privileges**.
Note that subjects can be users account but also processes.

A protection state here is described as a triple (S,O,M)
Where M is the matrix and M(s,o) = {certain privileges}
We can execute commands ((S,O,M) |-c (S',O',M')) like:
- enter a privilege
- create a subject (row)
- destroy an object (col)
- etc.
A set of commands describes a state-transition system.

## Harrison-Ruzzo-Ullman Model

Defines an authorization system via a simplified programming language made only of if, then, else.

Operations can be done if privilege/right 'r' is present in M(si, oi)


## Matrix implementation - Data Structure

How to represent matrix model in an efficient way?

Alternatives: action control lists or capabilities list
The first cut matrix by cols, the latter by rows

AC lists are preferred and used in UNIX.

### UNIX Control Access

UNIX bases control access per object using permission scheme 'owner/group/other'.
So -rwxr--r-- means that owner of the file (if starts with d it means directory) can read, write and execute, but group and others can only read the file. Those are called **file mode bits**.

There are **special mode bits** that:
- affects only executable files
- is bound to identity of user by looking to user-id
	- executing a file create a process with that user-id
	- if a 's' bit is specified the user-id used in the process is the one of the owner of the file (eventually the root!)
	- this allow execution of high-privilege operations.

Letting the user choose the policy open to a vulnerability to trojan horse:
	- exploit authorizations
	- run malicious processes

## MAC

Control access by comparing:
	- security labels -> sensivity of objects
	- formal authorization -> security clearances of subjects

Mandatory because subjects may not transfer access rights

A linear ording exists:
- read down: subject's clearance must dominate the security level of the read object
- write up: subject's clearance must be dominated by the security level of the written object 
	- often restricted to same level
	- no allowed to write lower security level data (it would mean to transfer sensitive info!)

E.g. Top Secret can read Secret and Secret can write Top Secret

A set of security labels and a partial ordering create a **lattice** that describe least upper bound and greatest lower bound

Sec labels are pairs: (h,c) where
	- h of H classification (linear ordering)
	- c of C categories (project name, company divisions)

### Bell-LaPadula model

- Based on AC matrix
- Multi-level sensitive (MLS) based on MAC
- The principles are the same of above

**Covert channel attack** can be used to transfer informations from high level to lower one
	-> for example by changing permission level on a file in order to hide malicious file to lower security level processes

### Biba model

Propose a class of integrity models (while Bell-LaPadula set confidentiality)

### Chinese Wall model

Used to avoid interest conflicts: if info flows between datasets it's a problem

Idea: track if a subject has had access the object in the past. Moreover access permission changes dynamically.

**'s' can access 'o' if 's' has never accessed info from a different company (dataset) in the same conflict class**.


### Clark-Wilson Integrity Model

- integrity model
- object (data-item) are partitioned into
	- constrained data-item
	- unconstrained data-item
- used in financial world, idea: every transaction sums results to zero (no create nor destroy money)


## Role-based Access Model (RBAC)

Role: decompose subject/object relationship using roles
User - roles -> roles - permissions

- one user can have multiple roles
- make permission management easier

Roles have an implicit hierarchy, it can be explicitated = less repetition of roles

Before:
![[RBAC-NoHierarchy.png]]
Then:
![[RBAC-WithHierarchy.png]]

Moreover we can specify which roles can't be set to same users together (e.g. student and faculty)

Note: roles vs groups
- roles are set of privileges, they can be added or removed by users
- groups are set of users, an user can't revoke their group membership

**Administrative policy** (ARBAC) allow to change and manage the tables of user - role - permission assignment. There are two type of rules:
	- can_assign: UEmployee: {Student, not TA} -> PTEmployee
		- where UEmployee is the role of the subject that operate the rule
	- can_revoke: UEmployee: {Student} -> {not Student}