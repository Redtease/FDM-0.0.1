#pragma once
#import "c:\Program Files\Common Files\System\ado\msado15.dll"no_namespace rename("EOF","adoEOF")rename("BOF","adoBOF")
class ADOConn
{
public:
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
public:
	ADOConn();
	virtual ~ADOConn();
	void OnlnitADOConn();
	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	BOOL ExecuteSQL(_bstr_t bstrSQL);
	void ExitConnect();
};

