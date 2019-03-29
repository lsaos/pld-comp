#pragma once

#include "antlr4-runtime.h"
#include "../parser/exprBaseVisitor.h"
#include "../ast/instruction.hpp"

#include <string>
#ifdef TREEVISIT
#include <iostream>
#endif

using namespace std;

class Visiteur : public exprBaseVisitor {
public:
	Visiteur() {
#ifdef TREEVISIT
		indent = 0;
#endif
	}

	virtual antlrcpp::Any visitProg(exprParser::ProgContext *ctx);

	virtual antlrcpp::Any visitMain(exprParser::MainContext *ctx);

	virtual antlrcpp::Any visitPreproc(exprParser::PreprocContext *ctx);

	virtual antlrcpp::Any visitInclude(exprParser::IncludeContext *ctx);

	virtual antlrcpp::Any visitBlock(exprParser::BlockContext *ctx);

	virtual antlrcpp::Any visitRetExpr(exprParser::RetExprContext *context);

	virtual antlrcpp::Any visitRetNoExpr(exprParser::RetNoExprContext *context);

	virtual antlrcpp::Any visitInstruction(exprParser::InstructionContext *ctx);

	virtual antlrcpp::Any visitDeclaration(exprParser::DeclarationContext *ctx);

	virtual antlrcpp::Any visitPlainNewVariable(exprParser::PlainNewVariableContext *context);

	virtual antlrcpp::Any visitValuedNewVariable(exprParser::ValuedNewVariableContext *context);

	virtual antlrcpp::Any visitAssignment(exprParser::AssignmentContext *ctx);

	virtual antlrcpp::Any visitUnary(exprParser::UnaryContext *ctx);
	
	virtual antlrcpp::Any visitNegativeUnary(exprParser::NegativeUnaryContext *ctx);

	virtual antlrcpp::Any visitBin(exprParser::BinContext *ctx);

	virtual antlrcpp::Any visitAdd(exprParser::AddContext *ctx);
	
	virtual antlrcpp::Any visitSub(exprParser::SubContext *ctx);

	virtual antlrcpp::Any visitMult(exprParser::MultContext *ctx);

	virtual antlrcpp::Any visitVariable(exprParser::VariableContext *ctx);

	virtual antlrcpp::Any visitChar(exprParser::CharContext *ctx);

	virtual antlrcpp::Any visitParenthesis(exprParser::ParenthesisContext *ctx);

	virtual antlrcpp::Any visitInt(exprParser::IntContext *ctx);

	virtual antlrcpp::Any visitFuncType(exprParser::FuncTypeContext *context);

	virtual antlrcpp::Any visitVarType(exprParser::VarTypeContext *ctx);

	virtual ~Visiteur() {}

#ifdef TREEVISIT
	void jump() {
		for (int i = 0; i < indent; i++) {
			cout << "\t";
		}
	}
#endif

private:
	ast::ItemPosition buildPos(size_t line, size_t column);
#ifdef TREEVISIT
	int indent;
#endif

};
