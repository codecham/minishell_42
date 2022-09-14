v01

char	*readline(const char *prompt);
    /* readline will read a line from the terminal and return it, using
    prompt as a prompt.  If prompt is NULL or the empty string, no
    prompt is issued.  The line returned is allocated with malloc(3);
    the caller must free it when finished.  The line returned has the
    final newline removed, so only the text of the line remains.*/

void	rl_clear_history(void);
	/* Clear the history list by deleting all of the entries, 
	in the same manner as the History library
	clear_history() function. This differs from clear_history 
	because it frees private data Readline saves in the history list. */

int 	rl_on_new_line (void);
 	/* Tell the update routines that we have moved onto a new (empty) line, 
 	usually after ouputting a newline. */

void	rl_replace_line(const char *text, int clear_undo);
 	/* Replace the contents of rl_line_buffer with text. 
 	The point and mark are preserved, if possible. If clear_undo is non-zero, 
 	the undo list associated with the current line is cleared. */

void	rl_redisplay (void);
 	/* Change what’s displayed on the screen to
 	reflect the current contents of rl_line_buffer. */

void	add_history(const char *string);
	/* Place string at the end of the history list. 
	The associated data field (if any) is set to NULL. 
	If the maximum number of history entries has been set using stifle_history(), 
	and the new number of history entries 
	would exceed that maximum, the oldest history entry is removed. */


int 	access(const char *pathname, int mode);
	/* checks whether the calling process can access the file pathname.  
    If pathname is a symbolic link, it is dereferenced.*/

int 	open(const char *pathname, int flags);
	/* open() returns a file descriptor*/

size_t	read(int fd, void *buf, size_t count);
 	/* read() attempts to read up to count bytes from file 
 	descriptor fd into the buffer starting at buf.*/

int 	close(int fd);
	/* close() closes a file descriptor, 
	so that it no longer refers to any file and may be reused.*/

pid_t	fork(void);
	/* fork()  creates a new process by duplicating the calling process.  
	The new process is referred to as the child
	process.  The calling process is referred to as the parent process.*/

pid_t	waitpid(pid_t pid, int *wstatus, int options); && pid_t	wait(int *wstatus);
	/* All  of  these  system  calls are used to wait for state changes in a child of the calling process, and obtain
    information about the child whose state has changed.  A state change is considered to  be:  the  child  termi‐
    nated;  the  child was stopped by a signal; or the child was resumed by a signal.*/

pid_t	wait3(int *wstatus, int options, struct rusage *rusage);
	/* oselete ; 
	it is an equivalent of waitpid(-1, wstatus, options);*/

pid_t	wait4(pid, wstatus, options, rusage);
	/* oselete ; 
	it is an equivalent of waitpid(pid, wstatus, options);*/

sighandler_t signal(int signum, sighandler_t handler);
	/* La fonction signal permet de définir le gestionnaire de signal à 
	invoquer en cas de réception du signal recu.*/

int 	sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
	/* The  sigaction()  system call is used to change 
	the action taken by a process on receipt of a specific signal.*/

int 	sigemptyset(sigset_t *set);
	/* initializes the signal set given by set to empty, 
	with all signals excluded from the set.*/

int 	sigaddset(sigset_t *set, int signum);
	/* add and delete respectively signal signum from set.*/

int 	kill(pid_t pid, int sig);
	/* cet appel système kill() peut être utilisé pour envoyer 
	peu importe quel signal à peu importe quel processus ou groupe de processus. */

void	exit(int status);
	/*The exit() function causes normal process termination and 
	the value of status & 0377 is returned to the parent*/

char 	*getwd(char *buf);
 	/*These  functions  return  a null-terminated string containing an 
 	absolute pathname that is the current working
    directory of the calling process.  The pathname is returned as 
    the function result and via the  argument  buf, if present.*/

int 	chdir(const char *path);
 	/* chdir() changes the current working directory of the 
 	calling process to the directory specified in path.*/

int		stat(const char *path, struct stat *buf);
	/*stat() récupère l'état du fichier pointé par path et remplit le tampon buf'*/

int		fstat(int fd, struct stat *buf);
	/* fstat() est identique à stat(), sauf que le fichier ouvert est pointé 
	par le descripteur fd, obtenu avec open(2). */ 

int		lstat(const char *path, struct stat *buf); 
	/* lstat() est identique à stat(), sauf que si path est un lien symbolique, il donne 
	l'état du lien lui-même plutôt que celui du fichier visé. */

int		unlink(const char *pathname);   
	/* unlink() détruit un nom dans le système de fichiers. Si ce nom était le dernier 
	lien sur un fichier, et si aucun processus n'a ouvert ce fichier, ce dernier est effacé, 
	et l'espace qu'il utilisait est rendu disponible*/

int		execve(const char *fichier, char *const argv[], char *const envp[]); 
	/* execve() exécute le programme correspondant au fichier. 
	Celui-ci doit être un exécutable binaire ou bien un script commençant 
	par une ligne du type :  #! interpréteur [argument-optionnel] */

int 	dup(int oldfd);
	/*The  dup()  system  call  creates  a copy of the file descriptor oldfd, using the lowest-numbered
    unused file descriptor for the new descriptor.*/

int		dup2(int oldfd, int newfd);
	/*The dup2() system call performs the same task as dup(), but instead of using the  lowest-numbered
    unused  file  descriptor,  it  uses  the  file descriptor number specified in newfd.  If the file
    descriptor newfd was previously open, it is silently closed before being reused.*/

int		pipe(int pipefd[2]);
	/* pipe() creates a pipe, a unidirectional data channel that can be used for interprocess communica‐
    tion.  The array pipefd is used to return two file descriptors referring to the ends of the pipe.
    pipefd[0]  refers  to  the  read end of the pipe.  pipefd[1] refers to the write end of the pipe.
    Data written to the write end of the pipe is buffered by the kernel until it  is  read  from  the
    read end of the pipe.*/

DIR		opendir(const char *name);
    /* The  opendir() function opens a directory stream corresponding to the directory name, and returns
    a pointer to the directory stream.  The stream is positioned at the first entry in the directory. */

struct dirent *readdir(DIR *dirp);
	/*The readdir() function returns a pointer to a dirent structure
    representing the next directory entry in the directory stream
    pointed to by dirp.  It returns NULL on reaching the end of the
    directory stream or if an error occurred.*/

int 	closedir(DIR *dirp);
	/*The  closedir()  function closes the directory stream associated with dirp.  A successful call to
    closedir() also closes the underlying file descriptor associated with dirp.  The directory stream
    descriptor dirp is not available after this call.*/

char 	*strerror(int errnum);
	/* The strerror() function returns a pointer to a string that describes the error code passed in the
    argument errnum, possibly using the LC_MESSAGES part of the current locale to select  the  appro‐
    priate  language.   (For  example, if errnum is EINVAL, the returned description will be "Invalid
    argument".)  This string must not be modified by the application, but may be modified by a subse‐
    quent  call  to strerror() or strerror_l().  No other library function, including perror(3), will
    modify this string.*/

void	perror(const char *s);
	/*The  perror()  function  produces a message on standard error describing the last error
    encountered during a call to a system or library function.*/

int		isatty(int fd);
	/*The isatty() function tests whether fd is an open file descriptor referring to a terminal.*/

char	*ttyname(int fd);
	/* The  function ttyname() returns a pointer to the null-terminated pathname of the termi‐
	nal device that is open on the file descriptor fd, or NULL on error (for example, if fd
    is  not  connected to a terminal).  The return value may point to static data, possibly
    overwritten by the next call.*/

int		ttyslot(void);
	/*The  legacy  function  ttyslot()  returns the index of the current user's entry in some
    file.*/

 int	ioctl(int fd, unsigned long request, ...);
	/*The ioctl() function manipulates the underlying device parameters of special files.  In
    particular, many operating characteristics of character special files (e.g., terminals)
    may be controlled with ioctl() requests. SEE MAN FOR THE REST*/

char	*getenv(const char *name);
	/*The  getenv()  function  searches the environment list to find the environment variable
    name, and returns a pointer to the corresponding value string.*/

int		tcgetattr(int fd, struct termios *termios_p);
int		tcsetattr(int fd, int optional_actions, const struct termios *termios_p);
	/* check man, too long */

int		tgetent(char *bp, const char *name);
	/*The tgetent routine loads the entry for name. 
	It returns 1 on success, 0 if there is no such entry,
	 and -1 if the terminfo database could not be found. 
	 The emulation ignores the buffer pointer bp*/

int		tgetflag(char *id);
	/*The tgetflag routine gets the boolean entry for id, or zero if it is not available. */

int		tgetnum(char *id);
	/*The tgetnum routine gets the numeric entry for id, or -1 if it is not available. */

char	*tgetstr(char *id, char **area);
	/*The tgetstr routine returns the string entry for id, 
	or zero if it is not available. Use tputs to output the returned string. 
	The return value will also be copied to the buffer pointed to by area, 
	and the area value will be updated to point past the null ending this value. */

char	*tgoto(const char *cap, int col, int row);
	/*The tgoto routine instantiates the parameters into the given capability. 
	The output from this routine is to be passed to tputs. */

int		tputs(const char *str, int affcnt, int (*putc)(int));