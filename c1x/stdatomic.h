/* ==========================================================================
 * stdatomic.h - Portable implementation of C++0x N2324 stdatomic.h proposal.
 * --------------------------------------------------------------------------
 * Copyright (c) 2008  William Ahern
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to permit
 * persons to whom the Software is furnished to do so, subject to the
 * following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
 * NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
 * USE OR OTHER DEALINGS IN THE SOFTWARE.
 * ==========================================================================
 * SYNOPSIS
 *
 * Portable stdatomic.h implementation, as described in "C++ Atomic Types and
 * Operations":
 *
 * 	http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2007/n2324.html
 *
 * ATOMIC_SCALAR_LOCK_FREE	enum { 0, 1, 2 }
 * 
 * memory_order			enum { memory_order_relaxed,
 * 				       memory_order_acquire,
 * 				       memory_order_release,
 * 				       memory_order_acq_rel,
 * 				       memory_order_seq_cst }
 *
 * atomic_flag		Binary flag. Always lock-free.
 * atomic_bool		Boolean.
 * atomic_address	Void pointer.
 * atomic_char, atomic_uchar, atomic_short, atomic_ushort, atomic_int,
 * atomic_uint, atomic_long, atomic_ulong, atomic_llong, atomic_ullong
 *
 * /--------------+------+------+---------+----------\
 * |              | flag | bool | address | integral |
 * +--------------+------+------+---------+----------+
 * | test_and_set |  O   |  .   |    .    |    .     |
 * | clear        |  O   |  .   |    .    |    .     |
 * | store        |  .   |  O   |    O    |    O     |
 * | load         |  .   |  O   |    O    |    O     |
 * | swap         |  .   |  O   |    O    |    O     |
 * | compare_swap |  .   |  O   |    O    |    O     |
 * | fence        |  .   |  O   |    O    |    O     |
 * | fetch_add    |  .   |  .   |    O    |    O     |
 * | fetch_sub    |  .   |  .   |    O    |    O     |
 * | fetch_and    |  .   |  .   |    .    |    O     |
 * | fetch_or     |  .   |  .   |    .    |    O     |
 * | fetch_xor    |  .   |  .   |    .    |    O     |
 * +--------------+------+------+---------+----------+
 * | lock_free    |  .   |  O   |    O    |    O     |
 * \--------------+------+------+---------+----------/
 *
 * ==========================================================================
 */
#ifndef C1X_STDATOMIC_H
#define C1X_STDATOMIC_H

#include <stdbool.h>	/* bool */

#include <limits.h>	/* LLONG_MAX */


#ifndef ATOMIC_SCOPE
#define ATOMIC_SCOPE	static
#endif


typedef enum memory_order {
	memory_order_relaxed, memory_order_acquire, memory_order_release,
	memory_order_acq_rel, memory_order_seq_cst
} memory_order;


typedef struct atomic_flag atomic_flag;
typedef struct atomic_bool atomic_bool;
typedef struct atomic_address atomic_address;
typedef struct atomic_char atomic_char;
typedef struct atomic_schar atomic_schar;
typedef struct atomic_uchar atomic_uchar;
typedef struct atomic_short atomic_short;
typedef struct atomic_ushort atomic_ushort;
typedef struct atomic_int atomic_int;
typedef struct atomic_uint atomic_uint;
typedef struct atomic_long atomic_long;
typedef struct atomic_ulong atomic_ulong;
#if defined(LLONG_MAX)
typedef struct atomic_llong atomic_llong;
typedef struct atomic_ullong atomic_ullong;
#endif


ATOMIC_SCOPE const struct atomic__flag_ops {
	bool (*test_and_set)(atomic_flag *, memory_order);
	void (*clear)(atomic_flag *, memory_order);
} atomic__flag_ops_initializer;

ATOMIC_SCOPE const struct atomic__bool_ops {
	bool (*lock_free)(atomic_bool *);
	void (*store)(atomic_bool *, bool, memory_order);
	bool (*load)(atomic_bool *, memory_order);
	bool (*swap)(atomic_bool *, bool, memory_order);
	bool (*compare_swap)(atomic_bool *, bool *, bool, memory_order);
	void (*fence)(atomic_bool *, memory_order);
} atomic__bool_ops_initializer;

ATOMIC_SCOPE const struct atomic__address_ops {
	bool (*lock_free)(atomic_address *);
	void (*store)(atomic_address *, void *, memory_order);
	void *(*load)(atomic_address *, memory_order);
	void *(*swap)(atomic_address *, void *, memory_order);
	bool (*compare_swap)(atomic_address *, void **, void *, memory_order);
	void (*fence)(atomic_address *, memory_order);
	void *(*fetch_add)(atomic_address *, void *, memory_order);
	void *(*fetch_sub)(atomic_address *, void *, memory_order);
} atomic__address_ops_initializer;

#define ATOMIC__DECL_INTEGRAL_OPS(type, name)				\
ATOMIC_SCOPE const struct atomic__##name##_ops {			\
	bool (*lock_free)(atomic_##name *);				\
	void (*store)(atomic_##name *, type, memory_order);		\
	type (*load)(atomic_##name *, memory_order);			\
	type (*swap)(atomic_##name *, type, memory_order);		\
	bool (*compare_swap)						\
		(atomic_##name *, type *, type, memory_order);		\
	void (*fence)(atomic_##name *, memory_order);			\
	type (*fetch_add)(atomic_##name *, type, memory_order);		\
	type (*fetch_sub)(atomic_##name *, type, memory_order);		\
	type (*fetch_and)(atomic_##name *, type, memory_order);		\
	type (*fetch_or)(atomic_##name *, type, memory_order);		\
	type (*fetch_xor)(atomic_##name *, type, memory_order);		\
} atomic__##name##_ops_initializer

ATOMIC__DECL_INTEGRAL_OPS(char, char);
ATOMIC__DECL_INTEGRAL_OPS(signed char, schar);
ATOMIC__DECL_INTEGRAL_OPS(unsigned char, uchar);
ATOMIC__DECL_INTEGRAL_OPS(short, short);
ATOMIC__DECL_INTEGRAL_OPS(unsigned short, ushort);
ATOMIC__DECL_INTEGRAL_OPS(int, int);
ATOMIC__DECL_INTEGRAL_OPS(unsigned int, uint);
ATOMIC__DECL_INTEGRAL_OPS(long, long);
ATOMIC__DECL_INTEGRAL_OPS(unsigned long, ulong);
#if defined(LLONG_MAX)
ATOMIC__DECL_INTEGRAL_OPS(long long, llong);
ATOMIC__DECL_INTEGRAL_OPS(unsigned long long, ullong);
#endif


#define atomic_test_and_set(a)		((a)->ops->test_and_set((a), memory_order_seq_cst))
#define atomic_clear(a)			((a)->ops->clear((a), memory_order_seq_cst))
#define atomic_lock_free(a)		((a)->ops->lock_free((a)))
#define atomic_load(a)			((a)->ops->load((a), memory_order_seq_cst))
#define atomic_store(a, n)		((a)->ops->store((a), (n), memory_order_seq_cst))
#define atomic_swap(a, n)		((a)->ops->swap((a), (n), memory_order_seq_cst))
#define atomic_compare_swap(a, m, n)	((a)->ops->compare_swap((a), (m), (n), memory_order_seq_cst))
#define atomic_fence(a, o)		((a)->ops->fence((a), (o)))
#define atomic_fetch_add(a, n)		((a)->ops->fetch_add((a), (n), memory_order_seq_cst))
#define atomic_fetch_sub(a, n)		((a)->ops->fetch_sub((a), (n), memory_order_seq_cst))
#define atomic_fetch_and(a, n)		((a)->ops->fetch_and((a), (n), memory_order_seq_cst))
#define atomic_fetch_or(a, n)		((a)->ops->fetch_or((a), (n), memory_order_seq_cst))
#define atomic_fetch_xor(a, n)		((a)->ops->fetch_xor((a), (n), memory_order_seq_cst))


/*
 * XXX: Eventually these type definitions might need to be target specific.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#define ATOMIC_FLAG_INIT	{ 0, &atomic__flag_ops_initializer }

struct atomic_flag {
	volatile int i;
	const struct atomic__flags_ops *ops;
}; /* struct atomic_flag */


#define ATOMIC_BOOL_INIT	{ 0, &atomic__bool_ops_initializer }

struct atomic_bool {
	volatile bool i;
	const struct atomic__bool_ops *ops;
}; /* struct atomic_bool */


#define ATOMIC_ADDRESS_INIT	{ 0, &atomic__address_ops_initializer }

struct atomic_address {
	volatile void *i;
	const struct atomic__address_ops *ops;
}; /* struct atomic_address */


#define ATOMIC__DECL_INTEGRAL(type, name)				\
struct atomic_##name {							\
	volatile type i;						\
	const struct atomic__##name##_ops *ops;				\
} /* struct atomic_integral */

#define ATOMIC_CHAR_INIT	{ 0, &atomic__char_ops_initializer }
ATOMIC__DECL_INTEGRAL(char, char);

#define ATOMIC_SCHAR_INIT	{ 0, &atomic__schar_ops_initializer }
ATOMIC__DECL_INTEGRAL(signed char, schar);

#define ATOMIC_UCHAR_INIT	{ 0, &atomic__uchar_ops_initializer }
ATOMIC__DECL_INTEGRAL(unsigned char, uchar);

#define ATOMIC_SHORT_INIT	{ 0, &atomic__short_ops_initializer }
ATOMIC__DECL_INTEGRAL(short, short);

#define ATOMIC_USHORT_INIT	{ 0, &atomic__ushort_ops_initializer }
ATOMIC__DECL_INTEGRAL(unsigned short, ushort);

#define ATOMIC_INT_INIT		{ 0, &atomic__int_ops_initializer }
ATOMIC__DECL_INTEGRAL(int, int);

#define ATOMIC_UINT_INIT	{ 0, &atomic__uint_ops_initializer }
ATOMIC__DECL_INTEGRAL(unsigned int, uint);

#define ATOMIC_LONG_INIT	{ 0, &atomic__long_ops_initializer }
ATOMIC__DECL_INTEGRAL(long, long);

#define ATOMIC_ULONG_INIT	{ 0, &atomic__ulong_ops_initializer }
ATOMIC__DECL_INTEGRAL(unsigned long, ulong);

#if defined(LLONG_MAX)
#define ATOMIC_LLONG_INIT	{ 0, &atomic__llong_ops_initializer }
ATOMIC__DECL_INTEGRAL(long long, llong);

#define ATOMIC_ULLONG_INIT	{ 0, &atomic__ullong_ops_initializer }
ATOMIC__DECL_INTEGRAL(unsigned long long, ullong);
#endif


#ifdef __GNUC__
#if __GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 1)
#error "Must use GCC 4.1.x or greater"
#endif

/* 0 = Never, 1 = Sometimes, 2 = Always */
#define ATOMIC_SCALAR_LOCK_FREE	2

typedef union {
	atomic_flag *flag_; atomic_bool *bool_; atomic_address *address_;
	atomic_char *char_; atomic_schar *schar_; atomic_uchar *uchar_;
	atomic_short *short_; atomic_ushort *ushort_;
	atomic_int *int_; atomic_uint *uint_;
	atomic_long *long_; atomic_ulong *ulong_;
#if defined(LLONG_MAX)
	atomic_llong *llong_; atomic_ullong *ullong_;
#endif
} atomic__any __attribute__ ((__transparent_union__));

static bool atomic__any_lock_free(atomic__any p) {
	return 1;
} /* atomic__any_lock_free() */


static bool atomic__flag_test_and_set(atomic_flag *p, memory_order o) {
	if (o >= memory_order_acq_rel)
		__sync_synchronize();
	return !!__sync_lock_test_and_set(&p->i, 1);
} /* atomic__flag_test_and_set() */

static void atomic__flag_clear(atomic_flag *p, memory_order o) {
	__sync_lock_release(&p->i);
	if (o >= memory_order_acq_rel)
		__sync_synchronize();
} /* atomic__flag_clear() */

ATOMIC_SCOPE const struct atomic__flag_ops atomic__flag_ops_initializer =
	{ &atomic__flag_test_and_set, &atomic__flag_clear };


static void atomic__bool_store(atomic_bool *p, bool n, memory_order o) {
	bool j	= atomic_load(p);

	while (!atomic_compare_swap(p, &j, n))
		;
} /* atomic__bool_store() */

static bool atomic__bool_load(atomic_bool *p, memory_order o) {
	return (bool)__sync_fetch_and_or(&p->i, 0U);
} /* atomic__bool_load() */

static bool atomic__bool_swap(atomic_bool *p, bool n, memory_order o) {
	bool j	= atomic_load(p);

	while (!atomic_compare_swap(p, &j, n))
		;;

	return j;
} /* atomic__bool_swap() */

static bool atomic__bool_compare_swap(atomic_bool *p, bool *m, bool n, memory_order o) {
	bool j	= *m;

	*m	= (bool)__sync_val_compare_and_swap(&p->i, j, n);

	return j == *m;
} /* atomic__bool_compare_swap() */

static void atomic__bool_fence(atomic_bool *p, memory_order o) {
	return /* void */;
} /* atomic__bool_fence() */

ATOMIC_SCOPE const struct atomic__bool_ops atomic__bool_ops_initializer =
	{ &atomic__any_lock_free, &atomic__bool_store, &atomic__bool_load,
	  &atomic__bool_swap, &atomic__bool_compare_swap, &atomic__bool_fence };


#define ATOMIC__GCC_IMPL_STORE(type, name)				\
static void atomic__##name##_store					\
    (atomic_##name *p, type n, memory_order o) {			\
	type j	= atomic_load(p);					\
									\
	while (!atomic_compare_swap(p, &j, n))				\
		;;							\
} /* atomic__store() */

#define ATOMIC__GCC_IMPL_LOAD(type, name)				\
static type atomic__##name##_load(atomic_##name *p, memory_order o) {	\
	return (type)__sync_fetch_and_or(&p->i, 0U);			\
} /* atomic__load() */

#define ATOMIC__GCC_IMPL_SWAP(type, name)				\
static type atomic__##name##_swap					\
    (atomic_##name *p, type n, memory_order o) {			\
	type j	= atomic_load(p);					\
									\
	while (!atomic_compare_swap(p, &j, n))				\
		;;							\
									\
	return j;							\
} /* atomic__swap() */

#define ATOMIC__GCC_IMPL_COMPARE_SWAP(type, name)			\
static bool atomic__##name##_compare_swap				\
    (atomic_##name *p, type *m, type n, memory_order o) {		\
	type j	= *m;							\
									\
	*m	= (type)__sync_val_compare_and_swap(&p->i, j, n);	\
									\
	return j == *m;							\
} /* atomic__compare_swap() */

#define ATOMIC__GCC_IMPL_FENCE(type, name)				\
static void atomic__##name##_fence(atomic_##name *p, memory_order o) {	\
	return /* void */;						\
} /* atomic__fence() */

#define ATOMIC__GCC_IMPL_FETCH_ADD(type, name)				\
static type atomic__##name##_fetch_add					\
    (atomic_##name *p, type n, memory_order o) {			\
	return (type)__sync_fetch_and_add(&p->i, n);			\
} /* atomic__fetch_add() */

#define ATOMIC__GCC_IMPL_FETCH_SUB(type, name)				\
static type atomic__##name##_fetch_sub					\
    (atomic_##name *p, type n, memory_order o) {			\
	return (type)__sync_fetch_and_sub(&p->i, n);			\
} /* atomic__fetch_sub() */

#define ATOMIC__GCC_IMPL_FETCH_AND(type, name)				\
static type atomic__##name##_fetch_and					\
    (atomic_##name *p, type n, memory_order o) {			\
	return (type)__sync_fetch_and_and(&p->i, n);			\
} /* atomic__fetch_and() */

#define ATOMIC__GCC_IMPL_FETCH_OR(type, name)				\
static type atomic__##name##_fetch_or					\
    (atomic_##name *p, type n, memory_order o) {			\
	return (type)__sync_fetch_and_or(&p->i, n);			\
} /* atomic__fetch_or() */

#define ATOMIC__GCC_IMPL_FETCH_XOR(type, name)				\
static type atomic__##name##_fetch_xor					\
    (atomic_##name *p, type n, memory_order o) {			\
	return (type)__sync_fetch_and_xor(&p->i, n);			\
} /* atomic__fetch_xor() */

#define ATOMIC__GCC_IMPL_METHODS(type, name)				\
	ATOMIC__GCC_IMPL_STORE(type, name)				\
	ATOMIC__GCC_IMPL_LOAD(type, name)				\
	ATOMIC__GCC_IMPL_SWAP(type, name)				\
	ATOMIC__GCC_IMPL_COMPARE_SWAP(type, name)			\
	ATOMIC__GCC_IMPL_FENCE(type, name)

#define ATOMIC__GCC_IMPL_FETCH_METHODS(type, name)			\
	ATOMIC__GCC_IMPL_FETCH_ADD(type, name)				\
	ATOMIC__GCC_IMPL_FETCH_SUB(type, name)				\
	ATOMIC__GCC_IMPL_FETCH_AND(type, name)				\
	ATOMIC__GCC_IMPL_FETCH_OR(type, name)				\
	ATOMIC__GCC_IMPL_FETCH_XOR(type, name)

ATOMIC__GCC_IMPL_METHODS(void *, address)
ATOMIC__GCC_IMPL_FETCH_ADD(void *, address)
ATOMIC__GCC_IMPL_FETCH_SUB(void *, address)

ATOMIC_SCOPE const struct atomic__address_ops atomic__address_ops_initializer =
	{ &atomic__any_lock_free, &atomic__address_store, &atomic__address_load,
	  &atomic__address_swap, &atomic__address_compare_swap, &atomic__address_fence,
	  &atomic__address_fetch_add, &atomic__address_fetch_sub };

#define ATOMIC__GCC_IMPL_INTEGRAL(type, name)				\
	ATOMIC__GCC_IMPL_METHODS(type, name)				\
	ATOMIC__GCC_IMPL_FETCH_METHODS(type, name)			\
	ATOMIC_SCOPE const struct atomic__##name##_ops			\
	atomic__##name##_ops_initializer =				\
	{ &atomic__any_lock_free,					\
	  &atomic__##name##_store, &atomic__##name##_load,		\
	  &atomic__##name##_swap, &atomic__##name##_compare_swap,	\
	  &atomic__##name##_fence, &atomic__##name##_fetch_add,		\
	  &atomic__##name##_fetch_sub, &atomic__##name##_fetch_and,	\
	  &atomic__##name##_fetch_or, &atomic__##name##_fetch_xor };

ATOMIC__GCC_IMPL_INTEGRAL(char, char)
ATOMIC__GCC_IMPL_INTEGRAL(signed char, schar)
ATOMIC__GCC_IMPL_INTEGRAL(unsigned char, uchar)
ATOMIC__GCC_IMPL_INTEGRAL(short, short)
ATOMIC__GCC_IMPL_INTEGRAL(unsigned short, ushort)
ATOMIC__GCC_IMPL_INTEGRAL(int, int)
ATOMIC__GCC_IMPL_INTEGRAL(unsigned int, uint)
ATOMIC__GCC_IMPL_INTEGRAL(long, long)
ATOMIC__GCC_IMPL_INTEGRAL(unsigned long, ulong)
#if defined(LLONG_MAX)
ATOMIC__GCC_IMPL_INTEGRAL(long long, llong)
ATOMIC__GCC_IMPL_INTEGRAL(unsigned long long, ullong)
#endif


#endif /* __GNUC__ */

#endif /* C1X_STDATOMIC_H */


#if 0

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	atomic_ulong a	= ATOMIC_ULONG_INIT;
	unsigned long i	= atoi(argv[1]);

	i	= atomic_swap(&a, i);

	printf("%lu => %lu\n", i, atomic_load(&a));

	i	= atomic_fetch_add(&a, 3);

	printf("%lu => %lu\n", i, atomic_load(&a));

	return 0;
} /* main() */

#endif
