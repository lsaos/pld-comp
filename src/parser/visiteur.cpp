#include "visiteur.hpp"

#include "../ast/program.hpp"
#include "../ast/assignment.hpp"
#include "../ast/binaryExpression.hpp"
#include "../ast/unaryExpression.hpp"
#include "../ast/block.hpp"
#include "../ast/constant.hpp"
#include "../ast/controlStructure.hpp"
#include "../ast/expression.hpp"
#include "../ast/functionCall.hpp"
#include "../ast/function.hpp"
#include "../ast/instruction.hpp"
#include "../ast/program.hpp"
#include "../ast/type.hpp"
#include "../ast/variable.hpp"
#include "../ast/error.hpp"
#include "../ast/return.hpp"
#include "../ast/if.hpp"
#include "../ast/while.hpp"
#include <vector>

using namespace ast;

ItemPosition Visiteur::buildPos(size_t line, size_t column) {
	ItemPosition pos;
	pos.line = line;
	pos.offset = column;
	return pos;
}

Expression* Visiteur::buildBinaryExpression(exprParser::ExpressionContext *ctx, BinaryOperator op){
    #ifdef TREEVISIT
	    jump(); cout << "BINARY "<<int(op)<<" ("<<endl;
	    indent++;
    #endif
    Expression* left = (Expression*)visit(ctx->children[0]);
    Expression* right = (Expression*)visit(ctx->children[2]);//Children 1 is the operator and children 2 is the right member.
	BinaryExpression* binExp = new BinaryExpression(left->getPosition());
	binExp->setLeftExpression(left);
	binExp->setRightExpression(right);
    binExp->setOperator(op);
	#ifdef TREEVISIT
		jump(); cout << ")"<<endl;
		indent--;
	#endif
    return (Expression*)binExp;
}

Expression* Visiteur::buildUnaryExpression(exprParser::ExpressionContext* ctx, UnaryOperator op){
    #ifdef TREEVISIT
	    jump(); cout << "UNARY "<<int(op)<<" ("<<endl;
	    indent++;
    #endif
	Expression* expr = (Expression*)visit(ctx->children[0]);

	UnaryExpression* unary = new  UnaryExpression(expr->getPosition());
	unary->setExpression(expr);
	unary->setOperator(op);
	#ifdef TREEVISIT
		jump(); cout << ")"<<endl;
		indent--;
	#endif
	return (Expression*)unary;
}

antlrcpp::Any Visiteur::visitProg(exprParser::ProgContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "PROG(" << endl;
	indent++;
#endif
	Program* prog = new Program();
	for(int i=0; i<ctx->function().size(); i++){
		Instruction* instr = (Instruction*)visit(ctx->function(i));
		prog->add(instr);
	}
#ifdef TREEVISIT
	jump(); cout << ")" << endl;
	indent--;
#endif
	return prog;
}

antlrcpp::Any Visiteur::visitFunction(exprParser::FunctionContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "FUNCTION " << ctx->VAR()->getText() <<endl;
	indent++;
#endif
	ItemPosition pos = buildPos(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
	Function* func = new Function(pos);
    Type type = (Type)visit(ctx->funcType());
    if(ctx->getRuleContexts<exprParser::ParametersContext>().size()!=0){
    	vector<Variable*>* parameters = (vector<Variable*>*)visit(ctx->parameters());
    	for(int i=0; i<parameters->size(); i++){
    		func->addParameter(parameters->at(i));
    	}
    }
    Instruction* block = (Instruction*)visit(ctx->block());
    func->add(block);   
    func->setName(ctx->VAR()->getText());
    
	func->setType(type);
#ifdef TREEVISIT
	jump(); cout << ")" << endl;
	indent--;
#endif
	return (Instruction*)func;
}

antlrcpp::Any Visiteur::visitParameters(exprParser::ParametersContext *ctx){
	#ifdef TREEVISIT
	jump(); cout << "PARAMETERS(" << endl;
	indent++;
	#endif
	vector<Variable*>* variables = new vector<Variable*>();
	for(int i=0; i<ctx->VAR().size(); i++){
		ItemPosition pos = buildPos(ctx->varType(i)->getStart()->getLine(), ctx->varType(i)->getStart()->getCharPositionInLine());//FIXME
		Type type = (Type)visit(ctx->varType(i));
		Variable* parameter = new Variable(pos);
		parameter->setName(ctx->VAR(i)->getText());
		parameter->setType(type);
		variables->push_back(parameter);	
	}
	
	#ifdef TREEVISIT
	jump(); cout << ")" << endl;
	indent--;
	#endif
	return variables;
}

antlrcpp::Any Visiteur::visitDeclaration(exprParser::DeclarationContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "DECLARATION(" << endl;
	indent++;
#endif
	Type type = (Type)visit(ctx->varType());
    vector<Instruction*>* declarations = new vector<Instruction*>;
    for(size_t i =0; i<ctx->newVar().size(); i++){
        vector<Instruction*>* sousDeclaration = (vector<Instruction*>*)visit(ctx->newVar(i));
        for(size_t j=0; j<sousDeclaration->size(); j++){
            if (sousDeclaration->at(j)->isVariable()){
                Variable* var = (Variable*)sousDeclaration->at(j);
                var->setType(type);
            }
            declarations->push_back(sousDeclaration->at(j));
        }
    }
	#ifdef TREEVISIT
		jump(); cout <<")"<<endl;
		indent--;
	#endif
	return declarations;
}

antlrcpp::Any Visiteur::visitPlainNewVariable(exprParser::PlainNewVariableContext *ctx){
    #ifdef TREEVISIT
	jump(); cout << "PLAIN" << endl;
    #endif
	ItemPosition pos = buildPos(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
    Variable* variable = new Variable(pos);
    variable->setName(ctx->VAR()->getText());
    vector<Instruction*>* declaration = new vector<Instruction*>;
    declaration->push_back((Instruction*)variable);
	return declaration;
}

antlrcpp::Any Visiteur::visitValuedNewVariable(exprParser::ValuedNewVariableContext *ctx){
#ifdef TREEVISIT
	jump(); cout << "VALUED(" << endl;
	indent++;
#endif
	ItemPosition pos = buildPos(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
    Variable* variable = new Variable(pos);
    variable->setName(ctx->VAR()->getText());
	Assignment* assignment = new Assignment(pos);
	Expression* expression = (Expression*)visit(ctx->expression());
	Identifier* identifier = new Identifier(pos);
	identifier->setIdent(variable->getName());
	assignment->setValue(expression);
	assignment->setIdentifier(identifier);

    vector<Instruction*>* declaration = new vector<Instruction*>;
    declaration->push_back((Instruction*)variable);
    declaration->push_back((Instruction*)assignment);
#ifdef TREEVISIT
	jump(); cout << ")" << endl;
	indent--;
#endif
	return declaration;
}

antlrcpp::Any Visiteur::visitRetExpr(exprParser::RetExprContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "RETURN_EXPR(" << endl;
	indent++;
#endif
	ItemPosition pos = buildPos(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
    Expression* expr=(Expression*)visit(ctx->expression());
	Return* ret = new Return(pos);
    ret->setExpression(expr);
#ifdef TREEVISIT
	jump(); cout << ")" << endl;
	indent--;
#endif
	return (Instruction*)ret;
}

antlrcpp::Any Visiteur::visitRetNoExpr(exprParser::RetNoExprContext *ctx){
    #ifdef TREEVISIT
	jump(); cout << "RETURN_NO_EXPR(" << endl;
	indent++;
#endif
	ItemPosition pos = buildPos(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
	Return* ret = new Return(pos);
#ifdef TREEVISIT
	jump(); cout << ")" << endl;
	indent--;
#endif
	return (Instruction*)ret;

}

antlrcpp::Any Visiteur::visitBlock(exprParser::BlockContext *ctx){
    #ifdef TREEVISIT
	jump(); cout << "BLOCK(" << endl;
	indent++;
    #endif
	ItemPosition pos = buildPos(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
    Block* block = new Block(pos);
    for (int i=0; i<ctx->declaration().size(); i++){
        vector<Instruction*>* declarations = (vector<Instruction*>*)visit(ctx->declaration(i));
        for(int j=0; j<declarations->size();j++){
            block->add(declarations->at(j));
        }
    }
	for (int i = 0; i < ctx->instruction().size(); i++) {
		block->add((Instruction*)visit(ctx->instruction(i)));
	}
    #ifdef TREEVISIT
	jump(); cout << ")" << endl;
	indent--;
    #endif
    return (Instruction*)block;
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

antlrcpp::Any Visiteur::visitAssignment(exprParser::AssignmentContext *ctx) {

#ifdef TREEVISIT
	jump(); cout << "ASSIGNMENT(" << endl;
	indent++;
#endif
	ItemPosition pos = buildPos(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
	Assignment* assignment = new Assignment(pos);
	Expression* expression = (Expression*)visit(ctx->expression());
	Identifier* identifier = new Identifier(pos);
	identifier->setIdent(ctx->VAR()->getText());
	assignment->setValue(expression);
	assignment->setIdentifier(identifier);
#ifdef TREEVISIT
	jump(); cout << ")" << endl;
	indent--;
#endif
	return (Instruction*)assignment;

}

antlrcpp::Any Visiteur::visitOptional(exprParser::OptionalContext *ctx){
    #ifdef TREEVISIT
	jump(); cout << "IF(" << endl;
	indent++;
    #endif
	ItemPosition pos = buildPos(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());    
    Instruction* block = (Instruction*)visit(ctx->controlBody(0));
    Expression* expr = (Expression*)visit(ctx->condition());
    If* condition = new If(pos);
    condition->setCondition(expr);
    condition->setInstruction(block);
    
    if(ctx->getRuleContexts<exprParser::ControlBodyContext>().size()==2) 
    {
    	Instruction* blockElse = (Instruction*)visit(ctx->controlBody(1));
        condition->setAlternative(blockElse);
    }  
    #ifdef TREEVISIT
    jump(); cout << ")" << endl;
    indent--;
    #endif
    return (Instruction*)condition;
}

antlrcpp::Any Visiteur::visitWhileLoop(exprParser::WhileLoopContext *ctx){
    #ifdef TREEVISIT
	jump(); cout << "WHILE(" << endl;
	indent++;
    #endif
	ItemPosition pos = buildPos(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());    
    Instruction* block = (Instruction*)visit(ctx->controlBody());
    Expression* expr = (Expression*)visit(ctx->condition());
    While* loop = new While(pos);
    loop->setCondition(expr);
    loop->setInstruction(block);
    #ifdef TREEVISIT
    jump(); cout << ")" << endl;
    indent--;
    #endif
    return (Instruction*)loop;
}

antlrcpp::Any Visiteur::visitForLoop(exprParser::ForLoopContext *ctx){
    #ifdef TREEVISIT
	jump(); cout << "FOR(" << endl;
	indent++;
    #endif
	ItemPosition pos = buildPos(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
    vector<Instruction*>* declarations = (vector<Instruction*>*)visit(ctx->forInit());
    Expression* expr = (Expression*)visit(ctx->expression());
    Instruction* assignment = (Instruction*)visit(ctx->assignment());
    Block* block = dynamic_cast<Block*>((Instruction*)visit(ctx->controlBody()));//FIXME : the ugliest way
    While* loop = new While(pos);
    loop->setCondition(expr);
    for(auto instr : *declarations){
        block->add(instr,true);
    }
    block->add(assignment);
    loop->setInstruction(block);
    #ifdef TREEVISIT
    jump(); cout << ")" << endl;
    indent--;
    #endif
    return (Instruction*)loop;
}

antlrcpp::Any Visiteur::visitForDeclaration(exprParser::ForDeclarationContext *ctx){
	vector<Instruction*>* declarations = (vector<Instruction*>*)visit(ctx->declaration());
	return declarations;
}

antlrcpp::Any Visiteur::visitForAssignment(exprParser::ForAssignmentContext *ctx){
	vector<Instruction*>* assignments = new vector<Instruction*>();
	Instruction* assignment = (Instruction*)visit(ctx->assignment());
	assignments->push_back(assignment);
	return assignments;
}

antlrcpp::Any Visiteur::visitCondition(exprParser::ConditionContext *ctx){
   return (Expression*)visit(ctx->expression());
}

antlrcpp::Any Visiteur::visitControlBody(exprParser::ControlBodyContext *ctx){
    return (Instruction*)visit(ctx->children[0]);
}


antlrcpp::Any Visiteur::visitVariable(exprParser::VariableContext *ctx){
	#ifdef TREEVISIT
		jump(); cout << "VAR"<<endl;
	#endif
	ItemPosition pos = buildPos(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
	Identifier* identifier = new Identifier(pos);
	identifier->setIdent(ctx->VAR()->getText());
	return (Expression*)identifier;
}

antlrcpp::Any Visiteur::visitChar(exprParser::CharContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "CHAR" << endl;
#endif
	ItemPosition pos = buildPos(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
	char value = (char)ctx->CHAR()->getText().at(1);
	Constant * constant = new Constant(pos);
	constant->setType(Type::Character);
	constant->setValue(value);
	return (Expression*)constant;
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

antlrcpp::Any Visiteur::visitInt(exprParser::IntContext *ctx) {
    #ifdef TREEVISIT
	    jump(); cout << "INT";
    #endif
	ItemPosition pos = buildPos(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
	int value = stoi(ctx->INT()->getText());
	Constant * constante = new Constant(pos);
	constante->setType(Type::Integer);
	constante->setValue(value);
#ifdef TREEVISIT
	cout << "()" << endl;
#endif
	return (Expression*)constante;
}

antlrcpp::Any Visiteur::visitFuncType(exprParser::FuncTypeContext *ctx){
    #ifdef TREEVISIT
	jump(); cout << "FUNCTYPE" << endl;
    #endif
	string type = ctx->getText();
	if (type == "void") {
		return Type::Void;
	}
	else if (type == "int") {
		return Type::Integer;
	}
	else {
		return Type::Void;
	}
}

antlrcpp::Any Visiteur::visitVarType(exprParser::VarTypeContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "VARTYPE" << endl;
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

antlrcpp::Any Visiteur::visitExprFunc(exprParser::ExprFuncContext *ctx){
	return (Expression*)visit(ctx->funcCall());
}

antlrcpp::Any Visiteur::visitAdd(exprParser::AddContext *ctx){
    return (Expression*)buildBinaryExpression((exprParser::ExpressionContext*)ctx, BinaryOperator::Add);
}

antlrcpp::Any Visiteur::visitMinus(exprParser::MinusContext *ctx) {
    return (Expression*)buildUnaryExpression((exprParser::ExpressionContext*)ctx, UnaryOperator::Minus);
}

antlrcpp::Any Visiteur::visitLogicalNot(exprParser::LogicalNotContext *ctx) {
    return (Expression*)buildUnaryExpression((exprParser::ExpressionContext*)ctx, UnaryOperator::LogicalNot);
}

antlrcpp::Any Visiteur::visitLowerThan(exprParser::LowerThanContext *ctx) {
    return (Expression*)buildBinaryExpression((exprParser::ExpressionContext*)ctx, BinaryOperator::LowerThan);
}

antlrcpp::Any Visiteur::visitLowerThanEquals(exprParser::LowerThanEqualsContext *ctx) {
    return (Expression*)buildBinaryExpression((exprParser::ExpressionContext*)ctx, BinaryOperator::LowerThanOrEquals);
}

antlrcpp::Any Visiteur::visitBitwiseXor(exprParser::BitwiseXorContext *ctx) {
    return (Expression*)buildBinaryExpression((exprParser::ExpressionContext*)ctx, BinaryOperator::BitwiseXor);
}

antlrcpp::Any Visiteur::visitBitwiseAnd(exprParser::BitwiseAndContext *ctx) {
    return (Expression*)buildBinaryExpression((exprParser::ExpressionContext*)ctx, BinaryOperator::BitwiseAnd);
}

antlrcpp::Any Visiteur::visitDifferent(exprParser::DifferentContext *ctx) {
    return (Expression*)buildBinaryExpression((exprParser::ExpressionContext*)ctx, BinaryOperator::DifferentThan);
}

antlrcpp::Any Visiteur::visitLogicalOr(exprParser::LogicalOrContext *ctx) {
    return (Expression*)buildBinaryExpression((exprParser::ExpressionContext*)ctx, BinaryOperator::LogicalOr);
}

antlrcpp::Any Visiteur::visitBitwiseNot(exprParser::BitwiseNotContext *ctx) {
    return (Expression*)buildUnaryExpression((exprParser::ExpressionContext*)ctx, UnaryOperator::BitwiseNot);
}

antlrcpp::Any Visiteur::visitGreaterThanEquals(exprParser::GreaterThanEqualsContext *ctx) {
    return (Expression*)buildBinaryExpression((exprParser::ExpressionContext*)ctx, BinaryOperator::GreaterThanOrEquals);
}

antlrcpp::Any Visiteur::visitGreaterThan(exprParser::GreaterThanContext *ctx) {
    return (Expression*)buildBinaryExpression((exprParser::ExpressionContext*)ctx, BinaryOperator::GreaterThan);
}

antlrcpp::Any Visiteur::visitEquals(exprParser::EqualsContext *ctx) {
    return (Expression*)buildBinaryExpression((exprParser::ExpressionContext*)ctx, BinaryOperator::Equals);
}

antlrcpp::Any Visiteur::visitLogicalAnd(exprParser::LogicalAndContext *ctx) {
    return (Expression*)buildBinaryExpression((exprParser::ExpressionContext*)ctx, BinaryOperator::Add);
}

antlrcpp::Any Visiteur::visitBitwiseOr(exprParser::BitwiseOrContext *ctx) {
    return (Expression*)buildBinaryExpression((exprParser::ExpressionContext*)ctx, BinaryOperator::BitwiseOr);
}

antlrcpp::Any Visiteur::visitMultiply(exprParser::MultiplyContext *ctx) {
    return (Expression*)buildBinaryExpression((exprParser::ExpressionContext*)ctx, BinaryOperator::Multiply);
}

antlrcpp::Any Visiteur::visitRightShift(exprParser::RightShiftContext *ctx) {
    return (Expression*)buildBinaryExpression((exprParser::ExpressionContext*)ctx, BinaryOperator::BitwiseRightShift);
}

antlrcpp::Any Visiteur::visitSubstract(exprParser::SubstractContext *ctx) {
    return (Expression*)buildBinaryExpression((exprParser::ExpressionContext*)ctx, BinaryOperator::Substract);
}

antlrcpp::Any Visiteur::visitLeftShift(exprParser::LeftShiftContext *ctx) {
    return (Expression*)buildBinaryExpression((exprParser::ExpressionContext*)ctx, BinaryOperator::BitwiseLeftShift);
}

antlrcpp::Any Visiteur::visitFuncCall(exprParser::FuncCallContext *ctx){
	#ifdef TREEVISIT
	    jump(); cout << "FUNCTION_CALL("<<endl;
	    indent++;
    #endif
	ItemPosition pos = buildPos(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
	FunctionCall* funcCall = new FunctionCall(pos);
	Identifier* identifier = new Identifier(pos);
	identifier->setIdent(ctx->VAR()->getText());
	funcCall->setIdentifier(identifier);
	if(ctx->getRuleContexts<exprParser::FuncCallArgumentsContext>().size()!=0){
		vector<Expression*>* arguments = (vector<Expression*>*)visit(ctx->funcCallArguments());
		for(int i=0; i<arguments->size(); i++){
			funcCall->addArgument(arguments->at(i));
		}
	}
	
	#ifdef TREEVISIT
		jump();cout << ")" << endl;
		indent--;
	#endif
	return (Expression*)funcCall;
}

antlrcpp::Any Visiteur::visitFuncCallArguments(exprParser::FuncCallArgumentsContext *ctx){
	vector<Expression*>* expressions = new vector<Expression*>();
	for(int i=0; i<ctx->expression().size(); i++){
		expressions->push_back((Expression*)visit(ctx->expression(i)));
	}
	return expressions;
}
