# Program 2 - Command Line Parser
"oh my god, finally." - said me after finishing this

### file details
 - old files: contains old versions of the program 2 I tried with before I actually sat down and did things properly.
 - args: args.h, executable code
 - args.cpp: source code
 - README.md: the file your reading now

 ### how to use the code
 1. open the terminal
 2. head to the correct directory
 3. in the terminal under ~/2143-OOP-ReedHartman/Assignments/P02 type "g++ args.cpp -o args" this is the thing I used to build the code each time and always worked for me.
 4. to execute the code, start with "./args" in the terminal.
 5. then enter the (hypothetical) input and output file names. These don't actually have any functionality given the program is just a command parser, but still enter them like they exist anyway. Just enter a and b or whatever you want.
 6. then enter commands, a list of commands is provided below:

 Usage: ./args <input_image> <output_image> [options]

 ### accepted commands
 - --grayscale (-g)
 - --blur (-l)
 - --flipH (-h)
 - --flipV (-v)
 - --brighten # (-b #)
 - --brighten=# (-b=#)
 - --rotate # (-r #)
 - --rotate=# (-r=#)

### personal notes
 - the program will abort if you enter anything incorrectly and should give instructions on how to fix your mistake through the error
 - always seperate commands with spaces