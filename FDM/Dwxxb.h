
#pragma once
class CDwxxb
{
private:
	int DWbh;
	CString DWmc;
	CString Lxr;
	CString Lxdh;
	CString Lxdz;
	CString Memo;
public:
	CDwxxb();
	virtual ~CDwxxb();
	CStringArray a_DWbh;
	CStringArray a_DWmc;
	int GetDWbh();
	void SetDWbh(int iDWbh);
	CString GetDWmc();
	void SetDWmc(CString cDWmc);
	CString GetLxr();
	void SetLxr(CString cLxr);
	CString GetLxdh();
	void SetLxdh(CString cLxdh);
	CString GetLxdz();
	void SetLxdz(CString cLxdz);
	CString GetMemo();
	void SetMemo(CString cMemo);
	void sql_insert();
	void sql_update(int iDWbh);
	void sql_delete(int iDWbh);
	void Load_dep();
	int Haveld(int iDWbh);
};

