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
			identifiable = unique_ptr<Identifiable>(ident);
		}

		Identifiable* getIdentifiable()
		{
			return identifiable.get();
		}

	public:
		virtual Type getType() const
		{
			assert(identifiable);
			return identifiable->getType();
		}

		virtual bool checkSemantic()
		{
			if (!identifiable || identifiable->getName().empty()) {
				error(Error::InvalidInstruction, this);
				return false;
			}

			return true;
		}

		virtual void toTextualRepresentation(ostream& out, size_t i)
		{
			for (size_t j = 0; j < i; j++) { out << ' '; }
			out << "Ident(" << identifiable->getName() << ')' << endl;
		}

	private:
		unique_ptr<Identifiable> identifiable;
	};
}
