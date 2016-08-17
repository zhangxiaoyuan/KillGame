
#include "KillRules.h"

KillRule::KillRule()
{
	m_preRule = new PreKillRule();
	m_doRule  = new DoKillRule();
	m_cleanRule = new CleanKillRule();
	m_answerRule = new AnswerKillRule();
}

KillRule::~KillRule()
{
	FREE_PTR(m_preRule)
	FREE_PTR(m_doRule)
	FREE_PTR(m_cleanRule)
	FREE_PTR(m_answerRule)
}

int KillRule::Pre(KillOrder& data, int id)
{
	return m_preRule->PreAction(data, id);
}

int KillRule::Do(KillOrder& data, int id)
{
	return m_doRule->DoAction(data, id);
}

int KillRule::Clean(KillOrder& data, int id)
{
	return m_cleanRule->CleanAction(data, id);
}

int KillRule::Answer(KillOrder& data, int id)
{
	return m_answerRule->AnswerAction(data, id);
}

KillRule& KillRule::SetPreRule(PreKillRule* pre)
{
	m_preRule = pre;
	return *this;
}

KillRule& KillRule::SetDoRule(DoKillRule* doRule)
{
	m_doRule = doRule;
	return *this;
}

KillRule& KillRule::SetCleanRule(CleanKillRule* clean)
{
	m_cleanRule = clean;
	return *this;
}

KillRule& KillRule::SetAnswerRule(AnswerKillRule* answer)
{
	m_answerRule = answer;
	return *this;
}
