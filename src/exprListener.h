
// Generated from expr.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "exprParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by exprParser.
 */
class  exprListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProg(exprParser::ProgContext *ctx) = 0;
  virtual void exitProg(exprParser::ProgContext *ctx) = 0;

  virtual void enterMain(exprParser::MainContext *ctx) = 0;
  virtual void exitMain(exprParser::MainContext *ctx) = 0;


};

