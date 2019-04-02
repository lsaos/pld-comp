#pragma once

#include "irInstrWmen.hpp"

using namespace std;
using namespace ast;
using namespace ir;

IRInstrWmen::IRInstrWmen(BasicBlock* bb, string addr, string var) : IRInstr(bb), addr(addr), var(var) { }

void IRInstrWmen::gen_asm(ostream &o) {} // TODO


