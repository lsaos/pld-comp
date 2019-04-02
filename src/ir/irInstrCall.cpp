#pragma once

#include "irInstrCall.hpp"

#include <bits/stdc++.h>

using namespace std;
using namespace ast;
using namespace ir;

IRInstrCall::IRInstrCall(BasicBlock* bb, string dest, string label, vector <string> op) : IRInstr(bb) { 
	this.dest = dest;
	this.label = label;
	this.op (op.begin(), op.end()); //to check
}

void IRInstrCall::gen_asm(ostream &o) {} // TODO

