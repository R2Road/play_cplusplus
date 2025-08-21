//
// # Version Rule
// - 1.0.0 : 사용 가능
// - 0.1.0 : 사용자가 코드를 바꿀 정도의 변화
// - 0.0.1 : 자잘한 변화
//
// # Last Update		: 2023.08.06 PM.03.40
// # Version			: 1.0.0
//

#pragma once

namespace r2
{
	class NoneCopyable
	{
	public:
		NoneCopyable() = default;

	private:
		// none copy
		NoneCopyable( const NoneCopyable& ) = delete;
		NoneCopyable( NoneCopyable&& ) = delete;
		NoneCopyable& operator=( const NoneCopyable& ) = delete;
		NoneCopyable& operator=( NoneCopyable&& ) = delete;
	};
}