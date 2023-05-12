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
$ ./pipex file1 cmd1 cmd2 file2
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

Bonus part: <br>
- [ ] to be continue..

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

## 👩🏾‍💻 How my code works:
Pipex is a program to executes the pipex process. It takes command line arguments (argv) and environment variables (envp) as parameters. 

####  The pipex file
- The first condition of main function, checks if the number of arguments is equal to 5. If no, it calls for error. If the argument count is correct, it proceeds to check the permissions of the input file specifieid in argv[1]. If the file dosent exist or if there is no a read permission, it calls  for error. If the input file exist and have read permission, it checks if the outtput file specified in argv[4] exists. If the output file dosent exist, it creates it with write permissions. If the creation fails or if there is no write permission, it calls errors with the corresponding error codes. <br> After performing the necessary checks and file operations, the program calls the pipex function, passing argv and envp as arguments. <br>
- The pipex function sets up a pipe using the pipe system call and creates a child process using fork. If the fork call fails, it calls for error. If the process is the child process, it calls the ft_child_process function passing argv, envp, and the file descriptors of the pipe. <br>
- In the ft_child_process function, it opens the input file specified in argv[1] and duplicates the file descriptor using dup2 to redirect the input and output. Then, it calls the ft_execute_commands function with argv[2] (the command) and envp. <br>
- In the parent process, it waits for the child process to finish using waitpid and then calls the ft_parent_process function. In the ft_parent_process function, it opens the output file specified in argv[4] and duplicates the file descriptors using dup2 to redirect the input and output. Finally, it calls the ft_execute_commands function with argv[3] (the command) and envp. <br>

####  The pipex utils
- The ft_execute_commands function split the command string into individual arguments, finds the correct path for the command by searching through the directories specified in the PATH environment variable, and attempt to execute the command using execve. <br>
- The ft_correct_path function finds the correct path for a given command by searching inside the directories specified in the PATH environment variable. <br>
- The ft_get_directories function extracts the directories specified in the PATH environment variable and returns them as an array of strings. <br>

####  The errors output
- The code includes two error handling functions: ft_errors_init and ft_errors_process. These functions are responsible for printing error messages and terminating the program with an exit status of 1.
- The ft_errors_init function takes an int parameter number_error, which represents the specific error code. Based on the value of number_error, it prints an appropriate error message using ft_printf (check the libft library). The possible error messages include: <br>
Error message for number_error 2: "Error. No such file or directory!" <br>
Error message for number_error 5: "Error. Input/Output error!" <br>
Error message for number_error 13: "Error. Permission denied!" <br>
Error message for number_error 22: "Error. Invalid argument! Ex: ./pipex \<file1\> \<cmd1\> \<cmd2> \<file2\>" <br>
After printing the error message, the function calls exit(1) to terminate the program with a non-zero exit status. <br>
The ft_errors_process function is similar to ft_errors_init but with different errors messages and type of number error.

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
