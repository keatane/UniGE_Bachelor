# Buffer overflow

It's possible to have a great software design but insecure implementation.
- Implementation deviates from design
- Design leaves many (unsafe) options
- Concretization may introduce new vulnerabilities (such as buffer overflow)

The protocols saw until now assumes that the implementation is safe and well-made. Here we focus on implementation level.

Understanding vulnerabilities is vital to developing and evaluating countermeasures.

## Threat

A buffer is a contiguos region of memory storing data of the same type (e.g. char)
Buffer overflow occurs when data is written past a buffer's end, so I'm overwriting the following region if something is allocated into it. Note that for each program a virtual memory is allocated to it.

The resulting damage depends on:
- where the data spills over to
- how this memory region is used
- what modifications are made

Example: Morris attack

If we are lucky the OP intercepts the illegal writings and throw a Segmentation Fault, terminating the program.

## Possible solutions

- restoring variables
- insert **canary**: random value (hard to guess) on the stack that is tested before returing to see if a malicious activity occurs. If its value change then a buffer overflow may be occured. Note that there are known attacks against canary.
- use wrapping functions that checks the inputs
- do not use dangerous operation or check well the buffer's size before operating

