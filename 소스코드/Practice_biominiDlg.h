
// Practice_biominiDlg.h : header file
//

#pragma once


#include "UFScanner.h"
#include "UFMatcher.h"
#include "afxwin.h"

#define MAX_TEMPLATE_SIZE		1024
#define MAX_TEMPLATE_NUM		9000
#define MAX_IMAGE_WIDTH			1024
#define MAX_IMAGE_HEIGHT		768
// CPractice_biominiDlg dialog
class CPractice_biominiDlg : public CDialogEx
{
// Construction
public:
	CPractice_biominiDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRACTICE_BIOMINI_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedInitbutton();
	afx_msg void OnBnClickedGetscannerhandle();
	afx_msg void OnBnClickedCapturesingleimage();
	afx_msg void OnEnChangeEdit1(char* szData);
	CString str;
	CEdit mEdit_qq;
	
	unsigned char* m_Template[MAX_TEMPLATE_NUM];
	unsigned char* m_TemplateCompare[MAX_TEMPLATE_NUM];
	unsigned char* m_TemplateOpened[MAX_TEMPLATE_NUM];
	unsigned char* m_TempTest[MAX_TEMPLATE_NUM];
	unsigned char* m_extractArr1[MAX_TEMPLATE_NUM];
	unsigned char* m_TestTemplate;
	CString m_selectArr1[5000] = { 0, };
	CString m_selectArr2[5000] = { 0, };
	int nEnrollQuality;
	int m_nResoltuion;
	CString m_fileNameArr1;
	CString m_fileNameArr2;

	CString m_yearArr1[5000];
	CString m_userArr1[5000];
	CString m_fingerArr1[5000];
	CString m_conditionArr1[5000];
	CString m_numArr1[5000];
	CString m_deviceArr1[5000];


	CString m_yearArr2[5000];
	CString m_userArr2[5000];
	CString m_fingerArr2[5000];
	CString m_conditionArr2[5000];
	CString m_numArr2[5000];
	CString m_deviceArr2[5000];

	int m_TempCompareSize[MAX_TEMPLATE_NUM];
	int m_TemplateSize[MAX_TEMPLATE_NUM];
	int m_TempOpenedSize[MAX_TEMPLATE_NUM];
	int m_TempTestSize[MAX_TEMPLATE_NUM];
	int m_selectArr1Size[MAX_TEMPLATE_NUM];
	int m_selectArr2Size[MAX_TEMPLATE_NUM];
	int m_extractArr1Size[MAX_TEMPLATE_NUM];
	int m_Template_num;
	int m_TempCompare_num;
	int m_TempOpened_num;
	int m_TempTest_num;
	int m_selectArr1_num;
	int m_selectArr2_num;
	
	int i;
	HUFMatcher m_hMatcher = NULL;
	bool m_fileOn;
	unsigned char* m_pImage_1;
	unsigned char* m_pImage_2;
	int m_nWidth_1;
	int m_nHeight_1;
	int m_nWidth_2;
	int m_nHeight_2;
	CString m_SelectedFolder;
	UFS_STATUS ufs_res;
	HUFScanner hScanner= NULL; //스캐너에 대한 핸들
	CStatic mImage_control;
	CString m_szFilename_1;
	CString m_selectList;

	int m_file_num1 = 0;
	int m_file_num2 = 0;
	

	afx_msg void OnBnClickedExtract();
	afx_msg void OnBnClickedVerify();
	afx_msg void OnBnClickedSavetemplate();
	afx_msg void OnBnClickedOpentemplate();
	
	afx_msg void OnBnClickedMatchfile();
	afx_msg void OnBnClickedOpenfile2();
	
	afx_msg void OnBnClickedimageload();
	afx_msg void OnBnClickedselectfile1();
	afx_msg void OnBnClickedselectfile2();
	afx_msg void OnBnClickedselection();
	afx_msg void OnBnClickedButton2();
};
