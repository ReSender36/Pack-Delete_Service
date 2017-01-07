#include <vcl.h>
#include <stdio.h>
#include <winbase.h>
#include <shellapi.h>
//#include <systdate.h>
//#include <inifiles.hpp>
//#include <WinError.h>

//---------------------------------------------------------------------------
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"

TService1 *Service1;
short i ;
//---------------------------------------------------------------------------
__fastcall TService1::TService1(TComponent* Owner)
	: TService(Owner)
{
}

void __stdcall ServiceController(unsigned CtrlCode)
{
	Service1->Controller(CtrlCode);
}

TServiceController __fastcall TService1::GetServiceController(void)
{
	return (TServiceController) ServiceController;
}

//---------------------------------------------------------------------------
void __fastcall TService1::ServiceStart(TService *Sender, bool &Started)
{
	FILE *fl ;
	AnsiString sFileName = ChangeFileExt(Vcl::Forms::Application->ExeName,".log") ;
	if(fl = fopen(sFileName.c_str(), "a+"))
	{
		AnsiString write_str = "сервис запущен" ;
		try{
			fprintf(fl, "%s \n", write_str) ;
			fclose(fl) ;
//			return true ;
		}
		catch(...){
//			return false ;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TService1::ServiceStop(TService *Sender, bool &Stopped)
{
	FILE *fl ;
	AnsiString sFileName = ChangeFileExt(Vcl::Forms::Application->ExeName,".log") ;
	if(fl = fopen(sFileName.c_str(), "a+")){
		AnsiString write_str = "сервис остановлен" ;
		try{
			fprintf(fl, "%s \n", write_str) ;
			fclose(fl) ;
//			return true ;
		}
		catch(...){
 //			return false ;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TService1::ServiceExecute(TService *Sender)
{
	FILE *fl ;
//	AnsiString sFileName = ChangeFileExt(Vcl::Forms::Application->ExeName,".log") ;
	AnsiString sFileName = "C:\\123.log" ;
	if(fl = fopen(sFileName.c_str(), "a+")){
		AnsiString write_str = "сервис работает" ;
		try{
			fprintf(fl, "%s \n", write_str) ;
			fclose(fl) ;
//			return true ;
		}
		catch(...){
//			return false ;
		}
	}
	Timer1->Enabled = true ;
}
//---------------------------------------------------------------------------
void __fastcall TService1::Timer1Timer(TObject *Sender)
{
	FILE *fl ;
	i++ ;
	AnsiString write_str = "" ;
	AnsiString sFileName = "C:\\123.log" ;
	if(fl = fopen(sFileName.c_str(), "a+")){
		write_str = "таймер работает" ;
		try{
			fprintf(fl, "%s \n", write_str) ;
			fclose(fl) ;
//			return true ;
		}
		catch(...){
//			return false ;
		}
	}

	FDQuery1->Active = false ;
	String str = String("SELECT TIME_TO_RUN FROM SM_TST.OPTIONS") ;
	FDQuery1->SQL->Text = str ;
	FDQuery1->Active = true ;

	String state = FDQuery1->FieldByName("TIME_TO_RUN")->AsString ;
 //	if ("True" == state) {
		if(fl = fopen(sFileName.c_str(), "a+")){
			write_str = "запускаем калькулятор " + state ;
			try{
				fprintf(fl, "%s \n", write_str) ;
				fclose(fl) ;
//				return true ;
			}
			catch(...){
//				return false ;
			}
		}


//		str = String("UPDATE SM_TST.OPTIONS SET TIME_TO_RUN = FALSE") ;
		FDCommand1->CommandText->Add("UPDATE SM_TST.OPTIONS SET TIME_TO_RUN = FALSE") ;
		FDCommand1->Execute() ;
//		WinExec("Calc.exe", SW_NORMAL) ;

	STARTUPINFO StartInfo = { sizeof(TStartupInfo) } ;
	PROCESS_INFORMATION ProcInfo ;
	LPCTSTR s ;
	StartInfo.cb = sizeof(StartInfo) ;
	StartInfo.dwFlags = STARTF_USESHOWWINDOW ;
	StartInfo.wShowWindow = SW_SHOWNORMAL ;
	AnsiString strProg = "Calc.exe" ;
	if(!CreateProcess(NULL, strProg.c_str(),NULL,NULL,false,
		CREATE_NEW_CONSOLE|HIGH_PRIORITY_CLASS,NULL,NULL,&StartInfo,&ProcInfo)){
//		ShowMessage("Ошибка: " + SysErrorMessage(GetLastError())) ;
		}
	else{
		if(WaitForSingleObject(ProcInfo.hProcess,10000) == WAIT_TIMEOUT) {}
//			ShowMessage("Процесс пока идет") ;
//		CloseHandle(ProcInfo.hProcess) ;
	}
//	HWND H = FindWindow("Calc.exe","Калькулятор") ;
//	ShowWindow(H, true) ;
	HWND H ;
	char Pch[128] ;
	do{
		H = GetNextWindow(H,GW_HWNDNEXT) ;
		GetWindowText(H,Pch,128) ;
        if(fl = fopen(sFileName.c_str(), "a+")){

			try{
				fprintf(fl, "%s \n", String(Pch)) ;
				fclose(fl) ;
//				return true ;
			}
			catch(...){
//				return false ;
			}
		}
		if(StrComp(Pch,"Калькулятор") == 0)
			break ;
	}while(H) ;

	if(H){
	   write_str = "НАШЛИ калькулятор" ;
	}else{
	   write_str = "Калькулятор не найден" ;
	}
		 if(fl = fopen(sFileName.c_str(), "a+")){

			try{
				fprintf(fl, "%s \n", write_str) ;
				fclose(fl) ;
//				return true ;
			}
			catch(...){
//				return false ;
			}
		}

 //	}
 //	if (10 == i) {
//		WideString ao = "C:\\mini-agent.txt" ;
//		ShellExecuteA(NULL, "open", "Notepad++.exe", AnsiString(ao).c_str(), NULL, SW_SHOWNORMAL) ;

		Timer1->Enabled = false ;
 //		Service1->DoShutdown() ;
 //		Service1-> >DoStop() ;

 //	}
}
//---------------------------------------------------------------------------
