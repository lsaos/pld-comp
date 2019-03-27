//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#pragma once

namespace ast
{
	// Supported base types.
	enum class Type
	{
		Void, // Indicates functions which don't return a value. Can't declare a variable with this type.
		Integer, // 32 bits signed integer.
		Character // 8 bits signed integer.
	};
}
