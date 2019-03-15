#pragma once

#include "expression.hpp"
#include "identifiable.hpp"

namespace ast
{
	class Identifier : public Expression
	{
	public:
		Identifier(const ItemPosition& position)
			: Expression(position),
			identifiable(nullptr)
		{
		}

	public:
		void setIdentifiable(Identifiable* ident)
		{
			assert(ident);
			((Instruction*)ident)->setParent(this);
			identifiable = ident;
		}

		const Identifiable* getIdentifiable() const
		{
			return identifiable;
		}

		Identifiable* getIdentifiable()
		{
			return identifiable;
		}

	public:
		virtual Type getType() const
		{
			assert(identifiable);
			return identifiable->getType();
		}

	private:
		Identifiable* identifiable;
	};
}
