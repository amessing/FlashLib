# Hardware Abstraction Layer
Development of a custom Hardware Abstraction Layer (HAL) for Raspberry PI and BeagleBone Black will be done in this orphan branch.
The result code will replace the use of the Bulldog library for IO.

# BeagleBone Black
Development for the BeagleBone Black HAL will include an FPGA system which runs on one of the PRUs. The system will manage IO and data will be passed from it and to it using the shared memory with the ARM processor.
