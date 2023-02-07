declare namespace Qt {
	enum MouseButton { Alls, Back, Extra1, Extra10, Extra11, Extra12, Extra13, Extra14, Extra15, Extra16, Extra17, Extra18, Extra19, Extra2, Extra20, Extra21, Extra22, Extra23, Extra24, Extra3, Extra4, Extra5, Extra6, Extra7, Extra8, Extra9, Forward, Left, Middle, No, Right, Task, X1, X2 }
	enum Key { _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, A, AE, Aacute, Acircumflex, AddFavorite, Adiaeresis, Agrave, Alt, AltGr, Ampersand, Any, Apostrophe, ApplicationLeft, ApplicationRight, Aring, AsciiCircum, AsciiTilde, Asterisk, At, Atilde, AudioCycleTrack, AudioForward, AudioRandomPlay, AudioRepeat, AudioRewind, Away, B, Back, BackForward, Backslash, Backspace, Backtab, Bar, BassBoost, BassDown, BassUp, Battery, Blue, Bluetooth, Book, BraceLeft, BraceRight, BracketLeft, BracketRight, BrightnessAdjust, C, CD, Calculator, Calendar, Call, Camera, CameraFocus, Cancel, CapsLock, Ccedilla, ChannelDown, ChannelUp, Clear, ClearGrab, Close, Codeinput, Colon, Comma, Community, Context1, Context2, Context3, Context4, ContrastAdjust, Control, Copy, Cut, D, DOS, Dead_A, Dead_Abovecomma, Dead_Abovedot, Dead_Abovereversedcomma, Dead_Abovering, Dead_Aboveverticalline, Dead_Acute, Dead_Belowbreve, Dead_Belowcircumflex, Dead_Belowcomma, Dead_Belowdiaeresis, Dead_Belowdot, Dead_Belowmacron, Dead_Belowring, Dead_Belowtilde, Dead_Belowverticalline, Dead_Breve, Dead_Capital_Schwa, Dead_Caron, Dead_Cedilla, Dead_Circumflex, Dead_Currency, Dead_Diaeresis, Dead_Doubleacute, Dead_Doublegrave, Dead_E, Dead_Grave, Dead_Greek, Dead_Hook, Dead_Horn, Dead_I, Dead_Invertedbreve, Dead_Iota, Dead_Longsolidusoverlay, Dead_Lowline, Dead_Macron, Dead_O, Dead_Ogonek, Dead_Semivoiced_Sound, Dead_Small_Schwa, Dead_Stroke, Dead_Tilde, Dead_U, Dead_Voiced_Sound, Dead_a, Dead_e, Dead_i, Dead_o, Dead_u, Delete, Direction_L, Direction_R, Display, Documents, Dollar, Down, E, ETH, Eacute, Ecircumflex, Ediaeresis, Egrave, Eisu_Shift, Eisu_toggle, Eject, End, Enter, Equal, Escape, Excel, Exclam, Execute, Exit, Explorer, F, F1, F10, F11, F12, F13, F14, F15, F16, F17, F18, F19, F2, F20, F21, F22, F23, F24, F25, F26, F27, F28, F29, F3, F30, F31, F32, F33, F34, F35, F4, F5, F6, F7, F8, F9, Favorites, Finance, Find, Flip, Forward, G, Game, Go, Greater, Green, Guide, H, Hangul, Hangul_Banja, Hangul_End, Hangul_Hanja, Hangul_Jamo, Hangul_Jeonja, Hangul_PostHanja, Hangul_PreHanja, Hangul_Romaja, Hangul_Special, Hangul_Start, Hangup, Hankaku, Help, Henkan, Hibernate, Hiragana, Hiragana_Katakana, History, Home, HomePage, HotLinks, Hyper_L, Hyper_R, I, Iacute, Icircumflex, Idiaeresis, Igrave, Info, Insert, J, K, Kana_Lock, Kana_Shift, Kanji, Katakana, KeyboardBrightnessDown, KeyboardBrightnessUp, KeyboardLightOnOff, L, LastNumberRedial, Launch0, Launch1, Launch2, Launch3, Launch4, Launch5, Launch6, Launch7, Launch8, Launch9, LaunchA, LaunchB, LaunchC, LaunchD, LaunchE, LaunchF, LaunchG, LaunchH, LaunchMail, LaunchMedia, Left, Less, LightBulb, LogOff, M, MailForward, Market, Massyo, MediaLast, MediaNext, MediaPause, MediaPlay, MediaPrevious, MediaRecord, MediaStop, MediaTogglePlayPause, Meeting, Memo, Menu, MenuKB, MenuPB, Messenger, Meta, MicMute, MicVolumeDown, MicVolumeUp, Minus, Mode_switch, MonBrightnessDown, MonBrightnessUp, Muhenkan, Multi_key, MultipleCandidate, Music, MySites, N, New, News, No, Ntilde, NumLock, NumberSign, O, Oacute, Ocircumflex, Odiaeresis, OfficeHome, Ograve, Ooblique, Open, OpenUrl, Option, Otilde, P, PageDown, PageUp, ParenLeft, ParenRight, Paste, Pause, Percent, Period, Phone, Pictures, Play, Plus, PowerDown, PowerOff, PreviousCandidate, Print, Printer, Q, Question, QuoteDbl, QuoteLeft, R, Red, Redo, Refresh, Reload, Reply, Return, Right, Romaji, RotateWindows, RotationKB, RotationPB, S, Save, ScreenSaver, ScrollLock, Search, Select, Semicolon, Send, Settings, Shift, Shop, SingleCandidate, Slash, Sleep, Space, Spell, SplitScreen, Standby, Stop, Subtitle, Super_L, Super_R, Support, Suspend, SysReq, T, THORN, Tab, TaskPane, Terminal, Time, ToDoList, ToggleCallHangup, Tools, TopMenu, TouchpadOff, TouchpadOn, TouchpadToggle, Touroku, Travel, TrebleDown, TrebleUp, U, UWB, Uacute, Ucircumflex, Udiaeresis, Ugrave, Underscore, Undo, Up, V, Video, View, VoiceDial, VolumeDown, VolumeMute, VolumeUp, W, WLAN, WWW, WakeUp, WebCam, Word, X, Xfer, Y, Yacute, Yellow, Yes, Z, Zenkaku, Zenkaku_Hankaku, Zoom, ZoomIn, ZoomOut, acute, brokenbar, cedilla, cent, copyright, currency, degree, diaeresis, division, exclamdown, guillemotleft, guillemotright, hyphen, iTouch, macron, masculine, mu, multiply, nobreakspace, notsign, onehalf, onequarter, onesuperior, ordfeminine, paragraph, periodcentered, plusminus, questiondown, registered, section, ssharp, sterling, threequarters, threesuperior, twosuperior, unknown, ydiaeresis, yen }
	enum FocusReason {
		MouseFocusReason = 0,
		TabFocusReason = 1,
		BacktabFocusReason = 2,
		ActiveWindowFocusReason = 3,
		PopupFocusReason = 4,
		ShortcutFocusReason = 5,
		MenuBarFocusReason = 6,
		OtherFocusReason = 7,
		NoFocusReason = 8,
	}
	namespace Events {
		type QMouseEvent = {
			button: Qt.MouseButton
			globalPos: QPoint
			globalPos: QPoint
			localPos: QPointF
			pos: QPoint
			screenPos: QPointF
			windowPos: QPointF
			x: number,
			y: number,
		}
		type QResizeEvent = {
			oldSize: QSize
			size: QSize
		}
		type QSize = {
			width: number
			height: number
			rheight: number
			rwidth: number
			isEmpty: boolean
			isNull: boolean
			isValid: boolean
		}
		type QPoint = {
			x: number,
			y: number,
			rx: number,
			ry: number
		}
		type QPointF = QPoint
	}
	enum WindowFlags{
		Widget,Window,Dialog,Sheet,Drawer,Popup,Tool,ToolTip,SplashScreen,Desktop,SubWindow,ForeignWindow,CoverWindow,WindowType_Mask,MSWindowsFixedSizeDialogHint,MSWindowsOwnDC,BypassWindowManagerHint,X11BypassWindowManagerHint,FramelessWindowHint,WindowTitleHint,WindowSystemMenuHint,WindowMinimizeButtonHint,WindowMaximizeButtonHint,WindowMinMaxButtonsHint,WindowContextHelpButtonHint,WindowShadeButtonHint,WindowStaysOnTopHint,WindowTransparentForInput,WindowOverridesSystemGestures,WindowDoesNotAcceptFocus,MaximizeUsingFullscreenGeometryHint,CustomizeWindowHint,WindowStaysOnBottomHint,WindowCloseButtonHint,MacWindowToolBarButtonHint,BypassGraphicsProxyWidget,NoDropShadowWindowHint,WindowFullscreenButtonHint
	}
}
declare namespace QSizePolicy {
	enum Policy { Fixed, Minimum, Maximum, Preferred, MinimumExpanding, Expanding, Ignored }
}

