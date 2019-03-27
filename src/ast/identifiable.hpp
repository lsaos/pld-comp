//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#pragma once

#include <cassert>
#include <string>

using namespace std;

#include "type.hpp"

namespace ast
{
	// Represents an identifiable symbol with a name and a type.
	// It can be a Function or a Variable.
	class Identifiable
	{
	public:
		// Create an identifiable.
		Identifiable();

	public:
		// Set the identifiable name.
		void setName(const string& n);

		// Set the identifiable type.
		void setType(Type t);

	public:
		// Get the identifiable name.
		const string& getName() const {
			return name;
		}

		// Get the identifiable type.
		Type getType() const {
			return type;
		}

		// Get the identifiable type as a string.
		string getTypeName() const;

	private:
		string name; // Identifier name.
		Type type; // Variable type or function return type.
	};
}
