//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <SvcMgr.hpp>
#include <vcl.h>
#include <Vcl.ExtCtrls.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.Comp.UI.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.MySQL.hpp>
#include <FireDAC.Phys.MySQLDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
//---------------------------------------------------------------------------
class TService1 : public TService
{
__published:    // IDE-managed Components
	TTimer *Timer1;
	TFDGUIxWaitCursor *FDGUIxWaitCursor1;
	TFDPhysMySQLDriverLink *FDPhysMySQLDriverLink1;
	TFDConnection *fdc;
	TFDQuery *FDQuery1;
	TFDCommand *FDCommand1;
	void __fastcall ServiceStart(TService *Sender, bool &Started);
	void __fastcall ServiceStop(TService *Sender, bool &Stopped);
	void __fastcall ServiceExecute(TService *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
private:        // User declarations
public:         // User declarations
	__fastcall TService1(TComponent* Owner);
	TServiceController __fastcall GetServiceController(void);

	friend void __stdcall ServiceController(unsigned CtrlCode);
};
//---------------------------------------------------------------------------
extern PACKAGE TService1 *Service1;
//---------------------------------------------------------------------------
#endif
