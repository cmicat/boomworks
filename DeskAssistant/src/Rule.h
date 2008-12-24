#ifndef RULE_H
#define RULE_H

#include "CategorizationFileInfo.h"

///////////////////////////////////////////////////////////////////////
WX_DEFINE_ARRAY(CategorizationFileInfo*, ArrayCategorizationFileInfo);
///////////////////////////////////////////////////////////////////////

class Rule
{
	public:
		Rule();
		virtual ~Rule();

		virtual void Execute( CategorizationFileInfo* pFileInfo ) = 0;

		///////////////////////////////////////////////////////////////

		bool m_bSelected;

		wxString m_strBaseDestPath;

	protected:
	private:
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

class BasicRule : public Rule
{
	public:
		BasicRule();
		virtual ~BasicRule();

		virtual void Execute( CategorizationFileInfo* pFileInfo );

	protected:
	private:
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

class NameIncludeRule : public Rule
{
public:
    NameIncludeRule();
    virtual ~NameIncludeRule();

    ///////////////////////////////////////////////////////////////////

	wxString m_strInclude;

	int m_nNo;
	static wxString ms_strType;

	///////////////////////////////////////////////////////////////////

    virtual void Execute( CategorizationFileInfo* pFileInfo );

protected:
private:

};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

class ExtNameRule : public Rule
{
public:
    ExtNameRule();
    virtual ~ExtNameRule();

    ///////////////////////////////////////////////////////////////////

	wxArrayString m_arrStrExtName;

	int m_nNo;
	wxString m_strType;

	///////////////////////////////////////////////////////////////////

    virtual void Execute( CategorizationFileInfo* pFileInfo );

protected:
private:

};

#endif // RULE_H