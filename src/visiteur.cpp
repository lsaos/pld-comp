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

ItemPosition Visiteur::buildPos(int line, int column) {
	ItemPosition pos;
	pos.line = line;
	pos.offset = column;
	return pos;
}

antlrcpp::Any Visiteur::visitProg(exprParser::ProgContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "PROG(" << endl;
	indent++;
#endif
	Program* prog = new Program();
	Instruction* instr = (Instruction*)visit(ctx->main());
	prog->add(instr);
#ifdef TREEVISIT
	jump(); cout << ")" << endl;
	indent--;
#endif
	return prog;
}

antlrcpp::Any Visiteur::visitMain(exprParser::MainContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "MAIN(" << endl;
	indent++;
#endif
	ItemPosition pos = buildPos(ctx->getRuleIndex(), 0);
	Function* func = new Function(pos);
	for (int i = 0; i < ctx->instruction().size(); i++) {
		func->add((Instruction*)visit(ctx->instruction(i)));
	}
	Return* ret = (Return*)visit(ctx->ret());
	func->add(ret);
	func->setName("main");
	func->setType(Type::Integer);
#ifdef TREEVISIT
	jump(); cout << ")" << endl;
	indent--;
#endif
	return (Instruction*)func;
}


antlrcpp::Any Visiteur::visitPreproc(exprParser::PreprocContext *ctx) {
	return antlrcpp::Any();
}

antlrcpp::Any Visiteur::visitInclude(exprParser::IncludeContext *ctx) {
	return antlrcpp::Any();
}

antlrcpp::Any Visiteur::visitBlock(exprParser::BlockContext *ctx) {
	return antlrcpp::Any();
}


antlrcpp::Any Visiteur::visitRet(exprParser::RetContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "RETURN(" << endl;
	indent++;
#endif
	ItemPosition pos = buildPos(ctx->SPACE(0)->getSymbol()->getLine(), ctx->SPACE(0)->getSymbol()->getCharPositionInLine() - 6);
	Expression* expr = (Expression*)visit(ctx->expression());
	Return* ret = new Return(pos);
	ret->setExpression(expr);
#ifdef TREEVISIT
	jump(); cout << ")" << endl;
	indent--;
#endif
	return ret;
}

antlrcpp::Any Visiteur::visitInstruction(exprParser::InstructionContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "INSTRUCTION [" << endl;
#endif
	Instruction* instr = (Instruction*)visit(ctx->children[0]);
#ifdef TREEVISIT
	jump(); cout << "]" << endl;
#endif
	return instr;
}

antlrcpp::Any Visiteur::visitDeclaration(exprParser::DeclarationContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "DECLARATION(" << endl;
	indent++;
#endif
	ItemPosition pos = buildPos(ctx->SPACE(0)->getSymbol()->getLine(), ctx->SPACE(0)->getSymbol()->getCharPositionInLine() - 4);
	Type type = (Type)visit(ctx->type());
	Variable* variable = new Variable(pos);
	variable->setType(type);
	variable->setName(ctx->VAR()->getText());
    variable->setScope(Scope::Block);
	#ifdef TREEVISIT
		jump(); cout <<")"<<endl;
		indent--;
	#endif
	return (Instruction*)variable;
}

antlrcpp::Any Visiteur::visitDefinition(exprParser::DefinitionContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "DEFINITION(" << endl;
	indent++;
#endif
	ItemPosition pos = buildPos(ctx->SPACE(0)->getSymbol()->getLine(), ctx->SPACE(0)->getSymbol()->getCharPositionInLine() - 4);
	Type type = (Type)visit(ctx->type());
	Variable* variable = new Variable(pos);
	variable->setType(type);
	variable->setName(ctx->VAR()->getText());
    variable->setScope(Scope::Block);
	Expression* expression = (Expression*)visit(ctx->expression());
	Assignment* assignment = new Assignment(pos);
	assignment->setValue(expression);
	Identifier* identifier = new Identifier(pos);
	identifier->setIdentifiable(variable);
	assignment->setIdentifier(identifier);
#ifdef TREEVISIT
	jump(); cout << ")" << endl;
	indent--;
#endif
	return (Instruction*)assignment;
}

antlrcpp::Any Visiteur::visitAssignment(exprParser::AssignmentContext *ctx) {

#ifdef TREEVISIT
	jump(); cout << "ASSIGNMENT(" << endl;
	indent++;
#endif
	ItemPosition pos = buildPos(ctx->VAR()->getSymbol()->getLine(), ctx->VAR()->getSymbol()->getCharPositionInLine());
	Assignment* assignment = new Assignment(pos);
	Expression* expression = (Expression*)visit(ctx->expression());
	Identifiable* identifiable = new Identifiable;
	identifiable->setName(ctx->VAR()->getText());
	Identifier* identifier = new Identifier(pos);
	identifier->setIdentifiable(identifiable);
	assignment->setValue(expression);
	assignment->setIdentifier(identifier);
#ifdef TREEVISIT
	jump(); cout << ")" << endl;
	indent--;
#endif
	return (Instruction*)assignment;

}

antlrcpp::Any Visiteur::visitUnary(exprParser::UnaryContext *ctx){
    #ifdef TREEVISIT
        jump();
        cout << "UNAIRE("<<endl;
        indent++;
    #endif
    char opUnary = ctx->UNARYOP()->getText().at(0);
    Expression* expr =(Expression*) visit(ctx->expression());
    UnaryExpression* unary = new UnaryExpression(expr->getPosition());
    unary->setExpression(unary);
    switch(opUnary){
        case '-':
            unary->setOperator(UnaryOperator::Minus);
            break;
        case '!':
            unary->setOperator(UnaryOperator::Not);
            break;
    }
    #ifdef TREEVISIT
        jump(); cout << ")" << endl;
        indent--;
    #endif
    return (Expression*)unary;
}

antlrcpp::Any Visiteur::visitBin(exprParser::BinContext *ctx){
	#ifdef TREEVISIT
		jump(); cout << "BINAIRE("<<endl;
		indent++;
	#endif
	char opbin = ctx->OPBIN()->getText().at(0);
	Expression* left = (Expression*)visit(ctx->expression(0));
	Expression* right = (Expression*)visit(ctx->expression(1));
	BinaryExpression* binExp = new BinaryExpression(left->getPosition());
	binExp->setLeftExpression(left);
	binExp->setRightExpression(right);
	switch (opbin) {
	case '&':
		binExp->setOperator(BinaryOperator::LogicalAnd);
		break;
	case '^':
		binExp->setOperator(BinaryOperator::LogicalXor);
		break;
	case '|':
		binExp->setOperator(BinaryOperator::LogicalOr);
		break;
	}
#ifdef TREEVISIT
	jump(); cout << ")" << endl;
	indent--;
#endif
	return (Expression*)binExp;
}

antlrcpp::Any Visiteur::visitAdd(exprParser::AddContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "SOMME(" << endl;
	indent++;
#endif
	char opadd = ctx->OPADD()->getText().at(0);
	Expression* left = (Expression*)visit(ctx->expression(0));
	Expression* right = (Expression*)visit(ctx->expression(1));
	BinaryExpression* binExp = new BinaryExpression(left->getPosition());
	binExp->setLeftExpression(left);
	binExp->setRightExpression(right);
	switch (opadd) {
	case '+':
		binExp->setOperator(BinaryOperator::Add);
		break;
	case '-':
		binExp->setOperator(BinaryOperator::Substract);
		break;
	}
#ifdef TREEVISIT
	jump(); cout << ")" << endl;
	indent--;
#endif
	return (Expression*)binExp;
}

antlrcpp::Any Visiteur::visitMult(exprParser::MultContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "MUL(" << endl;
	indent++;
#endif
	char opmul = ctx->OPMUL()->getText().at(0);
	Expression* left = (Expression*)visit(ctx->expression(0));
	Expression* right = (Expression*)visit(ctx->expression(1));
	BinaryExpression* binExp = new BinaryExpression(left->getPosition());
	binExp->setLeftExpression(left);
	binExp->setRightExpression(right);
	switch (opmul) {
	case '*':
		binExp->setOperator(BinaryOperator::Multiply);
		break;
	case '/':
		binExp->setOperator(BinaryOperator::Divide);
		break;
	}
#ifdef TREEVISIT
	jump(); cout << ")" << endl;
	indent--;
#endif
	return (Expression*)binExp;
}

antlrcpp::Any Visiteur::visitParenthesis(exprParser::ParenthesisContext *ctx){
	#ifdef TREEVISIT
		jump(); cout << "PARENTHESIS("<<endl;
		indent++;
	#endif
	Expression* expr = (Expression*)visit(ctx->expression());
	#ifdef TREEVISIT
		jump(); cout <<")"<<endl;
		indent--;
	#endif
	return expr;
}

antlrcpp::Any Visiteur::visitVariable(exprParser::VariableContext *ctx){
	#ifdef TREEVISIT
		jump(); cout << "VAR"<<endl;
	#endif
	ItemPosition pos = buildPos(ctx->VAR()->getSymbol()->getLine(), ctx->VAR()->getSymbol()->getCharPositionInLine());
	//FIXME : create variable ?
	Identifier* identifier = new Identifier(pos);
	Identifiable* identifiable = new Identifiable();
	identifiable->setName(ctx->VAR()->getText());
	identifier->setIdentifiable(identifiable);
	return (Expression*)identifier;
}

antlrcpp::Any Visiteur::visitChar(exprParser::CharContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "CHAR" << endl;
#endif
	ItemPosition pos = buildPos(ctx->CHAR()->getSymbol()->getLine(), ctx->CHAR()->getSymbol()->getCharPositionInLine());
	char value = (char)ctx->CHAR()->getText().at(1);
	Constant * constant = new Constant(pos);
	constant->setType(Type::Character);
	constant->setValue(value);
	return (Expression*)constant;
}

antlrcpp::Any Visiteur::visitInt(exprParser::IntContext *ctx) {
    #ifdef TREEVISIT
	    jump(); cout << "INT";
    #endif
	ItemPosition pos = buildPos(ctx->INT()->getSymbol()->getLine(), ctx->INT()->getSymbol()->getCharPositionInLine());
	int value = stoi(ctx->INT()->getText());
	Constant * constante = new Constant(pos);
	constante->setType(Type::Integer);
	constante->setValue(value);
#ifdef TREEVISIT
	cout << "()" << endl;
#endif
	return (Expression*)constante;
}

antlrcpp::Any Visiteur::visitType(exprParser::TypeContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "TYPE" << endl;
#endif
	string type = ctx->getText();
	if (type == "char") {
		return Type::Character;
	}
	else if (type == "int") {
		return Type::Integer;
	}
	else {
		return Type::Void;
	}
}
