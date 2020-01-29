Partners: Damien Rodriguez, Jessica Halcomb

Our current Shell has the following working as intended:
	- cd is implemented correctly as seen in output capture
	- pipeIt for multiple pipes is working correctly 
	- Fork is working for background process'
	- History is working in display, but not with !
	- PATH is working when user has input the path on the command line

What is not working:
	- .poshrc not working
	- ! operator with the history
	- redirect stdin
	- redirect stdio
	- Reading path from .poshrc file
