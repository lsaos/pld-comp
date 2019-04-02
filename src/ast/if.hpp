//
// (c) 2019 The Super 4404 C Compiler
// A.Belin, A.Nahid, L.Ohl, L.Saos, A.Verrier, I.Zemmouri
// INSA Lyon
//

#pragma once

#include "controlStructure.hpp"

namespace ast
{
	// Create a condition control structure.
	// An if can have an alternative (else)
	// to execute when the condition is false.
	class If : public ControlStructure
	{
	public:
		// Create an if.
		If(const ItemPosition& position);

	public:
		// Set the alternative instruction (else) to execute
		// when the condition is false.
		void setAlternative(Instruction* alt);

	public:
		// Get the alternative instruction (else) to execute
		// when the condition is false.
		// It can be null.
		Instruction* getAlternative() const {
			return alternative.get();
		}

		// Return true if the the if has an else.
		bool hasAlternative() const {
			return alternative != nullptr;
		}

	public:
		virtual void checkSemantic(bool advanced) const;
		virtual Instruction* optimize();
		virtual void prepare();

		virtual string getStringRepresentation() const { return "if"; }
		virtual void toTextualRepresentation(ostream& out, size_t i) const {}
		virtual void generateAssembly(ofstream& f, unordered_map<ast::Variable*,int>& addressTable, string curReg = "%eax") {}

		virtual bool isIf() const { return true; }

	private:
		unique_ptr<Instruction> alternative; // Alternative instruction to execute when the condition is false.
	};
}
