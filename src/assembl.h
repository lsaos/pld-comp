#pragma once

#include "antlr4-runtime.h"
#include "exprBaseVisitor.h"

#include <string>

using namespace std;

class Assembl : public exprBaseVisitor{
	public:
		Assembl(string name){
			file = new ofstream(name.substr(0, name.size()-1)+"s", ios::out);
		}
	
		antlrcpp::Any visitProg(exprParser::ProgContext *ctx){
			int dummy= (int)visitChildren(ctx);
			*file << ".text"<<endl;
			*file << ".global main"<<endl;
			*file<< "main:"<<endl;
			*file << "   movl $"<<dummy<<", %eax"<<endl;
			*file << "   ret"<<endl;
			
			
			return dummy;
		}
		
		antlrcpp::Any visitMain(exprParser::MainContext *ctx) {
			return stoi(ctx->INT()->getText());
		}
		
		virtual ~Assembl(){
			delete file;
		}
		
	private:
		ofstream *file;
};
