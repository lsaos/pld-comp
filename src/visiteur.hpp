#pragma once

#include "antlr4-runtime.h"
#include "exprBaseVisitor.h"
#include "ast/instruction.hpp"

#include <string>
#ifdef TREEVISIT
#include <iostream>
#endif

using namespace std;

class Visiteur : public exprBaseVisitor{
	public:
		Visiteur(){
		#ifdef TREEVISIT
			indent=0;
		#endif
		}
		
		virtual antlrcpp::Any visitProg(exprParser::ProgContext *ctx);

		virtual antlrcpp::Any visitMain(exprParser::MainContext *ctx);

		virtual antlrcpp::Any visitPreproc(exprParser::PreprocContext *ctx);

		virtual antlrcpp::Any visitInclude(exprParser::IncludeContext *ctx);

		virtual antlrcpp::Any visitBlock(exprParser::BlockContext *ctx);
		
		virtual antlrcpp::Any visitRet(exprParser::RetContext *ctx);

		virtual antlrcpp::Any visitInstruction(exprParser::InstructionContext *ctx);

		virtual antlrcpp::Any visitDeclaration(exprParser::DeclarationContext *ctx);

		virtual antlrcpp::Any visitDefinition(exprParser::DefinitionContext *ctx);
		
		virtual antlrcpp::Any visitAssignment(exprParser::AssignmentContext *ctx);

		virtual antlrcpp::Any visitBin(exprParser::BinContext *ctx);

		virtual antlrcpp::Any visitAdd(exprParser::AddContext *ctx);

		virtual antlrcpp::Any visitMult(exprParser::MultContext *ctx);

		virtual antlrcpp::Any visitVariable(exprParser::VariableContext *ctx);

		virtual antlrcpp::Any visitChar(exprParser::CharContext *ctx);

		virtual antlrcpp::Any visitParenthesis(exprParser::ParenthesisContext *ctx);

		virtual antlrcpp::Any visitInt(exprParser::IntContext *ctx);

		virtual antlrcpp::Any visitType(exprParser::TypeContext *ctx);
		
		virtual ~Visiteur(){}
		
		#ifdef TREEVISIT
		void jump(){
			for(int i=0; i<indent; i++){
				cout<<"\t";
			}
		}
		#endif

	private:
		ast::ItemPosition buildPos(int line, int column);
		#ifdef TREEVISIT
		int indent;
		#endif
	
};
