/* Modeling API uses and misuses via state machines.
   Copyright (C) 2019 Free Software Foundation, Inc.
   Contributed by David Malcolm <dmalcolm@redhat.com>.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#ifndef GCC_ANALYZER_SM_H
#define GCC_ANALYZER_SM_H

#include "analyzer/analyzer-logging.h"

////////////////////////////////////////////////////////////////////////////

/* Utility functions for use by state machines.  */

extern tree is_zero_assignment (const gimple *stmt);
extern bool is_comparison_against_zero (const gcond *cond_stmt,
					tree *out_lhs, enum tree_code *out_op);
extern bool any_pointer_p (tree var);

////////////////////////////////////////////////////////////////////////////

class state_machine;
class sm_context;
class pending_diagnostic;

/* An abstract base class for a state machine describing an API.
   A mapping from state IDs to names, and various virtual functions
   for pattern-matching on statements.  */

class state_machine : public log_user
{
public:
  typedef unsigned state_t;

  state_machine (const char *name, logger *logger)
  : log_user (logger), m_name (name) {}

  virtual ~state_machine () {}

  /* Should states be inherited from a parent region to a child region,
     when first accessing a child region?
     For example we should inherit the taintedness of a subregion,
     but we should not inherit the "malloc:non-null" state of a field
     within a heap-allocated struct.  */
  virtual bool inherited_state_p () const = 0;

  const char *get_name () const { return m_name; }

  const char *get_state_name (state_t s) const;

  /* Return true if STMT is a function call recognized by this sm.  */
  virtual bool on_stmt (sm_context *sm_ctxt,
			const supernode *node,
			const gimple *stmt) const = 0;

  virtual void on_condition (sm_context *sm_ctxt,
			     const supernode *node,
			     const gimple *stmt,
			     tree lhs, enum tree_code op, tree rhs) const = 0;

  virtual void on_leak (sm_context *sm_ctxt,
			const supernode *node,
			const gimple *stmt,
			tree var,
			state_machine::state_t state) const = 0;

  /* Return true if it safe to discard the given state (to help
     when simplifying state objects).
     States that need leak detection should return false.  */
  virtual bool can_purge_p (state_t s) const = 0;

  void validate (state_t s) const;

protected:
  state_t add_state (const char *name);

private:
  const char *m_name;
  auto_vec<const char *> m_state_names;
};

/* Is STATE the start state?  (zero is hardcoded as the start state).  */

static inline bool
start_start_p (state_machine::state_t state)
{
  return state == 0;
}

////////////////////////////////////////////////////////////////////////////

/* Abstract base class giving an interface for the state machine to call
   the checker engine, at a particular stmt.  */

class sm_context
{
public:
  virtual ~sm_context () {}

  /* Called by state_machine in response to pattern matches:
     if VAR is in state FROM, transition it to state TO, potentially
     recording the "origin" of the state as ORIGIN.
     Use NODE and STMT for location information.  */
   virtual void on_transition (const supernode *node, const gimple *stmt,
			      tree var,
			      state_machine::state_t from,
			      state_machine::state_t to,
			      tree origin = NULL_TREE) = 0;

  /* Called by state_machine in response to pattern matches:
     issue a diagnostic D if VAR is in state STATE, using NODE and STMT
     for location information.  */
  virtual void warn_for_state (const supernode *node, const gimple *stmt,
			       tree var, state_machine::state_t state,
			       pending_diagnostic *d) = 0;

  virtual tree get_readable_tree (tree expr)
  {
    return expr;
  }

protected:
  sm_context (int sm_idx, const state_machine &sm)
  : m_sm_idx (sm_idx), m_sm (sm) {}

  int m_sm_idx;
  const state_machine &m_sm;
};


////////////////////////////////////////////////////////////////////////////

/* The various state_machine subclasses are hidden in their respective
   implementation files.  */

extern void make_checkers (auto_delete_vec <state_machine> &out,
			   logger *logger);

extern state_machine *make_malloc_state_machine (logger *logger);
extern state_machine *make_fileptr_state_machine (logger *logger);
extern state_machine *make_taint_state_machine (logger *logger);
extern state_machine *make_sensitive_state_machine (logger *logger);
extern state_machine *make_pattern_test_state_machine (logger *logger);

#endif /* GCC_ANALYZER_SM_H */
