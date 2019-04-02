
// Generated from /home/louis/Documents/Projets/COMP/src/parser/expr.g4 by ANTLR 4.7.2


#include "exprVisitor.h"

#include "exprParser.h"


using namespace antlrcpp;
using namespace antlr4;

exprParser::exprParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

exprParser::~exprParser() {
  delete _interpreter;
}

std::string exprParser::getGrammarFileName() const {
  return "expr.g4";
}

const std::vector<std::string>& exprParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& exprParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

exprParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

exprParser::MainContext* exprParser::ProgContext::main() {
  return getRuleContext<exprParser::MainContext>(0);
}


size_t exprParser::ProgContext::getRuleIndex() const {
  return exprParser::RuleProg;
}


antlrcpp::Any exprParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

exprParser::ProgContext* exprParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, exprParser::RuleProg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(30);
    main();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MainContext ------------------------------------------------------------------

exprParser::MainContext::MainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

exprParser::FuncTypeContext* exprParser::MainContext::funcType() {
  return getRuleContext<exprParser::FuncTypeContext>(0);
}

std::vector<exprParser::DeclarationContext *> exprParser::MainContext::declaration() {
  return getRuleContexts<exprParser::DeclarationContext>();
}

exprParser::DeclarationContext* exprParser::MainContext::declaration(size_t i) {
  return getRuleContext<exprParser::DeclarationContext>(i);
}

std::vector<exprParser::InstructionContext *> exprParser::MainContext::instruction() {
  return getRuleContexts<exprParser::InstructionContext>();
}

exprParser::InstructionContext* exprParser::MainContext::instruction(size_t i) {
  return getRuleContext<exprParser::InstructionContext>(i);
}

exprParser::RetContext* exprParser::MainContext::ret() {
  return getRuleContext<exprParser::RetContext>(0);
}


size_t exprParser::MainContext::getRuleIndex() const {
  return exprParser::RuleMain;
}


antlrcpp::Any exprParser::MainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitMain(this);
  else
    return visitor->visitChildren(this);
}

exprParser::MainContext* exprParser::main() {
  MainContext *_localctx = _tracker.createInstance<MainContext>(_ctx, getState());
  enterRule(_localctx, 2, exprParser::RuleMain);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(32);
    funcType();
    setState(33);
    match(exprParser::T__0);
    setState(34);
    match(exprParser::T__1);
    setState(35);
    match(exprParser::T__2);
    setState(36);
    match(exprParser::T__3);
    setState(40);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::T__31

    || _la == exprParser::T__33) {
      setState(37);
      declaration();
      setState(42);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(46);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << exprParser::T__9)
      | (1ULL << exprParser::T__11)
      | (1ULL << exprParser::T__12)
      | (1ULL << exprParser::VAR))) != 0)) {
      setState(43);
      instruction();
      setState(48);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(50);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == exprParser::T__8) {
      setState(49);
      ret();
    }
    setState(52);
    match(exprParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

exprParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

exprParser::VarTypeContext* exprParser::DeclarationContext::varType() {
  return getRuleContext<exprParser::VarTypeContext>(0);
}

std::vector<exprParser::NewVarContext *> exprParser::DeclarationContext::newVar() {
  return getRuleContexts<exprParser::NewVarContext>();
}

exprParser::NewVarContext* exprParser::DeclarationContext::newVar(size_t i) {
  return getRuleContext<exprParser::NewVarContext>(i);
}


size_t exprParser::DeclarationContext::getRuleIndex() const {
  return exprParser::RuleDeclaration;
}


antlrcpp::Any exprParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

exprParser::DeclarationContext* exprParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 4, exprParser::RuleDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(54);
    varType();
    setState(55);
    newVar();
    setState(60);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::T__5) {
      setState(56);
      match(exprParser::T__5);
      setState(57);
      newVar();
      setState(62);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(63);
    match(exprParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NewVarContext ------------------------------------------------------------------

exprParser::NewVarContext::NewVarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::NewVarContext::getRuleIndex() const {
  return exprParser::RuleNewVar;
}

void exprParser::NewVarContext::copyFrom(NewVarContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ValuedNewVariableContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::ValuedNewVariableContext::VAR() {
  return getToken(exprParser::VAR, 0);
}

exprParser::ExpressionContext* exprParser::ValuedNewVariableContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

exprParser::ValuedNewVariableContext::ValuedNewVariableContext(NewVarContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::ValuedNewVariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitValuedNewVariable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PlainNewVariableContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::PlainNewVariableContext::VAR() {
  return getToken(exprParser::VAR, 0);
}

exprParser::PlainNewVariableContext::PlainNewVariableContext(NewVarContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::PlainNewVariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitPlainNewVariable(this);
  else
    return visitor->visitChildren(this);
}
exprParser::NewVarContext* exprParser::newVar() {
  NewVarContext *_localctx = _tracker.createInstance<NewVarContext>(_ctx, getState());
  enterRule(_localctx, 6, exprParser::RuleNewVar);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(69);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<NewVarContext *>(_tracker.createInstance<exprParser::PlainNewVariableContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(65);
      match(exprParser::VAR);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<NewVarContext *>(_tracker.createInstance<exprParser::ValuedNewVariableContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(66);
      match(exprParser::VAR);
      setState(67);
      match(exprParser::T__7);
      setState(68);
      expression(0);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RetContext ------------------------------------------------------------------

exprParser::RetContext::RetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::RetContext::getRuleIndex() const {
  return exprParser::RuleRet;
}

void exprParser::RetContext::copyFrom(RetContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- RetExprContext ------------------------------------------------------------------

exprParser::ExpressionContext* exprParser::RetExprContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

exprParser::RetExprContext::RetExprContext(RetContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::RetExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitRetExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RetNoExprContext ------------------------------------------------------------------

exprParser::RetNoExprContext::RetNoExprContext(RetContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::RetNoExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitRetNoExpr(this);
  else
    return visitor->visitChildren(this);
}
exprParser::RetContext* exprParser::ret() {
  RetContext *_localctx = _tracker.createInstance<RetContext>(_ctx, getState());
  enterRule(_localctx, 8, exprParser::RuleRet);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(77);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<RetContext *>(_tracker.createInstance<exprParser::RetExprContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(71);
      match(exprParser::T__8);
      setState(72);
      expression(0);
      setState(73);
      match(exprParser::T__6);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<RetContext *>(_tracker.createInstance<exprParser::RetNoExprContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(75);
      match(exprParser::T__8);
      setState(76);
      match(exprParser::T__6);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

exprParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<exprParser::DeclarationContext *> exprParser::BlockContext::declaration() {
  return getRuleContexts<exprParser::DeclarationContext>();
}

exprParser::DeclarationContext* exprParser::BlockContext::declaration(size_t i) {
  return getRuleContext<exprParser::DeclarationContext>(i);
}

std::vector<exprParser::InstructionContext *> exprParser::BlockContext::instruction() {
  return getRuleContexts<exprParser::InstructionContext>();
}

exprParser::InstructionContext* exprParser::BlockContext::instruction(size_t i) {
  return getRuleContext<exprParser::InstructionContext>(i);
}


size_t exprParser::BlockContext::getRuleIndex() const {
  return exprParser::RuleBlock;
}


antlrcpp::Any exprParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

exprParser::BlockContext* exprParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 10, exprParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79);
    match(exprParser::T__3);
    setState(83);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::T__31

    || _la == exprParser::T__33) {
      setState(80);
      declaration();
      setState(85);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(89);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << exprParser::T__9)
      | (1ULL << exprParser::T__11)
      | (1ULL << exprParser::T__12)
      | (1ULL << exprParser::VAR))) != 0)) {
      setState(86);
      instruction();
      setState(91);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(92);
    match(exprParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InstructionContext ------------------------------------------------------------------

exprParser::InstructionContext::InstructionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

exprParser::AssignmentContext* exprParser::InstructionContext::assignment() {
  return getRuleContext<exprParser::AssignmentContext>(0);
}

exprParser::OptionalContext* exprParser::InstructionContext::optional() {
  return getRuleContext<exprParser::OptionalContext>(0);
}

exprParser::LoopContext* exprParser::InstructionContext::loop() {
  return getRuleContext<exprParser::LoopContext>(0);
}


size_t exprParser::InstructionContext::getRuleIndex() const {
  return exprParser::RuleInstruction;
}


antlrcpp::Any exprParser::InstructionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitInstruction(this);
  else
    return visitor->visitChildren(this);
}

exprParser::InstructionContext* exprParser::instruction() {
  InstructionContext *_localctx = _tracker.createInstance<InstructionContext>(_ctx, getState());
  enterRule(_localctx, 12, exprParser::RuleInstruction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(99);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case exprParser::VAR: {
        enterOuterAlt(_localctx, 1);
        setState(94);
        assignment();
        setState(95);
        match(exprParser::T__6);
        break;
      }

      case exprParser::T__9: {
        enterOuterAlt(_localctx, 2);
        setState(97);
        optional();
        break;
      }

      case exprParser::T__11:
      case exprParser::T__12: {
        enterOuterAlt(_localctx, 3);
        setState(98);
        loop();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

exprParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* exprParser::AssignmentContext::VAR() {
  return getToken(exprParser::VAR, 0);
}

exprParser::ExpressionContext* exprParser::AssignmentContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}


size_t exprParser::AssignmentContext::getRuleIndex() const {
  return exprParser::RuleAssignment;
}


antlrcpp::Any exprParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

exprParser::AssignmentContext* exprParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 14, exprParser::RuleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    match(exprParser::VAR);
    setState(102);
    match(exprParser::T__7);
    setState(103);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OptionalContext ------------------------------------------------------------------

exprParser::OptionalContext::OptionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

exprParser::ConditionContext* exprParser::OptionalContext::condition() {
  return getRuleContext<exprParser::ConditionContext>(0);
}

std::vector<exprParser::ControlBodyContext *> exprParser::OptionalContext::controlBody() {
  return getRuleContexts<exprParser::ControlBodyContext>();
}

exprParser::ControlBodyContext* exprParser::OptionalContext::controlBody(size_t i) {
  return getRuleContext<exprParser::ControlBodyContext>(i);
}


size_t exprParser::OptionalContext::getRuleIndex() const {
  return exprParser::RuleOptional;
}


antlrcpp::Any exprParser::OptionalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitOptional(this);
  else
    return visitor->visitChildren(this);
}

exprParser::OptionalContext* exprParser::optional() {
  OptionalContext *_localctx = _tracker.createInstance<OptionalContext>(_ctx, getState());
  enterRule(_localctx, 16, exprParser::RuleOptional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(105);
    match(exprParser::T__9);
    setState(106);
    condition();
    setState(107);
    controlBody();
    setState(110);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      setState(108);
      match(exprParser::T__10);
      setState(109);
      controlBody();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoopContext ------------------------------------------------------------------

exprParser::LoopContext::LoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::LoopContext::getRuleIndex() const {
  return exprParser::RuleLoop;
}

void exprParser::LoopContext::copyFrom(LoopContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- WhileLoopContext ------------------------------------------------------------------

exprParser::ConditionContext* exprParser::WhileLoopContext::condition() {
  return getRuleContext<exprParser::ConditionContext>(0);
}

exprParser::ControlBodyContext* exprParser::WhileLoopContext::controlBody() {
  return getRuleContext<exprParser::ControlBodyContext>(0);
}

exprParser::WhileLoopContext::WhileLoopContext(LoopContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::WhileLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitWhileLoop(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForLoopContext ------------------------------------------------------------------

exprParser::DeclarationContext* exprParser::ForLoopContext::declaration() {
  return getRuleContext<exprParser::DeclarationContext>(0);
}

exprParser::ExpressionContext* exprParser::ForLoopContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

exprParser::AssignmentContext* exprParser::ForLoopContext::assignment() {
  return getRuleContext<exprParser::AssignmentContext>(0);
}

exprParser::ControlBodyContext* exprParser::ForLoopContext::controlBody() {
  return getRuleContext<exprParser::ControlBodyContext>(0);
}

exprParser::ForLoopContext::ForLoopContext(LoopContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::ForLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitForLoop(this);
  else
    return visitor->visitChildren(this);
}
exprParser::LoopContext* exprParser::loop() {
  LoopContext *_localctx = _tracker.createInstance<LoopContext>(_ctx, getState());
  enterRule(_localctx, 18, exprParser::RuleLoop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(125);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case exprParser::T__11: {
        _localctx = dynamic_cast<LoopContext *>(_tracker.createInstance<exprParser::WhileLoopContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(112);
        match(exprParser::T__11);
        setState(113);
        condition();
        setState(114);
        controlBody();
        break;
      }

      case exprParser::T__12: {
        _localctx = dynamic_cast<LoopContext *>(_tracker.createInstance<exprParser::ForLoopContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(116);
        match(exprParser::T__12);
        setState(117);
        match(exprParser::T__1);
        setState(118);
        declaration();
        setState(119);
        expression(0);
        setState(120);
        match(exprParser::T__6);
        setState(121);
        assignment();
        setState(122);
        match(exprParser::T__2);
        setState(123);
        controlBody();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionContext ------------------------------------------------------------------

exprParser::ConditionContext::ConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

exprParser::ExpressionContext* exprParser::ConditionContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}


size_t exprParser::ConditionContext::getRuleIndex() const {
  return exprParser::RuleCondition;
}


antlrcpp::Any exprParser::ConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitCondition(this);
  else
    return visitor->visitChildren(this);
}

exprParser::ConditionContext* exprParser::condition() {
  ConditionContext *_localctx = _tracker.createInstance<ConditionContext>(_ctx, getState());
  enterRule(_localctx, 20, exprParser::RuleCondition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    match(exprParser::T__1);
    setState(128);
    expression(0);
    setState(129);
    match(exprParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ControlBodyContext ------------------------------------------------------------------

exprParser::ControlBodyContext::ControlBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

exprParser::BlockContext* exprParser::ControlBodyContext::block() {
  return getRuleContext<exprParser::BlockContext>(0);
}

exprParser::InstructionContext* exprParser::ControlBodyContext::instruction() {
  return getRuleContext<exprParser::InstructionContext>(0);
}


size_t exprParser::ControlBodyContext::getRuleIndex() const {
  return exprParser::RuleControlBody;
}


antlrcpp::Any exprParser::ControlBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitControlBody(this);
  else
    return visitor->visitChildren(this);
}

exprParser::ControlBodyContext* exprParser::controlBody() {
  ControlBodyContext *_localctx = _tracker.createInstance<ControlBodyContext>(_ctx, getState());
  enterRule(_localctx, 22, exprParser::RuleControlBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(133);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case exprParser::T__3: {
        enterOuterAlt(_localctx, 1);
        setState(131);
        block();
        break;
      }

      case exprParser::T__9:
      case exprParser::T__11:
      case exprParser::T__12:
      case exprParser::VAR: {
        enterOuterAlt(_localctx, 2);
        setState(132);
        instruction();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

exprParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::ExpressionContext::getRuleIndex() const {
  return exprParser::RuleExpression;
}

void exprParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AddContext ------------------------------------------------------------------

std::vector<exprParser::ExpressionContext *> exprParser::AddContext::expression() {
  return getRuleContexts<exprParser::ExpressionContext>();
}

exprParser::ExpressionContext* exprParser::AddContext::expression(size_t i) {
  return getRuleContext<exprParser::ExpressionContext>(i);
}

exprParser::AddContext::AddContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::AddContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitAdd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MinusContext ------------------------------------------------------------------

exprParser::ExpressionContext* exprParser::MinusContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

exprParser::MinusContext::MinusContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::MinusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitMinus(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicalNotContext ------------------------------------------------------------------

exprParser::ExpressionContext* exprParser::LogicalNotContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

exprParser::LogicalNotContext::LogicalNotContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::LogicalNotContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitLogicalNot(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LowerThanContext ------------------------------------------------------------------

std::vector<exprParser::ExpressionContext *> exprParser::LowerThanContext::expression() {
  return getRuleContexts<exprParser::ExpressionContext>();
}

exprParser::ExpressionContext* exprParser::LowerThanContext::expression(size_t i) {
  return getRuleContext<exprParser::ExpressionContext>(i);
}

exprParser::LowerThanContext::LowerThanContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::LowerThanContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitLowerThan(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LowerThanEqualsContext ------------------------------------------------------------------

std::vector<exprParser::ExpressionContext *> exprParser::LowerThanEqualsContext::expression() {
  return getRuleContexts<exprParser::ExpressionContext>();
}

exprParser::ExpressionContext* exprParser::LowerThanEqualsContext::expression(size_t i) {
  return getRuleContext<exprParser::ExpressionContext>(i);
}

exprParser::LowerThanEqualsContext::LowerThanEqualsContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::LowerThanEqualsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitLowerThanEquals(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitwiseXorContext ------------------------------------------------------------------

std::vector<exprParser::ExpressionContext *> exprParser::BitwiseXorContext::expression() {
  return getRuleContexts<exprParser::ExpressionContext>();
}

exprParser::ExpressionContext* exprParser::BitwiseXorContext::expression(size_t i) {
  return getRuleContext<exprParser::ExpressionContext>(i);
}

exprParser::BitwiseXorContext::BitwiseXorContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::BitwiseXorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitBitwiseXor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitwiseAndContext ------------------------------------------------------------------

std::vector<exprParser::ExpressionContext *> exprParser::BitwiseAndContext::expression() {
  return getRuleContexts<exprParser::ExpressionContext>();
}

exprParser::ExpressionContext* exprParser::BitwiseAndContext::expression(size_t i) {
  return getRuleContext<exprParser::ExpressionContext>(i);
}

exprParser::BitwiseAndContext::BitwiseAndContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::BitwiseAndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitBitwiseAnd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesisContext ------------------------------------------------------------------

exprParser::ExpressionContext* exprParser::ParenthesisContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

exprParser::ParenthesisContext::ParenthesisContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::ParenthesisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitParenthesis(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::IntContext::INT() {
  return getToken(exprParser::INT, 0);
}

exprParser::IntContext::IntContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::IntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitInt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DifferentContext ------------------------------------------------------------------

std::vector<exprParser::ExpressionContext *> exprParser::DifferentContext::expression() {
  return getRuleContexts<exprParser::ExpressionContext>();
}

exprParser::ExpressionContext* exprParser::DifferentContext::expression(size_t i) {
  return getRuleContext<exprParser::ExpressionContext>(i);
}

exprParser::DifferentContext::DifferentContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::DifferentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitDifferent(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicalOrContext ------------------------------------------------------------------

std::vector<exprParser::ExpressionContext *> exprParser::LogicalOrContext::expression() {
  return getRuleContexts<exprParser::ExpressionContext>();
}

exprParser::ExpressionContext* exprParser::LogicalOrContext::expression(size_t i) {
  return getRuleContext<exprParser::ExpressionContext>(i);
}

exprParser::LogicalOrContext::LogicalOrContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::LogicalOrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitLogicalOr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitwiseNotContext ------------------------------------------------------------------

exprParser::ExpressionContext* exprParser::BitwiseNotContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

exprParser::BitwiseNotContext::BitwiseNotContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::BitwiseNotContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitBitwiseNot(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GreaterThanEqualsContext ------------------------------------------------------------------

std::vector<exprParser::ExpressionContext *> exprParser::GreaterThanEqualsContext::expression() {
  return getRuleContexts<exprParser::ExpressionContext>();
}

exprParser::ExpressionContext* exprParser::GreaterThanEqualsContext::expression(size_t i) {
  return getRuleContext<exprParser::ExpressionContext>(i);
}

exprParser::GreaterThanEqualsContext::GreaterThanEqualsContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::GreaterThanEqualsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitGreaterThanEquals(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GreaterThanContext ------------------------------------------------------------------

std::vector<exprParser::ExpressionContext *> exprParser::GreaterThanContext::expression() {
  return getRuleContexts<exprParser::ExpressionContext>();
}

exprParser::ExpressionContext* exprParser::GreaterThanContext::expression(size_t i) {
  return getRuleContext<exprParser::ExpressionContext>(i);
}

exprParser::GreaterThanContext::GreaterThanContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::GreaterThanContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitGreaterThan(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqualsContext ------------------------------------------------------------------

std::vector<exprParser::ExpressionContext *> exprParser::EqualsContext::expression() {
  return getRuleContexts<exprParser::ExpressionContext>();
}

exprParser::ExpressionContext* exprParser::EqualsContext::expression(size_t i) {
  return getRuleContext<exprParser::ExpressionContext>(i);
}

exprParser::EqualsContext::EqualsContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::EqualsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitEquals(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicalAndContext ------------------------------------------------------------------

std::vector<exprParser::ExpressionContext *> exprParser::LogicalAndContext::expression() {
  return getRuleContexts<exprParser::ExpressionContext>();
}

exprParser::ExpressionContext* exprParser::LogicalAndContext::expression(size_t i) {
  return getRuleContext<exprParser::ExpressionContext>(i);
}

exprParser::LogicalAndContext::LogicalAndContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::LogicalAndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitLogicalAnd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::VariableContext::VAR() {
  return getToken(exprParser::VAR, 0);
}

exprParser::VariableContext::VariableContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CharContext ------------------------------------------------------------------

tree::TerminalNode* exprParser::CharContext::CHAR() {
  return getToken(exprParser::CHAR, 0);
}

exprParser::CharContext::CharContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::CharContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitChar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitwiseOrContext ------------------------------------------------------------------

std::vector<exprParser::ExpressionContext *> exprParser::BitwiseOrContext::expression() {
  return getRuleContexts<exprParser::ExpressionContext>();
}

exprParser::ExpressionContext* exprParser::BitwiseOrContext::expression(size_t i) {
  return getRuleContext<exprParser::ExpressionContext>(i);
}

exprParser::BitwiseOrContext::BitwiseOrContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::BitwiseOrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitBitwiseOr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultiplyContext ------------------------------------------------------------------

std::vector<exprParser::ExpressionContext *> exprParser::MultiplyContext::expression() {
  return getRuleContexts<exprParser::ExpressionContext>();
}

exprParser::ExpressionContext* exprParser::MultiplyContext::expression(size_t i) {
  return getRuleContext<exprParser::ExpressionContext>(i);
}

exprParser::MultiplyContext::MultiplyContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::MultiplyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitMultiply(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RightShiftContext ------------------------------------------------------------------

std::vector<exprParser::ExpressionContext *> exprParser::RightShiftContext::expression() {
  return getRuleContexts<exprParser::ExpressionContext>();
}

exprParser::ExpressionContext* exprParser::RightShiftContext::expression(size_t i) {
  return getRuleContext<exprParser::ExpressionContext>(i);
}

exprParser::RightShiftContext::RightShiftContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::RightShiftContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitRightShift(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SubstractContext ------------------------------------------------------------------

std::vector<exprParser::ExpressionContext *> exprParser::SubstractContext::expression() {
  return getRuleContexts<exprParser::ExpressionContext>();
}

exprParser::ExpressionContext* exprParser::SubstractContext::expression(size_t i) {
  return getRuleContext<exprParser::ExpressionContext>(i);
}

exprParser::SubstractContext::SubstractContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::SubstractContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitSubstract(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LeftShiftContext ------------------------------------------------------------------

std::vector<exprParser::ExpressionContext *> exprParser::LeftShiftContext::expression() {
  return getRuleContexts<exprParser::ExpressionContext>();
}

exprParser::ExpressionContext* exprParser::LeftShiftContext::expression(size_t i) {
  return getRuleContext<exprParser::ExpressionContext>(i);
}

exprParser::LeftShiftContext::LeftShiftContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any exprParser::LeftShiftContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitLeftShift(this);
  else
    return visitor->visitChildren(this);
}

exprParser::ExpressionContext* exprParser::expression() {
   return expression(0);
}

exprParser::ExpressionContext* exprParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  exprParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  exprParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, exprParser::RuleExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(149);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case exprParser::VAR: {
        _localctx = _tracker.createInstance<VariableContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(136);
        match(exprParser::VAR);
        break;
      }

      case exprParser::INT: {
        _localctx = _tracker.createInstance<IntContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(137);
        match(exprParser::INT);
        break;
      }

      case exprParser::CHAR: {
        _localctx = _tracker.createInstance<CharContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(138);
        match(exprParser::CHAR);
        break;
      }

      case exprParser::T__1: {
        _localctx = _tracker.createInstance<ParenthesisContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(139);
        match(exprParser::T__1);
        setState(140);
        expression(0);
        setState(141);
        match(exprParser::T__2);
        break;
      }

      case exprParser::T__13: {
        _localctx = _tracker.createInstance<MinusContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(143);
        match(exprParser::T__13);
        setState(144);
        expression(19);
        break;
      }

      case exprParser::T__14: {
        _localctx = _tracker.createInstance<LogicalNotContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(145);
        match(exprParser::T__14);
        setState(146);
        expression(18);
        break;
      }

      case exprParser::T__15: {
        _localctx = _tracker.createInstance<BitwiseNotContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(147);
        match(exprParser::T__15);
        setState(148);
        expression(17);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(201);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(199);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultiplyContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(151);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(152);
          match(exprParser::T__16);
          setState(153);
          expression(17);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(154);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(155);
          match(exprParser::T__17);
          setState(156);
          expression(16);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<SubstractContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(157);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(158);
          match(exprParser::T__13);
          setState(159);
          expression(15);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<LeftShiftContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(160);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(161);
          match(exprParser::T__18);
          setState(162);
          expression(14);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<RightShiftContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(163);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(164);
          match(exprParser::T__19);
          setState(165);
          expression(13);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<LowerThanContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(166);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(167);
          match(exprParser::T__20);
          setState(168);
          expression(12);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<GreaterThanContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(169);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(170);
          match(exprParser::T__21);
          setState(171);
          expression(11);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<GreaterThanEqualsContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(172);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(173);
          match(exprParser::T__22);
          setState(174);
          expression(10);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<LowerThanEqualsContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(175);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(176);
          match(exprParser::T__23);
          setState(177);
          expression(9);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<EqualsContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(178);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(179);
          match(exprParser::T__24);
          setState(180);
          expression(8);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<DifferentContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(181);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(182);
          match(exprParser::T__25);
          setState(183);
          expression(7);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<BitwiseAndContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(184);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(185);
          match(exprParser::T__26);
          setState(186);
          expression(6);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<BitwiseXorContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(187);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(188);
          match(exprParser::T__27);
          setState(189);
          expression(5);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<BitwiseOrContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(190);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(191);
          match(exprParser::T__28);
          setState(192);
          expression(4);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<LogicalAndContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(193);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(194);
          match(exprParser::T__29);
          setState(195);
          expression(3);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<LogicalOrContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(196);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(197);
          match(exprParser::T__30);
          setState(198);
          expression(2);
          break;
        }

        } 
      }
      setState(203);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- FuncTypeContext ------------------------------------------------------------------

exprParser::FuncTypeContext::FuncTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::FuncTypeContext::getRuleIndex() const {
  return exprParser::RuleFuncType;
}


antlrcpp::Any exprParser::FuncTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitFuncType(this);
  else
    return visitor->visitChildren(this);
}

exprParser::FuncTypeContext* exprParser::funcType() {
  FuncTypeContext *_localctx = _tracker.createInstance<FuncTypeContext>(_ctx, getState());
  enterRule(_localctx, 26, exprParser::RuleFuncType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(204);
    _la = _input->LA(1);
    if (!(_la == exprParser::T__31

    || _la == exprParser::T__32)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarTypeContext ------------------------------------------------------------------

exprParser::VarTypeContext::VarTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::VarTypeContext::getRuleIndex() const {
  return exprParser::RuleVarType;
}


antlrcpp::Any exprParser::VarTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitVarType(this);
  else
    return visitor->visitChildren(this);
}

exprParser::VarTypeContext* exprParser::varType() {
  VarTypeContext *_localctx = _tracker.createInstance<VarTypeContext>(_ctx, getState());
  enterRule(_localctx, 28, exprParser::RuleVarType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(206);
    _la = _input->LA(1);
    if (!(_la == exprParser::T__31

    || _la == exprParser::T__33)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool exprParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 12: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool exprParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 16);
    case 1: return precpred(_ctx, 15);
    case 2: return precpred(_ctx, 14);
    case 3: return precpred(_ctx, 13);
    case 4: return precpred(_ctx, 12);
    case 5: return precpred(_ctx, 11);
    case 6: return precpred(_ctx, 10);
    case 7: return precpred(_ctx, 9);
    case 8: return precpred(_ctx, 8);
    case 9: return precpred(_ctx, 7);
    case 10: return precpred(_ctx, 6);
    case 11: return precpred(_ctx, 5);
    case 12: return precpred(_ctx, 4);
    case 13: return precpred(_ctx, 3);
    case 14: return precpred(_ctx, 2);
    case 15: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> exprParser::_decisionToDFA;
atn::PredictionContextCache exprParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN exprParser::_atn;
std::vector<uint16_t> exprParser::_serializedATN;

std::vector<std::string> exprParser::_ruleNames = {
  "prog", "main", "declaration", "newVar", "ret", "block", "instruction", 
  "assignment", "optional", "loop", "condition", "controlBody", "expression", 
  "funcType", "varType"
};

std::vector<std::string> exprParser::_literalNames = {
  "", "'main'", "'('", "')'", "'{'", "'}'", "','", "';'", "'='", "'return'", 
  "'if'", "'else'", "'while'", "'for'", "'-'", "'!'", "'~'", "'*'", "'+'", 
  "'<<'", "'>>'", "'<'", "'>'", "'>='", "'<='", "'=='", "'!='", "'&'", "'^'", 
  "'|'", "'&&'", "'||'", "'int'", "'void'", "'char'"
};

std::vector<std::string> exprParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "WS", 
  "Comment", "BlockComment", "Preproc", "INT", "CHAR", "VAR"
};

dfa::Vocabulary exprParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> exprParser::_tokenNames;

exprParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2b, 0xd3, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x29, 0xa, 0x3, 
    0xc, 0x3, 0xe, 0x3, 0x2c, 0xb, 0x3, 0x3, 0x3, 0x7, 0x3, 0x2f, 0xa, 0x3, 
    0xc, 0x3, 0xe, 0x3, 0x32, 0xb, 0x3, 0x3, 0x3, 0x5, 0x3, 0x35, 0xa, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 
    0x3d, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x40, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x48, 0xa, 0x5, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x50, 
    0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x54, 0xa, 0x7, 0xc, 0x7, 0xe, 
    0x7, 0x57, 0xb, 0x7, 0x3, 0x7, 0x7, 0x7, 0x5a, 0xa, 0x7, 0xc, 0x7, 0xe, 
    0x7, 0x5d, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x66, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 
    0xa, 0x71, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x5, 0xb, 0x80, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x88, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x98, 0xa, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 
    0xe, 0xca, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0xcd, 0xb, 0xe, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x2, 0x3, 0x1a, 0x11, 0x2, 0x4, 
    0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x2, 0x4, 0x3, 0x2, 0x22, 0x23, 0x4, 0x2, 0x22, 0x22, 0x24, 0x24, 0x2, 
    0xe6, 0x2, 0x20, 0x3, 0x2, 0x2, 0x2, 0x4, 0x22, 0x3, 0x2, 0x2, 0x2, 
    0x6, 0x38, 0x3, 0x2, 0x2, 0x2, 0x8, 0x47, 0x3, 0x2, 0x2, 0x2, 0xa, 0x4f, 
    0x3, 0x2, 0x2, 0x2, 0xc, 0x51, 0x3, 0x2, 0x2, 0x2, 0xe, 0x65, 0x3, 0x2, 
    0x2, 0x2, 0x10, 0x67, 0x3, 0x2, 0x2, 0x2, 0x12, 0x6b, 0x3, 0x2, 0x2, 
    0x2, 0x14, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x16, 0x81, 0x3, 0x2, 0x2, 0x2, 
    0x18, 0x87, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x97, 0x3, 0x2, 0x2, 0x2, 0x1c, 
    0xce, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xd0, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 
    0x5, 0x4, 0x3, 0x2, 0x21, 0x3, 0x3, 0x2, 0x2, 0x2, 0x22, 0x23, 0x5, 
    0x1c, 0xf, 0x2, 0x23, 0x24, 0x7, 0x3, 0x2, 0x2, 0x24, 0x25, 0x7, 0x4, 
    0x2, 0x2, 0x25, 0x26, 0x7, 0x5, 0x2, 0x2, 0x26, 0x2a, 0x7, 0x6, 0x2, 
    0x2, 0x27, 0x29, 0x5, 0x6, 0x4, 0x2, 0x28, 0x27, 0x3, 0x2, 0x2, 0x2, 
    0x29, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0x2b, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x30, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2a, 
    0x3, 0x2, 0x2, 0x2, 0x2d, 0x2f, 0x5, 0xe, 0x8, 0x2, 0x2e, 0x2d, 0x3, 
    0x2, 0x2, 0x2, 0x2f, 0x32, 0x3, 0x2, 0x2, 0x2, 0x30, 0x2e, 0x3, 0x2, 
    0x2, 0x2, 0x30, 0x31, 0x3, 0x2, 0x2, 0x2, 0x31, 0x34, 0x3, 0x2, 0x2, 
    0x2, 0x32, 0x30, 0x3, 0x2, 0x2, 0x2, 0x33, 0x35, 0x5, 0xa, 0x6, 0x2, 
    0x34, 0x33, 0x3, 0x2, 0x2, 0x2, 0x34, 0x35, 0x3, 0x2, 0x2, 0x2, 0x35, 
    0x36, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x7, 0x7, 0x2, 0x2, 0x37, 0x5, 
    0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x5, 0x1e, 0x10, 0x2, 0x39, 0x3e, 0x5, 
    0x8, 0x5, 0x2, 0x3a, 0x3b, 0x7, 0x8, 0x2, 0x2, 0x3b, 0x3d, 0x5, 0x8, 
    0x5, 0x2, 0x3c, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x40, 0x3, 0x2, 0x2, 
    0x2, 0x3e, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3f, 0x3, 0x2, 0x2, 0x2, 
    0x3f, 0x41, 0x3, 0x2, 0x2, 0x2, 0x40, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x41, 
    0x42, 0x7, 0x9, 0x2, 0x2, 0x42, 0x7, 0x3, 0x2, 0x2, 0x2, 0x43, 0x48, 
    0x7, 0x2b, 0x2, 0x2, 0x44, 0x45, 0x7, 0x2b, 0x2, 0x2, 0x45, 0x46, 0x7, 
    0xa, 0x2, 0x2, 0x46, 0x48, 0x5, 0x1a, 0xe, 0x2, 0x47, 0x43, 0x3, 0x2, 
    0x2, 0x2, 0x47, 0x44, 0x3, 0x2, 0x2, 0x2, 0x48, 0x9, 0x3, 0x2, 0x2, 
    0x2, 0x49, 0x4a, 0x7, 0xb, 0x2, 0x2, 0x4a, 0x4b, 0x5, 0x1a, 0xe, 0x2, 
    0x4b, 0x4c, 0x7, 0x9, 0x2, 0x2, 0x4c, 0x50, 0x3, 0x2, 0x2, 0x2, 0x4d, 
    0x4e, 0x7, 0xb, 0x2, 0x2, 0x4e, 0x50, 0x7, 0x9, 0x2, 0x2, 0x4f, 0x49, 
    0x3, 0x2, 0x2, 0x2, 0x4f, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x50, 0xb, 0x3, 
    0x2, 0x2, 0x2, 0x51, 0x55, 0x7, 0x6, 0x2, 0x2, 0x52, 0x54, 0x5, 0x6, 
    0x4, 0x2, 0x53, 0x52, 0x3, 0x2, 0x2, 0x2, 0x54, 0x57, 0x3, 0x2, 0x2, 
    0x2, 0x55, 0x53, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x3, 0x2, 0x2, 0x2, 
    0x56, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x57, 0x55, 0x3, 0x2, 0x2, 0x2, 0x58, 
    0x5a, 0x5, 0xe, 0x8, 0x2, 0x59, 0x58, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5d, 
    0x3, 0x2, 0x2, 0x2, 0x5b, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x3, 
    0x2, 0x2, 0x2, 0x5c, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5b, 0x3, 0x2, 
    0x2, 0x2, 0x5e, 0x5f, 0x7, 0x7, 0x2, 0x2, 0x5f, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0x60, 0x61, 0x5, 0x10, 0x9, 0x2, 0x61, 0x62, 0x7, 0x9, 0x2, 0x2, 
    0x62, 0x66, 0x3, 0x2, 0x2, 0x2, 0x63, 0x66, 0x5, 0x12, 0xa, 0x2, 0x64, 
    0x66, 0x5, 0x14, 0xb, 0x2, 0x65, 0x60, 0x3, 0x2, 0x2, 0x2, 0x65, 0x63, 
    0x3, 0x2, 0x2, 0x2, 0x65, 0x64, 0x3, 0x2, 0x2, 0x2, 0x66, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0x67, 0x68, 0x7, 0x2b, 0x2, 0x2, 0x68, 0x69, 0x7, 0xa, 
    0x2, 0x2, 0x69, 0x6a, 0x5, 0x1a, 0xe, 0x2, 0x6a, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0x6b, 0x6c, 0x7, 0xc, 0x2, 0x2, 0x6c, 0x6d, 0x5, 0x16, 0xc, 0x2, 
    0x6d, 0x70, 0x5, 0x18, 0xd, 0x2, 0x6e, 0x6f, 0x7, 0xd, 0x2, 0x2, 0x6f, 
    0x71, 0x5, 0x18, 0xd, 0x2, 0x70, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 
    0x3, 0x2, 0x2, 0x2, 0x71, 0x13, 0x3, 0x2, 0x2, 0x2, 0x72, 0x73, 0x7, 
    0xe, 0x2, 0x2, 0x73, 0x74, 0x5, 0x16, 0xc, 0x2, 0x74, 0x75, 0x5, 0x18, 
    0xd, 0x2, 0x75, 0x80, 0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x7, 0xf, 0x2, 
    0x2, 0x77, 0x78, 0x7, 0x4, 0x2, 0x2, 0x78, 0x79, 0x5, 0x6, 0x4, 0x2, 
    0x79, 0x7a, 0x5, 0x1a, 0xe, 0x2, 0x7a, 0x7b, 0x7, 0x9, 0x2, 0x2, 0x7b, 
    0x7c, 0x5, 0x10, 0x9, 0x2, 0x7c, 0x7d, 0x7, 0x5, 0x2, 0x2, 0x7d, 0x7e, 
    0x5, 0x18, 0xd, 0x2, 0x7e, 0x80, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x72, 0x3, 
    0x2, 0x2, 0x2, 0x7f, 0x76, 0x3, 0x2, 0x2, 0x2, 0x80, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0x81, 0x82, 0x7, 0x4, 0x2, 0x2, 0x82, 0x83, 0x5, 0x1a, 0xe, 
    0x2, 0x83, 0x84, 0x7, 0x5, 0x2, 0x2, 0x84, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x85, 0x88, 0x5, 0xc, 0x7, 0x2, 0x86, 0x88, 0x5, 0xe, 0x8, 0x2, 0x87, 
    0x85, 0x3, 0x2, 0x2, 0x2, 0x87, 0x86, 0x3, 0x2, 0x2, 0x2, 0x88, 0x19, 
    0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x8, 0xe, 0x1, 0x2, 0x8a, 0x98, 0x7, 
    0x2b, 0x2, 0x2, 0x8b, 0x98, 0x7, 0x29, 0x2, 0x2, 0x8c, 0x98, 0x7, 0x2a, 
    0x2, 0x2, 0x8d, 0x8e, 0x7, 0x4, 0x2, 0x2, 0x8e, 0x8f, 0x5, 0x1a, 0xe, 
    0x2, 0x8f, 0x90, 0x7, 0x5, 0x2, 0x2, 0x90, 0x98, 0x3, 0x2, 0x2, 0x2, 
    0x91, 0x92, 0x7, 0x10, 0x2, 0x2, 0x92, 0x98, 0x5, 0x1a, 0xe, 0x15, 0x93, 
    0x94, 0x7, 0x11, 0x2, 0x2, 0x94, 0x98, 0x5, 0x1a, 0xe, 0x14, 0x95, 0x96, 
    0x7, 0x12, 0x2, 0x2, 0x96, 0x98, 0x5, 0x1a, 0xe, 0x13, 0x97, 0x89, 0x3, 
    0x2, 0x2, 0x2, 0x97, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x97, 0x8c, 0x3, 0x2, 
    0x2, 0x2, 0x97, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x97, 0x91, 0x3, 0x2, 0x2, 
    0x2, 0x97, 0x93, 0x3, 0x2, 0x2, 0x2, 0x97, 0x95, 0x3, 0x2, 0x2, 0x2, 
    0x98, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0xc, 0x12, 0x2, 0x2, 0x9a, 
    0x9b, 0x7, 0x13, 0x2, 0x2, 0x9b, 0xca, 0x5, 0x1a, 0xe, 0x13, 0x9c, 0x9d, 
    0xc, 0x11, 0x2, 0x2, 0x9d, 0x9e, 0x7, 0x14, 0x2, 0x2, 0x9e, 0xca, 0x5, 
    0x1a, 0xe, 0x12, 0x9f, 0xa0, 0xc, 0x10, 0x2, 0x2, 0xa0, 0xa1, 0x7, 0x10, 
    0x2, 0x2, 0xa1, 0xca, 0x5, 0x1a, 0xe, 0x11, 0xa2, 0xa3, 0xc, 0xf, 0x2, 
    0x2, 0xa3, 0xa4, 0x7, 0x15, 0x2, 0x2, 0xa4, 0xca, 0x5, 0x1a, 0xe, 0x10, 
    0xa5, 0xa6, 0xc, 0xe, 0x2, 0x2, 0xa6, 0xa7, 0x7, 0x16, 0x2, 0x2, 0xa7, 
    0xca, 0x5, 0x1a, 0xe, 0xf, 0xa8, 0xa9, 0xc, 0xd, 0x2, 0x2, 0xa9, 0xaa, 
    0x7, 0x17, 0x2, 0x2, 0xaa, 0xca, 0x5, 0x1a, 0xe, 0xe, 0xab, 0xac, 0xc, 
    0xc, 0x2, 0x2, 0xac, 0xad, 0x7, 0x18, 0x2, 0x2, 0xad, 0xca, 0x5, 0x1a, 
    0xe, 0xd, 0xae, 0xaf, 0xc, 0xb, 0x2, 0x2, 0xaf, 0xb0, 0x7, 0x19, 0x2, 
    0x2, 0xb0, 0xca, 0x5, 0x1a, 0xe, 0xc, 0xb1, 0xb2, 0xc, 0xa, 0x2, 0x2, 
    0xb2, 0xb3, 0x7, 0x1a, 0x2, 0x2, 0xb3, 0xca, 0x5, 0x1a, 0xe, 0xb, 0xb4, 
    0xb5, 0xc, 0x9, 0x2, 0x2, 0xb5, 0xb6, 0x7, 0x1b, 0x2, 0x2, 0xb6, 0xca, 
    0x5, 0x1a, 0xe, 0xa, 0xb7, 0xb8, 0xc, 0x8, 0x2, 0x2, 0xb8, 0xb9, 0x7, 
    0x1c, 0x2, 0x2, 0xb9, 0xca, 0x5, 0x1a, 0xe, 0x9, 0xba, 0xbb, 0xc, 0x7, 
    0x2, 0x2, 0xbb, 0xbc, 0x7, 0x1d, 0x2, 0x2, 0xbc, 0xca, 0x5, 0x1a, 0xe, 
    0x8, 0xbd, 0xbe, 0xc, 0x6, 0x2, 0x2, 0xbe, 0xbf, 0x7, 0x1e, 0x2, 0x2, 
    0xbf, 0xca, 0x5, 0x1a, 0xe, 0x7, 0xc0, 0xc1, 0xc, 0x5, 0x2, 0x2, 0xc1, 
    0xc2, 0x7, 0x1f, 0x2, 0x2, 0xc2, 0xca, 0x5, 0x1a, 0xe, 0x6, 0xc3, 0xc4, 
    0xc, 0x4, 0x2, 0x2, 0xc4, 0xc5, 0x7, 0x20, 0x2, 0x2, 0xc5, 0xca, 0x5, 
    0x1a, 0xe, 0x5, 0xc6, 0xc7, 0xc, 0x3, 0x2, 0x2, 0xc7, 0xc8, 0x7, 0x21, 
    0x2, 0x2, 0xc8, 0xca, 0x5, 0x1a, 0xe, 0x4, 0xc9, 0x99, 0x3, 0x2, 0x2, 
    0x2, 0xc9, 0x9c, 0x3, 0x2, 0x2, 0x2, 0xc9, 0x9f, 0x3, 0x2, 0x2, 0x2, 
    0xc9, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xc9, 
    0xa8, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xab, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xae, 
    0x3, 0x2, 0x2, 0x2, 0xc9, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xb4, 0x3, 
    0x2, 0x2, 0x2, 0xc9, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xba, 0x3, 0x2, 
    0x2, 0x2, 0xc9, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xc0, 0x3, 0x2, 0x2, 
    0x2, 0xc9, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xc6, 0x3, 0x2, 0x2, 0x2, 
    0xca, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcb, 
    0xcc, 0x3, 0x2, 0x2, 0x2, 0xcc, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xcb, 
    0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 0x9, 0x2, 0x2, 0x2, 0xcf, 0x1d, 0x3, 
    0x2, 0x2, 0x2, 0xd0, 0xd1, 0x9, 0x3, 0x2, 0x2, 0xd1, 0x1f, 0x3, 0x2, 
    0x2, 0x2, 0x11, 0x2a, 0x30, 0x34, 0x3e, 0x47, 0x4f, 0x55, 0x5b, 0x65, 
    0x70, 0x7f, 0x87, 0x97, 0xc9, 0xcb, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

exprParser::Initializer exprParser::_init;
