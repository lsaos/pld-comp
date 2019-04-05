//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#include "return.hpp"
#include "function.hpp"
#include "identifier.hpp"
#include "../ir/irInstrReturn.hpp"
#include "../ir/cfg.hpp"

using namespace ir;

namespace ast
{
	//
	// Return
	//

	Return::Return(const ItemPosition& position)
		: Instruction(position)
	{
	}

	void Return::setExpression(Expression* expression)
	{
		assert(expression);
		expression->setParent(this);
		expr = unique_ptr<Expression>(expression);
	}

	void Return::checkSemantic(bool advanced) const
	{
		Function* parentFunc = getParentFunction();
		if (!parentFunc) {
			error(Error::InvalidStatement, this);
		}

		if (parentFunc->getType() == Type::Void) {
			if (expr) {
				error(Error::InvalidStatement, expr.get());
			}
		}
		else {
			if (!expr) {
				error(Error::ExpectingExpression, this);
			}

			expr->checkSemantic(advanced);

			if (expr->getType() == Type::Void) {
				error(Error::InvalidStatement, expr.get());
			}
		}
	}

	void Return::toTextualRepresentation(ostream& out, size_t i) const
	{
		for (size_t j = 0; j < i; j++) { out << ' '; }
		out << "Ret {" << endl;

		if (expr) {
			expr->toTextualRepresentation(out, i + 1);
		}
		else {
			for (size_t j = 0; j < i + 1; j++) { out << ' '; }
			out << "void" << endl;
		}

		for (size_t j = 0; j < i; j++) { out << ' '; }
		out << '}' << endl;
	}

	Instruction* Return::optimize()
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

		// We can't optimize the return itself
		return nullptr;
	}

	void Return::prepare()
	{
		if (expr) {
			expr->prepare();
		}
	}

	void Return::generateAssembly(ofstream& f, unordered_map<ast::Variable*, int>& addressTable, string curReg)
	{
		if (expr != nullptr) {
			expr->generateAssembly(f, addressTable, curReg);
			f << "%eax" << endl;
		}
	}

	string Return::buildIR(CFG* cfg)
	{
		string ret = "";
		if (expr != nullptr)
		{
			ret = expr.get()->buildIR(cfg);
			IRInstrReturn * instr = new IRInstrReturn(cfg->current_bb, ret);
			cfg->current_bb->add_IRInstr(instr, cfg->get_var_type(ret));
		}

		return "";
	}
}
