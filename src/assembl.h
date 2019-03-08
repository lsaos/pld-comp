#pragma once

#include "antlr4-runtime.h"
#include "exprBaseVisitor.h"

using namespace std;

class Assembl : public exprBaseVisitor{
	public:
		antlrcpp::Any visitProg(exprParser::ProgContext *ctx){
			int dummy= (int)visitChildren(ctx);
			return dummy;
		}
		
		antlrcpp::Any visitMain(exprParser::MainContext *ctx) {
			return stoi(ctx->INT()->getText());
		}
};
