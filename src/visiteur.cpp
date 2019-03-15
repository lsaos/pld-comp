#include "visiteur.hpp"

#include "ast/program.hpp"
#include "ast/assignment.hpp"
#include "ast/binaryExpression.hpp"
#include "ast/block.hpp"
#include "ast/constant.hpp"
#include "ast/controlStructure.hpp"
#include "ast/expression.hpp"
#include "ast/functionCall.hpp"
#include "ast/function.hpp"
#include "ast/instruction.hpp"
#include "ast/operator.hpp"
#include "ast/program.hpp"
#include "ast/type.hpp"
#include "ast/unaryExpression.hpp"
#include "ast/variable.hpp"
#include "ast/error.hpp"
#include "ast/return.hpp"

using namespace ast;

antlrcpp::Any Visiteur::visitProg(exprParser::ProgContext *ctx){
	Program* prog = new Program();
	prog->add((Instruction*)visit(ctx->main()));
	return prog;
}

antlrcpp::Any Visiteur::visitMain(exprParser::MainContext *ctx){
	int line = ctx->getRuleIndex();
	ItemPosition pos;
	pos.line=line;
	pos.offset=0;
	Function* func= new Function(pos);
	for(int i=0; i<ctx->instruction().size(); i++){
		func->add((Instruction*)visit(ctx->instruction(i)));
	}
	Return* ret = (Return*)visit(ctx->ret());
	func->add(ret);
	return func;
}

antlrcpp::Any Visiteur::visitPreproc(exprParser::PreprocContext *ctx){
//nothing
}

antlrcpp::Any Visiteur::visitInclude(exprParser::IncludeContext *ctx){
//nothing

}

antlrcpp::Any Visiteur::visitBlock(exprParser::BlockContext *ctx){
	//TODO
}

antlrcpp::Any Visiteur::visitInstruction(exprParser::InstructionContext *ctx){
	return (Instruction*)visitChildren(ctx);
}

antlrcpp::Any Visiteur::visitDeclaration(exprParser::DeclarationContext *ctx){
	Type type = (Type)visit(ctx->type());
	int line = ctx->SPACE(0)->getSymbol()->getLine();
	int column = ctx->SPACE(0)->getSymbol()->getCharPositionInLine()-4;
	ItemPosition pos;
	pos.line=line;
	pos.offset=column;
	Variable* variable = new Variable(pos);
	variable->setType(type);
	variable->setName(ctx->VAR()->getText());
	return variable;
}

antlrcpp::Any Visiteur::visitDefinition(exprParser::DefinitionContext *ctx){
	//TODO
}

antlrcpp::Any Visiteur::visitAdd(exprParser::AddContext *ctx){
	char opadd = ctx->OPADD()->getText().at(0);
	Expression* left = (Expression*) visit(ctx->expression(0));
	Expression* right = (Expression*) visit(ctx->expression(1));
	BinaryExpression* binExp = new BinaryExpression(left->getPosition());
	binExp->setLeftExpression(left);
	binExp->setRightExpression(right);
	switch(opadd){
		case '+':
			binExp->setOperator(BinaryOperator::Add);
			break;
		case '-':
			binExp->setOperator(BinaryOperator::Substract);
			break;
	}
	return binExp;
}

antlrcpp::Any Visiteur::visitMult(exprParser::MultContext *ctx){
	char opmul = ctx->OPMUL()->getText().at(0);
	Expression* left = (Expression*) visit(ctx->expression(0));
	Expression* right = (Expression*) visit(ctx->expression(1));
	BinaryExpression* binExp = new BinaryExpression(left->getPosition());
	binExp->setLeftExpression(left);
	binExp->setRightExpression(right);
	switch(opmul){
		case '*':
			binExp->setOperator(BinaryOperator::Multiply);
			break;
		case '/':
			binExp->setOperator(BinaryOperator::Divide);
			break;
	}
	return binExp;
}

antlrcpp::Any Visiteur::visitVariable(exprParser::VariableContext *ctx){

}

antlrcpp::Any Visiteur::visitChar(exprParser::CharContext *ctx){
	char value = (char)ctx->CHAR()->getText().at(1);
	int line = ctx->CHAR()->getSymbol()->getLine();
	int column = ctx->CHAR()->getSymbol()->getCharPositionInLine();
	ItemPosition pos;
	pos.line=line;
	pos.offset=column;
	Constant * constante = new Constant(pos);
	constante->setType(Type::Character);
	constante->setValue(value); 
	return constante;
}

antlrcpp::Any Visiteur::visitParenthesis(exprParser::ParenthesisContext *ctx){
	//TODO
}

antlrcpp::Any Visiteur::visitInt(exprParser::IntContext *ctx){
	int value = stoi(ctx->INT()->getText());
	int line = ctx->INT()->getSymbol()->getLine();
	int column = ctx->INT()->getSymbol()->getCharPositionInLine();
	ItemPosition pos;
	pos.line=line;
	pos.offset=column;
	Constant * constante = new Constant(pos);
	constante->setType(Type::Integer);
	constante->setValue(value); 
	return constante;
}

antlrcpp::Any Visiteur::visitType(exprParser::TypeContext *ctx){
	string type = ctx->getText();
	if (type=="char"){
		return Type::Character;
	} else if(type=="int"){
		return Type::Integer;
	}
}


antlrcpp::Any Visiteur::visitRet(exprParser::RetContext *ctx){
	//TODO
}
