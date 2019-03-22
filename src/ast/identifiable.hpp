#pragma once

#include <cassert>
#include <string>

using namespace std;

#include "type.hpp"

namespace ast
{
	class Identifiable
	{
	public:
		Identifiable()
			: type(Type::Void)
		{
		}

	public:
		void setName(const string& n)
		{
			assert(!n.empty());
			name = n;
		}

		const string& getName() const
		{
			return name;
		}

		void setType(Type t)
		{
			type = t;
		}

		Type getType() const
		{
			return type;
		}

	private:
		string name;
		Type type;
	};
}
