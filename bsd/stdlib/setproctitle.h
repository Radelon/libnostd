#ifndef BSD_STDLIB_SETPROCTITLE_H
#define BSD_STDLIB_SETPROCTITLE_H

#ifndef HAVE_SETPROCTITLE
#if defined __FreeBSD__ \
 || defined __NetBSD__  \
 || defined __OpenBSD__
#define HAVE_SETPROCTITLE 1
#else
#define HAVE_SETPROCTITLE 0
#endif
#endif


#if !HAVE_SETPROCTITLE

#if __GNUC__

void setproctitle(const char *, ...) __attribute__((format (printf, 1, 2)));

#else

void setproctitle(const char *, ...);

#endif

#endif /* !HAVE_SETPROCTITLE */


#endif /* BSD_STDLIB_SETPROCTITLE_H */
