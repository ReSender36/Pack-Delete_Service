object Service1: TService1
  OldCreateOrder = False
  DisplayName = 'Service1'
  OnStart = ServiceStart
  OnStop = ServiceStop
  Height = 150
  Width = 215
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 152
    Top = 16
  end
  object FDGUIxWaitCursor1: TFDGUIxWaitCursor
    Provider = 'Forms'
    Left = 16
    Top = 94
  end
  object FDPhysMySQLDriverLink1: TFDPhysMySQLDriverLink
    DriverID = 'MySQL1'
    Left = 16
    Top = 56
  end
  object fdc: TFDConnection
    Params.Strings = (
      'DriverID=MySQL1'
      'CharacterSet=cp1251'
      'Server=localhost'
      'User_Name=root'
      'Password=TykadKme27'
      'Database=SM')
    LoginPrompt = False
    Left = 16
    Top = 8
  end
  object FDQuery1: TFDQuery
    Connection = fdc
    Left = 136
    Top = 80
  end
  object FDCommand1: TFDCommand
    Connection = fdc
    Left = 96
    Top = 32
  end
end
