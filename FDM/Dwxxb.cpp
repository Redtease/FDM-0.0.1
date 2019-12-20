#include "stdafx.h"
#include "Dwxxb.h"
#include"ADOConn.h"


CDwxxb::CDwxxb()
{
}


CDwxxb::~CDwxxb()
{
}

int CDwxxb::GetDWbh(){ return DWbh; }
void CDwxxb::SetDWbh(int iDWbh){ DWbh = iDWbh; }
CString CDwxxb::GetDWmc(){ return DWmc; }
void CDwxxb::SetDWmc(CString iDWmc){ DWmc = iDWmc; }
CString CDwxxb::GetLxr(){ return Lxr; }
void CDwxxb::SetLxr(CString iLxr){ Lxr = iLxr; }
CString CDwxxb::GetLxdh(){ return Lxdh; }
void CDwxxb::SetLxdh(CString iLxdh){ Lxdh = iLxdh; }
CString CDwxxb::GetLxdz(){ return Lxdh; }
void CDwxxb::SetLxdz(CString iLxdz){ Lxdz = iLxdz; }
CString CDwxxb::GetMemo(){ return Memo; };
void CDwxxb::SetMemo(CString iMemo){ Memo = iMemo; }
void CDwxxb::sql_insert()
{
	ADOConn m_AdoConn;
	CString vSQL;
	vSQL.Format("INSERT INTO Dwxxb(DWbh,DWmc,Lxr,Lxdh,Lxdz,Memo)VALUES(%d,'''+DWmc+''', '''+Lxr+''', '''+Lxdh+''', '''+Lxdz+''', '''+ Memo+''')", DWbh);
	m_AdoConn.ExecuteSQL(_bstr_t(vSQL));
	m_AdoConn.ExitConnect();

}
void CDwxxb::sql_update(int iDWbh)
{
	ADOConn m_AdoConn;
	CString vSQL;
	//vSQL.Format("UPDATE Dwxxb SET DWmc='''+DWmc+''',Lxr='''+Lxr+''',Lxdh='''+Lxdh+''',Lxdz='''+Lxdz+''',Memo='''+Memo+'''WHERE DWbh=%d", iDWbh);
	m_AdoConn.ExecuteSQL(_bstr_t(vSQL));
	m_AdoConn.ExitConnect();
}
void CDwxxb::sql_delete(int iDWbh)
{
	ADOConn m_AdoConn;
	m_AdoConn.OnlnitADOConn();
	CString sql;
	//sql.Format("delete from Dwxxb where DWbh='%i'", iDWbh);
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
}
void CDwxxb::Load_dep()
{
	ADOConn m_AdoConn;
	m_AdoConn.OnlnitADOConn();
	_bstr_t vSQL = "SELECT*FROM Dwxxb ORDER BY DWbh";
	_RecordsetPtr  m_pRecordset = m_AdoConn.GetRecordSet(vSQL);
	a_DWbh.RemoveAll();
	a_DWmc.RemoveAll();
	while (m_pRecordset->adoEOF == 0)
	{
		a_DWbh.Add((LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("DWbh"));
		a_DWmc.Add((LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("DWbmc"));
		m_pRecordset->MoveNext();

	}
	m_AdoConn.ExitConnect();

}
int CDwxxb::Haveld(int iDWbh)
{
	ADOConn m_AdoConn;
	m_AdoConn.OnlnitADOConn();
	CString strDWbh;
	_RecordsetPtr m_pRecordset;
	//strDWbh.Format("SELECT*FROM Dwxxb WHERE DWbh=%d",iDWbh);
	return (m_pRecordset->adoEOF) ? -1: 1;
	m_AdoConn.ExitConnect();

}