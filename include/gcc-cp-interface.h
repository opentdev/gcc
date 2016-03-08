/* Interface between GCC C++ FE and GDB

   Copyright (C) 2014-2016 Free Software Foundation, Inc.

   This file is part of GCC.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#ifndef GCC_CP_INTERFACE_H
#define GCC_CP_INTERFACE_H

#include "gcc-interface.h"

/* This header defines the interface to the GCC API.  It must be both
   valid C and valid C++, because it is included by both programs.  */

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declaration.  */

struct gcc_cp_context;

/*
 * Definitions and declarations for the C++ front end.
 */

/* Defined versions of the C++ front-end API.  */

enum gcc_cp_api_version
{
  GCC_CP_FE_VERSION_0 = 0xffffffff-5
};

/* Qualifiers.  */

enum gcc_cp_qualifiers
{
  GCC_CP_QUALIFIER_CONST = 1,
  GCC_CP_QUALIFIER_VOLATILE = 2,
  GCC_CP_QUALIFIER_RESTRICT = 4
};

/* Ref qualifiers.  */

enum gcc_cp_ref_qualifiers {
  GCC_CP_REF_QUAL_NONE = 0,
  GCC_CP_REF_QUAL_LVALUE = 1,
  GCC_CP_REF_QUAL_RVALUE = 2
};

/* An array of types used for creating lists of base classes.  */

struct gcc_vbase_array
{
  /* Number of elements.  */

  int n_elements;

  /* The base classes.  */

  gcc_type *elements;

  /* Indicate virtual base classes.
     Take elements[i] as a virtual base class iff virtualp[i].  */

  char /* bool */ *virtualp;
};

/* Opaque typedef for type declarations.  They are used for template
   arguments, defaults for type template parameters, and types used to
   build type-conversion expressions.  */

typedef unsigned long long gcc_typedecl;

/* Opaque typedef for unbound class templates.  They are used for
   template arguments, and defaults for template template
   parameters.  */

typedef unsigned long long gcc_utempl;

/* Opaque typedef for expressions.  They are used for template
   arguments, defaults for non-type template parameters, and defaults
   for function arguments.  */

typedef unsigned long long gcc_expr;

/* FIXME: do we need to support argument packs?  */

typedef enum
  { GCC_CP_TPARG_VALUE, GCC_CP_TPARG_CLASS,
    GCC_CP_TPARG_TEMPL, GCC_CP_TPARG_PACK }
gcc_cp_template_arg_kind;

typedef union
{ gcc_expr value; gcc_typedecl type; gcc_utempl templ; gcc_typedecl pack; }
gcc_cp_template_arg;

/* An array of template arguments.  */

struct gcc_cp_template_args
{
  /* Number of elements.  */

  int n_elements;

  /* kind[i] indicates what kind of template argument type[i] is.  */

  char /* gcc_cp_template_arg_kind */ *kinds;

  /* The template arguments.  */

  gcc_cp_template_arg *elements;
};

/* This enumerates the kinds of decls that GDB can create.  */

enum gcc_cp_symbol_kind
{
  /* A function.  */

  GCC_CP_SYMBOL_FUNCTION,

  /* A variable.  */

  GCC_CP_SYMBOL_VARIABLE,

  /* A typedef.  */

  GCC_CP_SYMBOL_TYPEDEF,

  /* A label.  */

  GCC_CP_SYMBOL_LABEL,

  /* A class, or, in a template parameter list scope, a declaration of
     a template class, closing the parameter list.  */

  GCC_CP_SYMBOL_CLASS,

  GCC_CP_SYMBOL_MASK = 15,
  GCC_CP_FLAG_BASE,

  /* Flags to be used along with GCC_CP_SYMBOL_FUNCTION:  */

  /* This flag should be set for constructors, destructors and
     operators.  */
  GCC_CP_FLAG_SPECIAL_FUNCTION = GCC_CP_FLAG_BASE,

  /* We intentionally cannot express inline, constexpr, friend or
     virtual override for functions.  We can't inline or
     constexpr-replace without a source-level body.  Since we disable
     access control, friend is meaningless.  The override keyword is
     only meaningless within the definition of the containing
     class.  */

  /* This indicates a "virtual" member function, explicitly or
     implicitly (due to a virtual function with the same name and
     prototype in a base class) declared as such.  */
  GCC_CP_FLAG_VIRTUAL_FUNCTION = GCC_CP_FLAG_BASE << 1,

  /* The following two flags should only be set when the flag above is
     set.  */

  /* This indicates a pure virtual member function, i.e., one that is
     declared with "= 0", even if a body is provided in the
     definition.  */
  GCC_CP_FLAG_PURE_VIRTUAL_FUNCTION = GCC_CP_FLAG_BASE << 2,

  /* This indicates a "final" virtual member function.  */
  GCC_CP_FLAG_FINAL_VIRTUAL_FUNCTION = GCC_CP_FLAG_BASE << 3,

  /* This indicates a special member function should have its default
     implementation.  This either means the function declaration
     contains the "= default" tokens, or that the member function was
     implicitly generated by the compiler, although the latter use is
     discouraged: just let the compiler implicitly introduce it.

     A member function defaulted after its first declaration has
     slightly different ABI implications from one implicitly generated
     or explicitly defaulted at the declaration (and definition)
     point.  To avoid silent (possibly harmless) violation of the one
     definition rule, it is recommended that this flag not be used for
     such functions, and that the address of the definition be
     supplied instead.  */
  GCC_CP_FLAG_DEFAULTED_FUNCTION = GCC_CP_FLAG_BASE << 4,

  /* This indicates a deleted member function, i.e., one that has been
     defined as "= delete" at its declaration point, or one that has
     been implicitly defined as deleted (with or without an explicit
     "= default" definition).

     This should not be used for implicitly-declared member functions
     that resolve to deleted definitions, as it may affect the
     implicit declaration of other member functions.  */
  GCC_CP_FLAG_DELETED_FUNCTION = GCC_CP_FLAG_BASE << 5,

  /* This indicates a constructor or type-conversion operator declared
     as "explicit".  */

  GCC_CP_FLAG_EXPLICIT_FUNCTION = GCC_CP_FLAG_BASE << 6,

  GCC_CP_FLAG_END_FUNCTION,
  GCC_CP_FLAG_MASK_FUNCTION = (((GCC_CP_FLAG_END_FUNCTION - 1) << 1)
			       - GCC_CP_FLAG_BASE),

  /* Flags to be used along with GCC_CP_SYMBOL_VARIABLE:  */

  /* This indicates a variable declared as "constexpr".  */

  GCC_CP_FLAG_CONSTEXPR_VARIABLE = GCC_CP_FLAG_BASE,

  /* This indicates a variable declared as "thread_local".  ??? What
     should the ADDRESS be?  */

  GCC_CP_FLAG_THREAD_LOCAL_VARIABLE = GCC_CP_FLAG_BASE << 1,

  GCC_CP_FLAG_END_VARIABLE,
  GCC_CP_FLAG_MASK_VARIABLE = (((GCC_CP_FLAG_END_VARIABLE - 1) << 1)
			       - GCC_CP_FLAG_BASE),

  GCC_CP_FLAG_MASK = (GCC_CP_FLAG_MASK_FUNCTION | GCC_CP_FLAG_MASK_VARIABLE)
};

/* This enumerates the types of symbols that GCC might request from
   GDB.  */

enum gcc_cp_oracle_request
{
  /* An ordinary symbol -- a variable, function, typedef, or enum
     constant.  All namespace-scoped symbols with the requested name
     should be defined in response to this request.  */

  GCC_CP_ORACLE_SYMBOL,

  /* A struct, union, or enum tag.  All members of the tagged type
     should be defined in response to this request.  */

  GCC_CP_ORACLE_TAG,

  /* A label.  */

  GCC_CP_ORACLE_LABEL
};

/* The type of the function called by GCC to ask GDB for a symbol's
   definition.  DATUM is an arbitrary value supplied when the oracle
   function is registered.  CONTEXT is the GCC context in which the
   request is being made.  REQUEST specifies what sort of symbol is
   being requested, and IDENTIFIER is the name of the symbol.  */

typedef void gcc_cp_oracle_function (void *datum,
				     struct gcc_cp_context *context,
				     enum gcc_cp_oracle_request request,
				     const char *identifier);

/* The type of the function called by GCC to ask GDB for a symbol's
   address.  This should return 0 if the address is not known.  */

typedef gcc_address gcc_cp_symbol_address_function (void *datum,
						    struct gcc_cp_context *ctxt,
						    const char *identifier);

/* The vtable used by the C front end.  */

struct gcc_cp_fe_vtable
{
  /* The version of the C interface.  The value is one of the
     gcc_c_api_version constants.  */

  unsigned int cp_version;

  /* Set the callbacks for this context.

     The binding oracle is called whenever the C++ parser needs to
     look up a symbol.  This gives the caller a chance to lazily
     instantiate symbols using other parts of the gcc_cp_fe_interface
     API.

     The address oracle is called whenever the C++ parser needs to
     look up a symbol.  This is only called for symbols not provided
     by the symbol oracle -- that is, just built-in functions where
     GCC provides the declaration.

     DATUM is an arbitrary piece of data that is passed back verbatim
     to the callbakcs in requests.  */

  void (*set_callbacks) (struct gcc_cp_context *self,
			 gcc_cp_oracle_function *binding_oracle,
			 gcc_cp_symbol_address_function *address_oracle,
			 void *datum);

#define GCC_METHOD0(R, N) \
  R (*N) (struct gcc_cp_context *);
#define GCC_METHOD1(R, N, A) \
  R (*N) (struct gcc_cp_context *, A);
#define GCC_METHOD2(R, N, A, B) \
  R (*N) (struct gcc_cp_context *, A, B);
#define GCC_METHOD3(R, N, A, B, C) \
  R (*N) (struct gcc_cp_context *, A, B, C);
#define GCC_METHOD4(R, N, A, B, C, D) \
  R (*N) (struct gcc_cp_context *, A, B, C, D);
#define GCC_METHOD5(R, N, A, B, C, D, E) \
  R (*N) (struct gcc_cp_context *, A, B, C, D, E);
#define GCC_METHOD7(R, N, A, B, C, D, E, F, G) \
  R (*N) (struct gcc_cp_context *, A, B, C, D, E, F, G);

#include "gcc-cp-fe.def"

#undef GCC_METHOD0
#undef GCC_METHOD1
#undef GCC_METHOD2
#undef GCC_METHOD3
#undef GCC_METHOD4
#undef GCC_METHOD5
#undef GCC_METHOD7

};

/* The C front end object.  */

struct gcc_cp_context
{
  /* Base class.  */

  struct gcc_base_context base;

  /* Our vtable.  This is a separate field because this is simpler
     than implementing a vtable inheritance scheme in C.  */

  const struct gcc_cp_fe_vtable *cp_ops;
};

/* The name of the .so that the compiler builds.  We dlopen this
   later.  */

#define GCC_CP_FE_LIBCC libcc1.so

/* The compiler exports a single initialization function.  This macro
   holds its name as a symbol.  */

#define GCC_CP_FE_CONTEXT gcc_cp_fe_context

/* The type of the initialization function.  The caller passes in the
   desired base version and desired C-specific version.  If the
   request can be satisfied, a compatible gcc_context object will be
   returned.  Otherwise, the function returns NULL.  */

typedef struct gcc_cp_context *gcc_cp_fe_context_function
    (enum gcc_base_api_version,
     enum gcc_cp_api_version);

#ifdef __cplusplus
}
#endif

#endif /* GCC_CP_INTERFACE_H */
