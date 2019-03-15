#pragma once

#include "antlr4-runtime.h"
#include "exprBaseVisitor.h"

#include <string>

using namespace std;

class Visiteur : public exprBaseVisitor{
	public:
		Visiteur(){
		}
		
		virtual antlrcpp::Any visitProg(exprParser::ProgContext *ctx);

		virtual antlrcpp::Any visitMain(exprParser::MainContext *ctx);

		virtual antlrcpp::Any visitPreproc(exprParser::PreprocContext *ctx);

		virtual antlrcpp::Any visitInclude(exprParser::IncludeContext *ctx);

		virtual antlrcpp::Any visitBlock(exprParser::BlockContext *ctx);

		virtual antlrcpp::Any visitInstruction(exprParser::InstructionContext *ctx);

		virtual antlrcpp::Any visitDeclaration(exprParser::DeclarationContext *ctx);

		virtual antlrcpp::Any visitDefinition(exprParser::DefinitionContext *ctx);

		virtual antlrcpp::Any visitAdd(exprParser::AddContext *ctx);

		virtual antlrcpp::Any visitMult(exprParser::MultContext *ctx);

		virtual antlrcpp::Any visitVariable(exprParser::VariableContext *ctx);

		virtual antlrcpp::Any visitChar(exprParser::CharContext *ctx);

		virtual antlrcpp::Any visitParenthesis(exprParser::ParenthesisContext *ctx);

		virtual antlrcpp::Any visitInt(exprParser::IntContext *ctx);

		virtual antlrcpp::Any visitType(exprParser::TypeContext *ctx);
		
		virtual antlrcpp::Any visitRet(exprParser::RetContext *ctx);
		
		virtual ~Visiteur(){}

	protected:
		
	
};
