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
		virtual Type getType() const;
		virtual void checkSemantic(bool advanced) const;

	public:
		virtual bool isFunctionCall() const { return true; }

		virtual void generateAssembly(ofstream& f, unordered_map<ast::Variable*,int>& addressTable) {}

	private:
		vector<unique_ptr<Expression>> args; // Arguments to pass to the function.
		unique_ptr<Identifier> identifier; // Identifier referencing the called function.
	};
}
