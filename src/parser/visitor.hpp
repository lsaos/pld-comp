#pragma once

#include "antlr4-runtime.h"
#include "../parser/exprBaseVisitor.h"
#include "../ast/instruction.hpp"
#include "../ast/expression.hpp"
#include "../ast/operator.hpp"

#include <string>
#ifdef TREEVISIT
#include <iostream>
#endif

using namespace std;

class Visitor : public exprBaseVisitor {
public:
	Visitor() {
#ifdef TREEVISIT
		indent=0;
#endif
	}

    ast::Expression* buildBinaryExpression(exprParser::ExpressionContext*, ast::BinaryOperator);
    ast::Expression* buildUnaryExpression(exprParser::ExpressionContext*, ast::UnaryOperator);

	virtual antlrcpp::Any visitProg(exprParser::ProgContext *context);

    virtual antlrcpp::Any visitFunction(exprParser::FunctionContext *context);
    
    virtual antlrcpp::Any visitParameters(exprParser::ParametersContext *context);

    virtual antlrcpp::Any visitDeclaration(exprParser::DeclarationContext *context);

    virtual antlrcpp::Any visitPlainNewVariable(exprParser::PlainNewVariableContext *context);

    virtual antlrcpp::Any visitValuedNewVariable(exprParser::ValuedNewVariableContext *context);
    
    virtual antlrcpp::Any visitDeclareVariable(exprParser::DeclareVariableContext *context);

    virtual antlrcpp::Any visitDeclareArray(exprParser::DeclareArrayContext *context);

    virtual antlrcpp::Any visitRetExpr(exprParser::RetExprContext *context);

    virtual antlrcpp::Any visitRetNoExpr(exprParser::RetNoExprContext *context);

    virtual antlrcpp::Any visitBlock(exprParser::BlockContext *context);

    virtual antlrcpp::Any visitInstruction(exprParser::InstructionContext *context);

    virtual antlrcpp::Any visitAssignment(exprParser::AssignmentContext *context);
    
    virtual antlrcpp::Any visitVariableExpression(exprParser::VariableExpressionContext *context);

    virtual antlrcpp::Any visitArrayExpression(exprParser::ArrayExpressionContext *context);

    virtual antlrcpp::Any visitOptional(exprParser::OptionalContext *context);

    virtual antlrcpp::Any visitWhileLoop(exprParser::WhileLoopContext *context);

    virtual antlrcpp::Any visitForLoop(exprParser::ForLoopContext *context);
    
    virtual antlrcpp::Any visitForDeclaration(exprParser::ForDeclarationContext *context);

    virtual antlrcpp::Any visitForAssignment(exprParser::ForAssignmentContext *context);

    virtual antlrcpp::Any visitCondition(exprParser::ConditionContext *context);

    virtual antlrcpp::Any visitControlBody(exprParser::ControlBodyContext *context);
    
    virtual antlrcpp::Any visitExprFunc(exprParser::ExprFuncContext *context);

    virtual antlrcpp::Any visitAdd(exprParser::AddContext *context);

    virtual antlrcpp::Any visitMinus(exprParser::MinusContext *context);

    virtual antlrcpp::Any visitLogicalNot(exprParser::LogicalNotContext *context);

    virtual antlrcpp::Any visitLowerThan(exprParser::LowerThanContext *context);

    virtual antlrcpp::Any visitLowerThanEquals(exprParser::LowerThanEqualsContext *context);

    virtual antlrcpp::Any visitBitwiseXor(exprParser::BitwiseXorContext *context);

    virtual antlrcpp::Any visitBitwiseAnd(exprParser::BitwiseAndContext *context);

    virtual antlrcpp::Any visitParenthesis(exprParser::ParenthesisContext *context);

    virtual antlrcpp::Any visitInt(exprParser::IntContext *context);

    virtual antlrcpp::Any visitDifferent(exprParser::DifferentContext *context);

    virtual antlrcpp::Any visitLogicalOr(exprParser::LogicalOrContext *context);

    virtual antlrcpp::Any visitBitwiseNot(exprParser::BitwiseNotContext *context);

    virtual antlrcpp::Any visitGreaterThanEquals(exprParser::GreaterThanEqualsContext *context);

    virtual antlrcpp::Any visitGreaterThan(exprParser::GreaterThanContext *context);

    virtual antlrcpp::Any visitEquals(exprParser::EqualsContext *context);

    virtual antlrcpp::Any visitLogicalAnd(exprParser::LogicalAndContext *context);

    virtual antlrcpp::Any visitVariable(exprParser::VariableContext *context);

    virtual antlrcpp::Any visitChar(exprParser::CharContext *context);

    virtual antlrcpp::Any visitBitwiseOr(exprParser::BitwiseOrContext *context);

    virtual antlrcpp::Any visitMultiply(exprParser::MultiplyContext *context);

    virtual antlrcpp::Any visitSubstract(exprParser::SubstractContext *context);

    virtual antlrcpp::Any visitLeftShift(exprParser::LeftShiftContext *context);
    virtual antlrcpp::Any visitRightShift(exprParser::RightShiftContext *context);
    
    virtual antlrcpp::Any visitAssignmentExpression(exprParser::AssignmentExpressionContext *context);

    virtual antlrcpp::Any visitFuncType(exprParser::FuncTypeContext *context);

    virtual antlrcpp::Any visitVarType(exprParser::VarTypeContext *context);
    
    virtual antlrcpp::Any visitFuncCall(exprParser::FuncCallContext *context);

    virtual antlrcpp::Any visitFuncCallArguments(exprParser::FuncCallArgumentsContext *context);
    
	virtual ~Visitor() {}

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
