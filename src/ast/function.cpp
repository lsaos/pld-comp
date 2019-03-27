//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#include "function.hpp"
#include "variable.hpp"

namespace ast
{
	//
	// Function
	//

	Function::Function(const ItemPosition& position)
		: Block(position)
	{
	}

	void Function::addParameter(Variable* var)
	{
		assert(var);

		var->setScope(Scope::Parameter);
		add(var);
	}

	vector<Variable*> Function::getParameters() const
	{
		vector<Variable*> params;

		for (const auto& instr : instructions) {
			if (instr->isVariable() && ((Variable*)instr.get())->getScope() == Scope::Parameter) {
				params.push_back((Variable*)instr.get());
			}
		}

		return params;
	}

	size_t Function::getParametersCount() const
	{
		size_t cnt = 0;

		for (const auto& instr : instructions) {
			if (instr->isVariable() && ((Variable*)instr.get())->getScope() == Scope::Parameter) {
				cnt++;
			}
		}

		return cnt;
	}

	void Function::toTextualRepresentation(ostream& out, size_t i) const
	{
		for (size_t j = 0; j < i; j++) { out << ' '; }
		out << "DefFun {" << endl;

		for (size_t j = 0; j < i + 1; j++) { out << ' '; }
		out << getTypeName() << endl;

		for (size_t j = 0; j < i + 1; j++) { out << ' '; }
		out << "Ident(" << getName() << ')' << endl;

		Block::toTextualRepresentation(out, i + 1);

		for (size_t j = 0; j < i; j++) { out << ' '; }
		out << '}' << endl;
	}

	string Function::getStringRepresentation() const
	{
		return getTypeName() + ' ' + getName() + "()";
	}
}
