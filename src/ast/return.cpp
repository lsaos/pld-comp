//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#include "return.hpp"
#include "function.hpp"
#include "identifier.hpp"

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

	void Return::generateAssembly(ofstream& f, unordered_map<ast::Variable*, int>& addressTable)
	{
		cout << "Variable : " << expr->isVariable() << endl;

		if (expr->isIdentifier())
		{
			f << "\tmovl " << addressTable[((Identifier*)(expr.get()))->getReferencedVariable()] << "(%rbp), %eax" << endl;
		}
		else if (expr->isConstant())
		{
			cout << "RETURN : CONSTANTE" << endl; // DEBUG
			f << "\tmovl $" << expr->getValue() << ", %eax" << endl;
		}
		else
		{
			cout << "RETURN : RIEN" << endl; // DEBUG
			expr->generateAssembly(f, addressTable);
		}
	}
}
