
// Generated from /home/louis/Documents/Projets/COMP/src/parser/expr.g4 by ANTLR 4.7.2

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

  virtual antlrcpp::Any visitMain(exprParser::MainContext *ctx) override {
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

  virtual antlrcpp::Any visitAssignment(exprParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOptional(exprParser::OptionalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileLoop(exprParser::WhileLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForLoop(exprParser::ForLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondition(exprParser::ConditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitControlBody(exprParser::ControlBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAdd(exprParser::AddContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMinus(exprParser::MinusContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicalNot(exprParser::LogicalNotContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLowerThan(exprParser::LowerThanContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLowerThanEquals(exprParser::LowerThanEqualsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitwiseXor(exprParser::BitwiseXorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitwiseAnd(exprParser::BitwiseAndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParenthesis(exprParser::ParenthesisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInt(exprParser::IntContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDifferent(exprParser::DifferentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicalOr(exprParser::LogicalOrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitwiseNot(exprParser::BitwiseNotContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGreaterThanEquals(exprParser::GreaterThanEqualsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGreaterThan(exprParser::GreaterThanContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEquals(exprParser::EqualsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicalAnd(exprParser::LogicalAndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable(exprParser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChar(exprParser::CharContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitwiseOr(exprParser::BitwiseOrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultiply(exprParser::MultiplyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRightShift(exprParser::RightShiftContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubstract(exprParser::SubstractContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLeftShift(exprParser::LeftShiftContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncType(exprParser::FuncTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarType(exprParser::VarTypeContext *ctx) override {
    return visitChildren(ctx);
  }


};

