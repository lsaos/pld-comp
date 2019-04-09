//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#include "functionCall.hpp"
#include "function.hpp"
#include "variable.hpp"
#include "../ir/cfg.hpp"
#include "../ir/basicBlock.hpp"
#include "../ir/irInstrCall.hpp"

using namespace ir;

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

	Function* FunctionCall::getCalledFunction() const
	{
		if (identifier) {
			return identifier->getReferencedFunction();
		}
		else {
			return nullptr;
		}
	}

	vector<Expression*> FunctionCall::getArguments() const
	{
		vector<Expression*> ar;
		for (const auto& arg : args) {
			ar.push_back(arg.get());
		}
		return ar;
	}

	void FunctionCall::checkSemantic(bool advanced) const
	{
		if (!identifier) {
			error(Error::InvalidStatement, this);
		}

		identifier->checkSemantic(advanced);

		// The identifier must reference an existing function
		const Function* func = identifier->getReferencedFunction();
		if (!func) {
			error(Error::UnknownIdentifier, identifier.get());
		}

		const vector<Variable*> params = func->getParameters();
		if (args.size() != params.size()) {
			error(Error::WrongArgumentsCount, this);
		}

		for (size_t i = 0; i < args.size(); i++) {
			args[i]->checkSemantic(advanced);

			if (args[i]->getType() == Type::Void) {
				error(Error::InvalidStatement, args[i].get());
			}

			if (advanced && i < params.size() && !args[i]->isCastSafe(params[i]->getType())) {
				warning(Warning::UnsafeCast, args[i].get());
			}
		}
	}

	void FunctionCall::prepare()
	{
		if (identifier) {
			identifier->prepare();
		}

		for (auto& arg : args) {
			arg->prepare();
		}
	}

	string FunctionCall::getStringRepresentation() const
	{
		if (identifier) {
			return identifier->getIdent();
		}
		else {
			return string();
		}
	}

	void FunctionCall::toTextualRepresentation(ostream& out, size_t i) const
	{
		for (size_t j = 0; j < i; j++) { out << ' '; }
		out << "Call {" << endl;

		identifier->toTextualRepresentation(out, i + 1);

		if (!args.empty()) {
			for (size_t j = 0; j < i + 1; j++) { out << ' '; }
			out << "Arguments {" << endl;

			for (const auto& arg : args) {
				arg->toTextualRepresentation(out, i + 2);
			}

			for (size_t j = 0; j < i + 1; j++) { out << ' '; }
			out << '}' << endl;
		}

		for (size_t j = 0; j < i; j++) { out << ' '; }
		out << '}' << endl;
	}

	string FunctionCall::buildIR(ir::CFG* cfg)
	{
		string dest = cfg->create_new_tempvar(identifier->getType());
		vector<string> op;
		string temp;

		for (auto& exp : args)
		{
			temp = exp.get()->buildIR(cfg);
			op.push_back(temp);
		}

		bool isExternal = identifier->getReferencedFunction()->isExtern();

		IRInstrCall* instr = new IRInstrCall(cfg->current_bb, dest, identifier->getReferencedFunction()->getName(), op, isExternal);
		cfg->current_bb->add_IRInstr(instr,identifier->getType());

		return dest;
	}
}
