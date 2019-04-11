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

/**
*Most methods in visiteur.cpp have an #ifdef TREEVISIT section.
* Their goal was essentially for checking the visitors' recursive calls
* and ensure a program is built in the desired way.
*/

/**
*This method will most of the time be called whatever the context of the visitor.
*Its purpose is to build the position (line,column) of a token while parsing
*for later inspections and error managing.
**/
ItemPosition Visiteur::buildPos(size_t line, size_t column) {
	ItemPosition pos;
	pos.line = line;
	pos.offset = column;
	return pos;
}

Expression* Visiteur::buildBinaryExpression(exprParser::ExpressionContext *ctx, BinaryOperator op) {
#ifdef TREEVISIT
	jump(); cout << "BINARY " << int(op) << " (" << endl;
	indent++;
#endif
	Expression* left = (Expression*)visit(ctx->children[0]);
	Expression* right = (Expression*)visit(ctx->children[2]);//Children 1 is the operator and children 2 is the right member.
	BinaryExpression* binExp = new BinaryExpression(left->getPosition());
	binExp->setLeftExpression(left);
	binExp->setRightExpression(right);
	binExp->setOperator(op);
#ifdef TREEVISIT
	jump(); cout << ")" << endl;
	indent--;
#endif
	return (Expression*)binExp;
}

Expression* Visiteur::buildUnaryExpression(exprParser::ExpressionContext* ctx, UnaryOperator op) {
#ifdef TREEVISIT
	jump(); cout << "UNARY " << int(op) << " (" << endl;
	indent++;
#endif
	Expression* expr = (Expression*)visit(ctx->children[0]);

	UnaryExpression* unary = new  UnaryExpression(expr->getPosition());
	unary->setExpression(expr);
	unary->setOperator(op);
#ifdef TREEVISIT
	jump(); cout << ")" << endl;
	indent--;
#endif
	return (Expression*)unary;
}

antlrcpp::Any Visiteur::visitProg(exprParser::ProgContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "PROG(" << endl;
	indent++;
#endif
    //Prog is the axiom of the program grammar.
	Program* prog = new Program();
	for (int i = 0; i < ctx->declaration().size(); i++) {
		vector<Instruction*>* declarations = (vector<Instruction*>*)visit(ctx->declaration(i));
		for (int j = 0; j < declarations->size(); j++) {
			prog->add(declarations->at(j));
		}
		delete declarations;
	}
	for (int i = 0; i < ctx->function().size(); i++) {
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
	jump(); cout << "FUNCTION " << ctx->VAR()->getText() << endl;
	indent++;
#endif
	ItemPosition pos = buildPos(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
	Function* func = new Function(pos);
	Type type = (Type)visit(ctx->funcType());
	if (ctx->getRuleContexts<exprParser::ParametersContext>().size() != 0) {
		vector<Variable*>* parameters = (vector<Variable*>*)visit(ctx->parameters());
		for (int i = 0; i < parameters->size(); i++) {
			func->addParameter(parameters->at(i));
		}
		delete parameters;
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

antlrcpp::Any Visiteur::visitParameters(exprParser::ParametersContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "PARAMETERS(" << endl;
	indent++;
#endif
	vector<Variable*>* variables = new vector<Variable*>();
	for (int i = 0; i < ctx->VAR().size(); i++) {
		ItemPosition pos = buildPos(ctx->varType(i)->getStart()->getLine(), ctx->varType(i)->getStart()->getCharPositionInLine());
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
    //Since int a,b; is considered a declaration, that's why we will have to explore
    // every "subdeclarations" or symbol declaration in the same line.
	Type type = (Type)visit(ctx->varType());
	vector<Instruction*>* declarations = new vector<Instruction*>;
	for (size_t i = 0; i < ctx->newVar().size(); i++) {
		vector<Instruction*>* subDeclaration = (vector<Instruction*>*)visit(ctx->newVar(i));
		for (size_t j = 0; j < subDeclaration->size(); j++) {
			if (subDeclaration->at(j)->isVariable()) {
				Variable* var = (Variable*)subDeclaration->at(j);
				var->setType(type);
                declarations->insert(declarations->begin(), subDeclaration->at(j));
			} else {
    			declarations->push_back(subDeclaration->at(j));
            }
		}
	}
#ifdef TREEVISIT
	jump(); cout << ")" << endl;
	indent--;
#endif
	return declarations;
}

antlrcpp::Any Visiteur::visitPlainNewVariable(exprParser::PlainNewVariableContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "PLAIN" << endl;
#endif
    //A plain new variable is a variable declared without any assignment (e.g. int a;)
    //Since plainVariable and ValuedNewVariable are both declaration context,
    //they'll need to return the same type of object.
    //That's why there's only a 1-item sized vector.
	Variable* variable = (Variable*)visit(ctx->newVarName());
	vector<Instruction*>* declaration = new vector<Instruction*>;
	declaration->push_back((Instruction*)variable);
	return declaration;
}

antlrcpp::Any Visiteur::visitValuedNewVariable(exprParser::ValuedNewVariableContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "VALUED(" << endl;
	indent++;
#endif
    //A valued new variable is a variable declared with an assignment (e.g. int a=0;)
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

antlrcpp::Any Visiteur::visitDeclareVariable(exprParser::DeclareVariableContext *ctx) {
    //int a; (declaration context)
	ItemPosition pos = buildPos(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
	Variable* variable = new Variable(pos);
	variable->setName(ctx->VAR()->getText());
	return variable;
}

antlrcpp::Any Visiteur::visitDeclareArray(exprParser::DeclareArrayContext *ctx) {
    //int a[1+3]; (array declaration context)
	ItemPosition pos = buildPos(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
	Variable* variable = new Variable(pos);
	variable->setName(ctx->VAR()->getText());
	variable->setIsArray();
	Expression* expr = (Expression*)visit(ctx->expression());
	variable->setArraySize(expr);
	return variable;
}


antlrcpp::Any Visiteur::visitRetExpr(exprParser::RetExprContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "RETURN_EXPR(" << endl;
	indent++;
#endif
	ItemPosition pos = buildPos(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
	Expression* expr = (Expression*)visit(ctx->expression());
	Return* ret = new Return(pos);
	ret->setExpression(expr);
#ifdef TREEVISIT
	jump(); cout << ")" << endl;
	indent--;
#endif
	return (Instruction*)ret;
}

antlrcpp::Any Visiteur::visitRetNoExpr(exprParser::RetNoExprContext *ctx) {
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

antlrcpp::Any Visiteur::visitBlock(exprParser::BlockContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "BLOCK(" << endl;
	indent++;
#endif
	ItemPosition pos = buildPos(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
	Block* block = new Block(pos);
	vector<Instruction*>* firstInstructions = new vector<Instruction*>();
	for (int i = 0; i < ctx->declaration().size(); i++) {
		vector<Instruction*>* declarations = (vector<Instruction*>*)visit(ctx->declaration(i));
		for (auto instr : *declarations){
            if(instr->isVariable()){
                firstInstructions->insert(firstInstructions->begin(), instr);
            } else {
                firstInstructions->push_back(instr);
            }
        }
		delete declarations;
	}
	for (int i = 0; i < firstInstructions->size(); i++) {
		block->add(firstInstructions->at(i));
	}
	delete firstInstructions;
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
	Instruction* instr;
	if (ctx->getRuleContexts<exprParser::FuncCallContext>().size() != 0) {
		instr = (Instruction*)((Expression*)visit(ctx->children[0]));
	}
	else {
		instr = (Instruction*)visit(ctx->children[0]);
	}
#ifdef TREEVISIT
	jump(); cout << "]" << endl;
#endif
	return instr;
}

antlrcpp::Any Visiteur::visitAssignment(exprParser::AssignmentContext *ctx) {
	//FIXME
#ifdef TREEVISIT
	jump(); cout << "ASSIGNMENT(" << endl;
	indent++;
#endif
	ItemPosition pos = buildPos(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
	Assignment* assignment = new Assignment(pos);
	Expression* expression = (Expression*)visit(ctx->expression());
	Identifier* identifier = (Identifier*)visit(ctx->varExpr());
	assignment->setValue(expression);
	assignment->setIdentifier(identifier);
#ifdef TREEVISIT
	jump(); cout << ")" << endl;
	indent--;
#endif
	return (Instruction*)assignment;

}

antlrcpp::Any Visiteur::visitVariableExpression(exprParser::VariableExpressionContext *ctx) {
	ItemPosition pos = buildPos(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
	Identifier* identifier = new Identifier(pos);
	identifier->setIdent(ctx->VAR()->getText());
	return identifier;
}

antlrcpp::Any Visiteur::visitArrayExpression(exprParser::ArrayExpressionContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "=>ARRAY_ACCESS" << endl;
#endif
	ItemPosition pos = buildPos(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
	Identifier* identifier = new Identifier(pos);
	identifier->setIdent(ctx->VAR()->getText());
	Expression* expr = (Expression*)visit(ctx->expression());
	identifier->setArrayIndex(expr);
	return identifier;
}

antlrcpp::Any Visiteur::visitOptional(exprParser::OptionalContext *ctx) {
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

	if (ctx->getRuleContexts<exprParser::ControlBodyContext>().size() == 2)
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

antlrcpp::Any Visiteur::visitWhileLoop(exprParser::WhileLoopContext *ctx) {
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

antlrcpp::Any Visiteur::visitForLoop(exprParser::ForLoopContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "FOR(" << endl;
	indent++;
#endif
    //Since for is equivalent to while, we will only put initialisation before the while objet,
    //build the while objet and the for expression at the end of this while's instructions.
	ItemPosition pos = buildPos(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
	Block* forBlock = new Block(pos);
	vector<Instruction*>* declarations = (vector<Instruction*>*)visit(ctx->forInit());
	Expression* expr = (Expression*)visit(ctx->expression());
	Instruction* assignment = (Instruction*)visit(ctx->assignment());
    //Since visitBlock always return an instruction, we need to get again a Block
    // object to build or While object.
	Block* block = dynamic_cast<Block*>((Instruction*)visit(ctx->controlBody()));

	//Declarations before the loop
	for (auto instr : *declarations) {
		forBlock->add(instr);
	}
	delete declarations;
	//The loop itself
	While* loop = new While(pos);
	loop->setCondition(expr);
	block->add(assignment);
	loop->setInstruction(block);
	forBlock->add(loop);
#ifdef TREEVISIT
	jump(); cout << ")" << endl;
	indent--;
#endif
	return (Instruction*)forBlock;
}

antlrcpp::Any Visiteur::visitForDeclaration(exprParser::ForDeclarationContext *ctx) {
	vector<Instruction*>* declarations = (vector<Instruction*>*)visit(ctx->declaration());
	return declarations;
}

antlrcpp::Any Visiteur::visitForAssignment(exprParser::ForAssignmentContext *ctx) {
	vector<Instruction*>* assignments = new vector<Instruction*>();
	Instruction* assignment = (Instruction*)visit(ctx->assignment());
	assignments->push_back(assignment);
	return assignments;
}

antlrcpp::Any Visiteur::visitCondition(exprParser::ConditionContext *ctx) {
	return (Expression*)visit(ctx->expression());
}

antlrcpp::Any Visiteur::visitControlBody(exprParser::ControlBodyContext *ctx) {
	return (Instruction*)visit(ctx->children[0]);
}


antlrcpp::Any Visiteur::visitVariable(exprParser::VariableContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "VAR" << endl;
#endif
	Identifier* identifier = (Identifier*)visit(ctx->varExpr());
	return (Expression*)identifier;
}

antlrcpp::Any Visiteur::visitChar(exprParser::CharContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "CHAR" << endl;
#endif
	ItemPosition pos = buildPos(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
    char value;
    //We need to inspect if the char isn't a \n, or \t.
    if ((char)ctx->CHAR()->getText().at(1)=='\\'){
        switch((char)ctx->CHAR()->getText().at(2)){
            case 't':
                value='\t';
                break;
            case 'n':
                value='\n';
                break;
            default:
                value='\n';
        }
    } else {
    	char value = (char)ctx->CHAR()->getText().at(1);
    }
	Constant * constant = new Constant(pos);
	constant->setType(Type::Character);
	constant->setValue(value);
	return (Expression*)constant;
}

antlrcpp::Any Visiteur::visitParenthesis(exprParser::ParenthesisContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "PARENTHESIS(" << endl;
	indent++;
#endif
	Expression* expr = (Expression*)visit(ctx->expression());
#ifdef TREEVISIT
	jump(); cout << ")" << endl;
	indent--;
#endif
	return expr;
}

antlrcpp::Any Visiteur::visitInt(exprParser::IntContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "INT";
#endif
	ItemPosition pos = buildPos(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
	int value;
	try {
		value = stoi(ctx->INT()->getText());
	}
	catch (const out_of_range&) {
		throw out_of_range("line " + to_string(pos.line) + ':' + to_string(pos.offset) + " integer out of bounds '" + ctx->INT()->getText() + '\'');
	}
	Constant * constante = new Constant(pos);
	constante->setType(Type::Integer);
	constante->setValue(value);
#ifdef TREEVISIT
	cout << "()" << endl;
#endif
	return (Expression*)constante;
}

antlrcpp::Any Visiteur::visitFuncType(exprParser::FuncTypeContext *ctx) {
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
	else if (type == "char") {
		return Type::Character;
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
		return Type::Integer;
	}
}

antlrcpp::Any Visiteur::visitExprFunc(exprParser::ExprFuncContext *ctx) {
	return (Expression*)visit(ctx->funcCall());
}

antlrcpp::Any Visiteur::visitAdd(exprParser::AddContext *ctx) {
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

antlrcpp::Any Visiteur::visitFuncCall(exprParser::FuncCallContext *ctx) {
#ifdef TREEVISIT
	jump(); cout << "FUNCTION_CALL(" << endl;
	indent++;
#endif
	ItemPosition pos = buildPos(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
	FunctionCall* funcCall = new FunctionCall(pos);
	Identifier* identifier = new Identifier(pos);
	identifier->setIdent(ctx->VAR()->getText());
	funcCall->setIdentifier(identifier);
	if (ctx->getRuleContexts<exprParser::FuncCallArgumentsContext>().size() != 0) {
		vector<Expression*>* arguments = (vector<Expression*>*)visit(ctx->funcCallArguments());
		for (int i = 0; i < arguments->size(); i++) {
			funcCall->addArgument(arguments->at(i));
		}
		delete arguments;
	}

#ifdef TREEVISIT
	jump(); cout << ")" << endl;
	indent--;
#endif
	return (Expression*)funcCall;
}

antlrcpp::Any Visiteur::visitFuncCallArguments(exprParser::FuncCallArgumentsContext *ctx) {
	vector<Expression*>* expressions = new vector<Expression*>();
	for (int i = 0; i < ctx->expression().size(); i++) {
		expressions->push_back((Expression*)visit(ctx->expression(i)));
	}
	return expressions;
}
