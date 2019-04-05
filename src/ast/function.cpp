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
		: Block(position),
		isExternal(false)
	{
	}

	void Function::addParameter(Variable* var)
	{
		assert(var);

		var->setScope(Scope::Parameter);
		add(var);
	}

	void Function::setIsExtern()
	{
		isExternal = true;
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

		const vector<Variable*> params(getParameters());
		if (!params.empty()) {
			for (size_t j = 0; j < i + 1; j++) { out << ' '; }
			cout << "Parameters {" << endl;

			for (const Variable* param : params) {
				param->toTextualRepresentation(out, i + 2);
			}

			for (size_t j = 0; j < i + 1; j++) { out << ' '; }
			cout << '}' << endl;
		}

		Block::toTextualRepresentation(out, i + 1);

		for (size_t j = 0; j < i; j++) { out << ' '; }
		out << '}' << endl;
	}

	string Function::getStringRepresentation() const
	{
		return getTypeName() + ' ' + getName() + "()";
	}

	void Function::generateAssembly(ofstream& f, unordered_map<ast::Variable*, int>& addressTable, string curReg)
	{
		f << this->getName() << ":" << endl;
		f << "\tpushq %rbp" << endl;
		f << "\tmovq %rsp, %rbp" << endl;

		for (auto i : getInstructions()) {
			i->generateAssembly(f, addressTable, curReg);
		}

		f << "\tpopq %rbp" << endl << "\tret" << endl;
	}
}
