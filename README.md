<h1 align="center">
 Pipex  (⚠️ in development)
</h1>


<p align="center">
	<b><i>A project that teaches inter-process communication using pipes, recreating shell pipelines.  </i></b><br>
</p>


<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/mewmewdevart/pipex?color=6272a4" />
	<img alt="Main language" src="https://img.shields.io/github/languages/top/mewmewdevart/pipex?color=6272a4"/>
	<img alt="License" src="https://img.shields.io/github/license/mewmewdevart/pipex?color=6272a4"/>
</p>

## 💡 About the project
This is a  Pipex project involves creating a pipeline in Unix systems with four distinct processes (Version: 2). The pipeline is composed of four processes that are connected through pipes, with each process assigned a specific task:

1. The first process reads an input file and sends the data to the second process through a pipe.
2. The second process receives the data from the first process, performs a transformation on it, and sends the result to the third process through another pipe.
3. The third process receives the data from the second process, performs another transformation on it, and sends the result to the fourth process through a third pipe.
4. The fourth process receives the data from the third process and writes the result to an output file.

These processes are created using the fork() system call and communicate through pipes using the pipe() and dup2() system calls. The aim of the project is for each process to execute its specific task and pass the data to the next process in the pipeline until the output file is generated. <br>

- [ ] Mandatory part: <br>

The program should be executed as follows:
```bash
$ ./bin/pipex file1 cmd1 cmd2 file2
```
Where each parameter in the command line is: <br>
	• file1 and file2 are file names. <br>
	• cmd1 and cmd2 are shell commands with their parameters. <br>
It must behave exactly the same as the shell command below: <br>
```bash
$ < file1 cmd1 | cmd2 > file2
```
In the desired format:
```bash
$ ./pipex infile "ls -l" "wc -l" outfile
```
It should behave the same as:
```bash
< infile ls -l | wc -l > outfile
```

## 📁 Structure/
* ```include/```  The header file of the pipex project.
* ```bin/```  Where the final executable binary file goes.
* ```libs/```  The libraries (my own libft function).
* ```objs/``` Keeps all the .o files produced throughout the compilation process.
* ```rscs/``` Just my notes and researches about the project.
* ```srcs/```  Where the artcode happens!<br>


## 🛠️ Usage

### Prerequisites

**Linux and MacOS**
This project requires the [GNU Compiler Collection](https://gcc.gnu.org/), the [GNU Make](https://www.gnu.org/software/make/) compiler, and the Internet to clone my repository. <br>
❗️| Make sure you have all the required tools installed on your local machine, then continue with these steps.<br>

### Instructions to run the project :
**0. Download the archives**

```bash
# Clone the repository
$ git clone git@github.com:mewmewdevart/pipex.git

# Enter into the directory
$ cd pipex/
```

**1. Run the project**
```bash
# Run the command make root directory
$ make

#	To execute it, run the following command :
$ ./bin/pipex file1 cmd1 cmd2 file2
#	Example:
$ ./bin/pipex infile.txt cat "wc -l" outfile.txt
#	This command line, take the content inside of infile file, counts the number of 
# lines in the infile file and return the information inside the outfile file. 
# Compares the same result in your shell:
$ < infile cat | wc -l  > outfile

```

## 👩🏾‍💻 How my code works: Project Workflow
Pipex is a program to executes the pipex process. It takes command line arguments (argv) and environment variables (envp) as parameters. 

####  The pipex file
- The main function receives the command-line arguments (argc and argv) and the environment variables (envp). It performs several checks on the arguments and the input/output files to ensure they are valid.<br>
- If the arguments are valid, the main function proceeds to execute the pipex function.<br>
- The pipex function sets up a pipe using the pipe system call and creates two child processes using fork.<br>
- In the parent process, the pid1 and pid2 variables store the process IDs of the child processes. The parent process then waits for both child processes to finish using the waitpid system call.<br>
- The ft_wait_process function is responsible for closing the pipe's file descriptors and waiting for the child processes to finish. <br>
- In the child process (pid1), the ft_child_process function is executed. It opens the input file specified in argv[1] and duplicates the file descriptor using the dup2 system call to redirect the input to the pipe. It also duplicates the file descriptor for the output file and redirects the output to the pipe. Finally, it closes unnecessary file descriptors and calls the ft_execute_commands function to execute the command specified in argv[2].
- In the other child process (pid2), the ft_parent_process function is executed. It opens the output file specified in argv[4] and duplicates the file descriptor using the dup2 system call to redirect the input from the pipe. It also duplicates the file descriptor for the output file and redirects the output to the output file. Finally, it closes unnecessary file descriptors and calls the ft_execute_commands function to execute the command specified in argv[3].

####  The utils file
- The ft_execute_commands function splits and executes the specified commands separately. It checks if the command is an absolute or relative path. If it is, it executes the command using execve. If not, it searches for the command in specific directories based on the environment variables (envp) using the ft_search_directories function. If the command is not found, it executes a second specified command. <br>
- The ft_search_directories function searches for a command in the directories obtained from the "PATH" environment variable. It concatenates the directories with the command and checks if the command exists in any of that paths. <br>

####  The auxiliary functions : 
These auxiliary functions provide support for validating arguments and manipulating strings in the project's execution flow. (Norminette rules dont aceppt more than 5 functions in one file) <br>

- The ft_extension_arguments function checks if argv[2] and argv[3] are valid arguments by verifying their length and content.  <br>
- The ft_strspn function calculates the length of the initial segment of a string that consists entirely of characters not present in another string.  <br>

####  The errors output
- The code includes two error handling functions: ft_errors_init and ft_errors_process. These functions are responsible for printing error messages and terminating the program with an exit status of 1.
- The ft_errors_init function takes an int parameter number_error, which represents the specific error code. Based on the value of number_error, it prints an appropriate error message using ft_printf (check the libft library). The possible error messages include: <br>
Error message for number_error 2: "Error. No such file or directory!" <br>
Error message for number_error 5: "Error. Input/Output error!" <br>
Error message for number_error 13: "Error. Permission denied!" <br>
Error message for number_error 22: "Error. Invalid argument! Ex: ./pipex \<file1\> \<cmd1\> \<cmd2> \<file2\>" <br>
After printing the error message, the function calls exit(1) to terminate the program with a non-zero exit status. <br>
The ft_errors_process function is similar to ft_errors_init but with different errors messages and type of number error.
<br>
Btw, the workflow involves checking arguments, setting up pipes and child processes, redirecting input/output, executing commands, and handling errors throughout the process.


## 💫 Tests
The different tests that can be performed on the command line for this program result in different error messages being displayed as output. Here is a summary of the tests;
- [x] Invalid arguments test: Running the program without exactly four arguments will result in an "Invalid argument" error. <br>
- [x] Non-existent input file test: If the file specified as the first argument does not exist.  <br>
- [x] Input file read permission test: If the file specified as the first argument does not have read permission. <br>
- [x] Valid argument extension test: It checks whether the arguments provided as argv[2] and argv[3] are valid. If either of them is an empty string or contains only whitespace characters. <br>
- [x] Output file creation test: If the file specified as the fourth argument does not exist, the program will attempt to create it with read and write permissions. If an error occurs while creating the file. <br>
- [x] Output file write permission test: If the file specified as the fourth argument does not have write permission. <br>
- [x] Pipe creation error test: If an error occurs while creating the pipe using the pipe() function, the program will display the "Broken pipe. <br>
- [x] Child process creation error test: If an error occurs while creating the child process using the fork() function. <br>
- [x] Parent process creation error test: If an error occurs while creating the parent process using the fork() function. <br>
- [x] Error during waiting for child and parent processes test: If an error occurs during waiting for the child and parent processes using the waitpid() function.br>
- [x] Error during command execution test: If an error occurs while executing the command using the execve() function. <br>
<br>
 I have created an error handling message for different tests on the command line in case an error occurs that I haven't been able to anticipate. Please open an issue.

## 🦾 Technologies
- [VS CODE](https://www.eclipse.org/downloads/) |  I'm a fan of Vim but due to the size of the project, I opted to use Vscode.
- [GNU Compiler Collection](https://gcc.gnu.org/) | A suite of programming language compilers developed by the GNU Project for C, C++, Objective-C, Fortran, Ada, and other languages
- [GNU Make](https://www.gnu.org/software/make/) | A build automation tool for compiling and linking software projects
- A classic notebook to take some notes about the project

## 🔗 References
- [Markdown](https://www.markdownguide.org/basic-syntax/) | Documentation on how to use Markdown.
- Internet forums and blogs to address my doubts related to the language (Alura, Stack Overflow, and Geeks for Geeks).
- Google Translate/Chagpt to translate some parts of content that were in another language.
- [CodeVault](https://youtu.be/cex9XrZCU14) | He have a awesome playlist about how the unix process work!
- [Chagpt](https://chat.openai.com/chat) | To addressing my questions and providing exercises that helped me understand the behavior of certain functions
- 42SP Cadets and others pipex projects and testers| :)

## 📜  License
This project is licensed under the terms of the [LICENSE](https://github.com/mewmewdevart/pipex/blob/main/LICENSE) file. See the file for more details. <br>

<p align="center"> Developed with love 💜 by Larissa Cristina Benedito (Mewmew/Larcrist). </p>
