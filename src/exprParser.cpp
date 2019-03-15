
// Generated from src/expr.g4 by ANTLR 4.7.1


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
    setState(20);
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

exprParser::PreprocContext* exprParser::MainContext::preproc() {
  return getRuleContext<exprParser::PreprocContext>(0);
}

exprParser::ExpressionContext* exprParser::MainContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

std::vector<tree::TerminalNode *> exprParser::MainContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::MainContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}

std::vector<exprParser::InstructionContext *> exprParser::MainContext::instruction() {
  return getRuleContexts<exprParser::InstructionContext>();
}

exprParser::InstructionContext* exprParser::MainContext::instruction(size_t i) {
  return getRuleContext<exprParser::InstructionContext>(i);
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
    setState(22);
    preproc();
    setState(26);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(23);
      match(exprParser::SPACE);
      setState(28);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(29);
    match(exprParser::T__0);
    setState(31); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(30);
      match(exprParser::SPACE);
      setState(33); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == exprParser::SPACE);
    setState(35);
    match(exprParser::T__1);
    setState(39);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(36);
      match(exprParser::SPACE);
      setState(41);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(42);
    match(exprParser::T__2);
    setState(46);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(43);
      match(exprParser::SPACE);
      setState(48);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(49);
    match(exprParser::T__3);
    setState(53);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(50);
      match(exprParser::SPACE);
      setState(55);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(56);
    match(exprParser::T__4);
    setState(60);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(57);
      match(exprParser::SPACE);
      setState(62);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(72);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::T__0

    || _la == exprParser::T__12) {
      setState(63);
      instruction();
      setState(67);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == exprParser::SPACE) {
        setState(64);
        match(exprParser::SPACE);
        setState(69);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(74);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(75);
    match(exprParser::T__5);
    setState(77); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(76);
      match(exprParser::SPACE);
      setState(79); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == exprParser::SPACE);
    setState(81);
    expression(0);
    setState(85);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(82);
      match(exprParser::SPACE);
      setState(87);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(88);
    match(exprParser::T__6);
    setState(92);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(89);
      match(exprParser::SPACE);
      setState(94);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(95);
    match(exprParser::T__7);
    setState(99);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(96);
      match(exprParser::SPACE);
      setState(101);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PreprocContext ------------------------------------------------------------------

exprParser::PreprocContext::PreprocContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<exprParser::IncludeContext *> exprParser::PreprocContext::include() {
  return getRuleContexts<exprParser::IncludeContext>();
}

exprParser::IncludeContext* exprParser::PreprocContext::include(size_t i) {
  return getRuleContext<exprParser::IncludeContext>(i);
}

std::vector<tree::TerminalNode *> exprParser::PreprocContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::PreprocContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}


size_t exprParser::PreprocContext::getRuleIndex() const {
  return exprParser::RulePreproc;
}

antlrcpp::Any exprParser::PreprocContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitPreproc(this);
  else
    return visitor->visitChildren(this);
}

exprParser::PreprocContext* exprParser::preproc() {
  PreprocContext *_localctx = _tracker.createInstance<PreprocContext>(_ctx, getState());
  enterRule(_localctx, 4, exprParser::RulePreproc);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(111);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(105);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == exprParser::SPACE) {
          setState(102);
          match(exprParser::SPACE);
          setState(107);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(108);
        include(); 
      }
      setState(113);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IncludeContext ------------------------------------------------------------------

exprParser::IncludeContext::IncludeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* exprParser::IncludeContext::LIB() {
  return getToken(exprParser::LIB, 0);
}

std::vector<tree::TerminalNode *> exprParser::IncludeContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::IncludeContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}


size_t exprParser::IncludeContext::getRuleIndex() const {
  return exprParser::RuleInclude;
}

antlrcpp::Any exprParser::IncludeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitInclude(this);
  else
    return visitor->visitChildren(this);
}

exprParser::IncludeContext* exprParser::include() {
  IncludeContext *_localctx = _tracker.createInstance<IncludeContext>(_ctx, getState());
  enterRule(_localctx, 6, exprParser::RuleInclude);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(114);
    match(exprParser::T__8);
    setState(118);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(115);
      match(exprParser::SPACE);
      setState(120);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(121);
    match(exprParser::T__9);
    setState(122);
    match(exprParser::LIB);
    setState(123);
    match(exprParser::T__10);
   
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

std::vector<exprParser::InstructionContext *> exprParser::BlockContext::instruction() {
  return getRuleContexts<exprParser::InstructionContext>();
}

exprParser::InstructionContext* exprParser::BlockContext::instruction(size_t i) {
  return getRuleContext<exprParser::InstructionContext>(i);
}

std::vector<tree::TerminalNode *> exprParser::BlockContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::BlockContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
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
  enterRule(_localctx, 8, exprParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(132); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(125);
      instruction();
      setState(129);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == exprParser::SPACE) {
        setState(126);
        match(exprParser::SPACE);
        setState(131);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(134); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == exprParser::T__0

    || _la == exprParser::T__12);
   
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

exprParser::DeclarationContext* exprParser::InstructionContext::declaration() {
  return getRuleContext<exprParser::DeclarationContext>(0);
}

std::vector<tree::TerminalNode *> exprParser::InstructionContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::InstructionContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}

exprParser::DefinitionContext* exprParser::InstructionContext::definition() {
  return getRuleContext<exprParser::DefinitionContext>(0);
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
  enterRule(_localctx, 10, exprParser::RuleInstruction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(154);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(136);
      declaration();
      setState(140);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == exprParser::SPACE) {
        setState(137);
        match(exprParser::SPACE);
        setState(142);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(143);
      match(exprParser::T__6);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(145);
      definition();
      setState(149);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == exprParser::SPACE) {
        setState(146);
        match(exprParser::SPACE);
        setState(151);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(152);
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

//----------------- DeclarationContext ------------------------------------------------------------------

exprParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

exprParser::TypeContext* exprParser::DeclarationContext::type() {
  return getRuleContext<exprParser::TypeContext>(0);
}

tree::TerminalNode* exprParser::DeclarationContext::VAR() {
  return getToken(exprParser::VAR, 0);
}

std::vector<tree::TerminalNode *> exprParser::DeclarationContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::DeclarationContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
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
  enterRule(_localctx, 12, exprParser::RuleDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    type();
    setState(160);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(157);
      match(exprParser::SPACE);
      setState(162);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(163);
    match(exprParser::VAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefinitionContext ------------------------------------------------------------------

exprParser::DefinitionContext::DefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

exprParser::TypeContext* exprParser::DefinitionContext::type() {
  return getRuleContext<exprParser::TypeContext>(0);
}

tree::TerminalNode* exprParser::DefinitionContext::VAR() {
  return getToken(exprParser::VAR, 0);
}

exprParser::ExpressionContext* exprParser::DefinitionContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

std::vector<tree::TerminalNode *> exprParser::DefinitionContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::DefinitionContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}


size_t exprParser::DefinitionContext::getRuleIndex() const {
  return exprParser::RuleDefinition;
}

antlrcpp::Any exprParser::DefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitDefinition(this);
  else
    return visitor->visitChildren(this);
}

exprParser::DefinitionContext* exprParser::definition() {
  DefinitionContext *_localctx = _tracker.createInstance<DefinitionContext>(_ctx, getState());
  enterRule(_localctx, 14, exprParser::RuleDefinition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(165);
    type();
    setState(169);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(166);
      match(exprParser::SPACE);
      setState(171);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(172);
    match(exprParser::VAR);
    setState(176);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(173);
      match(exprParser::SPACE);
      setState(178);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(179);
    match(exprParser::T__11);
    setState(183);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == exprParser::SPACE) {
      setState(180);
      match(exprParser::SPACE);
      setState(185);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(186);
    expression(0);
   
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

tree::TerminalNode* exprParser::AddContext::OPADD() {
  return getToken(exprParser::OPADD, 0);
}

std::vector<tree::TerminalNode *> exprParser::AddContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::AddContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}

exprParser::AddContext::AddContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::AddContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitAdd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultContext ------------------------------------------------------------------

std::vector<exprParser::ExpressionContext *> exprParser::MultContext::expression() {
  return getRuleContexts<exprParser::ExpressionContext>();
}

exprParser::ExpressionContext* exprParser::MultContext::expression(size_t i) {
  return getRuleContext<exprParser::ExpressionContext>(i);
}

tree::TerminalNode* exprParser::MultContext::OPMUL() {
  return getToken(exprParser::OPMUL, 0);
}

std::vector<tree::TerminalNode *> exprParser::MultContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::MultContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
}

exprParser::MultContext::MultContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any exprParser::MultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitMult(this);
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
//----------------- ParenthesisContext ------------------------------------------------------------------

exprParser::ExpressionContext* exprParser::ParenthesisContext::expression() {
  return getRuleContext<exprParser::ExpressionContext>(0);
}

std::vector<tree::TerminalNode *> exprParser::ParenthesisContext::SPACE() {
  return getTokens(exprParser::SPACE);
}

tree::TerminalNode* exprParser::ParenthesisContext::SPACE(size_t i) {
  return getToken(exprParser::SPACE, i);
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

exprParser::ExpressionContext* exprParser::expression() {
   return expression(0);
}

exprParser::ExpressionContext* exprParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  exprParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  exprParser::ExpressionContext *previousContext = _localctx;
  size_t startState = 16;
  enterRecursionRule(_localctx, 16, exprParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(208);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case exprParser::VAR: {
        _localctx = _tracker.createInstance<VariableContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(189);
        match(exprParser::VAR);
        break;
      }

      case exprParser::INT: {
        _localctx = _tracker.createInstance<IntContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(190);
        match(exprParser::INT);
        break;
      }

      case exprParser::CHAR: {
        _localctx = _tracker.createInstance<CharContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(191);
        match(exprParser::CHAR);
        break;
      }

      case exprParser::T__2: {
        _localctx = _tracker.createInstance<ParenthesisContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(192);
        match(exprParser::T__2);
        setState(196);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == exprParser::SPACE) {
          setState(193);
          match(exprParser::SPACE);
          setState(198);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(199);
        expression(0);
        setState(203);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == exprParser::SPACE) {
          setState(200);
          match(exprParser::SPACE);
          setState(205);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(206);
        match(exprParser::T__3);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(242);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(240);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(210);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(214);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == exprParser::SPACE) {
            setState(211);
            match(exprParser::SPACE);
            setState(216);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(217);
          match(exprParser::OPMUL);
          setState(221);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == exprParser::SPACE) {
            setState(218);
            match(exprParser::SPACE);
            setState(223);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(224);
          expression(3);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(225);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(229);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == exprParser::SPACE) {
            setState(226);
            match(exprParser::SPACE);
            setState(231);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(232);
          match(exprParser::OPADD);
          setState(236);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == exprParser::SPACE) {
            setState(233);
            match(exprParser::SPACE);
            setState(238);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(239);
          expression(2);
          break;
        }

        } 
      }
      setState(244);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

exprParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t exprParser::TypeContext::getRuleIndex() const {
  return exprParser::RuleType;
}

antlrcpp::Any exprParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<exprVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

exprParser::TypeContext* exprParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 18, exprParser::RuleType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(245);
    _la = _input->LA(1);
    if (!(_la == exprParser::T__0

    || _la == exprParser::T__12)) {
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
    case 8: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool exprParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);
    case 1: return precpred(_ctx, 1);

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
  "prog", "main", "preproc", "include", "block", "instruction", "declaration", 
  "definition", "expression", "type"
};

std::vector<std::string> exprParser::_literalNames = {
  "", "'int'", "'main'", "'('", "')'", "'{'", "'return'", "';'", "'}'", 
  "'#include'", "'<'", "'>'", "'='", "'char'"
};

std::vector<std::string> exprParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "SPACE", "OPMUL", 
  "OPADD", "INT", "LIB", "CHAR", "VAR"
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
    0x3, 0x16, 0xfa, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x1b, 0xa, 0x3, 
    0xc, 0x3, 0xe, 0x3, 0x1e, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x6, 0x3, 0x22, 
    0xa, 0x3, 0xd, 0x3, 0xe, 0x3, 0x23, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x28, 
    0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x2b, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 
    0x3, 0x2f, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x32, 0xb, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x7, 0x3, 0x36, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x39, 0xb, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x7, 0x3, 0x3d, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x40, 0xb, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x44, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 
    0x47, 0xb, 0x3, 0x7, 0x3, 0x49, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x4c, 
    0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x6, 0x3, 0x50, 0xa, 0x3, 0xd, 0x3, 0xe, 
    0x3, 0x51, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x56, 0xa, 0x3, 0xc, 0x3, 0xe, 
    0x3, 0x59, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x5d, 0xa, 0x3, 0xc, 
    0x3, 0xe, 0x3, 0x60, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x64, 0xa, 
    0x3, 0xc, 0x3, 0xe, 0x3, 0x67, 0xb, 0x3, 0x3, 0x4, 0x7, 0x4, 0x6a, 0xa, 
    0x4, 0xc, 0x4, 0xe, 0x4, 0x6d, 0xb, 0x4, 0x3, 0x4, 0x7, 0x4, 0x70, 0xa, 
    0x4, 0xc, 0x4, 0xe, 0x4, 0x73, 0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 
    0x77, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x7a, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x82, 0xa, 0x6, 0xc, 
    0x6, 0xe, 0x6, 0x85, 0xb, 0x6, 0x6, 0x6, 0x87, 0xa, 0x6, 0xd, 0x6, 0xe, 
    0x6, 0x88, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x8d, 0xa, 0x7, 0xc, 0x7, 0xe, 
    0x7, 0x90, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 
    0x96, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x99, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x5, 0x7, 0x9d, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0xa1, 0xa, 0x8, 
    0xc, 0x8, 0xe, 0x8, 0xa4, 0xb, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 
    0x9, 0x7, 0x9, 0xaa, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xad, 0xb, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x7, 0x9, 0xb1, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xb4, 0xb, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0xb8, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 
    0xbb, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xc5, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 
    0xc8, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xcc, 0xa, 0xa, 0xc, 0xa, 
    0xe, 0xa, 0xcf, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xd3, 0xa, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xd7, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xda, 
    0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xde, 0xa, 0xa, 0xc, 0xa, 0xe, 
    0xa, 0xe1, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xe6, 0xa, 
    0xa, 0xc, 0xa, 0xe, 0xa, 0xe9, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 
    0xed, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xf0, 0xb, 0xa, 0x3, 0xa, 0x7, 0xa, 
    0xf3, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xf6, 0xb, 0xa, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x2, 0x3, 0x12, 0xc, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
    0x12, 0x14, 0x2, 0x3, 0x4, 0x2, 0x3, 0x3, 0xf, 0xf, 0x2, 0x112, 0x2, 
    0x16, 0x3, 0x2, 0x2, 0x2, 0x4, 0x18, 0x3, 0x2, 0x2, 0x2, 0x6, 0x71, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x74, 0x3, 0x2, 0x2, 0x2, 0xa, 0x86, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x9c, 0x3, 0x2, 0x2, 0x2, 0xe, 0x9e, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x12, 0xd2, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0xf7, 0x3, 0x2, 0x2, 0x2, 0x16, 0x17, 0x5, 0x4, 0x3, 0x2, 0x17, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0x18, 0x1c, 0x5, 0x6, 0x4, 0x2, 0x19, 0x1b, 0x7, 
    0x10, 0x2, 0x2, 0x1a, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x1e, 0x3, 0x2, 
    0x2, 0x2, 0x1c, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0x1d, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1c, 0x3, 0x2, 0x2, 0x2, 
    0x1f, 0x21, 0x7, 0x3, 0x2, 0x2, 0x20, 0x22, 0x7, 0x10, 0x2, 0x2, 0x21, 
    0x20, 0x3, 0x2, 0x2, 0x2, 0x22, 0x23, 0x3, 0x2, 0x2, 0x2, 0x23, 0x21, 
    0x3, 0x2, 0x2, 0x2, 0x23, 0x24, 0x3, 0x2, 0x2, 0x2, 0x24, 0x25, 0x3, 
    0x2, 0x2, 0x2, 0x25, 0x29, 0x7, 0x4, 0x2, 0x2, 0x26, 0x28, 0x7, 0x10, 
    0x2, 0x2, 0x27, 0x26, 0x3, 0x2, 0x2, 0x2, 0x28, 0x2b, 0x3, 0x2, 0x2, 
    0x2, 0x29, 0x27, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2a, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2c, 
    0x30, 0x7, 0x5, 0x2, 0x2, 0x2d, 0x2f, 0x7, 0x10, 0x2, 0x2, 0x2e, 0x2d, 
    0x3, 0x2, 0x2, 0x2, 0x2f, 0x32, 0x3, 0x2, 0x2, 0x2, 0x30, 0x2e, 0x3, 
    0x2, 0x2, 0x2, 0x30, 0x31, 0x3, 0x2, 0x2, 0x2, 0x31, 0x33, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x30, 0x3, 0x2, 0x2, 0x2, 0x33, 0x37, 0x7, 0x6, 0x2, 
    0x2, 0x34, 0x36, 0x7, 0x10, 0x2, 0x2, 0x35, 0x34, 0x3, 0x2, 0x2, 0x2, 
    0x36, 0x39, 0x3, 0x2, 0x2, 0x2, 0x37, 0x35, 0x3, 0x2, 0x2, 0x2, 0x37, 
    0x38, 0x3, 0x2, 0x2, 0x2, 0x38, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x39, 0x37, 
    0x3, 0x2, 0x2, 0x2, 0x3a, 0x3e, 0x7, 0x7, 0x2, 0x2, 0x3b, 0x3d, 0x7, 
    0x10, 0x2, 0x2, 0x3c, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x40, 0x3, 0x2, 
    0x2, 0x2, 0x3e, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x3f, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x40, 0x3e, 0x3, 0x2, 0x2, 0x2, 
    0x41, 0x45, 0x5, 0xc, 0x7, 0x2, 0x42, 0x44, 0x7, 0x10, 0x2, 0x2, 0x43, 
    0x42, 0x3, 0x2, 0x2, 0x2, 0x44, 0x47, 0x3, 0x2, 0x2, 0x2, 0x45, 0x43, 
    0x3, 0x2, 0x2, 0x2, 0x45, 0x46, 0x3, 0x2, 0x2, 0x2, 0x46, 0x49, 0x3, 
    0x2, 0x2, 0x2, 0x47, 0x45, 0x3, 0x2, 0x2, 0x2, 0x48, 0x41, 0x3, 0x2, 
    0x2, 0x2, 0x49, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x48, 0x3, 0x2, 0x2, 
    0x2, 0x4a, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4d, 0x3, 0x2, 0x2, 0x2, 
    0x4c, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4f, 0x7, 0x8, 0x2, 0x2, 0x4e, 
    0x50, 0x7, 0x10, 0x2, 0x2, 0x4f, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 
    0x3, 0x2, 0x2, 0x2, 0x51, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x3, 
    0x2, 0x2, 0x2, 0x52, 0x53, 0x3, 0x2, 0x2, 0x2, 0x53, 0x57, 0x5, 0x12, 
    0xa, 0x2, 0x54, 0x56, 0x7, 0x10, 0x2, 0x2, 0x55, 0x54, 0x3, 0x2, 0x2, 
    0x2, 0x56, 0x59, 0x3, 0x2, 0x2, 0x2, 0x57, 0x55, 0x3, 0x2, 0x2, 0x2, 
    0x57, 0x58, 0x3, 0x2, 0x2, 0x2, 0x58, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x59, 
    0x57, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5e, 0x7, 0x9, 0x2, 0x2, 0x5b, 0x5d, 
    0x7, 0x10, 0x2, 0x2, 0x5c, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x60, 0x3, 
    0x2, 0x2, 0x2, 0x5e, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x3, 0x2, 
    0x2, 0x2, 0x5f, 0x61, 0x3, 0x2, 0x2, 0x2, 0x60, 0x5e, 0x3, 0x2, 0x2, 
    0x2, 0x61, 0x65, 0x7, 0xa, 0x2, 0x2, 0x62, 0x64, 0x7, 0x10, 0x2, 0x2, 
    0x63, 0x62, 0x3, 0x2, 0x2, 0x2, 0x64, 0x67, 0x3, 0x2, 0x2, 0x2, 0x65, 
    0x63, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x3, 0x2, 0x2, 0x2, 0x66, 0x5, 
    0x3, 0x2, 0x2, 0x2, 0x67, 0x65, 0x3, 0x2, 0x2, 0x2, 0x68, 0x6a, 0x7, 
    0x10, 0x2, 0x2, 0x69, 0x68, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6d, 0x3, 0x2, 
    0x2, 0x2, 0x6b, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x3, 0x2, 0x2, 
    0x2, 0x6c, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6b, 0x3, 0x2, 0x2, 0x2, 
    0x6e, 0x70, 0x5, 0x8, 0x5, 0x2, 0x6f, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x70, 
    0x73, 0x3, 0x2, 0x2, 0x2, 0x71, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 
    0x3, 0x2, 0x2, 0x2, 0x72, 0x7, 0x3, 0x2, 0x2, 0x2, 0x73, 0x71, 0x3, 
    0x2, 0x2, 0x2, 0x74, 0x78, 0x7, 0xb, 0x2, 0x2, 0x75, 0x77, 0x7, 0x10, 
    0x2, 0x2, 0x76, 0x75, 0x3, 0x2, 0x2, 0x2, 0x77, 0x7a, 0x3, 0x2, 0x2, 
    0x2, 0x78, 0x76, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x3, 0x2, 0x2, 0x2, 
    0x79, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x78, 0x3, 0x2, 0x2, 0x2, 0x7b, 
    0x7c, 0x7, 0xc, 0x2, 0x2, 0x7c, 0x7d, 0x7, 0x14, 0x2, 0x2, 0x7d, 0x7e, 
    0x7, 0xd, 0x2, 0x2, 0x7e, 0x9, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x83, 0x5, 
    0xc, 0x7, 0x2, 0x80, 0x82, 0x7, 0x10, 0x2, 0x2, 0x81, 0x80, 0x3, 0x2, 
    0x2, 0x2, 0x82, 0x85, 0x3, 0x2, 0x2, 0x2, 0x83, 0x81, 0x3, 0x2, 0x2, 
    0x2, 0x83, 0x84, 0x3, 0x2, 0x2, 0x2, 0x84, 0x87, 0x3, 0x2, 0x2, 0x2, 
    0x85, 0x83, 0x3, 0x2, 0x2, 0x2, 0x86, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x87, 
    0x88, 0x3, 0x2, 0x2, 0x2, 0x88, 0x86, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 
    0x3, 0x2, 0x2, 0x2, 0x89, 0xb, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8e, 0x5, 
    0xe, 0x8, 0x2, 0x8b, 0x8d, 0x7, 0x10, 0x2, 0x2, 0x8c, 0x8b, 0x3, 0x2, 
    0x2, 0x2, 0x8d, 0x90, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8c, 0x3, 0x2, 0x2, 
    0x2, 0x8e, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x91, 0x3, 0x2, 0x2, 0x2, 
    0x90, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x7, 0x9, 0x2, 0x2, 0x92, 
    0x9d, 0x3, 0x2, 0x2, 0x2, 0x93, 0x97, 0x5, 0x10, 0x9, 0x2, 0x94, 0x96, 
    0x7, 0x10, 0x2, 0x2, 0x95, 0x94, 0x3, 0x2, 0x2, 0x2, 0x96, 0x99, 0x3, 
    0x2, 0x2, 0x2, 0x97, 0x95, 0x3, 0x2, 0x2, 0x2, 0x97, 0x98, 0x3, 0x2, 
    0x2, 0x2, 0x98, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x99, 0x97, 0x3, 0x2, 0x2, 
    0x2, 0x9a, 0x9b, 0x7, 0x9, 0x2, 0x2, 0x9b, 0x9d, 0x3, 0x2, 0x2, 0x2, 
    0x9c, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x93, 0x3, 0x2, 0x2, 0x2, 0x9d, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0x9e, 0xa2, 0x5, 0x14, 0xb, 0x2, 0x9f, 0xa1, 
    0x7, 0x10, 0x2, 0x2, 0xa0, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa4, 0x3, 
    0x2, 0x2, 0x2, 0xa2, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 0x3, 0x2, 
    0x2, 0x2, 0xa3, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa2, 0x3, 0x2, 0x2, 
    0x2, 0xa5, 0xa6, 0x7, 0x16, 0x2, 0x2, 0xa6, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0xa7, 0xab, 0x5, 0x14, 0xb, 0x2, 0xa8, 0xaa, 0x7, 0x10, 0x2, 0x2, 0xa9, 
    0xa8, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xad, 0x3, 0x2, 0x2, 0x2, 0xab, 0xa9, 
    0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x3, 0x2, 0x2, 0x2, 0xac, 0xae, 0x3, 
    0x2, 0x2, 0x2, 0xad, 0xab, 0x3, 0x2, 0x2, 0x2, 0xae, 0xb2, 0x7, 0x16, 
    0x2, 0x2, 0xaf, 0xb1, 0x7, 0x10, 0x2, 0x2, 0xb0, 0xaf, 0x3, 0x2, 0x2, 
    0x2, 0xb1, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb0, 0x3, 0x2, 0x2, 0x2, 
    0xb2, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb4, 
    0xb2, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb9, 0x7, 0xe, 0x2, 0x2, 0xb6, 0xb8, 
    0x7, 0x10, 0x2, 0x2, 0xb7, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xbb, 0x3, 
    0x2, 0x2, 0x2, 0xb9, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x3, 0x2, 
    0x2, 0x2, 0xba, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xb9, 0x3, 0x2, 0x2, 
    0x2, 0xbc, 0xbd, 0x5, 0x12, 0xa, 0x2, 0xbd, 0x11, 0x3, 0x2, 0x2, 0x2, 
    0xbe, 0xbf, 0x8, 0xa, 0x1, 0x2, 0xbf, 0xd3, 0x7, 0x16, 0x2, 0x2, 0xc0, 
    0xd3, 0x7, 0x13, 0x2, 0x2, 0xc1, 0xd3, 0x7, 0x15, 0x2, 0x2, 0xc2, 0xc6, 
    0x7, 0x5, 0x2, 0x2, 0xc3, 0xc5, 0x7, 0x10, 0x2, 0x2, 0xc4, 0xc3, 0x3, 
    0x2, 0x2, 0x2, 0xc5, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc4, 0x3, 0x2, 
    0x2, 0x2, 0xc6, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc9, 0x3, 0x2, 0x2, 
    0x2, 0xc8, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xcd, 0x5, 0x12, 0xa, 0x2, 
    0xca, 0xcc, 0x7, 0x10, 0x2, 0x2, 0xcb, 0xca, 0x3, 0x2, 0x2, 0x2, 0xcc, 
    0xcf, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 
    0x3, 0x2, 0x2, 0x2, 0xce, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xcd, 0x3, 
    0x2, 0x2, 0x2, 0xd0, 0xd1, 0x7, 0x6, 0x2, 0x2, 0xd1, 0xd3, 0x3, 0x2, 
    0x2, 0x2, 0xd2, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xc0, 0x3, 0x2, 0x2, 
    0x2, 0xd2, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xc2, 0x3, 0x2, 0x2, 0x2, 
    0xd3, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd8, 0xc, 0x4, 0x2, 0x2, 0xd5, 
    0xd7, 0x7, 0x10, 0x2, 0x2, 0xd6, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xda, 
    0x3, 0x2, 0x2, 0x2, 0xd8, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd9, 0x3, 
    0x2, 0x2, 0x2, 0xd9, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xda, 0xd8, 0x3, 0x2, 
    0x2, 0x2, 0xdb, 0xdf, 0x7, 0x11, 0x2, 0x2, 0xdc, 0xde, 0x7, 0x10, 0x2, 
    0x2, 0xdd, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xde, 0xe1, 0x3, 0x2, 0x2, 0x2, 
    0xdf, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe0, 
    0xe2, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xf3, 
    0x5, 0x12, 0xa, 0x5, 0xe3, 0xe7, 0xc, 0x3, 0x2, 0x2, 0xe4, 0xe6, 0x7, 
    0x10, 0x2, 0x2, 0xe5, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe9, 0x3, 0x2, 
    0x2, 0x2, 0xe7, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0x3, 0x2, 0x2, 
    0x2, 0xe8, 0xea, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xe7, 0x3, 0x2, 0x2, 0x2, 
    0xea, 0xee, 0x7, 0x12, 0x2, 0x2, 0xeb, 0xed, 0x7, 0x10, 0x2, 0x2, 0xec, 
    0xeb, 0x3, 0x2, 0x2, 0x2, 0xed, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xee, 0xec, 
    0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf1, 0x3, 
    0x2, 0x2, 0x2, 0xf0, 0xee, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf3, 0x5, 0x12, 
    0xa, 0x4, 0xf2, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xe3, 0x3, 0x2, 0x2, 
    0x2, 0xf3, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf2, 0x3, 0x2, 0x2, 0x2, 
    0xf4, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf5, 0x13, 0x3, 0x2, 0x2, 0x2, 0xf6, 
    0xf4, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf8, 0x9, 0x2, 0x2, 0x2, 0xf8, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x23, 0x1c, 0x23, 0x29, 0x30, 0x37, 0x3e, 0x45, 
    0x4a, 0x51, 0x57, 0x5e, 0x65, 0x6b, 0x71, 0x78, 0x83, 0x88, 0x8e, 0x97, 
    0x9c, 0xa2, 0xab, 0xb2, 0xb9, 0xc6, 0xcd, 0xd2, 0xd8, 0xdf, 0xe7, 0xee, 
    0xf2, 0xf4, 
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
