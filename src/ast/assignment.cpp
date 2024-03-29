//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#include "assignment.hpp"
#include "../ir/cfg.hpp"
#include "../ir/irInstrWmen.hpp"
#include "../ir/irInstrCopy.hpp"
#include "variable.hpp"

using namespace ir;

namespace ast
{
	//
	// Assignment
	//

	Assignment::Assignment(const ItemPosition& position)
		: Expression(position),
		identifier(nullptr),
		expr(nullptr)
	{
	}

	void Assignment::setIdentifier(Identifier* ident)
	{
		assert(ident);
		ident->setParent(this);
		identifier = unique_ptr<Identifier>(ident);
	}

	void Assignment::setValue(Expression* expression)
	{
		assert(expression);
		expression->setParent(this);
		expr = unique_ptr<Expression>(expression);
	}

	Type Assignment::getType() const
	{
		assert(expr);
		return expr->getType();
	}

	void Assignment::checkSemantic(bool advanced) const
	{
		if (!identifier || !expr) {
			error(Error::InvalidStatement, this);
		}

		identifier->checkSemantic(advanced);
		expr->checkSemantic(advanced);

		// We can't assign a value to a function
		if (!identifier->isReferencingVariable()) {
			error(Error::InvalidStatement, identifier.get());
		}

		// We can't assign a value to something void
		if (identifier->getType() == Type::Void) {
			error(Error::InvalidStatement, identifier.get());
		}

		// Something void can't be assigned
		if (expr->getType() == Type::Void) {
			error(Error::InvalidStatement, expr.get());
		}

		if (advanced) {
			if (identifier->getType() == Type::Character && expr->isConstant()) {
				const int val = expr->getValue();
				if (val < -128 || val > 127) {
					warning(Warning::ValueOutOfType, identifier.get());
				}
			}
		}
	}

	void Assignment::toTextualRepresentation(ostream& out, size_t i) const
	{
		for (size_t j = 0; j < i; j++) { out << ' '; }
		out << "Assignment {" << endl;

		identifier->toTextualRepresentation(out, i + 1);
		expr->toTextualRepresentation(out, i + 1);

		for (size_t j = 0; j < i; j++) { out << ' '; }
		out << '}' << endl;
	}

	Instruction* Assignment::optimize()
	{
		// Try to optimize the value expression
		if (expr) {
			Instruction* optimized = expr->optimize();
			if (optimized) {
				assert(optimized != expr.get() && optimized->isExpression());
				optimized->setParent(this);
				expr = unique_ptr<Expression>((Expression*)optimized);
			}
		}

		// We can't optimize the assignment itself
		return nullptr;
	}

	void Assignment::prepare()
	{
		if (identifier) {
			identifier->prepare();
		}

		if (expr) {
			expr->prepare();
		}
	}

	void Assignment::generateAssembly(ofstream& f, unordered_map<ast::Variable*, int>& addressTable, string curReg)
	{
		//cout << expr.get()->getValue() << endl;
		expr->generateAssembly(f, addressTable, curReg);

		if (expr->isConstant())
		{
			f << addressTable[identifier->getReferencedVariable()] << "(%rbp)" << endl;
		}
		else
		{
			f << curReg << endl;
			f << "\tmovl " << curReg << ", " << addressTable[identifier->getReferencedVariable()] << "(%rbp)" << endl;
		}
	}

	string Assignment::buildIR(CFG* cfg)
	{
		string left;
		string right = expr->buildIR(cfg);

		if (identifier->isReferencingArray())
		{
			string index = identifier->buildIR(cfg); // identifier->getReferencedVariable()->getName();
			left = cfg->get_var_name(identifier->getReferencedVariable());
			cfg->current_bb->add_IRInstr(new IRInstrWmen(cfg->current_bb, left, right, index), cfg->get_var_type(left));
		}
		else
		{
			//Simple assigment code
			left = identifier->buildIR(cfg);
			cfg->current_bb->add_IRInstr(new IRInstrCopy(cfg->current_bb, left, right), (identifier.get())->getReferencedVariable()->getType());
		}

		return left;
	}
}
