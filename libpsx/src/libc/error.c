#include <errno.h>
#include <stdio.h>
#include <string.h>

static const char *const str[] =
{
	[EPERM] = "Operation not permitted",
	[ENOENT] = "No such file or directory",
	[ESRCH] = "No such process",
	[EINTR] = "Interrupted system call",
	[EIO] = "Input/output error",
	[ENXIO] = "Device not configured",
	[E2BIG] = "Argument list too long",
	[ENOEXEC] = "Exec format error",
	[EBADF] = "Bad file descriptor",
	[ECHILD] = "No child processes",
	[EDEADLK] = "Resource deadlock avoided",
	[ENOMEM] = "Cannot allocate memory",
	[EACCES] = "Permission denied",
	[EFAULT] = "Bad address",
	[ENOTBLK] = "Block device required",
	[EBUSY] = "Device busy",
	[EEXIST] = "File exists",
	[EXDEV] = "Cross-device link",
	[ENODEV] = "Operation not supported by device",
	[ENOTDIR] = "Not a directory",
	[EISDIR] = "Is a directory",
	[EINVAL] = "Invalid argument",
	[ENFILE] = "Too many open files in system",
	[EMFILE] = "Too many open files",
	[ENOTTY] = "Inappropriate ioctl for device",
	[ETXTBSY] = "Text file busy",
	[EFBIG] = "File too large",
	[ENOSPC] = "No space left on device",
	[ESPIPE] = "Illegal seek",
	[EROFS] = "Read-only file system",
	[EMLINK] = "Too many links",
	[EPIPE] = "Broken pipe",
	[EDOM] = "Numerical argument out of domain",
	[ERANGE] = "Result too large or too small",
	[EAGAIN] = "Resource temporarily unavailable",
	[EWOULDBLOCK] = "Operation would block",
	[EINPROGRESS] = "Operation now in progress",
	[EALREADY] = "Operation already in progress",
	[ENOTSOCK] = "Socket operation on non-socket",
	[EDESTADDRREQ] = "Destination address required",
	[EMSGSIZE] = "Message too long",
	[EPROTOTYPE] = "Protocol wrong type for socket",
	[ENOPROTOOPT] = "Protocol option not available",
	[EPROTONOSUPPORT] = "Protocol not supported",
	[ESOCKTNOSUPPORT] = "Socket type not supported",
	[EOPNOTSUPP] = "Operation not supported",
	[EPFNOSUPPORT] = "Protocol family not supported",
	[EAFNOSUPPORT] = "Address family not supported by protocol family",
	[EADDRINUSE] = "Address already in use",
	[EADDRNOTAVAIL] = "Can't assign requested address",
	[ENETDOWN] = "Network is down",
	[ENETUNREACH] = "Network is unreachable",
	[ENETRESET] = "Network dropped connection on reset",
	[ECONNABORTED] = "Software caused connection abort",
	[ECONNRESET] = "Connection reset by peer",
	[ENOBUFS] = "No buffer space available",
	[EISCONN] = "Socket is already connected",
	[ENOTCONN] = "Socket is not connected",
	[ESHUTDOWN] = "Can't send after socket shutdown",
	[ETOOMANYREFS] = "Too many references: can't splice",
	[ETIMEDOUT] = "Operation timed out",
	[ECONNREFUSED] = "Connection refused",
	[ELOOP] = "Too many levels of symbolic links",
	[ENAMETOOLONG] = "File name too long",
	[EHOSTDOWN] = "Host is down",
	[EHOSTUNREACH] = "No route to host",
	[ENOTEMPTY] = "Directory not empty",
	[EUSERS] = "Too many users",
	[EDQUOT] = "Disc quota exceeded",
	[ESTALE] = "Stale NFS file handle",
	[EREMOTE] = "Too many levels of remote in path",
	[ENOLCK] = "No locks available",
	[ENOSYS] = "Function not implemented",
	[EIDRM] = "Identifier removed",
	[ENOMSG] = "No message of desired type",
	[EOVERFLOW] = "Value too large to be stored in data type",
	[EILSEQ] = "Illegal byte sequence",
	[ENOTSUP] = "Not supported",
	[ECANCELED] = "Operation canceled",
	[EBADMSG] = "Bad or Corrupt message",
	[ENODATA] = "No message available",
	[ENOSR] = "No STREAM resources",
	[ENOSTR] = "Not a STREAM",
	[ETIME] = "STREAM ioctl timeout",
	[EMULTIHOP] = "Multihop attempted",
	[ENOLINK] = "Link has been severed",
	[EPROTO] = "Protocol error"
};

char *strerror(int errnum)
{
	static char deferr[sizeof "Unknown error -2147483648"];

	if (errnum < sizeof str / sizeof *str)
		return (char *)str[errnum];

	snprintf(deferr, sizeof deferr, "Unknown error %d", errnum);
	return deferr;
}

int strerror_r(int errnum, char *strerrbuf, size_t buflen)
{
	if (errnum < sizeof str / sizeof *str) {
		snprintf(strerrbuf, buflen, "%s", str[errnum]);
		return strlen(str[errnum]);
	}

	snprintf(strerrbuf, buflen, "Unknown error %d", errnum);
	return -1;
}
