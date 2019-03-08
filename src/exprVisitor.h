
// Generated from src/expr.g4 by ANTLR 4.7.1

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


};

