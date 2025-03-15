#include "test_cpu_basic.h"

#include "r2tm/r2tm_inspector.h"
#include "r2tm/r2tm_ostream.h"

#include "r2tm/r2tm_StopWatch.h"

// REF : https://learn.microsoft.com/ko-kr/windows/win32/api/sysinfoapi/nf-sysinfoapi-getlogicalprocessorinformation
#include <windows.h>
typedef BOOL( WINAPI* LPFN_GLPI )( PSYSTEM_LOGICAL_PROCESSOR_INFORMATION, PDWORD );

namespace test_cpu_basic
{
	const char* Convert_CacheType2String( _PROCESSOR_CACHE_TYPE type )
	{
		switch( type )
		{
		case CacheUnified:
			return "Unified";
		case CacheInstruction:
			return "Instruction";
		case CacheData:
			return "Data";
		case CacheTrace:
			return "Trace";
		default:
			return "Unknown";
		}
	}

	r2tm::TitleFunctionT CacheInformation::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Cache Information";
		};
	}
	r2tm::DoFunctionT CacheInformation::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			LPFN_GetLogicalProcessorInformation glpi = ( LPFN_GetLogicalProcessorInformation )GetProcAddress( GetModuleHandle( TEXT( "kernel32" ) ), "GetLogicalProcessorInformation" );

			if( nullptr == glpi )
				return r2tm::eDoLeaveAction::Pause;

			//
			// ù ���ڷ� 0�� �ָ� ������ ������ ���� �ʿ��� �޸� ũ�⸦ ��ȯ �Ѵ�.
			//
			DWORD buffer_bytes = 0;
			glpi( 0, &buffer_bytes );

			//
			// �޸� �Ҵ�.
			//
			const std::size_t size = buffer_bytes / sizeof( SYSTEM_LOGICAL_PROCESSOR_INFORMATION );
			SYSTEM_LOGICAL_PROCESSOR_INFORMATION* buffer = new SYSTEM_LOGICAL_PROCESSOR_INFORMATION[size];

			//
			// ���� ȹ��.
			//
			glpi( buffer, &buffer_bytes );

			//
			// ���
			//
			for( std::size_t i = 0; size > i; ++i )
			{
				if( buffer[i].Relationship == _LOGICAL_PROCESSOR_RELATIONSHIP::RelationCache )
				{
					printf( "Level : %d | Type : %15s | Size : %6d KB %10d B | LineSize : %d\n"
						, buffer[i].Cache.Level
						, Convert_CacheType2String( buffer[i].Cache.Type )
						, ( buffer[i].Cache.Size / 1024 )
						, buffer[i].Cache.Size
						, buffer[i].Cache.LineSize
					);
				}
			}

			//
			//
			//
			delete[] buffer;

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}