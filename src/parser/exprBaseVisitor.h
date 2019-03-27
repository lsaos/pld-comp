
// Generated from src/expr.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "exprVisitor.h"


/**
 * This class provides an empty implementation of exprVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  exprBaseVisitor : public exprVisitor {
public:

  virtual antlrcpp::Any visitProg(exprParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPreproc(exprParser::PreprocContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInclude(exprParser::IncludeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMain(exprParser::MainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRetExpr(exprParser::RetExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRetNoExpr(exprParser::RetNoExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(exprParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInstruction(exprParser::InstructionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclaration(exprParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPlainNewVariable(exprParser::PlainNewVariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitValuedNewVariable(exprParser::ValuedNewVariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment(exprParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAdd(exprParser::AddContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMult(exprParser::MultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBin(exprParser::BinContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable(exprParser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChar(exprParser::CharContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnary(exprParser::UnaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParenthesis(exprParser::ParenthesisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInt(exprParser::IntContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncType(exprParser::FuncTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarType(exprParser::VarTypeContext *ctx) override {
    return visitChildren(ctx);
  }


};
