GGEZ is a simple command line tool meant for allowing 
quick and easy building and execution of applications 
for those new to C++ programming.

GGEZ is intended for use on Linux-based systems, but
can freely be modified for other systems.

To install GGEZ:
- Clone the GGEZ repository.
- Move into the GGEZ directory.
- Build GGEZ with g++.
- Change the permission of the newly created file
to allow execution.
- Optionally: Move the resulting file somewhere in
your $PATH to allow usage like any other command.

-=-=-=-=-
Changelog 1.1:
- Added ability to use warnings.
- Added return values to my functions.
- Removed the use of namespace std.
- Replaced unistd.h with thread and chrono.
- Removed unused parameters in functions.