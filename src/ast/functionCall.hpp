//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#pragma once

#include <vector>

using namespace std;

#include "identifier.hpp"

namespace ast
{
	class Function;

	// Represents a call to a function.
	class FunctionCall : public Expression
	{
	public:
		// Create a function call.
		FunctionCall(const ItemPosition& position);

	public:
		// Set the function identifier.
		void setIdentifier(Identifier* ident);

		// Add an argument to the function.
		void addArgument(Expression* arg);

	public:
		// Get the function called.
		Function* getCalledFunction() const;

		// Get the number of arguments passed to the function.
		size_t getArgumentsCount() const { return args.size(); }

		// Get the list of arguments passed to the function.
		vector<Expression*> getArguments() const;

	public:
		virtual Type getType() const;
		virtual void checkSemantic(bool advanced) const;
		virtual void prepare();
		virtual string getStringRepresentation() const;

	public:
		virtual bool isFunctionCall() const { return true; }

		virtual void generateAssembly(ofstream& f, unordered_map<ast::Variable*, int>& addressTable, string curReg = "%eax") {}

	private:
		vector<unique_ptr<Expression>> args; // Arguments to pass to the function.
		unique_ptr<Identifier> identifier; // Identifier referencing the called function.
	};
}
