//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#include "variable.hpp"

namespace ast
{
	//
	// Variable
	//

	Variable::Variable(const ItemPosition& position)
		: Instruction(position),
		scope(Scope::Block),
		used(false),
		isTypeArray(false)
	{
	}

	void Variable::setScope(Scope s)
	{
		scope = s;
	}

	void Variable::markUsed()
	{
		used = true;
	}

	void Variable::setIsArray()
	{
		isTypeArray = true;
	}

	void Variable::setArraySize(Expression* expr)
	{
		assert(expr);
		expr->setParent(this);
		arraySize = unique_ptr<Expression>(expr);
	}

	int Variable::getArraySize() const
	{
		if (arraySize && arraySize->isConstant()) {
			return arraySize->getValue();
		}
		else {
			return -1;
		}
	}

	void Variable::checkSemantic(bool advanced) const
	{
		if (getName().empty() || getType() == Type::Void) {
			error(Error::InvalidStatement, this);
		}

		if (advanced && !used) {
			warning(Warning::UnusedVariable, this);
		}

		if (isTypeArray && scope != Scope::Parameter) {
			if (!arraySize) {
				error(Error::MissingArraySize, this);
			}

			arraySize->checkSemantic(advanced);

			if (arraySize->getType() == Type::Void || !arraySize->isConstant()) {
				error(Error::NotConstant, arraySize.get());
			}

			if (arraySize->getValue() < 0) {
				error(Error::InvalidArraySize, arraySize.get());
			}
		}
		else {
			if (arraySize) {
				error(Error::InvalidStatement, arraySize.get());
			}
		}
	}

	Instruction* Variable::optimize()
	{
		// Try to optimize the array size expression
		if (arraySize) {
			Instruction* optimized = arraySize->optimize();
			if (optimized) {
				assert(optimized != arraySize.get() && optimized->isExpression());
				arraySize = unique_ptr<Expression>((Expression*)optimized);
			}
		}

		// We can't optimize the variable itself
		return nullptr;
	}

	void Variable::prepare()
	{
		if (arraySize) {
			arraySize->prepare();
		}
	}

	void Variable::toTextualRepresentation(ostream& out, size_t i) const
	{
		for (size_t j = 0; j < i; j++) { out << ' '; }
		out << "Var {" << endl;

		for (size_t j = 0; j < i + 1; j++) { out << ' '; }
		out << getTypeName();
		if (isTypeArray) {
			out << "[]";
		}
		out << endl;

		for (size_t j = 0; j < i + 1; j++) { out << ' '; }
		out << "Ident(" << getName() << ')' << endl;

		if (isTypeArray) {
			const int size = getArraySize();
			if (size >= 0) {
				for (size_t j = 0; j < i + 1; j++) { out << ' '; }
				out << "Size(" << size << ')' << endl;
			}
		}

		for (size_t j = 0; j < i; j++) { out << ' '; }
		out << '}' << endl;
	}

	string Variable::getStringRepresentation() const
	{
		string s = getTypeName() + ' ' + getName();

		if (isTypeArray) {
			s += '[';

			const int size = getArraySize();
			if (size >= 0) {
				s += to_string(size);
			}

			s += ']';
		}

		return s;
	}

	/*void Variable::generateAssembly(ofstream& f, unordered_map<ast::Variable*, int>& addressTable)
	{
		f << "\tmovl " << addressTable[this] << "(%rbp), %eax" << endl;
	}*/
}
