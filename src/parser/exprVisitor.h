
// Generated from src/expr.g4 by ANTLR 4.7.2

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

    virtual antlrcpp::Any visitPreproc(exprParser::PreprocContext *context) = 0;

    virtual antlrcpp::Any visitInclude(exprParser::IncludeContext *context) = 0;

    virtual antlrcpp::Any visitMain(exprParser::MainContext *context) = 0;

    virtual antlrcpp::Any visitRetExpr(exprParser::RetExprContext *context) = 0;

    virtual antlrcpp::Any visitRetNoExpr(exprParser::RetNoExprContext *context) = 0;

    virtual antlrcpp::Any visitBlock(exprParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitInstruction(exprParser::InstructionContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration(exprParser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitPlainNewVariable(exprParser::PlainNewVariableContext *context) = 0;

    virtual antlrcpp::Any visitValuedNewVariable(exprParser::ValuedNewVariableContext *context) = 0;

    virtual antlrcpp::Any visitAssignment(exprParser::AssignmentContext *context) = 0;

    virtual antlrcpp::Any visitAdd(exprParser::AddContext *context) = 0;

    virtual antlrcpp::Any visitMult(exprParser::MultContext *context) = 0;

    virtual antlrcpp::Any visitBin(exprParser::BinContext *context) = 0;

    virtual antlrcpp::Any visitVariable(exprParser::VariableContext *context) = 0;

    virtual antlrcpp::Any visitChar(exprParser::CharContext *context) = 0;

    virtual antlrcpp::Any visitUnary(exprParser::UnaryContext *context) = 0;

    virtual antlrcpp::Any visitParenthesis(exprParser::ParenthesisContext *context) = 0;

    virtual antlrcpp::Any visitInt(exprParser::IntContext *context) = 0;

    virtual antlrcpp::Any visitFuncType(exprParser::FuncTypeContext *context) = 0;

    virtual antlrcpp::Any visitVarType(exprParser::VarTypeContext *context) = 0;


};

