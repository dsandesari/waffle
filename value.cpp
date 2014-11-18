
#include "value.hpp"
#include "ast.hpp"
#include "type.hpp"

// -------------------------------------------------------------------------- //
// Built-in literal values
//
// TODO: Consider add a new "value" module for these things.

namespace {

Unit* unit_;
True* true_;
False* false_;

} // namespace

void
init_values() {
  unit_ = new Unit(get_unit_type());
  true_ = new True(get_bool_type());
  false_ = new False(get_bool_type());
}

Term*
get_unit() { return unit_; }

Term*
get_true() { return true_; }

Term*
get_false() { return false_; }

// -------------------------------------------------------------------------- //
// Term classification
//
// Determine if the given term is in the set of values. Note that this
// is distinct from typing.

// Returns true if t is true.
bool
is_true(Term* t) { return t->kind == true_term; }

// Returns true if t is false.
bool
is_false(Term* t) { return t->kind == false_term; }

// Returns true iff t is a boolean value.
//
//    bv ::= true | false
bool
is_boolean_value(Term* t) { return is_true(t) || is_false(t); }

// Returns true if t is an integer value.
//
//    nv ::= N
bool
is_integer_value(Term* t) { return t->kind == int_term; }

// Returns true when t is a lambda abstraction.
bool 
is_abs(Term* t) { return t->kind == abs_term; }

// Returns true when t unit.
bool
is_unit(Term* t) { return t->kind == unit_term; }


// Returns true if t is a value.
//
//    v ::= bv | nv | \x:T.t
bool
is_value(Term* t) { 
  return is_unit(t)
      || is_boolean_value(t) 
      || is_integer_value(t) 
      || is_abs(t);
      
}
