// See the file "COPYING" in the main distribution directory for copyright.

#include "Scope.h"
#include "Traverse.h"
#include "Stmt.h"
#include "input.h"

TraversalCode traverse_all(TraversalCallback* cb)
	{
	if ( ! zeek::detail::global_scope() )
		return TC_CONTINUE;

	if ( ! stmts )
		// May be null when parsing fails.
		return TC_CONTINUE;

	cb->current_scope = zeek::detail::global_scope();

	TraversalCode tc = zeek::detail::global_scope()->Traverse(cb);

	HANDLE_TC_STMT_PRE(tc);
	tc = stmts->Traverse(cb);
	HANDLE_TC_STMT_POST(tc);
	}
