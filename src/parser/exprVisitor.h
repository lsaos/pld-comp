
// Generated from /home/lohl/Documents/COMP/src/parser/expr.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "exprParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by exprParser.
 */
class  exprVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by exprParser.
   */
    virtual antlrcpp::Any visitProg(exprParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitMain(exprParser::MainContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration(exprParser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitPlainNewVariable(exprParser::PlainNewVariableContext *context) = 0;

    virtual antlrcpp::Any visitValuedNewVariable(exprParser::ValuedNewVariableContext *context) = 0;

    virtual antlrcpp::Any visitRetExpr(exprParser::RetExprContext *context) = 0;

    virtual antlrcpp::Any visitRetNoExpr(exprParser::RetNoExprContext *context) = 0;

    virtual antlrcpp::Any visitBlock(exprParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitInstruction(exprParser::InstructionContext *context) = 0;

    virtual antlrcpp::Any visitAssignment(exprParser::AssignmentContext *context) = 0;

    virtual antlrcpp::Any visitOptional(exprParser::OptionalContext *context) = 0;

    virtual antlrcpp::Any visitWhileLoop(exprParser::WhileLoopContext *context) = 0;

    virtual antlrcpp::Any visitForLoop(exprParser::ForLoopContext *context) = 0;

    virtual antlrcpp::Any visitCondition(exprParser::ConditionContext *context) = 0;

    virtual antlrcpp::Any visitControlBody(exprParser::ControlBodyContext *context) = 0;

    virtual antlrcpp::Any visitAdd(exprParser::AddContext *context) = 0;

    virtual antlrcpp::Any visitMinus(exprParser::MinusContext *context) = 0;

    virtual antlrcpp::Any visitLogicalNot(exprParser::LogicalNotContext *context) = 0;

    virtual antlrcpp::Any visitLowerThan(exprParser::LowerThanContext *context) = 0;

    virtual antlrcpp::Any visitLowerThanEquals(exprParser::LowerThanEqualsContext *context) = 0;

    virtual antlrcpp::Any visitBitwiseXor(exprParser::BitwiseXorContext *context) = 0;

    virtual antlrcpp::Any visitBitwiseAnd(exprParser::BitwiseAndContext *context) = 0;

    virtual antlrcpp::Any visitParenthesis(exprParser::ParenthesisContext *context) = 0;

    virtual antlrcpp::Any visitInt(exprParser::IntContext *context) = 0;

    virtual antlrcpp::Any visitDifferent(exprParser::DifferentContext *context) = 0;

    virtual antlrcpp::Any visitLogicalOr(exprParser::LogicalOrContext *context) = 0;

    virtual antlrcpp::Any visitBitwiseNot(exprParser::BitwiseNotContext *context) = 0;

    virtual antlrcpp::Any visitGreaterThanEquals(exprParser::GreaterThanEqualsContext *context) = 0;

    virtual antlrcpp::Any visitGreaterThan(exprParser::GreaterThanContext *context) = 0;

    virtual antlrcpp::Any visitEquals(exprParser::EqualsContext *context) = 0;

    virtual antlrcpp::Any visitLogicalAnd(exprParser::LogicalAndContext *context) = 0;

    virtual antlrcpp::Any visitVariable(exprParser::VariableContext *context) = 0;

    virtual antlrcpp::Any visitChar(exprParser::CharContext *context) = 0;

    virtual antlrcpp::Any visitBitwiseOr(exprParser::BitwiseOrContext *context) = 0;

    virtual antlrcpp::Any visitMultiply(exprParser::MultiplyContext *context) = 0;

    virtual antlrcpp::Any visitRightShift(exprParser::RightShiftContext *context) = 0;

    virtual antlrcpp::Any visitSubstract(exprParser::SubstractContext *context) = 0;

    virtual antlrcpp::Any visitLeftShift(exprParser::LeftShiftContext *context) = 0;

    virtual antlrcpp::Any visitFuncType(exprParser::FuncTypeContext *context) = 0;

    virtual antlrcpp::Any visitVarType(exprParser::VarTypeContext *context) = 0;


};

