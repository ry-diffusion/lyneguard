# Lyneguard
a Proof-of-concept kernel mode that the *real* code can be made propietary anticheat for linux.
This uses GPL Condom to work.


## Wait, this is not a GPL violation?
Probally, I am not a GPL expert but this uses a "GPL Condom" via a Kernel Compatibility Layer so the real module doesn't uses any Kernel GPL Symbol.

## Directory Structure
- *kernel* - The Kernel Interface aka KCL
- *module* - The **real** anti-cheat code, it uses KCL code to work.
- *lynectl* - A application that uses LyneGuard's API API.

# Building
Run: `make`
