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

Mandatory part: <br>
- [ ] to be continue..

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

#	To execute it, run the following command and ... :
$ ./bin/pipex
```



## 🦾 Technologies

## 🔗 References

## 📜  License
This project is licensed under the terms of the [LICENSE](https://github.com/mewmewdevart/pipex/blob/main/LICENSE) file. See the file for more details. <br>

<p align="center"> Developed with love 💜 by Larissa Cristina Benedito (Mewmew/Larcrist). </p>
