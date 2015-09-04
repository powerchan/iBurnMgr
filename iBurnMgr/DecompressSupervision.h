/*********************************************************************************************************
* DecompressSupervision.h
* Note: iBurnMgr DecompressSupervision
* E-mail:<forcemz@outlook.com>
* Date: @2015.03
* Copyright (C) 2015 The ForceStudio All Rights Reserved.
**********************************************************************************************************/
# ifndef DECOMPRESSSUPERVISION
#define  DECOMPRESSSUPERVISION
#include <string>

//////////////////////////
/// 1 Format Flash Disk
/// 2 7Z Decompress ISO Image
/// 3 Check End Return Success


BOOL WINAPI  IVdsVolumeFormat(
	LPCWSTR    latter,
	LPWSTR    pwszLabel,
	FormatCallback fcall,
	void *data);

namespace Decompress{
	typedef struct _SupervisorData{
		std::wstring image;
		wchar_t latter[9];
		LPVOID lParam;
	}SupervisorData,*LPSupervisorData;

	DWORD WINAPI DecompressSupervisorThread(LPVOID Spdata);

	class Supervisor{
	private:
		std::wstring m_image;
		std::wstring m_latter;
		HWND hParents;
		//bool FormatUSBDevice();
	public:
		bool CreateDecompressFormat();
		static bool WINAPI CreateDecompressInvoke(HWND hWnd,std::wstring img, LPWSTR latter);
		Supervisor(LPSupervisorData lPSpData);
		Supervisor(std::wstring img, LPCWSTR latter,LPVOID lParam);
	};

}
#endif
