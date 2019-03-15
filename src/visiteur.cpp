#include "visiteur.hpp"

#include "ast/program.hpp"

antlrcpp::Any Visiteur::visitProg(exprParser::ProgContext *ctx){
			int dummy= 3;
			*file << ".text"<<endl;
			*file << ".global main"<<endl;
			*file<< "main:"<<endl;
			*file << "   movl $"<<dummy<<", %eax"<<endl;
			*file << "   ret"<<endl;
			
			
			return dummy;
		}

antlrcpp::Any Visiteur::visitMain(exprParser::MainContext *ctx){
}

antlrcpp::Any Visiteur::visitPreproc(exprParser::PreprocContext *ctx){

}

antlrcpp::Any Visiteur::visitInclude(exprParser::IncludeContext *ctx){

}

antlrcpp::Any Visiteur::visitBlock(exprParser::BlockContext *ctx){

}

antlrcpp::Any Visiteur::visitInstruction(exprParser::InstructionContext *ctx){

}

antlrcpp::Any Visiteur::visitDeclaration(exprParser::DeclarationContext *ctx){

}

antlrcpp::Any Visiteur::visitDefinition(exprParser::DefinitionContext *ctx){

}

antlrcpp::Any Visiteur::visitAdd(exprParser::AddContext *ctx){

}

antlrcpp::Any Visiteur::visitMult(exprParser::MultContext *ctx){

}

antlrcpp::Any Visiteur::visitVariable(exprParser::VariableContext *ctx){

}

antlrcpp::Any Visiteur::visitChar(exprParser::CharContext *ctx){

}

antlrcpp::Any Visiteur::visitParenthesis(exprParser::ParenthesisContext *ctx){

}

antlrcpp::Any Visiteur::visitInt(exprParser::IntContext *ctx){

}

antlrcpp::Any Visiteur::visitType(exprParser::TypeContext *ctx){

}
