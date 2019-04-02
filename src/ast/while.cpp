//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#include "while.hpp"

namespace ast
{
	While::While(const ItemPosition& position)
		: ControlStructure(position)
	{
	}
	
	void While::toTextualRepresentation(ostream& out, size_t i) const
	{
		for (size_t j = 0; j < i; j++) { out << ' '; }
		out << "While {" << endl;

		for (size_t j = 0; j < i + 1; j++) { out << ' '; }
		out << "Cond {" << endl;

		getCondition()->toTextualRepresentation(out, i + 2);

		for (size_t j = 0; j < i + 1; j++) { out << ' '; }
		out << '}' << endl;

		for (size_t j = 0; j < i + 1; j++) { out << ' '; }
		out << "Body {" << endl;

		getInstruction()->toTextualRepresentation(out, i + 2);

		for (size_t j = 0; j < i + 1; j++) { out << ' '; }
		out << '}' << endl;

		for (size_t j = 0; j < i; j++) { out << ' '; }
		out << '}' << endl;
	}
}
