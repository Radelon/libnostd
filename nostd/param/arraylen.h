#ifndef NOSTD_PARAM_ARRAYLEN_H
#define NOSTD_PARAM_ARRAYLEN_H


#if !defined arraylen
#if __GNUC__
#define arraylen(a)								\
	(sizeof(a) / sizeof((a)[0]) +						\
	sizeof(typeof(int[1 - 2*!!__builtin_types_compatible_p(typeof(a),	\
	typeof(&a[0]))]))*0)
#else
#define arraylen(a, b)	(sizeof (a) / sizeof (a)[0])
#endif /* __GNUC__ */
#endif /* arraylen */


#endif /* NOSTD_PARAM_ARRAYLEN_H */
