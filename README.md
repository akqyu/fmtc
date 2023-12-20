# Formatter for texts that have SGR ANSI escape sequences

This is a short program, intended to imitate `fmt` command on Linux/Unix, to format texts that have
ANSI escape sequences of the type Select Graphic Rendition (SGR) embedded in them.
The program only breaks lines at line width which can be set by user as an argument to `fmtc`.

This is especially useful for colorful texts such as the output of `sdcv --color`.
