//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#include "functionCall.hpp"

namespace ast
{
	//
	// FunctionCall
	//

	FunctionCall::FunctionCall(const ItemPosition& position)
		: Expression(position)
	{
	}

	void FunctionCall::setIdentifier(Identifier* ident)
	{
		assert(ident);
		ident->setParent(this);
		identifier = unique_ptr<Identifier>(ident);
	}

	void FunctionCall::addArgument(Expression* arg)
	{
		assert(arg);
		arg->setParent(this);
		args.push_back(unique_ptr<Expression>(arg));
	}

	Type FunctionCall::getType() const
	{
		assert(identifier);
		return identifier->getType();
	}

	void FunctionCall::checkSemantic(bool advanced) const
	{
		if (!identifier) {
			error(Error::InvalidStatement, this);
		}

		identifier->checkSemantic(advanced);

		// The identifier must reference an existing function
		if (!identifier->isReferencingFunction()) {
			error(Error::InvalidStatement, identifier.get());
		}
	}
}
