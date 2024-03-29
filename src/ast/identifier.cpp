//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#include "identifier.hpp"
#include "variable.hpp"
#include "function.hpp"
#include "program.hpp"
#include "assignment.hpp"
#include "../ir/cfg.hpp"
#include "../ir/irInstrLdconst.hpp"
#include "../ir/irInstrBinaryOperation.hpp"
#include "../ir/irInstrRmen.hpp"

using namespace ir;

namespace ast
{
	//
	// Identifier
	//

	Identifier::Identifier(const ItemPosition& position)
		: Expression(position)
	{
	}

	void Identifier::setIdent(const string& str)
	{
		assert(!str.empty());
		ident = str;
	}

	void Identifier::setArrayIndex(Expression* expr)
	{
		assert(expr);
		expr->setParent(this);
		arrayIndex = unique_ptr<Expression>(expr);
	}

	Variable* Identifier::getReferencedVariable() const
	{
		return getParentBlock()->getVariable(ident, true);
	}

	Function* Identifier::getReferencedFunction() const
	{
		return getProgram()->getFunction(ident);
	}

	bool Identifier::isReferencingArray() const
	{
		const Variable* var = getReferencedVariable();
		return var && var->isArray();
	}

	Type Identifier::getType() const
	{
		// If referencing a variable
		Variable* var = getReferencedVariable();
		if (var) {
			return var->getType();
		}

		// If referencing a function
		Function* func = getReferencedFunction();
		if (func) {
			return func->getType();
		}

		return Type::Void;
	}

	void Identifier::checkSemantic(bool advanced) const
	{
		// Check the ident is valid
		if (ident.empty()) {
			error(Error::InvalidInstruction, this);
		}

		const bool refFunction = isReferencingFunction();
		const Variable* refVar = getReferencedVariable();

		// Check if the identifier is referencing something
		if (!refVar && !refFunction) {
			error(Error::UnknownIdentifier, this);
		}

		// A function identifier can only be in a function call
		if (refFunction && !getParent()->isFunctionCall()) {
			error(Error::InvalidInstruction, this);
		}

		if (refVar && refVar->isArray()) {
			if (!arrayIndex) {
				error(Error::MissingArrayIndex, this);
			}

			if (arrayIndex->getType() == Type::Void) {
				error(Error::InvalidInstruction, arrayIndex.get());
			}

			if (advanced && arrayIndex->isConstant()) {
				const int index = arrayIndex->getValue();
				if (index < 0) {
					error(Error::IndexOutOfBounds, arrayIndex.get());
				}

				if (refVar->isArraySizeKnown()) {
					const int arraySize = refVar->getArraySize();
					if (index >= arraySize) {
						error(Error::IndexOutOfBounds, arrayIndex.get());
					}
				}
			}
		}
		else {
			if (arrayIndex) {
				error(Error::InvalidStatement, arrayIndex.get());
			}
		}
	}

	Instruction* Identifier::optimize()
	{
		// Try to optimize the index expression
		if (arrayIndex) {
			Instruction* optimized = arrayIndex->optimize();
			if (optimized) {
				assert(optimized != arrayIndex.get() && optimized->isExpression());
				optimized->setParent(this);
				arrayIndex = unique_ptr<Expression>((Expression*)optimized);
			}
		}

		// We can't optimize the identifier itself
		return nullptr;
	}

	bool Identifier::isLeftValue() const
	{
		return getParent() && getParent()->isAssignment() && ((const Assignment*)getParent())->getIdentifier() == this;
	}

	void Identifier::prepare()
	{
		bool markVarUsed = getParentBlock() != nullptr;

		// Don't mark variable used if the identifier is a basic left-value
		if (isLeftValue()) {
			markVarUsed = false;
		}

		if (markVarUsed) {
			Variable* var = getReferencedVariable();
			if (var) {
				var->markUsed();
			}
		}

		if (arrayIndex) {
			arrayIndex->prepare();
		}
	}

	void Identifier::toTextualRepresentation(ostream& out, size_t i) const
	{
		for (size_t j = 0; j < i; j++) { out << ' '; }
		out << "Ident(" << ident << ')' << endl;

		if (arrayIndex) {
			for (size_t j = 0; j < i; j++) { out << ' '; }
			out << "Index {" << endl;

			arrayIndex->toTextualRepresentation(out, i + 1);

			for (size_t j = 0; j < i; j++) { out << ' '; }
			out << '}' << endl;
		}
	}

	void Identifier::generateAssembly(ofstream& f, unordered_map<ast::Variable*, int>& addressTable, string curReg)
	{
		f << "\tmovl " << addressTable[this->getReferencedVariable()] << "(%rbp), ";
	}

	string Identifier::buildIR(CFG* cfg)
	{
		if (isReferencingArray())
		{
			string index = getArrayIndex()->buildIR(cfg);
			if (isLeftValue())
			{
				return index;
			}
			else
			{
				string tmp = cfg->create_new_tempvar(getReferencedVariable()->getType());

				//Rmem ??
				cfg->current_bb->add_IRInstr(new IRInstrRmen(cfg->current_bb, cfg->get_var_name(getReferencedVariable()), tmp, index), getReferencedVariable()->getType());
				return tmp;
			}
		}
		else
		{
			//cout << getReferencedVariable()->getName() << endl;
			//return getReferencedVariable()->getName();
			return cfg->get_var_name(getReferencedVariable());
		}
	}
}
