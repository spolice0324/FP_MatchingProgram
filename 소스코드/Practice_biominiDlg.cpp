// Practice_biominiDlg.cpp : implementation file
//
#pragma warning(disable:4996)
#define MAX_CFileDialog_FILE_COUNT 99
#define FILE_LIST_BUFFER_SIZE ((MAX_CFileDialog_FILE_COUNT * (MAX_PATH + 1)) + 1)
#include "stdafx.h"
#include "Practice_biomini.h"
#include "Practice_biominiDlg.h"
#include "afxdialogex.h"
#include "string.h"

#include "UFScanner.h"
#include "UFMatcher.h"
#include "UFExtractor.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

														// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// CPractice_biominiDlg dialog

CPractice_biominiDlg::CPractice_biominiDlg(CWnd* pParent /* = NULL*/ )
	: CDialogEx(IDD_PRACTICE_BIOMINI_DIALOG, pParent)

	, m_szFilename_1(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPractice_biominiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EditMessage, res_Value);

	//DDX_Control(pDX, IDC_ED, mEdit);
	DDX_Control(pDX, IDC_EDIT_qq, mEdit_qq);
	DDX_Control(pDX, IDC_PIC, mImage_control);

}

BEGIN_MESSAGE_MAP(CPractice_biominiDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_InitButton, &CPractice_biominiDlg::OnBnClickedInitbutton)
	ON_BN_CLICKED(IDC_GetScannerHandle, &CPractice_biominiDlg::OnBnClickedGetscannerhandle)
	ON_BN_CLICKED(IDC_CaptureSingleImage, &CPractice_biominiDlg::OnBnClickedCapturesingleimage)
	//ON_EN_CHANGE(IDC_EDIT1, &CPractice_biominiDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_Extract, &CPractice_biominiDlg::OnBnClickedExtract)
	ON_BN_CLICKED(IDC_Verify, &CPractice_biominiDlg::OnBnClickedVerify)
	ON_BN_CLICKED(IDC_SaveTemplate, &CPractice_biominiDlg::OnBnClickedSavetemplate)
	ON_BN_CLICKED(IDC_OpenTemplate, &CPractice_biominiDlg::OnBnClickedOpentemplate)
	ON_BN_CLICKED(IDC_MatchFile, &CPractice_biominiDlg::OnBnClickedMatchfile)
	ON_BN_CLICKED(IDC_OpenFile2, &CPractice_biominiDlg::OnBnClickedOpenfile2)
	
	ON_BN_CLICKED(imageLoad, &CPractice_biominiDlg::OnBnClickedimageload)
	ON_BN_CLICKED(IDC_selectFile1, &CPractice_biominiDlg::OnBnClickedselectfile1)
	ON_BN_CLICKED(IDC_selectFile2, &CPractice_biominiDlg::OnBnClickedselectfile2)
	ON_BN_CLICKED(IDC_selection, &CPractice_biominiDlg::OnBnClickedselection)
	ON_BN_CLICKED(IDC_BUTTON2, &CPractice_biominiDlg::OnBnClickedButton2)
END_MESSAGE_MAP()

// CPractice_biominiDlg message handlers

BOOL CPractice_biominiDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

									// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPractice_biominiDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPractice_biominiDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CRect rect;
		CDC* pDC = mImage_control.GetDC();

		mImage_control.GetClientRect(&rect);
		rect.DeflateRect(1, 1);
		UFS_DrawCaptureImageBuffer(hScanner, pDC->m_hDC, rect.left, rect.top, rect.right, rect.bottom, TRUE);

		ReleaseDC(pDC);
	}
	CDialogEx::OnPaint();
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPractice_biominiDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CPractice_biominiDlg::OnBnClickedInitbutton()
{
	UFS_STATUS ufs_res;
	UFM_STATUS ufm_res;

	BeginWaitCursor();
	ufs_res = UFS_Init();
	EndWaitCursor();
	if (ufs_res == UFS_OK) {
		OnEnChangeEdit1("기기 Init에 성공하였습니다.\r\n");
	}
	ufm_res = UFM_Create(&m_hMatcher);
}

void CPractice_biominiDlg::OnBnClickedGetscannerhandle()
{
	UFS_STATUS ufs_resHandle; //스캐너 인덱스 (0 ~ 스캐너 개수 -1)
	UFS_STATUS ufs_resHandleNum; //스캐너 오브젝트 핸들에 대한 포인터

	int i;
	int nScannerNumber;

	ufs_resHandleNum = UFS_GetScannerNumber(&nScannerNumber);
	if (ufs_resHandleNum == UFS_OK) {
		for (i = 0; i < nScannerNumber; i++) {
			ufs_resHandle = UFS_GetScannerHandle(i, &hScanner);
		}
	}
	else {
		OnEnChangeEdit1("스캐너 핸들 가져오기에 실패했습니다. 프로그램을 종료합니다.\r\n");
		return;
	}

	OnEnChangeEdit1("스캐너 핸들 가져오기에 성공했습니다.\r\n");
	Invalidate(TRUE);
}

void CPractice_biominiDlg::OnBnClickedCapturesingleimage()
{

	UFS_STATUS ufs_res;
	int nWidth, nHeight, nResolution;

	BeginWaitCursor();
	ufs_res = UFS_CaptureSingleImage(hScanner);
	EndWaitCursor();
	ufs_res = UFS_GetCaptureImageBufferInfo(hScanner, &nWidth, &nHeight, &nResolution);
	if (ufs_res == UFS_OK) {
		unsigned char

			*pbImage = (unsigned char*)malloc(nWidth * nHeight);
		ZeroMemory(pbImage, 0, nWidth* nHeight);
		free(pbImage);
	}
	else
		return;
	Invalidate(FALSE);
}

void CPractice_biominiDlg::OnEnChangeEdit1(char* szData)
{
	str += szData;
	mEdit_qq.SetWindowText(str);
	mEdit_qq.LineScroll(mEdit_qq.GetLineCount());
}

void CPractice_biominiDlg::OnBnClickedExtract()
{
	int i;
	for (i = 0; i < MAX_TEMPLATE_NUM; i++) {
		m_Template[i] = (unsigned char*)malloc(MAX_TEMPLATE_SIZE);
		memset(m_Template[i], 0, MAX_TEMPLATE_SIZE);
		m_TemplateSize[i] = 0;
	}
	m_Template_num = 0;

	UpdateData(TRUE);
	UFS_STATUS ufs_res;

	ufs_res = UFS_ExtractEx(hScanner, MAX_TEMPLATE_SIZE, m_Template[m_Template_num], &m_TemplateSize[m_Template_num], &nEnrollQuality);
	OnEnChangeEdit1("지문 추출 성공\r\n");

	//EXTRACT 과정
	
	
}

void CPractice_biominiDlg::OnBnClickedVerify()
{
	UFS_STATUS ufs_res;
	UFM_STATUS ufm_res;

	int CompareEnrollQuality;
	int bVerifySucceed;
	int i;
	for (i = 0; i < MAX_TEMPLATE_NUM; i++) {
		m_TemplateCompare[i] = (unsigned char*)malloc(MAX_TEMPLATE_SIZE);
		memset(m_TemplateCompare[i], 0, MAX_TEMPLATE_SIZE);
		m_TempCompareSize[i] = 0;
	}
	m_TempCompare_num = 0;

	ufm_res = UFM_Create(&m_hMatcher);
	ufs_res = UFS_ClearCaptureImageBuffer(hScanner);
	ufs_res = UFS_CaptureSingleImage(hScanner);
	if (ufs_res == UFS_OK) {
		ufs_res = UFS_ExtractEx(hScanner, MAX_TEMPLATE_SIZE, m_TemplateCompare[m_TempCompare_num], &m_TempCompareSize[m_TempCompare_num],
			&CompareEnrollQuality);
		ufm_res = UFM_Verify(m_hMatcher, m_TemplateCompare[m_TempCompare_num], m_TempCompareSize[m_TempCompare_num], m_Template[m_Template_num],
			m_TemplateSize[m_Template_num], &bVerifySucceed);
		m_TempCompare_num++;
		if (bVerifySucceed)
		{
			OnEnChangeEdit1("verify 성공! 해당 지문과 일치합니다.\r\n");

		}
		else
		{
			OnEnChangeEdit1("verify 실패!\r\n ");
		}
	}
	else {
		OnEnChangeEdit1("verify할 새로운 지문이 캡처되지 않았습니다.\r\n");
		return;
	}

}

void CPractice_biominiDlg::OnBnClickedSavetemplate()
{
	size_t fwrite(const void *buffer, size_t size, size_t count, FILE* stream);
	FILE* file;
	file = fopen("0215_yk_leftIndex_W.bin", "wb");
	if (file == NULL) {
		return;
	}
	fwrite(m_Template[m_Template_num], 1, m_TemplateSize[m_Template_num], file);
	fclose(file);

	OnEnChangeEdit1("Saved\r\n");
}



void CPractice_biominiDlg::OnBnClickedOpentemplate() {
	UFS_STATUS ufs_res;
	UFM_STATUS ufm_res;
	UFE_STATUS ufe_res;

	//절대경로내 파일들의 이름 , 파일 자체를 가져오기 
	CString tpath = _T("C:\\1Copy\\*.bin");
	CString tpath2 = _T("C:\\1Copy");
	CFileFind finder;
	BOOL bWorking = finder.FindFile(tpath);
	CString csTemp;

	for (i = 0; i < MAX_TEMPLATE_NUM; i++) {
		memset(m_TempTest, 0, sizeof(m_TempTest));
		m_TempTestSize[i] = 0;
	}
	
	char fileName[500];
	int file_num = 0;

	while (bWorking) {
		bWorking = finder.FindNextFile();
		if (finder.IsArchived()) {
			file_num++;
			CString _fileName = finder.GetFileName();
			csTemp = tpath2 + (_T("\\")) + _fileName;
			int length = csTemp.GetLength();
			sprintf_s(fileName, 500, "%S", csTemp);
			FILE* file;
			file = fopen(fileName, "rb");

			OnEnChangeEdit1("파일 이름 읽어오기 성공\r\n");

			if (file == NULL)
			{
				OnEnChangeEdit1("파일 오픈 에러\n");
			}
			fseek(file, 0L, SEEK_END);
			m_TempTestSize[file_num - 1] = ftell(file);
			m_TempTest[file_num - 1] = (unsigned char*)malloc(m_TempTestSize[file_num - 1]);
			memset(m_TempTest[file_num - 1], 0, m_TempTestSize[file_num - 1]);
			fseek(file, 0, SEEK_SET);
			int rBytes = 0;
			//rBytes = fread(m_TempTest[file_num - 1],1, m_TempTestSize[file_num - 1], file);
			//fread(m_TempTest[file_num - 1], 1, m_TempTestSize[file_num - 1], file);
			fread(m_TempTest[file_num - 1], 1, m_TempTestSize[file_num - 1], file);
			fclose(file);
		}
	}
}
	
//그 파일의 데이터들을 fopen 하여 
// 읽어온 파일들의 데이터를 배열안에 쓰기				

void CPractice_biominiDlg::OnBnClickedOpenfile2()
{
	UFS_STATUS ufs_res;
	UFM_STATUS ufm_res;
	UFE_STATUS ufe_res;

	//절대경로내 파일들의 이름 , 파일 자체를 가져오기 
	CString tpath = _T("C:\\1Copy\\*.bin");
	CString tpath2 = _T("C:\\1Copy");
	CFileFind finder;
	BOOL bWorking = finder.FindFile(tpath);
	CString csTemp;

	for (i = 0; i < MAX_TEMPLATE_NUM; i++) {
		memset(m_TemplateOpened, 0, sizeof(m_TemplateOpened));
		m_TempOpenedSize[i] = 0;
	}

	char fileName[128];
	int file_num = 0;

	while (bWorking) {
		bWorking = finder.FindNextFile();
		if (finder.IsArchived()) {
			file_num++;
			CString _fileName = finder.GetFileName();
			csTemp = tpath2 + (_T("\\")) + _fileName;
			int length = csTemp.GetLength();
			sprintf_s(fileName, 128, "%S", csTemp);
			FILE* file;
			file = fopen(fileName, "rb");

			OnEnChangeEdit1("파일 이름 읽어오기 성공\r\n");

			if (file == NULL)
			{
				OnEnChangeEdit1("파일 오픈 에러\n");
			}
			fseek(file, 0L, SEEK_END);
			m_TempOpenedSize[file_num - 1] = ftell(file);
			m_TemplateOpened[file_num - 1] = (unsigned char*)malloc(m_TempOpenedSize[file_num - 1]);
			memset(m_TemplateOpened[file_num - 1], 0, m_TempOpenedSize[file_num - 1]);
			fseek(file, 0, SEEK_SET);
			int rBytes = 0;
			//rBytes = fread(m_TempTest[file_num - 1],1, m_TempTestSize[file_num - 1], file);
			//fread(m_TempTest[file_num - 1], 1, m_TempTestSize[file_num - 1], file);
			fread(m_TemplateOpened[file_num - 1], 1, m_TempOpenedSize[file_num - 1], file);
			fclose(file);
		}
	
	}
}

void CPractice_biominiDlg::OnBnClickedMatchfile()
{
	HUFExtractor hExtractor = NULL;
	HUFMatcher hMatcher = NULL;
	UFE_STATUS ufe_res;
	UFM_STATUS ufm_res;
	int bVerifySucceed;
	float fscore = 0;

	ufe_res = UFE_Create(&hExtractor);
	if (ufe_res == UFE_OK) {
		OnEnChangeEdit1("UFE_CREATE: OK\r\n");
	}

	int nValue = 4;
	ufm_res = UFM_Create(&hMatcher);
	if (ufm_res == UFM_OK) {
		OnEnChangeEdit1("UFM_Create: OK\r\n");
	}
	UFM_SetParameter(hMatcher, UFM_PARAM_SECURITY_LEVEL, &nValue);
	// 각각 open1 , open2 -> 그리고 매치를 누르면 비교한 두개를 VERIFY
	ufm_res = UFM_VerifyEx(hMatcher, m_TempTest[0], m_TempTestSize[0], m_TemplateOpened[0], m_TempOpenedSize[0], &fscore, &bVerifySucceed);

	if (bVerifySucceed) {
		OnEnChangeEdit1("Verification succeed\r\n");
	}
	else {
		OnEnChangeEdit1("Verification failed\r\n");
	}


	if (hMatcher != NULL) {
		ufm_res = UFM_Delete(hMatcher);
		if (ufm_res == UFE_OK) {
			OnEnChangeEdit1("UFM_Delete: OK\r\n");
		}
	}
}


//UFE_LoadImageFromBMPFile(파일명, RAW이미지 바이너리, 넓이, 높이)

void CPractice_biominiDlg::OnBnClickedimageload()
{
	m_pImage_1 = (unsigned char*)malloc(MAX_IMAGE_WIDTH * MAX_IMAGE_HEIGHT);
	m_fileOn = false;
	HUFExtractor hExtractor = NULL;
	HUFMatcher hMatcher = NULL;
	
	UFE_STATUS ufe_res;
	ufe_res = UFE_Create(&hExtractor);
	
	if (ufe_res == UFE_OK) {
		OnEnChangeEdit1("UFE_CREATE: OK\r\n");
	}
	TCHAR szFilter[] = {_T("Image(*.bmp|*.bmp|") };
	CFileDialog dlg(TRUE, NULL, NULL, OFN_OVERWRITEPROMPT | OFN_ALLOWMULTISELECT, szFilter);
	if (IDOK == dlg.DoModal()) {
		m_szFilename_1 = dlg.GetPathName();
	}
	CStringA fileName = (CStringA)m_szFilename_1;
	const char* cTest = fileName.GetBuffer();
	int lfdScore = 0;
	int lfdScore2 = 3;
	UFS_SetParameter(hScanner, UFS_PARAM_DETECT_FAKE, &lfdScore2);
	ufe_res = UFE_LoadImageFromBMPFile(cTest, m_pImage_1, &m_nWidth_1, &m_nHeight_1);
	//UFS_GetLFDScore(hScanner, RAW이미지 바이너리, 넓이, 높이, 스코어);
	ufs_res = UFS_GetLFDScore(hScanner, m_pImage_1, m_nWidth_1, m_nHeight_1, &lfdScore);
	if (ufe_res == UFE_OK) {
			OnEnChangeEdit1("UFE_LoadImageFromBMPFile from: OK\r\n");
			m_fileOn = true;
			m_szFilename_1 = dlg.GetPathName();
			CStringA fileName = (CStringA)m_szFilename_1;
			const char* cTest = fileName.GetBuffer();
		}
	if (ufs_res == UFS_OK) {
		OnEnChangeEdit1("UFS_GetLFDScore: OK\r\n");
	}
	}




void CPractice_biominiDlg::OnBnClickedButton2()
{
	m_pImage_2 = (unsigned char*)malloc(MAX_IMAGE_WIDTH * MAX_IMAGE_HEIGHT);
	m_fileOn = false;
	HUFExtractor hExtractor = NULL;
	HUFMatcher hMatcher = NULL;
	UFE_STATUS ufe_res;
	UFM_STATUS ufm_res;
	
	int bVerifySucceed;
	float fscore = 0;
	ufe_res = UFE_Create(&hExtractor);
	if (ufe_res == UFE_OK) {
		OnEnChangeEdit1("UFE_CREATE: OK\r\n");
	}
	
	CString csstrPath;
	CString csstrPath2;
	BROWSEINFO BrInfo;
	TCHAR szBuffer[512];
	::ZeroMemory(&BrInfo, sizeof(BROWSEINFO));
	::ZeroMemory(szBuffer, 512);
	BrInfo.hwndOwner = GetSafeHwnd();
	BrInfo.lpszTitle = _T("파일이 저장될 폴더를 선택하세요");
	BrInfo.ulFlags = BIF_NEWDIALOGSTYLE | BIF_EDITBOX | BIF_RETURNONLYFSDIRS;
	LPITEMIDLIST pItemIdList = ::SHBrowseForFolder(&BrInfo);
	::SHGetPathFromIDList(pItemIdList, szBuffer);
	csstrPath.Format(_T("%s"), szBuffer);

	csstrPath2 = csstrPath + (_T("\\*.*"));
	CFileFind finder;
	BOOL bWorking = finder.FindFile(csstrPath2);
	CString csTemp;

	
	int i;
	for (i = 0; i < MAX_TEMPLATE_NUM; i++) {
		m_TemplateOpened[i] = (unsigned char*)malloc(MAX_TEMPLATE_SIZE);
		memset(m_TemplateOpened[i], 0, MAX_TEMPLATE_SIZE);
		
		m_TempOpenedSize[i] = 0;
	}
	m_TempOpened_num = 0;

	char fileName[128];
	int file_num = 0;
	int lfdScore2 = 3;

	while (bWorking) {
		bWorking = finder.FindNextFile();
		if (finder.IsArchived()) {
			file_num++;
			CString _fileName = finder.GetFileName();
			CString csTemp = csstrPath + (_T("\\"))+_fileName;

			sprintf_s(fileName, 128, "%S", csTemp);
			CStringA fileName = (CStringA)csTemp;

			CString _fileTitle = finder.GetFileTitle();
			CString csTemp1 = csstrPath + (_T("\\")) + _fileTitle + (_T(".bin"));

			CStringA csTemp2 = (CStringA)csTemp1;
			char szFileName3[400] = { 0, };
			memcpy(szFileName3, (LPSTR)(LPCSTR)csTemp2, csTemp2.GetLength());
			const char* cfile = fileName.GetBuffer();

			ufe_res = UFE_LoadImageFromBMPFile(cfile, m_pImage_2, &m_nWidth_2, &m_nHeight_2);
			ufe_res = UFE_Extract(hExtractor, m_pImage_2, m_nWidth_2, m_nHeight_2, 500, m_TemplateOpened[m_TempOpened_num], m_TempOpenedSize, &nEnrollQuality);
			
			FILE* file;
			OnEnChangeEdit1("파일 이름 읽어오기 성공\r\n");


			file = fopen(szFileName3, "wb");
			if (file == NULL) {
				return;
			}
			fwrite(m_TemplateOpened[m_TempOpened_num], 1, m_TempOpenedSize[m_TempOpened_num], file);
			fclose(file);

			OnEnChangeEdit1("Saved\r\n");
				}

	}
}

void CPractice_biominiDlg::OnBnClickedselectfile1()
{
	//file dialog 다중 셀렉
	// 다중 셀렉 -> 배열에 파일 쓰기

	HUFExtractor hExtractor = NULL;
	HUFMatcher hMatcher = NULL;
	UFE_STATUS ufe_res;
	ufe_res = UFE_Create(&hExtractor);
	CString tpath = _T("C:\\1Copy\\*.bin");
	CString tpath2 = _T("C:\\1Copy");
	CFileFind finder;
	BOOL bWorking = finder.FindFile(tpath);
	CString csTemp;
	CString _fileName;
	char fileName[128];


	if (ufe_res == UFE_OK) {
		OnEnChangeEdit1("UFE_CREATE: OK\r\n");
	}

	//for (i = 0; i < 5000; i++) {
	//	memset(m_selectArr1, 0, sizeof(m_selectArr1));
	//	m_selectArr1Size[i] = 0;
//	}
	
	while (bWorking) {
		bWorking = finder.FindNextFile();
		if (finder.IsArchived()) {
			m_file_num1++;
			_fileName = finder.GetFileName();
			csTemp = tpath2 + _fileName;
					}
		m_selectArr1[m_file_num1 - 1] = _fileName;
		CString str = _fileName; //파싱할 문자열
		CString strA, strB, strC, strD, strE, strF, strG; //파싱되는 문자열을 담을 변수선언
		AfxExtractSubString(strA, str, 0, '_');
		AfxExtractSubString(strB, str, 1, '_');
		AfxExtractSubString(strC, str, 2, '_');
		AfxExtractSubString(strD, str, 3, '_');
		AfxExtractSubString(strE, str, 4, '_');
		AfxExtractSubString(strF, str, 5, '_');
		AfxExtractSubString(strG, str, 6, '.');
			m_yearArr1[m_file_num1-1] = strA;
			m_deviceArr1[m_file_num1 - 1] = strB;
			m_userArr1[m_file_num1-1] = strC;
			m_fingerArr1[m_file_num1-1] = strD;
			m_numArr1[m_file_num1 - 1] = strE;
			m_conditionArr1[m_file_num1-1] = strF;


	}
	}



void CPractice_biominiDlg::OnBnClickedselectfile2()
{
	//file dialog 다중 셀렉
	// 다중 셀렉 -> 배열에 파일 쓰기

	HUFExtractor hExtractor = NULL;
	HUFMatcher hMatcher = NULL;
	UFE_STATUS ufe_res;
	ufe_res = UFE_Create(&hExtractor);
	CString tpath = _T("C:\\1Copy\\*.bin");
	CString tpath2 = _T("C:\\1Copy");
	CFileFind finder;
	BOOL bWorking = finder.FindFile(tpath);
	CString csTemp;
	CString _fileName;
	char fileName[128];


	if (ufe_res == UFE_OK) {
		OnEnChangeEdit1("UFE_CREATE: OK\r\n");
	}

	//for (i = 0; i < MAX_TEMPLATE_NUM; i++) {
	//	memset(m_selectArr2, 0, sizeof(m_selectArr2));
	//	m_selectArr2Size[i] = 0;
	//}

	while (bWorking) {
		bWorking = finder.FindNextFile();
		if (finder.IsArchived()) {
			m_file_num2++;
			_fileName = finder.GetFileName();
			csTemp = tpath2 + _fileName;
		}
		m_selectArr2[m_file_num2 - 1] = _fileName;
		CString str = _fileName; //파싱할 문자열
		CString strA, strB, strC, strD, strE, strF,strG; //파싱되는 문자열을 담을 변수선언
		AfxExtractSubString(strA, str, 0, '_');
		AfxExtractSubString(strB, str, 1, '_');
		AfxExtractSubString(strC, str, 2, '_');
		AfxExtractSubString(strD, str, 3, '_');
		AfxExtractSubString(strE, str, 4, '_');
		AfxExtractSubString(strF, str, 5, '_');
		AfxExtractSubString(strG, str, 6, '.');
		m_yearArr2[m_file_num2 - 1] = strA;
		m_deviceArr2[m_file_num2 - 1] = strB;
		m_userArr2[m_file_num2 - 1] = strC;
		m_fingerArr2[m_file_num2 - 1] = strD;
		m_numArr2[m_file_num2 - 1] = strE;
		m_conditionArr2[m_file_num2 - 1] = strF;
		

	}
}



void CPractice_biominiDlg::OnBnClickedselection()
{
	HUFExtractor hExtractor = NULL;
	HUFMatcher hMatcher = NULL;
	UFE_STATUS ufe_res;
	UFM_STATUS ufm_res;
	int bVerifySucceed;
	float fscore = 0;
	int nValue = 4;

	ufe_res = UFE_Create(&hExtractor);
	if (ufe_res == UFE_OK) {
		OnEnChangeEdit1("UFE_CREATE: OK\r\n");
	}

	ufm_res = UFM_Create(&hMatcher);
	UFM_SetParameter(hMatcher, UFM_PARAM_SECURITY_LEVEL, &nValue);
	if (ufm_res == UFM_OK) {
		OnEnChangeEdit1("UFM_Create: OK\r\n");
	}


	FILE* fp = NULL;
	fp = fopen("Genuine match score list.txt", "wt");
	fputs("<<Genuine Matching Score List>>\n", fp);
	fseek(fp, 0L, SEEK_END);
	fclose(fp);

	for (int i = 0; i < m_file_num1; i++) {
		for (int j = i+1; j < m_file_num2; j++) {
			//if (m_selectArr1[i] == m_selectArr2[j])
			//{
			//	OnEnChangeEdit1("Pass\r\n");
			//}
			//else {

				if (m_fingerArr1[i] == m_fingerArr2[j] && m_userArr1[i] == m_userArr2[j]) {
					//FILE* fp = NULL;
					//fp = fopen("Genuine match score list.txt", "a+");
					//fputs("Genuine matching score: ", fp);
					//fseek(fp, 0L, SEEK_END);
					//fclose(fp);
					ufm_res = UFM_VerifyEx(hMatcher, m_TempTest[i], m_TempTestSize[i], m_TemplateOpened[j], m_TempOpenedSize[j], &fscore, &bVerifySucceed);
					char matchScore[10000];
					sprintf(matchScore, "%f", fscore);
					fp = fopen("Genuine match score list.txt", "a+");
					fseek(fp, 0L, SEEK_END);
					fwprintf_s(fp, _T("%s"), m_selectArr1[i]);
					fputs(" - ", fp);
					fwprintf_s(fp, _T("%s"), m_selectArr1[j]);
					fputs(" : ", fp);
					fwrite(matchScore, sizeof(char), strlen(matchScore), fp);
					fputs("\n", fp);
					fclose(fp);
					if (bVerifySucceed) {
						OnEnChangeEdit1("Verification succeed\r\n");
					}
					else {
						OnEnChangeEdit1("Verification failed\r\n");
					}
				}
				else {
					OnEnChangeEdit1("Pass\r\n");
				}
				
			//}
		}
	}

	FILE* file = NULL;
	file = fopen("Imposter match score list.txt", "wt");
	fputs("<<Imposter Matching Score List>>\n\n", file);
	fseek(file, 0L, SEEK_END);
	fclose(file);

	for (int i = 0; i < m_file_num1; i++) {
		for (int j = i+1; j < m_file_num2; j++) {
			//if (m_selectArr1[i] == m_selectArr2[j])
			//{
			//	OnEnChangeEdit1("Pass\r\n");
			//}
			//else {

				if (m_fingerArr1[i] == m_fingerArr2[j] && m_userArr1[i] == m_userArr2[j]) {
					OnEnChangeEdit1("Pass\r\n");
					
				}
				else {
					//file = fopen("Imposter match score list.txt", "a+");
					//fputs("Imposter matching score: ", file);
					//fseek(file, 0L, SEEK_END);
					//fclose(file);
					ufm_res = UFM_VerifyEx(hMatcher, m_TempTest[i], m_TempTestSize[i], m_TemplateOpened[j], m_TempOpenedSize[j], &fscore, &bVerifySucceed);
					char matchScore[10000];
					sprintf(matchScore, "%f", fscore);
					file = fopen("Imposter match score list.txt", "a+");
					fseek(file, 0L, SEEK_END);
			
				
					fwprintf_s(file, _T("%s"), m_selectArr1[i]);
					fputs(" - ", file);
					fwprintf_s(file, _T("%s"), m_selectArr1[j]);
					fputs(" : ", file);
					fwrite(matchScore, sizeof(char), strlen(matchScore), file);
					fputs("\n", file);
					fclose(file);
				
					if (bVerifySucceed) {
						OnEnChangeEdit1("Verification succeed\r\n");
					}
					else {
						OnEnChangeEdit1("Verification failed\r\n");
					}
				
				}
			//}
		}
	}

	if (hMatcher != NULL) {
		ufm_res = UFM_Delete(hMatcher);
		if (ufm_res == UFE_OK) {
			OnEnChangeEdit1("UFM_Delete: OK\r\n");
		}
	}
}

