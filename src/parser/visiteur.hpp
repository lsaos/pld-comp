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
		indent=0;
#endif
	}

	virtual antlrcpp::Any visitProg(exprParser::ProgContext *context);
    virtual antlrcpp::Any visitPreproc(exprParser::PreprocContext *context);
    virtual antlrcpp::Any visitInclude(exprParser::IncludeContext *context);
    virtual antlrcpp::Any visitMain(exprParser::MainContext *context);
    virtual antlrcpp::Any visitDeclaration(exprParser::DeclarationContext *context);
    virtual antlrcpp::Any visitPlainNewVariable(exprParser::PlainNewVariableContext *context);
    virtual antlrcpp::Any visitValuedNewVariable(exprParser::ValuedNewVariableContext *context);
    virtual antlrcpp::Any visitRetExpr(exprParser::RetExprContext *context);
    virtual antlrcpp::Any visitRetNoExpr(exprParser::RetNoExprContext *context);
    virtual antlrcpp::Any visitBlock(exprParser::BlockContext *context);
    virtual antlrcpp::Any visitInstruction(exprParser::InstructionContext *context);
    virtual antlrcpp::Any visitAssignment(exprParser::AssignmentContext *context);
    virtual antlrcpp::Any visitOptional(exprParser::OptionalContext *context);
    virtual antlrcpp::Any visitLoop(exprParser::LoopContext *context);
    virtual antlrcpp::Any visitCondition(exprParser::ConditionContext *context);
    virtual antlrcpp::Any visitControlBody(exprParser::ControlBodyContext *context);
    virtual antlrcpp::Any visitAdd(exprParser::AddContext *context);
    virtual antlrcpp::Any visitSub(exprParser::SubContext *context);
    virtual antlrcpp::Any visitMult(exprParser::MultContext *context);
    virtual antlrcpp::Any visitBin(exprParser::BinContext *context);
    virtual antlrcpp::Any visitVariable(exprParser::VariableContext *context);
    virtual antlrcpp::Any visitChar(exprParser::CharContext *context);
    virtual antlrcpp::Any visitNegativeUnary(exprParser::NegativeUnaryContext *context);
    virtual antlrcpp::Any visitUnary(exprParser::UnaryContext *context);
    virtual antlrcpp::Any visitParenthesis(exprParser::ParenthesisContext *context);
    virtual antlrcpp::Any visitInt(exprParser::IntContext *context);
    virtual antlrcpp::Any visitLogical(exprParser::LogicalContext *context);
    virtual antlrcpp::Any visitComparison(exprParser::ComparisonContext *context);
    virtual antlrcpp::Any visitFuncType(exprParser::FuncTypeContext *context);
    virtual antlrcpp::Any visitVarType(exprParser::VarTypeContext *context);
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
