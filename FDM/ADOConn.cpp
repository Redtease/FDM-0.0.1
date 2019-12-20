#include "stdafx.h"
#include "ADOConn.h"


ADOConn::ADOConn()
{

}


ADOConn::~ADOConn()
{
}

void ADOConn::OnlnitADOConn()
{
	::CoInitialize(NULL);
	try{
		m_pConnection.CreateInstance(_uuidof(Connection));
		TCHAR szFilename[MAX_PATH] = { 0 };
		GetModuleFileName(NULL, szFilename, _countof(szFilename));
		PathRemoveFileSpec(szFilename);
		const PCTSTR szAppName = _T("数据配置");
		CString strFilename = szFilename;
		strFilename += _T("\\Database.ini");
		CString strlnitialCatalog, strDataSource, strUserID, strPassword;
		GetPrivateProfileString(szAppName, _T("lnitialCatalog"), _T("WenDGL"), strlnitialCatalog.GetBuffer(1024), 1024, strFilename);
		GetPrivateProfileString(szAppName, _T("DataSource"), _T("192.168.1.97"), strDataSource.GetBuffer(1024), 1024, strFilename);
		GetPrivateProfileString(szAppName, _T("UserID"), _T("sa"), strUserID.GetBuffer(1024), 1024, strFilename);
		strlnitialCatalog.ReleaseBuffer();
		strDataSource.ReleaseBuffer();
		strUserID.ReleaseBuffer();
		strPassword.ReleaseBuffer();
		CString str;
		str.Format(_T("Provider=SQLOLEDB.1;lntegrated Security=SSPI;Persist Security lnfo=Ture;lnitialCatalog=%s;Data Source=%s;UserID=%s;Password=%s;")
			, strlnitialCatalog.GetString()
			, strDataSource.GetString()
			, strUserID.GetString()
			, strPassword.GetString()
			);
		str.Format(_T("driver={SQLServer}; Server = %s; Database = %s; UID = %s; PWD = %s; ")
			, strlnitialCatalog.GetString()
			, strDataSource.GetString()
			, strUserID.GetString()
			, strPassword.GetString()
			);
		
		_bstr_t strConnect = str;
		m_pConnection->Open(strConnect, strUserID.GetString(), strPassword.GetString(), adModeUnknown);
	}

	catch (_com_error e){
		AfxMessageBox(_T("连接数据库失败！"));
		AfxMessageBox(e.Description());
	}
	catch (...){
		AfxMessageBox(_T("连接数据库失败！"));
	}

}
_RecordsetPtr& ADOConn::GetRecordSet(_bstr_t bstrSQL)
{
	try{
		if (m_pConnection == NULL)
			m_pRecordset.CreateInstance("ADODB.Recordset");
		m_pRecordset->Open(bstrSQL, m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
	}
	catch (_com_error e)
	{
		e.Description();
	}
	return m_pRecordset;
}
BOOL ADOConn :: ExecuteSQL(_bstr_t bstrSQL)
{
	_variant_t RecordsAffected;
	try{
		if (m_pConnection == NULL){
			OnlnitADOConn();
		}
		m_pConnection->Execute(bstrSQL, NULL, adCmdText);
		return true;
	}
	catch (_com_error e)
	{
		e.Description();
		return false;
	}
}
void ADOConn::ExitConnect()
{
	if (m_pRecordset != NULL){
		m_pConnection->Close();
	}
	m_pConnection->Close();
	::CoUninitialize();
}